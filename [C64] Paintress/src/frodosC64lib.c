/********************************************** 
 * Frodo's C64 library 
 * Jul-2016 V1.0
 * Wilfried Elmenreich
 * Code under CC-BY-4.0 license
 * made as part of #bitbitjam3
 **********************************************/

#include "frodosC64lib.h"

/* n being the sprite number (0..7) */
void setSpriteXY(char n,int x,char y)
{
     poke(53248u+n+n+1,y);
     poke(53248u+n+n,x);
     if (x>255)
          poke(53264u,peek(53264u)|(1<<n));
     else
          poke(53264u,peek(53264u)&(0xFF - (1<<n)));     
}

void blinkwait(unsigned int seconds,unsigned char color)
{
    unsigned int i;
    for(i=0;i<seconds*1500;i++) {
            poke (53280L,0);
            poke (53280L,color);
    }
    poke (53280L,0);   
}

/* bank index from 0..3 
  * 3 $0000–$3FFF Char ROM at $1000-$1FFF
  * 2 $4000–$7FFF Char ROM inactive
  * 1 $8000–$BFFF Char ROM at $9000–$9FFF
  * 0 $C000–$FFFF Char ROM inactive **/
void setVICbank(char bank)
{
     poke(0xDD00, peek(0xDD00) & 0xFC | bank);
}

void setVICcharset(char index)
{
     poke(53272U,(peek(53272U) & 240) | (index*2));
}

void setVICscreen(unsigned int index)
{
     poke(0xD018, peek(0xD018) & 0x0F | (index*16)); //set VIC
     poke(648,index*4+(3-peek(0xDD00)&3)*64); //tell the OS where to print
}
