
dist/default/production/ATmega.X.production.elf:     file format elf32-avr

Sections:
Idx Name          Size      VMA       LMA       File off  Algn
  0 .text         0000006c  00000000  00000000  00000074  2**1
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
  1 .data         00000000  00800060  00800060  0000013e  2**0
                  ALLOC, LOAD, DATA
  2 .comment      0000005b  00000000  00000000  0000013e  2**0
                  CONTENTS, READONLY
  3 .stack.descriptors.hdr 0000002a  00000000  00000000  00000199  2**0
                  CONTENTS, READONLY
  4 .debug_aranges 00000020  00000000  00000000  000001c3  2**0
                  CONTENTS, READONLY, DEBUGGING
  5 .debug_info   0000073f  00000000  00000000  000001e3  2**0
                  CONTENTS, READONLY, DEBUGGING
  6 .debug_abbrev 00000503  00000000  00000000  00000922  2**0
                  CONTENTS, READONLY, DEBUGGING
  7 .debug_line   000001b4  00000000  00000000  00000e25  2**0
                  CONTENTS, READONLY, DEBUGGING
  8 .debug_frame  00000034  00000000  00000000  00000fdc  2**2
                  CONTENTS, READONLY, DEBUGGING
  9 .debug_str    00000196  00000000  00000000  00001010  2**0
                  CONTENTS, READONLY, DEBUGGING
 10 .debug_ranges 00000010  00000000  00000000  000011a6  2**0
                  CONTENTS, READONLY, DEBUGGING
 11 .text         00000004  000000bc  000000bc  00000130  2**1
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 12 .note.gnu.avr.deviceinfo 0000003c  00000000  00000000  000011b8  2**2
                  CONTENTS, READONLY, DEBUGGING
 13 .text.main    0000003a  0000006c  0000006c  000000e0  2**1
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 14 .text.__dummy_fini 00000002  000000c4  000000c4  00000138  2**1
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 15 .text.__dummy_funcs_on_exit 00000002  000000c6  000000c6  0000013a  2**1
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 16 .text.__dummy_simulator_exit 00000002  000000c8  000000c8  0000013c  2**1
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 17 .text.exit    00000016  000000a6  000000a6  0000011a  2**1
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 18 .text._Exit   00000004  000000c0  000000c0  00000134  2**1
                  CONTENTS, ALLOC, LOAD, READONLY, CODE

Disassembly of section .text:

00000000 <__vectors>:
   0:	0c 94 2a 00 	jmp	0x54	; 0x54 <__ctors_end>
   4:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
   8:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
   c:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
  10:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
  14:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
  18:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
  1c:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
  20:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
  24:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
  28:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
  2c:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
  30:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
  34:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
  38:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
  3c:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
  40:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
  44:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
  48:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
  4c:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>
  50:	0c 94 5e 00 	jmp	0xbc	; 0xbc <__bad_interrupt>

00000054 <__ctors_end>:
  54:	11 24       	eor	r1, r1
  56:	1f be       	out	0x3f, r1	; 63 --> store r1 in 0x3F SREG (STATUS_REGISTER)
  58:	cf e5       	ldi	r28, 0x5F	; 95
  5a:	d8 e0       	ldi	r29, 0x08	; 8
    ; **************************************************************************
  5c:	de bf       	out	0x3e, r29	; 62 --> 0x3E SPH REG -> Starts with 8 (top of RAM) (Optional in some AVR Implementation)
  5e:	cd bf       	out	0x3d, r28	; 61 --> 0x3D SPL REG -> Starts with 95
    ; **************************************************************************
  60:	0e 94 36 00 	call	0x6c	; 0x6c <_etext>
  64:	0c 94 53 00 	jmp	0xa6	; 0xa6 <exit>

00000068 <_exit>:
  68:	f8 94       	cli

0000006a <__stop_program>:
  6a:	ff cf       	rjmp	.-2      	; 0x6a <__stop_program>

Disassembly of section .text:

000000bc <__bad_interrupt>:
  bc:	0c 94 00 00 	jmp	0	; 0x0 <__TEXT_REGION_ORIGIN__>

Disassembly of section .text.main:

0000006c <main>:
 *
 * Created on March 5, 2022, 5:44 AM
 */
#include <avr/io.h>
int main(void)
{
  6c:	cf 93       	push	r28
  6e:	df 93       	push	r29
  70:	00 d0       	rcall	.+0      	; 0x72 <main+0x6>
  72:	0f 92       	push	r0
    ; **************************************************************************
  74:	cd b7       	in	r28, 0x3d	; 61 --> Store r28 in SPL
  76:	de b7       	in	r29, 0x3e	; 62 --> Store r28 in SPH
    ; **************************************************************************
    volatile unsigned char x = 128;
  78:	80 e8       	ldi	r24, 0x80	; 128
  7a:	89 83       	std	Y+1, r24	; 0x01
    volatile unsigned char y = 211;
  7c:	83 ed       	ldi	r24, 0xD3	; 211
  7e:	8a 83       	std	Y+2, r24	; 0x02
    volatile unsigned char z = y - x;
  80:	9a 81       	ldd	r25, Y+2	; 0x02
  82:	89 81       	ldd	r24, Y+1	; 0x01
  84:	29 2f       	mov	r18, r25
  86:	28 1b       	sub	r18, r24
  88:	82 2f       	mov	r24, r18
  8a:	8b 83       	std	Y+3, r24	; 0x03
    DDRB = z;
  8c:	87 e3       	ldi	r24, 0x37	; 55
  8e:	90 e0       	ldi	r25, 0x00	; 0
  90:	2b 81       	ldd	r18, Y+3	; 0x03
  92:	fc 01       	movw	r30, r24
  94:	20 83       	st	Z, r18
    return 0;
  96:	80 e0       	ldi	r24, 0x00	; 0
  98:	90 e0       	ldi	r25, 0x00	; 0
}
  9a:	0f 90       	pop	r0
  9c:	0f 90       	pop	r0
  9e:	0f 90       	pop	r0
  a0:	df 91       	pop	r29
  a2:	cf 91       	pop	r28
  a4:	08 95       	ret

Disassembly of section .text.__dummy_fini:

000000c4 <_fini>:
  c4:	08 95       	ret

Disassembly of section .text.__dummy_funcs_on_exit:

000000c6 <__funcs_on_exit>:
  c6:	08 95       	ret

Disassembly of section .text.__dummy_simulator_exit:

000000c8 <__simulator_exit>:
  c8:	08 95       	ret

Disassembly of section .text.exit:

000000a6 <exit>:
  a6:	ec 01       	movw	r28, r24
  a8:	0e 94 63 00 	call	0xc6	; 0xc6 <__funcs_on_exit>
  ac:	0e 94 62 00 	call	0xc4	; 0xc4 <_fini>
  b0:	ce 01       	movw	r24, r28
  b2:	0e 94 64 00 	call	0xc8	; 0xc8 <__simulator_exit>
  b6:	ce 01       	movw	r24, r28
  b8:	0e 94 60 00 	call	0xc0	; 0xc0 <_Exit>

Disassembly of section .text._Exit:

000000c0 <_Exit>:
  c0:	0e 94 34 00 	call	0x68	; 0x68 <_exit>
