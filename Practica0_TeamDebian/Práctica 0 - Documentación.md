# Documentación Práctica 0 IDE Arduino

## Código Utilizado

```arduino
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
```

## Funcionamiento del programa

```arduino
Inclusión de una librería para arduino
→ #include <Arduino.h>
Esta librería nos proporciona algunas funciones básicas y definiciones para poder trabajar con el hardware.

Definición de una constante a la que hemos llamado “ledPin” 
→ const int ledPin = 25; // Pin GPIO donde está conectado el LED
Representa el número de GPIO (General Purpose Input/Output) al que está conectado el led. En este caso se conecta al pin 25.

Configuración inicial en la función “setup”
→ void setup() {
    // Configurar el pin del LED como salida
    pinMode(ledPin, OUTPUT);
    
    // Iniciar la comunicación serial a 115200 baudios
    Serial.begin(115200);
    
    // Mensaje de bienvenida
    Serial.println("Hola, Raspberry Pi Pico W!");
→ }
pinMode(ledPin, OUTPUT): Configura el pin 25 como una salida.
Serial.begin(115200): Inicializa la comunicación serial con una velocidad de 115200 baudios.
Serial.println("Hola, Raspberry Pi Pico W!"): Envía un mensaje de bienvenida a través del puerto serial.



Bucle principal en la función de loop
→ void loop() {
     
    // Apagar el LED
    digitalWrite(ledPin, LOW);
    Serial.println("Hello World");
    
    // Esperar 1 segundo
    delay(10000);
→ }
digitalWrite(ledPin, LOW): Apaga el LED configurando el pin 25 en bajo (LOW).
Serial.println("Hello World"): Envía el mensaje "Hello World" a través del puerto serial.
delay(10000): Detiene la ejecución del programa durante 10,000 milisegundos (10 segundos).

```
