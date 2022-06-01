#include "../include/mp1.h"
#include "../include/enums.h"

//800F90F0 function checks if coin requirement was met
//800F91B0 coin requirement array

s16 coinRequirementsForWinning[] = {
0x000A, //MEMORY_MATCH
0x0000, //?
0x0001, //SLOT_MACHINE
0x000A, //BURIED_TREASURE
0x000A, //TREASURE_DIVERS
0x000A, //SHELL_GAME
0x000A, //UNUSED_MINIGAME_0 (wiggler minigame)
0x0005, //HOT_BOB_OMB
0x0000, //UNUSED_MINIGAME_1 (puzzle with colors minigame)
0x000A, //PIPE_MAZE
0x000A, //GHOST_GUESS
0x000A, //MUSICAL_MUSHROOM
0x000A, //PEDAL_POWER
0x000A, //CRAZY_CUTTER
0x000A, //FACE_LIFT
0x0019, //WHACK_A_PLANT
0x0001, //BASH_N_CASH
0x000F, //BOWL_OVER
0x000A, //GROUND_POUND
0x000A, //BALLOON_BURST
0x000A, //COIN_BLOCK_BLITZ
0x000A, //COIN_BLOCK_BASH
0x000A, //SKATEBOARD_SKAMPER
0x000A, //BOX_MOUNTAIN_MAYHEM
0x000A, //PLATFORM_PERIL
0x000A, //TEETERING_TOWER
0x000A, //MUSHROOM_MIXUP
0x0000, //HAMMER_DROP (?)
0x000F, //GRAB_BAG
0x000A, //BOBSLED_RUN
0x000A, //BUMPER_BALLS
0x000F, //TIGHTROPE_TREACHERY
0x000A, //KNOCK_BLOCK_TOWER
0x000A, //TIPSY_TOURNEY
0x000A, //BOMBS_AWAY
0x0014, //CRANE_GAME
0x0000, //FLOWER_SHOWER
0x000A, //SLOT_CAR_DERBY
0x000A, //MARIO_BANDSTAND
0x000A, //DESERT_DASH
0x000A, //SHY_GUY_SAYS
0x000A, //LIMBO_DANCE
0x000A, //?
0x001E, //CAST_AWAYS
0x000A, //KEY_PA_WAY
0x000A, //RUNNING_OF_THE_BULB
0x000A, //HOT_ROPE_JUMP
0x000A, //HANDCAR_HAVOC
0x0000, //DEEP_SEA_DIVERS
0x000F, //PIRANHAS_PURSUIT
0x000F, //TUG_O_WAR
0x000F, //PADDLE_BATTLE
0x000F, //BUMPER_BALL_MAZE
0x000F, //BUMPER_BALL_MAZE 3
0x0014, //FLOWER_SHOWER_COPY?
0x000A, //HAMMER_DROP_COPY
};

u16 validMinigameOverlayIDs[] = {
    MEMORY_MATCH,
    SLOT_MACHINE,
    BURIED_TREASURE,
    TREASURE_DIVERS,
    SHELL_GAME,
    UNUSED_MINIGAME_0,
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
    GRAB_BAG,
    BOBSLED_RUN,
    BUMPER_BALLS,
    TIGHTROPE_TREACHERY,
    KNOCK_BLOCK_TOWER,
    TIPSY_TOURNEY,
    BOMBS_AWAY,
    CRANE_GAME,
    SLOT_CAR_DERBY,
    MARIO_BANDSTAND,
    DESERT_DASH,
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
    BUMPER_BALL_MAZE_3,
    FLOWER_SHOWER_COPY,
    HAMMER_DROP_COPY,
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

u32 mainCFunction(void) {
    advanceCustomRNG();
    return 1;
}

u16 minigameChosenHook(void) {
    s32 result = getRandInRange(ARRAY_COUNT(validMinigameOverlayIDs));
    chosenMinigame = validMinigameOverlayIDs[result];
    loadedMinigame = chosenMinigame;
    return loadedMinigame;
}

s32 checkIfPlayerWonMinigame(s16 arg0) {
    return (coinRequirementsForWinning[arg0] > player1->miniGameCoins) ^ 1;
}