int trig = 9;
int echo = 10;
int mosfet = 3;
int mic = 12;
float distance = 0;
int brightness = 0;
int readings[10] = {0,0,0,0,0,0,0,0,0,0};
int total = 0;
int brightAvg = 0;
bool dimmer = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(mosfet, OUTPUT);
  pinMode(mic, INPUT);
  Serial.begin(9600);
  analogWrite(mosfet, 255);
  delay(1000);
   
}

void loop() {

  
  if(digitalRead(mic) == HIGH){
    dimmer = !dimmer;
    while(digitalRead(mic) == HIGH){
    }
  }

  Serial.println(dimmer);

  if(dimmer == 1){

    digitalWrite(trig, LOW);  
    delayMicroseconds(2);  
    digitalWrite(trig, HIGH);  
    delayMicroseconds(10);  
    digitalWrite(trig, LOW);
    distance = pulseIn(echo, HIGH);
    brightness = map(distance, 400, 4000, 0, 255);
    brightness = constrain(brightness, 0, 255);
  }
  
  
  total = brightness;

  for(int i = 0; i <= 9; i++){
    total = total + readings[i];
  }
  
  brightAvg = total / 11;
  analogWrite(mosfet, brightAvg);
  
  for(int i = 9; i > 0; i--){ 
    readings[i] = readings[i-1];
  }
  readings[0] = brightAvg;  
}
