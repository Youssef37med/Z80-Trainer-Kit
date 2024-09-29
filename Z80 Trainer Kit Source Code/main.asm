;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.4.0 #14620 (MINGW64)
;--------------------------------------------------------
	.module main
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _dptr
	.globl _SYS_SP
	.globl _USER_SP
	.globl _USER_IY
	.globl _USER_IX
	.globl _USER_HL
	.globl _USER_DE
	.globl _USER_BC
	.globl _USER_AF
	.globl _save_PC
	.globl _PC
	.globl _hit
	.globl _state
	.globl _data_in
	.globl _key
	.globl _count
	.globl _temp8
	.globl _temp16
	.globl _temp
	.globl _buffer
	.globl _hex_chars
	.globl _convert
	.globl _default_handler
	.globl _nmi_handler
	.globl _delay
	.globl _delay_ms
	.globl _lcd_8bit_initialize
	.globl _lcd_8bit_send_command
	.globl _lcd_8bit_send_char_data
	.globl _lcd_8bit_send_string
	.globl _lcd_8bit_set_cursor
	.globl _lcd_8bit_send_uint8_hex_data
	.globl _p8255_initialize
	.globl _dot_address
	.globl _dot_data
	.globl _address_buffer_write
	.globl _data_buffer_write
	.globl _address_display
	.globl _data_display
	.globl _read_memory
	.globl _key_address
	.globl _key_data
	.globl _key_plus
	.globl _key_minus
	.globl _key_PC
	.globl _hex_address
	.globl _data_hex
	.globl _key_reg
	.globl _reg_AF
	.globl _reg_BC
	.globl _reg_DE
	.globl _reg_HL
	.globl _reg_IX
	.globl _reg_IY
	.globl _reg_SP
	.globl _reg_display
	.globl _key_step
	.globl _key_go
	.globl _key_usart_receive_byte
	.globl _key_code
	.globl _scan
	.globl _key_exe
	.globl _scan1
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
_p8255	=	0x0069
_portA	=	0x0009
_portB	=	0x0029
_portC	=	0x0049
_portD	=	0x0005
_portE	=	0x000d
_portF	=	0x0011
_portG	=	0x0015
_portH	=	0x0019
_LCD_command_write	=	0x0001
_LCD_data_write	=	0x0021
_LCD_command_read	=	0x0041
_LCD_data_read	=	0x0061
_USART_READ	=	0x001d
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_buffer::
	.ds 6
_temp::
	.ds 2
_temp16::
	.ds 2
_temp8::
	.ds 1
_count::
	.ds 1
_key::
	.ds 1
_data_in::
	.ds 1
_state::
	.ds 1
_hit::
	.ds 1
_PC::
	.ds 2
_save_PC::
	.ds 2
_USER_AF::
	.ds 2
_USER_BC::
	.ds 2
_USER_DE::
	.ds 2
_USER_HL::
	.ds 2
_USER_IX::
	.ds 2
_USER_IY::
	.ds 2
_USER_SP::
	.ds 2
_SYS_SP::
	.ds 2
_dptr::
	.ds 2
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;.\main.c:41: void main(void)
;	---------------------------------
; Function main
; ---------------------------------
_main::
;.\main.c:43: portE = 0x00;
	ld	a, #0x00
	out	(_portE), a
;.\main.c:44: portF = 0xFF;
	ld	a, #0xff
	out	(_portF), a
;.\main.c:46: buffer[0] = 0x77;
	ld	hl, #_buffer
	ld	(hl), #0x77
;.\main.c:47: buffer[1] = 0xEF;
	inc	hl
	ld	(hl), #0xef
;.\main.c:48: buffer[2] = 0xEF;
	ld	hl, #_buffer + 2
	ld	(hl), #0xef
;.\main.c:49: buffer[3] = 0x34;
	ld	hl, #_buffer + 3
	ld	(hl), #0x34
;.\main.c:50: buffer[4] = 0x0E;
	ld	hl, #_buffer + 4
	ld	(hl), #0x0e
;.\main.c:51: buffer[5] = 0x9C;
	ld	hl, #_buffer + 5
	ld	(hl), #0x9c
;.\main.c:53: PC = 0x8100;
	ld	hl, #0x8100
	ld	(_PC), hl
;.\main.c:54: save_PC = 0x8100;
	ld	(_save_PC), hl
;.\main.c:55: USER_SP = 0x9FFF;
	ld	hl, #0x9fff
	ld	(_USER_SP), hl
;.\main.c:57: state = 0;
	ld	hl, #_state
	ld	(hl), #0x00
;.\main.c:59: count = 0;
	ld	hl, #_count
	ld	(hl), #0x00
;.\main.c:61: lcd_8bit_initialize();
	call	_lcd_8bit_initialize
;.\main.c:62: p8255_initialize();
	call	_p8255_initialize
;.\main.c:64: lcd_8bit_send_string("Z80 Processor");
	ld	hl, #___str_0
	call	_lcd_8bit_send_string
;.\main.c:65: lcd_8bit_set_cursor(2, 1);
	ld	l, #0x01
;	spillPairReg hl
;	spillPairReg hl
	ld	a, #0x02
	call	_lcd_8bit_set_cursor
;.\main.c:66: lcd_8bit_send_string("Trainer Kit");
	ld	hl, #___str_1
	call	_lcd_8bit_send_string
;.\main.c:68: while (1)
00102$:
;.\main.c:70: scan1();
	call	_scan1
;.\main.c:72: }
	jr	00102$
_convert:
	.db #0x14	; 20
	.db #0x77	; 119	'w'
	.db #0x4c	; 76	'L'
	.db #0x45	; 69	'E'
	.db #0x27	; 39
	.db #0x85	; 133
	.db #0x84	; 132
	.db #0x57	; 87	'W'
	.db #0x04	; 4
	.db #0x05	; 5
	.db #0x06	; 6
	.db #0xa4	; 164
	.db #0x9c	; 156
	.db #0x64	; 100	'd'
	.db #0x8c	; 140
	.db #0x8e	; 142
_hex_chars:
	.ascii "0123456789ABCDEF"
	.db 0x00
