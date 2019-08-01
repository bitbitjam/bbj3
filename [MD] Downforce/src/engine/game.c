#include "..\main.h"

const u8 speedXShip00[240] = {
	0,1,1,1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,
	4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
	4,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
	6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,

	9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
	10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
	12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
	14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,
	16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
	16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
};

const float speedYShip00[240] = {
	0.0,0.1,0.1,0.1,0.1,0.1,0.2,0.2,0.2,0.2,0.3,0.3,0.3,0.3,0.4,0.4,0.4,0.4,0.4,0.4,
	0.5,0.5,0.5,0.5,0.5,0.5,0.6,0.6,0.6,0.6,0.6,0.6,0.7,0.7,0.7,0.7,0.7,0.7,0.7,0.7,
	0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.8,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,1.0,1.0,1.0,1.0,
	1.0,1.0,1.0,1.0,1.1,1.1,1.1,1.1,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.2,1.3,1.3,1.3,1.3,
	1.3,1.3,1.3,1.3,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.4,1.5,1.5,1.5,1.5,1.5,1.5,1.5,1.5,
	1.6,1.6,1.6,1.6,1.6,1.6,1.6,1.6,1.7,1.7,1.7,1.7,1.7,1.7,1.7,1.7,1.8,1.8,1.8,1.8,
	
	1.9,1.9,1.9,1.9,1.9,1.9,1.9,1.9,1.9,1.9,1.9,1.9,1.9,1.9,1.9,1.9,1.9,1.9,1.9,1.9,
	2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,
	2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,2.1,
	2.2,2.2,2.2,2.2,2.2,2.2,2.2,2.2,2.2,2.2,2.2,2.2,2.2,2.2,2.2,2.2,2.2,2.2,2.2,2.2,
	2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,
	2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,2.4,
};

const u16 speedHudXShip00[240] = {
	0,2,4,6,8,10,13,16,19,22,25,28,32,36,40,44,49,54,59,65,
	71,77,83,90,97,104,111,118,125,132,139,146,153,160,167,174,181,188,195,202,
	209,215,222,230,235,240,245,250,255,260,265,270,275,280,285,290,295,300,310,315,
	320,325,330,335,340,345,350,355,360,365,370,375,380,385,390,395,400,410,415,420,
	425,430,435,440,445,450,455,460,465,470,475,480,485,490,495,500,510,515,520,525,
	530,535,540,545,550,555,560,565,570,575,580,585,590,595,600,610,615,620,625,630,
	
	630,633,636,639,642,645,648,651,654,657,660,663,666,669,672,675,678,681,684,687,
	690,693,696,699,702,705,708,711,714,717,720,723,726,729,732,735,738,741,744,747,
	750,753,756,759,762,765,768,771,772,774,775,777,778,780,783,786,787,784,781,789,
	790,798,804,808,814,814,824,828,834,838,844,848,854,858,864,868,874,878,884,888,
	904,909,914,919,924,929,934,939,944,949,954,959,964,969,974,979,984,989,999,999,
	999,999,974,952,930,898,886,874,852,830,798,786,774,752,730,698,686,674,652,630,
};

void movePlayerDown(){
	
	u8 a;
	
	if( scrollBPos_y < FIX32(player[0].initPosY)){

		if(player[0].sprite.posy > player[0].initPosY-2 && player[0].sprite.posy < player[0].initPosY+2 ){
			scrollAPos_y = fix32Add(scrollAPos_y, FIX32(speedYShip00[player[0].speedPos])<<1);
			scrollBPos_y = fix32Add(scrollBPos_y, FIX32(speedYShip00[player[0].speedPos])<<1);
					
			player[0].circuitPosY = fix32Add(player[0].circuitPosY, FIX32(speedYShip00[player[0].speedPos])<<1);	// posicion en el circuito
					
			for( a = 1; a < max_num_players; a++ )
				player[a].screenPosY = fix32Sub(player[a].screenPosY, FIX32(speedYShip00[player[0].speedPos])<<1);
		}
		else{
			player[0].screenPosY = fix32Add(player[0].screenPosY, FIX32(speedYShip00[player[0].speedPos])<<1);
				
			player[0].circuitPosY = fix32Add(player[0].circuitPosY, FIX32(speedYShip00[player[0].speedPos])<<1);
		}
	}
	else{
		player[0].screenPosY = fix32Add(player[0].screenPosY, FIX32(speedYShip00[player[0].speedPos])<<1);
			
		player[0].circuitPosY = fix32Add(player[0].circuitPosY, FIX32(speedYShip00[player[0].speedPos])<<1);
	}
}

void movePlayerUp(){
	
	u8 a;
	if( scrollBPos_y > 0 ){
		
		if(player[0].sprite.posy > player[0].initPosY-2 && player[0].sprite.posy < player[0].initPosY+2 ){
			scrollAPos_y = fix32Sub(scrollAPos_y, FIX32(speedYShip00[player[0].speedPos])<<1);
			scrollBPos_y = fix32Sub(scrollBPos_y, FIX32(speedYShip00[player[0].speedPos])<<1);
					
			player[0].circuitPosY = fix32Sub(player[0].circuitPosY, FIX32(speedYShip00[player[0].speedPos])<<1);	// posicion en el circuito
					
			for( a = 1; a < max_num_players; a++ )
				player[a].screenPosY = fix32Add(player[a].screenPosY, FIX32(speedYShip00[player[0].speedPos])<<1);
		}
		else{
			player[0].screenPosY = fix32Sub(player[0].screenPosY, FIX32(speedYShip00[player[0].speedPos])<<1);
					
			player[0].circuitPosY = fix32Sub(player[0].circuitPosY, FIX32(speedYShip00[player[0].speedPos])<<1);
		}
	}
	else{
		player[0].screenPosY = fix32Sub(player[0].screenPosY, FIX32(speedYShip00[player[0].speedPos])<<1);
			
		player[0].circuitPosY = fix32Sub(player[0].circuitPosY, FIX32(speedYShip00[player[0].speedPos])<<1);
	}
	
	
}

