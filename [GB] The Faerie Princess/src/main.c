#include <gb/gb.h>
#include "tiles.c"
#include "sprites.c"
#include "scenes.c"
#include "maps.c"

#define BANISH 224

void initGame();																
void updatePlayer();															
void init();																	
void updateSwitches();															
void start_Screen();
void over_Screen();
void win_screen();
void updateHealth();
void moveDragon();
void clear();
void showCredits();
UINT8 collisionCheck(UINT8, UINT8, UINT8, UINT8, UINT8, UINT8, UINT8, UINT8);


UINT8 i, j, k, l, m, health = 8, enemyHealth = 8;
UINT8 dir, sdir, spriteNumber, spear[2];

// This holds the position of the player
// X: [0]
// Y: [1]
UINT8 player[2];

// This holds the positions of the three fireballs and all 4 tiles of dragon
// Fireball 1 [0][1]
// Fireball 2 [2][3]
// Fireball 3 [4][5]
// Dragon
UINT8 enemyPositions[38];

UINT8 pressA[1] = {0x44};

// Time is used in all scenes
UBYTE time;  

void main(){
	
	init();
	start_Screen();
	initGame();
	
	m = 0;
	
	while(1) {
		
		updatePlayer();
		moveDragon();
		updateHealth();
		updateSwitches();
		time++;
		wait_vbl_done();
		
	}

}

void updateSwitches() {
	
	HIDE_WIN;
	SHOW_SPRITES;
	SHOW_BKG;
	
}

void init() {
	
	DISPLAY_ON;
	set_sprite_data(0, 37, sprites);
	set_bkg_data(0, 87, FloorTiles);
	
}

void initGame(){

	player[0] = 120;
	player[1] = 94;
	
	spriteNumber = 0;
	
	set_sprite_tile(0,0);
	
	dir = 0;
	set_bkg_tiles(0,0,20,18,area1);	
	set_bkg_tiles(0,16,20,2,bottomThird);
	updateHealth();

	j = 0;
	l = 80;
	
	enemyPositions[0] = 90;
	enemyPositions[1] = 33;
	
	enemyPositions[2] = 90;
	enemyPositions[3] = 33;
	
	enemyPositions[4] = 90;
	enemyPositions[5] = 33;
	
	enemyPositions[6] = 80;
	enemyPositions[7] = 33;
	
	enemyPositions[8] = 88;
	enemyPositions[9] = 33;
	
	enemyPositions[10] = 80;
	enemyPositions[11] = 41;
	
	enemyPositions[12] = 88;
	enemyPositions[13] = 41;
	
}

