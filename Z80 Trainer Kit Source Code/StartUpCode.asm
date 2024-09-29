;; startup code for z80 Microprocessor kit

;; File:   usart.h
;; Author: Youssef Ahmed Tawfik Ali


; Constants
.equ SP_INIT,            0xFFFF   ; Initialize stack pointer to top of RAM
.equ __data_load__start, 0x0000
.equ __data_start,       0x8000
.equ __data_size,        0x0000
.equ __bss_start,        0x8000
.equ __bss_size,         0x0000
.equ IVT_START,          0x0000   ; IVT starts at address 0x0000 ; Vector table setup for Interrupt Mode 2
; External declarations
.globl  _main       ; Entry point for C code (SDCC expects this)
.globl  _nmi_handler
.globl _default_handler


	.area _HEADER (ABS)
	;; Reset vector
    .org IVT_START
        jp start              ; Jump to start of initialization
        nop
    ;; Interrupt Vector Table (IVT) for IM2
    .rept 26
    .dw _default_handler             ; All entries point to _default_handler
    .endm
    ;; Interrupt Vector for IM1
    .org 0x0038
        jp _default_handler            ; INT ISR at 0x38
        nop
    ;; Interrupt Vector for NMI
    .org 0x0066
        jp _nmi_handler            ; NMI ISR at 0x66
	

start:
    ; Initialize the stack pointer
    ld sp, #SP_INIT

    ; Initialize interrupt mode 2
    ld a, #IVT_START >> 8  ; Load upper byte of IVT start address (0x00)
    ld i, a               ; Set interrupt vector base (IM2)
    im 2                  ; Set Z80 to interrupt mode 2

    ; Initialize interrupt mode 1
    im 1                  ; Set Z80 to interrupt mode 1

    ; Enable interrupts
    ei

    ; Copy .data section from ROM to RAM
    ;ld hl, #__data_load__start  ; Source in ROM
    ;ld de, #__data_start        ; Destination in RAM
    ;ld bc, #__data_size         ; Number of bytes to copy
    ;ldir                        ; Copy loop

    ; Zero out .bss section
    ;ld hl, #__bss_start         ; Start of .bss
    ;ld bc, #__bss_size          ; Size of .bss
    ;ld (hl), #0x00                 ; Zero first byte
    ;dec bc
    ;ldir                       ; Zero rest of .bss

    ; Jump to main C function
    call _main

    ;exit and force the processor to halt state
    jp	_exit
	

_exit::
	;; Exit - special code to the emulator
	ld	a,#0
        rst     0x08
1$:
	halt
	jr	1$

