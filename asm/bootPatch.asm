//ROM 0x15070
.headersize 0x7FFFF400
.org 0x8005B6E4
LI a0, 0x1CED490 //ROM addr to read from
LUI a1, 0x8040 //RAM addr to write to
ORI a2, r0, 0x1FFF //size of DMA
JAL dmaCopy2
NOP
J DisplacedBootCode
NOP
NOP //delete this line for clarity


.headersize 0x7E712B70
.org 0x80400000
DisplacedBootCode:
//run code overwritten/skipped by hook
LUI at, 0x800E
SW s1, 0x8910 (at)
JAL mallocPerm
ADDIU a0, r0, 0x0010
ADDU s0, v0, r0
ADDU a0, s1, r0
ADDU a1, s0, r0
JAL 0x80061FE8
ADDIU a2, r0, 0x0010
J 0x8005B708
NOP

//per frame code to randomize rng
.headersize 0x7FFFF400
.org 0x8001A484
everyFrameCode:
JAL mainCFunction
NOP
J	0x8001A45C
NOP

.headersize 0x7FE1B340
.org 0x800F665C
JAL minigameChosenHook
NOP

//table of coins required to pass minigames
.headersize 0x7FDEA0A0
.org 0x800F91B0
J checkIfPlayerWonMinigame
NOP