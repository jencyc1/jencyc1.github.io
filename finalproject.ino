#include <IRremote.hpp>

int photoresistor = A1; // sets up A1 as pin connected to photoresistor
int gatepin = 6; // sets up 6 as pin connected to led strip
int remotepin  = 3; // sets up 3 as pin connected to IR remote 

// variables:
int command;

IRrecv irrecv(remotepin); // intializes remotepin as IR receiver
decode_results results; // provides coded results

#define IR_BUTTON_2 24 // defines code 24 as linked to button 2
#define IR_BUTTON_3 94 // defines code 94 as linked to button 3


void setup() {
  // put your setup code here, to run once:  
  Serial.begin(9600); //starts serial count
  IrReceiver.begin(remotepin, ENABLE_LED_FEEDBACK); // Start the receiver
  pinMode(gatepin, OUTPUT); // defines ledstrip as output
  pinMode(photoresistor, INPUT); // defines photoresistor as input
  pinMode(remotepin, INPUT); // defines remotepin as input
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume(); // Enable receiving of the next value     
    Serial.println(IrReceiver.decodedIRData.command); // Prints "old" raw data
    command = IrReceiver.decodedIRData.command; // creates command
    if (command == IR_BUTTON_2) { // when button 2 is pressed
      Serial.println("Pressed on button 2"); // serial prints what is happening
      analogWrite(gatepin, 255); // and turns LEDstrip on
    }
    else if (command == IR_BUTTON_3) { // when button 2 is pressed
      Serial.println("Pressed on button 3"); // serial prints what is happening
      analogWrite(gatepin, 0); // and turns LEDstrip off
    }
  } 

  if (command != IR_BUTTON_2) { // if button 2 is not pressed
    int photo = analogRead(photoresistor); // read and store photoresistor values
    Serial.println(photo); // prints photoresistor values so that I can determine when it's light and when it's dark
    if (photo < 500) { // if the value is less than 500 (the number is calculated based on serial count of light in my hallway.)
      analogWrite(gatepin, 255); // turns LED strip on.
    } 
    else {
      analogWrite(gatepin, 0); // otherwise, turns LED strip off.
    }
  }
}

 