___str_0:
	.ascii "Z80 Processor"
	.db 0x00
___str_1:
	.ascii "Trainer Kit"
	.db 0x00
;.\main.c:74: void default_handler(void)
;	---------------------------------
; Function default_handler
; ---------------------------------
_default_handler::
;.\main.c:92: __endasm;
	push	af
	push	bc
	push	de
	push	hl
	push	ix
	push	iy
	ld	hl, #0x80
	call	_delay_ms
	pop	iy
	pop	ix
	pop	hl
	pop	de
	pop	bc
	pop	af
	jp	_nmi_handler
;.\main.c:93: }
	ret
;.\main.c:94: void nmi_handler(void)
;	---------------------------------
; Function nmi_handler
; ---------------------------------
_nmi_handler::
;.\main.c:135: __endasm;
	ld(_temp8),	a
	ld	a, #0x00
	out(_portE),	a
	ld	a, (_temp8)
	ld(_temp16),	hl; save hl
	pop	hl
	ld(_save_PC),	hl; save current PC
	ld(_USER_SP),	sp; save stack pointer
	ld	hl, (_temp16); restore hl
	push	af
	push	bc
	push	de
	push	hl
	push	ix
	push	iy
	pop	hl
	ld(_USER_IY),	hl
	pop	hl
	ld(_USER_IX),	hl
	pop	hl
	ld(_USER_HL),	hl
	pop	hl
	ld(_USER_DE),	hl
	pop	hl
	ld(_USER_BC),	hl
	pop	hl
	ld(_USER_AF),	hl
	ld	sp, (_SYS_SP); restore system stack
	call	_key_PC
	ld	hl, #0x010
	call	_delay_ms
;.\main.c:136: }
	ret
;.\main.c:138: void delay(uint16_t steps)
;	---------------------------------
; Function delay
; ---------------------------------
_delay::
	ex	de, hl
;.\main.c:141: for (i = 0; i < steps; i++)
	ld	bc, #0x0000
00103$:
	ld	a, c
	sub	a, e
	ld	a, b
	sbc	a, d
	ret	NC
	inc	bc
;.\main.c:144: }
	jr	00103$
;.\main.c:145: void delay_ms(uint16_t milliseconds) {
;	---------------------------------
; Function delay_ms
; ---------------------------------
_delay_ms::
	ex	de, hl
;.\main.c:147: for (i = 0; i < milliseconds; i++) {
	ld	bc, #0x0000
00107$:
	ld	a, c
	sub	a, e
	ld	a, b
	sbc	a, d
	ret	NC
;.\main.c:149: for (j = 0; j < 30; j++) {
	ld	hl, #0x001e
00105$:
;.\main.c:154: __endasm;
	nop
	dec	hl
;.\main.c:149: for (j = 0; j < 30; j++) {
	ld	a, h
	or	a, l
	jr	NZ, 00105$
;.\main.c:147: for (i = 0; i < milliseconds; i++) {
	inc	bc
;.\main.c:157: }
	jr	00107$
;.\main.c:159: void lcd_8bit_initialize()
;	---------------------------------
; Function lcd_8bit_initialize
; ---------------------------------
_lcd_8bit_initialize::
;.\main.c:161: delay_ms(15);
	ld	hl, #0x000f
	call	_delay_ms
;.\main.c:162: portH = 0x30;
	ld	a, #0x30
	out	(_portH), a
;.\main.c:163: LCD_command_write = 0x00;
	ld	a, #0x00
	out	(_LCD_command_write), a
;.\main.c:165: delay_ms(5);
	ld	hl, #0x0005
	call	_delay_ms
;.\main.c:166: portH = 0x30;
	ld	a, #0x30
	out	(_portH), a
;.\main.c:167: LCD_command_write = 0x00;
	ld	a, #0x00
	out	(_LCD_command_write), a
;.\main.c:169: delay_ms(1);
	ld	hl, #0x0001
	call	_delay_ms
;.\main.c:170: portH = 0x30;
	ld	a, #0x30
	out	(_portH), a
;.\main.c:171: LCD_command_write = 0x00;
	ld	a, #0x00
	out	(_LCD_command_write), a
;.\main.c:173: delay_ms(1);
	ld	hl, #0x0001
	call	_delay_ms
;.\main.c:174: portH = _LCD_8BIT_MODE_2_LINE;
	ld	a, #0x38
	out	(_portH), a
;.\main.c:175: LCD_command_write = 0x00;
	ld	a, #0x00
	out	(_LCD_command_write), a
;.\main.c:177: delay_ms(1);
	ld	hl, #0x0001
	call	_delay_ms
;.\main.c:178: portH = _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF;
	ld	a, #0x0c
	out	(_portH), a
;.\main.c:179: LCD_command_write = 0x00;
	ld	a, #0x00
	out	(_LCD_command_write), a
;.\main.c:181: delay_ms(1);
	ld	hl, #0x0001
	call	_delay_ms
;.\main.c:182: portH = _LCD_CLEAR;
	ld	a, #0x01
	out	(_portH), a
;.\main.c:183: LCD_command_write = 0x00;
	ld	a, #0x00
	out	(_LCD_command_write), a
;.\main.c:185: delay_ms(1);
	ld	hl, #0x0001
	call	_delay_ms
;.\main.c:186: portH = _LCD_ENTRY_MODE_INC_SHIFT_OFF;
	ld	a, #0x06
	out	(_portH), a
;.\main.c:187: LCD_command_write = 0x00;
	ld	a, #0x00
	out	(_LCD_command_write), a
;.\main.c:189: delay_ms(1);
	ld	hl, #0x0001
	call	_delay_ms
;.\main.c:190: portH = _LCD_RETURN_HOME;
	ld	a, #0x02
	out	(_portH), a
;.\main.c:191: LCD_command_write = 0x00;
	ld	a, #0x00
	out	(_LCD_command_write), a
;.\main.c:192: }
	ret
;.\main.c:193: void lcd_8bit_send_command(uint8_t command)
;	---------------------------------
; Function lcd_8bit_send_command
; ---------------------------------
_lcd_8bit_send_command::
	out	(_portH), a
;.\main.c:196: LCD_command_write = 0x00;
	ld	a, #0x00
	out	(_LCD_command_write), a
;.\main.c:197: }
	ret
;.\main.c:198: void lcd_8bit_send_char_data(uint8_t data)
;	---------------------------------
; Function lcd_8bit_send_char_data
; ---------------------------------
_lcd_8bit_send_char_data::
	out	(_portH), a
;.\main.c:201: LCD_data_write = 0x00;
	ld	a, #0x00
	out	(_LCD_data_write), a
;.\main.c:202: }
	ret
;.\main.c:203: void lcd_8bit_send_string(char* str)
;	---------------------------------
; Function lcd_8bit_send_string
; ---------------------------------
_lcd_8bit_send_string::
;.\main.c:205: while (*str)
00101$:
	ld	a, (hl)
	or	a, a
	ret	Z
;.\main.c:207: lcd_8bit_send_char_data(*str++);
	inc	hl
	ld	c, a
	push	hl
	ld	a, c
	call	_lcd_8bit_send_char_data
	pop	hl
;.\main.c:209: }
	jr	00101$
