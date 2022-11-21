#include<SoftwareSerial.h>
#include<PZEM004Tv30.h>
#include<ESP8266WiFi.h>
#include<FirebaseArduino.h>
#include<wpa2_enterprise.h>
 
#define FIREBASE_HOST "capstonea07-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "z2LkpOQOm2qjaP1s8h2BPggQq9T9twBwNzSILnAi"

bool s1,s2,s3,s4;

//char ssid[] = "UGM-Secure";
//char username[] = "suswanto.aida";
//char identity[] = "suswanto.aida";
//char password[] = "";
//uint8_t wemos_mac[6]={0x5c, 0xcf, 0x7f, 0xfc, 0x51, 0x80};

PZEM004Tv30 pzem1(D4,D5, 0x11);
PZEM004Tv30 pzem2(D4,D5, 0x12);
PZEM004Tv30 pzem3(D4,D5, 0x13);
PZEM004Tv30 pzem4(D4,D5, 0x14);


void setup() {
  Serial.begin(115200);
  WiFi.begin("asuswa","rangertiakupaswo");
  //WiFi.mode(WIFI_STA);
  //wifi_set_opmode(STATION_MODE);
  //struct station_config wifi_config;
  //memset(&wifi_config, 0, sizeof(wifi_config));
  //strcpy((char*)wifi_config.ssid, ssid);
  //strcpy((char*)wifi_config.password, password);
  //wifi_station_set_config(&wifi_config);
  //wifi_set_macaddr(STATION_IF, wemos_mac);
  //wifi_station_set_wpa2_enterprise_auth(1);
  //wifi_station_clear_cert_key();
  //wifi_station_clear_enterprise_ca_cert();
  //wifi_station_clear_enterprise_identity();
  //wifi_station_clear_enterprise_username();
  //wifi_station_clear_enterprise_password();
  //wifi_station_clear_enterprise_new_password();
  //wifi_station_set_enterprise_identity((uint8*)identity, strlen(identity));
  //wifi_station_set_enterprise_username((uint8*)username, strlen(username));
  //wifi_station_set_enterprise_password((uint8*)password, strlen((char*)password));
  //wifi_station_connect();
  Serial.print("menghubungkan");
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println(WiFi.localIP());
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D11, INPUT);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  digitalWrite(LED_BUILTIN, LOW);
}

bool orang;

void loop() {
  float daya1=pzem3.power();
  Serial.println(pzem1.voltage());
  if(isnan(daya1)){
    daya1=0;
  }
  float daya2=pzem1.power();
  Serial.println(pzem2.voltage());
  if(isnan(daya2)){
    daya2=0;
  }
  float daya3=pzem4.power();
  Serial.println(pzem3.voltage());
  if(isnan(daya3)){
    daya3=0;
  }
  float daya4=pzem2.power();
  Serial.println(pzem4.voltage());
  if(isnan(daya4)){
    daya4=0;
  }
  if(digitalRead(D11)==HIGH){
    Firebase.setBool("users/budi/adaorang", true);
    orang=true;
  }
  else{
    Firebase.setBool("users/budi/adaorang", false);
    orang=false;
  }
  s1=Firebase.getBool("users/budi/beban1/switch");
  s2=Firebase.getBool("users/budi/beban2/switch");
  s3=Firebase.getBool("users/budi/beban3/switch");
  s4=Firebase.getBool("users/budi/beban4/switch");
  if(orang){
    Firebase.setFloat("users/budi/beban1/data1/daya", daya1);
    Firebase.setFloat("users/budi/beban2/data1/daya", daya2);
    Firebase.setFloat("users/budi/beban3/data1/daya", daya3);
    Firebase.setFloat("users/budi/beban4/data1/daya", daya4);
    Firebase.setFloat("users/budi/beban1/data1/biaya", Firebase.getFloat("users/budi/beban1/data1/biaya")+daya1/3600/1000*Firebase.getInt("location/Yogyakarta/golongan/900VA/harga"));
    Firebase.setFloat("users/budi/beban2/data1/biaya", Firebase.getFloat("users/budi/beban2/data1/biaya")+daya2/3600/1000*Firebase.getInt("location/Yogyakarta/golongan/900VA/harga"));
    Firebase.setFloat("users/budi/beban3/data1/biaya", Firebase.getFloat("users/budi/beban3/data1/biaya")+daya3/3600/1000*Firebase.getInt("location/Yogyakarta/golongan/900VA/harga"));
    Firebase.setFloat("users/budi/beban4/data1/biaya", Firebase.getFloat("users/budi/beban4/data1/biaya")+daya4/3600/1000*Firebase.getInt("location/Yogyakarta/golongan/900VA/harga"));
  }
  else{
    Firebase.setFloat("users/budi/beban1/data2/daya", daya1);
    Firebase.setFloat("users/budi/beban2/data2/daya", daya2);
    Firebase.setFloat("users/budi/beban3/data2/daya", daya3);
    Firebase.setFloat("users/budi/beban4/data2/daya", daya4);
    Firebase.setFloat("users/budi/beban1/data2/biaya", Firebase.getFloat("users/budi/beban1/data2/biaya")+daya1/3600/1000*Firebase.getInt("location/Yogyakarta/golongan/900VA/harga"));
    Firebase.setFloat("users/budi/beban2/data2/biaya", Firebase.getFloat("users/budi/beban2/data2/biaya")+daya2/3600/1000*Firebase.getInt("location/Yogyakarta/golongan/900VA/harga"));
    Firebase.setFloat("users/budi/beban3/data2/biaya", Firebase.getFloat("users/budi/beban3/data2/biaya")+daya3/3600/1000*Firebase.getInt("location/Yogyakarta/golongan/900VA/harga"));
    Firebase.setFloat("users/budi/beban4/data2/biaya", Firebase.getFloat("users/budi/beban4/data2/biaya")+daya4/3600/1000*Firebase.getInt("location/Yogyakarta/golongan/900VA/harga"));
  }
  delay(1000);
}