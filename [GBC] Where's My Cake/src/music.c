
#include <gb/hardware.h>

#define C	0
#define CS	1
#define D	2
#define DS	3
#define EF	3
#define E	4
#define F	5
#define FS	6
#define G	7
#define GS	8
#define A	9
#define AS	10
#define BF	10
#define B	11
#define OCTAVE	12
#define O	12
#define DN	13
#define UP	14
#define TEMPO	22
#define LENGTH	23
#define VOLUME	24
#define R	25
#define LOOP	254
#define END		255

const unsigned int notes[]={44,  156, 262, 363, 457, 547, 631, 710, 786, 854, 923, 986,1046,1102,1155,1205,1253,1297,1339,1379,1417,1452,1486,1517,1546,1575,1602,1627,1650,1673,1694,1714,1732,1750,1767,1783,1798,1812,1825,1837,1849,1860,1871,1881,1890,1899,1907,1915,1923,1930,1936,1943,1949,1954,1959,1964,1969,1974,1978,1982,1985,1988,1992,1995,1998,2001,2004,2006,2009,2011,2013,2015};
const unsigned char music1[]={TEMPO,60,VOLUME,0X8,O,4,O,DN,A,10,A,10,O,UP,D,4,D,4,D,3,E,8,F,4,A,2,A,8,A,8,B,4,B,4,O,UP,D,3,O,DN,B,8,A,2,R,6,A,8,A,8,B,4,B,4,O,UP,D,3,O,DN,B,8,A,4,FS,2,A,8,A,8,B,4,A,4,G,4,FS,4,E,3,R,6,R,10,O,DN,A,10,A,10,O,UP,D,4,D,4,D,3,E,8,F,4,A,2,A,8,A,8,B,4,B,4,O,UP,D,3,O,DN,B,8,A,2,R,6,A,8,A,8,B,4,B,4,A,4,A,8,A,8,B,4,B,4,A,4,FS,8,G,8,A,4,A,4,FS,3,G,8,FS,4,D,2,R,6,A,2,G,2,FS,8,FS,8,FS,8,FS,8,FS,4,A,8,A,8,D,8,D,8,D,4,D,4,A,8,A,8,B,4,B,4,O,UP,D,3,O,DN,B,8,B,4,A,2,A,8,A,8,G,8,G,8,G,4,G,4,G,8,G,8,FS,4,FS,4,FS,4,FS,8,G,8,A,4,A,4,E,3,G,8,FS,4,D,2,R,6,LOOP};
const unsigned char titlemusic[]={TEMPO,60,VOLUME,0x8,O,5,R,4,C,4,C,4,O,DN,B,4,O,UP,C,1,R,4,A,4,A,4,B,4,A,2,A,8,R,8,A,8,G,8,F,4,F,4,F,4,D,4,C,4,A,2,F,8,A,8,G,1,LOOP};
const unsigned char yankee_doodle[]={TEMPO,60,VOLUME,0x8,O,6,F,4,F,4,G,4,A,4,F,4,A,4,G,4,C,4,F,4,F,4,G,4,A,4,F,2,E,2,F,4,F,4,G,4,A,4,AS,4,A,4,G,4,F,4,E,4,C,4,D,4,E,4,F,2,F,2,D,3,E,8,D,4,C,4,D,4,E,4,F,2,C,3,D,8,C,4,O,DN,A,4,G,2,O,UP,C,2,D,3,E,8,D,4,C,4,D,4,E,4,F,4,D,4,C,4,F,4,E,4,G,4,F,2,F,4,R,4,LOOP};

extern unsigned char tempo,octave,length,lsb,msb,wait,volume;
extern unsigned char *song_data,*song_start;

void waitdo(){
	wait=3600/tempo/length;
}

void play_note(){
	NR22_REG=(volume<<4)|(0<<3)|(7);
	NR23_REG=lsb;
	NR24_REG=(1<<7)|msb;
	waitdo();
}

extern unsigned char a,b;
void parse_song(){
	a=*(song_data++);
	b=*(song_data++);
	if(a<OCTAVE){
		lsb=notes[(octave-3)*OCTAVE+a]&0xff;
		msb=notes[(octave-3)*OCTAVE+a]>>8;
		length=b;
		play_note();
	}else if(a==O){
		if(b==DN)octave--;
		else if(b==UP)octave++;
		else octave=b;
	}else if(a==TEMPO){
		tempo=b;
	}else if(a==VOLUME){
		volume=b;
	}else if(a==R){
		NR22_REG=0;
		length=b;
		waitdo();
	}else if(a==LOOP){
		song_data=song_start;
	}
}
