.section "vectors"

.global vector
vector:

// ----------------------------------------
sp_el0_sync:        b       start
.align 7 , 0xff // 2^7
sp_el0_irq:         b       interrupt_handler_a

.align 7 , 0xff // 2^7
sp_el0_fiq:         b       interrupt_handler_a
    
.align 7 , 0xff // 2^7
sp_el0_serror:      b       interrupt_handler_a
// ----------------------------------------
.align 7 , 0xff // 2^7
sp_elx_sync:        b       interrupt_handler_a
    
.align 7 , 0xff // 2^7
sp_elx_irq:         b       interrupt_handler_a

.align 7 , 0xff // 2^7		// EL2 Timer-IRQ
sp_elx_fiq:         b       interrupt_handler_a
    
.align 7 , 0xff // 2^7
sp_elx_serror:      b       interrupt_handler_a
// ----------------------------------------
.align 7 , 0xff // 2^7
lower_64_sync:        b       interrupt_handler_a
    
.align 7 , 0xff // 2^7
lower_64_irq:         b       interrupt_handler_a

.align 7 , 0xff // 2^7		 // Lower level - Timer IRQ
lower_64_fiq:         b       asm_save_vcpu
    
.align 7 , 0xff // 2^7
lower_64_serror:      b       interrupt_handler_a
// ----------------------------------------
.align 7 , 0xff // 2^7
lower_32_sync:        b       interrupt_handler_a
    
.align 7 , 0xff // 2^7
lower_32_irq:         b       interrupt_handler_a

.align 7 , 0xff // 2^7
lower_32_fiq:         b       interrupt_handler_a
    
.align 7 , 0xff // 2^7
lower_32_serror:      b       interrupt_handler_a
// ----------------------------------------


// From lower exception level
.global lower_exception_level
lower_exception_level:
	bl main




// Handle interrupt
// 1. Save Context
// 2. Handle Interrupt
// 3. Restore Context
.global interrupt_handler_a
interrupt_handler_a:

    stp	x29, x30, [sp, #-16]!
	stp	x27, x28, [sp, #-16]!
	stp	x25, x26, [sp, #-16]!
	stp	x23, x24, [sp, #-16]!
	stp	x21, x22, [sp, #-16]!
	stp	x19, x20, [sp, #-16]!
	stp	x17, x18, [sp, #-16]!
	stp	x15, x16, [sp, #-16]!
	stp	x13, x14, [sp, #-16]!
	stp	x11, x12, [sp, #-16]!
	stp	x9, x10, [sp, #-16]!
	stp	x7, x8, [sp, #-16]!
	stp	x5, x6, [sp, #-16]!
	stp	x3, x4, [sp, #-16]!
	stp	x1, x2, [sp, #-16]!

    // Save Program Status Register
    mrs	x21, spsr_el2
    stp	x21, x0, [sp, #-16]!

    // Save Exception Link Register
    mrs	x21, elr_el2
    stp	xzr, x21, [sp, #-16]!

    // Jump to interupt handler in handler.c
    bl interrupt_handler                        

    // Reload Exception Link Register
    ldp	x21, x22, [sp], #16
    msr	elr_el2, x22 

    // Reload Program Status Register
    ldp	x21, x0, [sp], #16
    msr	spsr_el2, x21

    ldp	x1, x2, [sp], #16 
	ldp	x3, x4, [sp], #16 
	ldp	x5, x6, [sp], #16 
	ldp	x7, x8, [sp], #16 
	ldp	x9, x10, [sp], #16 
	ldp	x11, x12, [sp], #16
	ldp	x13, x14, [sp], #16
	ldp	x15, x16, [sp], #16
	ldp	x17, x18, [sp], #16
	ldp	x19, x20, [sp], #16
	ldp	x21, x22, [sp], #16
	ldp	x23, x24, [sp], #16
	ldp	x25, x26, [sp], #16
	ldp	x27, x28, [sp], #16
	ldp	x29, x30, [sp], #16

    eret
