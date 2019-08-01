#include <genesis.h>

#include "../inc/include.h"
#include "../res/resources.h"
#include "../inc/joyreader.h"
#include "../inc/vram.h"





bool move_left  = false;
bool move_right = false;
bool move_jump  = false;




Sprite *waSprites [ 80 ];
u16 wvSprites        = 0;

int dead_counter     = 0;
int swimmers_counter = 0;
int ship_counter     = 0;
s16 level            = 0;



typedef struct
{
	u16     id;

	u16     pal;
	SpriteDefinition *sd;

	u16     animations[6];

	s16     vel_x_min;
	s16     vel_x_max;

	enum
	{
		is_player,
		is_food,
		is_ship
	}
	type;
}
Entity;




const Entity entity_list [ ] =
{
	{ 0, PAL2, (SpriteDefinition*) &shark_01,    { 0, 1, 2 }, 0, 0, is_player }, // 0
	{ 1, PAL3, (SpriteDefinition*) &swimmers_01, { 0, 1    }, 1, 3, is_food   }, // 1
	{ 2, PAL3, (SpriteDefinition*) &swimmers_01, { 2, 3    }, 2, 4, is_food   }, // 2
	{ 3, PAL3, (SpriteDefinition*) &seagull_01,  { 0, 1    }, 1, 2, is_food   }, // 3
	{ 4, PAL3, (SpriteDefinition*) &ship_01,     { 0, 0    }, 1, 1, is_ship   }, // 4
	{ 5, PAL2, (SpriteDefinition*) &shark_01,    { 3       }, 0, 0, is_player }, // 5
};






enum
{
	is_ok,
	is_swimming,
	is_jumping,
	is_dead
};




typedef struct
{
	bool    active;

	s16     vel_x;
	s16     vel_y;

	Entity *entity;
	Sprite *sprite;

	u16     status;
	u16     vram;
}
Object;



Object player;
Object waEnemies[80];


Object splash;










s16 needed   = 0;
s16 total    = 0;
s16 escapees = 0;














//
const struct
{
	u16 total;
	u16 needed;

	u16 max_prob;

	const struct
	{
		u16 seconds;
		u16 probability;
	}
	probabilities [ 10 ];
}
levels [ 4 ] =
{
//	{ 100,   80, 4, { {  5,  80 }, { 10,  40 }, {  5,  60 }, { 20,  20 }, } },
//	{ 105,   90, 4, { {  5,  80 }, { 10,  30 }, {  5,  10 }, { 20,  20 }, } },
//	{ 110,  100, 3, { { 10,  40 }, {  5,  60 }, { 20,  20 }, } },
//	{ 120,  115, 5, { {  5,  90 }, { 20,  10 }, { 10,  25 }, {  5,  54 }, { 20,  20 }, } },
	{ 100,   50, 4, { {  5,  80 }, { 10,  40 }, {  5,  60 }, { 20,  20 }, } },
	{ 100,   60, 4, { {  5,  80 }, { 10,  30 }, {  5,  10 }, { 20,  20 }, } },
	{ 100,   70, 3, { { 10,  40 }, {  5,  60 }, { 20,  20 }, } },
	{ 100,   80, 5, { {  5,  90 }, {  5,  30 }, { 10,  25 }, {  5,  54 }, { 5,  25 }, } },

};






///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



s16 SPR_getXPosition ( Sprite *sprite )
{
	return sprite->x - 0x80;
}

s16 SPR_getYPosition ( Sprite *sprite )
{
	return sprite->y - 0x80;
}

u16 SPR_nbTiles ( Sprite *sprite )
{
	return ( sprite->frame[0].h >> 3 ) * ( sprite->frame[0].w >> 3 );
}


/******************************************************************************************************************************/



wait_press ( u16 hz )
{
	u16 wait = hz;

	while ( 1 )
	{
		JoyReader_update();

		if ( joy1_pressed_start | joy1_pressed_abc )
		{
			return;
		}


		if ( hz && wait == 0 )
		{
			return;
		}

		--wait;

		VDP_waitVSync();
	}
}




