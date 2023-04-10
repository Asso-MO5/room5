;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.2.0 #13081 (MINGW64)
;--------------------------------------------------------
	.module print
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _CopyNo8HeightFontData
	.globl _Print_ValidatePattern
	.globl _Print_ValidateChar
	.globl _VDP_Poke_16K
	.globl _VDP_FillVRAM_16K
	.globl _VDP_WriteVRAM_16K
	.globl _VDP_RegWrite
	.globl _g_PrintInvalid
	.globl _g_PrintData
	.globl _g_SLTSL
	.globl _g_GRPACY
	.globl _g_GRPACX
	.globl _g_LOGOPR
	.globl _g_CMASK
	.globl _g_CLOC
	.globl _g_FNKSTR
	.globl _g_ATRBYT
	.globl _g_BDRCLR
	.globl _g_BAKCLR
	.globl _g_FORCLR
	.globl _g_CSRX
	.globl _g_CSRY
	.globl _g_CLIKSW
	.globl _g_MLTPAT
	.globl _g_MLTATR
	.globl _g_MLTCGP
	.globl _g_MLTCOL
	.globl _g_MLTNAM
	.globl _g_GRPPAT
	.globl _g_GRPATR
	.globl _g_GRPCGP
	.globl _g_GRPCOL
	.globl _g_GRPNAM
	.globl _g_T32PAT
	.globl _g_T32ATR
	.globl _g_T32CGP
	.globl _g_T32COL
	.globl _g_T32NAM
	.globl _g_TXTPAT
	.globl _g_TXTATR
	.globl _g_TXTCGP
	.globl _g_TXTCOL
	.globl _g_TXTNAM
	.globl _g_CLMLST
	.globl _g_CRTCNT
	.globl _g_LINLEN
	.globl _g_LINL32
	.globl _g_LINL40
	.globl _g_HexChar
	.globl _g_CHAR_16
	.globl _g_MSXMID
	.globl _g_MSXVER
	.globl _g_ROMVersion
	.globl _g_BASRVN
	.globl _g_VDP_DW
	.globl _g_VDP_DR
	.globl _g_CGTABL
	.globl _g_SVFFFD
	.globl _g_RG27SAV
	.globl _g_RG26SAV
	.globl _g_RG25SAV
	.globl _g_SVFFF8
	.globl _g_MINROM
	.globl _g_RG23SAV
	.globl _g_RG22SAV
	.globl _g_RG21SAV
	.globl _g_RG20SAV
	.globl _g_RG19SAV
	.globl _g_RG18SAV
	.globl _g_RG17SAV
	.globl _g_RG16SAV
	.globl _g_RG15SAV
	.globl _g_RG14SAV
	.globl _g_RG13SAV
	.globl _g_RG12SAV
	.globl _g_RG11SAV
	.globl _g_RG10SAV
	.globl _g_RG09SAV
	.globl _g_RG08SAV
	.globl _g_PROCNM
	.globl _g_SLTWRK
	.globl _g_SLTATR
	.globl _g_SLTTBL
	.globl _g_EXPTBL
	.globl _g_MNROM
	.globl _g_DRWANG
	.globl _g_DRWSCL
	.globl _g_DRWFLG
	.globl _g_GYPOS
	.globl _g_GXPOS
	.globl _g_BRDATR
	.globl _g_CASPRV
	.globl _g_OLDSCR
	.globl _g_SCRMOD
	.globl _g_FLBMEM
	.globl _g_KANAMD
	.globl _g_KANAST
	.globl _g_CAPST
	.globl _g_CSTYLE
	.globl _g_CSRSW
	.globl _g_INSFLG
	.globl _g_ESCCNT
	.globl _g_GRPHED
	.globl _g_WINWID
	.globl _g_LOWLIM
	.globl _g_INTCNT
	.globl _g_INTVAL
	.globl _g_JIFFY
	.globl _g_PADX
	.globl _g_PADY
	.globl _g_INTFLG
	.globl _g_RTYCNT
	.globl _g_TRPTBL
	.globl _g_HIMEM
	.globl _g_BOTTOM
	.globl _g_PATWRK
	.globl _g_LINWRK
	.globl _g_KEYBUF
	.globl _g_NEWKEY
	.globl _g_OLDKEY
	.globl _g_CLIKFL
	.globl _g_ONGSBF
	.globl _g_FNKFLG
	.globl _g_FNKSWI
	.globl _g_CODSAV
	.globl _g_FSTPOS
	.globl _g_LINTTB
	.globl _g_BASROM
	.globl _g_ENSTOP
	.globl _g_VCBC
	.globl _g_VCBB
	.globl _g_VCBA
	.globl _g_PLYCNT
	.globl _g_MUSICF
	.globl _g_QUEUEN
	.globl _g_MCLPTR
	.globl _g_MCLLEN
	.globl _g_SAVVOL
	.globl _g_VOICEN
	.globl _g_SAVSP
	.globl _g_PRSCNT
	.globl _g_LSTMOD
	.globl _g_LSTCOM
	.globl _g_COMMSK
	.globl _g_ESTBLS
	.globl _g_FLAGS
	.globl _g_ERRORS
	.globl _g_DATCNT
	.globl _g_DEVNUM
	.globl _g_OLDINT
	.globl _g_OLDSTT
	.globl _g_MEXBIh
	.globl _g_RSIQLN
	.globl _g_RSFCB
	.globl _g_TOCNT
	.globl _g_RSTMP
	.globl _g_YSAVE
	.globl _g_XSAVE
	.globl _g_NORUSE
	.globl _g_MODE
	.globl _g_ROMA
	.globl _g_CHRCNT
	.globl _g_EXBRSA
	.globl _g_AVCSAV
	.globl _g_ACPAGE
	.globl _g_DPPAGE
	.globl _g_RS2IQ
	.globl _g_VOICCQ
	.globl _g_VOICBQ
	.globl _g_VOICAQ
	.globl _g_QUEBAK
	.globl _g_QUETAB
	.globl _g_ASPCT2
	.globl _g_ASPCT1
	.globl _g_HEADER
	.globl _g_HIGH
	.globl _g_LOW
	.globl _g_CS240
	.globl _g_CS120
	.globl _g_GETPNT
	.globl _g_PUTPNT
	.globl _g_REPCNT
	.globl _g_SCNCNT
	.globl _g_FRCNEW
	.globl _g_QUEUES
	.globl _g_MINUPD
	.globl _g_MAXUPD
	.globl _g_TRGFLG
	.globl _g_STATFL
	.globl _g_RG7SAV
	.globl _g_RG6SAV
	.globl _g_RG5SAV
	.globl _g_RG4SAV
	.globl _g_RG3SAV
	.globl _g_RG2SAV
	.globl _g_RG1SAV
	.globl _g_RG0SAV
	.globl _g_CNSDFG
	.globl _g_USRTAB
	.globl _g_CLPRIM
	.globl _g_WRPRIM
	.globl _g_RDPRIM
	.globl _Print_Initialize
	.globl _Print_SetMode
	.globl _Print_SetFont
	.globl _Print_SetColor
	.globl _Print_SetColorShade
	.globl _Print_SetTextFont
	.globl _DrawChar_Layout
	.globl _Print_Clear
	.globl _Print_Backspace
	.globl _Print_DrawChar
	.globl _Print_DrawCharX
	.globl _Print_DrawText
	.globl _Print_DrawBin8
	.globl _Print_DrawHex8
	.globl _Print_DrawHex16
	.globl _Print_DrawHex32
	.globl _Print_DrawInt
	.globl _Print_DrawFormat
	.globl _Print_DrawLineH
	.globl _Print_DrawLineV
	.globl _Print_DrawBox
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_g_LINL40	=	0xf3ae
_g_LINL32	=	0xf3af
_g_LINLEN	=	0xf3b0
_g_CRTCNT	=	0xf3b1
_g_CLMLST	=	0xf3b2
_g_TXTNAM	=	0xf3b3
_g_TXTCOL	=	0xf3b5
_g_TXTCGP	=	0xf3b7
_g_TXTATR	=	0xf3b9
_g_TXTPAT	=	0xf3bb
_g_T32NAM	=	0xf3bd
_g_T32COL	=	0xf3bf
_g_T32CGP	=	0xf3c1
_g_T32ATR	=	0xf3c3
_g_T32PAT	=	0xf3c5
_g_GRPNAM	=	0xf3c7
_g_GRPCOL	=	0xf3c9
_g_GRPCGP	=	0xf3cb
_g_GRPATR	=	0xf3cd
_g_GRPPAT	=	0xf3cf
_g_MLTNAM	=	0xf3d1
_g_MLTCOL	=	0xf3d3
_g_MLTCGP	=	0xf3d5
_g_MLTATR	=	0xf3d7
_g_MLTPAT	=	0xf3d9
_g_CLIKSW	=	0xf3db
_g_CSRY	=	0xf3dc
_g_CSRX	=	0xf3dd
_g_FORCLR	=	0xf3e9
_g_BAKCLR	=	0xf3ea
_g_BDRCLR	=	0xf3eb
_g_ATRBYT	=	0xf3f2
_g_FNKSTR	=	0xf87f
_g_CLOC	=	0xf92a
_g_CMASK	=	0xf92c
_g_LOGOPR	=	0xfb02
_g_GRPACX	=	0xfcb7
_g_GRPACY	=	0xfcb9
_g_SLTSL	=	0xffff
_g_PrintData::
	.ds 49
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_g_PrintInvalid::
	.ds 8
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
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:157: bool Print_Initialize()
;	---------------------------------
; Function Print_Initialize
; ---------------------------------
_Print_Initialize::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:159: Print_SetColor(0xF, 0x0);
	ld	l, #0x00
;	spillPairReg hl
;	spillPairReg hl
	ld	a, #0x0f
	call	_Print_SetColor
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:203: g_PrintData.CursorX = x;
	ld	hl, #(_g_PrintData + 5)
	ld	(hl), #0x00
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:204: g_PrintData.CursorY = y;
	ld	hl, #(_g_PrintData + 6)
	ld	(hl), #0x00
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.h:402: inline u8 VDP_GetMode() { return g_VDP_Data.Mode; }
	ld	hl, #_g_VDP_Data+0
	ld	c, (hl)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:226: g_PrintData.TabSize = size;
	ld	hl, #_g_PrintData + 4
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:173: g_PrintData.ScreenWidth = 40;
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:168: switch(VDP_GetMode()) // Screen mode specific initialization
	ld	a, c
	or	a, a
	jr	Z, 00101$
	ld	a, c
	dec	a
	jr	Z, 00106$
	ld	a, c
	sub	a, #0x02
	jr	Z, 00103$
	ld	a, c
	sub	a, #0x03
	jr	Z, 00104$
	jr	00105$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:171: case VDP_MODE_TEXT1:		// 40 characters per line of text, one colour for each character
00101$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:226: g_PrintData.TabSize = size;
	ld	(hl), #0x03
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:173: g_PrintData.ScreenWidth = 40;
	ld	hl, #0x0028
	ld	((_g_PrintData + 26)), hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:174: break;
	jr	00106$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:181: case VDP_MODE_GRAPHIC1:		// 32 characters per one line of text, the COLOURed character available
00103$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:226: g_PrintData.TabSize = size;
	ld	(hl), #0x03
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:183: g_PrintData.ScreenWidth = 32;
	ld	hl, #0x0020
	ld	((_g_PrintData + 26)), hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:184: break;
	jr	00106$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:187: case VDP_MODE_GRAPHIC2:		// 256 x 192, the colour is specififed for each 8 dots
