;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.2.0 #13081 (MINGW64)
;--------------------------------------------------------
	.module vdp
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _VDP_SetSprite
	.globl _g_VDPInitilized
	.globl _g_SpriteColorLow
	.globl _g_SpritePatternLow
	.globl _g_SpriteAttributeLow
	.globl _g_ScreenPatternLow
	.globl _g_ScreenColorLow
	.globl _g_ScreenLayoutLow
	.globl _g_VDP_Sprite
	.globl _g_VDP_Command
	.globl _g_VDP_Data
	.globl _g_VDP_REGSAV
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
	.globl _VDP_SetModeFlag
	.globl _VDP_SetModeText1
	.globl _VDP_SetModeMultiColor
	.globl _VDP_SetModeGraphic1
	.globl _VDP_SetModeGraphic2
	.globl _VDP_ClearVRAM
	.globl _VDP_WriteVRAM_16K
	.globl _VDP_FillVRAM_16K
	.globl _VDP_ReadVRAM_16K
	.globl _VDP_Peek_16K
	.globl _VDP_Poke_16K
	.globl _VDP_Initialize
	.globl _VDP_SetMode
	.globl _VDP_GetVersion
	.globl _VDP_RegWrite
	.globl _VDP_RegWriteBak
	.globl _VDP_RegWriteBakMask
	.globl _VDP_ReadDefaultStatus
	.globl _VDP_SetLayoutTable
	.globl _VDP_SetColorTable
	.globl _VDP_SetPatternTable
	.globl _VDP_SetSpriteAttributeTable
	.globl _VDP_SetSpritePatternTable
	.globl _VDP_LoadSpritePattern
	.globl _VDP_SetSpriteSM1
	.globl _VDP_SetSpritePosition
	.globl _VDP_SetSpritePositionX
	.globl _VDP_SetSpritePositionY
	.globl _VDP_SetSpritePattern
	.globl _VDP_SetSpriteColorSM1
	.globl _VDP_DisableSpritesFrom
	.globl _VDP_LoadPattern_GM2
	.globl _VDP_LoadColor_GM2
	.globl _VDP_WriteLayout_GM2
	.globl _VDP_FillLayout_GM2
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
_g_PortPrimarySlot	=	0x00a8
_g_PortReadKeyboard	=	0x00a9
_g_PortAccessKeyboard	=	0x00aa
_g_PortControl	=	0x00ab
_g_VDP_DataPort	=	0x0098
_g_VDP_RegPort	=	0x0099
_g_VDP_AddrPort	=	0x0099
_g_VDP_StatPort	=	0x0099
_g_PSG_RegPort	=	0x00a0
_g_PSG_DataPort	=	0x00a1
_g_PSG_StatPort	=	0x00a2
_g_PSG_Ext_RegPort	=	0x0010
_g_PSG_Ext_DataPort	=	0x0011
_g_PSG_Ext_StatPort	=	0x0012
_g_MSXMusic_IndexPort	=	0x007c
_g_MSXMusic_DataPort	=	0x007d
_g_MSXAudio_IndexPort	=	0x00c0
_g_MSXAudio_DataPort	=	0x00c1
_g_MSXAudio_IndexPort2	=	0x00c2
_g_MSXAudio_DataPort2	=	0x00c3
_g_RTC_AddrPort	=	0x00b4
_g_RTC_DataPort	=	0x00b5
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
_g_VDP_REGSAV::
	.ds 28
_g_VDP_Data::
	.ds 2
_g_VDP_Command::
	.ds 15
_g_VDP_Sprite::
	.ds 4
_g_ScreenLayoutLow::
	.ds 2
_g_ScreenColorLow::
	.ds 2
_g_ScreenPatternLow::
	.ds 2
_g_SpriteAttributeLow::
	.ds 2
_g_SpritePatternLow::
	.ds 2
