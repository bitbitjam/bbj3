////////////////////////////////////////////////////////////////////////////////
// DEMOGAME.C
//------------------------------------------------------------------------------
// FAIRLY MINIMAL GAME DEMO FOR GETTING STARTED WITH GBDK
// BY REFRESH GAMES
//------------------------------------------------------------------------------
// THIS IS INTENDED TO BE A BASE POINT FOR ANYONE TO CUSTOMISE AND ADD TO SO
// THEY CAN MAKE THEIR OWN GAMEBOY GAMES, HENCE THE COMMENTS!
//------------------------------------------------------------------------------
// WEB: refreshgames.co.uk
// TWITTER: @refreshgamesuk
////////////////////////////////////////////////////////////////////////////////

#define SHOW_PLAYER
#define SHOW_BG
#define SHOW_ENEMY
#ifdef SHOW_ENEMY
  #define ENABLE_COLLISION
#endif
#define PLAY_SOUND

#include <rand.h>	// INCLUDE RANDOM FUNCTIONS
#include <gb/gb.h>	// INCLUDE GBDK FUNCTION LIBRARY
#include <gb/hardware.h>	// INCLUDE HANDY HARDWARE REFERENCES

// FUNCTION DECLARATIONS
void initGame();	// INITIALISE OUR GAME
#ifdef SHOW_PLAYER
void updatePlayer();	// UPDATE OUR PLAYER
#endif
#ifdef ENABLE_COLLISION
UINT8 collisionCheck(UINT8, UINT8, UINT8, UINT8, UINT8, UINT8, UINT8, UINT8); 	// SIMPLE RECT TO RECT CHECK
#endif

// VARIABLE DECLARATIONS - STORED IN RAM
UINT8 i, j, t;	// GENERIC LOOPING VARIABLE

#ifdef SHOW_PLAYER
UINT8 playerX, playerY;	// PLAYER CO-ORDINATES
#endif
#ifdef SHOW_ENEMY
UINT8 eX[10], eY[10];	// ENEMY CO-ORDINATES
#endif
UINT8 lastKeys;	// HOLDS KEYS FOR THE PREVIOUS FRAME
#ifdef SHOW_BG
UINT8 randomBkgTiles[20];	// CONTAINS RANDOM DATA FOR OUR BKG
#endif

// SPRITE DATA - 14 SPRITES - STORED IN ROM
const unsigned char sprites[] = {
  0x3C,0x3C,0x42,0x42,0xA9,0xA9,0xA9,0xA9,0x81,0x81,0x91,0x91,0x42,0x42,0x3C,0x3C,
  0x3C,0x3C,0x42,0x42,0x81,0x81,0xED,0xED,0x81,0x81,0x91,0x91,0x42,0x42,0x3C,0x3C,
  0x99,0x81,0x42,0x5A,0x24,0x3C,0x99,0x7E,0x99,0x7E,0x24,0x3C,0x42,0x5A,0x99,0x81,
  0x38,0x04,0x7C,0x02,0x5C,0x22,0x5C,0x22,0x5C,0x22,0x5C,0x22,0x7C,0x02,0x38,0x04,
  0x00,0x00,0x3E,0x3E,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x3E,0x3E,0x00,0x00,
  0x00,0x00,0x1C,0x1C,0x3C,0x3C,0x6C,0x6C,0x0C,0x0C,0x0C,0x0C,0x7F,0x7F,0x00,0x00,
  0x00,0x00,0x3E,0x3E,0x63,0x63,0x03,0x03,0x1E,0x1E,0x70,0x70,0x7F,0x7F,0x00,0x00,
  0x00,0x00,0x7F,0x7F,0x03,0x03,0x3E,0x3E,0x07,0x07,0x43,0x43,0x3E,0x3E,0x00,0x00,
  0x00,0x00,0x60,0x60,0x6C,0x6C,0x6C,0x6C,0x7F,0x7F,0x0C,0x0C,0x0C,0x0C,0x00,0x00,
  0x00,0x00,0x7F,0x7F,0x60,0x60,0x7E,0x7E,0x03,0x03,0x63,0x63,0x3E,0x3E,0x00,0x00,
  0x00,0x00,0x3F,0x3F,0x60,0x60,0x7E,0x7E,0x63,0x63,0x63,0x63,0x3E,0x3E,0x00,0x00,
  0x00,0x00,0x7F,0x7F,0x03,0x03,0x06,0x06,0x0C,0x0C,0x18,0x18,0x30,0x30,0x00,0x00,
  0x00,0x00,0x3E,0x3E,0x63,0x63,0x63,0x63,0x3E,0x3E,0x63,0x63,0x3E,0x3E,0x00,0x00,
  0x00,0x00,0x3E,0x3E,0x63,0x63,0x63,0x63,0x3F,0x3F,0x03,0x03,0x7E,0x7E,0x00,0x00
};

