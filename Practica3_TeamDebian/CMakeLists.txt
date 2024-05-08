cmake_minimum_required(VERSION 3.13)

# Nombre del proyecto
project(pico_w_led_control)

# Incluir el SDK de Raspberry Pi Pico
include(pico_sdk_import.cmake)

# Inicializar el SDK
pico_sdk_init()

# Añadir tu código fuente
add_executable(pico_w_led_control
    src/main.c
)

# Vincular las bibliotecas necesarias
target_link_libraries(pico_w_led_control
    pico_stdlib
    pico_cyw43_arch
    pico_unique_id
)

# Configurar opciones de compilación
pico_add_extra_outputs(pico_w_led_control)
