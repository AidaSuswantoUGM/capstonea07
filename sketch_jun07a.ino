#include<SoftwareSerial.h>
#include<PZEM004Tv30.h>
#include<ESP8266WiFi.h>
#include<FirebaseArduino.h>
#include<wpa2_enterprise.h>

 
#define FIREBASE_HOST "capstonea07-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "z2LkpOQOm2qjaP1s8h2BPggQq9T9twBwNzSILnAi"

//#define PZEM_RX_PIN D5
//#define PZEM_TX_PIN D6

//char ssid[] = "UGM-Secure";
//char username[] = "suswanto.aida";
//char identity[] = "suswanto.aida";
//char password[] = "";
//uint8_t wemos_mac[6]={0x5c, 0xcf, 0x7f, 0xfc, 0x51, 0x80};

//SoftwareSerial pzemSWSerial(PZEM_RX_PIN, PZEM_TX_PIN);
//SoftwareSerial pzemserial1(D2, D3);
//SoftwareSerial pzemserial2(D4, D5);
//SoftwareSerial pzemserial3(D6, D7);
//SoftwareSerial pzemserial4(D10, D11);
//PZEM004Tv30 pzem(PZEM_RX_PIN, PZEM_TX_PIN, 0x02);
PZEM004Tv30 pzem1(D4,D5, 0x11);
PZEM004Tv30 pzem2(D4,D5, 0x12);
PZEM004Tv30 pzem3(D4,D5, 0x13);
PZEM004Tv30 pzem4(D4,D5, 0x14);


void setup() {
  Serial.begin(115200);
  WiFi.begin("Kost Bu Penika 2","setanalas");
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
  //pzem1=PZEM004Tv30(pzemserial1,0x11);
  //pzem2=PZEM004Tv30(pzemserial2,0x12);
  //pzem3=PZEM004Tv30(pzemserial3,0x13);
  //pzem4=PZEM004Tv30(pzemserial4,0x14);
  //Serial.println(WiFi.macAddress());
}
//int i=0;

bool orang;

