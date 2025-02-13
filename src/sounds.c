#include "SoundLibrary.h"

unsigned char sfx[150]= {
    SND_STEP_Vol,15,
    SND_STEP_V1AttDec,0,
    SND_STEP_V1SusRel,240,
    SND_STEP_V1Wav,33,
    SND_STEP_V1PiLow,195,
    SND_STEP_V1PiHigh,16,
    SND_STEP_Wait,32,
    SND_STEP_V1Wav,32,

    SND_STEP_V1Wav,33,
    SND_STEP_V1PiLow,195,
    SND_STEP_V1PiHigh,16,
    SND_STEP_Wait,32,
    SND_STEP_V1Wav,32,

    SND_STEP_V1Wav,33,
    SND_STEP_V1PiLow,208,
    SND_STEP_V1PiHigh,18,
    SND_STEP_Wait,32,
    SND_STEP_V1Wav,32,

    SND_STEP_V1Wav,33,
    SND_STEP_V1PiLow,30,
    SND_STEP_V1PiHigh,21,
    SND_STEP_Wait,32,
    SND_STEP_V1Wav,32,

    SND_STEP_V1Wav,33,
    SND_STEP_V1PiLow,30,
    SND_STEP_V1PiHigh,21,
    SND_STEP_Wait,32,
    SND_STEP_V1Wav,32,

    SND_STEP_V1Wav,33,
    SND_STEP_V1PiLow,208,
    SND_STEP_V1PiHigh,18,
    SND_STEP_Wait,32,
    SND_STEP_V1Wav,32,
    
    SND_STEP_V1Wav,33,
    SND_STEP_V1PiLow,142,
    SND_STEP_V1PiHigh,12,
    SND_STEP_Wait,32,
    SND_STEP_V1Wav,32,

    SND_STEP_V1Wav,33,
    SND_STEP_V1PiLow,142,
    SND_STEP_V1PiHigh,12,
    SND_STEP_Wait,32,
    SND_STEP_V1Wav,32,
    SND_STEP_End


};

unsigned char sfx2[150]= {
    SND_STEP_Vol,15,
    SND_STEP_V1AttDec,0,
    SND_STEP_V1SusRel,240,
    SND_STEP_V1Wav,33,
    SND_STEP_V1PiLow,195,
    SND_STEP_V1PiHigh,16,
    SND_STEP_Wait,32,
    SND_STEP_V1Wav,32,

    SND_STEP_V1Wav,SND_WAV_BITS_SAW,
    SND_STEP_V1PiLow,195,
    SND_STEP_V1PiHigh,16,
    SND_STEP_V2Wav,SND_WAV_BITS_SAW + SND_WAV_BITS_PULSE,
    SND_STEP_V2PiLow,195,
    SND_STEP_V2PiHigh,16,
    SND_STEP_V2Wav,SND_WAV_BITS_DISABLE,
    SND_STEP_V1Wav,SND_WAV_BITS_DISABLE,
    SND_STEP_Wait,32,

    SND_STEP_V1Wav,SND_WAV_BITS_SAW,
    SND_STEP_V1PiLow,208,
    SND_STEP_V1PiHigh,18,
    SND_STEP_V2Wav,SND_WAV_BITS_TRI,
    SND_STEP_V2PiLow,208,
    SND_STEP_V2PiHigh,18,
    SND_STEP_Wait,32,
    SND_STEP_V1Wav,SND_WAV_BITS_DISABLE,
    SND_STEP_V2Wav,SND_WAV_BITS_DISABLE + SND_WAV_BITS_PULSE,

    SND_STEP_V1Wav,SND_WAV_BITS_SAW,
    SND_STEP_V1PiLow,30,
    SND_STEP_V1PiHigh,21,
    SND_STEP_V2Wav,SND_WAV_BITS_TRI + SND_WAV_BITS_PULSE,
    SND_STEP_V2PiLow,30,
    SND_STEP_V2PiHigh,21,
    SND_STEP_Wait,32,
    SND_STEP_V1Wav,SND_WAV_BITS_DISABLE,
    SND_STEP_V2Wav,SND_WAV_BITS_DISABLE,

    SND_STEP_V1Wav,SND_WAV_BITS_SAW,
    SND_STEP_V1PiLow,30,
    SND_STEP_V1PiHigh,21,
    SND_STEP_V2Wav,SND_WAV_BITS_TRI + SND_WAV_BITS_PULSE,
    SND_STEP_V2PiLow,30,
    SND_STEP_V2PiHigh,21,
    SND_STEP_Wait,32,
    SND_STEP_V1Wav,SND_WAV_BITS_DISABLE,
    SND_STEP_V2Wav,SND_WAV_BITS_DISABLE,

    SND_STEP_V1Wav,SND_WAV_BITS_SAW,
    SND_STEP_V1PiLow,208,
    SND_STEP_V1PiHigh,18,
    SND_STEP_V2Wav,SND_WAV_BITS_TRI + SND_WAV_BITS_PULSE,
    SND_STEP_V2PiLow,208,
    SND_STEP_V2PiHigh,18,
    SND_STEP_Wait,32,
    SND_STEP_V1Wav,SND_WAV_BITS_DISABLE,
    SND_STEP_V2Wav,SND_WAV_BITS_DISABLE,
    
    SND_STEP_V1Wav,SND_WAV_BITS_SAW,
    SND_STEP_V1PiLow,142,
    SND_STEP_V1PiHigh,12,
    SND_STEP_V2Wav,SND_WAV_BITS_TRI + SND_WAV_BITS_PULSE,
    SND_STEP_V2PiLow,142,
    SND_STEP_V2PiHigh,12,
    SND_STEP_Wait,32,
    SND_STEP_V1Wav,SND_WAV_BITS_DISABLE,
    SND_STEP_V2Wav,SND_WAV_BITS_DISABLE,

    SND_STEP_V1Wav,SND_WAV_BITS_SAW,
    SND_STEP_V1PiLow,142,
    SND_STEP_V1PiHigh,12,
    SND_STEP_V2Wav,SND_WAV_BITS_SAW,
    SND_STEP_V2PiLow,142,
    SND_STEP_V2PiHigh,12,
    SND_STEP_Wait,32,
    SND_STEP_V1Wav,SND_WAV_BITS_DISABLE,
    SND_STEP_V2Wav,SND_WAV_BITS_DISABLE,
    SND_STEP_End


};

