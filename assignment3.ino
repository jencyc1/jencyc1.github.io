#include <Servo.h> //includes the servo library

Servo servo1; // initializes the servo 
int ledPin = 6; //names ledPin as pin 6 for future analog writing

void setup() { //setup code
  pinMode(A0, INPUT); // makes Analog pin 0 (photoresistor) the input pin
  pinMode(10, OUTPUT); // makes pin 10 (led pin) the output pin
  servo1.attach(9); // sets up pin 9 to be attatched to the servo
  Serial.begin(9600); // sets up pin 9 to be attatched to the servo

}

void loop() { // put your main code goes here
  int light = analogRead(A0); // sets up photoresistor to read values
  Serial.println(light); // prints photoresistor values so I can see high and low values of the amount of light in the area I'm in

  if (light < 350) { // if I am not blocking the light (when the light is blocked, serialprint shows it yields value around 350)
    servo1.write(map(light, 350, 700, 0, 180)); // makes servo value rotate based on amount of light there is
    analogWrite(6, map(light, 350, 700, 0, 255)); // makes light brighter based on amount of light photoresistor intakes
    }     

  
  else { // if photoresistor is taking in light higher than 350
    servo1.write(map(light, 350, 700, 0, 180)); // makes servo rotate less based on amount of light photoresistor intakes
    analogWrite(6, 0); // makes led turn off based on photoresistor intake
  }
}
