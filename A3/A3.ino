#include <Servo.h> // adding servo library
Servo servo; // assigning name to servo

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int sensorMin = 1023;       // sets the sensor minimun to highest value before calibrating
int sensorMax = 0;          // sets the sensor maximun to lowest value before calibrating
int posChange = 0;          // defines the position change for each loop pass

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);         // sets bps rate
servo.attach(9);            // connect servo to pin 9
servo.write(0);             // move servo to position 0


  while(millis()< 5000){    // calibration loop, runs for 5 seconds
    
    if(analogRead(analogInPin) < sensorMin){  // opens when sensor reads below current minimum reading
      sensorMin = analogRead(analogInPin);    // sets new minimun to current value
    }

    if(analogRead(analogInPin) > sensorMax){  // opens when sensor reads above current maximun reading
      sensorMax = analogRead(analogInPin);    // set new maximun to current value
    }
  }

}

void loop() {

  for(int i = 0; i < 181; i += posChange){ // loop moves servo from 0 to 180
    sensorValue = constrain(analogRead(analogInPin), sensorMin, sensorMax); // reads the photoresistor, constrained to calibrated min/max
    posChange = constrain(map(sensorValue, sensorMin, sensorMax, 25, 1), 1, 25); // sets the index change based on sensor value, constrained 1-25
    servo.write(i); // moves motor position to index value
    delay(15); // short pause
  }

  for(int i = 180; i > -1; i -= posChange){ // loop moves servo 180 to 0
    sensorValue = constrain(analogRead(analogInPin), sensorMin, sensorMax); // reads the photoresistor, constrained to calibrated min/max
    posChange = constrain(map(sensorValue, sensorMin, sensorMax, 25, 1),1,25); // sets the index change based on sensor value, constrained 1-25
    servo.write(i); // moves motor position to index value
    delay(15); //short pause
  }

  
}
