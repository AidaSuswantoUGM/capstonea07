#include <SoftwareSerial.h>
#include<PZEM004Tv30.h>
#include<ESP8266WiFi.h>
#include<FirebaseArduino.h>
#include<wpa2_enterprise.h>

 
#define FIREBASE_HOST "capstonea07-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "z2LkpOQOm2qjaP1s8h2BPggQq9T9twBwNzSILnAi"

#define PZEM_RX_PIN D5
#define PZEM_TX_PIN D6

//char ssid[] = "UGM-Secure";
//char username[] = "suswanto.aida";
//char identity[] = "suswanto.aida";
//char password[] = "";
//uint8_t wemos_mac[6]={0x5c, 0xcf, 0x7f, 0xfc, 0x51, 0x80};

//SoftwareSerial pzemSWSerial(PZEM_RX_PIN, PZEM_TX_PIN);
SoftwareSerial pzemserial(D5, D6);
//PZEM004Tv30 pzem(PZEM_RX_PIN, PZEM_TX_PIN, 0x02);
PZEM004Tv30 pzem;

void firebaseerror(){
  Serial.println(Firebase.error());
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
}

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
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  if(Firebase.failed()){
    firebaseerror();}
  digitalWrite(LED_BUILTIN, LOW);
  pzem=PZEM004Tv30(pzemserial,0x01);
  //Serial.println(WiFi.macAddress());
}
//int i=0;
 
void loop() {
  Serial.println(pzem.readAddress(), HEX);
  float teg=pzem.voltage();
  Serial.println(teg);
  if(isnan(teg)){
    teg=0;
  }
  float arus=pzem.current();
  Serial.println(teg);
  if(isnan(arus)){
    arus=0;
  }
  float daya=pzem.power();
  if(isnan(daya)){
    daya=0;
  }
  Firebase.setInt("teg1", teg);
  if(Firebase.failed()){
    firebaseerror();
  }
  Firebase.setInt("arus1", arus*1000);
  if(Firebase.failed()){
    firebaseerror();
  }
  Firebase.setInt("daya1", daya);
  if(Firebase.failed()){
    firebaseerror();
  }
  //Firebase.setInt("arus2",12);
  //i=i+1;
  delay(1000);
}