_g_SpriteColorLow::
	.ds 2
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_g_VDPInitilized::
	.ds 1
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
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:169: void VDP_SetModeFlag(u8 flag)
;	---------------------------------
; Function VDP_SetModeFlag
; ---------------------------------
_VDP_SetModeFlag::
	ld	e, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:172: u8 reg1 = g_VDP_REGSAV[1];
	ld	a, (#_g_VDP_REGSAV + 1)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:173: reg1 &= 0b11100111;
	and	a, #0xe7
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:174: if(flag & 0b00001)
	bit	0, e
	jr	Z, 00102$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:175: reg1 |= 0b00010000;
	set	4, l
00102$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:176: if(flag & 0b00010)
	bit	1, e
	jr	Z, 00104$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:177: reg1 |= 0b00001000;
	set	3, l
00104$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:178: VDP_RegWriteBak(1, reg1);
	ld	a, #0x01
	call	_VDP_RegWriteBak
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:181: u8 reg0 = g_VDP_REGSAV[0];
	ld	a, (#_g_VDP_REGSAV + 0)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:182: reg0 &= 0b11110001;
	and	a, #0xf1
	ld	c, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:183: flag >>= 1;
	ld	a, e
	srl	a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:184: flag &= 0b00001110;
	and	a, #0x0e
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:185: reg0 |= flag;
	or	a, c
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:186: VDP_RegWriteBak(0, reg0);
	xor	a, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:187: }
	jp	_VDP_RegWriteBak
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
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:192: void VDP_SetModeText1()
;	---------------------------------
; Function VDP_SetModeText1
; ---------------------------------
_VDP_SetModeText1::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:194: VDP_SetModeFlag(VDP_T1_MODE);
	ld	a, #0x01
	call	_VDP_SetModeFlag
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:195: VDP_SetLayoutTable(VDP_T1_ADDR_NT);
	ld	hl, #0x0000
	call	_VDP_SetLayoutTable
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:196: VDP_SetPatternTable(VDP_T1_ADDR_PT);
	ld	hl, #0x0800
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:197: }
	jp	_VDP_SetPatternTable
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:203: void VDP_SetModeMultiColor()
;	---------------------------------
; Function VDP_SetModeMultiColor
; ---------------------------------
_VDP_SetModeMultiColor::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:205: VDP_SetModeFlag(VDP_MC_MODE);
	ld	a, #0x02
	call	_VDP_SetModeFlag
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:206: VDP_SetLayoutTable(VDP_MC_ADDR_NT);
	ld	hl, #0x0800
	call	_VDP_SetLayoutTable
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:207: VDP_SetPatternTable(VDP_MC_ADDR_PT);
	ld	hl, #0x0000
	call	_VDP_SetPatternTable
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:209: VDP_SetSpriteAttributeTable(VDP_MC_ADDR_SAT);
	ld	hl, #0x1b00
	call	_VDP_SetSpriteAttributeTable
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:210: VDP_SetSpritePatternTable(VDP_MC_ADDR_SPT);
	ld	hl, #0x3800
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:212: }
	jp	_VDP_SetSpritePatternTable
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:218: void VDP_SetModeGraphic1()
;	---------------------------------
; Function VDP_SetModeGraphic1
; ---------------------------------
_VDP_SetModeGraphic1::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:220: VDP_SetModeFlag(VDP_G1_MODE);
	xor	a, a
	call	_VDP_SetModeFlag
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:221: VDP_SetLayoutTable(VDP_G1_ADDR_NT);
	ld	hl, #0x1800
	call	_VDP_SetLayoutTable
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:222: VDP_SetColorTable(VDP_G1_ADDR_CT);
	ld	hl, #0x2000
	call	_VDP_SetColorTable
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:223: VDP_SetPatternTable(VDP_G1_ADDR_PT);
	ld	hl, #0x0000
	call	_VDP_SetPatternTable
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:225: VDP_SetSpriteAttributeTable(VDP_G1_ADDR_SAT);
	ld	hl, #0x1b00
	call	_VDP_SetSpriteAttributeTable
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:226: VDP_SetSpritePatternTable(VDP_G1_ADDR_SPT);
	ld	hl, #0x3800
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:228: }
	jp	_VDP_SetSpritePatternTable
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:234: void VDP_SetModeGraphic2()
;	---------------------------------
; Function VDP_SetModeGraphic2
; ---------------------------------
_VDP_SetModeGraphic2::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:236: VDP_SetModeFlag(VDP_G2_MODE);
	ld	a, #0x04
	call	_VDP_SetModeFlag
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:237: VDP_SetLayoutTable(VDP_G2_ADDR_NT);
	ld	hl, #0x1800
	call	_VDP_SetLayoutTable
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:238: VDP_SetColorTable(VDP_G2_ADDR_CT);
	ld	hl, #0x2000
	call	_VDP_SetColorTable
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:239: VDP_SetPatternTable(VDP_G2_ADDR_PT);
	ld	hl, #0x0000
	call	_VDP_SetPatternTable
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:241: VDP_SetSpriteAttributeTable(VDP_G2_ADDR_SAT);
	ld	hl, #0x1b00
	call	_VDP_SetSpriteAttributeTable
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:242: VDP_SetSpritePatternTable(VDP_G2_ADDR_SPT);
	ld	hl, #0x3800
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:244: }
	jp	_VDP_SetSpritePatternTable
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:255: void VDP_ClearVRAM()
;	---------------------------------
; Function VDP_ClearVRAM
; ---------------------------------
_VDP_ClearVRAM::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:258: VDP_FillVRAM_16K(0, 0x0000, 0x4000);  // Clear 16 KB of VRAM
	ld	hl, #0x4000
	push	hl
	ld	de, #0x0000
	xor	a, a
	call	_VDP_FillVRAM_16K
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:265: }
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:276: void VDP_WriteVRAM_16K(const u8* src, u16 dest, u16 count) __sdcccall(0)
;	---------------------------------
; Function VDP_WriteVRAM_16K
; ---------------------------------
_VDP_WriteVRAM_16K::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:349: __endasm;
	ld	iy, #2
	add	iy, sp
	ld	a, 2(iy)
	di
	out	(0x99), a
	ld	a, 3(iy)
	and	a, #0x3F
	add	a, #0x40
	ei
	out	(0x99), a
	ld	l, 0(iy)
	ld	h, 1(iy)
	ld	e, 4(iy)
	ld	d, 5(iy)
	ld	c, #0x98
	ld	b, e
	dec	de
	inc	d
	 wrt16_loop_start:
	outi
	jp	nz, wrt16_loop_start
	dec	d
	jp	nz, wrt16_loop_start
	 wrt16_loop_end:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:350: }
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:359: void VDP_FillVRAM_16K(u8 value, u16 dest, u16 count) __naked // Stack: 4 bytes
;	---------------------------------
; Function VDP_FillVRAM_16K
; ---------------------------------
_VDP_FillVRAM_16K::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:406: __endasm;
	ld	c, a
	ld	a, e
	di
	out	(0x99), a
	ld	a, d
	and	a, #0x3F
	or	a, #0x40
	out	(0x99), a
	pop	iy
	pop	de
	ld	a, c
	ld	b, e
	dec	de
	inc	d
	 fll16_loop_start:
	out	(0x98), a
	djnz	fll16_loop_start
	dec	d
	jp	nz, fll16_loop_start
	 fll16_loop_end:
	ei
	jp	(iy)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:407: }
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:520: void VDP_ReadVRAM_16K(u16 src, u8* dest, u16 count) __sdcccall(0)
;	---------------------------------
; Function VDP_ReadVRAM_16K
; ---------------------------------
_VDP_ReadVRAM_16K::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:592: __endasm;
	ld	iy, #2
	add	iy, sp
	ld	a, 0(iy)
	di
	out	(0x99), a
	ld	a, 1(iy)
	and	a, #0x3F
	ei
	out	(0x99), a
	ld	l, 2(iy)
	ld	h, 3(iy)
	ld	e, 4(iy)
	ld	d, 5(iy)
	ld	c, #0x98
	ld	b, e
	dec	de
	inc	d
	 rd16_loop_start:
	ini
	jp	nz, rd16_loop_start
	dec	d
	jp	nz, rd16_loop_start
	 rd16_loop_end:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:593: }
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:603: u8 VDP_Peek_16K(u16 dest) __PRESERVES(b, c, d, e, iyl, iyh)
;	---------------------------------
; Function VDP_Peek_16K
; ---------------------------------
_VDP_Peek_16K::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:638: __endasm;
	ld	a, l
	di
	out	(0x99), a
	ld	a, h
	and	a, #0x3F
	out	(0x99), a
	add	hl, hl
	ei
	in	a, (0x98)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:639: }
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:647: void VDP_Poke_16K(u8 val, u16 dest) __PRESERVES(c, h, l, iyl, iyh)
;	---------------------------------
; Function VDP_Poke_16K
; ---------------------------------
_VDP_Poke_16K::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:684: __endasm;
	ld	b, a
	ld	a, e
	di
	out	(0x99), a
	ld	a, d
	and	a, #0x3F
	add	a, #0x40
	out	(0x99), a
	inc	de
	ld	a, b
	ei
	out	(0x98), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:685: }
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1484: void VDP_Initialize()
;	---------------------------------
; Function VDP_Initialize
; ---------------------------------
_VDP_Initialize::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1492: __endasm;
	ld	hl, #0xF3DF
	ld	de, #_g_VDP_REGSAV+0
	ld	bc, #8
	ldir
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1515: g_VDPInitilized = TRUE;
	ld	hl, #_g_VDPInitilized
	ld	(hl), #0x01
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1517: }
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1525: void VDP_SetMode(const u8 mode)
;	---------------------------------
; Function VDP_SetMode
; ---------------------------------
_VDP_SetMode::
	ld	c, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1528: if(!g_VDPInitilized)
	ld	a, (_g_VDPInitilized+0)
	or	a, a
	jr	NZ, 00102$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1529: VDP_Initialize();
	push	bc
	call	_VDP_Initialize
	pop	bc
