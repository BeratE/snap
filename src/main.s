.define ROM_NAME "Crimson Noir"
.include "header.inc"
.include "registers.inc"
.include "libmacro.inc"
	
.segment "RODATA"
vra_bin: .incbin "main.vra" 	; Size $1a00
cgr_bin: .incbin "main.cgr"	; Size $0020

;;;----- Game ------------------------------------------------------------------
.segment "CODE"
ResetHandler:
	init_cpu
 	clear_ppu

	lda #$E0
	sta CGDATA
	lda #$03
	sta CGDATA

 	load_vram vra_bin, $0000, #$1a00
 	load_cgrm cgr_bin, $80,   #$0020

        lda #$0f		; Release forced blanking
        sta INIDISP	

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
