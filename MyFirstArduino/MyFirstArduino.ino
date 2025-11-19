/*  ===============================================================================================
    - Project:   My First Arduio
    - Version Date:      2025/11/19a
    - Author: Patrick Basten - Bastens.com 
    ===============================================================================================
    - Overview: This code was written for teaching arduino code
    - hardware: Arduino Nano (Leonardo in IDE)
    ===============================================================================================
*/

// ===============================================================================================
// Arduino ProMini/Nano/UNO Notes:
// External Interrupts: 2 and 3.
// PWM: 3, 5, 6, 9, 10, and 11 (PWM does not work on pins 9 and 10 if using Servo.h)
// Nano has 8 analog inputs, each of which provide 10 bits of resolution (i.e. 1024 different values)
// Analog pins 6 and 7 cannot be used as digital pins
// AREF. Reference voltage for the analog inputs. Used with analogReference()
// use analog pins A0...A5 as digital pins by numbering them 14...19 
// ===============================================================================================

#include <Servo.h>
Servo MyServo;

#include <Adafruit_NeoPixel.h>
#define LED_PIN    7
#define NUM_LEDS   4
Adafruit_NeoPixel LEDstrip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{ 
  MyServo.attach(2);

  LEDstrip.begin(); // Initialize the NeoPixel library.
  LEDstrip.setBrightness(255);
  LEDstrip.show();  // Turn all pixels off (clear the strip).
}

void loop()
{
  MyServo.write(20);
  LEDstrip.clear();
  LEDstrip.setBrightness(150);
  LEDstrip.setPixelColor(0, LEDstrip.Color(255, 0, 0));
  LEDstrip.setPixelColor(1, LEDstrip.Color(255, 255, 0));
  LEDstrip.setPixelColor(2, LEDstrip.Color(0, 255, 0));
  LEDstrip.setPixelColor(3, LEDstrip.Color(0, 0, 255));
  LEDstrip.show();
  delay(2000);
  
  MyServo.write(90);
  LEDstrip.clear();
  LEDstrip.setBrightness(200);
  for (int i = 0; i < NUM_LEDS; i++) { // Example 3: Create a simple chasing effect
    LEDstrip.setPixelColor(i, LEDstrip.Color(0, 255, 0));
    LEDstrip.show();
    delay(250);
    LEDstrip.clear();
  }
  delay(250);
  
  MyServo.write(160);
  LEDstrip.clear();
  LEDstrip.setBrightness(100);
  LEDstrip.setPixelColor(0, LEDstrip.Color(0, 0, 255));
  LEDstrip.setPixelColor(1, LEDstrip.Color(0, 0, 255));
  LEDstrip.setPixelColor(2, LEDstrip.Color(0, 0, 255));
  LEDstrip.setPixelColor(3, LEDstrip.Color(0, 0, 255));
  LEDstrip.show();
  delay(2000);
}




