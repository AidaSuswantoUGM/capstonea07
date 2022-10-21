//#include <SoftwareSerial.h>
#include<PZEM004Tv30.h>
#include<ESP8266WiFi.h>
#include<FirebaseArduino.h>
#include<wpa2_enterprise.h>

 
#define FIREBASE_HOST "capstonea07-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "z2LkpOQOm2qjaP1s8h2BPggQq9T9twBwNzSILnAi"

#define PZEM_RX_PIN D5
#define PZEM_TX_PIN D6

//SoftwareSerial pzemSWSerial(PZEM_RX_PIN, PZEM_TX_PIN);
PZEM004Tv30 pzem(PZEM_RX_PIN, PZEM_TX_PIN, 0x02);

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
  //pzem=PZEM004Tv30(pzemSWSerial);
}
int i=0;
 
void loop() {
  //Serial.println(pzem.readAddress(), HEX);
  //float teg=pzem.voltage();
  //Serial.println(teg);
  //if(isnan(teg)){
  //  teg=0;
  //}
  //float arus=pzem.current();
  //Serial.println(teg);
  //if(isnan(arus)){
  //  arus=0;
  //}
  //float daya=pzem.power();
  //if(isnan(daya)){
  //  daya=0;
  //}
  Firebase.setInt("teg1", i);
  if(Firebase.failed()){
    firebaseerror();
  }
  Firebase.setInt("arus1", i+10);
  if(Firebase.failed()){
    firebaseerror();
  }
  Firebase.setInt("daya1", i+20);
  if(Firebase.failed()){
    firebaseerror();
  }
  //Firebase.setInt("arus2",12);
  i=i+1;
  delay(1000);
}