00102$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1536: g_VDP_Data.Mode = mode;
	ld	hl, #_g_VDP_Data
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1537: switch(mode)
	ld	a,c
	ld	(hl),a
	or	a, a
	jr	Z, 00103$
	ld	a, c
	dec	a
	jr	Z, 00104$
	ld	a,c
	cp	a,#0x02
	jr	Z, 00105$
	sub	a, #0x03
	jr	Z, 00106$
	jr	00113$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1544: case VDP_MODE_TEXT1:		VDP_SetModeText1(); break;
00103$:
	call	_VDP_SetModeText1
	jr	00113$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1549: case VDP_MODE_MULTICOLOR:	VDP_SetModeMultiColor(); break;
00104$:
	call	_VDP_SetModeMultiColor
	jr	00113$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1554: case VDP_MODE_GRAPHIC1:		VDP_SetModeGraphic1(); break;
00105$:
	call	_VDP_SetModeGraphic1
	jr	00113$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1559: case VDP_MODE_GRAPHIC2:		VDP_SetModeGraphic2(); break;
00106$:
	call	_VDP_SetModeGraphic2
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.h:629: inline void VDP_EnableDisplay(bool enable) { VDP_RegWriteBakMask(1, (u8)~R01_BL, enable ? R01_BL : 0); }
00113$:
	ld	a, #0x40
	push	af
	inc	sp
	ld	l, #0xbf