;.\main.c:210: void lcd_8bit_set_cursor(uint8_t row, uint8_t coulmn)
;	---------------------------------
; Function lcd_8bit_set_cursor
; ---------------------------------
_lcd_8bit_set_cursor::
;.\main.c:212: coulmn--;
	dec	l
;.\main.c:214: case ROW1: lcd_8bit_send_command((0x80 + coulmn)); break; /* 0x00 -> Decimal : 0  */
;.\main.c:213: switch (row) {
	cp	a, #0x01
	jr	Z, 00101$
	cp	a, #0x02
	jr	Z, 00102$
	cp	a, #0x03
	jr	Z, 00103$
	sub	a, #0x04
	jr	Z, 00104$
	ret
;.\main.c:214: case ROW1: lcd_8bit_send_command((0x80 + coulmn)); break; /* 0x00 -> Decimal : 0  */
00101$:
	ld	a, l
	add	a, #0x80
	ld	c, a
	jp	_lcd_8bit_send_command
;.\main.c:215: case ROW2: lcd_8bit_send_command((0xc0 + coulmn)); break; /* 0x40 -> Decimal : 64 */
00102$:
	ld	a, l
	add	a, #0xc0
	ld	c, a
	jp	_lcd_8bit_send_command
;.\main.c:216: case ROW3: lcd_8bit_send_command((0x94 + coulmn)); break; /* 0x14 -> Decimal : 20 */
00103$:
	ld	a, l
	add	a, #0x94
	ld	c, a
	jp	_lcd_8bit_send_command
;.\main.c:217: case ROW4: lcd_8bit_send_command((0xd4 + coulmn)); break; /* 0x54 -> Decimal : 84 */
00104$:
	ld	a, l
	add	a, #0xd4
	ld	c, a
;.\main.c:219: }
;.\main.c:220: }
	jp	_lcd_8bit_send_command
