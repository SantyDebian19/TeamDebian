#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>

// Nombre y clave de red
const char* ssid = "INFINITUM5A66_2.4";
const char* password = "duke1975";

// APY y Modelo
const char* api_key = "sk-proj-SCrtDnfTA7psqYCbJUlnT3BlbkFJbiGIBcW6p4Av82yVF5KA";
const char* model_id = "gpt-3.5-turbo-0125";

// Configuración del host y URL para la API
const char* host = "api.openai.com";
const char* url = "/v1/chat/completions";

void setup() {
  Serial.begin(115200);
  delay(10);

  // Conexión a Wi-Fi
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado");

  // Configuración del cliente seguro
  WiFiClientSecure client;
  client.setInsecure();
  client.setTimeout(10000);

  // Conexión a la API de ChatGPT
  Serial.print("Conectando a la API...");
  if (!client.connect(host, 443)) {
    Serial.println("¡Error al conectar!");
    return;
  }
  Serial.println("¡Conexión exitosa!");

  // Construcción de la carga útil de solicitud
  String estructura = "{";
  estructura += "\"model\": \"gpt-3.5-turbo-0125\",";
  estructura += "\"messages\": [";
  estructura += "{\"role\": \"user\",";
  estructura += "\"content\": \"Dime un chiste del team windows\"}";
  estructura += "],";
  estructura += "\"temperature\": 0.7,";
  estructura += "\"max_tokens\": 50,";
  estructura += "\"n\": 1,";
  estructura += "\"stop\": \"\\n\"}";

  // Construcción de la solicitud HTTP
  String resultado = "POST ";
  resultado += url;
  resultado += " HTTP/1.1\r\n";
  resultado += "Host: ";
  resultado += host;
  resultado += "\r\n";
  resultado += "Authorization: Bearer ";
  resultado += api_key;
  resultado += "\r\n";
  resultado += "Content-Type: application/json\r\n";
  resultado += "Content-Length: ";
  resultado += estructura.length();
  resultado += "\r\n\r\n";
  resultado += estructura;

  // Envío de la solicitud HTTP
  Serial.println("Enviando solicitud...");
  client.print(resultado);

  // Espera la respuesta de la API de OpenAI
  Serial.println("Esperando respuesta...");
  while (client.connected()) {
    if (client.available()) {
      String response = client.readString();
      Serial.print(response);
    }
  }
}

void loop() {
  // No hay nada que hacer aquí, ya que todo el trabajo se realiza en setup()
}