00104$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:226: g_PrintData.TabSize = size;
	ld	(hl), #0x03
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:189: g_PrintData.ScreenWidth = 32;
	ld	hl, #0x0020
	ld	((_g_PrintData + 26)), hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:190: break;
	jr	00106$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:230: default:
00105$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:232: return FALSE;
	xor	a, a
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:233: }
00106$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:237: return TRUE;
	ld	a, #0x01
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:238: }
	ret
_g_RDPRIM	=	0xf380
_g_WRPRIM	=	0xf385
_g_CLPRIM	=	0xf38c
_g_USRTAB	=	0xf39a
_g_CNSDFG	=	0xf3de
_g_RG0SAV	=	0xf3df
_g_RG1SAV	=	0xf3e0
_g_RG2SAV	=	0xf3e1
_g_RG3SAV	=	0xf3e2
_g_RG4SAV	=	0xf3e3
_g_RG5SAV	=	0xf3e4
_g_RG6SAV	=	0xf3e5
_g_RG7SAV	=	0xf3e6
_g_STATFL	=	0xf3e7
_g_TRGFLG	=	0xf3e8
_g_MAXUPD	=	0xf3ec
_g_MINUPD	=	0xf3ef
_g_QUEUES	=	0xf3f3
_g_FRCNEW	=	0xf3f5
_g_SCNCNT	=	0xf3f6
_g_REPCNT	=	0xf3f7
_g_PUTPNT	=	0xf3f8
_g_GETPNT	=	0xf3fa
_g_CS120	=	0xf3fc
_g_CS240	=	0xf401
_g_LOW	=	0xf406
_g_HIGH	=	0xf408
_g_HEADER	=	0xf40a
_g_ASPCT1	=	0xf40b
_g_ASPCT2	=	0xf40d
_g_QUETAB	=	0xf959
_g_QUEBAK	=	0xf971
_g_VOICAQ	=	0xf975
_g_VOICBQ	=	0xf9f5
_g_VOICCQ	=	0xfa75
_g_RS2IQ	=	0xfaf5
_g_DPPAGE	=	0xfaf5
_g_ACPAGE	=	0xfaf6
_g_AVCSAV	=	0xfaf7
_g_EXBRSA	=	0xfaf8
_g_CHRCNT	=	0xfaf9
_g_ROMA	=	0xfafa
_g_MODE	=	0xfafc
_g_NORUSE	=	0xfafd
_g_XSAVE	=	0xfafe
_g_YSAVE	=	0xfb00
_g_RSTMP	=	0xfb03
_g_TOCNT	=	0xfb03
_g_RSFCB	=	0xfb04
_g_RSIQLN	=	0xfb06
_g_MEXBIh	=	0xfb07
_g_OLDSTT	=	0xfb0c
_g_OLDINT	=	0xfb0c
_g_DEVNUM	=	0xfb16
_g_DATCNT	=	0xfb17
_g_ERRORS	=	0xfb1a
_g_FLAGS	=	0xfb1b
_g_ESTBLS	=	0xfb1c
_g_COMMSK	=	0xfb1d
_g_LSTCOM	=	0xfb1e
_g_LSTMOD	=	0xfb1f
_g_PRSCNT	=	0xfb35
_g_SAVSP	=	0xfb36
_g_VOICEN	=	0xfb38
_g_SAVVOL	=	0xfb39
_g_MCLLEN	=	0xfb3b
_g_MCLPTR	=	0xfb3c
_g_QUEUEN	=	0xfb3e
_g_MUSICF	=	0xfb3f
_g_PLYCNT	=	0xfb40
_g_VCBA	=	0xfb41
_g_VCBB	=	0xfb66
_g_VCBC	=	0xfb8b
_g_ENSTOP	=	0xfbb0
_g_BASROM	=	0xfbb1
_g_LINTTB	=	0xfbb2
_g_FSTPOS	=	0xfbca
_g_CODSAV	=	0xfbcc
_g_FNKSWI	=	0xfbcd
_g_FNKFLG	=	0xfbce
_g_ONGSBF	=	0xfbd8
_g_CLIKFL	=	0xfbd9
_g_OLDKEY	=	0xfbda
_g_NEWKEY	=	0xfbe5
_g_KEYBUF	=	0xfbf0
_g_LINWRK	=	0xfc18
_g_PATWRK	=	0xfc40
_g_BOTTOM	=	0xfc48
_g_HIMEM	=	0xfc4a
_g_TRPTBL	=	0xfc4c
_g_RTYCNT	=	0xfc9a
_g_INTFLG	=	0xfc9b
_g_PADY	=	0xfc9c
_g_PADX	=	0xfc9d
_g_JIFFY	=	0xfc9e
_g_INTVAL	=	0xfca0
_g_INTCNT	=	0xfca2
_g_LOWLIM	=	0xfca4
_g_WINWID	=	0xfca5
_g_GRPHED	=	0xfca6
_g_ESCCNT	=	0xfca7
_g_INSFLG	=	0xfca8
_g_CSRSW	=	0xfca9
_g_CSTYLE	=	0xfcaa
_g_CAPST	=	0xfcab
_g_KANAST	=	0xfcac
_g_KANAMD	=	0xfcad
_g_FLBMEM	=	0xfcae
_g_SCRMOD	=	0xfcaf
_g_OLDSCR	=	0xfcb0
_g_CASPRV	=	0xfcb1
_g_BRDATR	=	0xfcb2
_g_GXPOS	=	0xfcb3
_g_GYPOS	=	0xfcb5
_g_DRWFLG	=	0xfcbb
_g_DRWSCL	=	0xfcbc
_g_DRWANG	=	0xfcbd
_g_MNROM	=	0xfcc1
_g_EXPTBL	=	0xfcc1
_g_SLTTBL	=	0xfcc5
_g_SLTATR	=	0xfcc9
_g_SLTWRK	=	0xfd09
_g_PROCNM	=	0xfd89
_g_RG08SAV	=	0xffe7
_g_RG09SAV	=	0xffe8
_g_RG10SAV	=	0xffe9
_g_RG11SAV	=	0xffea
_g_RG12SAV	=	0xffeb
_g_RG13SAV	=	0xffec
_g_RG14SAV	=	0xffed
_g_RG15SAV	=	0xffee
_g_RG16SAV	=	0xffef
_g_RG17SAV	=	0xfff0
_g_RG18SAV	=	0xfff1
_g_RG19SAV	=	0xfff2
_g_RG20SAV	=	0xfff3
_g_RG21SAV	=	0xfff4
_g_RG22SAV	=	0xfff5
_g_RG23SAV	=	0xfff6
_g_MINROM	=	0xfff7
_g_SVFFF8	=	0xfff8
_g_RG25SAV	=	0xfffa
_g_RG26SAV	=	0xfffb
_g_RG27SAV	=	0xfffc
_g_SVFFFD	=	0xfffd
_g_CGTABL	=	0x0004
_g_VDP_DR	=	0x0006
_g_VDP_DW	=	0x0007
_g_BASRVN	=	0x002b
_g_ROMVersion	=	0x002b
_g_MSXVER	=	0x002d
_g_MSXMID	=	0x002e
_g_CHAR_16	=	0x0034
_g_HexChar:
	.db #0x30	; 48	'0'
	.db #0x31	; 49	'1'
	.db #0x32	; 50	'2'
	.db #0x33	; 51	'3'
	.db #0x34	; 52	'4'
	.db #0x35	; 53	'5'
	.db #0x36	; 54	'6'
	.db #0x37	; 55	'7'
	.db #0x38	; 56	'8'
	.db #0x39	; 57	'9'
	.db #0x41	; 65	'A'
	.db #0x42	; 66	'B'
	.db #0x43	; 67	'C'
	.db #0x44	; 68	'D'
	.db #0x45	; 69	'E'
	.db #0x46	; 70	'F'
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:242: void Print_SetMode(u8 mode)
;	---------------------------------
; Function Print_SetMode
; ---------------------------------
_Print_SetMode::
	ld	c, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:244: g_PrintData.SourceMode = mode;
	ld	hl, #_g_PrintData + 25
	rrd
	ld	a, c
	rld
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:246: switch(g_PrintData.SourceMode)
	ld	a, (hl)
	and	a, #0x0f
	sub	a, #0x04
	ret	NZ
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:311: g_PrintData.DrawChar = DrawChar_Layout;
	ld	hl, #_DrawChar_Layout
	ld	((_g_PrintData + 23)), hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:315: };
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:316: }
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:321: void Print_SetFont(const u8* font)
;	---------------------------------
; Function Print_SetFont
; ---------------------------------
_Print_SetFont::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	push	af
	ex	de, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:323: if(font == NULL) // Use Bios font (if any)
	ld	a, d
	or	a, e
	jr	NZ, 00102$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:324: Print_SetFontEx(8, 8, 6, 8, 1, 255, (const u8*)g_CGTABL + 8);
	ld	bc, (_g_CGTABL)
	ld	hl, #0x0008
	add	hl, bc
	ex	de, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:174: g_PrintData.PatternX     = patternX;
	ld	hl, #_g_PrintData
	ld	(hl), #0x08
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:175: g_PrintData.PatternY     = patternY;
	ld	bc, #_g_PrintData + 1
	ld	a, #0x08
	ld	(bc), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:176: g_PrintData.UnitX        = sizeX;
	ld	hl, #(_g_PrintData + 2)
	ld	(hl), #0x06
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:177: g_PrintData.UnitY        = sizeY;
	ld	hl, #(_g_PrintData + 3)
	ld	(hl), #0x08
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:178: g_PrintData.CharFirst    = firstChr;
	ld	hl, #(_g_PrintData + 20)
	ld	(hl), #0x01
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:179: g_PrintData.CharLast     = lastChr;
	ld	hl, #(_g_PrintData + 21)
	ld	(hl), #0xff
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:180: g_PrintData.CharCount    = lastChr - firstChr + 1;
	ld	hl, #(_g_PrintData + 22)
	ld	(hl), #0xff
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:181: g_PrintData.FontPatterns = patterns;
	ld	((_g_PrintData + 28)), de
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:182: g_PrintData.FontAddr     = g_PrintData.FontPatterns - (firstChr * g_PrintData.PatternY); // pre-compute address of the virtual index 0 character (used to quick drawing in PutChar_GX functions)
	ld	a, (bc)
	ld	c, a
	ld	b, #0x00
	ld	a, e
	sub	a, c
	ld	c, a
	ld	a, d
	sbc	a, b
	ld	b, a
	ld	((_g_PrintData + 30)), bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:324: Print_SetFontEx(8, 8, 6, 8, 1, 255, (const u8*)g_CGTABL + 8);
	jp	00106$
00102$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:326: Print_SetFontEx(font[0] >> 4, font[0] & 0x0F, font[1] >> 4, font[1] & 0x0F, font[2], font[3], font+4);
	ld	hl, #0x0004
	add	hl, de
	ld	c, l
	ld	b, h
	ld	l, e
;	spillPairReg hl
;	spillPairReg hl
	ld	h, d
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	inc	hl
	inc	hl
	ld	a, (hl)
	ld	-4 (ix), a
	ld	l, e
;	spillPairReg hl
;	spillPairReg hl
	ld	h, d
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	inc	hl
	ld	a, (hl)
	ld	-3 (ix), a
	ld	l, e
