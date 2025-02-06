
#include "unity.h"
#include "SoundLibrary.h"
#include "test.h"

char k;
unsigned char bits;
int n,j,h,l;
int r1,r2,r3;

int main (void)
{

    //Pre-computing some envelop bits for later use
    bits = SND_WAV_BITS_NOISE && SND_WAV_BITS_SAW;

#if defined(__CBM__)
    C64TextModePETSCII();
#endif

    SND_ClearSoundRegisters();

    clrscr();
    cprintf("sound library test\r\n");
    cprintf("==================\r\n");

    cprintf("1. zap\r\n");
    cprintf("2. ufo\r\n");
    cprintf("3. woosh\r\n");
    cprintf("4. siren\r\n");
    cprintf("5. random comp music\r\n");

    while (1) {

        k = cgetc();

        if (k=='1') {
            Shoot();
        }
        if (k=='2') {
            Ufo();
        }
        if (k=='3') {
            Woosh();
        }
        if (k=='4') {
            Siren();
        }
        if (k=='5') {
            CompMusic();
        }

    }

    return EXIT_SUCCESS;
} 

void Shoot() {
    for (n=15;n>1;n--) {
        SND_SetVolume(n);
        SND_SetVoice1Bits(SND_WAV_BITS_NOISE);
        SND_SetVoice1DecayAttack(15);
        SND_SetVoice1HighLow(40,200);
    }
    SND_SetVoice1Bits(0);
    SND_SetVoice1DecayAttack(0);
}

void Ufo() {
    SND_SetVoice1Bits(SND_WAV_BITS_SAW);
    SND_SetVoice1DecayAttack(128);
    SND_SetVoice1ReleaseSustain(128);
    SND_SetVolume(15);
    for (n=1;n<100;n++) {
        h=n/2+30;
        l=n/2+75;
        SND_SetVoice1HighLow(h,l);
    }
    SND_SetVoice1Bits(0);
    SND_SetVoice1DecayAttack(0);
}

void Woosh() {
    SND_SetVolume(15);
    SND_SetVoice1Bits(SND_WAV_BITS_NOISE);
    SND_SetVoice1DecayAttack(128);
    SND_SetVoice1ReleaseSustain(128);
    for (n=1;n<100;n++) {
        h=n/2+100;
        l=n/2+30;
        SND_SetVoice1HighLow(h,l);
    }
    SND_SetVoice1Bits(0);
    SND_SetVolume(0);
}

void Siren() {
    SND_SetVolume(15);
    SND_SetVoice1Bits(SND_WAV_BITS_SAW);
    SND_SetVoice1DecayAttack(15);
    SND_SetVoice1ReleaseSustain(128);
    for (j=1;j<5;j++) {
        for (n=1;n<100;n++) {
            h=n/2+30;
            l=n/2+70;
            SND_SetVoice1HighLow(h,l);
        }
    }
    SND_SetVolume(0);
}

void CompMusic() {
    SND_SetVolume(15);
    SND_SetVoice1Bits(SND_WAV_BITS_TRI);
    SND_SetVoice2Bits(SND_WAV_BITS_TRI);
    SND_SetVoice3Bits(SND_WAV_BITS_SAW);
    SND_SetVoice1DecayAttack(128);
    SND_SetVoice2DecayAttack(128);
    SND_SetVoice3DecayAttack(128);
    SND_SetVoice1ReleaseSustain(128);
    SND_SetVoice2ReleaseSustain(128);
    SND_SetVoice3ReleaseSustain(128);

    for (n=1;n<100;n++) {
        r1=rand() % 35;
        r2=rand() % 35;
        r3=rand() % 35;
        SND_SetVoice1LowHigh(r1+70,r1+30);
        SND_SetVoice2LowHigh(r2+70,r2+30);
        SND_SetVoice3LowHigh(r3+70,r3+30);
        for (j=0;j<1000;j++) {

        }
    }
    SND_SetVolume(0);
    SND_SetVoice1Bits(0);
    SND_SetVoice2Bits(0);
    SND_SetVoice3Bits(0);
}

//C64 trext routines
void C64TextModePETSCII() {
    __asm__("lda #$15");
    __asm__("sta $D018");    
}

void C64TextModeUpperLower() {
    __asm__("lda #$17");
    __asm__("sta $D018");
}
