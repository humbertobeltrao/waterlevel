#include <Arduino.h>

int echoPin = 2;  //Define Echo pin
int trigPin = 3;     // Define Trig pin
long  inches, duration, cm;   //Define variables
int height=6; //define depth of tank in cm
int firstLED = 4; // define LEDs pin
int secondLED = 5;
int thirdLED = 6;
int fourthLED = 7;

void setup() {

Serial.begin (9600);
pinMode(trigPin, OUTPUT);  //Define output pin
pinMode(firstLED, OUTPUT);
pinMode(secondLED, OUTPUT);
pinMode(thirdLED, OUTPUT);
pinMode(fourthLED, OUTPUT);
pinMode(echoPin, INPUT);  //Define input pin

}


void loop()
{
//Give a short low pulse  to trigPin for ensure a clean high pulse
digitalWrite(trigPin, LOW);
delayMicroseconds(5);

//give high pulse to trigPin 10 microseconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);

digitalWrite(trigPin, LOW);

// Read the signal from the sensor
duration = pulseIn(echoPin, HIGH);

// convert time into a distance
// The speed of sound is 29.1 microseconds per centimeter.
cm = (duration/2) / 29.1;

//Print distance
Serial.print(cm);
Serial.print("cm");
Serial.println();

if (cm >= (3*height/4)) {
    digitalWrite(firstLED, HIGH);
    digitalWrite(secondLED, LOW);
    digitalWrite(thirdLED, LOW);
    digitalWrite(fourthLED, LOW);
  } 
else if(cm >= (height/2)){
    digitalWrite(firstLED, HIGH);
    digitalWrite(secondLED, HIGH);
    digitalWrite(thirdLED, LOW);
    digitalWrite(fourthLED, LOW);
  }
else if(cm >= (height/4)){
    digitalWrite(firstLED, HIGH);
    digitalWrite(secondLED, HIGH);
    digitalWrite(thirdLED, HIGH);
    digitalWrite(fourthLED, LOW);
  }
else if(cm <= 10){
    digitalWrite(firstLED, HIGH);
    digitalWrite(secondLED, HIGH);
    digitalWrite(thirdLED, HIGH);
    digitalWrite(fourthLED, HIGH);
  }

}