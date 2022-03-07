
#include "aarch64/inc/irq.h"

extern uint32_t readIARGrp0 (void);
extern void     writeEOIGrp0(uint64_t);

void __arch_enable_irq(void)
{
	ASM("msr DAIFClr, %0" :: "i"(DAIF_IRQ_BIT));
    return;
}

void __arch_disable_irq(void)
{
	ASM("msr DAIFSet, %0" :: "i"(DAIF_IRQ_BIT));
    return;
};

// GIC helper function
uint32_t __arch_acknowledge_interrupt(void)
{
    return readIARGrp0();
} 

// GIC helper function
void __arch_end_of_interrupt(uint64_t _irq_num)
{
    writeEOIGrp0(_irq_num);
} 