;	spillPairReg hl
;	spillPairReg hl
	ld	a, #0x01
	call	_VDP_RegWriteBakMask
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.h:636: inline void VDP_EnableVBlank(bool enable) { VDP_RegWriteBakMask(1, (u8)~R01_IE0, enable ? R01_IE0 : 0); }
	ld	a, #0x20
	push	af
	inc	sp
	ld	l, #0xdf
;	spillPairReg hl
;	spillPairReg hl
	ld	a, #0x01
	call	_VDP_RegWriteBakMask
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1636: VDP_EnableVBlank(TRUE);
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1659: }
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1665: u8 VDP_GetVersion() __naked
;	---------------------------------
; Function VDP_GetVersion
; ---------------------------------
_VDP_GetVersion::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1729: __endasm;
	 VDP_GetVersionAsm:
	call	VDP_IsTMS9918A
	ret	z
	ld	a, #1
	di
	out	(0x99), a
	ld	a, #(0x80 | 15)
	out	(0x99), a
	in	a, (0x99)
	and	#0b00111110
	rrca
	ex	af, af'					; '
	xor	a
	out	(0x99), a
	ld	a, #(0x80 | 15)
	ei
	out	(0x99), a
	ex	af, af'					; '
	ret	nz
	inc	a
	ret
	 VDP_IsTMS9918A:
	in	a, (0x99)
	di
	 VDP_IsTMS9918A_Wait:
	in	a,(0x99)
	and	a
	jp	p, VDP_IsTMS9918A_Wait
	ld	a, #2
	out	(0x99), a
	ld	a, #(0x80 | 15)
	out	(0x99), a
	in	a, (0x99)
	ex	af, af'					; '
	xor	a
	out	(0x99), a
	ld	a, #(0x80 | 15)
	out	(0x99), a
	ld	a, (0xF3E6)
	out	(0x99), a
	ld	a, #(0x80 | 7)
	ei
	out	(0x99), a
	ex	af, af'					; '
	and	#0b01000000
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1730: }
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1738: void VDP_RegWrite(u8 reg, u8 value) __PRESERVES(b, c, d, e, iyl, iyh)
;	---------------------------------
; Function VDP_RegWrite
; ---------------------------------
_VDP_RegWrite::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1752: __endasm;
	ld	h, a
	ld	a, l
	di
	out	(0x99), a
	ld	a, h
	add	#0x80
	ei
	out	(0x99), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1753: }
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1761: void VDP_RegWriteBak(u8 reg, u8 value) __PRESERVES(d, e, iyl, iyh)
;	---------------------------------
; Function VDP_RegWriteBak
; ---------------------------------
_VDP_RegWriteBak::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1781: __endasm;
	ld	c, a
	ld	a, l
	ld	b, #0
	ld	hl, #_g_VDP_REGSAV
	add	hl, bc
	ld	(hl), a
	di
	out	(0x99), a
	ld	a, c
	add	#0x80
	ei
	out	(0x99), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1782: }
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1791: void VDP_RegWriteBakMask(u8 reg, u8 mask, u8 flag)
;	---------------------------------
; Function VDP_RegWriteBakMask
; ---------------------------------
_VDP_RegWriteBakMask::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	c, a
	ld	e, l
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1793: u8 value = g_VDP_REGSAV[reg];
	ld	hl, #_g_VDP_REGSAV+0
	ld	b, #0x00
	add	hl, bc
	ld	a, (hl)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1794: value &= mask;
	and	a, e
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1795: value |= flag;
	or	a, 4 (ix)
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1796: VDP_RegWriteBak(reg, value);
	ld	a, c
	call	_VDP_RegWriteBak
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1797: }
	pop	ix
	pop	hl
	inc	sp
	jp	(hl)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1823: u8 VDP_ReadDefaultStatus() __PRESERVES(b, c, d, e, h, l, iyl, iyh)
