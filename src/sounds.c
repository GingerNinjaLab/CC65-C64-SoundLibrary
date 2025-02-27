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
    SND_STEP_Count,100,
    SND_STEP_V1PiLow,1,
    SND_STEP_V1PiHigh,5,
    SND_STEP_Wait,128,
    SND_STEP_Repeat,12,    
    SND_STEP_End
};

unsigned char sfx_lowboop[150]= {
    SND_STEP_Vol,15,
    SND_STEP_V1Wav,SND_WAV_BITS_TRI,
    SND_STEP_V1AttDec,SND_HIGH_09 + SND_LOW_04,
    SND_STEP_V1SusRel,SND_HIGH_02 + SND_LOW_03,
    SND_STEP_Count,100,
    SND_STEP_V1PiLow,10,
    SND_STEP_V1PiHigh,15,
    SND_STEP_Wait,128,
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

unsigned char sfx_fanfare[200]= {
    SND_STEP_V1SusRel,240,
    SND_STEP_V2PlHigh,8,
    SND_STEP_V2SusRel,240,
    SND_STEP_V2PlHigh,8,
    SND_STEP_V3SusRel,240,

    SND_STEP_V1Wav,65,
    SND_STEP_V2Wav,65,
    SND_STEP_V3Wav,65,

    SND_STEP_Vol,15,
    SND_STEP_V1PiLow,97,
    SND_STEP_V1PiHigh,56,
    SND_STEP_V2PiLow,97,
    SND_STEP_V2PiHigh,56,
    SND_STEP_V3PiLow,97,
    SND_STEP_V3PiHigh,56,
    SND_STEP_Wait,255,
    SND_STEP_Wait,255,

    SND_STEP_V1PiLow,60,
    SND_STEP_V1PiHigh,42,
    SND_STEP_V2PiLow,60,
    SND_STEP_V2PiHigh,6420,
    SND_STEP_V3PiLow,60,
    SND_STEP_V3PiHigh,60,
    SND_STEP_Wait,255,
    SND_STEP_Wait,255,
    
    SND_STEP_V1PiLow,58,
    SND_STEP_V1PiHigh,50,
    SND_STEP_V2PiLow,58,
    SND_STEP_V2PiHigh,50,
    SND_STEP_V3PiLow,58,
    SND_STEP_V3PiHigh,50,
    SND_STEP_Wait,255,
    SND_STEP_Wait,255,

    SND_STEP_V1PiLow,58,
    SND_STEP_V1PiHigh,50,
    SND_STEP_V2PiLow,100,
    SND_STEP_V2PiHigh,161,
    SND_STEP_V3PiLow,37,
    SND_STEP_V3PiHigh,161,
    SND_STEP_Wait,255,
    SND_STEP_Wait,255,

    SND_STEP_V1PiLow,37,
    SND_STEP_V1PiHigh,97,
    SND_STEP_V2PiLow,56,
    SND_STEP_V2PiHigh,100,
    SND_STEP_V3PiLow,33,
    SND_STEP_V3PiHigh,21,
    SND_STEP_Wait,255,
    SND_STEP_Wait,255,

    SND_STEP_V1PiLow,30,
    SND_STEP_V1PiHigh,21,
    SND_STEP_V2PiLow,48,
    SND_STEP_V2PiHigh,28,
    SND_STEP_V3PiLow,10,
    SND_STEP_V3PiHigh,0,
    SND_STEP_Wait,255,
    SND_STEP_Wait,255,

    SND_STEP_V1PiLow,0,
    SND_STEP_V1PiHigh,0,
    SND_STEP_V2PiLow,0,
    SND_STEP_V2PiHigh,0,
    SND_STEP_V3PiLow,0,
    SND_STEP_V3PiHigh,0,
    SND_STEP_Wait,255,
    SND_STEP_Wait,255,

    SND_STEP_V1PiLow,50,
    SND_STEP_V1PiHigh,29,
    SND_STEP_V2PiLow,25,
    SND_STEP_V2PiHigh,208,
    SND_STEP_V3PiLow,18,
    SND_STEP_V3PiHigh,208,
    SND_STEP_Wait,255,
    SND_STEP_Wait,255,

    SND_STEP_V1PiLow,18,
    SND_STEP_V1PiHigh,50,
    SND_STEP_V2PiLow,95,
    SND_STEP_V2PiHigh,22,
    SND_STEP_V3PiLow,48,
    SND_STEP_V3PiHigh,28,    
    SND_STEP_Wait,255,
    SND_STEP_Wait,255,

    SND_STEP_V1PiLow,18,
    SND_STEP_V1PiHigh,50,
    SND_STEP_V2PiLow,95,
    SND_STEP_V2PiHigh,22,
    SND_STEP_V3PiLow,48,
    SND_STEP_V3PiHigh,28,    
    SND_STEP_Wait,255,
    SND_STEP_Wait,255,

    SND_STEP_V1PiLow,95,
    SND_STEP_V1PiHigh,22,
    SND_STEP_V2PiLow,50,
    SND_STEP_V2PiHigh,134,
    SND_STEP_V3PiLow,33,
    SND_STEP_V3PiHigh,37,    

    SND_STEP_End
};

unsigned char sfx_boom[100]= {
    SND_STEP_Vol,15,
    SND_STEP_V1PiHigh,1,
    SND_STEP_V1AttDec,7,
    SND_STEP_V1Wav,80,
    SND_STEP_V1Wav,81,

    SND_STEP_End
};


unsigned char sfx_kill[70]= {
    SND_STEP_Vol,15,
    SND_STEP_V1AttDec,0,
    SND_STEP_V1SusRel,120,
    SND_STEP_V1PiLow,1,
    SND_STEP_V1PiHigh,7,
    SND_STEP_V1Wav,129,
    SND_STEP_Wait,16,
    SND_STEP_V1Wav,128,
    SND_STEP_V1PiLow,1,
    SND_STEP_V1PiHigh,7,
    SND_STEP_V1Wav,129,
    SND_STEP_V1PiLow,25,
    SND_STEP_V1PiHigh,14,
    SND_STEP_V1Wav,129,
    SND_STEP_Wait,16,
    SND_STEP_V1Wav,128,
    SND_STEP_V1PiLow,1,
    SND_STEP_V1PiHigh,14,
    SND_STEP_V1Wav,129,
    SND_STEP_V1PiLow,10,
    SND_STEP_V1PiHigh,65,
    SND_STEP_V1Wav,129,
    SND_STEP_Wait,16,
    SND_STEP_V1Wav,128,
    SND_STEP_V1PiLow,0,
    SND_STEP_V1PiHigh,0,
    SND_STEP_V1Wav,0,
    SND_STEP_End
};

