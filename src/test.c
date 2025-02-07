
#include "unity.h"
#include "SoundLibrary.h"
#include "test.h"

char k;
unsigned char bits;
int n,j,h,l,x,y,z,w;
int r1,r2,r3;
int f1,f2,f3;

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

    cprintf("1. zap                     a. clunk\r\n");
    cprintf("2. ufo\r\n");
    cprintf("3. woosh\r\n");
    cprintf("4. siren\r\n");
    cprintf("5. random comp music\r\n");
    cprintf("6. chime\r\n");
    cprintf("7. clunk\r\n");
    cprintf("8. high chime\r\n");
    cprintf("9. alarm chime\r\n");

    while (1) {

        k = cgetc();

        if (k=='1') { Shoot(); }
        if (k=='2') { Ufo(); }
        if (k=='3') { Woosh(); }
        if (k=='4') { Siren(); }
        if (k=='5') { CompMusic(); }
        if (k=='6') { Chime(); }
        if (k=='7') { Clunk(); }
        if (k=='8') { HighChime(); }
        if (k=='9') { AlarmChime(); }

        if (k=='t') {
            Test();
        }


    }

    return EXIT_SUCCESS;
} 

void Test() {
    ShowPlaying(k);
    SND_ClearSoundRegisters();

    SND_SetVolume(15);

    //Put testing sounds here...
    
    ClearPlaying();
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
    ShowPlaying(k);
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
    ClearPlaying();
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

void Clunk() {
    ShowPlaying(k);
    SND_SetVoice1DecayAttack(8);
    SND_SetVoice1ReleaseSustain(255);
    SND_SetVoice1Bits(21);
    SND_SetVolume(15);
    for (z=1;z<40;z++) {
        f1=20;
        for (y=1;y<3;y++) {
            f2=100;
            SND_SetVoice1High(f1);
            for (x=1;x<15;x++) {
                SND_SetVoice1ReleaseSustain(f2);
                f2=f2-10;
                f1=f1+1;
            }
        }
    }
    SND_SetVoice1Bits(0);
    SND_SetVoice1DecayAttack(0);
    ClearPlaying();
}

void Chime() {
    ShowPlaying(k);
    SND_ClearSoundRegisters();

    SND_SetVolume(15);

    SND_SetVoice1PulseWidthHigh(8);
    SND_SetVoice2PulseWidthHigh(8);
    SND_SetVoice3PulseWidthHigh(8);
    SND_SetVoice1Bits(SND_WAV_BITS_SYNC);

    SND_SetVoice1DecayAttack(2);
    SND_SetVoice1ReleaseSustain(12);
    SND_SetVoice2DecayAttack(2);
    SND_SetVoice2ReleaseSustain(12);
    SND_SetVoice3DecayAttack(2);
    SND_SetVoice3ReleaseSustain(12);

    SND_SetVoice1HighLow(16,195);
    SND_SetVoice2HighLow(21,31);
    SND_SetVoice3HighLow(25,31);

    x=100;
    for (z=1;z<30;z++) {

        SND_SetVoice1Bits(65);

        for (y=1;y<x;y++) {
        }

        SND_SetVoice2Bits(65);
        SND_SetVoice1Bits(64);

        for (y=1;y<x;y++) {
        }

        SND_SetVoice2Bits(64);
        SND_SetVoice3Bits(65);
        SND_SetVoice1Bits(64);

        for (y=1;y<x;y++) {
        }

        SND_SetVoice3Bits(64);

        x=x-5;
    }
    SND_SetVoice1Bits(0);
    SND_SetVoice1DecayAttack(0);
    ClearPlaying();
}

void HighChime() {
    ShowPlaying(k);
    SND_ClearSoundRegisters();

    SND_SetVolume(15);

    x=15;
    y=107;

    SND_SetVoice1DecayAttack(x);
    SND_SetVoice2DecayAttack(x);
    SND_SetVoice3DecayAttack(x);
    SND_SetVoice1ReleaseSustain(y);
    SND_SetVoice2ReleaseSustain(y);
    SND_SetVoice3ReleaseSustain(y);

    SND_SetVoice2LowHigh(50,40);
    SND_SetVoice1Bits(33);
    SND_SetVoice2Bits(23);
    SND_SetVoice3Bits(23);

    for (z=10;z<40;z++) {
        SND_SetVoice1High(z);
        for (j=30;j<1;j-=5) {
            SND_SetVoice2High(j);
        }
    }
    SND_SetVoice1Bits(32);
    SND_SetVoice2Bits(32);
    SND_SetVoice3Bits(32);
    ClearPlaying();
}

void AlarmChime() {
    ShowPlaying(k);
    SND_ClearSoundRegisters();

    SND_SetVolume(15);

    x=15;
    y=107;

    SND_SetVoice1DecayAttack(4);
    SND_SetVoice1ReleaseSustain(12);

    for (z=1;z<50;z++) {
        f1=rand() % 100;
        SND_SetVoice1High(z);
        SND_SetVoice1Bits(23);
        for (j=1;j<1000;j++) {
        }
        SND_SetVoice1High(f1);
        SND_SetVoice3High(140);
        SND_SetVoice1Bits(20);
        f2+=3;
    }
    
    SND_SetVoice1High(30);
    ClearPlaying();
}

void ShowPlaying(unsigned char sound) {
    gotoxy(20,0);
    cputc(sound);
}

void ClearPlaying() {
    gotoxy(20,0);
    cputc(' ');
}

//C64 text routines
void C64TextModePETSCII() {
    __asm__("lda #$15");
    __asm__("sta $D018");    
}

void C64TextModeUpperLower() {
    __asm__("lda #$17");
    __asm__("sta $D018");
}
