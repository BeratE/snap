;;; Useful macro definitions

;;; Set Debugger Breakpoint
.macro breakpoint
	.byte $42, $00          
.endmacro

;;; Initialize Registers
.macro	init_cpu
 	sei			;Disable Interrupts
	clc			; Switch to Native Mode
	xce		
	rep #$10        	; X/Y 16-bit
	sep #$20        	; A 8-bit
.endmacro

;;; Set CPU into a known State
.macro clear_ppu
	lda #$80		; Force V-Blank
 	sta $2000
	ldx #$82
@loop1:	stz $2101, x		; Clear B-BUS Registers
 	dex
	bpl @loop1
	ldx #$1F
@loop2:	stz $4200, x		; Clear CPU Registers
	dex
	bpl @loop2
.endmacro
	
;;; Load Data into VRAM
.macro load_vram src_addr, dst_addr, size
	lda #$80		; Increment VRAM by word..
	sta VMAIN
	ldy #dst_addr		; VRAM Address
	sty VMADDL
	lda #$18		; Destination VRAM Data Low in..
	sta BBAD0		; DMA Destination
	lda #$00		; Source adress bank
	sta A1B0
 	ldy #src_addr		; From source address in..
 	sty A1T0L	
	ldy size		; Number of bytes to copy..
	sty DAS0L		; Transfer size
	lda #$01		; To PPU, Increment, Word write once..
	sta DMAP0		; DMA Control
	lda #$01
	sta MDMAEN		; Start rollin'
.endmacro	

;;; Load Data into CGRAM
.macro load_cgrm src_addr, dst_addr, size
	lda #$00
	sta A1B0		; Source bank..
	ldy #src_addr		; Source in..
	sty A1T0L
	ldy size		; Transfer size..
	sty DAS0L

	lda #dst_addr
	sta CGDATA
	lda #$22		; Transfer destination..
	sta BBAD0 		; to CGDATA
	
	stz DMAP0		; Byte increment
	lda #$01
	sta MDMAEN		; Start rolin'
.endmacro
