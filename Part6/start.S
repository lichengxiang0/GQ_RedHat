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
	bl set_svc
	bl set_peri_port
	bl disable_watchdog
	bl disable_interrupt
	bl disable_mmu
	bl light_led
	

set_peri_port:
	ldr r0, =0x70000000
	orr r0, r0, #0x13
	mcr p15,0,r0,c15,c2,4
	mov pc, lr
	
set_svc:
	mrs r0, cpsr
	bic r0, r0,#0x1f
	orr r0, r0,#0xd3  @at the mement:disable interrupt
	msr cpsr, r0
	mov pc, lr						


#define pWTCON 0x7e004000
disable_watchdog:
	ldr r0, =pWTCON
	mov r1, #0x0
	str r1, [r0]
	mov pc, lr

disable_interrupt:
	mvn r1, #0x0
	ldr r0, =0x71200014
	str r1, [r0]
	
	ldr r0, =0x71300014
	str r1, [r0]
	mov pc, lr			

disable_mmu:
	mcr p15,0,r0,c7,c7,0
	mrc p15,0,r0,c1,c0,0
	bic r0, r0, #0x00000007
	mcr p15,0,r0,c1,c0,0
	mov pc, lr

#define GPKCON0 0x7f008800
#define GPKDAT 0x7f008808
light_led:
	ldr r0, =GPKCON0
	ldr r1, =0x11110000
	str r1, [r0]

	ldr r0, =GPKDAT
	ldr r1, =0x0
	str r1, [r0]
	mov pc, lr	