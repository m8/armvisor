#ifndef ARCH_UTILS_H
#define ARCH_UTILS_H

/*
	Helper functions for aarch64
*/

#include <stdint.h>
#include "regs.h"

#define ASM __asm__ volatile 
#define __arch_wfi() ASM("wfi")


static inline uint64_t __arch_register_read (REG64 reg)
{
    uint64_t reg_val;
	ASM("mov %0, %1" : "=r"(reg_val) :"r"(reg):);
	return reg_val;
}

static inline uint64_t __arch_read_current_el (void)
{
	uint64_t current_el;
	ASM("mrs %0, CurrentEL": "=r"(current_el));
	return current_el;
}

static inline uint64_t __arch_elr_el2_read (void)
{
	uint64_t reg;
	ASM("mrs %0, elr_el2": "=r"(reg));
	return reg;
}

static inline uint64_t __arch_elr_el1_read (void)
{
	uint64_t reg;
	ASM("mrs %0, elr_el1": "=r"(reg));
	return reg;
}

static inline uint64_t __arch_elr_spsr_el2_read (void)
{
	uint64_t reg;
	ASM("mrs %0, spsr_el2": "=r"(reg));
	return reg;
}

static inline uint64_t __arch_elr_spsr_el1_read (void)
{
	uint64_t reg;
	ASM("mrs %0, spsr_el1": "=r"(reg));
	return reg;
}

#endif