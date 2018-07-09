/*
   Sketch to handle each sample read from a PulseSensor.
   Typically used when you don't want to use interrupts
   to read PulseSensor voltages.

   Here is a link to the tutorial that discusses this code
   https://pulsesensor.com/pages/getting-advanced

   Copyright World Famous Electronics LLC - see LICENSE
   Contributors:
     Joel Murphy, https://pulsesensor.com
     Yury Gitman, https://pulsesensor.com
     Bradford Needham, @bneedhamia, https://bluepapertech.com

   Licensed under the MIT License, a copy of which
   should have been included with this software.

   This software is not intended for medical use.
*/

/*
   Every Sketch that uses the PulseSensor Playground must
   define USE_ARDUINO_INTERRUPTS before including PulseSensorPlayground.h.
   Here, #define USE_ARDUINO_INTERRUPTS false tells the library to
   not use interrupts to read data from the PulseSensor.

   If you want to use interrupts, simply change the line below
   to read:
     #define USE_ARDUINO_INTERRUPTS true

   Set US_PS_INTERRUPTS to false if either
   1) Your Arduino platform's interrupts aren't yet supported
   by PulseSensor Playground, or
   2) You don't wish to use interrupts because of the side effects.

   NOTE: if US_PS_INTERRUPTS is false, your Sketch must
   call pulse.sawNewSample() at least once every 2 milliseconds
   to accurately read the PulseSensor signal.
*/

#define USE_ARDUINO_INTERRUPTS false
#include <PulseSensorPlayground.h>


const int PULSE_INPUT = A0;
const int THRESHOLD = 550;   // Adjust this number to avoid noise when idle


/*
   All the PulseSensor Playground functions.
*/
PulseSensorPlayground pulseSensor;

void setup() {

  Serial.begin(115200);
  delay(10);

  // Configure the PulseSensor manager.
  pulseSensor.analogInput(PULSE_INPUT);

  pulseSensor.setSerial(Serial);
  pulseSensor.setThreshold(THRESHOLD);

  
}


void loop() {
  
  int myBPM = pulseSensor.getBeatsPerMinute();
  
  if (pulseSensor.sawNewSample()) {
      Serial.println("tiga");
      if (pulseSensor.sawStartOfBeat()) {
       //Serial.println("♥  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
       Serial.print("BPM: ");                        // Print phrase "BPM: " 
       Serial.println(myBPM);                        // Print the value inside of myBPM.     
       }
  }


}