;	---------------------------------
; Function VDP_ReadDefaultStatus
; ---------------------------------
_VDP_ReadDefaultStatus::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1827: __endasm;
	in	a, (0x99)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1828: }
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1845: void VDP_SetLayoutTable(VADDR addr)
;	---------------------------------
; Function VDP_SetLayoutTable
; ---------------------------------
_VDP_SetLayoutTable::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1847: g_ScreenLayoutLow = (u16)addr;
	ld	(_g_ScreenLayoutLow), hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1850: reg = (u8)(addr >> 10);
	ld	a, h
	rrca
	rrca
	and	a, #0x3f
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1871: VDP_RegWrite(2, reg);
	ld	a, #0x02
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1876: }
	jp	_VDP_RegWrite
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1880: void VDP_SetColorTable(VADDR addr)
;	---------------------------------
; Function VDP_SetColorTable
; ---------------------------------
_VDP_SetColorTable::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1882: g_ScreenColorLow = (u16)addr;
	ld	(_g_ScreenColorLow), hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1885: reg = (u8)(addr >> 6);
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	ld	c, l
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1887: switch(g_VDP_Data.Mode)
	ld	a, (#_g_VDP_Data + 0)
	sub	a, #0x03
	jr	NZ, 00102$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1896: reg |= 0b1111111;
	ld	a, c
	or	a, #0x7f
	ld	c, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1898: };	
00102$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1900: VDP_RegWrite(3, reg);
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
	ld	a, #0x03
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1908: }
	jp	_VDP_RegWrite
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1912: void VDP_SetPatternTable(VADDR addr)
;	---------------------------------
; Function VDP_SetPatternTable
; ---------------------------------
_VDP_SetPatternTable::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1914: g_ScreenPatternLow = (u16)addr;
	ld	(_g_ScreenPatternLow), hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1917: reg = (u8)(addr >> 11);
	ld	a, h
	rrca
	rrca
	rrca
	and	a, #0x1f
	ld	c, a
	ld	b, #0x00
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1919: switch(g_VDP_Data.Mode)
	ld	a, (#_g_VDP_Data + 0)
	sub	a, #0x03
	jr	NZ, 00102$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1925: reg |= 0b11;
	ld	a, c
	or	a, #0x03
	ld	c, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1926: };
00102$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1928: VDP_RegWrite(4, reg);
	ld	l, c
;	spillPairReg hl
;	spillPairReg hl
	ld	a, #0x04
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1933: }
	jp	_VDP_RegWrite
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1947: void VDP_SetSpriteAttributeTable(VADDR addr)
;	---------------------------------
; Function VDP_SetSpriteAttributeTable
; ---------------------------------
_VDP_SetSpriteAttributeTable::
	ex	de, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1949: g_SpriteAttributeLow = (u16)addr;
	ld	(_g_SpriteAttributeLow), de
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1952: reg = (u8)(addr >> 7);
	ld	l, e
;	spillPairReg hl
;	spillPairReg hl
	ld	c, d
	srl	c
	rr	l
	srl	c
	rr	l
	srl	c
	rr	l
	srl	c
	rr	l
	srl	c
	rr	l
	srl	c
	rr	l
	srl	c
	rr	l
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1970: VDP_RegWrite(5, reg);
	ld	a, #0x05
	call	_VDP_RegWrite
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1979: addr -= 0x200;
;	spillPairReg hl
;	spillPairReg hl
	ld	l, e
	ld	a,d
	add	a,#0xfe
	ld	h, a
