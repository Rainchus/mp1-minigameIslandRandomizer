#include "../include/mp1.h"
#include "../include/enums.h"

//800F90F0 function checks if coin requirement was met
//800F91B0 coin requirement array

u16 validMinigameOverlayIDs[49] = {
    MEMORY_MATCH,
    SLOT_MACHINE,
    BURIED_TREASURE,
    TREASURE_DIVERS,
    SHELL_GAME,
    HOT_BOB_OMB,
    PIPE_MAZE,
    GHOST_GUESS,
    MUSICAL_MUSHROOM,
    PEDAL_POWER,
    CRAZY_CUTTER,
    FACE_LIFT,
    WHACK_A_PLANT,
    BASH_N_CASH,
    BOWL_OVER,
    GROUND_POUND,
    BALLOON_BURST,
    COIN_BLOCK_BLITZ,
    COIN_BLOCK_BASH,
    SKATEBOARD_SKAMPER,
    BOX_MOUNTAIN_MAYHEM,
    PLATFORM_PERIL,
    TEETERING_TOWER,
    MUSHROOM_MIXUP,
    HAMMER_DROP,
    GRAB_BAG,
    BOBSLED_RUN,
    BUMPER_BALLS,
    TIGHTROPE_TREACHERY,
    KNOCK_BLOCK_TOWER,
    TIPSY_TOURNEY,
    BOMBS_AWAY,
    CRANE_GAME,
    FLOWER_SHOWER,
    SLOT_CAR_DERBY,
    MARIO_BANDSTAND,
    //DESERT_DASH,
    SHY_GUY_SAYS,
    LIMBO_DANCE,
    CAST_AWAYS,
    KEY_PA_WAY,
    RUNNING_OF_THE_BULB,
    HOT_ROPE_JUMP,
    HANDCAR_HAVOC,
    DEEP_SEA_DIVERS,
    PIRANHAS_PURSUIT,
    TUG_O_WAR,
    PADDLE_BATTLE,
    BUMPER_BALL_MAZE,
};

u16 getRandInRange(u16 arg0) { //shared overlay function
    customSeed = customSeed * 0x19971204;
    customSeed = (customSeed + 0x19760831) >> 0x10;
    if (arg0 == 0) {
        return customSeed;
    } else {
        return (customSeed % arg0);
    }
}


void advanceCustomRNG(void) {
    customSeed = customSeed * 0x41C64E6D + 0x3039;
}

u32 GetRandomByteCustom(void) {
    advanceCustomRNG();
    return customSeed;
}

u32 cBootFunction(void) { //ran once on boot, initializes variables and such
    return 1;
}

u32 mainCFunction(void) {
    advanceCustomRNG();
    return 1;
}

s32 checkIfShouldRandomizeOverlay(s32 overlayID) {
    for (s32 i = 0; i < ARRAY_COUNT(validMinigameOverlayIDs); i++) {
        if (validMinigameOverlayIDs[i] == overlayID) {
            return 1;
        }
    }
    //not found
    return 0;
}

s32 randomizeOverlay(s32 overlayID) {
    s32 result = getRandInRange(ARRAY_COUNT(validMinigameOverlayIDs));
    chosenMinigame = validMinigameOverlayIDs[result];
    return validMinigameOverlayIDs[result];
}