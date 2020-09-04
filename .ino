// these constants won't change: 
//Modified to work with ATtiny85 from Arduino nano
const int analogPin1 = A1;// Antenne  Analog
const int ledCount = 4;// Number leds
const int buzzerPin = 0; //Buzzer

int ledPins[] = {
     1, 3, 4 };// Pin  Leds

void setup() { //Serial.begin(9600);// loop : 
for (
  int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    }
    }

void loop() {// read the potentiometer: 
  float sensorReading1 = (float)analogRead(analogPin1);
  int sensorResult = (int)(sensorReading1);
  // map the result to a range from 0 to the number of LEDs: 
  int ledLevel = map(sensorResult, 0, 700, 0, ledCount);
//  Serial.println(sensorResult); 
  delay(10); 
  
// loop over the LED array: 
for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    // if the array element's index is less than ledLevel, 
    // turn the pin for this element on: 
    if (thisLed < ledLevel) { 
    digitalWrite(ledPins[thisLed], HIGH);
    tone(buzzerPin, 10);
   //digitalWrite(buzzerPin, HIGH);
    }
    // turn off all pins higher than the ledLevel: 
    else { digitalWrite(ledPins[thisLed], LOW);
   //noTone(buzzerPin);
   digitalWrite(buzzerPin, LOW);
    }
  }
  //delay(1000);
}
