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
JAL cBootFunction
NOP

LUI t0, hi(everyFrameCodeJumpInstruction)
LW t0, lo(everyFrameCodeJumpInstruction) (t0)
LI t1, 0x8001A484 //end of frame hook for VI comparison (lag counter)
SW t0, 0x0000 (t1) //set hook


LUI t0, hi(loadOverlayHookJumpInstruction)
LW t0, lo(loadOverlayHookJumpInstruction) (t0)
LI t1, 0x800175C0 //loadOverlay hook
SW t0, 0x0000 (t1) //set hook
SW r0, 0x0004 (t1) //NOP after hook



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

newCoinCheck:
SLL a0, a0, 16
SRA a0, a0, 15
LUI v1, 0x8010
ADDU v1, v1, a0
LH v1, 0x91B0 (v1)
LUI v0, 0x800F
LH v0, 0x32BA (v0)
BLEZL v0, newCoinCheckZero
ADDU v0, r0, r0 //set collected coins to 0
newCoinCheckZero:
SLT v0, v0, v1
JR RA
XORI v0, v0, 0x0001


loadOverlayHookJumpInstruction:
J loadOverlayHook
NOP

loadOverlayHook:
ADDIU sp, sp, -0x30
SW ra, 0x0018 (sp)
SW a0, 0x001C (sp)
JAL checkIfShouldRandomizeOverlay //based on value in a0
NOP
BEQ v0, r0, dontRandomize
NOP
//randomize
JAL randomizeOverlay
NOP
JAL loadOverlayCustom
ADDU a0, v0, r0
BEQ r0, r0, exitRandomize
NOP
dontRandomize:
LW a0, 0x001C (sp)
JAL loadOverlayCustom
NOP
exitRandomize:
LW ra, 0x0018 (sp)
JR RA
ADDIU sp, sp, 0x30



everyFrameCodeJumpInstruction:
J everyFrameCode
NOP

everyFrameCode:
JAL mainCFunction
NOP
J	0x8001A45C
NOP

loadOverlayCustom:
ADDIU          SP, SP, -0x20
SW             RA, 0x0018 (SP)
SW             S1, 0x0014 (SP)
SW             S0, 0x0010 (SP)
SLL            V0, A0, 3
ADDU           V0, V0, A0
SLL            V0, V0, 2
LUI            A2, 0x800C
ADDU           A2, A2, V0
LW             A2, 0x1C74 (A2)
LUI            V1, 0x800C
ADDU           V1, V1, V0
LW             V1, 0x1C78 (V1)
LUI            S0, 0x800C
ADDU           S0, S0, V0
LW             S0, 0x1C90 (S0)
LUI            S1, 0x800C
ADDU           S1, S1, V0
LW             S1, 0x1C94 (S1)
ADDU           A0, A2, R0
LUI            A1, 0x800C
ADDU           A1, A1, V0
LW             A1, 0x1C7C (A1)
JAL            0x80062088 //readFromROM
SUBU           A2, V1, A2
SLTU           V0, S0, S1
BEQZ           V0, lbl_80017644
ADDU           V1, S0, R0
lbl_80017630:
SB             R0, 0x0000 (V1)
ADDIU          S0, S0, 0x0001
SLTU           V0, S0, S1
BNEZ           V0, lbl_80017630
ADDIU          V1, V1, 0x0001
lbl_80017644:
LUI            AT, 0x800C
SB             R0, 0x1C70 (AT)
LW             RA, 0x0018 (SP)
LW             S1, 0x0014 (SP)
LW             S0, 0x0010 (SP)
JR             RA
ADDIU          SP, SP, 0x20


//0x30F050
//0x800F90F0

.headersize 0x7FDEA0A0
.org 0x800F90F0
J newCoinCheck
NOP

.org 0x800F6614
LUI a0, hi(chosenMinigame)
JAL 0x800F90F0
LW a0, lo(chosenMinigame) (a0)