;.\main.c:221: void lcd_8bit_send_uint8_hex_data(uint8_t data) {
;	---------------------------------
; Function lcd_8bit_send_uint8_hex_data
; ---------------------------------
_lcd_8bit_send_uint8_hex_data::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	ld	e, a
;.\main.c:227: hex_string[0] = hex_chars[(data >> 4) & 0x0F];
	ld	bc, #_hex_chars+0
	ld	a, e
	rlca
	rlca
	rlca
	rlca
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
	and	a, #0xf
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, bc
	ld	a, (hl)
	ld	-2 (ix), a
;.\main.c:228: hex_string[1] = hex_chars[data & 0x0F];
	ld	a, e
	and	a, #0x0f
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, bc
	ld	a, (hl)
	ld	-1 (ix), a
;.\main.c:231: for (int i = 0; i < 2; ++i) {
	ld	bc, #0x0000
00103$:
	ld	a, c
	sub	a, #0x02
	ld	a, b
	rla
	ccf
	rra
	sbc	a, #0x80
	jr	NC, 00105$
;.\main.c:232: lcd_8bit_send_char_data(hex_string[i]);
	ld	hl, #0
	add	hl, sp
	add	hl, bc
	ld	e, (hl)
	push	bc
	ld	a, e
	call	_lcd_8bit_send_char_data
	pop	bc
;.\main.c:231: for (int i = 0; i < 2; ++i) {
	inc	bc
	jr	00103$
00105$:
;.\main.c:234: }
	ld	sp, ix
	pop	ix
	ret
;.\main.c:236: void p8255_initialize()
;	---------------------------------
; Function p8255_initialize
; ---------------------------------
_p8255_initialize::
;.\main.c:238: p8255 = P8255_DEFAULT_MODE;
	ld	a, #0x90
	out	(_p8255), a
;.\main.c:239: portB = 0x00;
	ld	a, #0x00
	out	(_portB), a
;.\main.c:240: portC = 0x00;
	ld	a, #0x00
	out	(_portC), a
;.\main.c:241: }
	ret
;.\main.c:243: void dot_address()
;	---------------------------------
; Function dot_address
; ---------------------------------
_dot_address::
;.\main.c:245: SETBIT(buffer[0], 2);
	ld	a, (#_buffer + 0)
	set	2, a
	ld	(#_buffer),a
;.\main.c:246: SETBIT(buffer[1], 2);
	ld	bc, #_buffer + 1
	ld	a, (bc)
	set	2, a
	ld	(bc), a
;.\main.c:248: CLEARBIT(buffer[2], 2);
	ld	bc, #_buffer + 2
	ld	a, (bc)
	res	2, a
	ld	(bc), a
;.\main.c:249: CLEARBIT(buffer[3], 2);
	ld	bc, #_buffer + 3
	ld	a, (bc)
	res	2, a
	ld	(bc), a
;.\main.c:250: CLEARBIT(buffer[4], 2);
	ld	bc, #_buffer + 4
	ld	a, (bc)
	res	2, a
	ld	(bc), a
;.\main.c:251: CLEARBIT(buffer[5], 2);
	ld	bc, #_buffer + 5
	ld	a, (bc)
	res	2, a
	ld	(bc), a
;.\main.c:252: }
	ret
;.\main.c:254: void dot_data()
;	---------------------------------
; Function dot_data
; ---------------------------------
_dot_data::
;.\main.c:256: CLEARBIT(buffer[0], 2);
	ld	a, (#_buffer + 0)
	res	2, a
	ld	(#_buffer),a
;.\main.c:257: CLEARBIT(buffer[1], 2);
	ld	bc, #_buffer + 1
	ld	a, (bc)
	res	2, a
	ld	(bc), a
;.\main.c:259: SETBIT(buffer[2], 2);
	ld	bc, #_buffer + 2
	ld	a, (bc)
	set	2, a
	ld	(bc), a
;.\main.c:260: SETBIT(buffer[3], 2);
	ld	bc, #_buffer + 3
	ld	a, (bc)
	set	2, a
	ld	(bc), a
;.\main.c:261: SETBIT(buffer[4], 2);
	ld	bc, #_buffer + 4
	ld	a, (bc)
	set	2, a
	ld	(bc), a
;.\main.c:262: SETBIT(buffer[5], 2);
	ld	bc, #_buffer + 5
	ld	a, (bc)
	set	2, a
	ld	(bc), a
;.\main.c:263: }
	ret
;.\main.c:265: void address_buffer_write(uint16_t value)
;	---------------------------------
; Function address_buffer_write
; ---------------------------------
_address_buffer_write::
	ld	(_temp16), hl
;.\main.c:268: buffer[2] = convert[temp16 & 0xf];
	ld	bc, #_convert+0
	ld	hl, (_temp16)
	ld	a, l
	and	a, #0x0f
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, bc
	ld	a, (hl)
	ld	(#(_buffer + 2)),a
;.\main.c:269: temp16 >>= 4;
	xor	a, a
	ld	hl, #_temp16+1
	rrd
	dec	hl
	rrd
;.\main.c:270: buffer[3] = convert[temp16 & 0xf];
	ld	hl, (_temp16)
	ld	a, l
	and	a, #0x0f
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, bc
	ld	a, (hl)
	ld	(#(_buffer + 3)),a
;.\main.c:271: temp16 >>= 4;
	xor	a, a
	ld	hl, #_temp16+1
	rrd
	dec	hl
	rrd
;.\main.c:272: buffer[4] = convert[temp16 & 0xf];
	ld	hl, (_temp16)
	ld	a, l
	and	a, #0x0f
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, bc
	ld	a, (hl)
	ld	(#(_buffer + 4)),a
;.\main.c:273: temp16 >>= 4;
	xor	a, a
	ld	hl, #_temp16+1
	rrd
	dec	hl
	rrd
;.\main.c:274: buffer[5] = convert[temp16 & 0xf];
	ld	hl, (_temp16)
	ld	a, l
	and	a, #0x0f
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, bc
	ld	a, (hl)
	ld	(#(_buffer + 5)),a
;.\main.c:275: }
	ret
;.\main.c:277: void data_buffer_write(uint8_t value)
;	---------------------------------
; Function data_buffer_write
; ---------------------------------
_data_buffer_write::
;.\main.c:279: temp = value;
	ld	(_temp+0), a
	ld	hl, #_temp + 1
	ld	(hl), #0x00
;.\main.c:280: buffer[0] = convert[temp & 0xf];
	ld	bc, #_buffer+0
	ld	de, #_convert+0
	ld	hl, (_temp)
	ld	a, l
	and	a, #0x0f
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, de
	ld	a, (hl)
	ld	(bc), a
;.\main.c:281: temp >>= 4;
	xor	a, a
	ld	hl, #_temp+1
	rrd
	dec	hl
	rrd
;.\main.c:282: buffer[1] = convert[temp & 0xf];
	inc	bc
	ld	hl, (_temp)
	ld	a, l
	and	a, #0x0f
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, de
	ld	a, (hl)
	ld	(bc), a
;.\main.c:283: }
	ret
;.\main.c:285: void address_display()
;	---------------------------------
; Function address_display
; ---------------------------------
_address_display::
;.\main.c:287: temp = PC;
	ld	hl, (_PC)
;.\main.c:288: address_buffer_write(temp);
	ld	(_temp), hl
;.\main.c:289: }
	jp	_address_buffer_write
;.\main.c:291: void data_display()
;	---------------------------------
; Function data_display
; ---------------------------------
_data_display::
;.\main.c:293: dptr = PC;
	ld	hl, (_PC)
;.\main.c:295: uint8_t data = *dptr;
	ld	(_dptr), hl
	ld	c, (hl)
;.\main.c:297: data_buffer_write(data);
	ld	a, c
;.\main.c:298: }
	jp	_data_buffer_write
;.\main.c:300: void read_memory()
;	---------------------------------
; Function read_memory
; ---------------------------------
_read_memory::
;.\main.c:302: address_display();
	call	_address_display
;.\main.c:303: data_display();
;.\main.c:304: }
	jp	_data_display
;.\main.c:306: void key_address()
;	---------------------------------
; Function key_address
; ---------------------------------
_key_address::
;.\main.c:308: state = 1;
	ld	hl, #_state
	ld	(hl), #0x01
;.\main.c:309: hit = 0;
	ld	hl, #_hit
	ld	(hl), #0x00
;.\main.c:310: read_memory();
	call	_read_memory
;.\main.c:311: dot_address();
;.\main.c:312: }
	jp	_dot_address
;.\main.c:314: void key_data()
;	---------------------------------
; Function key_data
; ---------------------------------
_key_data::
;.\main.c:316: state = 2;
	ld	hl, #_state
	ld	(hl), #0x02
;.\main.c:317: hit = 0;
	ld	hl, #_hit
	ld	(hl), #0x00
;.\main.c:318: read_memory();
	call	_read_memory
;.\main.c:319: dot_data();
;.\main.c:320: }
	jp	_dot_data
;.\main.c:322: void key_plus()
;	---------------------------------
; Function key_plus
; ---------------------------------
_key_plus::
;.\main.c:325: if (state == 1 || state == 2)
	ld	a, (_state+0)
	dec	a
	jr	Z, 00101$
	ld	a, (_state+0)
	sub	a, #0x02
	ret	NZ
