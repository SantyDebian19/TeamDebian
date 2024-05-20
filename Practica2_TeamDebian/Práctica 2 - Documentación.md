# Documentación Práctica 2 OLED Display Mensaje

### Integrantes:

* SANTY FRANCISCO MARTINEZ CASTELLANOS - 21211989
* JULIO ALEJANDRO HERNÁNDEZ LEÓN - 21211963
* LUIS ROBERTO LEAL LUA - 21211970

## Código Utilizado

```Arduino

//Práctica 2 -  OLED Display Mensaje
//Team Debian
//Integrantes:
//Santy Francisco Martinez Castellanos - 21211989
//Julio Alejandro Hernández León -21211963
//Luis Roberto Leal Lua - 21211970
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
Adafruit_SSD1306 display(128, 64);

void setup() { 
  // Inicializa el display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Address 0x3C for 128x32
  // Limpia el display para mostrar el texto
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

```

## Fotografías del Funcionamiento 

Fotografía de Raspberry con el programa funcionando correctamente.

![image](https://github.com/SantyDebian19/TeamDebian/assets/105742969/989dc7aa-e15c-4337-bdc2-5556e2fc8f0e)

![image](https://github.com/SantyDebian19/TeamDebian/assets/105742969/8ab86499-d795-4a45-815f-b9016ca80319)

Fotografía del simulador funcionando.

![image](https://github.com/SantyDebian19/TeamDebian/assets/105742969/447048c3-f5ed-484a-bb9d-f9c4685e8595)

