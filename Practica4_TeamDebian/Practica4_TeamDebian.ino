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
