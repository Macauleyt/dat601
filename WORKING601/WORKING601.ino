/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, 6, NEO_GRB + NEO_KHZ800);



// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;

// defines variables
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication

  strip.begin();
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);




 if (distance <= 10) {                                                                 // If motion sensor 2 (Downstairs) if high go to next line
          rainbow (20);
          strip.show();
          delay(100);
         
          //colorChase (strip.Color(255, 25, 25), 5);
          //colorChase2 (strip.Color(25, 255, 25), 5);
          //colorChase (strip.Color(25, 25, 255), 5);
         
          strip.show();
                                 }  

delay(100);


 if (distance >= 10 && distance <20) {                                                                 // If motion sensor 2 (Downstairs) if high go to next line
          colorWipe2 (strip.Color(255, 0, 0), 5);
          strip.show();
          delay(100);
         
          //colorChase (strip.Color(255, 25, 25), 5);
          //colorChase2 (strip.Color(25, 255, 25), 5);
          //colorChase (strip.Color(25, 25, 255), 5);
          colorWipe2 (strip.Color(0, 0, 0), 0);
          strip.show();
                                 }  

delay(100);
}








void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}   


uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}






void colorWipe2(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
                                              }
                                          }