#ifdef SHOW_BG
//BACKGROUND DATA - 4 SPRITES - STORED IN ROM
const unsigned char myBkgData[] = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x08,0x00,0x08,0x00,0x36,0x00,0x08,0x00,0x08,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x20,0x00,0x50,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x0E,0x00,0x04,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x50,0x00,0x20,0x00,0x50,0x00,0x00,0x00
};
#endif


////////////////////////////////////////////////////////////////////////////////
// MAIN FUNCTION

	void main(){
	
	initGame();	// RAN ONCE AT STARTUP
	
// GAME LOOP START

		while(1){
		
#ifdef SHOW_PLAYER
		updatePlayer();	// UPDATE PLAYER
#endif
				
		HIDE_WIN;	// SHOW WINDOW LAYER
		SHOW_SPRITES;	// HIDE SPRITES LAYER
#ifdef SHOW_BG
		SHOW_BKG;	// SHOW BACKGROUND LAYER
#endif
		
#ifdef SHOW_PLAYER
		lastKeys = joypad();	// UPDATE OUR KEYPRESSES
#endif
		wait_vbl_done();	// WAIT FOR VBLANK TO FINISH - ENSURES 60 FRAMES PER SECOND MAXIMUM
		}

// GAME LOOP END

	}


////////////////////////////////////////////////////////////////////////////////
// INIT GAME

	void initGame(){
	
	DISPLAY_ON;	// TURNS ON THE GAMEBOY LCD
#ifdef PLAY_SOUND
	NR52_REG = 0x80U;	// TURN SOUND ON
	NR51_REG = 0x11;	// ENABLE SOUND CHANNELS
	NR50_REG = 0x44;//0x1F;	// VOLUME MAX = 0x77, MIN = 0x00	
#endif
	
	initrand(DIV_REG);	// SEED OUR RANDOMIZER
	
	set_sprite_data(0, 14, sprites);	// STORE OUR SPRITE DATA AT THE START OF SPRITE VRAM
#ifdef SHOW_BG
	set_bkg_data(0, 4, myBkgData);	// STORE OUR BKG DATA AT THE START OF BKG VRAM - NOTE, THE WINDOW LAYER SHARED THE BKG VRAM BY DEFAULT
#endif
#ifdef SHOW_PLAYER
	playerX = 64;	// PLAYERS INITAL X POSITION
	playerY = 64;	// PLAYERS INITAL Y POSITION
	

	set_sprite_tile(0,0);	//PLAYERS SPRITE TILE - 0
#endif
#ifdef SHOW_ENEMY
	
		for (i=0; i !=10; i++){	// OUR ENEMY POSITION LOOP - NOTE, USE !=, NOT < TO SCRAPE BACK SOME CPU TIME
		
		eX[i] = 16+(((UBYTE)rand()) >> 1);	// RANDOM X POSITION 16 - 144
		eY[i] = 16+(((UBYTE)rand()) >> 1);	// RANDOM Y POSITION 16 - 144
		set_sprite_tile(i+1, 2);	// ENEMIES SPRITE TILE - SET TO SPRITE 2
		move_sprite(i+1,eX[i], eY[i]);	// POSITION ENEMIES	
		
		}
#endif
		
#ifdef SHOW_BG
		
		// GENERATE RANDOM BKG TILE DATA - SO STARRY!
		
		for (j=0; j != 18; j++){
		
			for (i=0; i != 20; i++){		
			randomBkgTiles[i] = rand() % 4;		
			}
		
		set_bkg_tiles(0,j,20,1,randomBkgTiles);									// SET A LINE OF BKG DATA (X, Y, W, H, DATA)
		}
#endif
	
	}

