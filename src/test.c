
#include "unity.h"
#include "SoundLibrary.h"
#include "test.h"

char k,c;
unsigned char bits;
int n,j,h,l,x,y,z,w,i;
int r1,r2,r3;
int f1,f2,f3;
//unsigned char EnvelopeHigh[16]= {0,16,32,48,64,80,96,112,128,144,160,176,192,208,224,240};

Snd_Parameters SoundParams[3];
Snd_Parameters* params;
extern unsigned char sfx[150];
extern unsigned char sfx2[150];
extern unsigned char sfx3[150];
extern unsigned char sxf_switch[150];
extern unsigned char sfx_lowBeep[150];
extern unsigned char sfx_lowboop[150];
extern unsigned char sfx_buzzzap[150];
extern unsigned char sfx_test[150];
extern unsigned char sfx_dooropen[100];
extern unsigned char sfx_crash[100];
extern unsigned char sfx_shortrumble[50];

unsigned char textBuffer[800];

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
    cprintf("6. chime\r\n");
    cprintf("7. clunk\r\n");
    cprintf("8. high chime\r\n");
    cprintf("9. alarm chime\r\n");
    cprintf("0. nasty\r\n");
    cprintf("a. bump\r\n");
    cprintf("b. buzz\r\n");
    cprintf("c. low beep\r\n");
    cprintf("d. low boop\r\n");
    cprintf("e. buzz zap\r\n");
    cprintf("f. door open\r\n");
    cprintf("g. crash\r\n");
    cprintf("h. short rumble\r\n");
    
    while (1) {

        k = cgetc();

        ShowPlaying(k);

        if (k=='1') { Shoot(); }
        if (k=='2') { Ufo(); }
        if (k=='3') { Woosh(); }
        if (k=='4') { Siren(); }
        if (k=='5') { CompMusic(); }
        if (k=='6') { Chime(); }
        if (k=='7') { Clunk(); }
        if (k=='8') { HighChime(); }
        if (k=='9') { AlarmChime(); }
        if (k=='0') { Nasty(); }
        if (k=='a') { Bump(); }
        if (k=='b') { Bump(); }
        if (k=='c') { SND_PLay(sfx_lowBeep,200); }
        if (k=='d') { SND_PLay(sfx_lowboop,200); }
        if (k=='e') { SND_PLay(sfx_buzzzap,200); }
        if (k=='f') { SND_PLay(sfx_dooropen,200); }
        if (k=='g') { SND_PLay(sfx_crash,200); }
        if (k=='h') { SND_PLay(sfx_shortrumble,50); }

        if (k=='t') {
            SND_PLay(sfx_test,200);
        }

        ClearPlaying();

    }

    return EXIT_SUCCESS;
} 

void Test() {
   // clrscr();
   // SND_PLay(sxf_switch2,200);
}

void fgff(){
    ShowPlaying(k);
    SND_ClearSoundRegisters();

    SND_SetVolume(15);
    SND_SetVoice1PulseWidthLow(128);
    SND_SetVoice1PulseWidthHigh(8);
    SND_SetVoice2PulseWidthLow(128);
    SND_SetVoice2PulseWidthHigh(8);
    SND_SetVoice1AttackDecay(53);
    SND_SetVoice1SustainRelease(85);
    SND_SetVoice1AttackDecay(11);
    SND_SetVoice1SustainRelease(11);
    SND_SetVoice1Bits(SND_WAV_BITS_SAW);
    SND_SetVoice2Bits(SND_WAV_BITS_NOISE);
    
    for (z=1;z<20;z++) {
        for (n=1;n<100;n++) {
            SND_SetVoice1HighLow(2,n);
            SND_SetVoice2HighLow(2,n);
        }
    }

    SND_SetVoice1Bits(0);
    SND_SetVoice1AttackDecay(0);
    SND_SetVolume(0);

    ClearPlaying();
}

void Buzz() {
    SND_ClearSoundRegisters();

    SND_SetVolume(15);
    SND_SetVoice1PulseWidthLow(128);
    SND_SetVoice1PulseWidthHigh(8);
    SND_SetVoice1AttackDecay(53);
    SND_SetVoice1SustainRelease(85);
    SND_SetVoice1Bits(SND_WAV_BITS_SAW);
    
    for (z=1;z<50;z++) {
        for (n=1;n<100;n++) {
            SND_SetVoice1HighLow(2,n);
        }
    }

    SND_SetVoice1Bits(0);
    SND_SetVoice1AttackDecay(0);
    SND_SetVolume(0);

}

void Bump() {
    SND_ClearSoundRegisters();

    SND_SetVolume(15);
    SND_SetVoice1PulseWidthLow(128);
    SND_SetVoice1PulseWidthHigh(8);
    SND_SetVoice1AttackDecay(53);
    SND_SetVoice1SustainRelease(85);
    SND_SetVoice1Bits(128);
    
    for (n=500;n>1;n--) {
        SND_SetVoice1HighLow(15,210);
        SND_SetVoice1HighLow(10,50);
    }

    SND_SetVoice1Bits(0);
    SND_SetVoice1AttackDecay(0);
    SND_SetVolume(0);

}

void Nasty() {
    SND_SetVoice1Bits(SND_WAV_BITS_NOISE);
    SND_SetVoice2Bits(SND_WAV_BITS_SAW);
    SND_SetVoice1AttackDecay(15);
    SND_SetVoice2AttackDecay(116);
    for (n=15;n>1;n--) {
        SND_SetVolume(n);
        SND_SetVoice1HighLow(40,200);
        SND_SetVoice2HighLow(100,33);
    }
    SND_SetVoice1Bits(0);
    SND_SetVoice2Bits(0);
}

