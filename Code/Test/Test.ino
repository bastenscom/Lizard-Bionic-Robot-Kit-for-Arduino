/* -----------------------------------------------------------------------------
  - Project:   Test the servo and IR receiver module
  - Copyright: Copyright (C) 2015 SunFounder.
  - Date:      2017/11/21
  - Author: Nick
  - Email: service@sunfounder.com
  - Web: www.sunfounder.com
   -----------------------------------------------------------------------------
  - Overview
  - This code was written for the Lizard robot desigened by Sunfounder to test the servo and ir receiver module..
  - Request
  - This project requires a library - IRremote. Make sure you have installed the file.
  - How to
  - Before use,you must to test the servo and ir receiver module.
    - operation
        1.upload the code to test three servos
        2.comment Servo, uncomment RECEIVER
        3. upload the code again.
        4. open the serial monitor to see the value of ir receiver module.

   ---------------------------------------------------------------------------*/
#include <IRremote.h>
#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;

int RECV_PIN = 7;

//#define SERVO  //uncomment only this to test the ir receiver
#define RECEIVER  //uncomment only this to TEST the servos

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(115200); 
  irrecv.enableIRIn();
  myservo1.attach(4);
  myservo2.attach(3);
  myservo3.attach(2);
}

void loop()
{
#ifdef SERVO
  //initialize all servos
  for (int i = 0; i < 180; i++)
  {
    myservo1.write(i);
    myservo2.write(i);
    myservo3.write(i);
    delay(20);
  }
  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(90);
  while (1);
#endif
#ifdef RECEIVER
  if (irrecv.decode(&results))
  {
    Serial.println(results.value,HEX);
    irrecv.resume();
  }
#endif
}
