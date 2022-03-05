#ifndef IRQ_H
#define IRQ_H

#include "utils.h"

#define DAIF_IRQ_BIT (1 << 1) /* IRQ mask bit */
#define DAIF_FIQ_BIT (1 << 0) /* FIQ mask bit */

void __arch_enable_irq(void);
void __arch_disable_irq(void);

void __arch_end_of_interrupt(uint64_t);
uint32_t __arch_acknowledge_interrupt(void);

#endif