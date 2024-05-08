#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "pico/unique_id.h"
#include "hardware/gpio.h"
#include "lwip/tcpip.h"
#include "lwip/apps/httpd.h"

// Definir el pin del LED interno
#define LED_PIN 25

// Variables para la red WiFi
const char *ssid = "tu_ssid";
const char *password = "tu_contraseña";

// Función para manejar comandos HTTP
void http_server_cgi_handler(int index, int num_params, char **params, char **values, char *response_buffer, int response_buffer_size) {
    if (index == 0) { // Ruta para controlar el LED
        if (num_params == 1 && strcmp(params[0], "command") == 0) {
            if (strcmp(values[0], "encender") == 0) {
                gpio_put(LED_PIN, 1); // Encender el LED
                snprintf(response_buffer, response_buffer_size, "LED encendido");
            } else if (strcmp(values[0], "apagar") == 0) {
                gpio_put(LED_PIN, 0); // Apagar el LED
                snprintf(response_buffer, response_buffer_size, "LED apagado");
            } else {
                snprintf(response_buffer, response_buffer_size, "Comando no reconocido");
            }
        }
    }
}

int main() {
    // Inicializar el SDK
    stdio_init_all();

    // Inicializar el controlador WiFi
    if (cyw43_arch_init_with_country(CYW43_COUNTRY_WORLD)) {
        printf("Fallo al inicializar el controlador WiFi\n");
        return -1;
    }

    // Conectarse a la red WiFi
    printf("Conectando a la red WiFi...\n");
    cyw43_arch_enable_sta_mode();
    if (cyw43_arch_wifi_connect_blocking(ssid, password)) {
        printf("Fallo al conectarse a la red WiFi\n");
        return -1;
    }
    printf("Conectado a la red WiFi\n");

    // Configurar el LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Iniciar servidor HTTP
    printf("Iniciando servidor HTTP\n");
    httpd_init();
    http_set_cgi_handlers((const tCGI []){{"/led", http_server_cgi_handler}}, 1);

    // Bucle principal
    while (true) {
        sleep_ms(1000);
    }

    return 0;
}
