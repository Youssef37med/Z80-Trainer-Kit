// Z80 Microprocessor Kit sdcc version
// Written by Youssef Ahmed Tawfik (C) 2024


// memory layout
// 0000  ROM
// 7FFF
// 8000  RAM
// FFFF

#pragma disable_warning 154

#include "lcd.h"
#include "keypad.h"
#include "seven_segment.h"
#include "main.h"
#include "utils.h"
#include "p8255.h"
#include "usart.h"

uint8_t buffer[6];
uint16_t temp, temp16;
uint8_t temp8;
uint8_t count;

uint8_t key,data_in;
uint8_t state;
uint8_t hit;

uint16_t PC, save_PC;
uint16_t USER_AF, USER_BC, USER_DE, USER_HL;
uint16_t USER_IX, USER_IY;
uint16_t USER_SP, SYS_SP;

uint8_t* dptr;

// table for converting 0-F to 7-segment LED
const uint8_t convert[] = { 0x14,0x77,0x4C,0x45,0x27,0x85,0x84,0x57,0x04,0x05,0x06,0xA4,0x9C,0x64,0x8C,0x8E };
const int8_t hex_chars[] = "0123456789ABCDEF";

void main(void)
{
	portE = 0x00;
	portF = 0xFF;

	buffer[0] = 0x77;
	buffer[1] = 0xEF;
	buffer[2] = 0xEF;
	buffer[3] = 0x34;
	buffer[4] = 0x0E;
	buffer[5] = 0x9C;

	PC = 0x8100;
	save_PC = 0x8100;
	USER_SP = 0x9FFF;

	state = 0;

	count = 0;

	lcd_8bit_initialize();
	p8255_initialize();

	lcd_8bit_send_string("Z80 Processor");
	lcd_8bit_set_cursor(2, 1);
	lcd_8bit_send_string("Trainer Kit");

	while (1)
	{
		scan1();
	}
}

void default_handler(void)
{
	__asm
		push af
		push bc
		push de
		push hl
		push ix
		push iy
		ld hl, #0x80
		call _delay_ms
		pop iy
		pop ix
		pop hl
		pop de
		pop bc
		pop af
		jp _nmi_handler
		__endasm;
}
void nmi_handler(void)
{
	__asm
		ld(_temp8), a
		ld a, #0x00
		out(_portE), a
		ld a, (_temp8)

		ld(_temp16), hl; save hl
		pop hl
		ld(_save_PC), hl; save current PC
		ld(_USER_SP), sp; save stack pointer
		ld hl, (_temp16); restore hl

		push af
		push bc
		push de
		push hl
		push ix
		push iy

		pop  hl
		ld(_USER_IY), hl
		pop  hl
		ld(_USER_IX), hl
		pop hl
		ld(_USER_HL), hl
		pop hl
		ld(_USER_DE), hl
		pop hl
		ld(_USER_BC), hl
		pop hl
		ld(_USER_AF), hl

		ld sp, (_SYS_SP); restore system stack

		call _key_PC

		ld hl, #0x010
		call _delay_ms

		__endasm;
}

void delay(uint16_t steps)
{
	uint16_t i;
	for (i = 0; i < steps; i++)
		;

}
void delay_ms(uint16_t milliseconds) {
	uint16_t i, j;
	for (i = 0; i < milliseconds; i++) {
		// Inner loop to generate a delay of approximately 1 millisecond
		for (j = 0; j < 30; j++) {
			// Each iteration of this loop takes approximately 4 clock cycles
			// Adjust this loop to match the required number of cycles
			__asm
				nop     // 1 cycle
			__endasm;
		}
	}
}

void lcd_8bit_initialize()
{
	delay_ms(15);
	portH = 0x30;
	LCD_command_write = 0x00;

	delay_ms(5);
	portH = 0x30;
	LCD_command_write = 0x00;

	delay_ms(1);
	portH = 0x30;
	LCD_command_write = 0x00;

	delay_ms(1);
	portH = _LCD_8BIT_MODE_2_LINE;
	LCD_command_write = 0x00;

	delay_ms(1);
	portH = _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF;
	LCD_command_write = 0x00;

	delay_ms(1);
	portH = _LCD_CLEAR;
	LCD_command_write = 0x00;

	delay_ms(1);
	portH = _LCD_ENTRY_MODE_INC_SHIFT_OFF;
	LCD_command_write = 0x00;

	delay_ms(1);
	portH = _LCD_RETURN_HOME;
	LCD_command_write = 0x00;
}
void lcd_8bit_send_command(uint8_t command)
{
	portH = command;
	LCD_command_write = 0x00;
}
void lcd_8bit_send_char_data(uint8_t data)
{
	portH = data;
	LCD_data_write = 0x00;
}
void lcd_8bit_send_string(char* str)
{
	while (*str)
	{
		lcd_8bit_send_char_data(*str++);
	}
}
void lcd_8bit_set_cursor(uint8_t row, uint8_t coulmn)
{
	coulmn--;
	switch (row) {
	case ROW1: lcd_8bit_send_command((0x80 + coulmn)); break; /* 0x00 -> Decimal : 0  */
	case ROW2: lcd_8bit_send_command((0xc0 + coulmn)); break; /* 0x40 -> Decimal : 64 */
	case ROW3: lcd_8bit_send_command((0x94 + coulmn)); break; /* 0x14 -> Decimal : 20 */
	case ROW4: lcd_8bit_send_command((0xd4 + coulmn)); break; /* 0x54 -> Decimal : 84 */
	default:;
	}
}
void lcd_8bit_send_uint8_hex_data(uint8_t data) {

	// Buffer to hold the two-digit hexadecimal representation.
	char hex_string[2]; // "XX"

	// Convert each nibble of the uint8_t data to a hexadecimal character.
	hex_string[0] = hex_chars[(data >> 4) & 0x0F];
	hex_string[1] = hex_chars[data & 0x0F];

	// Send each character of the hex string to the LCD.
	for (int i = 0; i < 2; ++i) {
		lcd_8bit_send_char_data(hex_string[i]);
	}
}

