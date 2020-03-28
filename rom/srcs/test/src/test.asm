; Hello World
; John Harrison
; With lots o' code borrowed from all over the place
; some tutorial-like comments stolen from "hello world" by GABY

; VERSIONS
; 1.01 02/09/07
;   fixed typos and clarified a few things in the comments
; 1.00 02/02/07

; Most GameBoy assemblers (and most other assembly
; language assemblers) use a semicolon to indicate
; that everything following it on a particular line
; is to be ignored and be treated purely as comments
; rather than code.

; gbhw.inc contains the
; 'Hardware Defines' for our program. This has
; address location labels for all of the GameBoy
; Hardware I/O registers. We can 'insert' this file
; into the present EXAMPLE1.ASM file by using the
; assembler INCLUDE command:

INCLUDE "gbhw.inc" ; standard hardware definitions from devrs.com

;  Next we want to include a file that contains a font
; macro. A macro is a portion of code or data that
; gets 'inserted' into your program. At this point,
; we are not actually inserting anything but a macro
; definition into our file. Code or data isn't physically
; inserted into a program until you invoke a macro which
; we will do later. For now, we are just making the macro
; name recognizable by our program.

INCLUDE "ibmpc1.inc" ; ASCII character set from devrs.com

; We are going to keep interrupts disabled for this program.
; However, it is good practice to leave the reserved memory locations for interrupts with
; executable code. It make for a nice template as well to fill in code when we use interrupts
; in the future
SECTION	"Vblank",ROM0[$0040]
	reti
SECTION	"LCDC",ROM0[$0048]
	reti
SECTION	"Timer_Overflow",ROM0[$0050]
	reti
SECTION	"Serial",ROM0[$0058]
	reti
SECTION	"p1thru4",ROM0[$0060]
	reti

;  Next we need to include the standard GameBoy ROM header
; information that goes at location $0100 in the ROM. (The
; $ before a number indicates that the number is a hex value.)
;
;  ROM location $0100 is also the code execution starting point
; for user written programs. The standard first two commands
; are usually always a NOP (NO Operation) and then a JP (Jump)
; command. This JP command should 'jump' to the start of user
; code. It jumps over the ROM header information as well that
; is located at $104.
;
;  First, we indicate that the following code & data should
; start at address $100 by using the following SECTION assembler
; command:

SECTION	"start",ROM0[$0100]
nop
jp	begin

;  To include the standard ROM header information we
; can just use the macro ROM_HEADER. We defined this macro
; earlier when we INCLUDEd "gbhw.inc".
;
;  The ROM_NOMBC just suggests to the complier that we are
; not using a Memory Bank Controller because we don't need one
; since our ROM won't be larger than 32K bytes.
;
;  Next we indicate the cart ROM size and then the cart RAM size.
; We don't need any cart RAM for this program so we set this to 0K.

; ****************************************************************************************
; ROM HEADER and ASCII character set
; ****************************************************************************************
; ROM header
	ROM_HEADER	ROM_NOMBC, ROM_SIZE_32KBYTE, RAM_SIZE_0KBYTE

; Next we need to include some code for doing
; RAM copy, RAM fill, etc.
INCLUDE "src/memory.asm"

;  Next, let's actually include font tile data into the ROM
; that we are building. We do this by invoking the chr_IBMPC1
; macro that was defined earlier when we INCLUDEd "ibmpc1.inc".
;
;  The 1 & 8 parameters define that we want to include the
; whole IBM-PC font set and not just parts of it.
;
;  Right before invoking this macro we define the label
; TileData. Whenever a label is defined with a colon
; it is given the value of the current ROM location.
;  As a result, TileData now has a memory location value that
; is the same as the first byte of the font data that we are
; including. We shall use the label TileData as a "handle" or
; "reference" for locating our font data.

TileData:
	chr_IBMPC1	1,8 ; LOAD ENTIRE CHARACTER SET

;  The NOP and then JP located at $100 in ROM are executed
; which causes the the following code to be executed next.

; ****************************************************************************************
; Main code Initialization:
; set the stack pointer, enable interrupts, set the palette, set the screen relative to the window
; copy the ASCII character table, clear the screen
; ****************************************************************************************

begin:
	ld b, $ff

loop:
	rl b
	jr loop

done:
	jr done