;	spillPairReg hl
;	spillPairReg hl
	ld	(_g_SpriteColorLow), hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1980: g_SpriteColorLow = (u16)addr;
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1984: }
	ret
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1990: void VDP_SetSpritePatternTable(VADDR addr)
;	---------------------------------
; Function VDP_SetSpritePatternTable
; ---------------------------------
_VDP_SetSpritePatternTable::
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1992: g_SpritePatternLow  = (u16)addr;
	ld	(_g_SpritePatternLow), hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1997: u8 reg = (u8)(addr >> 11);
	ld	a, h
	rrca
	rrca
	rrca
	and	a, #0x1f
	ld	l, a
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:1998: VDP_RegWrite(6, reg);
	ld	a, #0x06
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2000: }
	jp	_VDP_RegWrite
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2004: void VDP_LoadSpritePattern(const u8* addr, u8 index, u8 count)
;	---------------------------------
; Function VDP_LoadSpritePattern
; ---------------------------------
_VDP_LoadSpritePattern::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	c, l
	ld	b, h
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2006: u16 low = g_SpritePatternLow;
	ld	de, (_g_SpritePatternLow)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2007: low += (index * 8);
	ld	l, 4 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	ex	de, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2008: VDP_WriteVRAM(addr, low, g_SpritePatternHigh, count * 8);
	ld	l, 5 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	push	hl
	push	de
	push	bc
	call	_VDP_WriteVRAM_16K
	pop	af
	pop	af
	pop	af
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2009: }
	pop	ix
	pop	hl
	pop	af
	jp	(hl)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2013: void VDP_SetSpriteSM1(u8 index, u8 x, u8 y, u8 shape, u8 color)
;	---------------------------------
; Function VDP_SetSpriteSM1
; ---------------------------------
_VDP_SetSpriteSM1::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	e, a
	ld	c, l
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2015: g_VDP_Sprite.Y = y;				// Y coordinate on screen (all lower priority sprite will be disable if equal to 216 or 0xD0)
	ld	hl, #_g_VDP_Sprite
	ld	a, 4 (ix)
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2016: g_VDP_Sprite.X = x;				// X coordinate of the sprite
	ld	hl, #(_g_VDP_Sprite + 1)
	ld	(hl), c
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2017: g_VDP_Sprite.Pattern = shape;	// Pattern index
	ld	hl, #(_g_VDP_Sprite + 2)
	ld	a, 5 (ix)
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2018: g_VDP_Sprite.Color = color;		// Color index (Sprite Mode 1 only) + Early clock
	ld	hl, #(_g_VDP_Sprite + 3)
	ld	a, 6 (ix)
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2020: u16 low = g_SpriteAttributeLow;
	ld	bc, (_g_SpriteAttributeLow)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2021: low += (index * 4);
	ld	l, e
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2022: VDP_WriteVRAM((u8*)&g_VDP_Sprite, low, g_SpriteAtributeHigh, 4);
	ld	de, #0x0004
	push	de
	push	hl
	ld	hl, #_g_VDP_Sprite
	push	hl
	call	_VDP_WriteVRAM_16K
	pop	af
	pop	af
	pop	af
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2023: }
	pop	ix
	pop	hl
	pop	af
	inc	sp
	jp	(hl)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2027: void VDP_SetSprite(u8 index, u8 x, u8 y, u8 shape)
;	---------------------------------
; Function VDP_SetSprite
; ---------------------------------
_VDP_SetSprite::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	e, a
	ld	c, l
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2029: g_VDP_Sprite.Y = y;				// Y coordinate on screen (all lower priority sprite will be disable if equal to 216 or 0xD0)
	ld	hl, #_g_VDP_Sprite
	ld	a, 4 (ix)
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2030: g_VDP_Sprite.X = x;				// X coordinate of the sprite
	ld	hl, #(_g_VDP_Sprite + 1)
	ld	(hl), c
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2031: g_VDP_Sprite.Pattern = shape;	// Pattern index
	ld	hl, #(_g_VDP_Sprite + 2)
	ld	a, 5 (ix)
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2033: u16 low = g_SpriteAttributeLow;
	ld	bc, (_g_SpriteAttributeLow)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2034: low += (index * 4);
	ld	l, e
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2035: VDP_WriteVRAM((u8*)&g_VDP_Sprite, low, g_SpriteAtributeHigh, 3);
	ld	de, #0x0003
	push	de
	push	hl
	ld	hl, #_g_VDP_Sprite
	push	hl
	call	_VDP_WriteVRAM_16K
	pop	af
	pop	af
	pop	af
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2036: }
	pop	ix
	pop	hl
	pop	af
	jp	(hl)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2074: void VDP_SetSpritePosition(u8 index, u8 x, u8 y)
