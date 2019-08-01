//archivos para recursos
//recuerde referenciar los extern tambien en data.asm

#ifndef __LIBALEX_DEFS__
#define __LIBALEX_DEFS__

//sonidos
//=============================================
	extern char __SOUNDBANK__;

	//extern char scratchsnd;
	//extern char scratchsndend;
	
	/*extern char sound_accept, sound_accept_end;
	extern char sound_cancel, sound_cancel_end;
	extern char sound_select, sound_select_end;
	extern char sound_eni_studios, sound_eni_studios_end;
	extern char sound_footstep, sound_footstep_end;
	extern char sound_jump, sound_jump_end;
	extern char sound_attack, sound_attack_end;
	extern char sound_hurt, sound_hurt_end;*/

//graficos
//=============================================
	extern char snesfont;
	extern char gfxplayer, gfxplayer_end;
	extern char palplayer;
	//Splash back
	extern char gfxsplashback, gfxsplashback_end;
	extern char mapsplashback, mapsplashback_end;
	extern char palsplashback, palsplashback_end;	
	//Title back
	extern char gfxtitleback, gfxtitleback_end;
	extern char maptitleback, maptitleback_end;
	extern char paltitleback, paltitleback_end;
	//Title foreground
	extern char gfxtitlefore, gfxtitlefore_end;
	extern char maptitlefore, maptitlefore_end;
	extern char paltitlefore, paltitlefore_end;
	//Level Background 1
	extern char gfxbackground, gfxbackground_end;
	extern char mapbackground, mapbackground_end;
	extern char palbackground, palbackground_end;
	
	//Level room (along with its collision map)
	extern char gfxroom1, gfxroom1_end;
	extern char maproom1, maproom1_end;
	extern char palroom1, palroom1_end;
	extern char maproom1col, maproom1col_end;
	
	extern char gfxroom2, gfxroom2_end;
	extern char maproom2, maproom2_end;
	extern char palroom2, palroom2_end;
	extern char maproom2col, maproom2col_end;
	
	extern char gfxroom3, gfxroom3_end;
	extern char maproom3, maproom3_end;
	extern char palroom3, palroom3_end;
	extern char maproom3col, maproom3col_end;
	
	extern char gfxroom4, gfxroom4_end;
	extern char maproom4, maproom4_end;
	extern char palroom4, palroom4_end;
	extern char maproom4col, maproom4col_end;
	
	extern char gfxroom5, gfxroom5_end;
	extern char maproom5, maproom5_end;
	extern char palroom5, palroom5_end;
	extern char maproom5col, maproom5col_end;
	
	extern char gfxroom6, gfxroom6_end;
	extern char maproom6, maproom6_end;
	extern char palroom6, palroom6_end;
	extern char maproom6col, maproom6col_end;


#endif // __LIBALEX_DEFS__
