;----- Assembler directives -------------------------------------------------------  
.p816 	; 65816 processor
.i16    ; X/Y are 16 bits
.a8     ; A is 8 bits
;----------------------------------------------------------------------------------
	
;----- ROM Header -----------------------------------------------------------------
; At the End of Bank 0, $40 Bytes of cartridge Information.	
.segment "HEADER"        	; +$7FC0 in file
	.byte ROM_NAME		; ROM Title

.segment "ROMINFO"      ; +$7FD5 in file
	.byte $30       ; ROM Makeup - LoROM, fast-capable
	.byte 0         ; ROM Type   - No battery RAM
	.byte $07       ; ROM Size   - 128K ROM
	.byte 0		; SRAM Size
	.byte 0,0	; Creator License ID Code
	.byte 0		; Version Number   
	.word $AAAA	; Checksum Complement
	.word $5555    	; Checksum
;---------------------------------------------------------------------------------- 

;----- Vector Table ---------------------------------------------------------------
.segment "VECTORS"
	.word 0, 0, 0, 0, 0, 0, 0, 0
	.word 0, 0, 0, 0, 0, 0, reset, 0
;---------------------------------------------------------------------------------- 

.macro	init_cpu
	clc             ; native mode
	xce
	rep #$10        ; X/Y 16-bit
	sep #$20        ; A 8-bit
.endmacro