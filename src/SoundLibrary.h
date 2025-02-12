typedef struct {
	unsigned int PitchLow;
	unsigned int PitchHigh;
	unsigned int WidthLow;
	unsigned int WidthHigh;
	unsigned int Attack;
	unsigned int Decay;
	unsigned int Sustain;
	unsigned int Release;
	unsigned int WaveformBits;
} Snd_Parameters;



//Sound parameters:
#define SND_PITCH_LOW_1 54272
#define SND_PITCH_HIGH_1 54273
#define SND_PULSE_WIDTH_LOW_1 54274
#define SND_PULSE_WIDTH_HIGH_1 54275
#define SND_WAV_BITS_1 54276
#define SND_DECAY_ATTACK_1 54277
#define SND_RELEASE_SUSTAIN_1 54278

#define SND_PITCH_LOW_2 54279
#define SND_PITCH_HIGH_2 54280
#define SND_PULSE_WIDTH_LOW_2 54281
#define SND_PULSE_WIDTH_HIGH_2 54282
#define SND_WAV_BITS_2 54283
#define SND_DECAY_ATTACK_2 54284
#define SND_RELEASE_SUSTAIN_2 54285

#define SND_PITCH_LOW_3 54286
#define SND_PITCH_HIGH_3 54287
#define SND_PULSE_WIDTH_LOW_3 54288
#define SND_PULSE_WIDTH_HIGH_3 54289
#define SND_WAV_BITS_3 54290
#define SND_DECAY_ATTACK_3 54291
#define SND_RELEASE_SUSTAIN_3 54292

#define SND_CUTOFF_LOW 54293
#define SND_CUTOFF_HIGH 54294
#define SND_FILER_ENABLE_RESONANCE_BITS 54295
#define SND_VOLUME_PASS_FILTER_BITS 54296
#define SND_NUMERIC_OUTPUT_3 54299
#define SND_ENVELOPE_GENERATOR 54300

#define SND_WAV_BITS_DISABLE 0b00000000
  #define SND_WAV_BITS_NOISE 0b10000001
  #define SND_WAV_BITS_PULSE 0b01000001
    #define SND_WAV_BITS_SAW 0b00100001
    #define SND_WAV_BITS_TRI 0b00010001
   #define SND_WAV_BITS_RING 0b00000101
   #define SND_WAV_BITS_SYNC 0b00000011

#define SND_LOW_00 0b00000000
#define SND_LOW_01 0b00000001
#define SND_LOW_02 0b00000010
#define SND_LOW_03 0b00000011
#define SND_LOW_04 0b00000100
#define SND_LOW_05 0b00000101
#define SND_LOW_06 0b00000110
#define SND_LOW_07 0b00000111
#define SND_LOW_08 0b00001000
#define SND_LOW_09 0b00001001
#define SND_LOW_10 0b00001010
#define SND_LOW_11 0b00001011
#define SND_LOW_12 0b00001100
#define SND_LOW_13 0b00001101
#define SND_LOW_14 0b00001110
#define SND_LOW_15 0b00001111

#define SND_HIGH_00 0b00000000
#define SND_HIGH_01 0b00010000
#define SND_HIGH_02 0b00100000
#define SND_HIGH_03 0b00110000
#define SND_HIGH_04 0b01000000
#define SND_HIGH_05 0b01010000
#define SND_HIGH_06 0b01100000
#define SND_HIGH_07 0b01110000
#define SND_HIGH_08 0b10000000
#define SND_HIGH_09 0b10010000
#define SND_HIGH_10 0b10100000
#define SND_HIGH_11 0b10110000
#define SND_HIGH_12 0b11000000
#define SND_HIGH_13 0b11010000
#define SND_HIGH_14 0b11100000
#define SND_HIGH_15 0b11110000

#define SND_SetVolume(vol); POKE(SND_VOLUME_PASS_FILTER_BITS,vol);