void p8255_initialize()
{
	p8255 = P8255_DEFAULT_MODE;
	portB = 0x00;
	portC = 0x00;
}

void dot_address()
{
	SETBIT(buffer[0], 2);
	SETBIT(buffer[1], 2);

	CLEARBIT(buffer[2], 2);
	CLEARBIT(buffer[3], 2);
	CLEARBIT(buffer[4], 2);
	CLEARBIT(buffer[5], 2);
}

void dot_data()
{
	CLEARBIT(buffer[0], 2);
	CLEARBIT(buffer[1], 2);

	SETBIT(buffer[2], 2);
	SETBIT(buffer[3], 2);
	SETBIT(buffer[4], 2);
	SETBIT(buffer[5], 2);
}

void address_buffer_write(uint16_t value)
{
	temp16 = value;
	buffer[2] = convert[temp16 & 0xf];
	temp16 >>= 4;
	buffer[3] = convert[temp16 & 0xf];
	temp16 >>= 4;
	buffer[4] = convert[temp16 & 0xf];
	temp16 >>= 4;
	buffer[5] = convert[temp16 & 0xf];
}

void data_buffer_write(uint8_t value)
{
	temp = value;
	buffer[0] = convert[temp & 0xf];
	temp >>= 4;
	buffer[1] = convert[temp & 0xf];
}

void address_display()
{
	temp = PC;
	address_buffer_write(temp);
}

void data_display()
{
	dptr = PC;

	uint8_t data = *dptr;

	data_buffer_write(data);
}

void read_memory()
{
	address_display();
	data_display();
}

void key_address()
{
	state = 1;
	hit = 0;
	read_memory();
	dot_address();
}

void key_data()
{
	state = 2;
	hit = 0;
	read_memory();
	dot_data();
}

void key_plus()
{

	if (state == 1 || state == 2)
	{
		PC++;
		key_data();
	}
}

void key_minus()
{
	if (state == 1 | state == 2)
	{
		PC--;
		key_data();
	}
}

void key_PC()
{
	PC = save_PC;
	key_data();
}

void hex_address()
{
	if (hit == 0)
	{
		PC = 0;
	}
	hit = 1;
	PC <<= 4;
	PC |= key;
	read_memory();
	dot_address();
}

void data_hex()
{
	dptr = PC;
	data_in = *dptr;
	
	if (hit == 0)
	{
		data_in = 0;
	}

	hit = 1;
	data_in = data_in << 4;
	data_in = data_in | key;

	*dptr = data_in;

	read_memory();
	dot_data();
}
void key_reg()
{
	buffer[5] = 0x67;
	buffer[4] = 0x8C;
	buffer[3] = 0x05;
	buffer[2] = 0xFF;
	buffer[1] = 0xFF;
	buffer[0] = 0xFF;

	state = 3;    /* register display state = 3 with hex key */

}

void reg_AF()
{

	temp16 = USER_AF;

	address_buffer_write(temp16);


	buffer[1] = 0x06;
	buffer[0] = 0x8E;
}
void reg_BC()
{

	temp16 = USER_BC;

	address_buffer_write(temp16);


	buffer[1] = 0xA4;
	buffer[0] = 0x9C;
}
void reg_DE()
{

	temp16 = USER_DE;

	address_buffer_write(temp16);


	buffer[1] = 0x64;
	buffer[0] = 0x8C;
}
void reg_HL()
{
	temp16 = USER_HL;

	address_buffer_write(temp16);

	buffer[1] = 0x26;
	buffer[0] = 0xBC;
}
void reg_IX()
{
	temp16 = USER_IX;

	address_buffer_write(temp16);

	buffer[1] = 0x77;
	buffer[0] = 0x67;
}
void reg_IY()
{

	temp16 = USER_IY;

	address_buffer_write(temp16);


	buffer[1] = 0x77;
	buffer[0] = 0xAE;
}
void reg_SP()
{

	temp16 = USER_SP;

	address_buffer_write(temp16);


	buffer[1] = 0x85;
	buffer[0] = 0x0E;
}