void updatePlayer() {
	
	// UP
	if (joypad() & J_UP) {
			
		player[1]--;
		dir = 1;
		
		spriteNumber = 4;
			
		if (player[1] == 31) {
				
			player[1] = 32;
		}
	} else

	// DOWN
	if (joypad() & J_DOWN) {
			
		player[1]++;
		dir = 2;
		
		spriteNumber = 0;
			
		if (player[1] == 111) {
			
			player[1] = 110;
		}
	} else

	// LEFT
	if (joypad() & J_LEFT) {
		
		player[0]--;
		dir = 3;
		
		spriteNumber = 8;
		
		if (player[0] == 23) {
			
			player[0] = 24;
		}
	} else	
	
	// RIGHT
	if (joypad() & J_RIGHT) {
		
		player[0]++;
		dir = 4;
		
		spriteNumber = 12;
		
		if (player[0] == 137) {
			
			player[0] = 136;
		
		}
	}

	// B
	if (joypad() & J_B && j == 0 && (time&0x13) == 0) {

		spear[0] = player[0];
		spear[1] = player[1];
		
		if(dir == 1) {
			set_sprite_tile(4, 32);
			spear[0] = spear[0] + 4;
		} else if(dir == 2) {
			set_sprite_tile(4, 34);
			spear[0] = spear[0] + 4;
			spear[1] = spear[1] + 9;
		} else if(dir == 3) {
			set_sprite_tile(4, 35);
			spear[1] = spear[1] + 8;
		} else if(dir == 4) {
			set_sprite_tile(4, 33);
			spear[0] = spear[0] + 8;
			spear[1] = spear[1] + 8;
		}
		
		
		move_sprite(4, player[0], player[1]);
		j = 1;
		
		sdir = dir;
		
	}
	
	if(j == 1) {
		
		if(sdir == 1) {
			spear[1] = spear[1] - 2;
		} else if(sdir == 2) {
			spear[1] = spear[1] + 2;
		} else if(sdir == 3) {
			spear[0] = spear[0] - 2;
		} else if(sdir == 4) {
			spear[0] = spear[0] + 2;
		}
		
		move_sprite(4, spear[0], spear[1]);
				
		if (spear[1] <= 31 || spear[1] >= 122 || spear[0] <= 23 || spear[0] >= 146) {
			j = 0;
			move_sprite(4, BANISH, 144); //Hide the spear just off screen
		}
	}
	
	// Colliding with fireball1?
	if (collisionCheck(player[0], player[1], 8, 8, enemyPositions[0], enemyPositions[1], 8, 8) == 1) {
		health--;
		enemyPositions[0] = BANISH; // Reset fireball1
	}
	
	// Colliding with fireball2?
	if (collisionCheck(player[0], player[1], 8, 8, enemyPositions[2], enemyPositions[3], 8, 8) == 1) {
		health--;
		enemyPositions[2] = BANISH; // Reset fireball12
	}
	
	// Colliding with fireball3?
	if (collisionCheck(player[0], player[1], 8, 8, enemyPositions[4], enemyPositions[5], 8, 8) == 1) {
		health--;
		enemyPositions[4] = BANISH; // Banish fireball3
	}
	
	// Upper-left of dragon
	if (collisionCheck(player[0], player[1], 8, 8, enemyPositions[6], enemyPositions[7], 8, 8) == 1) {
		health--;
		player[0]--;
	}
	
	// Upper-right of dragon
	if (collisionCheck(player[0], player[1], 8, 8, enemyPositions[8], enemyPositions[9], 8, 8) == 1) {
		health--;
		player[0]++;
	}
	
	// Lower-left of dragon
	if (collisionCheck(player[0], player[1], 8, 8, enemyPositions[10], enemyPositions[11], 8, 8) == 1) {
		health--;
		player[0]--;
		player[1]++;
	}
	
	// Lower-right of dragon
	if (collisionCheck(player[0], player[1], 8, 8, enemyPositions[12], enemyPositions[13], 8, 8) == 1) {
		health--;
		player[0]++;
		player[1]++;
	}
	
	// Spear checks
	
	// Upper-left of dragon
	if (collisionCheck(spear[0], spear[1], 8, 8, enemyPositions[6], enemyPositions[7], 8, 8) == 1) {
		enemyHealth--;
		spear[0] = BANISH; // Banish spear
	}
	
	// Upper-right of dragon
	if (collisionCheck(spear[0], spear[1], 8, 8, enemyPositions[8], enemyPositions[9], 8, 8) == 1) {
		enemyHealth--;
		spear[0] = BANISH; // Banish spear
	}
	
	// Lower-left of dragon
	if (collisionCheck(spear[0], spear[1], 8, 8, enemyPositions[10], enemyPositions[11], 8, 8) == 1) {
		enemyHealth--;
		spear[0] = BANISH; // Banish spear
	}
	
	// Lower-right of dragon
	if (collisionCheck(spear[0], spear[1], 8, 8, enemyPositions[12], enemyPositions[13], 8, 8) == 1) {
		enemyHealth--;
		spear[0] = BANISH; // Banish spear
	}
	
	set_sprite_tile(0, spriteNumber);
	set_sprite_tile(1, spriteNumber + 1);
	set_sprite_tile(2, spriteNumber + 2);
	set_sprite_tile(3, spriteNumber + 3);
	
	move_sprite(0, player[0], player[1]);
	move_sprite(1, player[0], player[1] + 8);
	move_sprite(2, player[0] + 8, player[1]);
	move_sprite(3, player[0] + 8, player[1] + 8);
	
}

void start_Screen() {
	
	i = 0;
	k = 0;
	
	set_bkg_tiles(0,5,20,10,box);
	set_bkg_tiles(2,7,17,5,scene1);
	
	while(1) {
		
		updateSwitches();
		time++;
		
		if((time&0x78) == 0) {
			pressA[0] = 0x44;
		} else {
			pressA[0] = 0x43;
		}
		
		set_bkg_tiles(18, 13, 1, 1, pressA);
	
		if (joypad() & J_A && (time - i) > 50) {
			
			k++;
			i = time;
			
			switch(k) {
				case 2:
					
					set_bkg_tiles(0,5,20,10,box);
					set_bkg_tiles(2,7,13,5,scene2);
					break;
				case 3:
				
					set_bkg_tiles(0,5,20,10,box);
					set_bkg_tiles(2,7,16,5,scene3);
					break;
				case 4:
					
					set_bkg_tiles(0,5,20,10,box);
					set_bkg_tiles(2,7,14,5,scene4);
					break;
				case 5:
					
					set_bkg_tiles(0,5,20,10,box);
					set_bkg_tiles(2,7,15,3,scene5);
					break;
				case 6:
					
					set_bkg_tiles(0,5,20,10,box);
					set_bkg_tiles(2,7,14,3,scene6);
					break;
				case 7:
					
					set_bkg_tiles(0,5,20,10,box);
					set_bkg_tiles(2,7,13,5,scene7);
					break;
				case 8:
					
					set_bkg_tiles(0,5,20,10,box);
					set_bkg_tiles(2,7,17,5,scene8);
					break;
			}
			
			if(k == 9) {
				return;
			}
			
		}
	
		wait_vbl_done();
	}
	
}

void updateHealth() {
	
	if(health <= 4) {
		over_Screen();
	}
	
	if(enemyHealth <= 4) {
		win_screen();
	}
	
	// Reset HUD
	set_bkg_tiles(0,16,20,2,bottomThird);
	
	// Loop for number of hearts
	for(i = 4; i != health; i++) {
		set_bkg_tiles(5 + ((i - 4) * 3), 16, 2, 2, heart);
	}
}