unsigned char sfx3[150]= {
    SND_STEP_Vol,15,
    SND_STEP_V1AttDec,10,
    SND_STEP_V1SusRel,0,
    SND_STEP_Count,6,
    SND_STEP_V1PiLow,40,
    SND_STEP_V1PiHigh,95,
    SND_STEP_V1Wav,SND_WAV_BITS_SAW,
    SND_STEP_Wait,64,
    SND_STEP_V1Wav,16,
    SND_STEP_V1PiLow,20,
    SND_STEP_V1PiHigh,60,
    SND_STEP_V1Wav,SND_WAV_BITS_SAW,
    SND_STEP_Wait,32,
    SND_STEP_V1Wav,16,
    SND_STEP_Repeat,20,
    SND_STEP_Count,6,
    SND_STEP_V1PiLow,20,
    SND_STEP_V1PiHigh,43,
    SND_STEP_V1Wav,SND_WAV_BITS_PULSE,
    SND_STEP_Wait,96,
    SND_STEP_V1Wav,16,
    SND_STEP_V1PiLow,34,
    SND_STEP_V1PiHigh,12,
    SND_STEP_V1Wav,SND_WAV_BITS_PULSE,
    SND_STEP_Wait,64,
    SND_STEP_V1Wav,16,
    SND_STEP_Repeat,20,    
    SND_STEP_End
};

unsigned char sxf_switch[150]= {
    SND_STEP_Vol,15,
    SND_STEP_V1Wav,SND_WAV_BITS_NOISE,
    SND_STEP_V1AttDec,SND_HIGH_03 + SND_LOW_04,
    SND_STEP_V1SusRel,SND_HIGH_05 + SND_LOW_01,
    SND_STEP_Count,3,
    SND_STEP_V1PiLow,10,
    SND_STEP_V1PiHigh,30,
    SND_STEP_Wait,32,
    SND_STEP_Repeat,6,    
    SND_STEP_End
};

unsigned char sfx_lowBeep[150]= {
    SND_STEP_Vol,15,
    SND_STEP_V1Wav,SND_WAV_BITS_SAW,
    SND_STEP_V1AttDec,SND_HIGH_03 + SND_LOW_01,
    SND_STEP_V1SusRel,SND_HIGH_10 + SND_LOW_00,
    SND_STEP_Count,3,
    SND_STEP_V1PiLow,1,
    SND_STEP_V1PiHigh,5,
    SND_STEP_Wait,32,
    SND_STEP_Repeat,6,    
    SND_STEP_End
};

