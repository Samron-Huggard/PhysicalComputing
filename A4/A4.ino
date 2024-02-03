#include <dht.h>
#include <SevSeg.h> 

SevSeg sevseg;
dht DHT;
#define DHT11_PIN A0
int hum = 0;
int sense = 0;




byte numDigits = 4;  
byte digitPins[] = {0, 0, 5, 4};
byte segmentPins[] = {11, 13, 9, 7, 6, 12, 10, 8};
bool resistorsOnSegments = false; 

unsigned long previousMillis = 0;
const long interval = 10000;


void setup() {

    sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
    sevseg.setNumber(88,0);
}

void loop() {
  long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;
    sense = DHT.read11(DHT11_PIN);
    
    sevseg.setNumber(DHT.humidity,0);
  }
      

sevseg.refreshDisplay();

}
