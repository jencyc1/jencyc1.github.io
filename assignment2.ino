int ButtonValue = 0; //when button is not pressed, sets pin value as 0

int Button = 3; // sets button at pin 3


void setup() { // setup code 
  pinMode(Button, INPUT); // sets input button at pin 3
  pinMode(9, OUTPUT); // sets pin 9 as output button 
  pinMode(10, OUTPUT); // sets pin 9 as output button
  pinMode(11, OUTPUT); // sets pin 9 as output button
}

void loop() { // put your main code
  ButtonValue = digitalRead(Button); // reads button
  if (ButtonValue != 0) { // if button is on
    for (int thisPin = 9; thisPin < 12; thisPin++) { // for buttons 9-11
      for (int i = 0; i < 255;i++){ // sets for loop for  lights to fade on from 0-255
        analogWrite(thisPin, i); // causes lights to fade on from 0-255
        delay(10); //10 ms delay as lights dim
    }
  }
  }

  else { //if button value is 0
    for (int thisPin = 9; thisPin < 12; thisPin++) //for pins 9-11
    digitalWrite(thisPin, LOW); //do not turn on pins
  }
}
