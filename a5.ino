#include <IRremote.h>

int gatepin = 9; // sets up 9 as pin connected to led strip
int remotepin = 3; // sets up 3 as remote pin

IRrecv irrecv(remotepin);
decode_results results;

#define IR_BUTTON_2 24 // defines code 24 as linked to button 2
#define IR_BUTTON_3 94 // defines code 94 as linked to button 3


void setup() {
  // put your setup code here, to run once:  
  pinMode(gatepin, OUTPUT); // defines ledstrip as output
  Serial.begin(9600); //starts serial count
  irrecv.enableIRIn();; //receiver start collecting data 
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode()) { //if IR receiver codes input
    irrecv.resume(); // continue coding input
    int command = irrecv.decodedIRData.command; // creates command
    switch (command) { // switches the commond to different use cases
      case IR_BUTTON_2: { // when button 2 is pressed
        Serial.println("Pressed on button 2"); // serial prints what is happening
        analogWrite(gatepin, 255); // and turns LEDstrip on
      }
      case IR_BUTTON_3: { // when button 2 is pressed
        Serial.println("Pressed on button 3"); // serial prints what is happening
        analogWrite(gatepin, 0); // and turns LEDstrip on
      }
}
}
}