;	spillPairReg hl
;	spillPairReg hl
	ld	h, d
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	ld	a, (hl)
	push	af
	and	a, #0x0f
	ld	-2 (ix), a
	pop	af
	rlca
	rlca
	rlca
	rlca
	and	a, #0x0f
	ld	-1 (ix), a
	ld	a, (de)
	push	af
	and	a, #0x0f
	ld	e, a
	pop	af
	rlca
	rlca
	rlca
	rlca
	and	a, #0x0f
	ld	d, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:174: g_PrintData.PatternX     = patternX;
	ld	hl, #_g_PrintData
	ld	(hl), d
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:175: g_PrintData.PatternY     = patternY;
	ld	hl, #(_g_PrintData + 1)
	ld	(hl), e
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:176: g_PrintData.UnitX        = sizeX;
	ld	hl, #(_g_PrintData + 2)
	ld	a, -1 (ix)
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:177: g_PrintData.UnitY        = sizeY;
	ld	hl, #(_g_PrintData + 3)
	ld	a, -2 (ix)
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:178: g_PrintData.CharFirst    = firstChr;
	ld	hl, #(_g_PrintData + 20)
	ld	a, -3 (ix)
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:179: g_PrintData.CharLast     = lastChr;
	ld	hl, #(_g_PrintData + 21)
	ld	a, -4 (ix)
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:180: g_PrintData.CharCount    = lastChr - firstChr + 1;
	ld	a, -4 (ix)
	sub	a, -3 (ix)
	inc	a
	ld	(#(_g_PrintData + 22)),a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:181: g_PrintData.FontPatterns = patterns;
	ld	((_g_PrintData + 28)), bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:182: g_PrintData.FontAddr     = g_PrintData.FontPatterns - (firstChr * g_PrintData.PatternY); // pre-compute address of the virtual index 0 character (used to quick drawing in PutChar_GX functions)
	push	bc
	ld	h, -3 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	l, #0x00
	ld	d, l
	ld	b, #0x08
00113$:
	add	hl, hl
	jr	NC, 00114$
	add	hl, de
00114$:
	djnz	00113$
	pop	bc
	ld	a, c
	sub	a, l
	ld	c, a
	ld	a, b
	sbc	a, h
	ld	b, a
	ld	((_g_PrintData + 30)), bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:326: Print_SetFontEx(font[0] >> 4, font[0] & 0x0F, font[1] >> 4, font[1] & 0x0F, font[2], font[3], font+4);
00106$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:327: }
	ld	sp, ix
	pop	ix
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:390: void Print_SetColor(u8 text, u8 bg)
;	---------------------------------
; Function Print_SetColor
; ---------------------------------
_Print_SetColor::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:420: u8 col = text << 4 | bg;
	add	a, a
	add	a, a
	add	a, a
	add	a, a
	or	a, l
	ld	c, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.h:402: inline u8 VDP_GetMode() { return g_VDP_Data.Mode; }
	ld	a, (#_g_VDP_Data + 0)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:421: switch(VDP_GetMode())
	or	a, a
	jr	Z, 00101$
	cp	a, #0x02
	jr	Z, 00102$
	sub	a, #0x03
	jr	Z, 00103$
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:424: case VDP_MODE_TEXT1:		// 40 characters per line of text, one colour for each character
00101$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.h:643: inline void VDP_SetColor(u8 color) { VDP_RegWrite(7, color); }
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:431: break;
	ld	a, #0x07
	jp	_VDP_RegWrite
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:434: case VDP_MODE_GRAPHIC1:		// 32 characters per one line of text, the COLOURed character available
00102$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:435: VDP_FillVRAM(col, g_ScreenColorLow, 0, 32);
	ld	hl, #0x0020
	push	hl
	ld	de, (_g_ScreenColorLow)
	ld	a, c
	call	_VDP_FillVRAM_16K
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:436: break;
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:439: case VDP_MODE_GRAPHIC2:		// 256 x 192, the colour is specififed for each 8 dots
00103$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:446: u16 dst = (u16)g_ScreenColorLow + g_PrintData.PatternOffset * 8;
	ld	a, (#_g_PrintData + 32)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	de, (_g_ScreenColorLow)
	add	hl, de
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:447: VDP_FillVRAM(col, dst, 0, g_PrintData.CharCount * 8);
	ld	iy, #_g_PrintData + 22
	ld	e, 0 (iy)
	ld	d, #0x00
	ex	de, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ex	de, hl
	push	hl
	push	bc
	push	iy
	ex	de, hl
	push	hl
	ld	a, c
	call	_VDP_FillVRAM_16K
	pop	iy
	pop	bc
	pop	hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:448: dst += 256 * 8;
	ld	de, #0x0800
	add	hl, de
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:449: VDP_FillVRAM(col, dst, 0, g_PrintData.CharCount * 8);
	ld	e, 0 (iy)
	ld	d, #0x00
	ex	de, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ex	de, hl
	push	hl
	push	bc
	push	iy
	ex	de, hl
	push	hl
	ld	a, c
	call	_VDP_FillVRAM_16K
	pop	iy
	pop	bc
	pop	hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:450: dst += 256 * 8;
	ld	e, l
	ld	a, h
	add	a, #0x08
	ld	d, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:451: VDP_FillVRAM(col, dst, 0, g_PrintData.CharCount * 8);
	ld	l, 0 (iy)
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	push	hl
	ld	a, c
	call	_VDP_FillVRAM_16K
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:455: };
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:458: }
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:463: void Print_SetColorShade(const u8* shade)
;	---------------------------------
; Function Print_SetColorShade
; ---------------------------------
_Print_SetColorShade::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
	ld	c, l
	ld	b, h
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.h:402: inline u8 VDP_GetMode() { return g_VDP_Data.Mode; }
	ld	a, (#_g_VDP_Data + 0)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:481: switch(VDP_GetMode())
	sub	a, #0x03
	jr	NZ, 00113$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:491: u16 dst = (u16)g_ScreenColorLow + g_PrintData.PatternOffset * 8;
	ld	a, (#_g_PrintData + 32)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	de, (_g_ScreenColorLow)
	add	hl, de
	ex	de, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:492: for(u8 i = 0; i < g_PrintData.CharCount; ++i)
	ld	-1 (ix), #0x00
00111$:
	ld	hl, #_g_PrintData + 22
;	spillPairReg hl
	ld	a,-1 (ix)
	sub	a,(hl)
	jr	NC, 00113$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:494: VDP_WriteVRAM(shade, dst,           0, 8);
	push	bc
	push	de
	ld	hl, #0x0008
	push	hl
	push	de
	push	bc
	call	_VDP_WriteVRAM_16K
	pop	af
	pop	af
	pop	af
	pop	de
	pop	bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:495: VDP_WriteVRAM(shade, dst + 256 * 8, 0, 8);
	ld	hl, #0x0800
	add	hl, de
	push	bc
	push	de
	ld	de, #0x0008
	push	de
	push	hl
	push	bc
	call	_VDP_WriteVRAM_16K
	pop	af
	pop	af
	pop	af
	pop	de
	pop	bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:496: VDP_WriteVRAM(shade, dst + 512 * 8, 0, 8);
	ld	hl, #0x1000
	add	hl, de
	push	bc
	push	de
	ld	de, #0x0008
	push	de
	push	hl
	push	bc
	call	_VDP_WriteVRAM_16K
	pop	af
	pop	af
	pop	af
	pop	de
	pop	bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:497: dst += 8;
	ld	hl, #0x0008
	add	hl, de
	ex	de, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:492: for(u8 i = 0; i < g_PrintData.CharCount; ++i)
	inc	-1 (ix)
	jr	00111$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:502: };
00113$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:505: }
	inc	sp
	pop	ix
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:519: u8 Print_ValidateChar(u8 chr)
;	---------------------------------
; Function Print_ValidateChar
; ---------------------------------
_Print_ValidateChar::
	ld	c, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:521: if((chr < g_PrintData.CharFirst) || (chr > g_PrintData.CharLast))
	ld	hl, #_g_PrintData + 20
	ld	e, (hl)
	ld	hl, #_g_PrintData + 21
	ld	a, c
	sub	a, e
	jr	C, 00113$
	ld	a, (hl)
	sub	a, c
	jr	NC, 00114$
00113$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:525: chr = chr - 'a' + 'A';
	ld	b, c
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:523: if((chr >= 'a') && (chr <= 'z') && (g_PrintData.CharFirst <= 'A') && (g_PrintData.CharLast >= 'Z')) // try to remap to upper case letter
	ld	a, c
	sub	a, #0x61
	jr	C, 00108$
	ld	a, #0x7a
	sub	a, c
	jr	C, 00108$
	ld	a, #0x41
	sub	a, e
	jr	C, 00108$
	ld	a, (hl)
	sub	a, #0x5a
	jr	C, 00108$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:525: chr = chr - 'a' + 'A';
	ld	a, b
	add	a, #0xe0
	ld	c, a
	jr	00114$
00108$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:527: else if((chr >= 'A') && (chr <= 'Z') && (g_PrintData.CharFirst <= 'a') && (g_PrintData.CharLast >= 'z')) // try to remap to lower case letter
	ld	a, c
	sub	a, #0x41
	jr	C, 00102$
	ld	a, #0x5a
	sub	a, c
	jr	C, 00102$
	ld	a, #0x61
	sub	a, e
	jr	C, 00102$
	ld	a, (hl)
	sub	a, #0x7a
	jr	C, 00102$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:529: chr = chr - 'A' + 'a';
	ld	a, b
	add	a, #0x20
	ld	c, a
	jr	00114$
00102$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:532: chr = g_PrintData.CharFirst;
	ld	c, e
00114$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:534: return chr;
	ld	a, c
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:535: }
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:540: u8 Print_ValidatePattern(u8 chr, const c8** patterns)
;	---------------------------------
; Function Print_ValidatePattern
; ---------------------------------
_Print_ValidatePattern::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-6
	add	hl, sp
	ld	sp, hl
	ld	c, a
	ld	-2 (ix), e
	ld	-1 (ix), d
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:542: if((chr < g_PrintData.CharFirst) || (chr > g_PrintData.CharLast))
	ld	hl, #_g_PrintData + 20
	ld	e, (hl)
	ld	iy, #_g_PrintData + 21
	ld	a, c
	sub	a, e
	jr	C, 00113$
	ld	b, 0 (iy)
	ld	a, b
	sub	a, c
	jp	NC, 00114$
00113$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:546: chr = chr - 'a' + 'A';
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:547: *patterns = g_PrintData.FontPatterns + g_PrintData.PatternY * (chr - g_PrintData.CharFirst);
	ld	-6 (ix), e
	ld	-5 (ix), #0x00
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:544: if((chr >= 'a') && (chr <= 'z') && (g_PrintData.CharFirst <= 'A') && (g_PrintData.CharLast >= 'Z')) // try to remap to upper case letter
	ld	a, c
	sub	a, #0x61
	jr	C, 00108$
	ld	a, #0x7a
	sub	a, c
	jr	C, 00108$
	ld	a, #0x41
	sub	a, e
	jr	C, 00108$
	ld	a, 0 (iy)
	sub	a, #0x5a
	jr	C, 00108$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:546: chr = chr - 'a' + 'A';
	ld	a, l
	add	a, #0xe0
	ld	c, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:547: *patterns = g_PrintData.FontPatterns + g_PrintData.PatternY * (chr - g_PrintData.CharFirst);
	ld	hl, #(_g_PrintData + 28)
	ld	a, (hl)
	ld	-4 (ix), a
	inc	hl
	ld	a, (hl)
	ld	-3 (ix), a
	ld	hl, #(_g_PrintData + 1)
	ld	l, (hl)
