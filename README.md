*unofficial Arduino to Eurotherm 2416* 
==============

The Project controls an [Eurotherm 2416](http://www.eurotherm.com/products/temperature-controllers/single-loop/2400) PID controller by an Arduino Mikrocontroller.
The Output of the Arduino can be more easily read than the register based ModBus Output. 
Modbus Protocol simplification is included in a separate libary that was also built from scratch.

Installation
============
* Install the ./libraries in your [Arduino libraries folder](https://www.arduino.cc/en/Guide/Libraries).

* open the Arduino application from the ./app directory with your arduino programming app and upload it.
* schematic for the electronics setup is included in the ./fritzing directory.
* basically a TTL to RS232 conversion is required as well as the appropriate adapter for the [Eurotherm 2416](http://www.eurotherm.com/products/temperature-controllers/single-loop/2400).

Dependencies
============
The program uses SofwareSerial which should be included in your Arduino IDE.

License
============
This Software is distributed under the MIT License.

This is no official Application and was enginered for educational purpose at the University of Wuerzburg, Germany in the group of T. Hertel. 

Eurotherm is a trademark of [Eurotherm USA](http://www.eurotherm.com) 44621 Guilford Drive, Suite 100, Ashburn, Virginia 20147.
