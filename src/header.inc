;;;----- Assembler directives -------------------------------------------------------  
.p816 	; 65816 processor
.i16    ; X/Y are 16 bits
.a8     ; A is 8 bits
;;;----------------------------------------------------------------------------------
	
;;;----- ROM Header -----------------------------------------------------------------
.segment "HEADER"        	; +$7FC0 in file
	.byte ROM_NAME		; ROM Title

.segment "ROMINFO"      ; +$7FD5 in file
	.byte $30       ; ROM Makeup - LoROM, fast-capable
	.byte 0         ; ROM Type   - No battery RAM
	.byte $07       ; ROM Size   - 128K ROM
	.byte 0		; SRAM Size
	.byte 0		; Creator License ID Code
	.byte $33
	.byte 0		; Version Number   
	.word $0000	; Checksum Complement
	.word $0000    	; Checksum
;;;---------------------------------------------------------------------------------- 

;;;----- Interrupt and Reset vectors for the 65816 CPU ------------------------------
.segment "VECTORS"
;;; Native mode  
.addr 	$0000		; COP Co-process enable
.addr	$0000		; BRK	
.addr	$0000		; ABORT
.addr	$0000		; NMI
.addr	$0000		; RESET
.addr	$0000		; IRW
.word   $0000, $0000    ; Unused
;;;Emulation Mode
.addr 	$0000		; COP Co-process enable
.word 	$0000		; Unused
.addr	$0000		; ABORT	
.addr	NMIHandler	; NMI
.addr	ResetHandler	; RESET
.addr	$0000		; BRK/IRQ
;;;----------------------------------------------------------------------------------
