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
  * better way is a TTL to RS232 conversion with a [MAX232](https://github.com/ukos-git/arduino-eurotherm2416/blob/master/documents/UT232A.pdf) and some capacitors. See the schematics a view lines down.
* required is also the appropriate RS232 output hardware module for the [Eurotherm 2416](http://www.eurotherm.com/products/temperature-controllers/single-loop/2400). You can stick it by first removing the Controller from the front.

Dependencies
============
The program uses SofwareSerial which should be included in your Arduino IDE.

simple example
============
Take a look at the example [app.ino](https://github.com/ukos-git/arduino-eurotherm2416/blob/master/app/app.ino) in the app folder of the project. It should be self-explanatory.

A minimal example of setting once the temperature to 500°C and after that reading it and outputting it to the serial console is shown below. Start from here to build some more advanced features.

```c
#include <SoftwareSerial.h>
#include <MKModbus.h>
#include <MKTemperature.h>

SoftwareSerial Eurotherm2416(9, 8);           // Init Eurotherm PID Controller on Ports rx,tx,convert the ttl by hardware
MKModbus Modbus(Eurotherm2416);               // Init Modbus Protocol for Eurotherm PID Controller
MKTemperature Temperature(Modbus);            // Init Oven with attached Eurotherm Controller

void setup()
{
  Serial.begin(9600);
  Eurotherm2416.begin(9600);
  Temperature.set(500)
}

void loop()
{
  Serial.print(Temperature.getTemperature());
}
```

Schematics
============
schematic for the electronics setup is included in the ./fritzing directory:
![breadboard](https://github.com/ukos-git/arduino-eurotherm2416/blob/master/fritzing/arduino-breadboard.png)

License
============
This Software is distributed under the MIT License.

This is no official Application and was enginered for educational purpose at the University of Wuerzburg, Germany in the group of T. Hertel. 

Eurotherm is a trademark of [Eurotherm USA](http://www.eurotherm.com) 44621 Guilford Drive, Suite 100, Ashburn, Virginia 20147.