#define SND_SetVoice1Bits(wavbits); POKE(SND_WAV_BITS_1,wavbits);
#define SND_SetVoice1AttackDecay(AttackDecay); POKE(SND_DECAY_ATTACK_1,AttackDecay);
#define SND_SetVoice1SustainRelease(SustainRelease); POKE(SND_RELEASE_SUSTAIN_1,SustainRelease);
#define SND_SetVoice1HighLow(pitchhigh,pitchlow); POKE(SND_PITCH_HIGH_1,pitchhigh);POKE(SND_PITCH_LOW_1,pitchlow);
#define SND_SetVoice1LowHigh(pitchlow,pitchhigh); POKE(SND_PITCH_LOW_1,pitchlow);POKE(SND_PITCH_HIGH_1,pitchhigh);
#define SND_SetVoice1High(pitchhigh); POKE(SND_PITCH_HIGH_1,pitchhigh);
#define SND_SetVoice1Low(pitchlow); POKE(SND_PITCH_LOW_1,pitchlow);
#define SND_SetVoice1PulseWidthHigh(pulsehigh); POKE(SND_PULSE_WIDTH_HIGH_1,pulsehigh);
#define SND_SetVoice1PulseWidthLow(pulselow); POKE(SND_PULSE_WIDTH_LOW_1,pulselow);

#define SND_SetVoice2Bits(wavbits); POKE(SND_WAV_BITS_2,wavbits);
#define SND_SetVoice2AttackDecay(AttackDecay); POKE(SND_DECAY_ATTACK_2,AttackDecay);
#define SND_SetVoice2SustainRelease(SustainRelease); POKE(SND_RELEASE_SUSTAIN_2,SustainRelease);
#define SND_SetVoice2HighLow(pitchhigh,pitchlow); POKE(SND_PITCH_HIGH_2,pitchhigh);POKE(SND_PITCH_LOW_2,pitchlow);
#define SND_SetVoice2LowHigh(pitchlow,pitchhigh); POKE(SND_PITCH_LOW_2,pitchlow);POKE(SND_PITCH_HIGH_2,pitchhigh);
#define SND_SetVoice2High(pitchhigh); POKE(SND_PITCH_HIGH_2,pitchhigh);
#define SND_SetVoice2Low(pitchlow); POKE(SND_PITCH_LOW_2,pitchlow);
#define SND_SetVoice2PulseWidthHigh(pulsehigh); POKE(SND_PULSE_WIDTH_HIGH_2,pulsehigh);
#define SND_SetVoice2PulseWidthLow(pulselow); POKE(SND_PULSE_WIDTH_LOW_2,pulselow);

#define SND_SetVoice3Bits(wavbits); POKE(SND_WAV_BITS_3,wavbits);
#define SND_SetVoice3AttackDecay(AttackDecay); POKE(SND_DECAY_ATTACK_3,AttackDecay);
#define SND_SetVoice3SustainRelease(SustainRelease); POKE(SND_RELEASE_SUSTAIN_3,SustainRelease);
#define SND_SetVoice3HighLow(pitchhigh,pitchlow); POKE(SND_PITCH_HIGH_3,pitchhigh);POKE(SND_PITCH_LOW_3,pitchlow);
#define SND_SetVoice3LowHigh(pitchlow,pitchhigh); POKE(SND_PITCH_LOW_3,pitchlow);POKE(SND_PITCH_HIGH_3,pitchhigh);
#define SND_SetVoice3High(pitchhigh); POKE(SND_PITCH_HIGH_3,pitchhigh);
#define SND_SetVoice3Low(pitchlow); POKE(SND_PITCH_LOW_3,pitchlow);
#define SND_SetVoice3PulseWidthHigh(pulsehigh); POKE(SND_PULSE_WIDTH_HIGH_3,pulsehigh);
#define SND_SetVoice3PulseWidthLow(pulselow); POKE(SND_PULSE_WIDTH_LOW_3,pulselow);

#define SND_End 0
#define SND_Wait 255
#define SND_V1Wav 1
#define SND_V1PiHigh 2
#define SND_V1PiLow 3
#define SND_V1PlHigh 4
#define SND_V1PlLow 5
#define SND_V1AttDec 6
#define SND_V1SusRel 7
#define SND_V2Wav 8
#define SND_V2PiHigh 9
#define SND_V2PiLow 10
#define SND_V2PlHigh 11
#define SND_V2PlLow 12
#define SND_V2AttDec 13
#define SND_V2SusRel 14
#define SND_V3Wav 15
#define SND_V3PiHigh 16
#define SND_V3PiLow 17
#define SND_V3PlHigh 18
#define SND_V3PlLow 19
#define SND_V3AttDec 20
#define SND_V3SusRel 21
#define SND_Vol 22
#define SND_V1Rise 23
#define SND_Count 24
#define SND_Repeat 15


#define SND_Envelop
//=========================================================
void SND_ClearSoundRegisters();
unsigned char SND_GetEnv(unsigned char high,unsigned char low);
void SND_PLay(unsigned char *arr,int size);
//=========================================================

