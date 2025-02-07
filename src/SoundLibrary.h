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


#define SND_SetVolume(vol); POKE(SND_VOLUME_PASS_FILTER_BITS,vol);

#define SND_SetVoice1Bits(wavbits); POKE(SND_WAV_BITS_1,wavbits);
#define SND_SetVoice1DecayAttack(decayattack); POKE(SND_DECAY_ATTACK_1,decayattack);
#define SND_SetVoice1ReleaseSustain(releasesustain); POKE(SND_RELEASE_SUSTAIN_1,releasesustain);
#define SND_SetVoice1HighLow(pitchhigh,pitchlow); POKE(SND_PITCH_HIGH_1,pitchhigh);POKE(SND_PITCH_LOW_1,pitchlow);
#define SND_SetVoice1LowHigh(pitchlow,pitchhigh); POKE(SND_PITCH_LOW_1,pitchlow);POKE(SND_PITCH_HIGH_1,pitchhigh);
#define SND_SetVoice1High(pitchhigh); POKE(SND_PITCH_HIGH_1,pitchhigh);
#define SND_SetVoice1Low(pitchlow); POKE(SND_PITCH_LOW_1,pitchlow);
#define SND_SetVoice1PulseWidthHigh(pulsehigh); POKE(SND_PULSE_WIDTH_HIGH_1,pulsehigh);
#define SND_SetVoice1PulseWidthLow(pulselow); POKE(SND_PULSE_WIDTH_LOW_1,pulselow);

#define SND_SetVoice2Bits(wavbits); POKE(SND_WAV_BITS_2,wavbits);
#define SND_SetVoice2DecayAttack(decayattack); POKE(SND_DECAY_ATTACK_2,decayattack);
#define SND_SetVoice2ReleaseSustain(releasesustain); POKE(SND_RELEASE_SUSTAIN_2,releasesustain);
#define SND_SetVoice2HighLow(pitchhigh,pitchlow); POKE(SND_PITCH_HIGH_2,pitchhigh);POKE(SND_PITCH_LOW_2,pitchlow);
#define SND_SetVoice2LowHigh(pitchlow,pitchhigh); POKE(SND_PITCH_LOW_2,pitchlow);POKE(SND_PITCH_HIGH_2,pitchhigh);
#define SND_SetVoice2High(pitchhigh); POKE(SND_PITCH_HIGH_2,pitchhigh);
#define SND_SetVoice2Low(pitchlow); POKE(SND_PITCH_LOW_2,pitchlow);
#define SND_SetVoice2PulseWidthHigh(pulsehigh); POKE(SND_PULSE_WIDTH_HIGH_2,pulsehigh);
#define SND_SetVoice2PulseWidthLow(pulselow); POKE(SND_PULSE_WIDTH_LOW_2,pulselow);

#define SND_SetVoice3Bits(wavbits); POKE(SND_WAV_BITS_3,wavbits);
#define SND_SetVoice3DecayAttack(decayattack); POKE(SND_DECAY_ATTACK_3,decayattack);
#define SND_SetVoice3ReleaseSustain(releasesustain); POKE(SND_RELEASE_SUSTAIN_3,releasesustain);
#define SND_SetVoice3HighLow(pitchhigh,pitchlow); POKE(SND_PITCH_HIGH_3,pitchhigh);POKE(SND_PITCH_LOW_3,pitchlow);
#define SND_SetVoice3LowHigh(pitchlow,pitchhigh); POKE(SND_PITCH_LOW_3,pitchlow);POKE(SND_PITCH_HIGH_3,pitchhigh);
#define SND_SetVoice3High(pitchhigh); POKE(SND_PITCH_HIGH_3,pitchhigh);
#define SND_SetVoice3Low(pitchlow); POKE(SND_PITCH_LOW_3,pitchlow);
#define SND_SetVoice3PulseWidthHigh(pulsehigh); POKE(SND_PULSE_WIDTH_HIGH_3,pulsehigh);
#define SND_SetVoice3PulseWidthLow(pulselow); POKE(SND_PULSE_WIDTH_LOW_3,pulselow);

//=========================================================
void SND_ClearSoundRegisters();
//=========================================================

