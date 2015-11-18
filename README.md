OSHTimer
========
*the Open Source Hardware lap timer*

Introduction
------------
This project is targetted on developing open source and open hardware RC / FPV
racing lap timing system.


Technical description
---------------------
### Transponder
For initial proof-of-concept IR transponder with static Sony modulated code has
been chosen. Custom single-sided board based on AVR attiny*4 has been designed
and published in `transponder/` directory of this repository, however only
testing has been carried out on generic "Digispark"-like attiny84 board with IR
LED directly soldered to respective pins so far. Software is available in
`transponder-software/` directory of this repository. It uses
[Arduino-IRRemote library](https://github.com/z3t0/Arduino-IRremote), which has
to be installed beforehand. Migration to ino or platformio build system is
planned in near future.

### Receiver
Ground receiver consists of TSOP17**-like IR receiver connected to any
Arduino-compatible AVR board. Current testing has been carried out on custom
atmega32u4 board, however published code should work flawlessly on any atmega
microcontroller which would fit the sketch. Software for this part is available
in `receiver-software/` directory, and, same as transponder, uses
Arduino-IRRemote library.


License
-------
Software part of this project is published under **MIT license**, unless
otherwise specified.

Hardware part of this project is published under **CERN Open Hardware License**,
unless otherwise specified.
