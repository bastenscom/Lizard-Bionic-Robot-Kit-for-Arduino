/* -----------------------------------------------------------------------------
  - Project:   Lizzie the Lizard Robot
  - Version Date:      2025/11/11a
  - Author: Patrick Basten
   -----------------------------------------------------------------------------
  - Overview: This code was written for the Lizard robot desigened by Sunfounder to test the servo and ir receiver module..
  - for Arduino Nano
  - written with Arduino IDE 1.8.19 https://www.arduino.cc/en/software/
  - IRremote ver 4.5.0 https://arduino-irremote.github.io/Arduino-IRremote/classIRrecv.html

   ---------------------------------------------------------------------------*/
#include <IRremote.hpp>
#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;

int RECV_PIN = 7;
long unsigned int RcvdIR = 0; // must be defined as a 'long unsigned int' to alocated enough memory for larger numbers

void setup()
{
  Serial.begin(9600); 
  IrReceiver.begin(RECV_PIN,ENABLE_LED_FEEDBACK);
  myservo1.attach(4);
  myservo2.attach(3);
  myservo3.attach(2);
}

void loop()
{
  if (IrReceiver.decode()) {
      RcvdIR = IrReceiver.decodedIRData.decodedRawData;
      Serial.println(RcvdIR); // Print "old" raw data
      IrReceiver.resume(); // Enable receiving of the next value
      
      //initialize all servos
      if (RcvdIR == 3810328320){
        for (int i = 50; i < 130; i++)
        {
          myservo1.write(i);
          myservo2.write(i);
          myservo3.write(i);
          delay(20);
        }
        myservo1.write(90);
        myservo2.write(90);
        myservo3.write(90);
      }
  }
}



