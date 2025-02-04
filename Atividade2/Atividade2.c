#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define LED_RED 12
#define LED_BLUE 11
#define LED_GREEN 13
#define BUTTON 5

volatile bool sequence_active = false;

// Callbacks para desligar os LEDs na ordem correta
int turn_off_green(alarm_id_t id, void *user_data) {
    printf("Desligando LED verde\n");
    gpio_put(LED_GREEN, 0);
    sequence_active = false; // Permitir nova ativação apenas após o último LED apagar
    return 0;
}

int turn_off_red(alarm_id_t id, void *user_data) {
    printf("Desligando LED vermelho\n");
    gpio_put(LED_RED, 0);
    add_alarm_in_ms(3000, turn_off_green, NULL, false);
    return 0;
}

int turn_off_blue(alarm_id_t id, void *user_data) {
    printf("Desligando LED azul\n");
    gpio_put(LED_BLUE, 0);
    add_alarm_in_ms(3000, turn_off_red, NULL, false);
    return 0;
}

// Callback do botão com debounce
void button_callback(uint gpio, uint32_t events) {
    static uint32_t last_press_time = 0;
    uint32_t current_time = to_ms_since_boot(get_absolute_time());

    if ((current_time - last_press_time) < 200) return; // Debounce de 200ms
    last_press_time = current_time;

    if (!sequence_active) {
        sequence_active = true;
        printf("Botão pressionado! Ligando LEDs...\n");
        
        gpio_put(LED_RED, 1);
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_GREEN, 1);

        add_alarm_in_ms(3000, turn_off_blue, NULL, false);
    }
}

int main() {
    stdio_init_all();

    // Inicialização dos LEDs
    gpio_init(LED_RED);
    gpio_init(LED_BLUE);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_put(LED_RED, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_GREEN, 0);

    // Configuração do botão
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);

    // Configuração da interrupção do botão corretamente
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    while (1) {
        sleep_ms(1000); // Loop principal sem consumir CPU desnecessária
    }
}
