#ifndef ARCH_TIME_ASM_H
#define ARCH_TIME_ASM_H

#include "utils.h"

#define CNTV_CTL_ENABLE         (1 << 0)    /* Enables the timer */
#define CNTV_CTL_IMASK          (1 << 1)    /* Timer interrupt mask bit */
#define CNTV_CTL_ISTATUS        (1 << 2)    /* The status of the timer interrupt. This bit is read-only */


// Read counter frequency register
static inline uint32_t __arch_read_cntfrq_el0(void)
{
	uint32_t cntfrq_el0;
	ASM("mrs %0, CNTFRQ_EL0" : "=r"(cntfrq_el0));
	return cntfrq_el0;
}

// Read physical count register
static inline uint32_t __arch_read_cntpct_el0(void)
{
	uint64_t cntpct_el0;
	ASM("mrs %0, CNTPCT_EL0" : "=r"(cntpct_el0));
	return cntpct_el0;
}

static inline uint32_t __arch_read_cnthp_ctl_el2(void)
{
	uint32_t cntv_ctl;
	ASM("mrs %0, CNTHP_CTL_EL2": "=r"(cntv_ctl));
	return cntv_ctl;
}

// Read physical count register
static inline void __arch_disable_cnthp(void)
{
	uint32_t cntv_ctl;
	cntv_ctl = __arch_read_cnthp_ctl_el2();
	cntv_ctl &= ~CNTV_CTL_ENABLE;
	ASM("msr CNTHP_CTL_EL2, %0":: "r"(cntv_ctl));
	return;
}

static inline void __arch_enable_cnthp(void)
{
	uint32_t cntv_ctl;

	cntv_ctl = __arch_read_cnthp_ctl_el2();
	cntv_ctl |= CNTV_CTL_ENABLE;
	ASM("msr CNTHP_CTL_EL2, %0":: "r"(cntv_ctl));
    return;
}

void __arch_write_cnthp_cval_el2(uint64_t cntv_cval_el0)
{
	ASM("msr CNTHP_CVAL_EL2, %0" : : "r"(cntv_cval_el0));
    return;
}

#endif