;	spillPairReg hl
	ld	e, c
	ld	d, #0x00
	ld	a, e
	sub	a, -6 (ix)
	ld	e, a
	ld	a, d
	sbc	a, -5 (ix)
	ld	d, a
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	push	bc
	call	__mulint
	pop	bc
	ld	a, e
	add	a, -4 (ix)
	ld	b, a
	ld	a, d
	adc	a, -3 (ix)
	ld	e, a
	ld	l, -2 (ix)
	ld	h, -1 (ix)
	ld	(hl), b
	inc	hl
	ld	(hl), e
	jr	00114$
00108$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:549: else if((chr >= 'A') && (chr <= 'Z') && (g_PrintData.CharFirst <= 'a') && (g_PrintData.CharLast >= 'z')) // try to remap to lower case letter
	ld	a, c
	sub	a, #0x41
	jr	C, 00102$
	ld	a, #0x5a
	sub	a, c
	jr	C, 00102$
	ld	a, #0x61
	sub	a, e
	jr	C, 00102$
	ld	a, 0 (iy)
	sub	a, #0x7a
	jr	C, 00102$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:551: chr = chr - 'A' + 'a';
	ld	a, l
	add	a, #0x20
	ld	c, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:552: *patterns = g_PrintData.FontPatterns + g_PrintData.PatternY * (chr - g_PrintData.CharFirst);
	ld	hl, #(_g_PrintData + 28)
	ld	a, (hl)
	ld	-4 (ix), a
	inc	hl
	ld	a, (hl)
	ld	-3 (ix), a
	ld	hl, #(_g_PrintData + 1)
	ld	l, (hl)
;	spillPairReg hl
	ld	e, c
	ld	d, #0x00
	ld	a, e
	sub	a, -6 (ix)
	ld	e, a
	ld	a, d
	sbc	a, -5 (ix)
	ld	d, a
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	push	bc
	call	__mulint
	pop	bc
	ld	a, e
	add	a, -4 (ix)
	ld	b, a
	ld	a, d
	adc	a, -3 (ix)
	ld	e, a
	ld	l, -2 (ix)
	ld	h, -1 (ix)
	ld	(hl), b
	inc	hl
	ld	(hl), e
	jr	00114$
00102$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:555: *patterns = g_PrintInvalid;
	ld	l, -2 (ix)
	ld	h, -1 (ix)
	ld	(hl), #<(_g_PrintInvalid)
	inc	hl
	ld	(hl), #>(_g_PrintInvalid)
00114$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:557: return chr;
	ld	a, c
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:558: }
	ld	sp, ix
	pop	ix
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:859: void CopyNo8HeightFontData(const u8* src, u16 dst, u8 height)
;	---------------------------------
; Function CopyNo8HeightFontData
; ---------------------------------
_CopyNo8HeightFontData::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
	ld	c, l
	ld	b, h
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:861: for(u8 i = 0; i < g_PrintData.CharCount; ++i)
	ld	-1 (ix), #0x00
00103$:
	ld	hl, #(_g_PrintData + 22)
;	spillPairReg hl
	ld	a,-1 (ix)
	sub	a,(hl)
	jr	NC, 00105$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:863: VDP_FillVRAM(0, dst, 0, 8);
	push	bc
	push	de
	ld	hl, #0x0008
	push	hl
	xor	a, a
	call	_VDP_FillVRAM_16K
	pop	de
	pop	bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:864: VDP_WriteVRAM(src, dst, 0, height);
	ld	l, 4 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	push	bc
	push	de
	push	hl
	push	de
	push	bc
	call	_VDP_WriteVRAM_16K
	pop	af
	pop	af
	pop	af
	pop	de
	pop	bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:865: src += height;
	ld	a, c
	add	a, 4 (ix)
	ld	c, a
	jr	NC, 00118$
	inc	b
00118$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:866: dst += 8;
	ld	hl, #0x0008
	add	hl, de
	ex	de, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:861: for(u8 i = 0; i < g_PrintData.CharCount; ++i)
	inc	-1 (ix)
	jr	00103$
00105$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:868: }
	inc	sp
	pop	ix
	pop	hl
	inc	sp
	jp	(hl)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:873: void Print_SetTextFont(const u8* fontData, u8 offset)
