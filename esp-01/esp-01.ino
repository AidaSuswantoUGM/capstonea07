#include<ESP8266WiFi.h>
#include<FirebaseArduino.h>

#define FIREBASE_HOST "capstonea07-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "z2LkpOQOm2qjaP1s8h2BPggQq9T9twBwNzSILnAi"

bool s1, s2, s3, s4;
byte aof[]={0xA0, 0x01, 0x00, 0xA1};
byte aon[]={0xA0, 0x01, 0x01, 0xA2};
byte bof[]={0xA0, 0x02, 0x00, 0xA2};
byte bon[]={0xA0, 0x02, 0x01, 0xA3};
byte cof[]={0xA0, 0x03, 0x00, 0xA3};
byte con[]={0xA0, 0x03, 0x01, 0xA4};
byte dof[]={0xA0, 0x04, 0x00, 0xA4};
byte don[]={0xA0, 0x04, 0x01, 0xA5};

void setup() {
  WiFi.begin("asuswa", "rangertiakupaswo");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Serial.begin(115200);
}

void loop() {
  s1=Firebase.getBool("users/budi/data1/beban1/switch");
  s2=Firebase.getBool("users/budi/data1/beban1/switch");
  s3=Firebase.getBool("users/budi/data1/beban1/switch");
  s4=Firebase.getBool("users/budi/data1/beban1/switch");
  if(s1==true){
    Serial.write(aon, sizeof(aon));
  }
  if(s1==false){
    Serial.write(aof, sizeof(aof));
  }
  delay(400);
  if(s2==true){
    Serial.write(bon, sizeof(bon));
  }
  if(s2==false){
    Serial.write(bof, sizeof(bof));
  }
  delay(400);
  if(s3==true){
    Serial.write(con, sizeof(don));
  }
  if(s3==false){
    Serial.write(cof, sizeof(dof));
  }
  delay(400);
  if(s4==true){
    Serial.write(don, sizeof(don));
  }
  if(s4==false){
    Serial.write(dof, sizeof(dof));
  }
  delay(400);
}
