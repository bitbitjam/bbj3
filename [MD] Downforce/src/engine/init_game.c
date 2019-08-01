#include "..\main.h"

/////////////////////////////////////////////////////////////////
//
// BKGs y PALETAS
// --------------
// BKG-A fondo del escenario PAL0
// BKG-B circuito PAL1
// Sprites comunes PAL2
// Naves PAL 3 (ultimo color es FF para la transparencia)

// VRAM
// -----
// naves (3*2 tiles -> 6*3 frames -> 18*6 naves -> 108 )
// sombras ( 108 )
// tiles sprites comunes (estelas) ( 32 )
// fondo
// circuito
// fuente
//
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
//
// void initRecords(){
// valores iniciales de la pantalla de records
//
/////////////////////////////////////////////////////////////////
void initRecords(){
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void initGame(){
// doy valor inicial a las variables del juego (personajes...)
// y carga los tiles de los personajes e inicia sus sprites
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void initGame( u8 mode, u8 circuit ){
	
	u8 a;
	
	// cargo la paleta inicial
    VDP_setPalette((u16 *)palette_black, 0, 16);
    VDP_setPalette((u16 *)palette_black, 16, 16);
    VDP_setPalette((u16 *)palette_black, 32, 16);
    VDP_setPalette((u16 *)palette_black, 48, 16);

    // borro los planos
    VDP_clearPlan(APLAN);
    VDP_clearPlan(BPLAN);

    // cambia el color del fondo
    VDP_setReg(7, 0x0F);
	
	// activo el modo HS
    VDP_setHilightShadow(1);
	
	// full hscroll full vscroll
	VDP_setReg(11, 0x00);

	////////////////////////////////////////////////////////////////////
	// jugadores
	// cargo los tiles de las naves
	VDP_loadTileData(ship00Tiles, shipTilesPos				  , shipTilesSize, 1);
	/*VDP_loadTileData(ship00Tiles, shipTilesPos+shipTilesSize  , shipTilesSize, 1);
	VDP_loadTileData(ship00Tiles, shipTilesPos+shipTilesSize*2, shipTilesSize, 1);
	VDP_loadTileData(ship00Tiles, shipTilesPos+shipTilesSize*3, shipTilesSize, 1);
	VDP_loadTileData(ship00Tiles, shipTilesPos+shipTilesSize*4, shipTilesSize, 1);
	VDP_loadTileData(ship00Tiles, shipTilesPos+shipTilesSize*5, shipTilesSize, 1);*/
	
	// posicion en pantalla
	player[0].screenPosX = FIX32(initPlayer1PosX);
	player[0].screenPosY = FIX32(initPlayer1PosY);
		
	if( circuit == 0 ){
		player[1].screenPosX = FIX32(initPlayer2PosX);
		player[1].screenPosY = FIX32(initPlayer2PosY);
		player[2].screenPosX = FIX32(initPlayer3PosX);
		player[2].screenPosY = FIX32(initPlayer3PosY);
		player[3].screenPosX = FIX32(initPlayer4PosX);
		player[3].screenPosY = FIX32(initPlayer4PosY);
		player[4].screenPosX = FIX32(initPlayer5PosX);
		player[4].screenPosY = FIX32(initPlayer5PosY);
		player[5].screenPosX = FIX32(initPlayer6PosX);
		player[5].screenPosY = FIX32(initPlayer6PosY);
	}
	else{
		player[1].screenPosX = FIX32(screen_width);
		player[1].screenPosY = FIX32(screen_width);
		player[2].screenPosX = FIX32(screen_width);
		player[2].screenPosY = FIX32(screen_width);
		player[3].screenPosX = FIX32(screen_width);
		player[3].screenPosY = FIX32(screen_width);
		player[4].screenPosX = FIX32(screen_width);
		player[4].screenPosY = FIX32(screen_width);
		player[5].screenPosX = FIX32(screen_width);
		player[5].screenPosY = FIX32(screen_width);
	}
	
	player[0].initPosY = initPlayer1PosY;
	
	// posicion en en el circuito
	player[0].circuitPosX = initPlayer1PosX;
	player[0].circuitPosY = FIX32(initPlayer1PosY+scrollInitPosY);
	player[1].circuitPosX = initPlayer2PosX;
	player[1].circuitPosY = FIX32(initPlayer2PosY+scrollInitPosY);
	player[2].circuitPosX = initPlayer3PosX;
	player[2].circuitPosY = FIX32(initPlayer3PosY+scrollInitPosY);
	player[3].circuitPosX = initPlayer4PosX;
	player[3].circuitPosY = FIX32(initPlayer4PosY+scrollInitPosY);
	player[4].circuitPosX = initPlayer5PosX;
	player[4].circuitPosY = FIX32(initPlayer5PosY+scrollInitPosY);
	player[5].circuitPosX = initPlayer6PosX;
	player[5].circuitPosY = FIX32(initPlayer6PosY+scrollInitPosY);
	
	// naves
	for( a = 0; a < max_num_players; a++ ){
		player[a].speedPos = player[a].turbo = player[a].sparksAnim = player[a].sparksPos = player[a].weapon = 0;
		player[a].direction = dir_stand;
		player[a].numFrame = player[a].numFrameTurbo = 0;
		player[a].lap = player[a].newLap = 0;
		player[a].energy = 99;
		player[a].state = 2;
		
		player[a].collisionUpRear = player[a].collisionUpFront = player[a].collisionDownRear = player[a].collisionDownFront = 1;
		
		// sprite principal
		player[a].sprite.posx = fix32ToInt(player[a].screenPosX);
		player[a].sprite.posy = fix32ToInt(player[a].screenPosY);
		player[a].sprite.size = SPRITE_SIZE(3, 2);
		player[a].sprite.tile_attr = TILE_ATTR_FULL(PAL3, 1, 0, 0, shipTilesPos+shipAloneTileSize*a);
		player[a].sprite.link  = shipSpriteId+a+1;
			
		VDP_setSpriteP(shipSpriteId+a, &player[a].sprite);
	}
	
	// estelas
	for( a = 0; a < max_num_players; a++ ){
		player[a].trail.posx = screen_width;
		player[a].trail.posy = 0;
		player[a].trail.size = SPRITE_SIZE(4, 2);
		player[a].trail.tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, commonSpritesTilesPos);
		player[a].trail.link  = shipSpriteId+max_num_players+a+1;
			
		VDP_setSpriteP(shipSpriteId+max_num_players+a, &player[a].trail);
	}
	
	// chispas
	for( a = 0; a < max_num_players; a++ ){
		player[a].sparks.posx = screen_width;
		player[a].sparks.posy = 0;
		player[a].sparks.size = SPRITE_SIZE(4, 1);
		player[a].sparks.tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, sparksTilePos);
		player[a].sparks.link  = shipSpriteId+max_num_players*2+a+1;
			
		VDP_setSpriteP(shipSpriteId+max_num_players*2+a, &player[a].sparks);
	}
	
	// sombras
	VDP_loadTileData(ship00ShadowTiles, shipShadowTilesPos				  , shipTilesSize, 1);
	/*VDP_loadTileData(ship00ShadowTiles, shipShadowTilesPos+shipTilesSize  , shipTilesSize, 1);
	VDP_loadTileData(ship00ShadowTiles, shipShadowTilesPos+shipTilesSize*2, shipTilesSize, 1);
	VDP_loadTileData(ship00ShadowTiles, shipShadowTilesPos+shipTilesSize*3, shipTilesSize, 1);
	VDP_loadTileData(ship00ShadowTiles, shipShadowTilesPos+shipTilesSize*4, shipTilesSize, 1);
	VDP_loadTileData(ship00ShadowTiles, shipShadowTilesPos+shipTilesSize*5, shipTilesSize, 1);*/
	
	for( a = 0; a < max_num_players; a++ ){
		player[a].shadow.posx = fix32ToInt(player[a].screenPosX)-4;
		player[a].shadow.posy = fix32ToInt(player[a].screenPosY)+4;
		player[a].shadow.size = SPRITE_SIZE(3, 2);
		player[a].shadow.tile_attr = TILE_ATTR_FULL(PAL3, 1, 0, 0, shipShadowTilesPos+shipAloneTileSize*a);
		player[a].shadow.link  = shipSpriteId+max_num_players*3+a+1;
			
		VDP_setSpriteP(shipSpriteId+max_num_players*3+a, &player[a].shadow);
	}
	
	// borramos las sombras de los sprites para el time attack
	if( circuit == 1 ){
		player[1].shadow.posx = screen_width;
		player[2].shadow.posx = screen_width;
		player[3].shadow.posx = screen_width;
		player[4].shadow.posx = screen_width;
		player[5].shadow.posx = screen_width;
		VDP_setSpriteP(shipSpriteId+max_num_players*3+1, &player[1].shadow);
		VDP_setSpriteP(shipSpriteId+max_num_players*3+2, &player[2].shadow);
		VDP_setSpriteP(shipSpriteId+max_num_players*3+3, &player[3].shadow);
		VDP_setSpriteP(shipSpriteId+max_num_players*3+4, &player[4].shadow);
		VDP_setSpriteP(shipSpriteId+max_num_players*3+5, &player[5].shadow);
		
		VDP_updateSprites();
	}
	
	//////////////////////////////////////////////////////////////////
	// cargo los tiles de los sprites comunes
	VDP_loadTileData(commonSpritesTiles, commonSpritesTilesPos, commonSpritesSize, 1);
	
	//////////////////////////////////////////////////////////////////
	// cargo los tiles de los fondos
	// fondo BKG-A
	if( circuit == 0 ){
		VDP_loadTileData(bg00Tiles, bgTilesPos, bg00TilesSize, 1);
		VDP_fillTileMap( APLAN, bg00Map, 0, 0, bg00MapSizeX, bg00MapSizeY, TILE_ATTR_FULL(PAL1, 0, 0, 0, bgTilesPos));
		
		// circuito BKG-B
		VDP_loadTileData(circuit00Tiles, circuitTilesPos, circuit00TilesSize, 1);
		
		// plano, mapa, x/y desde, x/y hasta, tamaño mapa, tile
		VDP_fillBigTileMap( BPLAN, circuit00Map, 0, 0, 64, circuit00MapSizeY-1, circuit00MapSizeX, TILE_ATTR_FULL(PAL1, 1, 0, 0, circuitTilesPos));
	}
	else if( circuit == 1 ){
		VDP_loadTileData(bg01Tiles, bgTilesPos, bg01TilesSize, 1);
		VDP_fillTileMap( APLAN, bg01Map, 0, 0, bg00MapSizeX, bg00MapSizeY, TILE_ATTR_FULL(PAL1, 0, 0, 0, bgTilesPos));
		
		// circuito BKG-B
		VDP_loadTileData(circuit01Tiles, circuitTilesPos, circuit01TilesSize, 1);
		
		// plano, mapa, x/y desde, x/y hasta, tamaño mapa, tile
		VDP_fillBigTileMap( BPLAN, circuit01Map, 0, 0, 64, circuit00MapSizeY-1, circuit00MapSizeX, TILE_ATTR_FULL(PAL1, 1, 0, 0, circuitTilesPos));
	}
	
	//////////////////////////////////////////////////////////////////
	// globales
	scrollPos_x = scrollBgTotal = 0;
	scrollAPos_y = scrollBPos_y = FIX32(scrollInitPosY);
	
	VDP_setVerticalScroll(BPLAN, 0, fix32ToInt(scrollBPos_y));
	VDP_setVerticalScroll(APLAN, 0, fix32ToInt(scrollAPos_y));
	
	VDP_setHorizontalScroll(BPLAN, 0, 0);
	VDP_setHorizontalScroll(APLAN, 0, 0);
	
	// carga la fuente
	if( mode )
		VDP_loadTileData( titleFontVTiles, pos_vram_font, titleFontTilesSize, 1);
	else
		VDP_loadTileData( titleFontHTiles, pos_vram_font, titleFontTilesSize, 1);
	
	////////////////////////////////////////////////////////////////////////////////
	// marcadores
	if( !mode ){
		VDP_loadTileData( numbersTilesH, pos_vram_font-numbersTilesSize, numbersTilesSize, 1);
		VDP_loadTileData( miscTilesH, pos_vram_font-numbersTilesSize-miscTilesSize, miscTilesSize, 1);
		
		for( a = 0; a < 3; a++ ){
			speedHud[a].posx = 262+8*a;
			speedHud[a].posy = 200;
			speedHud[a].size = SPRITE_SIZE(1, 2);
			speedHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize);
			speedHud[a].link  = a+1;
					
			VDP_setSpriteP(a, &speedHud[a]);
		}
		
		for( a = 0; a < 2; a++ ){
			energyHud[a].posx = 286+8*a;
			energyHud[a].posy = 180;
			energyHud[a].size = SPRITE_SIZE(1, 2);
			energyHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+18);
			energyHud[a].link  = 4+a;
					
			VDP_setSpriteP(a+3, &energyHud[a]);
		}
		
		for( a = 0; a < 2; a++ ){
			lapHud[a].posx = 286+18*a;
			lapHud[a].posy = 32;
			lapHud[a].size = SPRITE_SIZE(1, 2);
			lapHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+2);
			lapHud[a].link  = 6+a;
					
			VDP_setSpriteP(a+5, &lapHud[a]);
		}
		
		lapHud[1].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+6);
		VDP_setSpriteP(6, &lapHud[1]);
		
		for( a = 0; a < 2; a++ ){
			posHud[a].posx = 286+18*a;
			posHud[a].posy = 12;
			posHud[a].size = SPRITE_SIZE(1, 2);
			if( circuit == 0 )
				posHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+12);
			else
				posHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+2);
			posHud[a].link  = 8+a;
					
			VDP_setSpriteP(a+7, &posHud[a]);
		}
		
		for( a = 0; a < 2; a++ ){
			timeHud[a].posx = 24+8*a;
			timeHud[a].posy = 8;
			timeHud[a].size = SPRITE_SIZE(1, 2);
			timeHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize);
			timeHud[a].link  = minsSpriteId+1+a;
					
			VDP_setSpriteP(a+minsSpriteId, &timeHud[a]);
		}
		
		for( a = 2; a < 4; a++ ){
			timeHud[a].posx = 32+8*a;
			timeHud[a].posy = 8;
			timeHud[a].size = SPRITE_SIZE(1, 2);
			timeHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize);
			timeHud[a].link  = minsSpriteId+1+a;
					
			VDP_setSpriteP(a+minsSpriteId, &timeHud[a]);
		}
		
		timeHud[4].posx = 72;
		timeHud[4].posy = 8;
		timeHud[4].size = SPRITE_SIZE(1, 2);
		timeHud[4].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize);
		timeHud[4].link  = decsSpriteId+1;
					
		VDP_setSpriteP(decsSpriteId, &timeHud[4]);
		
		// best time
		for( a = 0; a < 2; a++ ){
			bestHud[a].posx = 24+8*a;
			bestHud[a].posy = 27;
			bestHud[a].size = SPRITE_SIZE(1, 2);
			bestHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize);
			bestHud[a].link  = 15+a;
					
			VDP_setSpriteP(a+14, &bestHud[a]);
		}
		
		for( a = 2; a < 4; a++ ){
			bestHud[a].posx = 32+8*a;
			bestHud[a].posy = 27;
			bestHud[a].size = SPRITE_SIZE(1, 2);
			bestHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize);
			bestHud[a].link  = 15+a;
					
			VDP_setSpriteP(a+14, &bestHud[a]);
		}
		
		bestHud[4].posx = 72;
		bestHud[4].posy = 27;
		bestHud[4].size = SPRITE_SIZE(1, 2);
		bestHud[4].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize);
		bestHud[4].link  = 19;
					
		VDP_setSpriteP(18, &bestHud[4]);
		
		// descripcion del arma
		for( a = 0; a < 2; a++ ){
			weaponHud[a].posx = 36+8*a;
			weaponHud[a].posy = 180;
			weaponHud[a].size = SPRITE_SIZE(1, 2);
			weaponHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+20);
			weaponHud[a].link  = 20+a;
					
			VDP_setSpriteP(a+19, &weaponHud[a]);
		}
		
		weaponHud[1].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+22);
		VDP_setSpriteP(20, &weaponHud[1]);
		
		// numero de muertes
		killsHud.posx = 28;
		killsHud.posy = 200;
		killsHud.size = SPRITE_SIZE(1, 2);
		killsHud.tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize);
		killsHud.link  = 22;
					
		VDP_setSpriteP(21, &killsHud);
		
		// speed
		{miscHud[0].posx =  262 - 26;
		miscHud[0].posy =  208;
		miscHud[0].size = SPRITE_SIZE(4, 1);
		miscHud[0].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize);
		miscHud[0].link  = spriteMisc+1;
					
		VDP_setSpriteP(spriteMisc, &miscHud[0]);
		
		// km/h
		miscHud[1].posx =  262 +24;
		miscHud[1].posy =  208;
		miscHud[1].size = SPRITE_SIZE(3, 1);
		miscHud[1].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+4);
		miscHud[1].link  = spriteMisc+2;
					
		VDP_setSpriteP(spriteMisc+1, &miscHud[1]);
		
		// energy
		miscHud[2].posx =  286 - 30;
		miscHud[2].posy =  188;
		miscHud[2].size = SPRITE_SIZE(4, 1);
		miscHud[2].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+7);
		miscHud[2].link  = spriteMisc+3;
					
		VDP_setSpriteP(spriteMisc+2, &miscHud[2]);
		
		// %
		miscHud[3].posx =  286 +16;
		miscHud[3].posy =  188;
		miscHud[3].size = SPRITE_SIZE(1, 1);
		miscHud[3].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+11);
		miscHud[3].link  = spriteMisc+4;
					
		VDP_setSpriteP(spriteMisc+3, &miscHud[3]);}
		
		// lap
		{miscHud[4].posx =  286 -15;
		miscHud[4].posy =  33;
		miscHud[4].size = SPRITE_SIZE(2, 1);
		miscHud[4].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+12);
		miscHud[4].link  = spriteMisc+5;
					
		VDP_setSpriteP(spriteMisc+4, &miscHud[4]);
		
		// of
		miscHud[5].posx =  286 +8;
		miscHud[5].posy =  33;
		miscHud[5].size = SPRITE_SIZE(2, 1);
		miscHud[5].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+14);
		miscHud[5].link  = spriteMisc+6;
					
		VDP_setSpriteP(spriteMisc+5, &miscHud[5]);
		
		// pos
		miscHud[6].posx =  286 -15;
		miscHud[6].posy =  13;
		miscHud[6].size = SPRITE_SIZE(2, 1);
		miscHud[6].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+16);
		miscHud[6].link  = spriteMisc+7;
					
		VDP_setSpriteP(spriteMisc+6, &miscHud[6]);
		
		// of
		miscHud[7].posx =  286 +8;
		miscHud[7].posy =  13;
		miscHud[7].size = SPRITE_SIZE(2, 1);
		miscHud[7].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+14);
		miscHud[7].link  = spriteMisc+8;
					
		VDP_setSpriteP(spriteMisc+7, &miscHud[7]);}
		
		// time
		{miscHud[8].posx =  22 -19;
		miscHud[8].posy =  9;
		miscHud[8].size = SPRITE_SIZE(3, 1);
		miscHud[8].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+18);
		miscHud[8].link  = spriteMisc+9;
					
		VDP_setSpriteP(spriteMisc+8, &miscHud[8]);
		
		// :
		miscHud[9].posx =  40;
		miscHud[9].posy =  12;
		miscHud[9].size = SPRITE_SIZE(1, 1);
		miscHud[9].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+21);
		miscHud[9].link  = spriteMisc+10;
					
		VDP_setSpriteP(spriteMisc+9, &miscHud[9]);
		
		// .
		miscHud[10].posx =  64;
		miscHud[10].posy =  16;
		miscHud[10].size = SPRITE_SIZE(1, 1);
		miscHud[10].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+22);
		miscHud[10].link  = spriteMisc+11;
					
		VDP_setSpriteP(spriteMisc+10, &miscHud[10]);
		
		// best
		miscHud[11].posx =  22 - 19;
		miscHud[11].posy =  28;
		miscHud[11].size = SPRITE_SIZE(3, 1);
		miscHud[11].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+23);
		miscHud[11].link  = spriteMisc+12;
					
		VDP_setSpriteP(spriteMisc+11, &miscHud[11]);
		
		// :
		miscHud[12].posx =  40;
		miscHud[12].posy =  32;
		miscHud[12].size = SPRITE_SIZE(1, 1);
		miscHud[12].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+21);
		miscHud[12].link  = spriteMisc+13;
					
		VDP_setSpriteP(spriteMisc+12, &miscHud[12]);
		
		// .
		miscHud[13].posx =  64;
		miscHud[13].posy =  35;
		miscHud[13].size = SPRITE_SIZE(1, 1);
		miscHud[13].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+22);
		miscHud[13].link  = spriteMisc+14;
					
		VDP_setSpriteP(spriteMisc+13, &miscHud[13]);}
		
		{// weapon
		miscHud[14].posx =  24 - 20;
		miscHud[14].posy =  188;
		miscHud[14].size = SPRITE_SIZE(4, 1);
		miscHud[14].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+26);
		miscHud[14].link  = spriteMisc+15;
					
		VDP_setSpriteP(spriteMisc+14, &miscHud[14]);
		
		// kills
		miscHud[15].posx =  24 - 20;
		miscHud[15].posy =  208;
		miscHud[15].size = SPRITE_SIZE(3, 1);
		miscHud[15].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+30);
		miscHud[15].link  = spriteMisc+16;
					
		VDP_setSpriteP(spriteMisc+15, &miscHud[15]);}
	}
	else{
		VDP_loadTileData( numbersTilesV, pos_vram_font-numbersTilesSize, numbersTilesSize, 1);
		VDP_loadTileData( miscTilesV, pos_vram_font-numbersTilesSize-miscTilesSize, miscTilesSize, 1);
		
		for( a = 0; a < 3; a++ ){
			speedHud[a].posx = 8;
			speedHud[a].posy = 168+8*a;
			speedHud[a].size = SPRITE_SIZE(2, 1);
			speedHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize);
			speedHud[a].link  = a+1;
					
			VDP_setSpriteP(a, &speedHud[a]);
		}
		
		for( a = 0; a < 2; a++ ){
			energyHud[a].posx = 28;
			energyHud[a].posy = 192+8*a;
			energyHud[a].size = SPRITE_SIZE(2, 1);
			energyHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+18);
			energyHud[a].link  = 4+a;
					
			VDP_setSpriteP(a+3, &energyHud[a]);
		}
		
		for( a = 0; a < 2; a++ ){
			lapHud[a].posx = 276;
			lapHud[a].posy = 190+20*a;
			lapHud[a].size = SPRITE_SIZE(2, 1);
			lapHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+2);
			lapHud[a].link  = 6+a;
					
			VDP_setSpriteP(a+5, &lapHud[a]);
		}
		
		lapHud[1].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+6);
		VDP_setSpriteP(6, &lapHud[1]);
		
		for( a = 0; a < 2; a++ ){
			posHud[a].posx = 296;
			posHud[a].posy = 190+20*a;
			posHud[a].size = SPRITE_SIZE(2, 1);
			if( circuit == 0 )
				posHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+12);
			else
				posHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+2);
			posHud[a].link  = 8+a;
					
			VDP_setSpriteP(a+7, &posHud[a]);
		}
		
		for( a = 0; a < 2; a++ ){
			timeHud[a].posx = 298;
			timeHud[a].posy = 28+8*a;
			timeHud[a].size = SPRITE_SIZE(2, 1);
			timeHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize);
			timeHud[a].link  = 10+a;
					
			VDP_setSpriteP(a+9, &timeHud[a]);
		}
		
		for( a = 2; a < 4; a++ ){
			timeHud[a].posx = 298;
			timeHud[a].posy = 36+8*a;
			timeHud[a].size = SPRITE_SIZE(2, 1);
			timeHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize);
			timeHud[a].link  = 10+a;
					
			VDP_setSpriteP(a+9, &timeHud[a]);
		}
		
		timeHud[4].posx = 298;
		timeHud[4].posy = 76;
		timeHud[4].size = SPRITE_SIZE(2, 1);
		timeHud[4].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize);
		timeHud[4].link  = 14;
					
		VDP_setSpriteP(13, &timeHud[4]);
		
		// best time
		for( a = 0; a < 2; a++ ){
			bestHud[a].posx = 278;
			bestHud[a].posy = 28+8*a;
			bestHud[a].size = SPRITE_SIZE(2, 1);
			bestHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize);
			bestHud[a].link  = 15+a;
					
			VDP_setSpriteP(a+14, &bestHud[a]);
		}
		
		for( a = 2; a < 4; a++ ){
			bestHud[a].posx = 278;
			bestHud[a].posy = 36+8*a;
			bestHud[a].size = SPRITE_SIZE(2, 1);
			bestHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize);
			bestHud[a].link  = 15+a;
					
			VDP_setSpriteP(a+14, &bestHud[a]);
		}
		
		bestHud[4].posx = 278;
		bestHud[4].posy = 76;
		bestHud[4].size = SPRITE_SIZE(2, 1);
		bestHud[4].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize);
		bestHud[4].link  = 19;
					
		VDP_setSpriteP(18, &bestHud[4]);
		
		// descripcion del arma
		for( a = 0; a < 2; a++ ){
			weaponHud[a].posx = 24;
			weaponHud[a].posy = 40+8*a;
			weaponHud[a].size = SPRITE_SIZE(2, 1);
			weaponHud[a].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+20);
			weaponHud[a].link  = 20+a;
					
			VDP_setSpriteP(a+19, &weaponHud[a]);
		}
		
		weaponHud[1].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+22);
		VDP_setSpriteP(20, &weaponHud[1]);
		
		// numero de muertes
		killsHud.posx = 8;
		killsHud.posy = 31;
		killsHud.size = SPRITE_SIZE(2, 1);
		killsHud.tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize);
		killsHud.link  = 22;
					
		VDP_setSpriteP(21, &killsHud);
		
		// speed
		{miscHud[0].posx =  8;
		miscHud[0].posy =  168-27;
		miscHud[0].size = SPRITE_SIZE(1, 4);
		miscHud[0].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize);
		miscHud[0].link  = spriteMisc+1;
					
		VDP_setSpriteP(spriteMisc, &miscHud[0]);
		
		// km/h
		miscHud[1].posx =  8;
		miscHud[1].posy =  193;
		miscHud[1].size = SPRITE_SIZE(1, 3);
		miscHud[1].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+4);
		miscHud[1].link  = spriteMisc+2;
					
		VDP_setSpriteP(spriteMisc+1, &miscHud[1]);
		
		// energy
		miscHud[2].posx =  28;
		miscHud[2].posy =  161;
		miscHud[2].size = SPRITE_SIZE(1, 4);
		miscHud[2].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+7);
		miscHud[2].link  = spriteMisc+3;
					
		VDP_setSpriteP(spriteMisc+2, &miscHud[2]);
		
		// %
		miscHud[3].posx =  28;
		miscHud[3].posy =  208;
		miscHud[3].size = SPRITE_SIZE(1, 1);
		miscHud[3].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+11);
		miscHud[3].link  = spriteMisc+4;
					
		VDP_setSpriteP(spriteMisc+3, &miscHud[3]);}
		
		// lap
		{miscHud[4].posx =  283;
		miscHud[4].posy =  174;
		miscHud[4].size = SPRITE_SIZE(1, 2);
		miscHud[4].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+12);
		miscHud[4].link  = spriteMisc+5;
					
		VDP_setSpriteP(spriteMisc+4, &miscHud[4]);
		
		// of
		miscHud[5].posx =  276;
		miscHud[5].posy =  199;
		miscHud[5].size = SPRITE_SIZE(1, 2);
		miscHud[5].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+14);
		miscHud[5].link  = spriteMisc+6;
					
		VDP_setSpriteP(spriteMisc+5, &miscHud[5]);
		
		// pos
		miscHud[6].posx =  303;
		miscHud[6].posy =  174;
		miscHud[6].size = SPRITE_SIZE(1, 2);
		miscHud[6].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+16);
		miscHud[6].link  = spriteMisc+7;
					
		VDP_setSpriteP(spriteMisc+6, &miscHud[6]);
		
		// of
		miscHud[7].posx =  296;
		miscHud[7].posy =  199;
		miscHud[7].size = SPRITE_SIZE(1, 2);
		miscHud[7].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+14);
		miscHud[7].link  = spriteMisc+8;
					
		VDP_setSpriteP(spriteMisc+7, &miscHud[7]);}
		
		// time
		{miscHud[8].posx =  305;
		miscHud[8].posy =  6;
		miscHud[8].size = SPRITE_SIZE(1, 3);
		miscHud[8].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+18);
		miscHud[8].link  = spriteMisc+9;
					
		VDP_setSpriteP(spriteMisc+8, &miscHud[8]);
		
		// :
		miscHud[9].posx =  302;
		miscHud[9].posy =  44;
		miscHud[9].size = SPRITE_SIZE(1, 1);
		miscHud[9].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+21);
		miscHud[9].link  = spriteMisc+10;
					
		VDP_setSpriteP(spriteMisc+9, &miscHud[9]);
		
		// .
		miscHud[10].posx =  297;
		miscHud[10].posy =  67;
		miscHud[10].size = SPRITE_SIZE(1, 1);
		miscHud[10].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+22);
		miscHud[10].link  = spriteMisc+11;
					
		VDP_setSpriteP(spriteMisc+10, &miscHud[10]);
		
		// best
		miscHud[11].posx =  285;
		miscHud[11].posy =  6;
		miscHud[11].size = SPRITE_SIZE(1, 3);
		miscHud[11].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+23);
		miscHud[11].link  = spriteMisc+12;
					
		VDP_setSpriteP(spriteMisc+11, &miscHud[11]);
		
		// :
		miscHud[12].posx =  281;
		miscHud[12].posy =  44;
		miscHud[12].size = SPRITE_SIZE(1, 1);
		miscHud[12].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+21);
		miscHud[12].link  = spriteMisc+13;
					
		VDP_setSpriteP(spriteMisc+12, &miscHud[12]);
		
		// .
		miscHud[13].posx =  277;
		miscHud[13].posy =  67;
		miscHud[13].size = SPRITE_SIZE(1, 1);
		miscHud[13].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+22);
		miscHud[13].link  = spriteMisc+14;
					
		VDP_setSpriteP(spriteMisc+13, &miscHud[13]);}
		
		{// weapon
		miscHud[14].posx =  24;
		miscHud[14].posy =  8;
		miscHud[14].size = SPRITE_SIZE(1, 4);
		miscHud[14].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+26);
		miscHud[14].link  = spriteMisc+15;
					
		VDP_setSpriteP(spriteMisc+14, &miscHud[14]);
		
		// kills
		miscHud[15].posx =  8;
		miscHud[15].posy =  8;
		miscHud[15].size = SPRITE_SIZE(1, 3);
		miscHud[15].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize+30);
		miscHud[15].link  = spriteMisc+16;
					
		VDP_setSpriteP(spriteMisc+15, &miscHud[15]);}
	}
	
	// numeros gigante
	VDP_loadTileData( numberTiles, pos_vram_font-numbersTilesSize-miscTilesSize*2, 2, 1);
}