void over_Screen() {
	
	// Clear screen
	clear();
	
	set_bkg_tiles(0,5,20,10,box);
	set_bkg_tiles(2,7,14,5,over);
	
	while(1) {
		
		HIDE_WIN;
		SHOW_BKG;
		HIDE_SPRITES;
		wait_vbl_done();
	}
	
}

void win_screen() {
	
	clear();
	set_bkg_tiles(0,5,20,10,box);
	set_bkg_tiles(2,7,15,5,win);
	
	while(1) {
		
		HIDE_WIN;
		SHOW_BKG;
		HIDE_SPRITES;
		
		time++;
		
		if((time&0x78) == 0) {
			pressA[0] = 0x44;
		} else {
			pressA[0] = 0x43;
		}
		
		set_bkg_tiles(18, 13, 1, 1, pressA);
		
		if(joypad() & J_A) {
			clear();
			showCredits(); // Go to credits, never to return
		}
		
		wait_vbl_done();
	}
}

void moveDragon() {
	
	set_sprite_tile(5, 16);
	set_sprite_tile(6, 17);
	set_sprite_tile(7, 18);
	set_sprite_tile(8, 19);
	set_sprite_tile(9, 20); //Fireball
	set_sprite_tile(10, 20); //Fireball
	set_sprite_tile(11, 20); //Fireball
	
	move_sprite(5, enemyPositions[6], enemyPositions[7]); //Row one
	move_sprite(6, enemyPositions[8], enemyPositions[9]); // Row one
	move_sprite(7, enemyPositions[10], enemyPositions[11]); // Row two
	move_sprite(8, enemyPositions[12], enemyPositions[13]); // Row two
	
	if((time&0x28) == 0) {
		
		if(enemyPositions[0] == BANISH) {
		
			enemyPositions[0] = enemyPositions[6];
			enemyPositions[1] = 43;
		
		}
	
		if(enemyPositions[2] == BANISH) {
			
			enemyPositions[2] = enemyPositions[6];
			enemyPositions[3] = 43;
			
		}
		
		if(enemyPositions[4] == BANISH) {
			
			enemyPositions[4] = enemyPositions[6];
			enemyPositions[5] = 43;
			
		}
		
	}
	
	enemyPositions[0]++;
	enemyPositions[1]++;
	
	enemyPositions[2]--;
	enemyPositions[3]++;
	
	enemyPositions[5]++;
	
	move_sprite(9, enemyPositions[0], enemyPositions[1]);
	move_sprite(10, enemyPositions[2], enemyPositions[3]);
	move_sprite(11, enemyPositions[4], enemyPositions[5]);
	
	if (enemyPositions[1] <= 31 || enemyPositions[1] >= 122 || enemyPositions[0] <= 23 || enemyPositions[0] >= 146) {
		enemyPositions[0] = BANISH;
		move_sprite(9, enemyPositions[0], 144);
	}
	
	if (enemyPositions[2] <= 31 || enemyPositions[3] >= 122 || enemyPositions[2] <= 23 || enemyPositions[3] >= 146) {
		enemyPositions[2] = BANISH;
		move_sprite(10, enemyPositions[2], 144);
	}
	
	if (enemyPositions[4] <= 31 || enemyPositions[5] >= 122 || enemyPositions[4] <= 23 || enemyPositions[5] >= 146) {
		enemyPositions[4] = BANISH;
		move_sprite(11, enemyPositions[4], 144);
	}
	
	if(m == 0) {
		enemyPositions[6]--;
		enemyPositions[8]--;
		enemyPositions[10]--; 
		enemyPositions[12]--;
	} else {
		enemyPositions[6]++;
		enemyPositions[8]++;
		enemyPositions[10]++; 
		enemyPositions[12]++;
	}

	if(enemyPositions[6] < 39) {
		m = 1;
	}
	
	if(enemyPositions[6] > 140) {
		m = 0;
	}
	
}

void clear() {
	// Clear screen
	for(i = 0; i != 20; i++) {
		for(k = 0; k != 18; k++) {
			set_bkg_tiles(i,k,1,1,FloorTiles[0]);
		}
	}
}

void showCredits() {
	while(1) {
		set_bkg_tiles(1,7,18,5,credits);
	}
}

////////////////////////////////////////////////////////////////////////////////
// COLLISION CHECKER - SIMPLE RECTANGLE COLLISION CHECKING
// RETURNS 1 IF OVERLAPPING
// Code by Ryan Carson @refreshgamesuk
UINT8 collisionCheck(UINT8 x1, UINT8 y1, UINT8 w1, UINT8 h1, UINT8 x2, UINT8 y2, UINT8 w2, UINT8 h2) {

	if ((x1 < (x2+w2)) && ((x1+w1) > x2) && (y1 < (h2+y2)) && ((y1+h1) > y2)) {
		
		return 1;
	
	} else {
		
		return 0;
	
	}

}