00101$:
;.\main.c:327: PC++;
	ld	hl, (_PC)
	inc	hl
	ld	(_PC), hl
;.\main.c:328: key_data();
;.\main.c:330: }
	jp	_key_data
;.\main.c:332: void key_minus()
;	---------------------------------
; Function key_minus
; ---------------------------------
_key_minus::
;.\main.c:334: if (state == 1 | state == 2)
	ld	a, (_state+0)
	dec	a
	ld	a, #0x01
	jr	Z, 00113$
	xor	a, a
00113$:
	ld	c, a
	ld	a, (_state+0)
	sub	a, #0x02
	ld	a, #0x01
	jr	Z, 00115$
	xor	a, a
00115$:
	or	a, c
	or	a, a
	ret	Z
;.\main.c:336: PC--;
	ld	hl, (_PC)
	dec	hl
	ld	(_PC), hl
;.\main.c:337: key_data();
;.\main.c:339: }
	jp	_key_data
;.\main.c:341: void key_PC()
;	---------------------------------
; Function key_PC
; ---------------------------------
_key_PC::
;.\main.c:343: PC = save_PC;
	ld	hl, (_save_PC)
	ld	(_PC), hl
;.\main.c:344: key_data();
;.\main.c:345: }
	jp	_key_data
;.\main.c:347: void hex_address()
;	---------------------------------
; Function hex_address
; ---------------------------------
_hex_address::
;.\main.c:349: if (hit == 0)
	ld	a, (_hit+0)
	or	a, a
	jr	NZ, 00102$
;.\main.c:351: PC = 0;
	ld	hl, #0x0000
	ld	(_PC), hl
00102$:
;.\main.c:353: hit = 1;
	ld	hl, #_hit
	ld	(hl), #0x01
;.\main.c:354: PC <<= 4;
	ld	hl, (_PC)
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	(_PC), hl
;.\main.c:355: PC |= key;
	ld	a, (_key+0)
	ld	c, a
	ld	a, (_PC+0)
	or	a, c
	ld	(_PC+0), a
;.\main.c:356: read_memory();
	call	_read_memory
;.\main.c:357: dot_address();
;.\main.c:358: }
	jp	_dot_address
;.\main.c:360: void data_hex()
;	---------------------------------
; Function data_hex
; ---------------------------------
_data_hex::
;.\main.c:362: dptr = PC;
	ld	hl, (_PC)
	ld	(_dptr), hl
;.\main.c:363: data_in = *dptr;
	ld	bc, (_dptr)
	ld	a, (bc)
	ld	(_data_in+0), a
;.\main.c:365: if (hit == 0)
	ld	a, (_hit+0)
	or	a, a
	jr	NZ, 00102$
;.\main.c:367: data_in = 0;
	ld	hl, #_data_in
	ld	(hl), #0x00
00102$:
;.\main.c:370: hit = 1;
	ld	hl, #_hit
	ld	(hl), #0x01
;.\main.c:371: data_in = data_in << 4;
	ld	a, (_data_in+0)
	add	a, a
	add	a, a
	add	a, a
	add	a, a
;.\main.c:372: data_in = data_in | key;
	ld	(_data_in+0), a
	ld	hl, #_key
	or	a, (hl)
;.\main.c:374: *dptr = data_in;
	ld	(_data_in+0), a
	ld	(bc), a
;.\main.c:376: read_memory();
	call	_read_memory
;.\main.c:377: dot_data();
;.\main.c:378: }
	jp	_dot_data
;.\main.c:379: void key_reg()
;	---------------------------------
; Function key_reg
; ---------------------------------
_key_reg::
;.\main.c:381: buffer[5] = 0x67;
	ld	hl, #_buffer + 5
	ld	(hl), #0x67
;.\main.c:382: buffer[4] = 0x8C;
	ld	hl, #_buffer + 4
	ld	(hl), #0x8c
;.\main.c:383: buffer[3] = 0x05;
	ld	hl, #_buffer + 3
	ld	(hl), #0x05
;.\main.c:384: buffer[2] = 0xFF;
	ld	hl, #_buffer + 2
	ld	(hl), #0xff
;.\main.c:385: buffer[1] = 0xFF;
	ld	hl, #_buffer + 1
	ld	(hl), #0xff
;.\main.c:386: buffer[0] = 0xFF;
	ld	hl, #_buffer
	ld	(hl), #0xff
;.\main.c:388: state = 3;    /* register display state = 3 with hex key */
	ld	hl, #_state
	ld	(hl), #0x03
;.\main.c:390: }
	ret
;.\main.c:392: void reg_AF()
;	---------------------------------
; Function reg_AF
; ---------------------------------
_reg_AF::
;.\main.c:395: temp16 = USER_AF;
	ld	hl, (_USER_AF)
;.\main.c:397: address_buffer_write(temp16);
	ld	(_temp16), hl
	call	_address_buffer_write
;.\main.c:400: buffer[1] = 0x06;
	ld	hl, #_buffer + 1
	ld	(hl), #0x06
;.\main.c:401: buffer[0] = 0x8E;
	ld	hl, #_buffer
	ld	(hl), #0x8e
;.\main.c:402: }
	ret
;.\main.c:403: void reg_BC()
;	---------------------------------
; Function reg_BC
; ---------------------------------
_reg_BC::
;.\main.c:406: temp16 = USER_BC;
	ld	hl, (_USER_BC)
;.\main.c:408: address_buffer_write(temp16);
	ld	(_temp16), hl
	call	_address_buffer_write
;.\main.c:411: buffer[1] = 0xA4;
	ld	hl, #_buffer + 1
	ld	(hl), #0xa4
;.\main.c:412: buffer[0] = 0x9C;
	ld	hl, #_buffer
	ld	(hl), #0x9c
;.\main.c:413: }
	ret
;.\main.c:414: void reg_DE()
;	---------------------------------
; Function reg_DE
; ---------------------------------
_reg_DE::
;.\main.c:417: temp16 = USER_DE;
	ld	hl, (_USER_DE)
