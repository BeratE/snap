;;; Memory Mapped Input/Output Registers

;;;----- Address Bus B Registers -------------------------
;;;-------------------------------------------------------
INIDISP     = $2100     ; Screen Display
BGMODE	    = $2105	; BG Mode and Character Size

;;;----- OAM Registers ------------------------------------
OBJSEL      = $2101     ; Object Size and Character Size 
OAMADDL     = $2102     ; OAM Address Low
OAMADDH     = $2103	; OAM Address High
OAMDATA     = $2104     ; OAM Data Write
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

TM          = $212c     ; Screen Destination
TS	    = $212d	; Screen Destination

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


