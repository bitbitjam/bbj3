//debug
#define __SFX_ON	1
#define __MUSIC_ON	1

unsigned char MUSIC_ON,SFX_ON;

#define MUSIC_BANK	2

extern const unsigned char music1[];
extern const unsigned char titlemusic[];
extern const unsigned char yankee_doodle[];

unsigned char tempo,octave,length,lsb,msb,wait,volume;
unsigned char *song_data,*song_start;
unsigned char a,b;

extern void parse_song();

void music_init(){
	
	NR52_REG=(1<<7);
	NR50_REG=0xff;
	NR51_REG=0xff;
	
	NR21_REG=(11<6);
	NR22_REG=(volume<<4);

}
void play_music(){
#ifdef __MUSIC_ON
	if(MUSIC_ON==1){
		if(wait==0){
			SWITCH_ROM_MBC1(MUSIC_BANK);
			parse_song();
			SWITCH_ROM_MBC1(1);
		}else if(--wait==0){
			NR22_REG=0;
		}
	}
#endif
}

void music_disable(){
	
	if(MUSIC_ON==1)MUSIC_ON=2;
	
}

void music_enable(){
	
	if(MUSIC_ON==2)MUSIC_ON=1;
	
}

void sfx_shoot(){
#ifdef __SFX_ON
if(SFX_ON){
	NR41_REG=24;
	NR42_REG=(0x9<<4)|2;
	NR43_REG=(16<<4)|4;
	NR44_REG=(1<<7)|(0<<6);
}
#endif
}

void sfx_jump(){
#ifdef __SFX_ON	
if(SFX_ON){
	NR10_REG=(7<<4)|(0<<3)|(7);
	NR11_REG=(3<<6)|(0);
	NR12_REG=(0xf<<4)|(1<<3)|(7);
	NR13_REG=1546&0xff;
	NR14_REG=(1<<7)|(1<<6)|(1546>>8);	
}
#endif
}

void sfx_land(){
#ifdef __SFX_ON	
if(SFX_ON){
	if(!(NR52_REG&1)){
		NR10_REG=(7<<4)|(0<<3)|(7);
		NR11_REG=(3<<6)|(48);
		NR12_REG=(0xf<<4)|(1<<3)|(7);
		NR13_REG=1546&0xff;
		NR14_REG=(1<<7)|(1<<6);
	}
}
#endif
}

void sfx_pickup(){
#ifdef __SFX_ON
if(SFX_ON){
	NR10_REG=(7<<4)|(0<<3)|(7);
	NR11_REG=(3<<6)|(0);
	NR12_REG=(0xf<<4)|(0<<3)|(7);
	NR13_REG=1881&0xff;
	NR14_REG=(1<<7)|(1<<6)|(1881>>8);	
}
#endif
}

void sfx_kill(){
#ifdef __SFX_ON
if(SFX_ON){
	NR10_REG=(7<<4)|(1<<3)|(3);
	NR11_REG=(3<<6)|(0);
	NR12_REG=(0xf<<4)|(0<<3)|(7);
	NR13_REG=1155&0xff;
	NR14_REG=(1<<7)|(1<<6)|(1155>>8);
	
	NR41_REG=63;
}
#endif
}

void sfx_score(){
#ifdef __SFX_ON	
if(SFX_ON){
	if(!(NR52_REG&1)){
		NR10_REG=(7<<4)|(0<<3)|(7);
		NR11_REG=(3<<6)|(48);
		NR12_REG=(0xf<<4)|(1<<3)|(7);
		NR13_REG=1546&0xff;
		NR14_REG=(1<<7)|(1<<6)|(1546>>8);	
	}
}
#endif
}
