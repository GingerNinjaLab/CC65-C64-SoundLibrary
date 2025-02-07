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