//////////////////////////////////////////////////////////////////////////////////////////////
//
// mueve el jugador
//
//////////////////////////////////////////////////////////////////////////////////////////////
void playerMove( u8 mode, u8 circuit  ){
	
	unsigned int keys = 0;
	u8 dirUp = 0, dirDown = 0, a;
	u16 tempPosX;
	
	// lee el pad
    keys = get_pad(0) & SEGA_CTRL_BUTTONS;
	
	// segun el modo de control las teclas cambian
	if( !mode ){
		if( keys & SEGA_CTRL_UP && player[0].speedPos)
			dirUp = 1;
		if( keys & SEGA_CTRL_DOWN && player[0].speedPos)
			dirDown = 1;
	}
	else{
		if( keys & SEGA_CTRL_LEFT && player[0].speedPos)
			dirUp = 1;
		if( keys & SEGA_CTRL_RIGHT && player[0].speedPos)
			dirDown = 1;
	}
	
	// colisiones
	if( circuit == 0 ){
		tempPosX      = ((player[0].circuitPosX+shipCollisionFront)>>3)%circuit00MapSizeX;
		player[0].collisionUpFront 	 = circuit00MaskMap[ tempPosX + (((fix32ToInt(player[0].circuitPosY)+shipCollisionUp  )>>3)*circuit00MapSizeX)]; // x + y
		player[0].collisionDownFront = circuit00MaskMap[ tempPosX + (((fix32ToInt(player[0].circuitPosY)+shipCollisionDown)>>3)*circuit00MapSizeX)];
		
		tempPosX      = ((player[0].circuitPosX)>>3)%circuit00MapSizeX;
		player[0].collisionUpRear 	 = circuit00MaskMap[ tempPosX + (((fix32ToInt(player[0].circuitPosY)+shipCollisionUp  )>>3)*circuit00MapSizeX)]; // x + y
		player[0].collisionDownRear = circuit00MaskMap[ tempPosX + (((fix32ToInt(player[0].circuitPosY)+shipCollisionDown)>>3)*circuit00MapSizeX)];
	}
	else if( circuit == 1 ){
		tempPosX      = ((player[0].circuitPosX+shipCollisionFront)>>3)%circuit00MapSizeX;
		player[0].collisionUpFront 	 = circuit01MaskMap[ tempPosX + (((fix32ToInt(player[0].circuitPosY)+shipCollisionUp  )>>3)*circuit00MapSizeX)]; // x + y
		player[0].collisionDownFront = circuit01MaskMap[ tempPosX + (((fix32ToInt(player[0].circuitPosY)+shipCollisionDown)>>3)*circuit00MapSizeX)];
		
		tempPosX      = ((player[0].circuitPosX)>>3)%circuit00MapSizeX;
		player[0].collisionUpRear 	 = circuit01MaskMap[ tempPosX + (((fix32ToInt(player[0].circuitPosY)+shipCollisionUp  )>>3)*circuit00MapSizeX)]; // x + y
		player[0].collisionDownRear = circuit01MaskMap[ tempPosX + (((fix32ToInt(player[0].circuitPosY)+shipCollisionDown)>>3)*circuit00MapSizeX)];
	}
	
	/*VDP_drawText("   ", APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), 0, 2, mode);
	VDP_drawText("   ", APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), 0, 3, mode);
	VDP_drawNumber(tempPosX, APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), 0, 2, mode);
	VDP_drawNumber(fix32ToInt(player[0].circuitPosY)>>3, APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), 0, 3, mode);
	
	VDP_drawNumber(fix32ToInt(player[0].circuitPosX), APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), 5, 2, mode);
	VDP_drawNumber(fix32ToInt(player[0].circuitPosY), APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), 5, 3, mode);
	
	VDP_drawNumber(collisionUp, APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), 0, 4, mode);
	VDP_drawNumber(collisionDown, APLAN, TILE_ATTR_FULL(PAL3, 1, 0, 0,  pos_vram_font), 0, 5, mode);*/

	
	// incrementamos la vuelta
	if( player[0].collisionUpFront == 5 && player[0].newLap == 0 )
		player[0].newLap = 1;
	if( player[0].collisionUpRear == 5 && player[0].newLap == 1 )	
		player[0].newLap = 2;
	
	if( player[0].collisionUpRear == 1 && player[0].collisionUpRear == 1 && player[0].newLap == 2 ){
		player[0].lap++;
		player[0].newLap = 0;
	}
	
	// turbo
	if( player[0].collisionUpFront == 3 || player[0].collisionDownFront == 3 )
		player[0].speedPos = 240;
	if( player[0].speedPos > 119 )
		player[0].speedPos--;
	
	// arma
	if( player[0].collisionUpFront == 4 || player[0].collisionDownFront == 4 ){
		
		player[0].weapon = 1;
		
		weaponHud[0].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize);
		weaponHud[1].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+2);
		VDP_setSpriteP(19, &weaponHud[0]);
		VDP_setSpriteP(20, &weaponHud[1]);
	}
	
	// repulsion
	if( player[0].collisionUpFront == 2 && player[0].collisionDownFront == 1 ){
		movePlayerDown();
		
		if( player[0].speedPos > 2 )
			player[0].speedPos -= 2;
		
		player[0].numFrame = 0;
		player[0].direction = dir_stand;
		
		player[0].sparksAnim = sparksTime;
		player[0].sparksPos = 1;
		
		if( player[0].energy > 0 )
			player[0].energy--;
	}
	else if( player[0].collisionDownFront == 2 && player[0].collisionUpFront == 1){
		movePlayerUp();
		
		if( player[0].speedPos > 4 )
			player[0].speedPos -= 4;
		
		player[0].numFrame = 0;
		player[0].direction = dir_stand;
		
		player[0].sparksAnim = sparksTime;
		player[0].sparksPos = 2;
		
		if( player[0].energy > 0 )
			player[0].energy--;
	}
	else if( player[0].collisionDownFront == 2 && player[0].collisionUpFront > 1){
		if(dirUp){
			movePlayerDown();
			player[0].sparksPos = 1;
		}
		else if(dirDown){
			movePlayerUp();
			player[0].sparksPos = 2;
		}
		
		if( player[0].speedPos > 4 )
			player[0].speedPos -= 4;
		
		player[0].numFrame = 0;
		player[0].direction = dir_stand;
		
		player[0].sparksAnim = sparksTime;
		
		if( player[0].energy > 0 )
			player[0].energy--;
	}
	// si la nave va hacia arriba
	else if(dirUp){

		// hay collision
		if( player[0].collisionUpFront == 2 ){
			if( player[0].speedPos > 4 )
				player[0].speedPos -= 4;
			
			player[0].numFrame = 0;
			player[0].direction = dir_stand;
			
			player[0].sparksAnim = sparksTime;
			player[0].sparksPos = 1;
			
			if( player[0].energy > 0 )
			player[0].energy--;
		}
		else{
			if( scrollBPos_y > 0 ){
				if(player[0].sprite.posy > player[0].initPosY-2 && player[0].sprite.posy < player[0].initPosY+2 ){
					scrollAPos_y = fix32Sub(scrollAPos_y, FIX32(speedYShip00[player[0].speedPos]));
					scrollBPos_y = fix32Sub(scrollBPos_y, FIX32(speedYShip00[player[0].speedPos]));
					
					player[0].circuitPosY = fix32Sub(player[0].circuitPosY, FIX32(speedYShip00[player[0].speedPos]));	// posicion en el circuito
					
					for( a = 1; a < max_num_players; a++ )
						player[a].screenPosY = fix32Add(player[a].screenPosY, FIX32(speedYShip00[player[0].speedPos]));
				}
				else{
					player[0].screenPosY = fix32Sub(player[0].screenPosY, FIX32(speedYShip00[player[0].speedPos]));
					
					player[0].circuitPosY = fix32Sub(player[0].circuitPosY, FIX32(speedYShip00[player[0].speedPos]));
				}
			}
			else{
				player[0].screenPosY = fix32Sub(player[0].screenPosY, FIX32(speedYShip00[player[0].speedPos]));
			
				player[0].circuitPosY = fix32Sub(player[0].circuitPosY, FIX32(speedYShip00[player[0].speedPos]));
			}

			if( player[0].direction != dir_up ){

				player[0].direction = dir_up;
				player[0].numFrame = 0;
			}
			else if( player[0].numFrame <= turn_frame_mid_ani )    // para que sea completo cambiar por turn_frame_full_ani
				player[0].numFrame++;
		}
    }
    else if(dirDown){
		if( player[0].collisionDownFront == 2 ){
			if( player[0].speedPos > 4 )
				player[0].speedPos -= 4;
			
			player[0].numFrame = 0;
			player[0].direction = dir_stand;
			
			player[0].sparksAnim = sparksTime;
			player[0].sparksPos = 2;
			
			if( player[0].energy > 0 )
			player[0].energy--;
		}
		else{
			if( scrollBPos_y < FIX32(player[0].initPosY-40)){

				if(player[0].sprite.posy > player[0].initPosY-2 && player[0].sprite.posy < player[0].initPosY+2 ){
					scrollAPos_y = fix32Add(scrollAPos_y, FIX32(speedYShip00[player[0].speedPos]));
					scrollBPos_y = fix32Add(scrollBPos_y, FIX32(speedYShip00[player[0].speedPos]));
					
					player[0].circuitPosY = fix32Add(player[0].circuitPosY, FIX32(speedYShip00[player[0].speedPos]));	// posicion en el circuito
					
					for( a = 1; a < max_num_players; a++ )
						player[a].screenPosY = fix32Sub(player[a].screenPosY, FIX32(speedYShip00[player[0].speedPos]));
				}
				else{
					player[0].screenPosY = fix32Add(player[0].screenPosY, FIX32(speedYShip00[player[0].speedPos]));
					
					player[0].circuitPosY = fix32Add(player[0].circuitPosY, FIX32(speedYShip00[player[0].speedPos]));
				}
			}
			else{
				player[0].screenPosY = fix32Add(player[0].screenPosY, FIX32(speedYShip00[player[0].speedPos]));
				
				player[0].circuitPosY = fix32Add(player[0].circuitPosY, FIX32(speedYShip00[player[0].speedPos]));
			}
			
			if( player[0].direction != dir_down ){

				player[0].direction = dir_down;
				player[0].numFrame = 0;
			}
			else if( player[0].numFrame <= turn_frame_mid_ani )
				player[0].numFrame++;
		}
    }
	else{

		/*if( player[0].collisionUpFront > 1 || player[0].collisionDownFront > 1 ){

			if( player[0].speedPos > 2 )

				player[0].speedPos -= 2;

		}*/

        if( player[0].numFrame > 0 )

            player[0].numFrame--;

        else

            player[0].direction = dir_stand;

    }

	// control de la aceleracion
    if( keys & SEGA_CTRL_A ){
		player[0].turbo = 1;
		if( player[0].speedPos < 119 )
			player[0].speedPos++;
		
		if( player[0].numFrameTurbo == 255 )
			player[0].numFrameTurbo = turbo_frame_basic_ani-1;
	}
	else{
		player[0].turbo = 0;
		player[0].numFrameTurbo = turbo_frame_basic_ani-1;
		if( player[0].speedPos > 0 && player[0].speedPos < 119 )
			player[0].speedPos--;
	}
	
	// control del arma
	if( keys & SEGA_CTRL_B ){
		player[0].weapon = 1;
		weaponHud[0].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+20);
		weaponHud[1].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+22);
		VDP_setSpriteP(19, &weaponHud[0]);
		VDP_setSpriteP(20, &weaponHud[1]);
	}

    // colisiones arriba y abajo (forma mas rapida pero menos ajustada)
    /*tempPosX = ((player[0].sprite.posx+scrollPos_x)>>3)+ (((player[0].sprite.posy)>>3)*circuit00MapSizeX);
    collisionUp = circuit00MaskMap[ tempPosX ];
	collisionDown = circuit00MaskMap[ tempPosX + (circuit00MapSizeX<<1)];*/
	
	/*VDP_drawNumber(player[0].sprite.posx, APLAN, TILE_ATTR_FULL(PAL2, 1, 0, 0,  pos_vram_font), 0, 1, mode );
	VDP_drawNumber(player[0].sprite.posy, APLAN, TILE_ATTR_FULL(PAL2, 1, 0, 0,  pos_vram_font), 0, 2, mode);
	VDP_drawNumber(temp, APLAN, TILE_ATTR_FULL(PAL2, 1, 0, 0,  pos_vram_font), 0, 3, mode);*/
}


