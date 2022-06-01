// Tell armips' linker where the assets we declared in sm64.h are located
.definelabel dmaCopy, 0x80062088
.definelabel dmaCopy2, 0x80061FE8
.definelabel sleepVProcess, 0x800635B4
.definelabel drawDebugText, 0x800622BC
.definelabel mp1_sprintf, 0x8008C490
.definelabel mallocPerm, 0x8003B6A4
.definelabel drawBox, 0x80062364
.definelabel osGetTime, 0x80088810
.definelabel osGetCount, 0x80093780
.definelabel __osVIIntrCount, 0x800ED608
.definelabel rng_seed, 0x800C2FF4
.definelabel GetRandomByte, 0x8001758C
.definelabel rngSeed, 0x800C2FF4
.definelabel LoadOverlay, 0x800175C0
.definelabel loadedMinigame, 0x800ED5DE
.definelabel playersMain, 0x800F32B0

//choose minigame based on space value 800F665C

//800D8984 if set to 2, load minigame instantly

//custom data
.definelabel chosenMinigame, 0x803FFFF8
.definelabel customSeed, 0x803FFFFC