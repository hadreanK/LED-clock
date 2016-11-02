# LED-clock
This project is for controlling the LED display I ripped out of a broken alarm clock.
The main file is LED_Clock.ino, which is an arduino file for use with the Arduino compiler and uploader.
There are 3 support files:
  LED_Clock_helper.cpp -  Support functions called in the LED_Clock master file. 
                          Code is in C, but made it a .cpp file to allow for addition of classes later
  LED_Clock_helper.hpp -  Associated header file
  LED_Pin_Helper.h - Contains a mapping of the LEDs on the display to the pinout on the LED's PCB
