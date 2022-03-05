#ifndef AVGIC_H
#define AVGIC_H

#include "lib/std.h"
#include "aarch64/inc/utils.h"

// Memory mapped registers
#define GIC_BASE                    (0x08000000)
#define VIRT_GIC_DIST				(0x08000000)
#define VIRT_GIC_CPU                (0x08010000)
#define VIRT_GIC_REDIST             (0x080A0000)

static uint64_t GIC_REDIST_ID = 0;

// Helper functions for GIC control
void gic_init(void);
void gic_register_device(uint64_t DEVICE_ID);

#endif