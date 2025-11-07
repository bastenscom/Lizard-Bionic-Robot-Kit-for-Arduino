/* -----------------------------------------------------------------------------
  Author             : Nick
  Check              : 
  Version            : V1.0
  Date               : 11/01/2017
  Description        : Lizard robot
  Company website    : http://www.sunfounder.com
   ---------------------------------------------------------------------------*/

/* Include ------------------------------------------------------------------*/
#include <Servo.h>
#include <IRremote.h>

Servo Servo_1;
Servo Servo_2;
Servo Servo_3;

int RECV_PIN = 7;
int array_setup[] = {90,98,90};//Set the original angle of the servo
int angle1 = 25,angle2 = 35,angle3 = 55;
int delayedTime1 = 13;//The time needed for rotating 1 degree of the servo


long KEY_CODE_forward = 0xFF02FD;
long KEY_CODE_back = 0xFFC23D;
long KEY_CODE_ADD = 0xFF906F;
long KEY_CODE_SUB = 0xFFA857;
long KEY_CODE_playback = 0xFF9867;
long KEY_CODE_usd = 0xFFB04F;
long KEY_CODE_2 = 0xFF18E7;
long KEY_CODE_3 = 0xFF7A85;
long KEY_CODE_4 = 0xFF10EF;
long KEY_CODE_5 = 0xFF38C7;
long KEY_CODE_6 = 0xFF5AA5;
long KEY_CODE_7 = 0xFF42BD;
long KEY_CODE_8 = 0xFF4AB5;
long KEY_CODE_9 = 0xFF52AD;
long KEY_CODE_MODE = 0xFF629D;
long KEY_CODE_MUTE = 0xFFE21D;
long KEY_CODE_LONG_PRESS = 0xFFFFFFFF;
long longPressKey = -1;

IRrecv irrecv(RECV_PIN);
decode_results results;


/*
 - setup function
 * ---------------------------------------------------------------------------*/
void setup()
{
  //Start the serial for debug.
  Serial.begin(115200);
  irrecv.enableIRIn();

  //Attach the servos on pins to the servo object
  Servo_1.attach(4);
  Servo_2.attach(3);
  Servo_3.attach(2);
  Servo_1.write(array_setup[0]);
  Servo_2.write(array_setup[1]);
  Servo_3.write(array_setup[2]);
  delay(1000);
}

/*
 - loop function
 * ---------------------------------------------------------------------------*/
void loop()
{
  //Print the data.
  if (irrecv.decode(&results))
  {
    Serial.println(results.value,HEX);//Infrared encode of serial printing
    irrecv.resume();
  }

  //number 2 button
  if (results.value == KEY_CODE_2)
  {
    keyTwo();
  }

   //ADD button
  if (results.value == KEY_CODE_ADD)
  {
    delayedTime1 = 8;
    keyADD();
  }

   //number 5 button
  if (results.value ==KEY_CODE_5)
  {
    delayedTime1 = 16;
    keyFive();
  }

   //number 4 button
  if (results.value == KEY_CODE_4)
  {
    keyFour();
  }

   //number 6 button
  if (results.value == KEY_CODE_6)
  {
    keySix();
  }

   //number 8 button
  if (results.value == KEY_CODE_8)
  {
    keyEight();
  }

   //SUB button
   if (results.value == KEY_CODE_SUB)
  {
     keySUB();
  }
  }
