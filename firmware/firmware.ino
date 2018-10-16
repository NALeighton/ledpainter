#include <noise.h>
#include <bitswap.h>
#include <fastspi_types.h>
#include <pixelset.h>
#include <fastled_progmem.h>
#include <led_sysdefs.h>
#include <hsv2rgb.h>
#include <fastled_delay.h>
#include <colorpalettes.h>
#include <color.h>
#include <fastspi_ref.h>
#include <fastspi_bitbang.h>
#include <controller.h>
#include <fastled_config.h>
#include <colorutils.h>
#include <chipsets.h>
#include <pixeltypes.h>
#include <fastspi_dma.h>
#include <fastpin.h>
#include <fastspi_nop.h>
#include <platforms.h>
#include <lib8tion.h>
#include <cpp_compat.h>
#include <fastspi.h>
#include <FastLED.h>
#include <dmx.h>
#include <power_mgt.h>

CRGB leds[696]; //The amount of LEDs on the pannel
int colors[] = {CRGB::White, CRGB::Red, CRGB::Green, CRGB::Purple, CRGB::Blue, CRGB::Yellow};
int currColor = 0;
const int limit = 1000;
int cooldown;

void setup() {
  Serial.begin(115200);
  cooldown = limit;
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), change, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), reset, FALLING);
  //The LEDs were split into 3 banks
  FastLED.addLeds<NEOPIXEL, 7>(leds, 0, 336);
  FastLED.addLeds<NEOPIXEL, 8>(leds, 336, 336*2);
  FastLED.addLeds<NEOPIXEL, 9>(leds, 336*2, 696);
  for(int i = 0; i < 696; i++)
  {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void loop() {
  char tmp[3];
  if(cooldown > 0)
  {
    cooldown --;
  }
  if(Serial.available())
  {
    Serial.readBytes(tmp,3);
    int val = (tmp[0]-48)*100 + (tmp[1]-48) * 10 + tmp[2]-48; //Read finger postition
    leds[val] = colors[currColor]; //Use change() function to have the LEDs turn off after a certain time
    FastLED.show();
  }
}

void change()
{
  if(cooldown > 0)
  {
    return;
  }
  currColor++;
  if(currColor > 6) currColor = 0;
  if(cooldown == 0)
  {
    cooldown = limit;
  }
}

void reset()
{
  for(int i = 0; i < 696; i++)
  {
    leds[i] = CRGB::Black;
  }
}
