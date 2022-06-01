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

LoadOverlayHook:
ORI t0, r0, 0x0025 //slot car derby overlay ID
BNE t0, a0, exitOverlayHook
NOP
LI t0, chosenMinigame
LW t0, 0x0000 (t0) //load chosen minigame
ORI t1, r0, 6 //unused puzzle minigame ID
BEQL t0, t1, exitOverlayHook
ORI a0, r0, 6
ORI t1, r0, 8 //unused wiggler minigame ID
BEQL t0, t1, exitOverlayHook
ORI a0, r0, 8
//otherwise, continue as normal
exitOverlayHook:
ADDIU sp, sp, -0x20
J 0x800175C8
SW ra, 0x0018 (sp)


//per frame code to randomize rng
.headersize 0x7FFFF400
.org 0x8001A484
everyFrameCode:
JAL mainCFunction
NOP
J	0x8001A45C
NOP

.org 0x800175C0
J LoadOverlayHook
NOP

.headersize 0x7FE1B340
.org 0x800F665C
JAL minigameChosenHook
NOP

//table of coins required to pass minigames
.headersize 0x7FDEA0A0
.org 0x800F90F0
J checkIfPlayerWonMinigame
NOP
