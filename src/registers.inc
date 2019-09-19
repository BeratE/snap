;;; Memory Mapped Input/Output Registers
.ifndef REGISTERS_H
.define REGISTERS_H	
.p816
	
;;;----- Address Bus B Registers -------------------------
;;;-------------------------------------------------------
INIDISP     = $2100     ; Screen Display

;;;----- OAM Registers ------------------------------------
OBJSEL      = $2101     ; Object Size and Character Size 
OAMADDL     = $2102     ; OAM Address Low
OAMADDH     = $2103	; OAM Address High
OAMDATA     = $2104     ; OAM Data Write
;;;--------------------------------------------------------

;;;----- BG Registers -------------------------------------
BGMODE	    = $2105	; BG Mode and Character Size
MOSAIC	    = $2106	; Mosaic Register
BG1SC	    = $2107	; BG 1 Tilemap Address and Size
BG2SC	    = $2108	; BG 2 Tilemap Address and Size
BG3SC	    = $2109	; BG 3 Tilemap Address and Size
BG4SC	    = $210a	; BG 4 Tilemap Address and Size
BG12NBA     = $210b	; BG 1, 2 CHR Address 
BG34NBA     = $210c	; BG 3, 4 CHR Address
BG1HOFS	    = $210d	; BG1 Horizontal Scroll Registers
BG1VOFS	    = $210e 	; BG1 Vertical Scroll Register
BG2HOFS	    = $210f	; BG2 Horizontal Scroll Registers
BG2VOFS	    = $2110 	; BG2 Vertical Scroll Register
BG3HOFS	    = $2111	; BG3 Horizontal Scroll Registers
BG3VOFS	    = $2112 	; BG3 Vertical Scroll Register
BG4HOFS	    = $2113	; BG4 Horizontal Scroll Registers
BG4VOFS	    = $2114 	; BG4 Vertical Scroll Register
;;;--------------------------------------------------------
	
;;;----- VRAM Registers -----------------------------------
VMAIN       = $2115     ; Video Port Control
VMADDL      = $2116     ; VRAM Address Low
VMADDH      = $2117	; VRAM Address High
VMDATAL     = $2118     ; VRAM Data Low
VMDATAH     = $2119     ; VRAM Data High
;;;--------------------------------------------------------

;;;----- CGRAM Registers ----------------------------------
CGADD       = $2121     ; CGRAM Address
CGDATA      = $2122     ; CGRAM DATA WRITE
;;;--------------------------------------------------------

TM          = $212c     ; Main Screen Destination
TS	    = $212d	; Sub Screen Destination

;;;----- Internal CPU Registers ---------------------------
;;;--------------------------------------------------------
NMITIMEN    = $4200     ; Interrrupt Enable
RDNMI       = $4210     ; Interrupt Flag
TIMEUP	    = $4211	; Interrupt Flag
HVBJOY      = $4212	; PPU Status

;;;----- DMA Registers ------------------------------------
DMAP0	    = $4300	; DMA Control
BBAD0 	    = $4301 	; DMA Destination ($21xx) (B Bus)
A1T0L       = $4302     ; DMA Source Address Low  (A Bus)
A1T0H       = $4303     ; DMA Source Address High (A Bus)	 	
A1B0        = $4304 	; DMA Source Address Bank (A Bus)	 	
DAS0L       = $4305 	; DMA Transfer Size Low 	 	
DAS0H       = $4306 	; DMA Transfer Size High 	 	
MDMAEN      = $420b     ; DMA Enable Register
;;;--------------------------------------------------------
.endif