;.\main.c:419: address_buffer_write(temp16);
	ld	(_temp16), hl
	call	_address_buffer_write
;.\main.c:422: buffer[1] = 0x64;
	ld	hl, #_buffer + 1
	ld	(hl), #0x64
;.\main.c:423: buffer[0] = 0x8C;
	ld	hl, #_buffer
	ld	(hl), #0x8c
;.\main.c:424: }
	ret
;.\main.c:425: void reg_HL()
;	---------------------------------
; Function reg_HL
; ---------------------------------
_reg_HL::
;.\main.c:427: temp16 = USER_HL;
	ld	hl, (_USER_HL)
;.\main.c:429: address_buffer_write(temp16);
	ld	(_temp16), hl
	call	_address_buffer_write
;.\main.c:431: buffer[1] = 0x26;
	ld	hl, #_buffer + 1
	ld	(hl), #0x26
;.\main.c:432: buffer[0] = 0xBC;
	ld	hl, #_buffer
	ld	(hl), #0xbc
;.\main.c:433: }
	ret
;.\main.c:434: void reg_IX()
;	---------------------------------
; Function reg_IX
; ---------------------------------
_reg_IX::
;.\main.c:436: temp16 = USER_IX;
	ld	hl, (_USER_IX)
;.\main.c:438: address_buffer_write(temp16);
	ld	(_temp16), hl
	call	_address_buffer_write
;.\main.c:440: buffer[1] = 0x77;
	ld	hl, #_buffer + 1
	ld	(hl), #0x77
;.\main.c:441: buffer[0] = 0x67;
	ld	hl, #_buffer
	ld	(hl), #0x67
;.\main.c:442: }
	ret
;.\main.c:443: void reg_IY()
;	---------------------------------
; Function reg_IY
; ---------------------------------
_reg_IY::
;.\main.c:446: temp16 = USER_IY;
	ld	hl, (_USER_IY)
;.\main.c:448: address_buffer_write(temp16);
	ld	(_temp16), hl
	call	_address_buffer_write
;.\main.c:451: buffer[1] = 0x77;
	ld	hl, #_buffer + 1
	ld	(hl), #0x77
;.\main.c:452: buffer[0] = 0xAE;
	ld	hl, #_buffer
	ld	(hl), #0xae
;.\main.c:453: }
	ret
;.\main.c:454: void reg_SP()
;	---------------------------------
; Function reg_SP
; ---------------------------------
_reg_SP::
;.\main.c:457: temp16 = USER_SP;
	ld	hl, (_USER_SP)
;.\main.c:459: address_buffer_write(temp16);
	ld	(_temp16), hl
	call	_address_buffer_write
;.\main.c:462: buffer[1] = 0x85;
	ld	hl, #_buffer + 1
	ld	(hl), #0x85
;.\main.c:463: buffer[0] = 0x0E;
	ld	hl, #_buffer
	ld	(hl), #0x0e
;.\main.c:464: }
	ret
;.\main.c:466: void reg_display()
;	---------------------------------
; Function reg_display
; ---------------------------------
_reg_display::
;.\main.c:469: switch (key)
	ld	a, #0x06
	ld	iy, #_key
	sub	a, 0 (iy)
	ret	C
	ld	c, 0 (iy)
	ld	b, #0x00
	ld	hl, #00118$
	add	hl, bc
	add	hl, bc
	add	hl, bc
	jp	(hl)
00118$:
	jp	_reg_AF
	jp	_reg_BC
	jp	_reg_DE
	jp	_reg_HL
	jp	_reg_IX
	jp	_reg_IY
;.\main.c:471: case 0: reg_AF(); break;
;.\main.c:472: case 1: reg_BC(); break;
;.\main.c:473: case 2: reg_DE(); break;
;.\main.c:474: case 3: reg_HL(); break;
;.\main.c:475: case 4: reg_IX(); break;
;.\main.c:476: case 5: reg_IY(); break;
;.\main.c:477: case 6: reg_SP(); break;
;.\main.c:478: }
;.\main.c:479: }
	jp	_reg_SP
;.\main.c:481: void key_step()
;	---------------------------------
; Function key_step
; ---------------------------------
_key_step::
;.\main.c:518: __endasm;
	ld(_SYS_SP),	sp; save system stack
	ld	sp, (_USER_SP); reload with user stack
;	load CPU registers with user registers
	ld	hl, (_USER_IY)
	push	hl
	ld	hl, (_USER_IX)
	push	hl
	ld	hl, (_USER_DE)
	push	hl
	ld	hl, (_USER_BC)
	push	hl
	ld	hl, (_USER_AF)
	push	hl
	pop	af
	pop	bc
	pop	de
	pop	ix
	pop	iy
	ld	hl, (_PC)
	push	hl
	ld(_temp8),	a
	ld	a, #0x40
	out(_portE),	a
	ld	a, (_temp8) ; 1st M1
	ld	hl, (_USER_HL) ; 2nd M1
	ret	; 3rd M1
;.\main.c:520: }
	ret
;.\main.c:522: void key_go()
;	---------------------------------
; Function key_go
; ---------------------------------
_key_go::
;.\main.c:524: if (state == 1 || state == 2)
	ld	a, (_state+0)
	dec	a
	jr	Z, 00101$
	ld	a, (_state+0)
	sub	a, #0x02
	ret	NZ
00101$:
;.\main.c:555: __endasm;
	ld(_SYS_SP),	sp; save system stack
	ld	sp, (_USER_SP); reload with user stack
;	load CPU registers with user registers
	ld	hl, (_USER_IY)
	push	hl
	ld	hl, (_USER_IX)
	push	hl
	ld	hl, (_USER_DE)
	push	hl
	ld	hl, (_USER_BC)
	push	hl
	ld	hl, (_USER_AF)
	push	hl
	pop	af
	pop	bc
	pop	de
	pop	ix
	pop	iy
	ld	hl, (_PC)
	push	hl
	ld	hl, (_USER_HL)
;.\main.c:557: }
	ret