;	---------------------------------
; Function Print_SetTextFont
; ---------------------------------
_Print_SetTextFont::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	iy, #-12
	add	iy, sp
	ld	sp, iy
	ld	-2 (ix), l
	ld	-1 (ix), h
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:875: g_PrintData.PatternOffset = offset;
	ld	hl, #(_g_PrintData + 32)
	ld	a, 4 (ix)
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:878: if(fontData == NULL) // Use Bios font (if any)
	ld	a, -1 (ix)
	or	a, -2 (ix)
	jp	NZ, 00102$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:879: Print_SetFontEx(8, 8, 1, 1, 1, 255, (const u8*)g_CGTABL + 8); // @todo Should be [1, 255] to include all characters
	ld	hl, (_g_CGTABL)
	ld	-4 (ix), l
	ld	-3 (ix), h
	ld	a, -4 (ix)
	add	a, #0x08
	ld	-8 (ix), a
	ld	a, -3 (ix)
	adc	a, #0x00
	ld	-7 (ix), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:174: g_PrintData.PatternX     = patternX;
	ld	hl, #_g_PrintData
	ld	(hl), #0x08
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:175: g_PrintData.PatternY     = patternY;
	ld	hl, #(_g_PrintData + 1)
	ld	(hl), #0x08
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:176: g_PrintData.UnitX        = sizeX;
	ld	hl, #(_g_PrintData + 2)
	ld	(hl), #0x01
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:177: g_PrintData.UnitY        = sizeY;
	ld	hl, #(_g_PrintData + 3)
	ld	(hl), #0x01
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:178: g_PrintData.CharFirst    = firstChr;
	ld	hl, #(_g_PrintData + 20)
	ld	(hl), #0x01
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:179: g_PrintData.CharLast     = lastChr;
	ld	hl, #(_g_PrintData + 21)
	ld	(hl), #0xff
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:180: g_PrintData.CharCount    = lastChr - firstChr + 1;
	ld	hl, #_g_PrintData + 22
	ex	(sp), hl
	pop	hl
	push	hl
	ld	(hl), #0xff
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:181: g_PrintData.FontPatterns = patterns;
	ld	hl, #_g_PrintData + 28
	ld	-10 (ix), l
	ld	-9 (ix), h
	pop	bc
	pop	hl
	push	hl
	push	bc
	ld	a, -8 (ix)
	ld	(hl), a
	inc	hl
	ld	a, -7 (ix)
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:182: g_PrintData.FontAddr     = g_PrintData.FontPatterns - (firstChr * g_PrintData.PatternY); // pre-compute address of the virtual index 0 character (used to quick drawing in PutChar_GX functions)
	ld	a, (#(_g_PrintData + 1) + 0)
	ld	-3 (ix), a
	ld	-6 (ix), a
	ld	-5 (ix), #0x00
	ld	a, -8 (ix)
	sub	a, -6 (ix)
	ld	-4 (ix), a
	ld	a, -7 (ix)
	sbc	a, -5 (ix)
	ld	-3 (ix), a
	ld	hl, #(_g_PrintData + 30)
	ld	a, -4 (ix)
	ld	(hl), a
	inc	hl
	ld	a, -3 (ix)
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:879: Print_SetFontEx(8, 8, 1, 1, 1, 255, (const u8*)g_CGTABL + 8); // @todo Should be [1, 255] to include all characters
	jp	00103$
00102$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:881: Print_SetFontEx(8, 8, 1, 1, fontData[2], fontData[3], fontData+4);
	ld	a, -2 (ix)
	add	a, #0x04
	ld	-8 (ix), a
	ld	a, -1 (ix)
	adc	a, #0x00
	ld	-7 (ix), a
	ld	a, -2 (ix)
	ld	-4 (ix), a
	ld	a, -1 (ix)
	ld	-3 (ix), a
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	inc	hl
	inc	hl
	inc	hl
	ld	a, (hl)
	ld	-3 (ix), a
	ld	a, -2 (ix)
	ld	-5 (ix), a
	ld	a, -1 (ix)
	ld	-4 (ix), a
	ld	l, -5 (ix)
	ld	h, -4 (ix)
	inc	hl
	inc	hl
	ld	a, (hl)
	ld	-6 (ix), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:174: g_PrintData.PatternX     = patternX;
	ld	hl, #_g_PrintData
	ld	(hl), #0x08
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:175: g_PrintData.PatternY     = patternY;
	ld	hl, #(_g_PrintData + 1)
	ld	(hl), #0x08
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:176: g_PrintData.UnitX        = sizeX;
	ld	hl, #(_g_PrintData + 2)
	ld	(hl), #0x01
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:177: g_PrintData.UnitY        = sizeY;
	ld	hl, #(_g_PrintData + 3)
	ld	(hl), #0x01
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:178: g_PrintData.CharFirst    = firstChr;
	ld	hl, #(_g_PrintData + 20)
	ld	a, -6 (ix)
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:179: g_PrintData.CharLast     = lastChr;
	ld	hl, #(_g_PrintData + 21)
	ld	a, -3 (ix)
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:180: g_PrintData.CharCount    = lastChr - firstChr + 1;
	ld	hl, #_g_PrintData + 22
	ex	(sp), hl
	ld	a, -3 (ix)
	sub	a, -6 (ix)
	ld	-3 (ix), a
	inc	-3 (ix)
	pop	hl
	push	hl
	ld	a, -3 (ix)
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:181: g_PrintData.FontPatterns = patterns;
	ld	hl, #_g_PrintData + 28
	ld	-10 (ix), l
	ld	-9 (ix), h
	pop	bc
	pop	hl
	push	hl
	push	bc
	ld	a, -8 (ix)
	ld	(hl), a
	inc	hl
	ld	a, -7 (ix)
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:182: g_PrintData.FontAddr     = g_PrintData.FontPatterns - (firstChr * g_PrintData.PatternY); // pre-compute address of the virtual index 0 character (used to quick drawing in PutChar_GX functions)
	ld	a, (#(_g_PrintData + 1) + 0)
	ld	-3 (ix), a
	ld	e, a
	ld	h, -6 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	l, #0x00
	ld	d, l
	ld	b, #0x08
00145$:
	add	hl, hl
	jr	NC, 00146$
	add	hl, de
00146$:
	djnz	00145$
	ld	-4 (ix), l
	ld	-3 (ix), h
	ld	a, -8 (ix)
	sub	a, -4 (ix)
	ld	-6 (ix), a
	ld	a, -7 (ix)
	sbc	a, -3 (ix)
	ld	-5 (ix), a
	ld	hl, #(_g_PrintData + 30)
	ld	a, -6 (ix)
	ld	(hl), a
	inc	hl
	ld	a, -5 (ix)
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:881: Print_SetFontEx(8, 8, 1, 1, fontData[2], fontData[3], fontData+4);
00103$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:882: Print_Initialize();
	call	_Print_Initialize
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:883: Print_SetMode(PRINT_MODE_TEXT);
	ld	a, #0x04
	call	_Print_SetMode
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:886: const u8* src = g_PrintData.FontPatterns;
	ld	l, -10 (ix)
	ld	h, -9 (ix)
	ld	a, (hl)
	ld	-4 (ix), a
	inc	hl
	ld	a, (hl)
	ld	-3 (ix), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:887: u16 dst = (u16)g_ScreenPatternLow + (offset * 8);
	ld	a, 4 (ix)
	ld	-6 (ix), a
	ld	-5 (ix), #0x00
	ld	b, #0x03
00147$:
	sla	-6 (ix)
	rl	-5 (ix)
	djnz	00147$
	ld	hl, (_g_ScreenPatternLow)
	ld	-10 (ix), l
	ld	-9 (ix), h
	ld	a, -6 (ix)
	ld	-8 (ix), a
	ld	a, -5 (ix)
	ld	-7 (ix), a
	ld	a, -10 (ix)
	add	a, -8 (ix)
	ld	-6 (ix), a
	ld	a, -9 (ix)
	adc	a, -7 (ix)
	ld	-5 (ix), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:889: if(fontData != NULL)
	ld	a, -1 (ix)
	or	a, -2 (ix)
	jr	Z, 00105$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:890: CopyNo8HeightFontData(src, dst, fontData[0] & 0x0F);
	ld	l, -2 (ix)
	ld	h, -1 (ix)
	ld	a, (hl)
	and	a, #0x0f
	push	af
	inc	sp
	ld	e, -6 (ix)
	ld	d, -5 (ix)
	ld	l, -4 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, -3 (ix)
;	spillPairReg hl
;	spillPairReg hl
	call	_CopyNo8HeightFontData
	jr	00106$
00105$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:893: VDP_WriteVRAM(src, dst, 0, g_PrintData.CharCount * 8);
	pop	hl
	push	hl
	ld	a, (hl)
	ld	-7 (ix), a
	ld	-8 (ix), a
	ld	-7 (ix), #0x00
	ld	b, #0x03
00148$:
	sla	-8 (ix)
	rl	-7 (ix)
	djnz	00148$
	ld	l, -8 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, -7 (ix)
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	ld	l, -6 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, -5 (ix)
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	ld	l, -4 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, -3 (ix)
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	call	_VDP_WriteVRAM_16K
	pop	af
	pop	af
	pop	af
00106$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.h:402: inline u8 VDP_GetMode() { return g_VDP_Data.Mode; }
	ld	a, (#_g_VDP_Data + 0)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:895: switch(VDP_GetMode())
	sub	a, #0x03
	jp	NZ,00118$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:904: dst += 256 * 8;
	ld	a, -6 (ix)
	ld	-8 (ix), a
	ld	a, -5 (ix)
	ld	-7 (ix), a
	ld	a, -8 (ix)
	ld	-6 (ix), a
	ld	a, -7 (ix)
	add	a, #0x08
	ld	-5 (ix), a
	ld	a, -6 (ix)
	ld	-8 (ix), a
	ld	a, -5 (ix)
	ld	-7 (ix), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:906: if(fontData != NULL)
	ld	a, -1 (ix)
	or	a, -2 (ix)
	jr	Z, 00109$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:907: CopyNo8HeightFontData(src, dst, fontData[0] & 0x0F);
	ld	l, -2 (ix)
	ld	h, -1 (ix)
	ld	a, (hl)
	and	a, #0x0f
	push	af
	inc	sp
	ld	e, -8 (ix)
	ld	d, -7 (ix)
	ld	l, -4 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, -3 (ix)
;	spillPairReg hl
;	spillPairReg hl
	call	_CopyNo8HeightFontData
	jr	00110$
00109$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:910: VDP_WriteVRAM(src, dst, 0, g_PrintData.CharCount * 8);
	pop	hl
	push	hl
	ld	a, (hl)
	ld	-5 (ix), a
	ld	-6 (ix), a
	ld	-5 (ix), #0x00
	ld	b, #0x03
00151$:
	sla	-6 (ix)
	rl	-5 (ix)
	djnz	00151$
	ld	l, -6 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, -5 (ix)
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	ld	l, -8 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, -7 (ix)
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	ld	l, -4 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, -3 (ix)
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	call	_VDP_WriteVRAM_16K
	pop	af
	pop	af
	pop	af
00110$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:911: dst += 256 * 8;
	ld	a, -8 (ix)
	ld	-6 (ix), a
	ld	a, -7 (ix)
	ld	-5 (ix), a
	ld	a, -6 (ix)
	ld	-8 (ix), a
	ld	a, -5 (ix)
	add	a, #0x08
	ld	-7 (ix), a
	ld	a, -8 (ix)
	ld	-6 (ix), a
	ld	a, -7 (ix)
	ld	-5 (ix), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:913: if(fontData != NULL)
	ld	a, -1 (ix)
	or	a, -2 (ix)
	jr	Z, 00112$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:914: CopyNo8HeightFontData(src, dst, fontData[0] & 0x0F);
	ld	l, -2 (ix)
	ld	h, -1 (ix)
	ld	a, (hl)
	and	a, #0x0f
	push	af
	inc	sp
	ld	e, -6 (ix)
	ld	d, -5 (ix)
	ld	l, -4 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, -3 (ix)
;	spillPairReg hl
;	spillPairReg hl
	call	_CopyNo8HeightFontData
	jr	00118$
00112$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:917: VDP_WriteVRAM(src, dst, 0, g_PrintData.CharCount * 8);
	pop	hl
	push	hl
	ld	a, (hl)
	ld	-8 (ix), a
	ld	-7 (ix), #0x00
	ld	b, #0x03
00152$:
	sla	-8 (ix)
	rl	-7 (ix)
	djnz	00152$
	ld	l, -8 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, -7 (ix)
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	ld	l, -6 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, -5 (ix)
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	ld	l, -4 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, -3 (ix)
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	call	_VDP_WriteVRAM_16K
	pop	af
	pop	af
	pop	af
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:920: };
00118$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:921: }
	ld	sp, ix
	pop	ix
	pop	hl
	inc	sp
	jp	(hl)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:926: void DrawChar_Layout(u8 chr)
;	---------------------------------
; Function DrawChar_Layout
; ---------------------------------
_DrawChar_Layout::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:929: chr = Print_ValidateChar(chr);
	call	_Print_ValidateChar
	ld	c, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:931: u8 shape = chr - g_PrintData.CharFirst + g_PrintData.PatternOffset;
	ld	hl, #_g_PrintData + 20
	ld	b, (hl)
	ld	a, c
	sub	a, b
	ld	hl, #_g_PrintData + 32
	ld	c, (hl)
	add	a, c
	ld	-1 (ix), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:932: u16 dst = (u16)g_ScreenLayoutLow + (g_PrintData.CursorY * g_PrintData.ScreenWidth) + g_PrintData.CursorX;
	ld	hl, #_g_PrintData + 6
	ld	c, (hl)
	ld	de, (#_g_PrintData + 26)
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
	call	__mulint
	ld	iy, (_g_ScreenLayoutLow)
	add	iy, de
	ld	a, (#_g_PrintData + 5)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	push	iy
	pop	bc
	add	hl, bc
	ex	de, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:933: VDP_Poke(shape, dst, g_ScreenLayoutHigh);
	ld	a, -1 (ix)
	call	_VDP_Poke_16K
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:934: }
	inc	sp
	pop	ix
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1099: void Print_Clear()
;	---------------------------------
; Function Print_Clear
; ---------------------------------
_Print_Clear::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1112: VDP_FillVRAM(0, g_ScreenLayoutLow, g_ScreenLayoutHigh, 24 * g_PrintData.ScreenWidth);
	ld	hl, (#(_g_PrintData + 26) + 0)
	ld	c, l
	ld	b, h
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	add	hl, hl
	push	hl
	ld	de, (_g_ScreenLayoutLow)
	xor	a, a
	call	_VDP_FillVRAM_16K
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1115: }
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1120: void Print_Backspace(u8 num)
;	---------------------------------
; Function Print_Backspace
; ---------------------------------
_Print_Backspace::
	ld	c, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1140: u16 dst = g_ScreenLayoutLow + (g_PrintData.CursorY * g_PrintData.ScreenWidth) + g_PrintData.CursorX - num;
	ld	hl, #_g_PrintData + 6
	ld	b, (hl)
	ld	de, (#_g_PrintData + 26)
	ld	l, b
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	push	bc
	call	__mulint
	pop	bc
	ld	iy, (_g_ScreenLayoutLow)
	add	iy, de
	ld	a, (#_g_PrintData + 5)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	push	iy
	pop	de
	add	hl, de
	ld	e, c
	ld	d, #0x00
	cp	a, a
	sbc	hl, de
	ex	de, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1141: VDP_FillVRAM(0, dst, g_ScreenLayoutHigh, num);
	ld	b, #0x00
	push	bc
	xor	a, a
	call	_VDP_FillVRAM_16K
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1144: }
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1149: void Print_DrawChar(u8 chr)
;	---------------------------------
; Function Print_DrawChar
; ---------------------------------
_Print_DrawChar::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
	ld	-1 (ix), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1152: if(g_PrintData.CursorX + PRINT_W(g_PrintData.UnitX) > g_PrintData.ScreenWidth) // Handle automatic new-line when 
	ld	bc, #_g_PrintData + 5
	ld	a, (bc)
	ld	e, a
	ld	d, #0x00
	inc	de
	ld	hl, (#_g_PrintData + 26)
	xor	a, a
	sbc	hl, de
	jr	NC, 00102$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:408: g_PrintData.CursorX = 0;
	xor	a, a
	ld	(bc), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:409: g_PrintData.CursorY += PRINT_H(g_PrintData.UnitY);
	ld	de, #_g_PrintData + 6
	ld	a, (de)
	inc	a
	ld	(de), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1153: Print_Return();
00102$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1158: g_PrintData.DrawChar(chr);
	ld	hl, (#_g_PrintData + 23)
	push	bc
	ld	a, -1 (ix)
	call	___sdcc_call_hl
	pop	bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1161: g_PrintData.CursorX += PRINT_W(g_PrintData.UnitX);
	ld	a, (bc)
	inc	a
	ld	(bc), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1162: }
	inc	sp
	pop	ix
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1168: void Print_DrawCharX(c8 chr, u8 num)
;	---------------------------------
; Function Print_DrawCharX
; ---------------------------------
_Print_DrawCharX::
	ld	c, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1170: for(u8 i = 0; i < num; ++i)
	ld	b, #0x00
00103$:
	ld	a, b
	sub	a, l
	ret	NC
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1171: Print_DrawChar(chr);
	push	hl
	push	bc
	ld	a, c
	call	_Print_DrawChar
	pop	bc
	pop	hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1170: for(u8 i = 0; i < num; ++i)
	inc	b
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1172: }
	jr	00103$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1177: void Print_DrawText(const c8* str)
;	---------------------------------
; Function Print_DrawText
; ---------------------------------
_Print_DrawText::
	ex	de, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1179: while(*str != 0)
00107$:
	ld	a, (de)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1181: if(*str == '\t')
	ld	c,a
	or	a,a
	ret	Z
	sub	a, #0x09
	jr	NZ, 00105$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:400: g_PrintData.CursorX += PRINT_W(g_PrintData.UnitX) + g_PrintData.TabSize - 1;
	ld	bc, #_g_PrintData + 5
	ld	a, (bc)
	ld	hl, #(_g_PrintData + 4)
	ld	l, (hl)
;	spillPairReg hl
	add	a, l
	ld	(bc), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:401: g_PrintData.CursorX &= ~(g_PrintData.TabSize - 1);
	ld	hl, #(_g_PrintData + 4)
	ld	l, (hl)
;	spillPairReg hl
	dec	l
	push	af
	ld	a, l
	cpl
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	pop	af
	and	a, l
	ld	(bc), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1182: Print_Tab();
	jr	00106$
00105$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1183: else if(*str == '\n')
	ld	a, c
	sub	a, #0x0a
	jr	NZ, 00102$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:408: g_PrintData.CursorX = 0;
	ld	hl, #(_g_PrintData + 5)
	ld	(hl), #0x00
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:409: g_PrintData.CursorY += PRINT_H(g_PrintData.UnitY);
	ld	bc, #_g_PrintData + 6
	ld	a, (bc)
	inc	a
	ld	(bc), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1184: Print_Return();
	jr	00106$
00102$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1190: Print_DrawChar(*str);
	push	de
	ld	a, c
	call	_Print_DrawChar
	pop	de
00106$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1191: str++;
	inc	de
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1193: }
	jr	00107$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1198: void Print_DrawBin8(u8 value)
;	---------------------------------
; Function Print_DrawBin8
; ---------------------------------
_Print_DrawBin8::
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1200: u8 flag = (u8)(1 << 7);
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1201: for(u8 i = 0; i < 8; ++i)
	ld	bc, #0x80
00103$:
	ld	a, b
	sub	a, #0x08
	ret	NC
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1203: Print_DrawChar((value & flag) ? '1' : '0');
	ld	a, l
	and	a,c
	jr	Z, 00107$
	ld	de, #0x0031
	jr	00108$
00107$:
	ld	de, #0x0030
00108$:
	push	hl
	push	bc
	ld	a, e
	call	_Print_DrawChar
	pop	bc
	pop	hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1204: flag >>= 1;
	srl	c
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1201: for(u8 i = 0; i < 8; ++i)
	inc	b
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1209: }
	jr	00103$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1214: void Print_DrawHex8(u8 value)
;	---------------------------------
; Function Print_DrawHex8
; ---------------------------------
_Print_DrawHex8::
	ld	e, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1216: Print_DrawChar(g_HexChar[(value >> 4) & 0x000F]);
	ld	bc, #_g_HexChar+0
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
	ld	d, (hl)
	push	bc
	push	de
	ld	a, d
	call	_Print_DrawChar
	pop	de
	pop	bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1217: Print_DrawChar(g_HexChar[value & 0x000F]);
	ld	d, #0x00
	ld	a, e
	and	a, #0x0f
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, bc
	ld	c, (hl)
	ld	a, c
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1221: }
	jp	_Print_DrawChar
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1226: void Print_DrawHex16(u16 value)
;	---------------------------------
; Function Print_DrawHex16
; ---------------------------------
_Print_DrawHex16::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1228: Print_DrawHex8(value >> 8);
	ld	c, h
	push	hl
	ld	a, c
	call	_Print_DrawHex8
	pop	hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1229: Print_DrawHex8((u8)value);
	ld	a, l
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1230: }
	jp	_Print_DrawHex8
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1236: void Print_DrawHex32(u32 value)
;	---------------------------------
; Function Print_DrawHex32
; ---------------------------------
_Print_DrawHex32::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1238: Print_DrawHex16(value >> 16);
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
;	spillPairReg hl
	push	hl
	push	de
	call	_Print_DrawHex16
	pop	de
	pop	bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1239: Print_DrawHex16((u16)value);
	ex	de, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1240: }
	jp	_Print_DrawHex16
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1247: void Print_DrawInt(i32 value)
;	---------------------------------
; Function Print_DrawInt
; ---------------------------------
_Print_DrawInt::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	iy, #-12
	add	iy, sp
	ld	sp, iy
	ld	-4 (ix), e
	ld	-3 (ix), d
	ld	-2 (ix), l
	ld	-1 (ix), h
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1254: if(value < 0)
	bit	7, -1 (ix)
	jr	Z, 00102$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1256: Print_DrawChar('-');
	ld	a, #0x2d
	call	_Print_DrawChar
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1257: value = -value;
	xor	a, a
	sub	a, -4 (ix)
	ld	-4 (ix), a
	ld	a, #0x00
	sbc	a, -3 (ix)
	ld	-3 (ix), a
	ld	a, #0x00
	sbc	a, -2 (ix)
	ld	-2 (ix), a
	sbc	a, a
	sub	a, -1 (ix)
	ld	-1 (ix), a
