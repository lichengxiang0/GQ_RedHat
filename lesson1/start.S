@**************************
@lichengxiang
@20170211   15:27
@**************************

.text
.global _start
_start:

	b reset
	ldr pc,_undefine_instruction
	ldr pc,_software_interrupt
	ldr pc,_prefect_abort
	ldr pc,_data_abort
	ldr pc,_not_used
	ldr pc,_irq
	ldr pc,_fiq

_undefine_instruction	:.word	undefine_instruction
_software_interrupt	:.word	software_interrupt
_prefect_abort		:.word	prefect_abort
_data_abort		:.word	data_abort
_not_used		:.word	not_used
_irq			:.word	irq
_fiq			:.word	fiq
_reset			:.word	reset	

undefine_instruction:
	nop
	
software_interrupt:
	nop	
	
prefect_abort:
	nop
	
data_abort:
	nop

not_used:
	nop
	
irq:
	nop
	
fiq:
	nop
	
reset:
	nop					
	

