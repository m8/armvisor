

.global asm_enable_hypervisor
asm_enable_hypervisor:
    mov	x0, xzr
	mov	x0, #(1 << 31)		        		// 64bit EL1
    orr	x0, x0, #(1 << 3)	        		// Physical IRQ Routing ! MUST
    orr	x0, x0, #(1 << 4)	        		// Physical Serror Routing 
    orr	x0, x0, #(1 << 5)	        		// Physical Serror Routing
    msr	hcr_el2, x0
    ret


.global asm_save_vcpu
asm_save_vcpu:
	
	str x15, [sp, #-8]!						// Store register in stack 
	ldr x15, =TEMP_REGSET					// Get address of current vm

	stp	x1, x2,   [x15, #0]					// Save each register into temp regset
	stp	x3, x4,   [x15, #16]
	stp	x5, x6,   [x15, #32]
	stp	x7, x8,   [x15, #48]
	stp	x9, x10,  [x15, #64]
	stp	x11, x12, [x15, #80]
	stp	x13, x14, [x15, #96]
	stp	x15, x16, [x15, #112]
	stp	x17, x18, [x15, #128]
	stp	x19, x20, [x15, #144]
	stp	x21, x22, [x15, #160]
	stp	x23, x24, [x15, #176]
	stp	x25, x26, [x15, #192]
	stp	x27, x28, [x15, #208]
	stp	x29, x30, [x15, #224]

	ldr x29, [sp] , #8						// Restore register value
	str x29, [x15, #112]					// Save to vcpu struct

    bl vcpu_save_current					// Save current vcpu into struct

	bl interrupt_handler

	b asm_start_vm



.global asm_start_vm
asm_start_vm:
	
    ldr x30, =CURRENT_VM
    
	# Used for pointer address
	ldr x30, [x30]

	ldr	x21, [x30 , #248]
    msr	elr_el2, x21

	ldr	x21, [x30, #240]
	msr	spsr_el2, x21		

	ldp	x1, x2,   [x30, #0]
	ldp	x3, x4,   [x30, #16]
	ldp	x5, x6,   [x30, #32]
	ldp	x7, x8,   [x30, #48]
	ldp	x9, x10,  [x30, #64]
	ldp	x11, x12, [x30, #80]
	ldp	x13, x14, [x30, #96]
	ldp	x15, x16, [x30, #112]
	ldp	x17, x18, [x30, #128]
	ldp	x19, x20, [x30, #144]
	ldp	x21, x22, [x30, #160]
	ldp	x23, x24, [x30, #176]
	ldp	x25, x26, [x30, #192]
	ldp	x27, x28, [x30, #208]
	ldp	x29, x30, [x30, #224]

	eret