00102$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1261: c8* ptr = str;
	ld	hl, #0
	add	hl, sp
	ld	c, l
	ld	b, h
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1262: *ptr = 0;
	xor	a, a
	ld	(bc), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1263: while(value >= 10)
00103$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1265: *++ptr = '0' + (value % 10);
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
	ld	h, b
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1263: while(value >= 10)
	ld	a, -4 (ix)
	sub	a, #0x0a
	ld	a, -3 (ix)
	sbc	a, #0x00
	ld	a, -2 (ix)
	sbc	a, #0x00
	ld	a, -1 (ix)
	rla
	ccf
	rra
	sbc	a, #0x80
	jr	C, 00105$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1265: *++ptr = '0' + (value % 10);
	ld	c, l
	ld	b, h
	push	hl
	push	bc
	ld	de, #0x0000
	push	de
	ld	e, #0x0a
	push	de
	ld	e, -4 (ix)
	ld	d, -3 (ix)
	ld	l, -2 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, -1 (ix)
;	spillPairReg hl
;	spillPairReg hl
	call	__modslong
	pop	af
	ex	(sp),hl
	pop	iy
	pop	bc
	pop	hl
	ld	a, e
	add	a, #0x30
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1266: value /= 10;
	push	bc
	ld	hl, #0x0000
	push	hl
	ld	l, #0x0a
	push	hl
	ld	e, -4 (ix)
	ld	d, -3 (ix)
	ld	l, -2 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, -1 (ix)
;	spillPairReg hl
;	spillPairReg hl
	call	__divslong
	pop	af
	pop	af
	pop	bc
	ld	-4 (ix), e
	ld	-3 (ix), d
	ld	-2 (ix), l
	ld	-1 (ix), h
	jr	00103$
00105$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1268: *++ptr = '0' + value;
	ld	a, -4 (ix)
	add	a, #0x30
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1269: while(*ptr != 0)
00106$:
	ld	a, (hl)
	or	a, a
	jr	Z, 00109$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1270: Print_DrawChar(*ptr--);	
	dec	hl
	ld	c, a
	push	hl
	ld	a, c
	call	_Print_DrawChar
	pop	hl
	jr	00106$
00109$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1271: }
	ld	sp, ix
	pop	ix
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1280: void Print_DrawFormat(const c8* format, ...)
;	---------------------------------
; Function Print_DrawFormat
; ---------------------------------
_Print_DrawFormat::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-16
	add	hl, sp
	ld	sp, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1285: va_start(args, format);
	ld	hl, #22
	add	hl, sp
	ld	-12 (ix), l
	ld	-11 (ix), h
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1287: const c8* ptr = format;
	ld	a, 4 (ix)
	ld	-2 (ix), a
	ld	a, 5 (ix)
	ld	-1 (ix), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1288: while(*ptr != 0)
00191$:
	ld	l, -2 (ix)
	ld	h, -1 (ix)
	ld	a, (hl)
	ld	-3 (ix), a
	or	a, a
	jp	Z, 00197$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1290: if(*ptr == '%')
	ld	a, -3 (ix)
	sub	a, #0x25
	jp	NZ,00189$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1292: ptr++;
	ld	c, -2 (ix)
	ld	b, -1 (ix)
	inc	bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1295: u8 len = 0;
	ld	-10 (ix), #0x00
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1296: if((*ptr >= '0') && (*ptr <= '9'))
	ld	a, (bc)
	ld	e, a
	sub	a, #0x30
	jr	C, 00205$
	ld	a, #0x39
	sub	a, e
	jr	C, 00205$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1298: len = *ptr - '0';
	ld	a, e
	add	a, #0xd0
	ld	-10 (ix), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1299: ptr++;
	inc	bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1301: while((*ptr >= '0') && (*ptr <= '9'))
00205$:
	ld	-2 (ix), c
	ld	-1 (ix), b
00105$:
	ld	l, -2 (ix)
	ld	h, -1 (ix)
	ld	a, (hl)
	ld	-9 (ix), a
	sub	a, #0x30
	jr	C, 00240$
	ld	a, #0x39
	sub	a, -9 (ix)
	jr	C, 00240$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1303: len *= 10;
	ld	l, -10 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	c, l
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1304: len += *ptr - '0';
	ld	a, -9 (ix)
	add	a, #0xd0
	add	a, l
	ld	-10 (ix), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1305: ptr++;
	inc	-2 (ix)
	jr	NZ, 00105$
	inc	-1 (ix)
	jr	00105$
00240$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1311: i16 val = (i16)va_arg(args, i16);
	ld	a, -12 (ix)
	add	a, #0x02
	ld	-8 (ix), a
	ld	a, -11 (ix)
	adc	a, #0x00
	ld	-7 (ix), a
	ld	a, -8 (ix)
	add	a, #0xfe
	ld	-6 (ix), a
	ld	a, -7 (ix)
	adc	a, #0xff
	ld	-5 (ix), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1309: if((*ptr == 'i') || (*ptr == 'd'))
	ld	a, -9 (ix)
	sub	a, #0x69
	jr	Z, 00175$
	ld	a, -9 (ix)
	sub	a, #0x64
	jr	NZ, 00176$
00175$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1311: i16 val = (i16)va_arg(args, i16);
	ld	a, -8 (ix)
	ld	-12 (ix), a
	ld	a, -7 (ix)
	ld	-11 (ix), a
	ld	a, -6 (ix)
	ld	-4 (ix), a
	ld	a, -5 (ix)
	ld	-3 (ix), a
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	a, (hl)
	ld	-4 (ix), a
	inc	hl
	ld	a, (hl)
	ld	-3 (ix), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1312: Print_DrawInt(val);
	ld	a, -4 (ix)
	ld	-6 (ix), a
	ld	a, -3 (ix)
	ld	-5 (ix), a
	rlca
	sbc	a, a
	ld	-4 (ix), a
	ld	-3 (ix), a
	ld	e, -6 (ix)
	ld	d, -5 (ix)
	ld	l, -4 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, -3 (ix)
;	spillPairReg hl
;	spillPairReg hl
	call	_Print_DrawInt
	jp	00190$
00176$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1316: u16 val = (u16)va_arg(args, u16);
	ld	a, -6 (ix)
	ld	-4 (ix), a
	ld	a, -5 (ix)
	ld	-3 (ix), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1314: else if(*ptr == 'u')
	ld	a, -9 (ix)
	sub	a, #0x75
	jr	NZ, 00173$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1316: u16 val = (u16)va_arg(args, u16);
	ld	a, -8 (ix)
	ld	-12 (ix), a
	ld	a, -7 (ix)
	ld	-11 (ix), a
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	a, (hl)
	ld	-4 (ix), a
	inc	hl
	ld	a, (hl)
	ld	-3 (ix), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1317: Print_DrawInt(val);
	ld	a, -4 (ix)
	ld	-6 (ix), a
	ld	a, -3 (ix)
	ld	-5 (ix), a
	xor	a, a
	ld	-4 (ix), a
	ld	-3 (ix), a
	ld	e, -6 (ix)
	ld	d, -5 (ix)
	ld	l, -4 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, -3 (ix)