;.\main.c:559: void key_usart_receive_byte(void)
;	---------------------------------
; Function key_usart_receive_byte
; ---------------------------------
_key_usart_receive_byte::
;.\main.c:561: temp8 = 0x00;
	ld	hl, #_temp8
	ld	(hl), #0x00
;.\main.c:562: portE = 0x00;
	ld	a, #0x00
	out	(_portE), a
;.\main.c:564: lcd_8bit_send_command(_LCD_CLEAR);
	ld	a, #0x01
	call	_lcd_8bit_send_command
;.\main.c:565: delay_ms(1);
	ld	hl, #0x0001
	call	_delay_ms
;.\main.c:566: lcd_8bit_set_cursor(1, 1);
;	spillPairReg hl
;	spillPairReg hl
	ld	a,#0x01
	ld	l,a
	call	_lcd_8bit_set_cursor
;.\main.c:567: lcd_8bit_send_string("Serial Mode");
	ld	hl, #___str_3
	call	_lcd_8bit_send_string
;.\main.c:569: while (1)
00106$:
;.\main.c:571: uint8_t keypad_col_value = portA;
	in	a, (_portA)
;.\main.c:572: if ((keypad_col_value & 0x80) == 0x80)
	and	a, #0x80
	sub	a, #0x80
	jr	NZ, 00106$
;.\main.c:574: temp8 = USART_READ;
	in	a, (_USART_READ)
	ld	(_temp8+0), a
;.\main.c:575: portE = 0x80;
	ld	a, #0x80
	out	(_portE), a
;.\main.c:577: if (temp8 == 0xE4)
	ld	a, (_temp8+0)
	sub	a, #0xe4
	jr	NZ, 00102$
;.\main.c:579: lcd_8bit_send_command(_LCD_CLEAR);
	ld	a, #0x01
	call	_lcd_8bit_send_command
;.\main.c:580: delay_ms(1);
	ld	hl, #0x0001
	call	_delay_ms
;.\main.c:581: lcd_8bit_set_cursor(1, 1);
;	spillPairReg hl
;	spillPairReg hl
	ld	a,#0x01
	ld	l,a
	call	_lcd_8bit_set_cursor
;.\main.c:582: lcd_8bit_send_string("Monitor Mode");
;.\main.c:583: break;
	ld	hl, #___str_4
	jp	_lcd_8bit_send_string
00102$:
;.\main.c:586: key = temp8;
	ld	a, (_temp8+0)
	ld	(_key+0), a
;.\main.c:587: key_exe();
	call	_key_exe
;.\main.c:589: portE = 0x00;
	ld	a, #0x00
	out	(_portE), a
;.\main.c:593: }
	jr	00106$
___str_3:
	.ascii "Serial Mode"
	.db 0x00
___str_4:
	.ascii "Monitor Mode"
	.db 0x00
;.\main.c:595: char key_code(char n)
;	---------------------------------
; Function key_code
; ---------------------------------
_key_code::
;.\main.c:597: switch (n)
	cp	a, #0x21
	jr	Z, 00102$
	cp	a, #0x22
	jr	Z, 00103$
	cp	a, #0x23
	jr	Z, 00104$
	cp	a, #0x24
	jr	Z, 00111$
	cp	a, #0x28
	jr	Z, 00105$
	cp	a, #0x29
	jr	Z, 00106$
	cp	a, #0x2a
	jr	Z, 00107$
	cp	a, #0x2b
	jr	Z, 00112$
	cp	a, #0x2f
	jr	Z, 00108$
	cp	a, #0x30
	jr	Z, 00109$
	cp	a, #0x31
	jr	Z, 00110$
	cp	a, #0x32
	jr	Z, 00113$
	cp	a, #0x36
	jr	Z, 00116$
	cp	a, #0x37
	jr	Z, 00101$
	cp	a, #0x38
	jr	Z, 00115$
	sub	a, #0x39
	jr	Z, 00114$
	jr	00117$
;.\main.c:599: case 0x37: key = 0; break;
00101$:
	ld	hl, #_key
	ld	(hl), #0x00
	jr	00117$
;.\main.c:600: case 0x21: key = 1; break;
00102$:
	ld	hl, #_key
	ld	(hl), #0x01
	jr	00117$
;.\main.c:601: case 0x22: key = 2; break;
00103$:
	ld	hl, #_key
	ld	(hl), #0x02
	jr	00117$
;.\main.c:602: case 0x23: key = 3; break;
00104$:
	ld	hl, #_key
	ld	(hl), #0x03
	jr	00117$
;.\main.c:603: case 0x28: key = 4; break;
00105$:
	ld	hl, #_key
	ld	(hl), #0x04
	jr	00117$
;.\main.c:604: case 0x29: key = 5; break;
00106$:
	ld	hl, #_key
	ld	(hl), #0x05
	jr	00117$
;.\main.c:605: case 0x2A: key = 6; break;
00107$:
	ld	hl, #_key
	ld	(hl), #0x06
	jr	00117$
;.\main.c:606: case 0x2F: key = 7; break;
00108$:
	ld	hl, #_key
	ld	(hl), #0x07
	jr	00117$
;.\main.c:607: case 0x30: key = 8; break;
00109$:
	ld	hl, #_key
	ld	(hl), #0x08
	jr	00117$
;.\main.c:608: case 0x31: key = 9; break;
00110$:
	ld	hl, #_key
	ld	(hl), #0x09
	jr	00117$
;.\main.c:609: case 0x24: key = 0xa; break;
00111$:
	ld	hl, #_key
	ld	(hl), #0x0a
	jr	00117$
;.\main.c:610: case 0x2B: key = 0xb; break;
00112$:
	ld	hl, #_key
	ld	(hl), #0x0b
	jr	00117$
;.\main.c:611: case 0x32: key = 0xc; break;
00113$:
	ld	hl, #_key
	ld	(hl), #0x0c
	jr	00117$
;.\main.c:612: case 0x39: key = 0xd; break;
00114$:
	ld	hl, #_key
	ld	(hl), #0x0d
	jr	00117$
;.\main.c:613: case 0x38: key = 0xe; break;
00115$:
	ld	hl, #_key
	ld	(hl), #0x0e
	jr	00117$
