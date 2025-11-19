// This is a basic code demonstrate the use of a WS2812 type LED strip 
// this code strives to use less memory using the Adafruit_NeoPixel library
// as aposed to FastLED library. For more information on how LED strips differ
// this video is a great start https://youtu.be/QnvircC22hU

#include <Adafruit_NeoPixel.h>
#define LED_PIN    4
#define NUM_LEDS   4
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin(); // Initialize the NeoPixel library.
  strip.show();  // Turn all pixels off (clear the strip).
  LEDstrip.clear();
}

void loop() {
  strip.setBrightness(150);
  strip.setPixelColor(0, strip.Color(0, 255, 0));
  strip.setPixelColor(1, strip.Color(255, 255, 0));
  strip.setPixelColor(2, strip.Color(0, 255, 255));
  strip.setPixelColor(3, strip.Color(255, 0, 255));
  strip.show();
  delay(2000);

  strip.setBrightness(100);
  strip.setPixelColor(0, strip.Color(255, 0, 0));
  strip.setPixelColor(1, strip.Color(255, 0, 0));
  strip.setPixelColor(2, strip.Color(255, 0, 0));
  strip.setPixelColor(3, strip.Color(255, 0, 0));
  strip.show();
  delay(2000);

  strip.setBrightness(200);
  strip.setPixelColor(0, strip.Color(255, 0, 0));
  strip.setPixelColor(1, strip.Color(255, 0, 0));
  strip.setPixelColor(2, strip.Color(255, 0, 0));
  strip.setPixelColor(3, strip.Color(255, 0, 0));
  strip.show();
  delay(2000);
}
