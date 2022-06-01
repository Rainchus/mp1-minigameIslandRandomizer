#include "types.h"

typedef u64	OSTime;
extern u32	osGetCount(void);
#define	OS_CLOCK_RATE		62500000LL
#define	OS_CPU_COUNTER		(OS_CLOCK_RATE*3/4) // 46875000
#define OS_CYCLES_TO_USEC(c)	(((u64)(c)*(1000000LL/15625LL))/(OS_CPU_COUNTER/15625LL))
#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))

extern u16 loadedMinigame;
extern void LoadOverlay(s32 overlayID);
extern u32 chosenMinigame;
extern u32 customSeed;
extern u32 rngSeed;
u8 GetRandomByte(void);
extern u32 __osVIIntrCount;
void drawDebugText(s32 xPos, s32 yPos, char* string);
void mp1_sprintf(char* dest, char* source, ...);
s32 drawBox(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

typedef struct playerMain {
/* 0x00 */ char unk_00;
/* 0x01 */ u8 cpuDifficulty;
/* 0x02 */ u8 cpuDifficultyCopy;
/* 0x03 */ u8 flags; //including CPU flag
/* 0x04 */ u8 characterID;
/* 0x05 */ char unk_05;
/* 0x06 */ u16 unk_06;
/* 0x08 */ u16 coinAmount;
/* 0x0A */ s16 miniGameCoins; //coins to give to player after minigame
/* 0x0C */ u16 starAmount;
/* 0x0E */ u16 curChainIndex;
/* 0x10 */ u16 curSpaceIndex;
/* 0x12 */ u16 nextChainIndex;
/* 0x14 */ u16 nextSpaceIndex;
/* 0x16 */ u8 poisonedFlag;
/* 0x17 */ u8 turn_status; //space type player landed on
/* 0x18 */ u8 playerIndex; //0, 1, 2, or 3
/* 0x19 */ char unk_19[3]; //likely padding
/* 0x1C */ void* unk_1C; //some heap instance
/* 0x20 */ void* playerObj; //ptr to playerObj on heap
/* 0x24 */ u16 totalMinigameCoins;
/* 0x26 */ u16 totalCoins;
/* 0x28 */ u8 happeningSpacesTotal;
/* 0x29 */ u8 redSpacesTotal;
/* 0x2A */ u8 blueSpacesTotal;
/* 0x2B */ u8 minigameSpacesTotal;
/* 0x2C */ u8 chanceSpacesTotal;
/* 0x2D */ u8 mushroomSpacesTotal;
/* 0x2E */ u8 bowserSpacesTotal;
/* 0x2F */ char unk_2F;
} playerMain; //sizeof 0x30
//P1 800F32B0, P2 800F32E0, P3 800F3310, P4 800F3340

playerMain* player1 = (playerMain*)0x800F32B0;