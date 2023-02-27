/* void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

} */



void setup() {
  Serial.begin(9600);	// initialize serial communications
  pinMode(5, OUTPUT); // initializes 5 as output
}
 
void loop() {
  int photoresistor = analogRead(0); // read value from analog pin 0 
  int thermistor = analogRead(1); // read value from analog pin 1

// prints arrays of values
  Serial.print("[");
  Serial.print(photoresistor);
  Serial.print(",");
  Serial.print(thermistor);
  Serial.println("]");


  if (Serial.available() > 0) {   // if there's serial data 
  int inByte = Serial.read(); // read it
 	Serial.write(inByte);  	// send it back out as raw binary data
 	analogWrite(5, inByte);	// use it to set the LED brightness
  } 

}