//////////////////////////////////////////////////////////////////////////////////////////////
//
// actualiza el sprite del jugador
//
//////////////////////////////////////////////////////////////////////////////////////////////
void updatePlayerSprite( u8 ticks ){
	
    // cambia su frame a stand y el flip
    if( player[0].numFrame == 0 || player[0].collisionUpFront > 1 || player[0].collisionDownFront > 1 ){
		player[0].sprite.tile_attr = TILE_ATTR_FULL(PAL3, 1, 0, 0, shipTilesPos);
		player[0].shadow.tile_attr = TILE_ATTR_FULL(PAL3, 1, 0, 0, shipShadowTilesPos);
    }
    // cambia su frame a giro basico
    else if( player[0].numFrame == turn_frame_basic_ani ){
		if( player[0].direction == dir_down ){
			player[0].sprite.tile_attr = TILE_ATTR_FULL(PAL3, 1, 0, 0, shipTilesPos+shipFrameTilesSize);
			player[0].shadow.tile_attr = TILE_ATTR_FULL(PAL3, 1, 0, 0, shipShadowTilesPos+shipFrameTilesSize);
		}
		else{
			player[0].sprite.tile_attr = TILE_ATTR_FULL(PAL3, 1, 1, 0, shipTilesPos+shipFrameTilesSize);
			player[0].shadow.tile_attr = TILE_ATTR_FULL(PAL3, 1, 1, 0, shipShadowTilesPos+shipFrameTilesSize);
		}
    }
    // cambia su frame a giro parcial
    else if( player[0].numFrame == turn_frame_mid_ani ){
		if( player[0].direction == dir_down ){
			player[0].sprite.tile_attr = TILE_ATTR_FULL(PAL3, 1, 0, 0, shipTilesPos+shipFrameTilesSize*2);
			player[0].shadow.tile_attr = TILE_ATTR_FULL(PAL3, 1, 0, 0, shipShadowTilesPos+shipFrameTilesSize*2);
		}
		else{
			player[0].sprite.tile_attr = TILE_ATTR_FULL(PAL3, 1, 1, 0, shipTilesPos+shipFrameTilesSize*2);
			player[0].shadow.tile_attr = TILE_ATTR_FULL(PAL3, 1, 1, 0, shipShadowTilesPos+shipFrameTilesSize*2);
		}
    }
	
	// estela del turbo
	if( player[0].turbo ){
		
		player[0].numFrameTurbo++;
		player[0].trail.size = SPRITE_SIZE(4, 2);
		
		// animacion
		if( player[0].numFrameTurbo == turbo_frame_basic_ani )
			player[0].trail.tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, commonSpritesTilesPos+2);
		else if( player[0].numFrameTurbo == turbo_frame_mid_ani ){
			player[0].trail.tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, commonSpritesTilesPos+2+shipShadowTilesSize);
			player[0].numFrameTurbo = 0;
		}
		
		//player[0].trail.tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, commonSpritesTilesPos+2+(ticks%2)*shipShadowTilesSize);

		// parpadeo
		if( player[0].numFrameTurbo % 2 == 0 ){
		//if( ticks % 3 == 0 ){
			if( player[0].direction == dir_up )
				player[0].trail.posy = fix32ToInt(player[0].screenPosY)+2;
			else if( player[0].direction == dir_down )
				player[0].trail.posy = fix32ToInt(player[0].screenPosY)-2;
			else
				player[0].trail.posy = fix32ToInt(player[0].screenPosY);
			
			player[0].trail.posx = fix32ToInt(player[0].screenPosX)-28;
		}
		else	
			player[0].trail.posx = screen_width;
	}
	else{
		player[0].numFrameTurbo = 255;
		player[0].trail.size = SPRITE_SIZE(1, 1);
		
		// animacion
		player[0].trail.tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, commonSpritesTilesPos+(ticks%2));
		

		// parpadeo
		if( ticks % 3 == 0 ){
			if( player[0].direction == dir_up )
				player[0].trail.posy = fix32ToInt(player[0].screenPosY)+6;
			else if( player[0].direction == dir_down )
				player[0].trail.posy = fix32ToInt(player[0].screenPosY)+2;
			else
				player[0].trail.posy = fix32ToInt(player[0].screenPosY)+4;
			
			player[0].trail.posx = fix32ToInt(player[0].screenPosX)-4;
		}
		else	
			player[0].trail.posx = screen_width;
	}
	
	// chispas
	if( player[0].sparksAnim && player[0].sparksPos == 1 && player[0].speedPos > 0 ){
		player[0].sparks.tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, sparksTilePos+(ticks%3)*4);
		
		player[0].sparks.posx = fix32ToInt(player[0].screenPosX)-10;
		player[0].sparks.posy = fix32ToInt(player[0].screenPosY)-4;
		
		player[0].sparksAnim--;
	}
	else if( player[0].sparksAnim && player[0].sparksPos == 2 && player[0].speedPos > 0 ){
		player[0].sparks.tile_attr = TILE_ATTR_FULL(PAL2, 1, 1, 0, sparksTilePos+(ticks%3)*4);
		
		player[0].sparks.posx = fix32ToInt(player[0].screenPosX)-10;
		player[0].sparks.posy = fix32ToInt(player[0].screenPosY)+12;
		
		player[0].sparksAnim--;
	}
	else
		player[0].sparks.posx = screen_width;

	// mueve el sprite a la posicion x, y
	player[0].sprite.posx = fix32ToInt(player[0].screenPosX);
    player[0].sprite.posy = fix32ToInt(player[0].screenPosY);
	
	player[0].shadow.posx = fix32ToInt(player[0].screenPosX)-4;
    player[0].shadow.posy = fix32ToInt(player[0].screenPosY)+4;
	
	VDP_setSpriteP( shipSpriteId+0, 				   &player[0].sprite );
	VDP_setSpriteP( shipSpriteId+max_num_players,   &player[0].trail );
	VDP_setSpriteP( shipSpriteId+max_num_players*2, &player[0].sparks );
	VDP_setSpriteP( shipSpriteId+max_num_players*3, &player[0].shadow );
}