unsigned char sfx_lowboop[150]= {
    SND_STEP_Vol,15,
    SND_STEP_V1Wav,SND_WAV_BITS_TRI,
    SND_STEP_V1AttDec,SND_HIGH_09 + SND_LOW_04,
    SND_STEP_V1SusRel,SND_HIGH_02 + SND_LOW_03,
    SND_STEP_Count,5,
    SND_STEP_V1PiLow,10,
    SND_STEP_V1PiHigh,15,
    SND_STEP_Wait,40,
    SND_STEP_Repeat,6,    
    SND_STEP_End
};

unsigned char sfx_buzzzap[150]= {
    SND_STEP_Vol,15,
    SND_STEP_VolumePassFilter,31,
    SND_STEP_ResonanceBits,1,
    SND_STEP_V1PlHigh,8,
    SND_STEP_V1AttDec,0,
    SND_STEP_V1SusRel,240,
    SND_STEP_V1PiHigh,10,
    SND_STEP_V1PiLow,5,
    SND_STEP_V1Wav,65,
    SND_STEP_FallValue,255,
    SND_STEP_CutoffHigh,32,
    SND_STEP_V1Wav,0,
    SND_STEP_V2Wav,0,
    SND_STEP_End
};

unsigned char sfx_dooropen[30]= {
    SND_STEP_Vol,15,
    SND_STEP_VolumePassFilter,31,
    SND_STEP_ResonanceBits,1,
    SND_STEP_V1PlHigh,8,
    SND_STEP_V1AttDec,0,
    SND_STEP_V1SusRel,240,
    SND_STEP_V1PiHigh,10,
    SND_STEP_V1PiLow,5,
    SND_STEP_V1Wav,SND_WAV_BITS_NOISE,
    SND_STEP_RiseValue,64,
    SND_STEP_CutoffLow,16,
    SND_STEP_FallValue,64,
    SND_STEP_CutoffHigh,16,
    SND_STEP_End
};

unsigned char sfx_crash[100]= {
    SND_STEP_Vol,15,
    SND_STEP_V1AttDec,0,
    SND_STEP_V1SusRel,240,
    SND_STEP_V1PiLow,1,
    SND_STEP_V1PiHigh,14,
    SND_STEP_V1Wav,129,
    SND_STEP_Wait,16,
    SND_STEP_V1Wav,128,
    SND_STEP_V1PiLow,1,
    SND_STEP_V1PiHigh,14,
    SND_STEP_V1Wav,129,
    SND_STEP_V1PiLow,1,
    SND_STEP_V1PiHigh,14,
    SND_STEP_V1Wav,129,
    SND_STEP_Wait,16,
    SND_STEP_V1Wav,128,
    SND_STEP_V1PiLow,0,
    SND_STEP_V1PiHigh,0,

    SND_STEP_End
};

unsigned char sfx_shortrumble[50]= {
    SND_STEP_Vol,15,
    SND_STEP_V1AttDec,0,
    SND_STEP_V1SusRel,140,
    SND_STEP_V1PiLow,10,
    SND_STEP_V1PiHigh,4,
    SND_STEP_V1Wav,129,
    SND_STEP_Wait,16,
    SND_STEP_V1Wav,128,
    SND_STEP_V1PiLow,10,
    SND_STEP_V1PiHigh,2,
    SND_STEP_V1Wav,129,
    SND_STEP_V1PiLow,10,
    SND_STEP_V1PiHigh,4,
    SND_STEP_V1Wav,129,
    SND_STEP_Wait,16,
    SND_STEP_V1Wav,128,
    SND_STEP_V1PiLow,0,
    SND_STEP_V1PiHigh,0,

    SND_STEP_End
};

unsigned char sfx_test[100]= {
    SND_STEP_Vol,15,
    SND_STEP_V1AttDec,0,
    SND_STEP_V1SusRel,140,
    SND_STEP_V1PiLow,10,
    SND_STEP_V1PiHigh,4,
    SND_STEP_V1Wav,129,
    SND_STEP_Wait,16,
    SND_STEP_V1Wav,128,
    SND_STEP_V1PiLow,10,
    SND_STEP_V1PiHigh,2,
    SND_STEP_V1Wav,129,
    SND_STEP_V1PiLow,10,
    SND_STEP_V1PiHigh,4,
    SND_STEP_V1Wav,129,
    SND_STEP_Wait,16,
    SND_STEP_V1Wav,128,
    SND_STEP_V1PiLow,0,
    SND_STEP_V1PiHigh,0,

    SND_STEP_End
};

