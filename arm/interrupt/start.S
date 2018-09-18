.globl _start
_start: 
	b	reset
	ldr	pc, _undefined_instruction
	ldr	pc, _software_interrupt
	ldr	pc, _prefetch_abort
	ldr	pc, _data_abort
	ldr	pc, _not_used
	ldr	pc, _irq
	ldr	pc, _fiq
    
_undefined_instruction: .word undefined_instruction
_software_interrupt: .word software_interrupt
_prefetch_abort: .word prefetch_abort
_data_abort: .word data_abort
_not_used: .word not_used
_irq: .word irq
_fiq: .word fiq

undefined_instruction:
	nop

software_interrupt:
	nop
	
prefetch_abort:
	nop
	
data_abort:
	nop
	
not_used:
	nop

irq:
	sub lr,lr,#4
	stmfd sp!, {r0-r12, lr}
	bl irq_handler
	ldmfd sp!, {r0-r12, pc}^
 
fiq:
	nop
	

reset:
	/*
	 * set the cpu to SVC32 mode
	 */
	mrs	r0, cpsr
	bic	r0, r0, #0x1f
	orr	r0, r0, #0xd3
	msr	cpsr,r0  
    
	/* Set vector address in CP15 VBAR register */
	ldr	r0, =0x41000000
	mcr	p15, 0, r0, c12, c0, 0	@Set VBAR
	
	ldr sp, stacktop
	sub r1, sp, #128
	
	/*转换模式到irq模式*/
	mrs	r0, cpsr
	bic	r0, r0, #0x1f
	orr	r0, r0, #0xd2
	msr	cpsr,r0  
  mov sp, r1   
  sub r1, sp, #128
  
  /*转换模式到user模式*/
	mrs	r0, cpsr
	bic	r0, r0, #0xff
	orr	r0, r0, #0x10
	msr	cpsr,r0  
  mov sp, r1
  
	b main
	
stacktop:  .word stack+128*2     
stack:  .space 128*2
    
    
    
    