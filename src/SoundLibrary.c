#include "unity.h"
#include "SoundLibrary.h"

//=========================================================
//Sound routines
//=========================================================

//Clear all of the sound registers
void SND_ClearSoundRegisters() {
    POKE(54272,0);
    POKE(54273,0);
    POKE(54274,0);
    POKE(54275,0);
    POKE(54276,0);
    POKE(54277,0);
    POKE(54278,0);
    POKE(54279,0);
    POKE(54280,0);
    POKE(54281,0);
    POKE(54282,0);
    POKE(54283,0);
    POKE(54284,0);
    POKE(54285,0);
    POKE(54286,0);
    POKE(54287,0);
    POKE(54288,0);
    POKE(54289,0);
    POKE(54290,0);
    POKE(54291,0);
    POKE(54292,0);
    POKE(54293,0);
    POKE(54294,0);
    POKE(54295,0);
    POKE(54296,0);
}