;	spillPairReg hl
;	spillPairReg hl
	call	_Print_DrawInt
	jp	00190$
00173$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1319: else if(*ptr == 'x')
	ld	a, -9 (ix)
	sub	a, #0x78
	jp	NZ,00170$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1321: if(len == 0)
	ld	a, -10 (ix)
	or	a, a
	jr	NZ, 00109$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1322: len = 4;
	ld	-10 (ix), #0x04
00109$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1323: u16 val = (u16)va_arg(args, u16);
	ld	a, -8 (ix)
	ld	-12 (ix), a
	ld	a, -7 (ix)
	ld	-11 (ix), a
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1324: if(len > 3)
	ld	a, #0x03
	sub	a, -10 (ix)
	jr	NC, 00111$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1325: Print_DrawChar(g_HexChar[(val >> 12) & 0x000F]);
	ld	a, b
	rlca
	rlca
	rlca
	rlca
	and	a, #0xf
	ld	e, a
	ld	d, #0x00
	ld	hl, #_g_HexChar
	add	hl, de
	ld	e, (hl)
	push	bc
	ld	a, e
	call	_Print_DrawChar
	pop	bc
00111$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1326: if(len > 2)
	ld	a, #0x02
	sub	a, -10 (ix)
	jr	NC, 00113$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1327: Print_DrawChar(g_HexChar[(val >> 8) & 0x000F]);
	ld	a, b
	and	a, #0x0f
	ld	e, a
	ld	d, #0x00
	ld	hl, #_g_HexChar
	add	hl, de
	ld	e, (hl)
	push	bc
	ld	a, e
	call	_Print_DrawChar
	pop	bc
00113$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1328: if(len > 1)
	ld	a, #0x01
	sub	a, -10 (ix)
	jr	NC, 00115$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1329: Print_DrawChar(g_HexChar[(val >> 4) & 0x000F]);
	ld	e, c
	ld	d, b
	srl	d
	rr	e
	srl	d
	rr	e
	srl	d
	rr	e
	srl	d
	rr	e
	ld	a, e
	and	a, #0x0f
	ld	e, a
	ld	d, #0x00
	ld	hl, #_g_HexChar
	add	hl, de
	ld	e, (hl)
	push	bc
	ld	a, e
	call	_Print_DrawChar
	pop	bc
00115$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1330: Print_DrawChar(g_HexChar[val & 0x000F]);
	ld	a, c
	and	a, #0x0f
	ld	c, a
	ld	b, #0x00
	ld	hl, #_g_HexChar
	add	hl, bc
	ld	a, (hl)
	call	_Print_DrawChar
	jp	00190$
00170$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1332: else if(*ptr == 'b')
	ld	a, -9 (ix)
	sub	a, #0x62
	jr	NZ, 00167$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1334: if(len == 0)
	ld	a, -10 (ix)
	or	a, a
	jr	NZ, 00117$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1335: len = 16;
	ld	-10 (ix), #0x10
00117$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1336: u16 val = (u16)va_arg(args, u16);
	ld	a, -8 (ix)
	ld	-12 (ix), a
	ld	a, -7 (ix)
	ld	-11 (ix), a
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	a, (hl)
	ld	-4 (ix), a
	inc	hl
	ld	a, (hl)
	ld	-3 (ix), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1337: u16 bit = 1 << (len - 1);
	ld	b, -10 (ix)
	dec	b
	ld	hl, #0x0001
	inc	b
	jr	00418$
00417$:
	add	hl, hl
00418$:
	djnz	00417$
	ex	de, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1338: while(bit)
00121$:
	ld	a, d
	or	a, e
	jp	Z, 00190$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1340: if(val & bit)
	ld	a, -4 (ix)
	and	a, e
	ld	-6 (ix), a
	ld	a, -3 (ix)
	and	a, d
	ld	-5 (ix), a
	or	a, -6 (ix)
	jr	Z, 00119$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1341: Print_DrawChar('1');
	push	de
	ld	a, #0x31
	call	_Print_DrawChar
	pop	de
	jr	00120$
00119$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1343: Print_DrawChar('0');
	push	de
	ld	a, #0x30
	call	_Print_DrawChar
	pop	de
00120$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1344: bit >>= 1;
	srl	d
	rr	e
	jr	00121$
00167$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1350: i32 val = (i32)va_arg(args, i32);
	ld	a, -12 (ix)
	add	a, #0x04
	ld	c, a
	ld	a, -11 (ix)
	adc	a, #0x00
	ld	b, a
	ld	a, c
	add	a, #0xfc
	ld	e, a
	ld	a, b
	adc	a, #0xff
	ld	d, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1348: else if((*ptr == 'I') || (*ptr == 'D'))
	ld	a, -9 (ix)
	sub	a, #0x49
	jr	Z, 00162$
	ld	a, -9 (ix)
	sub	a, #0x44
	jr	NZ, 00163$
00162$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1350: i32 val = (i32)va_arg(args, i32);
	ld	-12 (ix), c
	ld	-11 (ix), b
	ex	de, hl
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	inc	hl
	ld	c, (hl)
	inc	hl
	ld	h, (hl)
;	spillPairReg hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1351: Print_DrawInt(val);
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
	call	_Print_DrawInt
	jp	00190$
00163$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1355: u32 val = (u32)va_arg(args, u32);
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1353: else if(*ptr == 'U')
	ld	a, -9 (ix)
	sub	a, #0x55
	jr	NZ, 00160$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1355: u32 val = (u32)va_arg(args, u32);
	ld	-12 (ix), c
	ld	-11 (ix), b
	ex	de,hl
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	inc	hl
	ld	c, (hl)
	inc	hl
	ld	h, (hl)
;	spillPairReg hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1356: Print_DrawInt(val);
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
	call	_Print_DrawInt
	jp	00190$
00160$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1358: else if(*ptr == 'X')
	ld	a, -9 (ix)
	sub	a, #0x58
	jp	NZ,00157$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1360: if(len == 0)
	ld	a, -10 (ix)
	or	a, a
	jr	NZ, 00125$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1361: len = 8;
	ld	-10 (ix), #0x08
00125$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1362: u32 val = (u32)va_arg(args, u32);
	ld	-12 (ix), c
	ld	-11 (ix), b
	ex	de,hl
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	inc	hl
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1364: if(len > 7)
	ld	a, #0x07
	sub	a, -10 (ix)
	jr	NC, 00127$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1365: Print_DrawChar(g_HexChar[(val >> 28) & 0xF]);
	ld	-6 (ix), d
	xor	a, a
	ld	-5 (ix), a
	ld	-4 (ix), a
	ld	-3 (ix), a
	ld	a, #0x04
00426$:
	srl	-6 (ix)
	dec	a
	jr	NZ, 00426$
	ld	a, -6 (ix)
;	spillPairReg hl
;	spillPairReg hl
	and	a, #0x0f
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	a, #<(_g_HexChar)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	a, h
	adc	a, #>(_g_HexChar)
	ld	h, a
	ld	l, (hl)
;	spillPairReg hl
	push	bc
	push	de
	ld	a, l
	call	_Print_DrawChar
	pop	de
	pop	bc
00127$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1366: if(len > 6)
	ld	a, #0x06
	sub	a, -10 (ix)
	jr	NC, 00129$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1367: Print_DrawChar(g_HexChar[(val >> 24) & 0xF]);
	ld	a, d
;	spillPairReg hl
;	spillPairReg hl
	and	a, #0x0f
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	a, #<(_g_HexChar)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	a, h
	adc	a, #>(_g_HexChar)
	ld	h, a
	ld	l, (hl)
;	spillPairReg hl
	push	bc
	push	de
	ld	a, l
	call	_Print_DrawChar
	pop	de
	pop	bc
00129$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1368: if(len > 5)
	ld	a, #0x05
	sub	a, -10 (ix)
	jr	NC, 00131$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1369: Print_DrawChar(g_HexChar[(val >> 20) & 0xF]);
	ld	-6 (ix), e
	ld	-5 (ix), d
	xor	a, a
	ld	-4 (ix), a
	ld	-3 (ix), a
	ld	a, #0x04
00428$:
	srl	-5 (ix)
	rr	-6 (ix)
	dec	a
	jr	NZ, 00428$
	ld	a, -6 (ix)
;	spillPairReg hl
;	spillPairReg hl
	and	a, #0x0f
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	a, #<(_g_HexChar)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	a, h
	adc	a, #>(_g_HexChar)
	ld	h, a
	ld	l, (hl)
;	spillPairReg hl
	push	bc
	push	de
	ld	a, l
	call	_Print_DrawChar
	pop	de
	pop	bc
00131$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1370: if(len > 4)
	ld	a, #0x04
	sub	a, -10 (ix)
	jr	NC, 00133$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1371: Print_DrawChar(g_HexChar[(val >> 16) & 0xF]);
	ld	a, e
;	spillPairReg hl
;	spillPairReg hl
	and	a, #0x0f
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	a, #<(_g_HexChar)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	a, h
	adc	a, #>(_g_HexChar)
	ld	h, a
	ld	l, (hl)
;	spillPairReg hl
	push	bc
	push	de
	ld	a, l
	call	_Print_DrawChar
	pop	de
	pop	bc
00133$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1372: if(len > 3)
	ld	a, #0x03
	sub	a, -10 (ix)
	jr	NC, 00135$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1373: Print_DrawChar(g_HexChar[(val >> 12) & 0xF]);
	ld	-6 (ix), b
	ld	-5 (ix), e
	ld	-4 (ix), d
	ld	-3 (ix), #0x00
	ld	a, #0x04
00430$:
	srl	-4 (ix)
	rr	-5 (ix)
	rr	-6 (ix)
	dec	a
	jr	NZ, 00430$
	ld	a, -6 (ix)
;	spillPairReg hl
;	spillPairReg hl
	and	a, #0x0f
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	push	de
	ld	de, #_g_HexChar
	add	hl, de
	pop	de
	ld	l, (hl)
;	spillPairReg hl
	push	bc
	push	de
	ld	a, l
	call	_Print_DrawChar
	pop	de
	pop	bc
00135$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1374: if(len > 2)
	ld	a, #0x02
	sub	a, -10 (ix)
	jr	NC, 00137$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1375: Print_DrawChar(g_HexChar[(val >> 8) & 0xF]);
	ld	a, b
;	spillPairReg hl
;	spillPairReg hl
	and	a, #0x0f
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	a, #<(_g_HexChar)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	a, h
	adc	a, #>(_g_HexChar)
	ld	h, a
	ld	l, (hl)
;	spillPairReg hl
	push	bc
	push	de
	ld	a, l
	call	_Print_DrawChar
	pop	de
	pop	bc
00137$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1376: if(len > 1)
	ld	a, #0x01
	sub	a, -10 (ix)
	jr	NC, 00139$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1377: Print_DrawChar(g_HexChar[(val >> 4) & 0xF]);
	ld	-6 (ix), c
	ld	-5 (ix), b
	ld	-4 (ix), e
	ld	-3 (ix), d
	ld	a, #0x04
00432$:
	srl	-3 (ix)
	rr	-4 (ix)
	rr	-5 (ix)
	rr	-6 (ix)
	dec	a
	jr	NZ, 00432$
	ld	a, -6 (ix)
;	spillPairReg hl
;	spillPairReg hl
	and	a, #0x0f
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	a, #<(_g_HexChar)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	a, h
	adc	a, #>(_g_HexChar)
	ld	h, a
	ld	l, (hl)
