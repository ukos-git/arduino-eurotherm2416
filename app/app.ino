#include <SoftwareSerial.h>
#include <MKModbus.h>
#include <MKTemperature.h>

//SoftwareSerial Eurotherm2416(9, 8, true);   // Init Eurotherm PID Controller on Ports rx,tx,convert the ttl by software
SoftwareSerial Eurotherm2416(9, 8);           // Init Eurotherm PID Controller on Ports rx,tx,convert the ttl by hardware
MKModbus Modbus(Eurotherm2416);               // Init Modbus Protocol for Eurotherm PID Controller
MKTemperature Temperature(Modbus);            // Init Oven with attached Eurotherm Controller

#include <MKUserInput.h>
MKUserInput Input;

#include <MKMath.h>
MKMath Math;

long runtime=0;

void setup()
{
  //INIT
  Serial.begin(9600);
  Eurotherm2416.begin(9600);
  Input.setInput(Serial);
}

void loop()
{ 
  checkinput();
  Serial.print((float)millis()/1000.0);
  Temperature.batch(Math,2); //Temperature change is very low and Modbus protocol is slow
  printTemperature(); 
  Serial.println();
  secure();
}

void secure()
{
  if (Pressure.getValue()>980.0)
  { 
      Argon.set(0);
      Ethanol.set(0);
      //Pressure.set(1000);
  }
    
}

void printTemperature()
{
  Serial.print("\tTemp\t");
  Serial.print(Temperature.getTemperature());
  Serial.print("\t");
  Serial.print(Temperature.getTDeviation());
  Serial.print("\t");
  Serial.print(Temperature.getError());  
  Serial.print("\t");
  Serial.print(Temperature.getSetPoint());
  
  Serial.print("\tPower\t");  
  Serial.print(Temperature.getPower());
/*  Serial.print("\t");
  Serial.print(Temperature.getPDeviation());
  Serial.print("\t");
  Serial.print(Temperature.getError());
  Serial.print("\t");
  Serial.print(Temperature.getSetPointPower());  */
}

void checkinput()
{
  Input.waitfor('t','/');  
    if (Input.ready()) { Temperature.set(Input.receive()); }
  Input.waitfor('d',',');
    if (Input.ready()) 
    { 
      word value = Input.receive();
      switch (value) {
      case 1:
        Temperature.debug(Serial);
      break;
      case 2:
        Input.debug(Serial);
      break;      
      case 3:
        Math.debug(Serial);
      break;
      case 4:
        Modbus.debug(Serial);
      break;      
      }
    } 
  Input.clear();  
}

