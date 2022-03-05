#ifndef AV_UART_H
#define AV_UART_H

#include "utils.h"
#include "irq.h"
#include "board.h"

#define DR_DATA_MASK                (0xFF)
#define RX_INTERRUPT	            (1U << 4U)
#define BE_INTERRUPT	            (1U << 9U)
#define LCRH_FEN                    (1U << 4U)
#define CR_UARTEN                   (1U	<< 0U)
#define IMSC_RXIM		            (1U << 4U)
#define FR_RXFE                     (1U	<< 4U)
#define RSRECR_ERR_MASK             (0xF)

// Macros
#define SERIAL_NEWLINE 		uart_print_char('\n');
#define SERIAL_LINE 		uart_print_string("--------------------------");

#define HYP_LOG(x) 			uart_print_string("> HYP:"); uart_print_string(x);
#define HYP_LOG_N(x) 		HYP_LOG(x); SERIAL_NEWLINE;
#define HYP_ERR(x) 			uart_print_string("!!! HYP: ERROR "); uart_print_string(x);

#define SERIAL_LINE_N SERIAL_LINE SERIAL_NEWLINE;


struct __attribute__((packed)) PL011_REGS
{
	REG32 DR;                            
	REG32 RSRECR;                        
	REG32 __empty0__[4];                 
	REG32 FR;                            
	REG32 __empty1__;                    
	REG32 ILPR;                          
	REG32 IBRD;                          
	REG32 FBRD;                          
	REG32 LCRH;                          
	REG32 CR;                            
	REG32 IFLS;				            
	REG32 IMSC;				            
	REG32 RIS;				            
	REG32 MIS;				            
	REG32 ICR;				            
} ;

static struct PL011_REGS* UART_DEVICE = (struct PL011_REGS*)0x09000000;

// PL011 Device
void uart_print_char(const char);
void uart_print_string(const char *);
void uart_print_hex(uint64_t);
void uart_enable_interrupts(void);
void uart_print_register_colon(const char *s,uint64_t n,const char *s1,uint64_t n1);

#endif