;	---------------------------------
; Function VDP_SetSpritePosition
; ---------------------------------
_VDP_SetSpritePosition::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	e, a
	ld	c, l
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2076: g_VDP_Sprite.Y = y;				// Y coordinate on screen (all lower priority sprite will be disable if equal to 216 or 0xD0)
	ld	hl, #_g_VDP_Sprite
	ld	a, 4 (ix)
	ld	(hl), a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2077: g_VDP_Sprite.X = x;				// X coordinate of the sprite
	ld	hl, #(_g_VDP_Sprite + 1)
	ld	(hl), c
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2079: u16 low = g_SpriteAttributeLow;
	ld	bc, (_g_SpriteAttributeLow)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2080: low += (index * 4);
	ld	l, e
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, bc
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2081: VDP_WriteVRAM((u8*)&g_VDP_Sprite, low, g_SpriteAtributeHigh, 2);
	ld	de, #0x0002
	push	de
	push	hl
	ld	hl, #_g_VDP_Sprite
	push	hl
	call	_VDP_WriteVRAM_16K
	pop	af
	pop	af
	pop	af
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2082: }
	pop	ix
	pop	hl
	inc	sp
	jp	(hl)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2086: void VDP_SetSpritePositionX(u8 index, u8 x)
;	---------------------------------
; Function VDP_SetSpritePositionX
; ---------------------------------
_VDP_SetSpritePositionX::
	ld	b, a
	ld	c, l
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2088: u16 low = g_SpriteAttributeLow;
	ld	de, (_g_SpriteAttributeLow)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2089: low += (index * 4);
	ld	l, b
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	ex	de, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2090: VDP_Poke(x, ++low, g_SpriteAtributeHigh);
	inc	de
	ld	a, c
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2091: }
	jp	_VDP_Poke_16K
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2095: void VDP_SetSpritePositionY(u8 index, u8 y)
;	---------------------------------
; Function VDP_SetSpritePositionY
; ---------------------------------
_VDP_SetSpritePositionY::
	ld	b, a
	ld	c, l
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2097: u16 low = g_SpriteAttributeLow;
	ld	de, (_g_SpriteAttributeLow)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2098: low += (index * 4);
	ld	l, b
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	ex	de, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2099: VDP_Poke(y, low, g_SpriteAtributeHigh);
	ld	a, c
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2100: }
	jp	_VDP_Poke_16K
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2104: void VDP_SetSpritePattern(u8 index, u8 shape)
;	---------------------------------
; Function VDP_SetSpritePattern
; ---------------------------------
_VDP_SetSpritePattern::
	ld	b, a
	ld	c, l
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2106: u16 low = g_SpriteAttributeLow + 2;
	ld	de, (_g_SpriteAttributeLow)
	inc	de
	inc	de
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2107: low += (index * 4);
	ld	l, b
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	ex	de, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2108: VDP_Poke(shape, low, g_SpriteAtributeHigh);
	ld	a, c
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2109: }
	jp	_VDP_Poke_16K
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2113: void VDP_SetSpriteColorSM1(u8 index, u8 color)
;	---------------------------------
; Function VDP_SetSpriteColorSM1
; ---------------------------------
_VDP_SetSpriteColorSM1::
	ld	b, a
	ld	c, l
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2115: u16 low = g_SpriteAttributeLow + 3;
	ld	de, (_g_SpriteAttributeLow)
	inc	de
	inc	de
	inc	de
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2116: low += (index * 4);
	ld	l, b
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	ex	de, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2117: VDP_Poke(color, low, g_SpriteAtributeHigh);
	ld	a, c
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2118: }
	jp	_VDP_Poke_16K
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2151: void VDP_DisableSpritesFrom(u8 index)
;	---------------------------------
; Function VDP_DisableSpritesFrom
; ---------------------------------
_VDP_DisableSpritesFrom::
	ld	c, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2158: VDP_SetSpritePositionY(index, y);
	ld	l, #0xd0
;	spillPairReg hl
;	spillPairReg hl
	ld	a, c
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2159: }
	jp	_VDP_SetSpritePositionY
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2204: void VDP_LoadPattern_GM2(const u8* src, u8 count, u8 offset)
;	---------------------------------
; Function VDP_LoadPattern_GM2
; ---------------------------------
_VDP_LoadPattern_GM2::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	c, l
	ld	b, h
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2206: u16 dst = g_ScreenPatternLow + (offset * 8);
	ld	l, 5 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	de, (_g_ScreenPatternLow)
	add	hl, de
	ex	de, hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2207: VDP_WriteVRAM(src, dst, g_ScreenPatternHigh, count * 8);
	ld	l, 4 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	push	hl
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
	pop	hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2208: dst += 0x800;
	ld	a, d
	add	a, #0x08
	ld	d, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2209: VDP_WriteVRAM(src, dst, g_ScreenPatternHigh, count * 8);
	push	hl
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
	pop	hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2210: dst += 0x800;
	ld	a, d
	add	a, #0x08
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2211: VDP_WriteVRAM(src, dst, g_ScreenPatternHigh, count * 8);
	push	hl
	ld	d, a
	push	de
	push	bc
	call	_VDP_WriteVRAM_16K
	pop	af
	pop	af
	pop	af
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2212: }
	pop	ix
	pop	hl
	pop	af
	jp	(hl)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2216: void VDP_LoadColor_GM2(const u8* src, u8 count, u8 offset)
