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
/* normally open
 * lampu nyala --> timer jalan 
 * if switch = true  --> nyala (aon, bon, con, don)
 *                   --> timer jalan (read time)
 */                 

void loop() {

  // definisikan user
  String user = "budi"

  // cek variabel ada orang
  String path_adaorang = "users/"+user+"/adaorang" ;
  bool adaorang = Firebase.getBool(path_adaorang);
  if(adaorang==true) {
    String data = "data1" ;
  } else {
    String data = "data2" ;
  }

  // baca switch, dan kalkulasi time 
  s1=Firebase.getBool("users/"+user+"/beban1/switch");
  s2=Firebase.getBool("users/"+user+"/beban2/switch");
  s3=Firebase.getBool("users/"+user+"/beban3/switch");
  s4=Firebase.getBool("users/"+user+"/beban4/switch");

  // switch 1 == true, alat nyala, timer jalan
  if(s1==true){
    Serial.write(aon, sizeof(aon));
    String time_path = "users/" + user + "/beban1/" + data + "/time" ;
    int time1 = Firebase.getInt(time_path) ;
    int time = time1 + 1;
    Firebase.setInt(time_path, time) ;
  } else {
    Serial.write(aof, sizeof(aof));
  }
  delay(400);

  // switch 2 == true, alat nyala, timer jalan
  if(s2==true){
    Serial.write(bon, sizeof(bon));
    String time_path = "users/" + user + "/beban2/" + data + "/time" ;
    int time2 = Firebase.getInt(time_path) ;
    int time = time2 + 1;
    Firebase.setInt(time_path, time) ;
  } else {
    Serial.write(bof, sizeof(bof));
  }
  delay(400);

  // switch 3 == true, alat nyala, timer jalan
  if(s3==true){
    Serial.write(con, sizeof(con));
    String time_path = "users/" + user + "/beban3/" + data + "/time" ;
    int time3 =Firebase.getInt(time_path) ;
    int time = time3 + 1;
    Firebase.setInt(time_path, time) ;
  } else {
    Serial.write(cof, sizeof(cof));
  }
  delay(400);

  // switch 4 == true, alat nyala, timer jalan
  if(s4==true){
    Serial.write(don, sizeof(don));
    String time_path = "users/" + user + "/beban4/" + data + "/time" ;
    int time4 = Firebase.getInt(time_path) ;
    int time = time4 + 1;
    Firebase.setInt(time_path, time) ;
  } else {
    Serial.write(dof, sizeof(dof));
  }
  delay(400);
}
