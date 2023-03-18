#ifndef UART_H
#define UART_H

#include <stdint.h>

#define _UART_BUFFER_SIZE 32

/*
 * Definição dos tipos relacionados com o módulo serial
 */
/* Definição do tipo relacionado à estrutura que representa o módulo
   serial.  A definição da estrutura em si é feita depois */
typedef struct Uart_Struct Uart_t;

/* Tipo relativo à função de callback a ser usada na interrupção.
   Este tipo consiste de um ponteiro para função */
typedef void (*uart_cb_t)(Uart_t*);

/* Estrutura usada para configuração da porta serial.  Além dos
   parâmetros da comunicação serial, temos também possíveis funções de
   callback a ser usada nas interrupções. Se não for usar os
   callbacks, inicialize-os com o valor nulo (0) */
typedef struct {
    uint16_t freq;
    uint8_t parity;
    uint8_t nbr_data_bits;
    uint8_t nbr_stop_bits;
    uart_cb_t rx_cb;
    uart_cb_t tx_cb;
} Uart_Config_t;

/*
 * Declaração das variáveis relativas a cada módulo de serial
 */
extern Uart_t* UARTD1;

/*
 * Declaração das funções que lidam com a serial
 */
void uart_init(Uart_t* drv);
void uart_start(Uart_t* drv, Uart_Config_t* cfg,
		uint8_t transmitter_on, uint8_t receiver_on);
void uart_stop(Uart_t* drv, uint8_t transmitter_off,
	       uint8_t receiver_off);

uint8_t uart_writechar(Uart_t* drv, uint8_t ch);
uint8_t uart_write(Uart_t* drv, uint8_t* buf, uint8_t len);
uint16_t uart_read(Uart_t* drv);
uint8_t uart_read_bytes(Uart_t* drv, uint8_t* buf, uint8_t len);
uint8_t uart_available(Uart_t* drv);
uint8_t uart_available_for_write(Uart_t* drv);

#endif /* UART_H */