;	---------------------------------
; Function VDP_LoadColor_GM2
; ---------------------------------
_VDP_LoadColor_GM2::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	c, l
	ld	b, h
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2218: u16 dst = g_ScreenColorLow + (offset * 8);
	ld	l, 5 (ix)
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
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2219: VDP_WriteVRAM(src, dst, g_ScreenColorHigh, count * 8);
	ld	l, 4 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	push	hl
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
	pop	hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2220: dst += 0x800;
	ld	a, d
	add	a, #0x08
	ld	d, a
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2221: VDP_WriteVRAM(src, dst, g_ScreenColorHigh, count * 8);
	push	hl
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
	pop	hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2222: dst += 0x800;
	ld	a, d
	add	a, #0x08
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2223: VDP_WriteVRAM(src, dst, g_ScreenColorHigh, count * 8);
	push	hl
	ld	d, a
	push	de
	push	bc
	call	_VDP_WriteVRAM_16K
	pop	af
	pop	af
	pop	af
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2224: }
	pop	ix
	pop	hl
	pop	af
	jp	(hl)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2228: void VDP_WriteLayout_GM2(const u8* src, u8 dx, u8 dy, u8 nx, u8 ny)
;	---------------------------------
; Function VDP_WriteLayout_GM2
; ---------------------------------
_VDP_WriteLayout_GM2::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
	ld	c, l
	ld	b, h
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2230: u16 dst = g_ScreenLayoutLow + (dy * 32) + dx;
	ld	l, 5 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	de, (_g_ScreenLayoutLow)
	add	hl, de
	ld	e, 4 (ix)
	ld	d, #0x00
	add	hl, de
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2231: for(u8 y = 0; y < ny; ++y)
	ld	-1 (ix), #0x00
00103$:
	ld	a, -1 (ix)
	sub	a, 7 (ix)
	jr	NC, 00105$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2233: VDP_WriteVRAM(src, dst, g_ScreenLayoutHigh, nx);
	ld	e, 6 (ix)
	ld	d, #0x00
	push	hl
	push	bc
	push	de
	push	hl
	push	bc
	call	_VDP_WriteVRAM_16K
	pop	af
	pop	af
	pop	af
	pop	bc
	pop	hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2234: src += nx;
	ld	a, c
	add	a, 6 (ix)
	ld	c, a
	jr	NC, 00118$
	inc	b
00118$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2235: dst += 32;
	ld	de, #0x0020
	add	hl, de
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2231: for(u8 y = 0; y < ny; ++y)
	inc	-1 (ix)
	jr	00103$
00105$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2237: }
	inc	sp
	pop	ix
	pop	hl
	pop	af
	pop	af
	jp	(hl)
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2241: void VDP_FillLayout_GM2(u8 value, u8 dx, u8 dy, u8 nx, u8 ny)
;	---------------------------------
; Function VDP_FillLayout_GM2
; ---------------------------------
_VDP_FillLayout_GM2::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	c, a
	ld	b, l
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2243: u16 dst = g_ScreenLayoutLow + (dy * 32) + dx;
	ld	l, 4 (ix)
;	spillPairReg hl
;	spillPairReg hl
	ld	h, #0x00
;	spillPairReg hl
;	spillPairReg hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	de, (_g_ScreenLayoutLow)
	add	hl, de
	ld	e, b
	ld	d, #0x00
	add	hl, de
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2244: for(u8 y = 0; y < ny; ++y)
	ld	b, #0x00
00103$:
	ld	a, b
	sub	a, 6 (ix)
	jr	NC, 00105$
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2246: VDP_FillVRAM(value, dst, g_ScreenLayoutHigh, nx);
	ld	e, 5 (ix)
	ld	d, #0x00
	push	hl
	push	bc
	ex	de, hl
	push	hl
	ld	a, c
	call	_VDP_FillVRAM_16K
	pop	bc
	pop	hl
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2247: dst += 32;
	ld	de, #0x0020
	add	hl, de
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2244: for(u8 y = 0; y < ny; ++y)
	inc	b
	jr	00103$
00105$:
;C:\Users\socia\Documents\www\MO5\MSX\engine/src/vdp.c:2249: }
	pop	ix
	pop	hl
	pop	af
	inc	sp
	jp	(hl)
	.area _CODE
	.area _INITIALIZER
__xinit__g_VDPInitilized:
	.db #0x00	; 0
	.area _CABS (ABS)
