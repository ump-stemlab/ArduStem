//****************** OLED setting ******************//
#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//****************** OLED setting ******************//


void oledDisplay(int8_t textSize, int8_t x, int8_t y) {
  display.clearDisplay();
  display.display();
  display.setTextSize(textSize);
  display.setTextColor(WHITE);
  display.setCursor(x, y);
}


void setup() {
  // put your setup code here, to run once:
 //****************** OLED setup ******************//
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  //****************** OLED setup ******************//
}

void loop() {
  // put your main code here, to run repeatedly:
  oledDisplay(2, 0, 0);
  display.println("  Hello ");
  display.println("");
  display.println("  World  ");
  display.println("----------");
  display.display();
  delay(1000);
}
