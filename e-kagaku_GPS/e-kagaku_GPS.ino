#include <Wire.h>
#include <SoftwareSerial.h> //シリアル通信用のライブラリ
#include <TinyGPS++.h>

SoftwareSerial gps(10, 11); //GPS のシリアル通信ポートの割り当て RX2 番ピン，TX3 番ピン
TinyGPSPlus tinyGPS;

void setup() {
  Serial.begin(9600); //PC とのシリアル通信開始
  gps.begin(9600); //GPS とのシリアル通信開始
  delay(2000);
}


void loop() {
  Serial.print(tinyGPS.location.lat(), 6);
  Serial.print(", ");
  Serial.println(tinyGPS.location.lng(), 6);

  smartDelay(1000);
}

void smartDelay(unsigned long ms){
 unsigned long start = millis();
 do{
 while(gps.available())
 tinyGPS.encode(gps.read());
 }while(millis()-start<ms);
}
