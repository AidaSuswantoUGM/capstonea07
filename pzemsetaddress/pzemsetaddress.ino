#include<PZEM004Tv30.h>

PZEM004Tv30 pzem(5,4);

void setup() {
  // put your setup code h7ere, to run once:
  Serial.begin(115200);
}

uint8_t addr=0x11;

void loop() {
  // put your main code here, to run repeatedly:
  pzem.setAddress(addr);
  Serial.println(pzem.getAddress());

  delay(2000);
}
