//Práctica 0 - TeamDebian
//Integrantes:
//Santy Francisco Martinez Castellanos - 21211989
//Julio Alejandro Hernández León -21211963
//Luis Roberto Leal Lua - 21211970
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
Adafruit_SSD1306 display(128, 64);

void setup() { 
  // Initialize the display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Address 0x3C for 128x32
  // Clear the display
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println("Team Debian");
  display.println("Practica 3");
  display.println("Raspberry");
  display.println("07/MAY/2024");
  display.display();
}

void loop() {
  // Nothing to do here, just display the static text
}
