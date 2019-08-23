.define ROM_NAME "Crimson Noir"
.include "header.inc"
.include "registers.inc"
.include "libmacro.inc"
	
.segment "RODATA"
cgr_bin: .incbin "main.cgr"	; Size $0020
vra_bin: .incbin "main.vra" 	; Size $1a00

;;;----- Game ------------------------------------------------------------------
.segment "CODE"
ResetHandler:
	sei			; Disable Interrupts	
	init_cpu
 	clear_ppu

 	load_vram vra_bin, $0000, #$1a00
 	load_cgrm cgr_bin, $80,   #$0020

        lda #$0f		; Release forced blanking
        sta INIDISP	
	lda #$81
	sta NMITIMEN

	
GameLoop:
	jmp GameLoop
;;;-----------------------------------------------------------------------------

;;;;----- Non Maskable Interrupt -----------------------------------------------
.proc   NMIHandler
        lda RDNMI               ; read NMI status, acknowledge NMI
        ; this is where we would do graphics update

        rti
.endproc
;;;----------------------------------------------------------------------------

;;;----- Interrupt Request ----------------------------------------------------
.proc   IRQHandler
        ; code
        rti
.endproc
;;;----------------------------------------------------------------------------
