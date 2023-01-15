int timer = 1; // sets timer for per half second

void setup() { // setup includes initializing pins as output 
  for (int thisPin = 11; thisPin < 14; thisPin++) { // use a for loop to initialize each pin as an output:
    pinMode(thisPin, OUTPUT); // initializes pins 11, 12, and 13, as output 
  }
}

void loop() { // allows for me to set up code for LED lights to turn on
  for (int thisPin = 11; thisPin < 14; thisPin++) { // loops from the lowest pin to the highest
    digitalWrite(thisPin, HIGH); // turns pin on
    delay(timer); // sets time before pin turns off
    digitalWrite(thisPin, LOW); // turn the pin off
  }
}