void reg_display()
{

	switch (key)
	{
		case 0: reg_AF(); break;
		case 1: reg_BC(); break;
		case 2: reg_DE(); break;
		case 3: reg_HL(); break;
		case 4: reg_IX(); break;
		case 5: reg_IY(); break;
		case 6: reg_SP(); break;
	}
}

void key_step()
{
	__asm

		ld(_SYS_SP), sp; save system stack
		ld sp, (_USER_SP); reload with user stack

		; load CPU registers with user registers


		ld hl, (_USER_IY)
		push  hl
		ld hl, (_USER_IX)
		push hl
		ld hl, (_USER_DE)
		push hl
		ld hl, (_USER_BC)
		push hl
		ld hl, (_USER_AF)
		push hl

		pop af
		pop bc
		pop de
		pop ix
		pop iy

		ld hl, (_PC)
		push hl

		ld(_temp8), a
		ld a, #0x40
		out(_portE), a
		ld a, (_temp8)	   ; 1st M1
		ld hl, (_USER_HL)  ; 2nd M1
		ret				   ; 3rd M1

		__endasm;

}

void key_go()
{
	if (state == 1 || state == 2)
	{
		__asm
			ld(_SYS_SP), sp; save system stack
			ld sp, (_USER_SP); reload with user stack

			; load CPU registers with user registers


			ld hl, (_USER_IY)
			push  hl
			ld hl, (_USER_IX)
			push hl
			ld hl, (_USER_DE)
			push hl
			ld hl, (_USER_BC)
			push hl
			ld hl, (_USER_AF)
			push hl

			pop af
			pop bc
			pop de
			pop ix
			pop iy

			ld hl, (_PC)
			push hl

			ld hl, (_USER_HL)

			__endasm;
	}
}

void key_usart_receive_byte(void)
{
	temp8 = 0x00;
	portE = 0x00;

	lcd_8bit_send_command(_LCD_CLEAR);
	delay_ms(1);
	lcd_8bit_set_cursor(1, 1);
	lcd_8bit_send_string("Serial Mode");

	while (1)
	{
		uint8_t keypad_col_value = portA;
		if ((keypad_col_value & 0x80) == 0x80)
		{
			temp8 = USART_READ;
			portE = 0x80;

			if (temp8 == 0xE4)
			{
				lcd_8bit_send_command(_LCD_CLEAR);
				delay_ms(1);
				lcd_8bit_set_cursor(1, 1);
				lcd_8bit_send_string("Monitor Mode");
				break;
			}

			key = temp8;
			key_exe();

			portE = 0x00;
		}
	}

}

char key_code(char n)
{
	switch (n)
	{
		case 0x37: key = 0; break;
		case 0x21: key = 1; break;
		case 0x22: key = 2; break;
		case 0x23: key = 3; break;
		case 0x28: key = 4; break;
		case 0x29: key = 5; break;
		case 0x2A: key = 6; break;
		case 0x2F: key = 7; break;
		case 0x30: key = 8; break;
		case 0x31: key = 9; break;
		case 0x24: key = 0xa; break;
		case 0x2B: key = 0xb; break;
		case 0x32: key = 0xc; break;
		case 0x39: key = 0xd; break;
		case 0x38: key = 0xe; break;
		case 0x36: key = 0xf; break;
	}
	return key;
}

char scan()
{
	char keypad_row_value = 1;
	key = 0;
	char key_code = 0x21;

	for (char i = 0; i < 6; i++)
	{
		portE = keypad_row_value;

		portF = buffer[i];
		delay(2);
		portF = 0xFF;

		delay(1);

		if (i < 4)
		{
			uint8_t keypad_col_value = portA;

			for (char i = 0; i < 7; i++)
			{
				if ((keypad_col_value & 1) == 1)
				{
					key = key_code;
				}

				else key_code++;
				keypad_col_value >>= 1;
			}
		}
		keypad_row_value <<= 1;
		
	}

	return key;

}

void key_exe()
{
	switch (key)
	{
	case 0x25: key_address(); break;
	case 0x26: key_data(); break;
	case 0x2C: key_plus(); break;
	case 0x2D: key_minus(); break;
	case 0x2E: key_PC(); break;
	case 0x27: key_reg(); break;
	case 0x35: key_go(); break;
	case 0x33: key_step(); break;
	//case 0x34: func1(); break;
	case 0x3A: key_usart_receive_byte(); break;
	//case 0x3B: func2(); break;
	//case 0x3C: func3(); break;
	default:
		switch (state)
		{
			case 1: hex_address(); break;
			case 2: data_hex(); break;
			case 3: reg_display(); break;
		}

	/*  case 0x14: key_user(); break;  available for user key */

	}
	
}

void scan1()
{
	while (scan() != 0)
		continue;
	delay(3);

	while (scan() == 0)
		continue;
	delay(3);

	key = scan();

	key = key_code(key);

	key_exe();

}
