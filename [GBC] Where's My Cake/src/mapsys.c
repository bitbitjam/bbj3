
#include "map/lv0.h"
#include "map/lv1.h"
#include "map/lv2.h"
#include "map/lv3.h"
#include "map/lv4.h"
#include "map/lv5.h"
#include "map/lv6.h"
#include "map/lv7.h"
#include "map/lv8.h"
#include "map/lv9.h"
#include "map/lv10.h"
#include "map/lv11.h"
#include "map/lv12.h"
#include "map/lv13.h"
#include "map/lv14.h"
#include "map/lv15.h"
#include "map/lv16.h"
#include "map/lv17.h"
#include "map/lv18.h"
#include "map/lv19.h"
#include "map/lv20.h"
#include "map/lv21.h"
#include "map/lv22.h"
#include "map/lv23.h"
#include "map/lv24.h"

#define LVTAB_W	2
const unsigned char *lvtab[]={
	&lv0PLN0,		&lv0PLN1,
	&lv1PLN0,		&lv1PLN1,
	&lv6PLN0,		&lv6PLN1,
	&lv7PLN0,		&lv7PLN1,
	&lv20PLN0,		&lv20PLN1,
	&lv19PLN0,		&lv19PLN1,
	&lv15PLN0,		&lv15PLN1,
	&lv18PLN0,		&lv18PLN1,
	&lv5PLN0,		&lv5PLN1,
	&lv13PLN0,		&lv13PLN1,
	&lv17PLN0,		&lv17PLN1,
	&lv21PLN0,		&lv21PLN1,
	&lv12PLN0,		&lv12PLN1,
	&lv8PLN0,		&lv8PLN1,
	&lv4PLN0,		&lv4PLN1,
	&lv3PLN0,		&lv3PLN1,
	&lv22PLN0,		&lv22PLN1,
	&lv23PLN0,		&lv23PLN1,
	&lv14PLN0,		&lv14PLN1,
	&lv2PLN0,		&lv2PLN1,
	&lv9PLN0,		&lv9PLN1,
	&lv16PLN0,		&lv16PLN1,
	&lv11PLN0,		&lv11PLN1,
	&lv10PLN0,		&lv10PLN1,
	&lv24PLN0,		&lv24PLN1,
};

#define LVINF_W	4
const unsigned char lvinf[]={
	3,	lv0Width,lv0Height,		0,	//0
	3,	lv1Width,lv1Height,		0,	//1
	3,	lv6Width,lv6Height,		0,	//6
	3,	lv7Width,lv7Height,		0,	//7
	1,	lv20Width,lv20Height,	0,	//20
	1,	lv19Width,lv19Height,	0,	//19
	3,	lv15Width,lv15Height,	0,	//15
	3,	lv18Width,lv18Height,	0,	//18
	3,	lv5Width,lv5Height,		0,	//5
	3,	lv13Width,lv13Height,	0,	//13
	3,	lv17Width,lv17Height,	0,	//17
	1,	lv21Width,lv21Height,	0,	//21
	3,	lv12Width,lv12Height,	0,	//12
	3,	lv8Width,lv8Height,		0,	//8
	3,	lv4Width,lv4Height,		0,	//4
	3,	lv3Width,lv3Height,		0,	//3
	1,	lv22Width,lv22Height,	0,	//22
	1,	lv23Width,lv23Height,	0,	//23
	3,	lv14Width,lv14Height,	0,	//14
	3,	lv2Width,lv2Height,		0,	//2
	3,	lv9Width,lv9Height,		0,	//9
	3,	lv16Width,lv16Height,	0,	//16
	3,	lv11Width,lv11Height,	LOOP_VERT,	//11
	3,	lv10Width,lv10Height,	0,	//10
	1,	lv24Width,lv24Height,	0,	//24
	255,
};

void upd_scroll(){
	SCX_REG=(unsigned char)scrx;
	SCY_REG=(unsigned char)scry;
}

unsigned char row[32];
void map_process(){
	
	SWITCH_ROM_MBC1(1);
	init_enemies();
	k=0;
	for(j=0;j<maph;j++){
		get_bkg_tiles(0,j,mapw,1,row);
		for(i=0;i<mapw;i++){
			h=row[i]-TILESET_TILE;
			if(h==PLAYER_START_TILE){
				set_bkg_tiles(i,j,1,1,&k);
				
				px=i*8;
				py=j*8+8;
				if(canscroll){
					scrx=0;
					scry=0;
					if(px>SCR_X2){
						while(px!=80){
							if(++scrx>mapw*8-160){
								scrx=mapw*8-160;
								break;
							}
							px--;
						}
					}
					if(py>144){
						while(py!=SCR_Y){
							if(++scry>maph*8-144){
								scry=maph*8-144;
								break;
							}
							py--;
						}
					}
				}
			}else if(h>=ENEMY_SPAWN_TILE && h<ENEMY_SPAWN_TILE+0x10){
				set_bkg_tiles(i,j,1,1,&k);
				spawn_enemy(h-ENEMY_SPAWN_TILE,i,j);
			}
		}
	}
}

extern void init_osd();
void load_level(){
	
	DISPLAY_OFF;
	scrx=0;
	scry=0;
	SCX_REG=0;
	SCY_REG=0;
	
	SWITCH_ROM_MBC1(lvinf[level*LVINF_W]);
	
	map=lvtab[LVTAB_W*level];
	attrmap=lvtab[LVTAB_W*level+1];	
	
	mapw=lvinf[level*LVINF_W+1];
	maph=lvinf[level*LVINF_W+2];
	scr_loop=lvinf[level*LVINF_W+3];
	if(mapw>20 || maph>17)canscroll=1;
	else canscroll=0;
	
	
		//...
	
	for(i=0;i!=32;i++)
		row[i]=0x33;//obstacle tile
	for(i=0;i!=32;i++)
		set_bkg_tiles(0,i,32,1,&row);
	if(maph<31){
		for(i=0;i!=32;i++)
			row[i]=0x36;//spike tile
		set_bkg_tiles(0,maph,32,1,&row);
	}
	
	VBK_REG=1;
	set_bkg_tiles(0,0,mapw,maph,attrmap);
	VBK_REG=0;
	set_bkg_tiles(0,0,mapw,maph,map);
	
	map_process();
	
	game_over=0;
	level_cleared=0;
	timeleft=99;
	init_osd();
	
	SWITCH_ROM_MBC1(1);
	pstate=PS_ACTIVE;
	ptile_down();
	if(ptile_d==TT_PASS)pcanjump=0;
	else pcanjump=1;
	phflip=0;
	panim=PANIM_STAND;
	panim_t=0;
	pvy=0;
	
	set_sprite_tile(PSPR,PTILE);
	set_sprite_tile(PSPR+1,PTILE+2);
	set_sprite_prop(PSPR,PPAL);
	set_sprite_prop(PSPR+1,PPAL);
	
	DISPLAY_ON;
}