void scream ()
{
	u16 id = 64;
	u16 prio = 1;
	u16 ch = SOUND_PCM_CH1;

	if ( random() % 2 )
	{
		id   = 65;
		prio = 2;
		ch   = SOUND_PCM_CH2;
	}

	SND_startPlayPCM_XGM ( id, prio, ch ) ;
}


void seagull()
{
	SND_startPlayPCM_XGM ( 67, 4, SOUND_PCM_CH4 ) ;
}

void paused()
{
	if (joy1_pressed_start )
	{
		VDP_drawText("PAUSED", 13, 11);

//		do
//		{
//			JoyReader_update();
//			VDP_waitVSync();
//		}
//		while ( !joy1_pressed_start ) ;
		wait_press (0);


		VDP_clearTextLine(11);
	}
}


void cheats ( s16 *ret )
{
	if ( !DEV )
	{
		return;
	}

	if ( joy1_pressed_x ) *ret = -1;
	if ( joy1_pressed_y ) *ret = +1;
}



void title ()
{
	if ( DEV )
	{
		return;
	}


	vram_init ( 16 );

	u16 pos;

	pos = vram_new ( title_a.tileset->numTile );
	VDP_drawImageEx ( PLAN_A, &title_a, TILE_ATTR_FULL ( PAL1, 0, 0, 0, pos ), 1, 4, 1, 0 );

	pos = vram_new ( title_b.tileset->numTile );
	VDP_drawImageEx ( PLAN_B, &title_b, TILE_ATTR_FULL ( PAL0, 0, 0, 0, pos ), 0, 0, 1, 0 );

	VDP_drawText ( "           PRESS START          ", 0, 20 );
	VDP_drawText ( "     BY MUN - @MOONWATCHERMD    ", 0, 26 );
	VDP_drawText ( "        FOR BITBIT JAM #3       ", 0, 23 );
	VDP_drawText ( "           @JULY 2016           ", 0, 24 );

	vram_destroy();

//	do
//	{
//		JoyReader_update();
//	}
//	while ( !joy1_pressed_start );
	wait_press (0);

	VDP_fadeOutAll(7,0);
}



void intro ()
{
	if ( DEV )
	{
		return;
	}

	VDP_fadeOutAll(1,0);






	VDP_init();
	VDP_setScreenWidth256 ( );
	VDP_setPlanSize ( 32, 32 );



	vram_init ( 16 );

	u16 pos, pos_2, pos_3, pos_4;

	pos = vram_new ( intro_a.tileset->numTile );
	VDP_drawImageEx ( PLAN_A, &intro_a, TILE_ATTR_FULL ( PAL1, 0, 0, 0, pos ), 0, 0, 1, 0 );

	pos = vram_new ( intro_b.tileset->numTile );
	VDP_drawImageEx ( PLAN_B, &intro_b, TILE_ATTR_FULL ( PAL0, 0, 0, 0, pos ), 0, 0, 1, 0 );

	//wait_press ( 120 );



	// mom
	pos_2 = vram_new ( intro_a_1.tileset->numTile );
	VDP_drawImageEx ( PLAN_A, &intro_a_1, TILE_ATTR_FULL ( PAL1, 0, 0, 0, pos_2 ), 4, 6, 1, 0 );

	wait_press ( 120 );

	VDP_fillTileMapRect(PLAN_A,0, 4, 5, 13, 8 );


	// Sharky
	pos_3 = vram_new ( intro_a_2.tileset->numTile );
	VDP_drawImageEx ( PLAN_A, &intro_a_2, TILE_ATTR_FULL ( PAL1, 0, 0, 0, pos_3 ), 18, 9, 1, 0 );

	wait_press ( 120 );



	// Mom
	Image *i;
	if ( level == 0 ) i = &intro_a_3;
	if ( level == 1 ) i = &intro_a_4;
	if ( level == 2 ) i = &intro_a_5;
	if ( level == 3 ) i = &intro_a_6;
	if ( level == 4 ) i = &intro_a_7;

	VDP_fillTileMapRect(PLAN_A, 0, 18, 9, 8, 6 );

	pos_2 = vram_new ( i->tileset->numTile );
	VDP_drawImageEx ( PLAN_A, i, TILE_ATTR_FULL ( PAL1, 0, 0, 0, pos_2 ), 4, 6, 1, 0 );

	wait_press ( 120 );

	pos_4 = vram_new ( intro_a_10.tileset->numTile );
	VDP_drawImageEx ( PLAN_A, &intro_a_10, TILE_ATTR_FULL ( PAL1, 0, 0, 0, pos_4 ), 8, 0, 1, 0 );

	wait_press ( 120 );

	VDP_fillTileMapRect(PLAN_A,0, 4, 5, 13, 8 );
	VDP_fillTileMapRect(PLAN_A,0, 8, 0, 13, 8 );


	// Sharky
	pos_3 = vram_new ( intro_a_8.tileset->numTile );
	VDP_drawImageEx ( PLAN_A, &intro_a_8, TILE_ATTR_FULL ( PAL1, 0, 0, 0, pos_3 ), 18, 9, 1, 0 );

	wait_press ( 120 );

	VDP_fillTileMapRect(PLAN_A, 0, 18, 9, 8, 6 );

	// Mom
	pos_2 = vram_new ( intro_a_9.tileset->numTile );
	VDP_drawImageEx ( PLAN_A, &intro_a_9, TILE_ATTR_FULL ( PAL1, 0, 0, 0, pos_2 ), 4, 6, 1, 0 );

	vram_destroy();



	VDP_setHorizontalScroll ( PLAN_B, 0 );
	VDP_setHorizontalScroll ( PLAN_A, 0 );


	wait_press (120);
}