//////////////////////////////////////////////////////////////////////////////////////////////
//
// actualiza el sprite de la CPU
//
//////////////////////////////////////////////////////////////////////////////////////////////
void updateCpuSprites(){
	
	u8 a;
	
	for( a = 1; a < max_num_players; a++ ){
		
		/*if( fix32ToInt(player[a].screenPosX) > -32 )
			player[a].screenPosX = fix32Sub(player[a].screenPosX, FIX32(speedXShip00[player[0].speedPos]));
	
		player[a].sprite.posx = fix32ToInt(player[a].screenPosX);
		player[a].sprite.posy = fix32ToInt(player[a].screenPosY);
		
		player[a].shadow.posx = fix32ToInt(player[a].screenPosX)-4;
		player[a].shadow.posy = fix32ToInt(player[a].screenPosY)+4;*/
		
		if( fix32ToInt(player[a].screenPosX) < 330 && player[a].state == 2 )
			player[a].screenPosX = fix32Add(player[a].screenPosX, FIX32(speedXShip00[player[0].speedPos]));
		else if( fix32ToInt(player[a].screenPosX) >= 330 && player[a].state == 2 )
			player[a].state = 0;
		
		player[a].sprite.posx = fix32ToInt(player[a].screenPosX);
		player[a].sprite.posy = fix32ToInt(player[a].screenPosY);
		
		player[a].shadow.posx = fix32ToInt(player[a].screenPosX)-4;
		player[a].shadow.posy = fix32ToInt(player[a].screenPosY)+4;
	
		VDP_setSpriteP( shipSpriteId+a, 				     &player[a].sprite );
		VDP_setSpriteP( shipSpriteId+a+max_num_players  , &player[a].trail  );
		VDP_setSpriteP( shipSpriteId+a+max_num_players*3, &player[a].shadow );
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////
//
// actualiza el scroll
//
//////////////////////////////////////////////////////////////////////////////////////////////
void updateScroll( u8 circuit ){
	
	// posicion del scroll del mapa grande y control de la posicion del tile actual en el mapa grande
	static u8 scrollBg = 0;
	static u16 cx = 0, old_cx = 0;

	scrollBgTotal += speedXShip00[player[0].speedPos]; //8;
	scrollBg 	  += speedXShip00[player[0].speedPos]>>1;
	
	player[0].circuitPosX += speedXShip00[player[0].speedPos];	// posicion en el circuito
	
	cx = scrollBgTotal>>3;
	
    // actualizo el mapa redibujando una comlumna de tiles fuera de la pantalla
    if( old_cx != cx ){
        old_cx = cx;
		
		if( circuit == 0 ){
			
			if( player[0].speedPos > 119 ){
				VDP_updateBigTileMap( BPLAN, circuit00Map, cx+45, 0, circuit00MapSizeY, circuit00MapSizeX, TILE_ATTR_FULL( PAL1, 1, 0, 0, circuitTilesPos ));
				VDP_updateBigTileMap( BPLAN, circuit00Map, cx+46, 0, circuit00MapSizeY, circuit00MapSizeX, TILE_ATTR_FULL(PAL1,1,0,0, circuitTilesPos)); // si speed es mas que 8
			}
			else
				VDP_updateBigTileMap( BPLAN, circuit00Map, cx+46, 0, circuit00MapSizeY, circuit00MapSizeX, TILE_ATTR_FULL( PAL1, 1, 0, 0, circuitTilesPos ));
		}
		else if( circuit == 1 ){
			if( player[0].speedPos > 119 ){
				VDP_updateBigTileMap( BPLAN, circuit01Map, cx+45, 0, circuit00MapSizeY, circuit00MapSizeX, TILE_ATTR_FULL( PAL1, 1, 0, 0, circuitTilesPos ));
				VDP_updateBigTileMap( BPLAN, circuit01Map, cx+46, 0, circuit00MapSizeY, circuit00MapSizeX, TILE_ATTR_FULL(PAL1,1,0,0, circuitTilesPos)); // si speed es mas que 8
			}
			else
				VDP_updateBigTileMap( BPLAN, circuit01Map, cx+46, 0, circuit00MapSizeY, circuit00MapSizeX, TILE_ATTR_FULL( PAL1, 1, 0, 0, circuitTilesPos ));
		}
    }
    
	VDP_setHorizontalScroll(BPLAN, 0, -scrollBgTotal);
	VDP_setHorizontalScroll(APLAN, 0, -scrollBg);
	
	VDP_setVerticalScroll(BPLAN, 0, fix32ToInt(scrollBPos_y));
	VDP_setVerticalScroll(APLAN, 0, fix32ToInt(scrollAPos_y));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// void gameLoop()
// bucle del juego
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void gameLoop( u8 mode, u8 circuit ){
	
	u8 ticks = 0, a = 0;
	u8 mins = 0, secs = 0, decs = 0, minsBest = 0, secsBest = 0, decsBest = 0, temp = 0, change = 0, changeTime = 0, temp_lap = 2, keypress = 1;
	u16 temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
	unsigned int keys = 0;
	
	temp1 =  pos_vram_font-numbersTilesSize+((mins%10)<<1);
	temp2 =  pos_vram_font-numbersTilesSize+((secs/10)<<1);
	temp3 =  pos_vram_font-numbersTilesSize+((secs%10)<<1);
	temp4 =  pos_vram_font-numbersTilesSize+(decs<<1);
	
	// fade in de paleta
	if( circuit == 0 )
		VDP_initFading3(16, 31, palette_black, circuit00Pal, 32, 47, palette_black, commonSpritesPal, 48, 63, palette_black, ships00Pal, 30);    // from col, to col, pal src, pal dst, numframes);
    else if( circuit == 1 )
		VDP_initFading3(16, 31, palette_black, circuit01Pal, 32, 47, palette_black, commonSpritesPal, 48, 63, palette_black, ships00Pal, 30);
	
	while(VDP_doStepFading3())
        VDP_waitVSync();
	
	if( circuit == 0 )
		VDP_setPalette((u16 *)circuit00Pal, 16, 16);
	else if( circuit == 1 )
		VDP_setPalette((u16 *)circuit01Pal, 16, 16);

    VDP_setPalette((u16 *)commonSpritesPal, 32, 16);
    VDP_setPalette((u16 *)ships00Pal, 48, 16);
	
	// numeros de la salida
	if( mode ){
		VDP_fillTileMap( APLAN, number3VMap, 28, 13, 8, 6, TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize*2));
		SND_loadPcm_XGM(2, 0);
		delay(60);
		VDP_fillTileMap( APLAN, number2VMap, 28, 13, 8, 6, TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize*2));
		SND_loadPcm_XGM(3, 0);
		delay(60);
		VDP_fillTileMap( APLAN, number1VMap, 28, 13, 8, 6, TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize*2));
		SND_loadPcm_XGM(4, 0);
		delay(60);
	}
	else{
		VDP_fillTileMap( APLAN, number3HMap, 29, 12, 6, 8, TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize*2));
		SND_loadPcm_XGM(2, 0);
		delay(60);
		VDP_fillTileMap( APLAN, number2HMap, 29, 12, 6, 8, TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize*2));
		SND_loadPcm_XGM(3, 0);
		delay(60);
		VDP_fillTileMap( APLAN, number1HMap, 29, 12, 6, 8, TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize-miscTilesSize*2));
		SND_loadPcm_XGM(4, 0);
		delay(60);
	}
	if( circuit == 0 )
		VDP_fillTileMap( APLAN, bg00Map, 0, 0, bg00MapSizeX, bg00MapSizeY, TILE_ATTR_FULL(PAL1, 0, 0, 0, bgTilesPos));
	else if( circuit == 1 )
		VDP_fillTileMap( APLAN, bg01Map, 0, 0, bg00MapSizeX, bg00MapSizeY, TILE_ATTR_FULL(PAL1, 0, 0, 0, bgTilesPos));
	
	SND_loadPcm_XGM(5, 0);
	SND_loadSong_XGM(0);
	
	while(1){
		
		a++;
		if( a == 2 ){
			a = 0;
			ticks++;
		}
		
		temp++;
		change = 0;
		if( temp % 6 == 0 ){
			
			change = 1;
			
			decs++;
			if( decs == 10 ){
			
				secs++;
				decs = 0;
				if( secs == 60 ){
					secs = 0;
					mins++;
				}
			}
			
			temp1 =  pos_vram_font-numbersTilesSize+((mins%10)<<1);
			temp2 =  pos_vram_font-numbersTilesSize+((secs/10)<<1);
			temp3 =  pos_vram_font-numbersTilesSize+((secs%10)<<1);
			temp4 =  pos_vram_font-numbersTilesSize+(decs<<1);
		}
		
		// salida por energia
		if( player[0].energy == 0 )
			break;

		// mueve el jugador
        playerMove( mode, circuit );
		
		VDP_waitVSync();
		VDP_updateSprites();
		
		// actualiza el scroll
        updateScroll( circuit );
		
		timeHud[1].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, temp1);
		VDP_setSpriteP(minsSpriteId+1, &timeHud[1]);
				
		timeHud[2].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, temp2);
		VDP_setSpriteP(secsSpriteId, &timeHud[2]);
				
		timeHud[3].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, temp3);
		VDP_setSpriteP(secsSpriteId+1, &timeHud[3]);

		timeHud[4].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, temp4);
		VDP_setSpriteP(decsSpriteId, &timeHud[4]);
		
		// marcador de vuelta
		if( temp_lap != player[0].lap ){
			
			temp_lap = player[0].lap;
			
			if( temp_lap < 4 ){
				lapHud[0].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+(temp_lap<<1));
				VDP_setSpriteP(5, &lapHud[0]);
			}
			else
				break;
			
			VDP_setSpriteP(spriteMisc+4, &miscHud[4]);
			
			if( temp_lap == 2 ){
				
				bestHud[1].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, temp1);
				VDP_setSpriteP(minsSpriteId+6, &bestHud[1]);
						
				bestHud[2].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, temp2);
				VDP_setSpriteP(secsSpriteId+5, &bestHud[2]);
						
				bestHud[3].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, temp3);
				VDP_setSpriteP(secsSpriteId+6, &bestHud[3]);

				bestHud[4].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, temp4);
				VDP_setSpriteP(decsSpriteId+5, &bestHud[4]);
				
				minsBest = mins;
				secsBest = secs;
				decsBest = decs;
			}
			else{
				
				changeTime = 0;
				
				// mejoramos tiempo
				if( mins <= minsBest ){
					if( secs < secsBest )
						changeTime = 1;
					else if( secs == secsBest ){
						if( decs < decsBest )
							changeTime = 1;
					}
				}
				
				if( changeTime ){
					bestHud[1].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, temp1);
					VDP_setSpriteP(minsSpriteId+6, &bestHud[1]);
							
					bestHud[2].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, temp2);
					VDP_setSpriteP(secsSpriteId+5, &bestHud[2]);
							
					bestHud[3].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, temp3);
					VDP_setSpriteP(secsSpriteId+6, &bestHud[3]);

					bestHud[4].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, temp4);
					VDP_setSpriteP(decsSpriteId+5, &bestHud[4]);
					
					minsBest = mins;
					secsBest = secs;
					decsBest = decs;
				}
			}
			
			mins = secs = decs = 0;
		}
		
		// marcador de velocidad
		speedHud[0].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+((speedHudXShip00[player[0].speedPos]/100)<<1));
		VDP_setSpriteP(0, &speedHud[0]);
		speedHud[1].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+(((speedHudXShip00[player[0].speedPos]/10)%10)<<1));
		VDP_setSpriteP(1, &speedHud[1]);
		speedHud[2].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+(((speedHudXShip00[player[0].speedPos]%100)%10)<<1));
		VDP_setSpriteP(2, &speedHud[2]);
		
		// energia
		energyHud[0].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+((player[0].energy/10)<<1));		
		VDP_setSpriteP(3, &energyHud[0]);
		energyHud[1].tile_attr = TILE_ATTR_FULL(PAL2, 1, 0, 0, pos_vram_font-numbersTilesSize+((player[0].energy%10)<<1));		
		VDP_setSpriteP(4, &energyHud[1]);

		
        // actualiza el sprite del jugador
        updatePlayerSprite( ticks );
		
		// actualiza los sprites de la CPU
		updateCpuSprites();
	}
	
	//////////////////////////////////////////////////////////////
	// marcador de tiempo final, mejor vuelta
	// fade out de paleta
	if( circuit == 0 )
		VDP_initFading3(16, 31, circuit00Pal, palette_black, 32, 47, commonSpritesPal, palette_black, 48, 63, ships00Pal, palette_black, 30);    // from col, to col, pal src, pal dst, numframes);
    else if( circuit == 1 )
		VDP_initFading3(16, 31, circuit01Pal, palette_black, 32, 47, commonSpritesPal, palette_black, 48, 63, ships00Pal, palette_black, 30);
	
	while(VDP_doStepFading3())
        VDP_waitVSync();
	
	// borro los planos
    VDP_clearPlan(APLAN);
    VDP_clearPlan(BPLAN);
	
	VDP_setHorizontalScroll(BPLAN, 0, 0);
    VDP_setHorizontalScroll(APLAN, 0, 0);
    VDP_setVerticalScroll(BPLAN, 0, 0);
	
	bestHud[0].link = 0;
	VDP_setSpriteP(0, &bestHud[0]);
	
    for( a = 3; a < 7; a++)
        VDP_setVerticalScroll(APLAN, a, 0);
	
	if( player[0].energy > 0 ){
		if( mode ){
			VDP_loadTileData( titleFontVTiles, pos_vram_font, titleFontTilesSize, 1);
			
			VDP_drawText("congratulations", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 28, 6, mode);
			
			VDP_drawText("your best lap is 0 :  +", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 22, 2, mode);
			VDP_drawNumber(minsBest, BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 22, 20, mode);
			if( secsBest > 10 )
				VDP_drawNumber(secsBest, BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 22, 22, mode);
			else
				VDP_drawNumber(secsBest, BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 22, 23, mode);
			VDP_drawNumber(decsBest, BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 22, 25, mode);
		}
		else{
			VDP_loadTileData( titleFontHTiles, pos_vram_font, titleFontTilesSize, 1);
			
			VDP_drawText("congratulations", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 12, 8, mode);
			
			VDP_drawText("your best lap is 0 :  +", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 7, 12, mode);
			VDP_drawNumber(minsBest, BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 25, 12, mode);
			if( secsBest > 10 )
				VDP_drawNumber(secsBest, BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 27, 12, mode);
			else
				VDP_drawNumber(secsBest, BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 28, 12, mode);
			VDP_drawNumber(decsBest, BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 30, 12, mode);
		}
		
		VDP_initFading1(0, 15, palette_black, titleFontPal, 30);
		while(VDP_doStepFading1())
			VDP_waitVSync();
		
		
		change = 0;
		while(1){
			
			change++;
			if( mode ){
				if( change % 3 == 0 )
					VDP_drawText("congratulations", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 28, 6, mode);
				else
					VDP_drawText("CONGRATULATIONS", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 28, 6, mode);
			}
			else{
				if( change % 3 == 0 )
					VDP_drawText("congratulations", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 12, 8, mode);
				else
					VDP_drawText("CONGRATULATIONS", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 12, 8, mode);
			}
			
			
			// lee el pad
			keys = get_pad(0) & SEGA_CTRL_BUTTONS;
			
			// salimos
			if(keys & SEGA_CTRL_START && keypress == 0){

				keypress = 1;

				break;
			}
			else if(!(keys & SEGA_CTRL_START))
				keypress = 0;
			
			VDP_waitVSync();
		}
	}
	// muerte por energia
	else{
		if( mode ){
			VDP_loadTileData( titleFontVTiles, pos_vram_font, titleFontTilesSize, 1);
			
			VDP_drawText("you died) loser", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 28, 6, mode);
			
			VDP_drawText("your best lap is 00:00+0", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 22, 2, mode);
			VDP_drawNumber(minsBest, BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 22, 20, mode);
			if( secsBest > 10 )
				VDP_drawNumber(secsBest, BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 22, 22, mode);
			else
				VDP_drawNumber(secsBest, BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 22, 23, mode);
			VDP_drawNumber(decsBest, BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 22, 25, mode);
		}
		else{
			VDP_loadTileData( titleFontHTiles, pos_vram_font, titleFontTilesSize, 1);
			
			VDP_drawText("you died) loser", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 12, 8, mode);
			
			VDP_drawText("your best lap is 00:00+0", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 7, 12, mode);
			VDP_drawNumber(minsBest, BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 25, 12, mode);
			if( secsBest > 10 )
				VDP_drawNumber(secsBest, BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 27, 12, mode);
			else
				VDP_drawNumber(secsBest, BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 28, 12, mode);
			VDP_drawNumber(decsBest, BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 30, 12, mode);
		}
		
		VDP_initFading1(0, 15, palette_black, titleFontPal, 30);
		while(VDP_doStepFading1())
			VDP_waitVSync();
		
		
		change = 0;
		while(1){
			
			change++;
			if( mode ){
				if( change % 3 == 0 )
					VDP_drawText("you died) loser", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 28, 6, mode);
				else
					VDP_drawText("YOU DIED  LOSER", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 28, 6, mode);
			}
			else{
				if( change % 3 == 0 )
					VDP_drawText("you died) loser", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 12, 8, mode);
				else
					VDP_drawText("YOU DIED  LOSER", BPLAN, TILE_ATTR_FULL(PAL0, 1, 0, 0,  pos_vram_font), 12, 8, mode);
			}
			
			
			// lee el pad
			keys = get_pad(0) & SEGA_CTRL_BUTTONS;
			
			// salimos
			if(keys & SEGA_CTRL_START && keypress == 0){

				keypress = 1;

				break;
			}
			else if(!(keys & SEGA_CTRL_START))
				keypress = 0;
			
			VDP_waitVSync();
		}
	}
	
	SND_stopPlay_XGM();
}

