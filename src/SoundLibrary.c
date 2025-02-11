#include "unity.h"
#include "SoundLibrary.h"

unsigned char EnvelopeHigh[16]= {0,16,32,48,64,80,96,112,128,144,160,176,192,208,224,240};
//unsigned char EnvelopeLow;


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


unsigned char SND_GetEnv(unsigned char high,unsigned char low) {
       return EnvelopeHigh[high] + low; 
}

void SND_PLay(unsigned char *arr,int size) {
    int i;
    unsigned char c,v,z,n,j;
    SND_ClearSoundRegisters();
    SND_SetVolume(15);

    i=0;
    while (i<size) {
        c=arr[i];
        if (c==SND_End) {
            break;
        }
        i++;
        v=arr[i];

        if (c==SND_Wait) { 
            for (z=0;z<255;z++) { 
                for (n=0;n<10;n++) {

                }
            }
        }
        if (c==SND_V1Wav) { SND_SetVoice1Bits(v); }
        if (c==SND_V1PiHigh) { SND_SetVoice1High(v); }
        if (c==SND_V1PiLow) { SND_SetVoice1Low(v); }
        if (c==SND_V1PlHigh) { SND_SetVoice1PulseWidthHigh(v); }
        if (c==SND_V1PlLow) { SND_SetVoice1PulseWidthLow(v); }
        if (c==SND_V1AttDec) { SND_SetVoice1AttackDecay(v); }
        if (c==SND_V1SusRel) { SND_SetVoice1SustainRelease(v); }

        if (c==SND_V2Wav) { SND_SetVoice2Bits(v); }
        if (c==SND_V2PiHigh) { SND_SetVoice2High(v); }
        if (c==SND_V2PiLow) { SND_SetVoice2Low(v); }
        if (c==SND_V2PlHigh) { SND_SetVoice2PulseWidthHigh(v); }
        if (c==SND_V2PlLow) { SND_SetVoice2PulseWidthLow(v); }
        if (c==SND_V2AttDec) { SND_SetVoice2AttackDecay(v); }
        if (c==SND_V2SusRel) { SND_SetVoice2SustainRelease(v); }

        if (c==SND_V3Wav) { SND_SetVoice3Bits(v); }
        if (c==SND_V3PiHigh) { SND_SetVoice3High(v); }
        if (c==SND_V3PiLow) { SND_SetVoice3Low(v); }
        if (c==SND_V3PlHigh) { SND_SetVoice3PulseWidthHigh(v); }
        if (c==SND_V3PlLow) { SND_SetVoice3PulseWidthLow(v); }
        if (c==SND_V3AttDec) { SND_SetVoice3AttackDecay(v); }
        if (c==SND_V3SusRel) { SND_SetVoice3SustainRelease(v); }

        if (c==SND_V1Rise) { for (z=0;z<v;z++) { SND_SetVoice1High(z) } }

        if (c==SND_Count) { 
            j=v;
          //  cprintf("Count: %i",j);     

        }

        if (c==SND_Repeat) { 
            j=j-1;
          //  cprintf("SND_Repeat: %i",j);     
            if (j==0) {
                i++;           
            //    cprintf("Repeat done");     
            } else {
                i=i-v;
            }
        }

        if (c==SND_Vol) { SND_SetVolume(v); }
        i++;
        //Debugging output
//        cprintf("c:%i / %i / %i \r\n",i,c,v);
    }
    SND_ClearSoundRegisters();
    SND_SetVolume(0);
}