void Keyboard() {

    ShowPlaying(k);
    n=1;

    SND_SetVolume(15);
    clrscr();
    params = &SoundParams[0];

    printf("waveform bits:\r\n");
    scanf("%d", &i);
    if (i<128) { params->WaveformBits=i; }

    printf("attack:\r\n");
    scanf("%d", &i);
    if (i<16) { params->Attack=i; }

    printf("decay:\r\n");
    scanf("%d", &i);
    if (i<16) { params->Decay=i; }

    printf("sustain:\r\n");
    scanf("%d", &i);
    if (i<16) { params->Sustain=i; }

    printf("release:\r\n");
    scanf("%d", &i);
    if (i<16) { params->Release=i; }

    printf("putch high:\r\n");
    scanf("%d", &i);
    if (i<128) { params->PitchHigh=i; }

    printf("pitch low:\r\n");
    scanf("%d", &i);
    if (i<128) { params->PitchLow=i; }

/*
    printf("width high:\r\n");
    scanf("%d", &l);
    if (i<128) { params->WidthHigh=i; }

    printf("width low:\r\n");
    scanf("%d", &l);
    if (i<128) { params->WidthLow=i; }
*/

    cprintf("voice 1\r\n");
    i=SND_GetEnv(params->Attack,params->Decay);
    j=SND_GetEnv(params->Sustain,params->Release);

    cprintf("w:%i a:%i d:%i (%i) s:%i r:%i (%i) h:%i l:%i",params->WaveformBits,params->Attack,params->Decay,i,params->Sustain,params->Release,j,params->PitchHigh,params->PitchLow);

    SND_SetVoice1Bits(params->WaveformBits);
    SND_SetVoice1AttackDecay(i);
    SND_SetVoice1SustainRelease(j);
    SND_SetVoice1High(params->PitchHigh);
    SND_SetVoice1Low(params->PitchLow);
//    SND_SetVoice1PulseWidthHigh(params->WidthHigh);
//    SND_SetVoice1PulseWidthLow(params->WidthLow);

    SND_SetVoice1Bits(0);
    SND_SetVoice1AttackDecay(0);

    ClearPlaying();
}

void Shoot() {
    for (n=150;n>1;n--) {
        SND_SetVolume(n);
        SND_SetVoice1Bits(SND_WAV_BITS_NOISE);
        SND_SetVoice1AttackDecay(15);
        SND_SetVoice1HighLow(40,200);
    }
    SND_SetVoice1Bits(0);
    SND_SetVoice1AttackDecay(0);
}

void Ufo() {
    SND_SetVoice1Bits(SND_WAV_BITS_SAW);
    SND_SetVoice1AttackDecay(128);
    SND_SetVoice1SustainRelease(128);
    SND_SetVolume(15);
    for (n=1;n<100;n++) {
        h=n/2+30;
        l=n/2+75;
        SND_SetVoice1HighLow(h,l);
    }
    SND_SetVoice1Bits(0);
    SND_SetVoice1AttackDecay(0);
}

void Woosh() {
    SND_SetVolume(15);
    SND_SetVoice1Bits(SND_WAV_BITS_NOISE);
    SND_SetVoice1AttackDecay(128);
    SND_SetVoice1SustainRelease(128);
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
    SND_SetVoice1AttackDecay(15);
    SND_SetVoice1SustainRelease(128);
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
    SND_SetVoice1AttackDecay(128);
    SND_SetVoice2AttackDecay(128);
    SND_SetVoice3AttackDecay(128);
    SND_SetVoice1SustainRelease(128);
    SND_SetVoice2SustainRelease(128);
    SND_SetVoice3SustainRelease(128);

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
    SND_SetVoice1AttackDecay(8);
    SND_SetVoice1SustainRelease(255);
    SND_SetVoice1Bits(21);
    SND_SetVolume(15);
    for (z=1;z<40;z++) {
        f1=20;
        for (y=1;y<3;y++) {
            f2=100;
            SND_SetVoice1High(f1);
            for (x=1;x<15;x++) {
                SND_SetVoice1SustainRelease(f2);
                f2=f2-10;
                f1=f1+1;
            }
        }
    }
    SND_SetVoice1Bits(0);
    SND_SetVoice1AttackDecay(0);
    ClearPlaying();
}

void Chime() {
    SND_ClearSoundRegisters();

    SND_SetVolume(15);

    SND_SetVoice1PulseWidthHigh(8);
    SND_SetVoice2PulseWidthHigh(8);
    SND_SetVoice3PulseWidthHigh(8);
    SND_SetVoice1Bits(SND_WAV_BITS_SYNC);

    SND_SetVoice1AttackDecay(2);
    SND_SetVoice1SustainRelease(12);
    SND_SetVoice2AttackDecay(2);
    SND_SetVoice2SustainRelease(12);
    SND_SetVoice3AttackDecay(2);
    SND_SetVoice3SustainRelease(12);

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
    SND_SetVoice1AttackDecay(0);
}

void HighChime() {
    ShowPlaying(k);
    SND_ClearSoundRegisters();

    SND_SetVolume(15);

    x=15;
    y=107;

    SND_SetVoice1AttackDecay(x);
    SND_SetVoice2AttackDecay(x);
    SND_SetVoice3AttackDecay(x);
    SND_SetVoice1SustainRelease(y);
    SND_SetVoice2SustainRelease(y);
    SND_SetVoice3SustainRelease(y);

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

    SND_SetVoice1AttackDecay(4);
    SND_SetVoice1SustainRelease(12);

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
    cprintf("playing: %c",sound);
}

void ClearPlaying() {
    gotoxy(20,0);
    cprintf("          ");
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
