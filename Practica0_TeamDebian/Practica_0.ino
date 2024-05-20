//Práctica 0 - IDE Arduino 
//Team Debian
//Integrantes:
//Santy Francisco Martinez Castellanos - 21211989
//Julio Alejandro Hernández León -21211963
//Luis Roberto Leal Lua - 21211970
#include <Arduino.h>

const int ledPin = 25; // Pin GPIO donde está conectado el LED

void setup() {
    // Configurar el pin del LED como salida
    pinMode(ledPin, OUTPUT);
    
    // Iniciar la comunicación serial a 115200 baudios
    Serial.begin(115200);
    
    // Mensaje de bienvenida
    Serial.println("Hola, Raspberry Pi Pico W!");
}

void loop() {
     
    // Apagar el LED
    digitalWrite(ledPin, LOW);
    Serial.println("Hello World");
    
    // Esperar 1 segundo
    delay(10000);
}
