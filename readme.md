CC65-C64-SoundLibrary
=====================

The start of a simple sound library for the C64 compiled using CC65 and 8-bit unity.
The 8-bit unity bit is not needed here, it is just an easier environment to debug in.

The library consists of 2 simple files:

SoundLibrary.c and SoundLibrary.h

Include SoundLibrary.c in your CC65 code compilcation and reference SoundLibrary.h in your code.

You will need to refrence CC65 includes in your project (im using 8pbit-unity that does it for me) for the library to use the POKE command.

It is varaible-less, using macros and a simple funciton to reset the SID registsres.

The example has some examples:

1. zap
2. ufo
3. woosh
4. siren
5. random comp music
6. chime
7. clunk
8. high chime
9. alarm chime

Plese feel free to comment/amend and feedback.
If you come up with some nice sound effects please do share.
I will be trying to come up with some more interesting ones.

Note that unlike other C64 sound libraries this does not use interrupts.
The code is executed inline with the intention of keeping it super simple.

The .builder file is used by 8-bit unity to build the batch file that compiles the code... As mentioned above it is lazy and I might port this to work outside of that but I find it easy to use for basic projects.

Sound builder array
===================

There is support for a a simple sound player file.
It is contained in an array with the format:

SND_THING,VALUE

In the sounds.c file you can see some arrays:
unsigned char sfx3[150]= {
    SND_Vol,15,
    SND_V1AttDec,10,
    SND_V1SusRel,0,
    SND_Count,6,
...
    SND_End
};

If you call call the sound player:

SND_PLay(sfx3,200);

It will process the sound array.
The sound.c file is seperate to keep it clean.
Make sure you extern reference the array:

extern unsigned char sfx3[150];

Then it will find the reference to the sounds.c file.

So far the commands it supports are:

SND_End 0
SND_Wait 255
SND_V1Wav 1
SND_V1PiHigh 2
SND_V1PiLow 3
SND_V1PlHigh 4
SND_V1PlLow 5
SND_V1AttDec 6
SND_V1SusRel 7
SND_V2Wav 8
SND_V2PiHigh 9
SND_V2PiLow 10
SND_V2PlHigh 11
SND_V2PlLow 12
SND_V2AttDec 13
SND_V2SusRel 14
SND_V3Wav 15
SND_V3PiHigh 16
SND_V3PiLow 17
SND_V3PlHigh 18
SND_V3PlLow 19
SND_V3AttDec 20
SND_V3SusRel 21
SND_Vol 22
SND_V1Rise 23
SND_Count 24
SND_Repeat 15

All is self-explintary but of note (sorry about the pun!) are:

SND_Count
---------
Sets an internal counter

SND_Repeat
----------
Go back the specified number of steps in the array and decrements the counter.
If the counter is zero it will continune past the SND_Repeat step
Neat!



