/*
    Helper functions for GIC implementation
    - registering device
    - initialize gic
*/

#include "./inc/irq.h"
#include "./inc/av_gic.h"
#include "./inc/uart.h"
#include "aarch64/gicv3/gicv3_basic.h"
#include "aarch64/gicv3/gicv3_registers.h"

extern uint32_t getAffinity(void);

void gic_init(void)
{  
    setGICAddr((void *)VIRT_GIC_DIST, (void *)VIRT_GIC_REDIST);
    enableGIC();

    GIC_REDIST_ID = getRedistID(getAffinity());
    wakeUpRedist(GIC_REDIST_ID);
    
    setPriorityMask(0xFF);

    enableGroup0Ints();
    enableGroup1Ints();
}

void gic_register_device(uint64_t _device_id)
{
    setIntPriority(_device_id, GIC_REDIST_ID, 0);
    setIntGroup(_device_id, GIC_REDIST_ID, 0);
    enableInt(_device_id, GIC_REDIST_ID);
}

