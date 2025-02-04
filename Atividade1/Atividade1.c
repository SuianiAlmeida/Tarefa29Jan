#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED 11   // GPIO para LED Vermelho
#define LED_YELLOW 12 // GPIO para LED Amarelo
#define LED_GREEN 13  // GPIO para LED Verde

// Estados do semáforo
typedef enum {
    RED,
    YELLOW,
    GREEN
} traffic_light_state_t;

volatile traffic_light_state_t state = RED; // Estado inicial

// Callback do temporizador periódico
bool repeating_timer_callback(struct repeating_timer *t) {
    switch (state) {
        case RED:
            gpio_put(LED_RED, 1);
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 0);
            state = YELLOW;
            break;
        case YELLOW:
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 1);
            gpio_put(LED_GREEN, 0);
            state = GREEN;
            break;
        case GREEN:
            gpio_put(LED_RED, 0);
            gpio_put(LED_YELLOW, 0);
            gpio_put(LED_GREEN, 1);
            state = RED;
            break;
    }
    return true; // Mantém o temporizador ativo
}

int main() {
    stdio_init_all();

    // Configura os pinos dos LEDs como saída
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Inicializa o temporizador
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        printf("Semáforo funcionando - Estado atual: %d\n", state);
        sleep_ms(1000); // Mensagem a cada segundo
    }
}
