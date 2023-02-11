#include <CapacitiveSensor.h> // uses the Capacitive Sensor library
#include "pitches.h" // uses the pitches library

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);    	// 1 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, metal thing
const int sensorPin = 2;  // pin that the sensor is attached to 

int tempo = 140; // sets song speed at tempo of 140
int buzzer = 9; // sets buzzer pin as 9

int melody[] = {

  // Take on me, by A-ha
  // Score available at https://musescore.com/user/27103612/scores/4834399
  // Arranged by Edward Truong

  NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8, 
  REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
  NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8, 
  REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
  NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8, 
  
  REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
  NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8, 
  REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
  NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8, 
  REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,
  
  NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8, 
  REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,
  
};


int notes = sizeof(melody) / sizeof(melody[0]) / 2; // sets notes to be the number of bytes for the melody divided by the pitch and duration per note divided by 2

int wholenote = (60000 * 4) / tempo; //  calculates the duration of a whole note in ms

int divider = 0, noteDuration = 0;

void setup() {
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); 	// turns off autocalibrate 
  Serial.begin(9600); //  starts serial monitor
  digitalWrite(2, INPUT); // sets 2 (capacitive sensor as input)
  analogWrite(9,OUTPUT); // sets 9 (buzzer as output)
}

void loop() {

  long total1 =  cs_4_2.capacitiveSensor(30); //reads sensor output 
  
  Serial.println(total1);                  // print sensor output 

  if (total1 < 1000) { // when touched, the serial monitor printed values above 1000, hence if the serial monitor prints below 1000, there is no buzzer sound.
    noTone(buzzer); // no buzzer sound when sensor is not touched
  }

  else {
    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) { // per each note
      divider = melody[thisNote + 1]; // calculates note duration
      if (divider > 0) {   // if the divider has a value larger than 0
        noteDuration = (wholenote) / divider; //the note duration is divided by the diveder value
      } 
      else if (divider < 0) {    // if the divider is less than 0
        noteDuration = (wholenote) / abs(divider);
        noteDuration *= 1.5; // the note duration is increased by 1.5 (longer note)
      }

      tone(buzzer, melody[thisNote], noteDuration * 0.9);         // we only play the note for 90% of the duration, leaving 10% as a pause

      delay(noteDuration);   // Wait for the specief duration before playing the next note.
      noTone(buzzer); //stop playing after the song is over
      }
    } 
    
}


