/* -----------------------------------------------------------------------------
  - Project:   My First Arduio
  - Version Date:      2025/11/17a
  - Author: Patrick Basten
   -----------------------------------------------------------------------------
  - Overview: This code was written for teaching arduino code
  - Arduino Nano
  - written using Arduino IDE 1.8.19 https://www.arduino.cc/en/software/

   ---------------------------------------------------------------------------*/

#include <Servo.h>
Servo MyServo;

#include <FastLED.h> // written with version 3.10.3
#define LED_PIN     7
#define NUM_LEDS    4
#define BRIGHTNESS  150  // 0-255, adjust as needed

#define COLOR_ORDER RGB // important to set using calibration ino, may be different order per different manufactures
CRGB leds[NUM_LEDS];


void setup()
{ 
  MyServo.attach(2);

  FastLED.addLeds <WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  // Set global brightness (optional)
  FastLED.setBrightness(BRIGHTNESS);
  // Clear all LEDs to off
  FastLED.clear();
  FastLED.show(); 
  
}

void loop()
{
  MyServo.write(10);
  FastLED.clear();
  leds[0] = CHSV( HUE_GREEN, 255, BRIGHTNESS);
  leds[1] = CHSV( HUE_YELLOW, 255, BRIGHTNESS);
  leds[2] = CHSV( HUE_RED, 255, BRIGHTNESS);
  leds[3] = CHSV( random8(), 255, BRIGHTNESS);
  FastLED.show();
  
  delay(2000);
  
  MyServo.write(90);
  FastLED.clear();
  for (int i = 0; i < NUM_LEDS; i++) { // Example 3: Create a simple chasing effect
    leds[i] = CRGB::Green;
    FastLED.show();
    delay(250);
    leds[i] = CRGB::Black; // Turn off the previous LED
  }
  FastLED.show();
  delay(250);
  
  MyServo.write(170);
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  FastLED.show();
  
  delay(2000);
}