void loop() {
  float daya1=pzem1.power();
  if(isnan(daya1)){
    daya1=0;
  }
  float daya2=pzem2.power();
  if(isnan(daya2)){
    daya2=0;
  }
  float daya3=pzem3.power();
  if(isnan(daya3)){
    daya3=0;
  }
  float daya4=pzem4.power();
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
  Serial.println(pzem1.voltage());
  Serial.println(pzem2.voltage());
  Serial.println(pzem3.voltage());
  Serial.println(pzem4.voltage());
  if(orang){
    Firebase.setFloat("users/budi/beban1/data1/menit60", Firebase.getFloat("users/budi/beban1/data1/menit50"));
    Firebase.setFloat("users/budi/beban1/data1/menit50", Firebase.getFloat("users/budi/beban1/data1/menit40"));
    Firebase.setFloat("users/budi/beban1/data1/menit40", Firebase.getFloat("users/budi/beban1/data1/menit30"));
    Firebase.setFloat("users/budi/beban1/data1/menit30", Firebase.getFloat("users/budi/beban1/data1/menit20"));
    Firebase.setFloat("users/budi/beban1/data1/menit20", Firebase.getFloat("users/budi/beban1/data1/menit10"));
    Firebase.setFloat("users/budi/beban1/data1/menit10", Firebase.getFloat("users/budi/beban1/data1/daya"));
    Firebase.setFloat("users/budi/beban2/data1/menit60", Firebase.getFloat("users/budi/beban2/data1/menit50"));
    Firebase.setFloat("users/budi/beban2/data1/menit50", Firebase.getFloat("users/budi/beban2/data1/menit40"));
    Firebase.setFloat("users/budi/beban2/data1/menit40", Firebase.getFloat("users/budi/beban2/data1/menit30"));
    Firebase.setFloat("users/budi/beban2/data1/menit30", Firebase.getFloat("users/budi/beban2/data1/menit20"));
    Firebase.setFloat("users/budi/beban2/data1/menit20", Firebase.getFloat("users/budi/beban2/data1/menit10"));
    Firebase.setFloat("users/budi/beban2/data1/menit10", Firebase.getFloat("users/budi/beban2/data1/daya"));
    Firebase.setFloat("users/budi/beban3/data1/menit60", Firebase.getFloat("users/budi/beban3/data1/menit50"));
    Firebase.setFloat("users/budi/beban3/data1/menit50", Firebase.getFloat("users/budi/beban3/data1/menit40"));
    Firebase.setFloat("users/budi/beban3/data1/menit40", Firebase.getFloat("users/budi/beban3/data1/menit30"));
    Firebase.setFloat("users/budi/beban3/data1/menit30", Firebase.getFloat("users/budi/beban3/data1/menit20"));
    Firebase.setFloat("users/budi/beban3/data1/menit20", Firebase.getFloat("users/budi/beban3/data1/menit10"));
    Firebase.setFloat("users/budi/beban3/data1/menit10", Firebase.getFloat("users/budi/beban3/data1/daya"));
    Firebase.setFloat("users/budi/beban4/data1/menit60", Firebase.getFloat("users/budi/beban4/data1/menit50"));
    Firebase.setFloat("users/budi/beban4/data1/menit50", Firebase.getFloat("users/budi/beban4/data1/menit40"));
    Firebase.setFloat("users/budi/beban4/data1/menit40", Firebase.getFloat("users/budi/beban4/data1/menit30"));
    Firebase.setFloat("users/budi/beban4/data1/menit30", Firebase.getFloat("users/budi/beban4/data1/menit20"));
    Firebase.setFloat("users/budi/beban4/data1/menit20", Firebase.getFloat("users/budi/beban4/data1/menit10"));
    Firebase.setFloat("users/budi/beban4/data1/menit10", Firebase.getFloat("users/budi/beban4/data1/daya"));
    Firebase.setFloat("users/budi/beban1/data1/daya", daya1);
    Firebase.setFloat("users/budi/beban2/data1/daya", daya2);
    Firebase.setFloat("users/budi/beban3/data1/daya", daya3);
    Firebase.setFloat("users/budi/beban4/data1/daya", daya4);
  }
  else{
    Firebase.setFloat("users/budi/beban1/data2/menit60", Firebase.getFloat("users/budi/beban1/data2/menit50"));
    Firebase.setFloat("users/budi/beban1/data2/menit50", Firebase.getFloat("users/budi/beban1/data2/menit40"));
    Firebase.setFloat("users/budi/beban1/data2/menit40", Firebase.getFloat("users/budi/beban1/data2/menit30"));
    Firebase.setFloat("users/budi/beban1/data2/menit30", Firebase.getFloat("users/budi/beban1/data2/menit20"));
    Firebase.setFloat("users/budi/beban1/data2/menit20", Firebase.getFloat("users/budi/beban1/data2/menit10"));
    Firebase.setFloat("users/budi/beban1/data2/menit10", Firebase.getFloat("users/budi/beban1/data2/daya"));
    Firebase.setFloat("users/budi/beban2/data2/menit60", Firebase.getFloat("users/budi/beban2/data2/menit50"));
    Firebase.setFloat("users/budi/beban2/data2/menit50", Firebase.getFloat("users/budi/beban2/data2/menit40"));
    Firebase.setFloat("users/budi/beban2/data2/menit40", Firebase.getFloat("users/budi/beban2/data2/menit30"));
    Firebase.setFloat("users/budi/beban2/data2/menit30", Firebase.getFloat("users/budi/beban2/data2/menit20"));
    Firebase.setFloat("users/budi/beban2/data2/menit20", Firebase.getFloat("users/budi/beban2/data2/menit10"));
    Firebase.setFloat("users/budi/beban2/data2/menit10", Firebase.getFloat("users/budi/beban2/data2/daya"));
    Firebase.setFloat("users/budi/beban3/data2/menit60", Firebase.getFloat("users/budi/beban3/data2/menit50"));
    Firebase.setFloat("users/budi/beban3/data2/menit50", Firebase.getFloat("users/budi/beban3/data2/menit40"));
    Firebase.setFloat("users/budi/beban3/data2/menit40", Firebase.getFloat("users/budi/beban3/data2/menit30"));
    Firebase.setFloat("users/budi/beban3/data2/menit30", Firebase.getFloat("users/budi/beban3/data2/menit20"));
    Firebase.setFloat("users/budi/beban3/data2/menit20", Firebase.getFloat("users/budi/beban3/data2/menit10"));
    Firebase.setFloat("users/budi/beban3/data2/menit10", Firebase.getFloat("users/budi/beban3/data2/daya"));
    Firebase.setFloat("users/budi/beban4/data2/menit60", Firebase.getFloat("users/budi/beban4/data2/menit50"));
    Firebase.setFloat("users/budi/beban4/data2/menit50", Firebase.getFloat("users/budi/beban4/data2/menit40"));
    Firebase.setFloat("users/budi/beban4/data2/menit40", Firebase.getFloat("users/budi/beban4/data2/menit30"));
    Firebase.setFloat("users/budi/beban4/data2/menit30", Firebase.getFloat("users/budi/beban4/data2/menit20"));
    Firebase.setFloat("users/budi/beban4/data2/menit20", Firebase.getFloat("users/budi/beban4/data2/menit10"));
    Firebase.setFloat("users/budi/beban4/data2/menit10", Firebase.getFloat("users/budi/beban4/data2/daya"));
    Firebase.setFloat("users/budi/beban1/data2/daya", daya1);
    Firebase.setFloat("users/budi/beban2/data2/daya", daya2);
    Firebase.setFloat("users/budi/beban3/data2/daya", daya3);
    Firebase.setFloat("users/budi/beban4/data2/daya", daya4);
  }
  //Firebase.setInt("arus2",12);
  //i=i+1;
  //delay(599000);//10menit
  delay(1000);
}
