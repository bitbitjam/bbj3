/**
 * dialogScreen.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef DIALOG_SCREEN_H
#define DIALOG_SCREEN_H

#include <types.h>

typedef struct DialogScreenData{
  UBYTE dialogNum;
  UBYTE dialogTime;
} DialogScreenData;

DialogScreenData dialogScreen_data;

void dialogScreen_enter();
void dialogScreen_update();
void dialogScreen_draw();

typedef struct DialogEntry{
  char * text;
  UBYTE speaker;//0 = no portraits
} DialogEntry;

#define DIALOG_LENGTH 5
#define DIALOG_SPEAKER_PALETTE 0xE4U
#define DIALOG_LISTENER_PALETTE 0x90U

DialogEntry dialog[] = {
  {"\
\n\n\
  60,000 years ago  \
during great turmoil\
\n\
 His Magesty        \
       King Simplex \
\n\
     spoke with     \
    his daughter    \
\n\
 Her Royal          \
   Highness         \
     Princess Virus \
          The First\n\n\n", 0},
  {"\
 Father,\n\
 You are weak\n\
 You are corrupt\n\
 There is no\n\
  greatness in the\n\
 Kingdom.\n\
\n\
 Your existence is\n\
  stagnant\n\
 Your soul is a\n\
  cesspool\n", 1},
  {"\
 My Daughter,\n\
 You are my\n\
  living wound\n\
 That bleeds\n\
  flowing sorrow\n\
\n\
 I am Ultimate.\n\
 The Kingdom\n\
  exists only to\n\
 Feed my HUNGER\n\n", 2},
  {"\
 I am leaving,\n\
 I will create\n\
  a Kingdom\n\
 That will span\n\
  the world. \n\
\n\
 I will be the \n\
 First to infect\n\
 To Conquer\n\
 The HUMANS\n\n", 1},
  {"\
\n\
 I will\n\
 Pull dreams\n\
  from the Heavens\n\
\n\
\n\
 And deliver them\n\
  into our Reality\n\
\n\
\n\n", 1}
};

#endif
