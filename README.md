*unofficial Arduino to Eurotherm 2416* 
==============

The Project controls an [Eurotherm 2416](http://www.eurotherm.com/products/temperature-controllers/single-loop/2400) PID controller by an Arduino Mikrocontroller.
The Output of the Arduino can be more easily read than the register based ModBus Output. 
Modbus Protocol simplification is included in a separate libary that was also built from scratch.

Installation
============
* Install the ./libraries in your [Arduino libraries folder](https://www.arduino.cc/en/Guide/Libraries).

* open the Arduino application from the ./app directory with your arduino programming app and upload it.
* software serial is used in this example to don't interfere with the USB-Port-Communication on PIN 0 and 1.
  * You can try to convert the TTL-Signal directly by Software to RS232 but be reminded, that pure RS232 is 12V while the arduino uses 5V for signal high values. There is a commented line in the example app.ino to do this by software.
  * better way is a TTL to RS232 conversion with a MAX232 and some capacitors. See the schematics a view lines down.
* required is also the appropriate RS232 output hardware module for the [Eurotherm 2416](http://www.eurotherm.com/products/temperature-controllers/single-loop/2400). You can stick it by first removing the Controller from the front.

Dependencies
============
The program uses SofwareSerial which should be included in your Arduino IDE.

Schematics
============
schematic for the electronics setup is included in the ./fritzing directory:
![breadboard](https://github.com/ukos-git/arduino-eurotherm2416/blob/master/fritzing/arduino-breadboard.png)

License
============
This Software is distributed under the MIT License.

This is no official Application and was enginered for educational purpose at the University of Wuerzburg, Germany in the group of T. Hertel. 

Eurotherm is a trademark of [Eurotherm USA](http://www.eurotherm.com) 44621 Guilford Drive, Suite 100, Ashburn, Virginia 20147.
