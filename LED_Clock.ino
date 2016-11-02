// http://www.atmel.com/Images/Atmel-2549-8-bit-AVR-Microcontroller-ATmega640-1280-1281-2560-2561_datasheet.pdf
// page 133 is the beginning of the timer stuff
// page 154 is the register descriptions
#include "LED_Clock_helper.hpp"


dispInfo Info;

void setup() {
    initializeClockTimers(1,1);
    setupClockOutputs();
    Info.t = 5*3600 + 35*60;
    Serial.begin(9600);
    pinMode(13,OUTPUT);

}


void loop() {
   setClockPins(&Info);
   Serial.print(millis()*1000 - Info.t);
   Serial.println("-------------------");
}

ISR(TIMER4_COMPA_vect) { // The lower the Interrupt Vector address, the higher the priority. Table 14.1, p101
  Info.t = Info.t + 1; // increment time by 1 second
  digitalWrite(13,!digitalRead(13));
}

ISR(TIMER3_COMPA_vect) {
  
    PORTC = PORTC ^ 0x03; // Set cathode 0 low, cathode 1 high, so toggle pins C0 and C1
    PORTA = ((PORTC&0x01)* Info.PortAc1Pins) + (((PORTC&0x02)/2)*Info.PortAc2Pins);
    PORTC = (PORTC&0x03) + ((PORTC&0x01)* Info.PortCc1Pins) + (((PORTC&0x02)/2)*Info.PortCc2Pins);

  
}