////////////////////////////////////////////////////////////////////////////////
// UPDATE PLAYER
#ifdef SHOW_PLAYER
	void updatePlayer(){
	
	// MOTION VIA DPAD - LIMITED TO A CERTAIN AREA ON SCREEN
	
	// UP
		if (joypad() & J_UP){
		playerY--;
			if (playerY == 15){
			playerY = 16;
			}
		}

	// DOWN
		if (joypad() & J_DOWN){
		playerY++;
			if (playerY == 153){
			playerY = 152;
			}
		}

	// LEFT
		if (joypad() & J_LEFT){
		playerX--;
			if (playerX == 7){
			playerX = 8;
			}
		}	
	
	// RIGHT
		if (joypad() & J_RIGHT){
		playerX++;
			if (playerX == 161){
			playerX = 160;
			}
		}	
	
	// END MOTION VIA DPAD
	
#ifdef PLAY_SOUND
	                 
		
			
                if (joypad() & J_UP){
                NR11_REG = 0x9f;
		NR12_REG = 0x7f;
		NR13_REG = 0x09 + playerY;
		NR14_REG = 0x6a +playerY; } 
                
                else if (joypad() & J_DOWN){
                NR11_REG = 0x9f;
		NR12_REG = 0x7f;
		NR13_REG = 0x09 + playerY;
		NR14_REG = 0x6a +playerY; } 

                else if (joypad() & J_RIGHT){
                NR11_REG = 0x62;
		NR12_REG = 0x74;
		NR13_REG = 0x22 + playerX;
		NR14_REG = 0x69 +playerX*playerX-250; } 

                else if (joypad() & J_LEFT){
                NR11_REG = 0x62;
		NR12_REG = 0x74;
		NR13_REG = 0x22 + playerX;
		NR14_REG = 0x69 +playerX*playerX-250; }

                else if (joypad() & J_A){
                NR11_REG = 0x7f;
		NR12_REG = 0x7f;
		NR13_REG = DIV_REG;
		NR14_REG = 0x80 + (DIV_REG & 7); }

                else if (joypad() & J_B){
                NR11_REG = 0x7f;
		NR12_REG = 0x7f;
		NR13_REG = DIV_REG;
		NR14_REG = 0x80 + (DIV_REG & 20); }

                else {
		NR11_REG = 0x00;													
		NR12_REG = 0x00;
		NR13_REG = 0x00;
		NR14_REG = 0x00;

		}
#endif //PLAY_SOUND

	//MOVE OUR SPRITE
	move_sprite(0,playerX,playerY);												// POSITION OUR SPRITE ON THE SCREEN	
	
#ifdef ENABLE_COLLISION
	j=0;																		// RE-USE J AS A FLAG TO SEE IF WE HAVE COLLIDED WITH AN ENEMY
	
		for (i=0; i != 10; i++){												// LOOP THROUGH OUR 10 ENEMIES
		
			if (collisionCheck(playerX, playerY, 8, 8, eX[i], eY[i], 8, 8) == 1){
			j= 1;																// IF WE COLLIDED, SET OUR FLAG VARIABLE, J TO 1
			}
			
		}
		
		// ADJUST OUR PLAYER SPRITES FRAME IF THEY HIT SOMETHING
		switch (j){
		// NO HIT
		case 0:
		set_sprite_tile(0,0);
		break;
		
		// HIT ENEMY
		default:
		set_sprite_tile(0,1);
		break;		
		}
	
#endif //ENABLE_COLLISION
	}
#endif //SHOW_PLAYER

#ifdef ENABLE_COLLISION
////////////////////////////////////////////////////////////////////////////////
// COLLISION CHECKER - SIMPLE RECTANGLE COLLISION CHECKING
// RETURNS 1 IF OVERLAPPING
	UINT8 collisionCheck(UINT8 x1, UINT8 y1, UINT8 w1, UINT8 h1, UINT8 x2, UINT8 y2, UINT8 w2, UINT8 h2){

		if ((x1 < (x2+w2)) && ((x1+w1) > x2) && (y1 < (h2+y2)) && ((y1+h1) > y2)){
		return 1;
		} else {
		return 0;
		}

	}
#endif //ENABLE_COLLISION

