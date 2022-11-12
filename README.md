Github for Capstone A07 2022
================

## Group members
1. Aida Suswanto                (19/443561/TK/48757)
2. Andreas Pangaribuan          (19/446485/TK/49590)
3. Diah Ayu Widyati             (19/444046/TK/49242)
4. Kurnia Wisesa Kisna          (19/439611/TK/48341)
5. Gregorius Paskalis Dimas P   (19/446494/TK/49599)

## Project description

This project is used to monitor and control electric power in a room. This project uses 4 PZEM-004t v3 sensors to monitor electric power, a WEMOS D1 R1 to connect sensors to the database, Firebase Realtime Database to store data, and ESP-01/ESP8266 four ways wifi relay for controlling electric power.

## Library used
| Library    | Description |
|------------|-------------|
| [ESP8266](https://github.com/esp8266/Arduino) | To make Arduino IDE can program the WEMOS and use the WiFi |
| [Firebase Arduino](https://github.com/FirebaseExtended/firebase-arduino) | This project is using FIrebase Realtime Database, and this library is used to connect the WEMOS to the database |
| [ArduinoJson](https://github.com/bblanchon/ArduinoJson) | This library is required for Firebase Arduino. (Required version 5 at least version 5.13.1) |
| [PZEM-004T-v3.0](https://github.com/mandulaj/PZEM-004T-v30) | This project is using PZEM004Tv3.0 to monitor power |
| Software Serial | This library is used to add more serial in the microcontroller |
## References
1. [PZEM-004t-v3 datasheet](https://github.com/vortigont/pzem-edl/blob/main/docs/PZEM-004T-V3.0-Datasheet-User-Manual.pdf)
2. [ESP-01/ESP8266 four ways wifi relay](http://www.chinalctech.com/cpzx/Programmer/428.html)