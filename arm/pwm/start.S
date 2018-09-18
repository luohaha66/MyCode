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
    
  _undefined_instruction: .word _undefined_instruction
  _software_interrupt:	.word _software_interrupt
  _prefetch_abort:	.word _prefetch_abort
  _data_abort:		.word _data_abort
  _not_used:		.word _not_used
  _irq:			.word _irq
  _fiq:			.word _fiq
    
reset:
	/*
	 * set the cpu to SVC32 mode
	 */
	mrs	r0, cpsr
	bic	r0, r0, #0x1f
	orr	r0, r0, #0xd3
	msr	cpsr,r0  
    
	/* Set vector address in CP15 VBAR register */
	ldr	r0, =_start
	mcr	p15, 0, r0, c12, c0, 0	@Set VBAR
	
	ldr sp, stacktop
	sub r1, sp, #128

	mrs	r0, cpsr
	bic	r0, r0, #0x1f
	orr	r0, r0, #0xd0
	msr	cpsr,r0  
	
	mov sp, r1
	b main
    
stacktop:  .word stack+128*2     
stack:  .space 128*2
    
    
    
    