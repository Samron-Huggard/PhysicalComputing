
/*
 * Sam Ferguson
 * A1: Blink
 */


void setup() {
  // initializes digital pins 7-13 as outputs
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);

}

// initializes variables
float bpm = 100;
float time_per_beat = (60/bpm)*1000; //finds milliseconds per beat
float time_per_led = time_per_beat/6; //finds an equal amount of time for 6 LEDs per ber beat

void loop() {

  for (int i=7; i < 13; i++){  //this loop lights up the blue LED on the left then the green LEDs, going right
    digitalWrite(i, HIGH);      // turns the indexed LED on
    delay(time_per_led);        // holds with the LED on for calculated time
    digitalWrite(i, LOW);       // turns the idexed LED off
  }

  for (int i=13; i > 7; i--){ //this loop lights up the blue LED on the right then the green LEDs, going left
    digitalWrite(i, HIGH);    // turns the indexed LED on
    delay(time_per_led);      // holds with the LED on for calculated time
    digitalWrite(i, LOW);     // turns the idexed LED off
  }

}
