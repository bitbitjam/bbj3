#ifndef _MODE_H_
#define _MODE_H_

// intro
#define delayBetweenMessages    110
#define num_screens_intro       9
#define num_strings_intro       19

SpriteDef props[3];

// prototipos
void draw1985Logo( u8 mode );
u8 recordsScreen( u8 mode );
u8 titleScreen( u8 mode, u8 *circuit );
u8 selectMode();
void disclaimerScreen( u8 mode );
u8 introScreen( u8 mode );

#endif


