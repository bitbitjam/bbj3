
extern const int title_screen_tile_data_size;
extern const unsigned char title_screen_map_data[];
extern const unsigned char title_screen_tile_data[];

const unsigned int title_pal[]={
	chr_tilesetCGBPal0c0,chr_tilesetCGBPal0c1,chr_tilesetCGBPal0c2,chr_tilesetCGBPal0c3,
};

void ts(){
	music_init();
	song_data=&titlemusic;
	song_start=song_data;

	SWITCH_ROM_MBC1(TILESET_BANK);
	set_bkg_palette(0,1,&title_pal);
	set_bkg_data(0x0,title_screen_tile_data_size/0x10,title_screen_tile_data);
	VBK_REG=1;
	clearscreen();
	VBK_REG=0;
	set_bkg_tiles(0,0,20,18,title_screen_map_data);
	
	SCX_REG=0;
	SCY_REG=0;
	
	waitpadup();
	DISPLAY_ON;
	
	music_enable();
	while(1){
		wait_vbl_done();
		joy=joypad();
		if(joy&J_START || joy&J_A){
			break;
		}
	}
	music_disable();
	NR52_REG=0;
	
	DISPLAY_OFF;
	clearscreen();
	
	music_init();
}

#include "chr/cake_icon.c"
#include "chr/cake_map.c"
void the_end(){
	HIDE_SPRITES;
	HIDE_WIN;
	SCX_REG=0;
	SCY_REG=0;
	VBK_REG=1;
	clearscreen();
	VBK_REG=0;
	clearscreen();
	
	gotoxy(5,3);
	printf("ALL CLEAR!");
	gotoxy(5,5);
	printf("BEST SCORE");
	gotoxy(5,7);
	printf("%d00",(unsigned int)highscore);
	set_bkg_data(0x27,4,cake_icon);
	set_bkg_tiles(9,10,2,2,cake_map);
	gotoxy(1,14);
	printf("THANKS FOR PLAYING");
	
	for(i=0;i!=40;i++)move_sprite(i,0,0);
	
	music_init();
	song_data=&yankee_doodle;
	song_start=song_data;
	
	DISPLAY_ON;
	music_enable();
	while(1){
		wait_vbl_done();
		joy=joypad();
		if(joy&J_START)
			break;
	}
	music_disable();
	NR52_REG=0;
	music_init();
}
