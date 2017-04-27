#include "RingoHardware.h"

  const int MULT = 1;
  const int VOLUME = 33;
  int counter = 0;
  int NOTES[51] = {
    NOTE_E6,
    NOTE_E6,
    NOTE_E6,
    NOTE_E6,
    NOTE_E6,
    NOTE_E6,
    NOTE_E6,
    NOTE_G6,
    NOTE_C6,
    NOTE_D6,
    NOTE_E6,
    NOTE_F6,
    NOTE_F6,
    NOTE_F6,
    NOTE_F6,
    NOTE_F6,
    NOTE_E6,
    NOTE_E6,
    NOTE_E6,
    NOTE_E6,
    NOTE_E6,
    NOTE_D6,
    NOTE_D6,
    NOTE_E6,
    NOTE_D6,
    NOTE_G6,
    NOTE_E6,
    NOTE_E6,
    NOTE_E6,
    NOTE_E6,
    NOTE_E6,
    NOTE_E6,
    NOTE_E6,
    NOTE_G6,
    NOTE_C6,
    NOTE_D6,
    NOTE_E6,
    NOTE_F6,
    NOTE_F6,
    NOTE_F6,
    NOTE_F6,
    NOTE_F6,
    NOTE_E6,
    NOTE_E6,
    NOTE_E6,
    NOTE_E6,
    NOTE_G6,
    NOTE_G6,
    NOTE_F6,
    NOTE_D6,
    NOTE_C6
  };

  int DUR[51] = {
    250,
    250,
    500,
    250,
    250,
    500,
    250,
    250,
    250,
    125,
    1000,
    250,
    250,
    250,
    125,
    250,
    250,
    250,
    125,
    125,
    250,
    250,
    250,
    250,
    500,
    500,
    250,
    250,
    500,
    250,
    250,
    500,
    250,
    250,
    250,
    125,
    1000,
    250,
    250,
    250,
    250,
    250,
    250,
    250,
    125,
    125,
    250,
    250,
    250,
    250,
    1000
  };
  

void setup(){
  
  HardwareBegin();        //initialize Ringo's brain to work with his circuitry
  PlayStartChirp();       //Play startup chirp and blink eyes
  SwitchMotorsToSerial(); //Call "SwitchMotorsToSerial()" before using Serial.print functions as motors & serial share a line
  RestartTimer();
  
}

    
void loop(){ 

  SetAllPixelsRGB(0, 128, 0);  
  SetPixelRGB(counter % 6, 255, 0, 0);

  PlayChirp(NOTES[counter % 50], VOLUME);

  delay(DUR[counter % 50] * MULT);

  OffChirp();

  delay(10);
  
  counter++;

} // end of loop() function

