#include "types.h"

typedef u64	OSTime;
extern u32	osGetCount(void);
#define	OS_CLOCK_RATE		62500000LL
#define	OS_CPU_COUNTER		(OS_CLOCK_RATE*3/4) // 46875000
#define OS_CYCLES_TO_USEC(c)	(((u64)(c)*(1000000LL/15625LL))/(OS_CPU_COUNTER/15625LL))
#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))

extern s16 loadedMinigame;
extern void LoadOverlay(s32 overlayID);
extern u32 chosenMinigame;
extern u32 customSeed;
extern u32 rngSeed;
u8 GetRandomByte(void);
extern u32 __osVIIntrCount;
void drawDebugText(s32 xPos, s32 yPos, char* string);
void mp1_sprintf(char* dest, char* source, ...);
s32 drawBox(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);