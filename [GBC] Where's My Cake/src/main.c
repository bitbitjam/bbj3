
#include <gb/gb.h>
#include <gb/cgb.h>
#include "custom_font.c"
#include <stdio.h>
#include <gb/console.h>

#include "global.c"
#include "bank/bank0.c"

void main(){
	
	cpu_fast();	
	
	MUSIC_ON=1;
	SFX_ON=1;
	
	score=0;
	
	music_disable();
	disable_interrupts();
	add_VBL(play_music);
	enable_interrupts();
	
	SPRITES_8x16;
	
_BEGIN:
	SHOW_BKG;
	SHOW_SPRITES;
	HIDE_WIN;
	DISPLAY_OFF;
	
	music_init();	
	
	ts();
	
	load_custom_font();
	load_tileset();
	loadsprites();
	
	music_init();
	song_data=&music1;
	song_start=song_data;

	level=0;
	timeleft=99;
	highscore=0;
	pspd=1;

	i=0;
	while(1){
		if(lvinf[i*LVINF_W]==255)break;
		i++;
	}
	num_levels=i;

_METALOOP:

	music_disable();
	load_level();
	music_enable();
	
	while(1){
		lastjoy=joy;
		wait_vbl_done();
		joy=joypad();
		
		SWITCH_ROM_MBC1(1);
		
		if(pstate==PS_ACTIVE)
			p_upd();
		else if(pstate==PS_KILL){
			if(panim_t==0){
				phflip=0;
				set_sprite_prop(PSPR,FLAMEPAL);
				set_sprite_prop(PSPR+1,FLAMEPAL);
				pmovesprite();
				set_sprite_tile(PSPR,FLAME);
				set_sprite_tile(PSPR+1,FLAME+2);
			}else if(panim_t==FLAME_DELAY){
				set_sprite_tile(PSPR,FLAME+4);
				set_sprite_tile(PSPR+1,FLAME+4+2);
			}else if(panim_t==FLAME_DELAY*2){
				set_sprite_tile(PSPR,FLAME+8);
				set_sprite_tile(PSPR+1,FLAME+8+2);
			}else if(panim_t==FLAME_DELAY*3){
				set_sprite_tile(PSPR,FLAME+12);
				set_sprite_tile(PSPR+1,FLAME+12+2);
			}else if(panim_t==FLAME_DELAY*4){
				set_sprite_tile(PSPR,FLAME+16);
				set_sprite_tile(PSPR+1,FLAME+16+2);
			}else if(panim_t==FLAME_DELAY*5){
				set_sprite_tile(PSPR,FLAME+20);
				set_sprite_tile(PSPR+1,FLAME+20+2);
			}else if(panim_t==FLAME_DELAY*6){
				move_sprite(PSPR,0,0);
				move_sprite(PSPR+1,0,0);
				game_over=1;
			}
			panim_t++;
		}
		
		e_upd();
		
		if(!level_cleared){
			if(++tick==15){
				if(--timeleft==255){
					timeleft=0;
					pkill();
				}
				tick=0;
				osdd_time();
			}
		}
		if(game_over)break;
		if(level_cleared)break;
	}

	if(game_over){
		score=0;
	}
	if(level_cleared){
		while(1){
			wait_vbl_done();
			osdd_time();
			osdd_score();
			score++;
			timeleft-=2;
			sfx_score();
			if(timeleft>99)break;
		}
		level++;
	}
	if(score>highscore)highscore=score;
	DISPLAY_OFF;
	if(level<num_levels)
		goto _METALOOP;
	else{
		// THE END
		NR52_REG=0;
		the_end();
		goto _BEGIN;
	}
}
