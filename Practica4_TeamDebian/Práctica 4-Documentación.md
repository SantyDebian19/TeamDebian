# Documentación Práctica 4 Control Bluetooth con Pico W

### Integrantes:

* SANTY FRANCISCO MARTINEZ CASTELLANOS - 21211989
* JULIO ALEJANDRO HERNÁNDEZ LEÓN - 21211963
* LUIS ROBERTO LEAL LUA - 21211970

## Código Utilizado

```C

//Practica 4 Bluetooth
//Team Debian
// Martinez Castellanos Santy Francisco
// Leal Lua Luis Roberto
// Hernandez Leon Julio Alejandro

#include <BTstackLib.h>  // Biblioteca Bluetooth
#include <SPI.h>  // Biblioteca SPI

static char characteristic_data = 'H';  

void setup(void) {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);  // LED DE SALIDA

  // Funciones de callback
  BTstack.setBLEDeviceConnectedCallback(deviceConnectedCallback);
  BTstack.setBLEDeviceDisconnectedCallback(deviceDisconnectedCallback);
  BTstack.setGATTCharacteristicRead(gattReadCallback);
  BTstack.setGATTCharacteristicWrite(gattWriteCallback);

  // Base de datos GATT
  BTstack.addGATTService(new UUID("B8E06067-62AD-41BA-9231-206AE80AB551"));  // Se añade un servicio GATT
  BTstack.addGATTCharacteristic(new UUID("f897177b-aee8-4767-8ecc-cc694fd5fcef"), ATT_PROPERTY_READ, "This is a String!");  // Se añade una característica GATT
  BTstack.addGATTCharacteristicDynamic(new UUID("f897177b-aee8-4767-8ecc-cc694fd5fce0"), ATT_PROPERTY_READ | ATT_PROPERTY_WRITE | ATT_PROPERTY_NOTIFY, 0);  // Se añade una característica GATT dinámica

  // Inicia Bluetooth
  BTstack.setup();
  BTstack.startAdvertising();
}

void loop(void) {
  BTstack.loop(); 
}

void deviceConnectedCallback(BLEStatus status, BLEDevice *device) {
  (void) device;  
  switch (status) {
    case BLE_STATUS_OK:
      Serial.println("Device connected!");  // Indica si el dispositivo esta conectado
      break;
    default:
      break;
  }
}

void deviceDisconnectedCallback(BLEDevice * device) {
  (void) device;  
  Serial.println("Disconnected.");  // Indica si el dispositivo se ha desconectado
}

uint16_t gattReadCallback(uint16_t value_handle, uint8_t * buffer, uint16_t buffer_size) {
  (void) value_handle;  
  (void) buffer_size;  
  if (buffer) {
    Serial.print("gattReadCallback, value: ");
    Serial.println(characteristic_data, HEX);  // Valor de la caractistica Hexadecimal 
    buffer[0] = characteristic_data;  

    // Control del LED
    if (characteristic_data == '1')
      digitalWrite(LED_BUILTIN, HIGH);  // LED ENCENDIDO
    else if (characteristic_data == '0')
      digitalWrite(LED_BUILTIN, LOW);   // LED APAGADO
  }
  return 1;  
}

int gattWriteCallback(uint16_t value_handle, uint8_t *buffer, uint16_t size) {
  (void) value_handle;  
  (void) size;  
  characteristic_data = buffer[0]; 
  
  // Controla del LED
  if (characteristic_data == '1')
    digitalWrite(LED_BUILTIN, HIGH);  // LED ENCENDIDO
  else if (characteristic_data == '0')
    digitalWrite(LED_BUILTIN, LOW);   // LED APAGADO

  Serial.print("gattWriteCallback , value ");
  Serial.println(characteristic_data, HEX);  // Valor de la caractistica Hexadecimal 
  return 0; 
}

```

## Fotografías del Funcionamiento 

Se muestra la configuración para conectar dentro de la aplicación “Serial Bluetooth Terminal”.

![image](https://github.com/SantyDebian19/TeamDebian/assets/144566345/8df7ecdc-fb08-4272-93c7-070628ce9594)


Conexión.

![image](https://github.com/SantyDebian19/TeamDebian/assets/144566345/30763004-06e2-47cc-a476-1894a56b8869)


El perfil de bluetooth que se utiliza es customizado y se insertaron los siguientes UUID.

![image](https://github.com/SantyDebian19/TeamDebian/assets/144566345/29657ade-5dd8-4462-9500-065295f58a72)


Cuando el dispositivo es conectado:

![image](https://github.com/SantyDebian19/TeamDebian/assets/144566345/f83b9834-b4df-498f-acb8-4fa7d1095f6e)


En la aplicación se confirma el resultado.

![image](https://github.com/SantyDebian19/TeamDebian/assets/144566345/fa1eba2c-7fdb-4b18-80fa-e9a669d7f5c6)


![image](https://github.com/SantyDebian19/TeamDebian/assets/144566345/4f97ba76-9f0f-4626-80e4-69fb0e0cb028)


Se muestran los resultados en la aplicación de Arduino.


![image](https://github.com/SantyDebian19/TeamDebian/assets/144566345/964d5470-9c69-4382-ad84-1c487616cad5)