;	spillPairReg hl
	push	bc
	push	de
	ld	a, l
	call	_Print_DrawChar
	pop	de
	pop	bc
00139$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1378: Print_DrawChar(g_HexChar[val & 0xF]);
	ld	a, c
	and	a, #0x0f
	ld	c, a
	ld	b, #0x00
	ld	hl, #_g_HexChar
	add	hl, bc
	ld	a, (hl)
	call	_Print_DrawChar
	jp	00190$
00157$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1380: else if(*ptr == 'B')
	ld	a, -9 (ix)
	sub	a, #0x42
	jp	NZ,00154$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1382: if(len == 0)
	ld	a, -10 (ix)
	or	a, a
	jr	NZ, 00141$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1383: len = 16;
	ld	-10 (ix), #0x10
00141$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1384: u32 val = (u32)va_arg(args, u32);
	ld	-12 (ix), c
	ld	-11 (ix), b
	ld	hl, #0
	add	hl, sp
	ex	de, hl
	ld	bc, #0x0004
	ldir
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1385: u32 bit = 1 << (len - 1);
	ld	b, -10 (ix)
	dec	b
	ld	hl, #0x0001
	inc	b
	jr	00437$
00436$:
	add	hl, hl
00437$:
	djnz	00436$
	ld	-6 (ix), l
	ld	a, h
	ld	-5 (ix), a
	rlca
	sbc	a, a
	ld	-4 (ix), a
	ld	-3 (ix), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1386: while(bit)
00145$:
	ld	a, -3 (ix)
	or	a, -4 (ix)
	or	a, -5 (ix)
	or	a, -6 (ix)
	jp	Z, 00190$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1388: if(val & bit)
	ld	a, -16 (ix)
	and	a, -6 (ix)
	ld	-10 (ix), a
	ld	a, -15 (ix)
	and	a, -5 (ix)
	ld	-9 (ix), a
	ld	a, -14 (ix)
	and	a, -4 (ix)
	ld	-8 (ix), a
	ld	a, -13 (ix)
	and	a, -3 (ix)
	ld	-7 (ix), a
	or	a, -8 (ix)
	or	a, -9 (ix)
	or	a, -10 (ix)
	jr	Z, 00143$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1389: Print_DrawChar('1');
	ld	a, #0x31
	call	_Print_DrawChar
	jr	00144$
00143$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1391: Print_DrawChar('0');
	ld	a, #0x30
	call	_Print_DrawChar
00144$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1392: bit >>= 1;
	srl	-3 (ix)
	rr	-4 (ix)
	rr	-5 (ix)
	rr	-6 (ix)
	jr	00145$
00154$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1396: else if(*ptr == 'c')
	ld	a, -9 (ix)
	sub	a, #0x63
	jr	NZ, 00151$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1398: c8 val = (c8)va_arg(args, c8);
	ld	l, -12 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, -11 (ix)
;	spillPairReg hl
;	spillPairReg hl
	inc	hl
	ld	-12 (ix), l
	ld	-11 (ix), h
	dec	hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1399: Print_DrawChar(val);
	ld	a, (hl)
	call	_Print_DrawChar
	jr	00190$
00151$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1401: else if(*ptr == 's')
	ld	a, -9 (ix)
	sub	a, #0x73
	jr	NZ, 00190$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1403: const c8* val = (const c8*)va_arg(args, const c8*);
	ld	a, -8 (ix)
	ld	-12 (ix), a
	ld	a, -7 (ix)
	ld	-11 (ix), a
	ld	l, -6 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, -5 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	c, (hl)
	inc	hl
	ld	h, (hl)
;	spillPairReg hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1404: Print_DrawText(val);
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
	call	_Print_DrawText
	jr	00190$
00189$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1408: else if(*ptr == '\t')
	ld	a, -3 (ix)
	sub	a, #0x09
	jr	NZ, 00186$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:400: g_PrintData.CursorX += PRINT_W(g_PrintData.UnitX) + g_PrintData.TabSize - 1;
	ld	bc, #_g_PrintData + 5
	ld	a, (bc)
	ld	hl, #(_g_PrintData + 4)
	ld	e, (hl)
	add	a, e
	ld	e, a
	ld	(bc), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:401: g_PrintData.CursorX &= ~(g_PrintData.TabSize - 1);
	ld	a, (#(_g_PrintData + 4) + 0)
	dec	a
	cpl
	and	a, e
	ld	(bc), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1409: Print_Tab();
	jr	00190$
00186$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1410: else if(*ptr == '\n')
	ld	a, -3 (ix)
	sub	a, #0x0a
	jr	NZ, 00183$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:408: g_PrintData.CursorX = 0;
	ld	hl, #(_g_PrintData + 5)
	ld	(hl), #0x00
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:409: g_PrintData.CursorY += PRINT_H(g_PrintData.UnitY);
	ld	bc, #_g_PrintData + 6
	ld	a, (bc)
	inc	a
	ld	(bc), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1411: Print_Return();
	jr	00190$
00183$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1412: else if(*ptr == ' ')
	ld	a, -3 (ix)
	sub	a, #0x20
	jr	NZ, 00180$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:393: g_PrintData.CursorX += PRINT_W(g_PrintData.UnitX);
	ld	bc, #_g_PrintData + 5
	ld	a, (bc)
	inc	a
	ld	(bc), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1413: Print_Space();
	jr	00190$
00180$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1415: Print_DrawChar(*ptr);
	ld	a, -3 (ix)
	call	_Print_DrawChar
00190$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1417: ptr++;
	inc	-2 (ix)
	jp	NZ,00191$
	inc	-1 (ix)
	jp	00191$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1420: va_end(args);
00197$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1421: }
	ld	sp, ix
	pop	ix
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1431: void Print_DrawLineH(u8 x, u8 y, u8 len)
;	---------------------------------
; Function Print_DrawLineH
; ---------------------------------
_Print_DrawLineH::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	b, a
	ld	c, l
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:203: g_PrintData.CursorX = x;
	ld	hl, #(_g_PrintData + 5)
	ld	(hl), b
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:204: g_PrintData.CursorY = y;
	ld	hl, #(_g_PrintData + 6)
	ld	(hl), c
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1434: Print_DrawCharX(0x17, len);
	ld	l, 4 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	a, #0x17
	call	_Print_DrawCharX
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1435: }
	pop	ix
	pop	hl
	inc	sp
	jp	(hl)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1439: void Print_DrawLineV(u8 x, u8 y, u8 len)
;	---------------------------------
; Function Print_DrawLineV
; ---------------------------------
_Print_DrawLineV::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
	ld	c, a
	ld	-1 (ix), l
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1441: for(u8 i = 0; i < len; i++)
	ld	b, #0x00
00104$:
	ld	a, b
	sub	a, 4 (ix)
	jr	NC, 00106$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1443: Print_SetPosition(x, y + i);
	ld	a, -1 (ix)
	add	a, b
	ld	e, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:203: g_PrintData.CursorX = x;
	ld	hl, #(_g_PrintData + 5)
	ld	(hl), c
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:204: g_PrintData.CursorY = y;
	ld	hl, #(_g_PrintData + 6)
	ld	(hl), e
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1444: Print_DrawChar(0x16);
	push	bc
	ld	a, #0x16
	call	_Print_DrawChar
	pop	bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1441: for(u8 i = 0; i < len; i++)
	inc	b
	jr	00104$
00106$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1446: }
	inc	sp
	pop	ix
	pop	hl
	inc	sp
	jp	(hl)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1450: void Print_DrawBox(u8 x, u8 y, u8 width, u8 height)
;	---------------------------------
; Function Print_DrawBox
; ---------------------------------
_Print_DrawBox::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
	ld	d, a
	ld	e, l
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:203: g_PrintData.CursorX = x;
	ld	hl, #(_g_PrintData + 5)
	ld	(hl), d
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:204: g_PrintData.CursorY = y;
	ld	hl, #(_g_PrintData + 6)
	ld	(hl), e
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1454: Print_DrawChar(0x18);
	push	de
	ld	a, #0x18
	call	_Print_DrawChar
	pop	de
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1455: Print_SetPosition(x + width - 1, y);
	ld	a, d
	add	a, 4 (ix)
	dec	a
	ld	c, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:203: g_PrintData.CursorX = x;
	ld	(#(_g_PrintData + 5)),a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:204: g_PrintData.CursorY = y;
	ld	hl, #(_g_PrintData + 6)
	ld	(hl), e
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1456: Print_DrawChar(0x19);
	push	bc
	push	de
	ld	a, #0x19
	call	_Print_DrawChar
	pop	de
	pop	bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1457: Print_SetPosition(x, y + height - 1);
	ld	a, e
	add	a, 5 (ix)
	dec	a
	ld	b, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:203: g_PrintData.CursorX = x;
	ld	hl, #(_g_PrintData + 5)
	ld	(hl), d
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:204: g_PrintData.CursorY = y;
	ld	(#(_g_PrintData + 6)),a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1458: Print_DrawChar(0x1A);
	push	bc
	push	de
	ld	a, #0x1a
	call	_Print_DrawChar
	pop	de
	pop	bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:203: g_PrintData.CursorX = x;
	ld	hl, #(_g_PrintData + 5)
	ld	(hl), c
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.h:204: g_PrintData.CursorY = y;
	ld	hl, #(_g_PrintData + 6)
	ld	(hl), b
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1460: Print_DrawChar(0x1B);
	push	bc
	push	de
	ld	a, #0x1b
	call	_Print_DrawChar
	pop	de
	pop	bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1463: Print_DrawLineH(x + 1, y,              width - 2);
	ld	a, 4 (ix)
	add	a, #0xfe
	ld	-1 (ix), a
	ld	h, d
;	spillPairReg hl
;	spillPairReg hl
	inc	h
	push	hl
	push	bc
	push	de
	ld	a, -1 (ix)
	push	af
	inc	sp
	ld	l, e
;	spillPairReg hl
;	spillPairReg hl
	ld	a, h
	call	_Print_DrawLineH
	pop	de
	pop	bc
	pop	hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1464: Print_DrawLineH(x + 1, y + height - 1, width - 2);
	push	bc
	push	de
	ld	a, -1 (ix)
	push	af
	inc	sp
	ld	l, b
;	spillPairReg hl
;	spillPairReg hl
	ld	a, h
	call	_Print_DrawLineH
	pop	de
	pop	bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1467: Print_DrawLineV(x,             y + 1, height - 2);
	ld	b, 5 (ix)
	dec	b
	dec	b
	inc	e
	push	bc
	push	de
	push	bc
	inc	sp
	ld	l, e
;	spillPairReg hl
;	spillPairReg hl
	ld	a, d
	call	_Print_DrawLineV
	pop	de
	pop	bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1468: Print_DrawLineV(x + width - 1, y + 1, height - 2);
	push	bc
	inc	sp
	ld	l, e
;	spillPairReg hl
;	spillPairReg hl
	ld	a, c
	call	_Print_DrawLineV
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/print.c:1469: }
	inc	sp
	pop	ix
	pop	hl
	pop	af
	jp	(hl)
	.area _CODE
	.area _INITIALIZER
__xinit__g_PrintInvalid:
	.db #0xff	; 255
	.db #0x81	; 129
	.db #0x81	; 129
	.db #0x81	; 129
	.db #0x81	; 129
	.db #0x81	; 129
	.db #0x81	; 129
	.db #0xff	; 255
	.area _CABS (ABS)
