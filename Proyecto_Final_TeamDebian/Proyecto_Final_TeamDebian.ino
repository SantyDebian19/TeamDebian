
//OV767X - Camera Capture Raw Bytes
//Team Debian
//Proyecto Final
//Martinez Castellanos Santy Francisco
//Leal Lua Luis Roberto
//Hernandez Leon Julio Hernandez 

#include <Arduino_OV767X.h>

int bytesPerFrame;

byte data[176 * 144 * 2]; // QVGA: 320x240 X 2 bytes per pixel (RGB565)

void setup() {
  Serial.begin(460800 ); 
  while (!Serial);

  if (!Camera.begin(QCIF, RGB565, 1)) {
    Serial.println("Failed to initialize camera!");
    while (1);
  }

  bytesPerFrame = Camera.width() * Camera.height() * Camera.bytesPerPixel();

   Camera.testPattern();
}

void loop() {
  Camera.readFrame(data);

  Serial.write(data, bytesPerFrame);
}