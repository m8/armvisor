.global start
start:
    ldr x1, =stack_top	                // setup stack
    mov sp, x1                          // move stack pointer    

    ldr	x1, = vector
    msr	vbar_el2, x1                    // set vector table of el2


    // Enable Interrupts
    // ------------------
    MSR      DAIFClr, #0x3

    bl main                             // jump to c program
