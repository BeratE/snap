.define ROM_NAME "Crimson Noir"
.include "header.inc"
.include "registers.inc"
.include "libmacro.inc"
	
.segment "RODATA"
cgr_bin: .incbin "main.cgr"	; Size $0020
vra_bin: .incbin "main.vra" 	; Size $1a00
map_bin: .incbin "startscreen.map"
;;;----- Game ------------------------------------------------------------------
.segment "CODE"
ResetHandler:
	sei			; Disable Interrupts	
	init_cpu
 	clear_ppu

	
 	load_vram vra_bin, $0000, #$1a00
	load_vram map_bin, $2000, #$0700
	
 	load_cgrm cgr_bin, $80,   #$0020
	load_cgrm cgr_bin, $00,	  #$0020

	breakpoint

	init_video	
	
        lda #$0f		; Release forced blanking
        sta INIDISP	
	lda #$81		; Enable NMI and Joypad Pulling
	sta NMITIMEN

	
GameLoop:
	jmp GameLoop
;;;-----------------------------------------------------------------------------

;;;;----- Non Maskable Interrupt -----------------------------------------------
.proc   NMIHandler


	lda RDNMI               ; read NMI status, acknowledge NMI
        rti
.endproc
;;;----------------------------------------------------------------------------

;;;----- Interrupt Request ----------------------------------------------------
.proc   IRQHandler
        ; code
        rti
.endproc
;;;----------------------------------------------------------------------------
