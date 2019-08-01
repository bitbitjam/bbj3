#include "../sndsys.c"
#include "../tilesys.c"
#include "../mapsys.c"

void clearscreen(){
	for(i=0;i!=32;i++)row[i]=0;
	for(i=0;i!=32;i++)set_bkg_tiles(0,i,32,1,row);
}

#include "../chr/spr_fireball.h"
#include "../chr/spr_bear.h"
#include "../chr/spr_butt.h"
#include "../chr/spr_flame.h"
#include "../chr/spr_flower.h"
#include "../chr/spr_princess.h"

unsigned int sprites_pal[]={
	spr_princessCGBPal1c0,spr_princessCGBPal1c1,spr_princessCGBPal1c2,spr_princessCGBPal1c3,
	spr_fireballCGBPal1c0,spr_fireballCGBPal1c1,spr_fireballCGBPal1c2,spr_fireballCGBPal1c3,
	spr_flameCGBPal0c0,spr_flameCGBPal0c1,spr_flameCGBPal0c2,spr_flameCGBPal0c3,
	spr_bearCGBPal1c0,spr_bearCGBPal1c1,spr_bearCGBPal1c2,spr_bearCGBPal1c3,
	spr_buttCGBPal1c0,spr_buttCGBPal1c1,spr_buttCGBPal1c2,spr_buttCGBPal1c3,
	spr_flowerCGBPal0c0,spr_flowerCGBPal0c1,spr_flowerCGBPal0c2,spr_flowerCGBPal0c3,
	spr_buttCGBPal0c0,spr_buttCGBPal0c1,spr_buttCGBPal0c2,spr_buttCGBPal0c3,
	spr_flowerCGBPal1c0,spr_flowerCGBPal1c1,spr_flowerCGBPal1c2,spr_flowerCGBPal1c3,
};

void loadsprites(){
	set_sprite_palette(0,8,&sprites_pal);	
	SWITCH_ROM_MBC1(TILESET_BANK);
	set_sprite_data(PTILE,spr_princessLen,spr_princess);
	set_sprite_tile(PSPR,PTILE);
	set_sprite_tile(PSPR+1,PTILE+2);
	set_sprite_prop(PSPR,PPAL);
	set_sprite_prop(PSPR+1,PPAL);
	set_sprite_data(SHOT_TILE,spr_fireballLen,spr_fireball);
	for(i=0;i!=MAX_SHOT;i++){
		set_sprite_tile(SHOT_SPR+i,SHOT_TILE);
		set_sprite_prop(SHOT_SPR+i,SHOT_PAL);
		move_sprite(SHOT_SPR+i,0,0);
		sht[i]=255;
	}
	num_shot=1;
	shot_length=16;
	shot_spd=2;
	set_sprite_data(BEAR,spr_bearLen,spr_bear);
	set_sprite_data(BUTT,spr_buttLen,spr_butt);
	set_sprite_data(FLAME,spr_flameLen,spr_flame);
	set_sprite_data(FLWR,spr_flowerLen,spr_flower);
}

#include "../osd.c"
#include "../title.c"