;.\main.c:614: case 0x36: key = 0xf; break;
00116$:
	ld	hl, #_key
	ld	(hl), #0x0f
;.\main.c:615: }
00117$:
;.\main.c:616: return key;
	ld	a, (_key+0)
;.\main.c:617: }
	ret
;.\main.c:619: char scan()
;	---------------------------------
; Function scan
; ---------------------------------
_scan::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-6
	add	hl, sp
	ld	sp, hl
;.\main.c:621: char keypad_row_value = 1;
	ld	-4 (ix), #0x01
;.\main.c:622: key = 0;
	ld	hl, #_key
	ld	(hl), #0x00
;.\main.c:623: char key_code = 0x21;
	ld	-1 (ix), #0x21
;.\main.c:625: for (char i = 0; i < 6; i++)
	ld	-3 (ix), #0x00
00112$:
	ld	a, -3 (ix)
	sub	a, #0x06
	jr	NC, 00107$
;.\main.c:627: portE = keypad_row_value;
	ld	a, -4 (ix)
	out	(_portE), a
;.\main.c:629: portF = buffer[i];
	ld	a, #<(_buffer)
	add	a, -3 (ix)
	ld	-6 (ix), a
	ld	a, #>(_buffer)
	adc	a, #0x00
	ld	-5 (ix), a
	pop	hl
	push	hl
	ld	a, (hl)
	out	(_portF), a
;.\main.c:630: delay(2);
	ld	hl, #0x0002
	call	_delay
;.\main.c:631: portF = 0xFF;
	ld	a, #0xff
	out	(_portF), a
;.\main.c:633: delay(1);
	ld	hl, #0x0001
	call	_delay
;.\main.c:635: if (i < 4)
	ld	a, -3 (ix)
	sub	a, #0x04
	jr	NC, 00106$
;.\main.c:637: uint8_t keypad_col_value = portA;
	in	a, (_portA)
	ld	-2 (ix), a
;.\main.c:639: for (char i = 0; i < 7; i++)
	ld	c, #0x00
00109$:
	ld	a, c
	sub	a, #0x07
	jr	NC, 00122$
;.\main.c:641: if ((keypad_col_value & 1) == 1)
	ld	a, -2 (ix)
	and	a, #0x01
	dec	a
	jr	NZ, 00102$
;.\main.c:643: key = key_code;
	ld	a, -1 (ix)
	ld	(_key+0), a
	jr	00103$
00102$:
;.\main.c:646: else key_code++;
	inc	-1 (ix)
00103$:
;.\main.c:647: keypad_col_value >>= 1;
	srl	-2 (ix)
;.\main.c:639: for (char i = 0; i < 7; i++)
	inc	c
	jr	00109$
00122$:
00106$:
;.\main.c:650: keypad_row_value <<= 1;
	ld	a, -4 (ix)
	add	a, a
	ld	-4 (ix), a
;.\main.c:625: for (char i = 0; i < 6; i++)
	inc	-3 (ix)
	jr	00112$
00107$:
;.\main.c:654: return key;
	ld	a, (_key+0)
;.\main.c:656: }
	ld	sp, ix
	pop	ix
	ret
;.\main.c:658: void key_exe()
;	---------------------------------
; Function key_exe
; ---------------------------------
_key_exe::
;.\main.c:660: switch (key)
	ld	a, (_key+0)
	sub	a, #0x25
	jp	Z,_key_address
	ld	a, (_key+0)
	sub	a, #0x26
	jp	Z,_key_data
	ld	a, (_key+0)
	sub	a, #0x27
	jp	Z,_key_reg
	ld	a, (_key+0)
	sub	a, #0x2c
	jp	Z,_key_plus
	ld	a, (_key+0)
	sub	a, #0x2d
	jp	Z,_key_minus
	ld	a, (_key+0)
	sub	a, #0x2e
	jp	Z,_key_PC
	ld	a, (_key+0)
	sub	a, #0x33
	jp	Z,_key_step
	ld	a, (_key+0)
	sub	a, #0x35
	jp	Z,_key_go
	ld	a, (_key+0)
	sub	a, #0x3a
	jp	Z,_key_usart_receive_byte
;.\main.c:662: case 0x25: key_address(); break;
;.\main.c:663: case 0x26: key_data(); break;
;.\main.c:664: case 0x2C: key_plus(); break;
;.\main.c:665: case 0x2D: key_minus(); break;
;.\main.c:666: case 0x2E: key_PC(); break;
;.\main.c:667: case 0x27: key_reg(); break;
;.\main.c:668: case 0x35: key_go(); break;
;.\main.c:669: case 0x33: key_step(); break;
;.\main.c:671: case 0x3A: key_usart_receive_byte(); break;
;.\main.c:674: default:
;.\main.c:675: switch (state)
	ld	a, (_state+0)
	dec	a
	jp	Z,_hex_address
	ld	a, (_state+0)
	sub	a, #0x02
	jp	Z,_data_hex
	ld	a, (_state+0)
	sub	a, #0x03
	jp	Z,_reg_display
;.\main.c:677: case 1: hex_address(); break;
;.\main.c:678: case 2: data_hex(); break;
;.\main.c:679: case 3: reg_display(); break;
;.\main.c:684: }
;.\main.c:686: }
	ret
;.\main.c:688: void scan1()
;	---------------------------------
; Function scan1
; ---------------------------------
_scan1::
;.\main.c:690: while (scan() != 0)
00101$:
	call	_scan
	or	a, a
	jr	NZ, 00101$
;.\main.c:692: delay(3);
	ld	hl, #0x0003
	call	_delay
;.\main.c:694: while (scan() == 0)
00104$:
	call	_scan
	or	a, a
	jr	Z, 00104$
;.\main.c:696: delay(3);
	ld	hl, #0x0003
	call	_delay
;.\main.c:698: key = scan();
	call	_scan
;.\main.c:700: key = key_code(key);
	ld	(_key+0), a
	call	_key_code
	ld	(_key+0), a
;.\main.c:702: key_exe();
;.\main.c:704: }
	jp	_key_exe
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