/******************************************************************************************************************************/



void drawInt ( u32 nb, u8 x, u8 y, u8 zeros )
{
	u8 str [ zeros+1 ];
	intToStr ( nb, str, zeros );

	SYS_disableInts();
	VDP_drawText ( str, x, y );
	SYS_enableInts();
}


void drawUInt ( u32 nb, u8 x, u8 y, u8 zeros )
{
	u8 str [ zeros+1 ];
	uintToStr ( nb, str, zeros );

	SYS_disableInts();
	VDP_drawText ( str, x, y );
	SYS_enableInts();
}


void drawFix32 ( fix32 nb, u8 x, u8 y, u8 zeros )
{
	u8 str [ zeros+1 ];
	fix32ToStr ( nb, str, zeros );

	SYS_disableInts();
	VDP_drawText ( str, x, y );
	SYS_enableInts();
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





void write_total ()
{
	drawInt ( total,  1, 2, 3 );
}


void write_needed ()
{
	drawInt ( needed, 14, 2, 3 );
}





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void object_init ( )
{
	memset ( waEnemies, 0, sizeof(Object)*80 );
}


Object *object_create ( )
{
	u16 i;

	for ( i=0; i<80; i++ )
	{
		if ( waEnemies[i].active == false )
		{
			return (Object*) &waEnemies[i];
		}
	}

	return NULL;
}


void object_destroy ( Object *object )
{
	object->active = false;
}






/******************************************************************************************************************************/



void check_collisions ( Object *enemy )
{
	if ( !enemy->active  ||  enemy->status == is_dead )
	{
		return;
	}

	s16 x = player.sprite->x + ( player.sprite->frame[0].w >> 1 );
	s16 y = player.sprite->y + ( player.sprite->frame[0].h >> 1 );

	s16 x1 = enemy->sprite->x;
	s16 y1 = enemy->sprite->y;
	s16 x2 = enemy->sprite->x + enemy->sprite->frame[0].w - 0;
	s16 y2 = enemy->sprite->y + enemy->sprite->frame[0].h - 0;

	if ( x1 < x )
	{
		if ( x < x2 )
		{
			if ( y1 < y )
			{
				if ( y < y2 )
				{
					if ( enemy->entity->type == is_food )
					{
						if ( enemy->entity->id == 1  ||  enemy->entity->id == 2  )
						{
							scream ( );
						}

						if ( enemy->entity->id == 3  )
						{
							seagull ( );
						}


						SPR_setAnim ( enemy->sprite, enemy->entity->animations[1] ) ;

						enemy->status = is_dead;
						enemy->vel_x  = 0;
						enemy->vel_y  = 0;

						++dead_counter;

						--needed;
						write_needed ();
					}

					if ( enemy->entity->type == is_ship )
					{
						player.vel_y = 0;
					}
				}
			}
		}
	}
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





void splash_show ( xpos )
{
	if ( move_jump )
	{
		return;
	}

	if ( splash.active )
	{
		return;
	}

	splash.active = true;

	SPR_setAlwaysVisible ( splash.sprite, true );
	SPR_setPosition ( splash.sprite, xpos, 55 );

	SND_startPlayPCM_XGM ( 66, 3, SOUND_PCM_CH3 ) ;
}


void splash_hide ( )
{
	splash.active = false;
	SPR_setNeverVisible ( splash.sprite, true );
}

void splash_update ( )
{
	if ( splash.active  &&  splash.sprite->timer  == 1  &&  splash.sprite->frameInd == splash.sprite->animation->numFrame - 1 )
	{
		splash_hide();
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





void player_init ( )
{
	move_left  = false;
	move_right = false;
	move_jump  = false;


	player.active    = true;

	player.vel_x     = 0;
	player.vel_y     = 0;

	player.status    = is_ok;
	player.entity    = &entity_list[0];

	player.sprite    = SPR_addSprite ( player.entity->sd, 0, 0, TILE_ATTR ( player.entity->pal, 0, 0, 0 ) );

	waSprites[wvSprites++] = player.sprite;

	player.vram      = vram_new ( SPR_nbTiles ( player.sprite ) );

	SPR_setVRAMTileIndex ( player.sprite, player.vram );
	SPR_setAnim          ( player.sprite, player.entity->animations[0] );
	SPR_setPosition      ( player.sprite, 100, 100 );

	VDP_setPalette  ( player.entity->pal, player.entity->sd->palette->data );




	splash.active    = false;

	splash.vel_x     = 0;
	splash.vel_y     = 0;

	splash.status    = is_ok;
	splash.entity    = &entity_list[5];

	splash.sprite    = SPR_addSprite ( splash.entity->sd, 0, 0, TILE_ATTR ( splash.entity->pal, 0, 0, 0 ) );

	waSprites[wvSprites++] = splash.sprite;

	splash.vram      = vram_new ( SPR_nbTiles ( splash.sprite ) );

	SPR_setVRAMTileIndex ( splash.sprite, splash.vram );
	SPR_setAnim          ( splash.sprite, splash.entity->animations[0] );
	SPR_setPosition      ( splash.sprite, 100, 100 );
	SPR_setNeverVisible  ( splash.sprite, true );


	VDP_setPalette  ( splash.entity->pal, splash.entity->sd->palette->data );


}



void player_update ( )
{
	s16 anim   =  0;
	s16 flip_h = -1;
	s16 flip_v = -1;
	s16 xpos   = SPR_getXPosition ( player.sprite );
	s16 ypos   = SPR_getYPosition ( player.sprite );


	if ( joy1_active_right  ||  move_right )
	{
		anim   = player.entity->animations[1];
		flip_h = 0;

		++xpos;
	}

	if ( joy1_active_left  ||  move_left )
	{
		anim   = player.entity->animations[1];
		flip_h = 1;

		--xpos;
	}


	if ( player.status != is_jumping )
	{
		//if ( joy1_pressed_abc ) // if ( joy1_active_abc )

		if ( joy1_pressed_abc  ||  ( DEV && joy1_active_z )  ||  move_jump )
		{
			player.vel_y = 10;
		}

		if ( ypos < 42  )
		{
			player.status = is_jumping;
			player.vel_y  = 12;

			splash_show ( xpos );
		}
	}



	if ( player.status == is_jumping )
	{
			splash_show ( xpos );
	}


	if ( player.vel_y )
	{
		anim = player.entity->animations[2];

		ypos -= player.vel_y;
		--player.vel_y;
	}
	else
	{
		ypos += 5;

		if ( ypos > 180 )
		{
			ypos = 180;
		}
	}


	if ( ypos >= 62 )
	{
		player.status = is_ok;
	}




	if ( xpos < -11 ) xpos = -11;
	if ( xpos > 219 ) xpos = 219;

	SPR_setAnim ( player.sprite, anim );
	SPR_setPosition ( player.sprite, xpos, ypos );

	if ( flip_h != -1 )
	{
		SPR_setHFlip ( player.sprite, flip_h );
	}

	if ( flip_v != -1 )
	{
		SPR_setVFlip ( player.sprite, flip_v );
	}
}




void flying_shark()
{
//	if ( DEV )
//	{
//		return;
//	}

	VDP_fadeOutAll(7,0);


	VDP_init();
	VDP_setScreenWidth256 ( );
	VDP_setPlanSize ( 32, 32 );



	vram_init ( 16 );

	u16 pos;

	pos = vram_new ( intro_b.tileset->numTile );
	VDP_drawImageEx ( PLAN_B, &intro_b, TILE_ATTR_FULL ( PAL0, 0, 0, 0, pos ), 0, 0, 1, 0 );


	VDP_setTextPalette(PAL1);
	VDP_setPaletteColor(31,0x0af);

	VDP_drawText ( "YOU DID IT!",      11, 11 );
	VDP_drawText ( "CONGRATULATIONS!",  9, 14 );


	wvSprites = 0;
	SPR_init ( 80, 0, 0 );

	object_init ( );
	player_init();


	s16 y =150;


	SPR_setPosition ( player.sprite, 100, 150 );
	player_update ( );
	SPR_update ( waSprites, wvSprites );
	VDP_waitVSync();

	waitMs(3000);

	move_jump  = true;

	SPR_setPosition ( player.sprite, SPR_getXPosition(player.sprite), y );
	player_update ( );
	SPR_update ( waSprites, wvSprites );
	VDP_waitVSync();

	while ( y>=0 )
	{
		y-=6;
		SPR_setPosition ( player.sprite, SPR_getXPosition(player.sprite), y );
		player_update ( );
		SPR_update ( waSprites, wvSprites );
		VDP_waitVSync();
	}



	vram_delete ( pos );
	pos = vram_new ( ending_b.tileset->numTile );
	VDP_drawImageEx ( PLAN_B, &ending_b, TILE_ATTR_FULL ( PAL0, 0, 0, 0, pos ), 0, 0, 1, 0 );


	y=224;

	while ( y > 110 )
	{
		move_jump  = true;

		SPR_setPosition ( player.sprite, SPR_getXPosition(player.sprite), y );
		player_update ( );
		SPR_update ( waSprites, wvSprites );
		VDP_waitVSync();

		y -= 5;
	}


	waitMs(3000);
	wait_press ( 120 );

	VDP_fadeOutAll(60, 0);


	vram_destroy();

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void enemy_add ( )
{

	u16 type;


	do
	{
		type = ( random() % 4 ) + 1;
	}
	while ( type == 4  &&  ship_counter == MAX_SHIPS );



	Object *tmp = (Object *) object_create();

	tmp->entity = &entity_list [ type ];

	tmp->active = true;
	tmp->status = is_ok;
	tmp->vel_x  = random () % ( tmp->entity->vel_x_max - tmp->entity->vel_x_min + 1 ) + tmp->entity->vel_x_min ;
	tmp->vel_y  = 0;

	tmp->sprite = SPR_addSprite ( tmp->entity->sd, 0, 0, TILE_ATTR ( tmp->entity->pal, 0, 0, 0 ) );

	waSprites[wvSprites++] = tmp->sprite;


	s16 x      = -20;
	s16 y      = +46;
	u16 flip_h = 0;


	if ( random() % 2 == 0 )
	{
		x = 254;
		tmp->vel_x = -tmp->vel_x;
		flip_h = 1;
	}

	if ( type == 1 )
	{
		y += ( ( random() % 10 ) + 8 );
	}

	if ( type == 2 )
	{
		y = ( random() % 60 ) + 88;
	}

	if ( type == 3 )
	{
		y = ( random() % 10 ) + 15;
	}

	if ( type == 4 )
	{
		y = 78;
		++ship_counter;
	}

	tmp->vram = vram_new ( SPR_nbTiles ( tmp->sprite ) );

	SPR_setVRAMTileIndex ( tmp->sprite, tmp->vram );
	SPR_setHFlip         ( tmp->sprite, flip_h );
	SPR_setPosition      ( tmp->sprite, x, y );
	SPR_setAnim          ( tmp->sprite, tmp->entity->animations[0] );
	VDP_setPalette       ( tmp->entity->pal, tmp->entity->sd->palette->data );


	if ( tmp->entity->type == is_food ) // this avoid ships
	{
		++swimmers_counter;

		--total;

		write_total  () ;
	}
}



void enemy_update ( Object *object )
{
	if ( !object->active )
	{
		return;
	}

	if
	(
		object->status           == is_dead  &&
		object->sprite->timer    == 1  &&
		object->sprite->frameInd == object->sprite->animation->numFrame - 1
	)
	{
		SPR_releaseSprite( object->sprite );
		--wvSprites;

		vram_delete ( object->vram);

		object_destroy ( object );

		return;
	}

	s16 x = SPR_getXPosition ( object->sprite ) + object->vel_x;
	s16 y = SPR_getYPosition ( object->sprite ) + object->vel_y;

	SPR_setPosition ( object->sprite, x, y	);


	// escaped
	if ( !SPR_computeVisibility ( object->sprite ) )
	{
		if ( object->entity->id == 4 )
		{
			--ship_counter;
		}


		SPR_releaseSprite( object->sprite );
		--wvSprites;

		vram_delete(object->vram);

		object->status = is_dead;

		object_destroy ( object );


		++escapees;

		if ( DEV )
		{
			drawInt(escapees,4,0,3);
		}
	}
}




////////////////////////////////////////////////////////////////////////////////////////////////////


s16 level_get_seconds ( s16 step )
{
	return levels[level].probabilities[step].seconds * ( SYS_isPAL() ? 50 : 60 );
}

s16 level_get_max_prob ( )
{
	return levels[level].max_prob;
}

s16  level_calculate_prob ( s16 step )
{
	return ( random() % levels[level].probabilities[step].probability == 0 );
}

s16 level_get_needed ( )
{
	return levels[level].needed;
}

s16 level_get_total ( )
{
	return levels[level].total;
}


////////////////////////////////////////////////////////////////////////////////////////////////////


void write_texts()
{
	VDP_clearTextLine(14);
	VDP_clearTextLine(16);

	// hud                          z
	VDP_drawText ( " REST        NEDDED       LEVEL ", 0, 1 );
	drawInt ( level+1, 28, 2, 0 );

	write_total ( );
	write_needed ( );



	//
	VDP_drawText ( "LEVEL ",     13, 11 );
	drawInt ( level+1, 19, 11, 0 );

	VDP_drawText ( "DEVOUR   ", 12, 14 );
	drawInt ( level_get_needed(), 19, 14, 0 );

	waitMs(2000);
	//SND_startPlay_XGM ( &xgm_start );


	VDP_clearTextLine(11);
	VDP_clearTextLine(14);
	VDP_clearTextLine(16);

	VDP_drawText ( "READY",     14, 11 );


	waitMs(1000);

	VDP_clearTextLine(11);
	VDP_clearTextLine(14);
	VDP_clearTextLine(16);

	VDP_drawText ( "GO!",        15, 11 );

	waitMs(1000);

	VDP_clearTextLine(11);
	VDP_clearTextLine(14);
	VDP_clearTextLine(16);


	//SND_stopPlay_XGM();
}

//////////////////////////////////////////////////////////////////////////////////////////////////



s16 scroll_tiles [ 6 ];

scroll_init()
{
	scroll_tiles[0] = random();
	scroll_tiles[1] = random();
	scroll_tiles[2] = random();
	scroll_tiles[3] = random();
	scroll_tiles[4] = random();
	scroll_tiles[5] = random();

	VDP_setScrollingMode ( HSCROLL_TILE, VSCROLL_PLANE );
}


scroll_update ()
{
	--scroll_tiles[0];
	++scroll_tiles[1];
	--scroll_tiles[2];
	++scroll_tiles[3];
	--scroll_tiles[4];
	++scroll_tiles[5];

	u16 start = 9;
	u16 len   = 5;

	if ( level == 3 )
	{
		start = 8;
		len   = 6;
	}

	VDP_setHorizontalScrollTile ( PLAN_B, start, scroll_tiles, len, 1 );
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////






s16 game_loop ( )
{
	intro ();

	VDP_fadeOutAll(7,0);


	VDP_setEnable ( 0 );

	VDP_init();
	VDP_setScreenWidth256 ( );
	VDP_setPlanSize ( 32, 32 );


	u16 counter = 0;
	u16 step    = 0;
	u16 pos     = 0;


	wvSprites        = 0;
	dead_counter     = 0;
	swimmers_counter = 0;
	ship_counter     = 0;

	vram_init ( 16 );

	const Image *background_list [ 4 ] = { &background_01, &background_02, &background_03, &background_04 };

	pos = vram_new ( background_list[level]->tileset->numTile );
	VDP_drawImageEx ( PLAN_B, background_list[level], TILE_ATTR_FULL ( PAL0, 0, 0, 0, pos ), 0, 0, 1, 0 );






	SPR_init ( 80, 0, 0 );

	object_init ( );
	player_init ( );




	VDP_setPalette ( PAL3, swimmers_01.palette->data );




	// yellow text
	VDP_setTextPalette(PAL1);
	VDP_setPaletteColor(31,0x0af);

	scroll_init();
	scroll_update();


	needed   = level_get_needed ( );
	total    = level_get_total  ( );
	escapees = 0;



	VDP_setEnable ( 1 );

	write_texts();





	s16 ret = 0;

	while ( ret == 0 )
	{
		////////////////////////////////////////////////////////////////////////////////

		if ( level_get_needed ( ) <= dead_counter )
		{
			ret = +1;
		}

		if ( level_get_total ( ) <= swimmers_counter )
		{
			ret = -1;
		}

		////////////////////////////////////////////////////////////////////////////////

		++counter;

		if ( counter >= level_get_seconds (step) )
		{
			counter = 0 ;
			++step;

			if ( step >= level_get_max_prob() )
			{
				step = 0;
			}

		}

		if ( level_calculate_prob(step) )
		{
			enemy_add ( );
		}

		////////////////////////////////////////////////////////////////////////////////

		JoyReader_update();
		cheats ( &ret );
		paused ( );
		player_update ( );
		splash_update ( );

		////////////////////////////////////////////////////////////////////////////////

		u16 i;

		for ( i=0; i<80; i++ )
		{
			if ( !waEnemies[i].active )
			{
				continue;
			}

			enemy_update ( &waEnemies [i] );
			check_collisions ( &waEnemies [i] );
		}

		////////////////////////////////////////////////////////////////////////////////

		SPR_update ( waSprites, wvSprites );
		VDP_waitVSync();

		////////////////////////////////////////////////////////////////////////////////


		scroll_update();
	}

	vram_destroy ( );
	SPR_clear();
	SPR_end();


	return ret;
}



int main ( )
{
	//flying_shark();

	SND_setPCM_XGM ( 64, ahhh_01,    sizeof(ahhh_01) );
	SND_setPCM_XGM ( 65, ahhh_02,    sizeof(ahhh_02) );
	SND_setPCM_XGM ( 66, splash_01,  sizeof(splash_01) );
	SND_setPCM_XGM ( 67, seagull_02, sizeof(seagull_02) );

	JoyReader_init(1);
	screen_sega();

	while (1)
	{
		level = 0;


		setRandomSeed ( 19 );

		VDP_init();

		VDP_setScreenWidth256 ( );
		VDP_setPlanSize ( 32, 32 );

		VDP_setScrollingMode ( HSCROLL_PLANE, VSCROLL_PLANE );
		VDP_setHorizontalScroll ( PLAN_A, 0 );
		VDP_setHorizontalScroll ( PLAN_B, 0 );

		title();


		while ( 1 )
		{
			s16 ret = game_loop();


			if ( ret == +1 )
			{
				++level;

				if ( level > 3 )
				{
					VDP_drawText ( "YOU DID IT!",      11, 11 );
					VDP_drawText ( "CONGRATULATIONS!",  9, 14 );
					waitMs ( 5000 );

					level = 0;
					break;
				}
				else
				{
					VDP_drawText ( "G0OD JOB!",   12, 11 );
					waitMs(3000);
				}
			}

			if ( ret == -1 )
			{
				--level;

				if ( level <= 0 )
				{
					level = 0;
				}

				//SND_startPlay_XGM ( &xgm_try_again );
				VDP_drawText ( "TRY AGAIN",  11, 11 );
				waitMs(1500);
				//SND_stopPlay_XGM();
				waitMs(1500);
			}




		}

		flying_shark();
	}


	return 0;
}

