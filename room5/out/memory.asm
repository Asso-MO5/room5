;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.2.0 #13081 (MINGW64)
;--------------------------------------------------------
	.module memory
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _g_StackAddress
	.globl _Mem_HeapAlloc
	.globl _Mem_HeapFree
	.globl _Mem_Copy
	.globl _Mem_Set
	.globl _Mem_Set_16b
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_g_StackAddress::
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
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/memory.c:22: void* Mem_HeapAlloc(u16 size)
;	---------------------------------
; Function Mem_HeapAlloc
; ---------------------------------
_Mem_HeapAlloc::
	ld	c, l
	ld	b, h
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/memory.c:24: u16 addr = g_HeapStartAddress;
	ld	de, (_g_HeapStartAddress)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/memory.c:25: g_HeapStartAddress += size;
	ld	hl, #_g_HeapStartAddress
	ld	a, (hl)
	add	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, b
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/memory.c:26: return (void*)addr;
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/memory.c:27: }
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/memory.c:31: void Mem_HeapFree(u16 size)
;	---------------------------------
; Function Mem_HeapFree
; ---------------------------------
_Mem_HeapFree::
	ex	de, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/memory.c:33: g_HeapStartAddress -= size;	
	ld	hl, #_g_HeapStartAddress
	ld	a, (hl)
	sub	a, e
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	sbc	a, d
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/memory.c:34: }
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/memory.c:38: void Mem_Copy(const void* src, void* dest, u16 size) __NAKED // Stack: 4 bytes
;	---------------------------------
; Function Mem_Copy
; ---------------------------------
_Mem_Copy::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/memory.c:57: __endasm;
	pop	iy
	pop	bc
	ldir
	 mem_copy_end:
	jp	(iy)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/memory.c:58: }
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/memory.c:109: void Mem_Set(u8 val, void* dest, u16 size) __NAKED // Stack: 4 bytes
;	---------------------------------
; Function Mem_Set
; ---------------------------------
_Mem_Set::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/memory.c:136: __endasm;
	push	de
	pop	hl
	ld	(hl), a
	inc	de
	pop	iy
	pop	bc
	dec	bc
	ldir
	 mem_fill_end:
	jp	(iy)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/memory.c:137: }
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/memory.c:141: void Mem_Set_16b(u16 val, void* dest, u16 size)
;	---------------------------------
; Function Mem_Set_16b
; ---------------------------------
_Mem_Set_16b::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/memory.c:175: __endasm;
	push	de
	ex	de, hl
	ld	(hl), d
	inc	hl
	ld	(hl), e
	inc	hl
	ex	de, hl
	pop	hl
	pop	iy
	pop	bc
	dec	bc
	dec	bc
	ldir
	 mem_fill16_end:
	jp	(iy)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/memory.c:176: }
	pop	hl
	pop	af
	jp	(hl)
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
