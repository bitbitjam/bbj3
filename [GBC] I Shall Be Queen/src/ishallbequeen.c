#include <rand.h>
#include <gb/gb.h>
#include <gb/hardware.h>

#define STATE_LANDED 0
#define STATE_JUMPING 2

#define HP_BAR 0
#define MP_BAR 1

void fadeInSprites(UINT8);
void fadeInBkg(UINT8);
void fadeOutSprites(UINT8);
void fadeOutBkg(UINT8);
void waitFrames(UINT8);
void stopAllSounds();
void initGame();
void updatePlayer();
void destroyEnemy();
void instantiatePowerUp();
void setProps();
void moveEnemySprites();
void launchFireBall();
UINT8 fireBallX;
UINT8 fireBallY;
UINT8 fireBallLife;
UINT8 fireBallDir;

extern void updateGame();

const UINT16 blackPalette[] = {
RGB(0,0,0), RGB(0,0,0), RGB(0,0,0),RGB(0,0,0),
RGB(0,0,0), RGB(0,0,0), RGB(0,0,0),RGB(0,0,0),
RGB(0,0,0), RGB(0,0,0), RGB(0,0,0),RGB(0,0,0),
RGB(0,0,0), RGB(0,0,0), RGB(0,0,0),RGB(0,0,0),
RGB(0,0,0), RGB(0,0,0), RGB(0,0,0),RGB(0,0,0),
RGB(0,0,0), RGB(0,0,0), RGB(0,0,0),RGB(0,0,0),
RGB(0,0,0), RGB(0,0,0), RGB(0,0,0),RGB(0,0,0),
RGB(0,0,0), RGB(0,0,0), RGB(0,0,0),RGB(0,0,0)
};


const UINT16 halfPalette[] = {
RGB(30,0,0), RGB(20,0,0), RGB(10,0,0),RGB(0,0,0),
RGB(30,0,0), RGB(20,0,0), RGB(10,0,0),RGB(0,0,0),
RGB(30,0,0), RGB(20,0,0), RGB(10,0,0),RGB(0,0,0),
RGB(30,0,0), RGB(20,0,0), RGB(10,0,0),RGB(0,0,0),
RGB(30,0,0), RGB(20,0,0), RGB(10,0,0),RGB(0,0,0),
RGB(30,0,0), RGB(20,0,0), RGB(10,0,0),RGB(0,0,0),
RGB(30,0,0), RGB(20,0,0), RGB(10,0,0),RGB(0,0,0),
RGB(30,0,0), RGB(20,0,0), RGB(10,0,0),RGB(0,0,0)
};

//const unsigned char superAttackTiles[] = {0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x78,0x6E,0x36,0x37,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x6F,0x6F,0x6B,0x6C,0x6C,0x6C,0x6F,0x6D,0x6E,0x6E,0x6E,0x6E,0x6E,0x6C,0x3D,0x37,0x37,0x3E,0x3F,0x4D,0x4E,0x4F,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6E,0x6F,0x6F,0x6F,0x6B,0x6C,0x6C,0x6E,0x70,0x37,0x37,0x71,0x72,0x73,0x74,0x75,0x6F,0x6B,0x6C,0x6C,0x6C,0x6C,0x6C,0x6F,0x6D,0x6E,0x6E,0x6E,0x6E,0x79,0x79,0x79,0x79,0x79,0x79,0x79,0x79,0x79,0x79,0x79,0x79,0x79,0x79,0x79,0x79,0x79,0x79,0x79,0x79,0x79,0x79};


void endGame();
void updateBar(UINT8, UINT8);													// UPDATES OUR BAR DISPLAY HP / MP
void updatePlayerFrame();
void updateEnemies();
void performStateChange();

void showValue(UINT8,UINT8, UINT8,UINT8);															// value,x,y,chars

UINT8 switchRomBanks();															// SWITCH ROM BANKS

UINT8 debugValueArray[2];
UINT8 walkNoise;															//MAKES A SMALL WALKING NOISE
void checkCollisions();														//PERFORMS A BUNCH OF COLLISION CHECKS
UINT8 collisionCheck(UINT8, UINT8, UINT8, UINT8, UINT8, UINT8, UINT8, UINT8); 	// RECT TO RECT CHECK

UINT8 hMode;																	// H- MODE CHECKER

UINT8 painNoise;																//CONTROLS THE PAIN NOISE MAKER

UINT8 superAttacks;																// HOW MANY SUPER ATTACKS ARE THERE LEFT?
UINT8 level;				//WHICH LEVEL ARE WE ON EXACTLY....
UINT8 i,j,k,l,m,n,tempVal,wn;
UINT16 ii,jj,kk,ll;
UINT8 myDelay;
UINT8 screen, seed;
UINT8 lastKeys;

UINT8 globalY;

UINT8 screenShake;
UINT8 shakeDir;					// 0 = HORIZONTAL, 1 = VERTICAL


UINT8 maxLevel;

UINT8 attackDelay;

UINT8 menuX;
UINT8 menuY;

UINT8 powerUpX;
UINT8 powerUpY;
UINT8 powerUpType;
UINT8 powerUpNoise;

UINT8 shadowY;					//WHERE IS OUR SHADOW SPRITE APPEARING?
UINT8 conversationTime;
UINT8 conversationIndex;
UINT8 conversationID;
unsigned char currentConversation[77];


UINT8 initBank, newBank;													// SET TO 1 WHEN WE SWITCH ROM BANKS
UINT8 scene;

UINT8 move, isMoving;														//ARE WE MOVING? IF SO BEGIN MOVING ANIMATION
UINT8 pX, pY, pState, playerFrame, jumpTime;
UINT8 myDamage;
UINT8 punchWindDown;
UINT8 iFrames;
UINT8 HP,MP;
UINT8 eHitIndex;												//WHICH ENEMY WE HIT
UINT8 flipX;													//ARE WE FACING LEFT ORRR RIGHT?

UINT8 barArray[] = {0x00,0x00,0x00,0x00};						//TEMPARRAY TO STORE ENERGY / MP BAR DISPLAY
UINT8 fullRow[20];

UINT8 frameCounter;

UINT8 enemiesRemaining;														//ENEMIES LEFT UNTIL PROCEDD TO NEXT STAGE
UINT8 eTargetX[3], eTargetY[3], eX[3], eY[3],eFrame[3],eState[3],eHP[3],eTime[3],eType[3],eDamage[3], eRealType[3];			//ENEMY VARIABLES



// MAIN FUNCTION

	int main(){
	//SEED OUR RANDOMIZER
	seed = DIV_REG;
	initrand(DIV_REG);

	// INIT ROUTINE
	DISPLAY_ON;
	OBP0_REG=0x00;
	BGP_REG=0x00;

	NR52_REG = 0x8F;	// TURN SOUND ON
	NR51_REG = 0xff;	// sound channell SET TO 1
	NR50_REG = 0x77; 	// VOLUME MAX = 0x77, min = 0x00

	newBank = 1;	//INITIAL BANK TO LOAD 
	scene = 0;		//CURRENT SCENE 
	hMode = 0;		//TOGGLES HENTAI MODE 1 / 0

//GAME LOOP

		while(1){



			// CHECK FOR BANK SWITCHES AND SWITCH ACCORDINGLY
			if (newBank != 0){
			switchRomBanks();
			}

//OUR HANDY SCENE CONTROLLER
			switch (scene){
			case 0:					// REFRESH LOGO
			case 1:					// INTRO SCREEN
			case 2:					// DIALOG SCREENS
			case 3:					// DIALOG SCREENS
			case 4:					// DIALOG SCREENS
			case 50:				// WIN GAME
			case 99:				// GAME OVER
			updateGame();
			break;


			
			case 5:					// INIT THE GAME SCENE! - LEVEL 1
			case 15:				//LEVEL 2
			case 25:				//LEVEL 3
			//LOAD SPRITES FIRST.
			newBank = 5;
			initBank = 1;
			switchRomBanks();
			updateGame();
			//ACTUALLY INIT GAME
			initGame();
			

				
			scene++;
			break;
			
			
			//MAIN GAME LOOP!!!!!!!!!!!111111111111111111111111oneoneoneoneoneoneeleven
			
			case 6:					// TRUE GAME LOOP	
			case 16:
			case 26:		
			
			
			//TRANSITION TO OUR CONVERSATION BITS WHEN LEVELCOMPLETE
				if ((scene==6) && (level ==3)){
				scene=3;
				newBank=2;
				initBank=1;
				fadeOutBkg(10);
				fadeOutSprites(10);
				}
				
				if ((scene==16) && (level ==4)){
				scene=4;
				newBank=2;
				initBank=1;
				fadeOutBkg(10);
				fadeOutSprites(10);				
				}

				if ((scene==26) && (level == 7)){
				scene=50;
				newBank=3;
				initBank=1;
				fadeOutBkg(10);
				fadeOutSprites(10);				
				}	
			
			//HANDLE INPUT AND PLAYER STATES
			frameCounter++;
			isMoving = 0;


		//UPDATE FIREBALL
		if (fireBallLife !=0){
		fireBallLife--;

			switch (fireBallDir){
			case 0:
			fireBallX+=2;
			break;
			default:
			fireBallX-=2;
			}

			if (fireBallLife > 1){
			NR11_REG = 0x1f;
			NR12_REG = fireBallLife<<2;
			NR13_REG= DIV_REG;
			NR14_REG= 0x81;
			} else {
			stopAllSounds();
			}

		move_sprite(33,fireBallX,fireBallY);	

			for (i=0; i!=3; i++){
			
				if (collisionCheck(fireBallX, fireBallY, 8, 8, eX[i]+2, eY[i]+2, 12, 12) == 1){	
				eHitIndex = i;
				eHP[eHitIndex] -=10;
					
				//HAS HP LOOPED AROUND?
					if (eHP[eHitIndex] >220){
					destroyEnemy(eHitIndex);
					}
				}				
			}
		
		
		} else {
		fireBallX = 0;
		fireBallY =220;
		move_sprite(33,fireBallX,fireBallY);
		}


		//HANDLE SCREEN SHAKE
			if (screenShake!=0){
			screenShake--;
			
				if (screenShake > 1){
				NR11_REG = 0x7f;
				NR12_REG = 0x3f;
				NR13_REG= DIV_REG;
				NR14_REG= 0x80;
				
					switch (shakeDir){
					case 0:
					scroll_bkg(0, 1-(frameCounter%3));
					break;
					
					default:
					scroll_bkg(1-(frameCounter%3), 0);
					break;
					}
					
				} else {
				stopAllSounds();
				move_bkg(globalY,0);
				}
			
			}
			


			//POWER UP NOISE
				if(powerUpNoise!=255){
				powerUpNoise+=5;
				
						NR11_REG = 0x7f;
						NR12_REG = 0x4f;
						NR13_REG = powerUpNoise;
						NR14_REG= 0x84;			

					if (powerUpNoise == 250){
					NR11_REG = 0x00;
					NR12_REG = 0x00;
					NR13_REG = 0x00;
					NR14_REG = 0x00;
					powerUpNoise = 255;
					}				
				}
			
		//HANDLE IFRAMES
				if(iFrames!=0){
				iFrames--;		
				}
				
				if (attackDelay !=0){
				attackDelay--;
				}

				//PERFORM ATTACK ANIMATION - DEPENDING ON HOW LONG B IS HELD FOR... IF LESS THAN 10 FRAMES DO A PUNCH OTHERWISE CHARGE FIREBALL FROM MP

					if ((joypad() & J_B) && (attackDelay ==0) && (punchWindDown == 0)){
					
						
						isMoving = 0;
						if (pState == STATE_LANDED){
						move=0;
						}
					punchWindDown = 30;

						if (pState == STATE_LANDED){
						playerFrame = 4;
						updatePlayerFrame();					
						} else {
						playerFrame=7;
						updatePlayerFrame();
						
						}
					}
	
			
				if (punchWindDown !=0){
				punchWindDown--;
				
					if (pState == STATE_LANDED){
						if (punchWindDown == 15){
						playerFrame = 5;
						updatePlayerFrame();

							switch (flipX){
							case 0:
							move_sprite(39,pX+24,pY+16);

							break;
							default:
							move_sprite(39,pX-8,pY+16);
							break;
							}					
							
						}
						
						if (punchWindDown <18){
						
							switch (flipX){
							case 0:
							
								for (i=0; i!=3; i++){
								
									if (collisionCheck(pX+24, pY+16,8,8,eX[i],eY[i],16,16) ==1){
									eHitIndex = i;
									eHP[eHitIndex] -=myDamage;
									eX[i]+=8;
									screenShake= 3;
									shakeDir=1;									
									
									//HAS HP LOOPED AROUND?
										if (eHP[eHitIndex] >220){
										screenShake = 3;
										destroyEnemy(eHitIndex);
										}
									
									}
								
								}						
							
							break;
							default:
							
								for (i=0; i!=3; i++){
								
									if (collisionCheck(pX-8, pY+16,8,8,eX[i],eY[i],16,16) ==1){
									eHitIndex = i;
									eHP[eHitIndex] -=myDamage;
									eX[i]-=8;
									screenShake= 3;
									shakeDir=1;									
									
									//HAS HP LOOPED AROUND?
										if (eHP[eHitIndex] >220){
										screenShake = 3;
										destroyEnemy(eHitIndex);
										}
									
									}
								
								}							
							
							break;
							}					
						
						}
						
					} else {
					//JUMP KICK
					
							switch (flipX){
							case 0:
							move_sprite(37,pX+24,pY+32);
							move_sprite(38,pX+24,pY+40);

							break;
							default:
							move_sprite(37,pX-8,pY+32);
							move_sprite(38,pX-8,pY+40);
							break;
							}



						if (punchWindDown <18){
						
							switch (flipX){
							case 0:
							
								for (i=0; i!=3; i++){
								
									if (collisionCheck(pX+24, pY+32,8,16,eX[i],eY[i],16,16) ==1){
									eHitIndex = i;
									eHP[eHitIndex] -=myDamage;
									eX[i]+=8;
									screenShake= 3;
									shakeDir=1;									
									
									//HAS HP LOOPED AROUND?
										if (eHP[eHitIndex] >220){
										screenShake = 3;
										destroyEnemy(eHitIndex);
										}
									
									}
								
								}						
							
							break;
							default:
							
								for (i=0; i!=3; i++){
								
									if (collisionCheck(pX-8, pY+24,8,16,eX[i],eY[i],16,16) ==1){
									eHitIndex = i;
									eHP[eHitIndex] -=myDamage;
									eX[i]-=8;
									screenShake= 3;
									shakeDir=1;									
									
									//HAS HP LOOPED AROUND?
										if (eHP[eHitIndex] >220){
										screenShake = 3;
										destroyEnemy(eHitIndex);
										}
									
									}
								
								}							
							
							break;
							}					
						
						}





							if ((punchWindDown == 1) || (pState == STATE_LANDED)){
							playerFrame = 0;
							updatePlayerFrame();
							move_sprite(37,0,0);
							move_sprite(38,0,0);
							move_sprite(39,0,0);
							punchWindDown = 0;
							attackDelay=15;	//LESS DELAY BETWEEN PUNCHES
							}
					
					}
				
					if ((punchWindDown ==1) && (pState == STATE_LANDED)){
					playerFrame = 0;
					updatePlayerFrame();
					move_sprite(39,0,0);
					move_sprite(37,0,0);
					move_sprite(38,0,0);
					attackDelay=5;					
					}

				}


				//JUMP STATE
				if (pState == STATE_JUMPING){
				jumpTime--;

					if (jumpTime > 23){
					pY--;
	
						if (jumpTime >35){
						pY--;

						NR21_REG = 0x7f;
						NR22_REG = jumpTime;
						NR23_REG = 255-(jumpTime<<4);
						NR24_REG = 0x86;
						}

					} else {

						NR22_REG= 0x00;
					pY++;


						if (jumpTime < 13){
						pY++;

						}


					}

				move_sprite(35,pX+4,shadowY);
				move_sprite(36,pX+12,shadowY);

					if (jumpTime == 0){
					screenShake= 5;
					shakeDir=0;
					move_sprite(35,0,0);
					move_sprite(36,0,0);
					pState = STATE_LANDED;
					playerFrame = 0;
					updatePlayerFrame();				
					performStateChange();
					}
				}

				if ((joypad() & J_A) && (pState != STATE_JUMPING)){
				pState= STATE_JUMPING;
				playerFrame = 6;
				shadowY = pY+36;
				updatePlayerFrame();				
				performStateChange();
				jumpTime = 48;
				}

				if (joypad() & J_SELECT){
					if ((pState != STATE_JUMPING) && (punchWindDown ==0) && (MP>4) && (fireBallLife == 0)){
					MP-=4;
					updateBar(MP_BAR, MP);
					launchFireBall();
					}
				}


				if (punchWindDown == 0){

					if(joypad() & J_RIGHT){

						if (pX != 100){
						flipX=0;
						pX++;
						} else {
						scroll_bkg(1,0);
						globalY++;
						powerUpX--;
						
							if (powerUpX >180){
							powerUpY=190;
							}
						
						move_sprite(34,powerUpX,powerUpY);	
						eX[0]--;
						eX[1]--;
						eX[2]--;
						pX=100;
						}

					isMoving = 1;

					}


					if(joypad() & J_LEFT){

						if (pX != 8){
						flipX=1;
						pX--;
						isMoving = 1;
						}

					}

					if(joypad() & J_UP){

						switch (pState){
						case STATE_LANDED:
							if (pY != 24){
							pY--;
							isMoving = 1;
							}
						break;
						}

					}

					if(joypad() & J_DOWN){

						switch (pState){


						case STATE_LANDED:

							if (pY < 92){
							pY++;
							isMoving = 1;
							}

						break;
						}

					}
				}

				if ((pY > 91) && (pY < 160)){
				pY = 91;
				}

				if (isMoving == 1){
				move++;
				}
	`
				if (pState == STATE_LANDED){
				wn = move %30;

					if (wn == 9){
					playerFrame = 1;
					updatePlayerFrame();
					}

					if (wn == 19){
					playerFrame = 2;
					updatePlayerFrame();
					NR21_REG = 0x7f;
					NR22_REG = 0x2f;
					NR23_REG = 0x00;
					NR24_REG= 0x82;			
					} else {
					NR21_REG = 0x00;
					NR22_REG = 0x00;
					NR23_REG = 0x00;
					NR24_REG = 0x00;

					}


					if (wn == 29){
					playerFrame = 3;
					updatePlayerFrame();					
					}
				
				}

					if (punchWindDown == 0){
						if((joypad() == 0) && (lastKeys !=0)){
						playerFrame = 0;
						move = 0;
						updatePlayerFrame();
						}
					}

				if ((joypad() != 0) || (pState == STATE_JUMPING)){
				updatePlayer();
				}

			i=frameCounter % 4;
				if (i !=3){
				updateEnemies();
				}

				if (i == 3){
				checkCollisions();
				frameCounter=0;
				}
			break;
			}

		lastKeys = joypad();
		wait_vbl_done();
		}
	}



	void updateBar(UINT8 barId, UINT8 amount){
	j= (amount >> 3);

	barArray[0] = 0x2F;
	barArray[1] = 0x2F;
	barArray[2] = 0x2F;
	barArray[3] = 0x2F;

		for(i=0; i!=j; i++){
		barArray[i] = 0x27;
		}

	k = amount %8;
	barArray[i] = 0x2F-k;

		if(barId == HP_BAR){
		set_win_tiles(2,2,4,1,barArray);
		} else {
		set_win_tiles(8,2,4,1,barArray);
		}

	}


	void updateEnemies(){

	j= frameCounter %20;
	k=DIV_REG %2;

		

		for (i=0; i!=3; i++){

			switch (eRealType[i]){
			//SLIMES
			case 0:	
			eTargetY[i] = pY+16;



				if (j ==1){
				

				eType[i]+=4;

					if (eType[i] ==208){
					eType[i] = 192;
					}

				set_sprite_tile(18+(i*4),eType[0]);
				set_sprite_tile(19+(i*4),eType[0]+1);
				set_sprite_tile(20+(i*4),eType[0]+2);
				set_sprite_tile(21+(i*4),eType[0]+3);
				}

				if (k==1){
					if (eX[i]+32 < (pX+42)){
					eX[i]++;
					} else {
					eX[i]--;
					}
				} else {

					if (eY[i] < (eTargetY[i]+12)){
					eY[i]++;
					} else {
					eY[i]--;
					}
				}

			moveEnemySprites();
			break;
			
			//SNAKES
			case 1:	
			case 2:
			eTargetY[i] = pY+16;

			j= frameCounter %60;

				if ((j ==1) && (k==1)){
				
				eState[i]++;
				
				
				eType[i]+=4;
				
					if (eRealType[i] == 1){
					
					//CHANGE SNAKE STATE
						if (eType[i] > 215){
						eType[i] = 208;
						}
						
						if (eState[i] >80){
						eType[i] = 216;
						}
						
						if(eState[i] >100){					
						eType[i]=220;
						}
						
						if (eState[i] > 140){
						eState[i] = 0;
						eType[i]=208;
						}
						
					} else {
					
						if(eState[i] >40){
						eState[i] =0;
						}
						
						if (eType[i] == 240){
						eType[i] = 224;
						}
					}

				}

				if (k==1){
				j=i*4;
				
					if (eX[i]+32 < (pX+42)){
					
						if (get_sprite_prop(18+j) < 32){
						tempVal=get_sprite_prop(18+j);
						tempVal+=32;						
						setProps();					
						}
						
						
					set_sprite_tile(18+j,eType[i]+1);
					set_sprite_tile(19+j,eType[i]+0);
					set_sprite_tile(20+j,eType[i]+3);
					set_sprite_tile(21+j,eType[i]+2);						
					
						if (eRealType[i] == 1){
						
							if (eType[i] != 216){	
							eX[i]++;
							}
							
							if (eType[i] == 220){
							eX[i]+=3;
							eState[i]++;
							}
						} else {
							
							if (eState[i] <20){
							eX[i]++;
							}
						}
					
					} else {
					
						if (get_sprite_prop(18+j) > 31){
						tempVal=get_sprite_prop(18+j);
						tempVal-=32;
						setProps();					
						}
						
					set_sprite_tile(18+j,eType[i]);
					set_sprite_tile(19+j,eType[i]+1);
					set_sprite_tile(20+j,eType[i]+2);
					set_sprite_tile(21+j,eType[i]+3);	
					
						if (eRealType[i] == 1){
							if (eType[i] != 216){	
							eX[i]--;
							}
							
							if (eType[i] == 220){
							eX[i]--;
							eState[i]++;
							}
						} else {
								
							if (eState[i] <20){
							eX[i]++;
							}
						}
					}
			
				
					if (eRealType[i]== 1){
						if (eType[i] < 216){
							if (eY[i] < (eTargetY[i]+12)){
							eY[i]++;
							} else {
							eY[i]--;
							}
						}
					} else {

						if (eState[i] > 20){
							if (eY[i] < (eTargetY[i]+12)){
							eY[i]++;
							} else {
							eY[i]--;
							}
						}
					
					}
				
				}

			move_sprite(18+(i*4),eX[i],eY[i]);
			move_sprite(19+(i*4),eX[i]+8,eY[i]);
			move_sprite(20+(i*4),eX[i],eY[i]+8);
			move_sprite(21+(i*4),eX[i]+8,eY[i]+8);	
			break;
			

			
			case 3:
			// ARROW (DIES AFTER X = 244)
			j=i*4;
			eX[i] -=3;
			eType[i] = 0xB4;

			set_sprite_tile(18+j,eType[i]);
			set_sprite_tile(19+j,eType[i]+1);
			set_sprite_tile(20+j,eType[i]+2);
			set_sprite_tile(21+j,eType[i]+3);				
			
			tempVal = get_sprite_prop(18);
			
				if (tempVal>32){tempVal-=32;}
			
			setProps();
			moveEnemySprites();
			
				if ((eX[i] == 180) || (eX[i] == 181)){
				eHitIndex= i;
				destroyEnemy();
				enemiesRemaining++;
				}
			
			break;			
			}			
		
		}

	}

	void moveEnemySprites(){
			move_sprite(18+(i*4),eX[i],eY[i]);
			move_sprite(19+(i*4),eX[i]+8,eY[i]);
			move_sprite(20+(i*4),eX[i],eY[i]+8);
			move_sprite(21+(i*4),eX[i]+8,eY[i]+8);	
	}

	void setProps(){
			set_sprite_prop(18+j,tempVal);
			set_sprite_prop(19+j,tempVal);
			set_sprite_prop(20+j,tempVal);
			set_sprite_prop(21+j,tempVal);	
	}

	void updatePlayerFrame(){

		k = playerFrame *18;

		for (i=0; i!=18; i++){
		set_sprite_tile(i,k+i);
		}

	}

	void updatePlayer(){
		
		if (playerFrame != 9){
		
			switch (flipX){
			case 0:

				for (i=0; i!=18; i++){

					if (i <6){
					set_sprite_prop(i, 0);
					} else {
					set_sprite_prop(i, 1);
					}

				}
				
			set_sprite_prop(37,1);
			set_sprite_prop(38,1);
			set_sprite_prop(39,1);

			move_sprite(0,pX,pY);
			move_sprite(1,pX+8,pY);
			move_sprite(2,pX+16,pY);
			move_sprite(3,pX,pY+8);
			move_sprite(4,pX+8,pY+8);
			move_sprite(5,pX+16,pY+8);
			move_sprite(6,pX,pY+16);
			move_sprite(7,pX+8,pY+16);
			move_sprite(8,pX+16,pY+16);
			move_sprite(9,pX,pY+24);
			move_sprite(10,pX+8,pY+24);
			move_sprite(11,pX+16,pY+24);
			move_sprite(12,pX,pY+32);
			move_sprite(13,pX+8,pY+32);
			move_sprite(14,pX+16,pY+32);
			move_sprite(15,pX,pY+40);
			move_sprite(16,pX+8,pY+40);
			move_sprite(17,pX+16,pY+40);
			break;

			case 1:

				for (i=0; i!=18; i++){
					if (i <6){
					set_sprite_prop(i, 32);
					} else {
					set_sprite_prop(i, 33);
					}
				}

			set_sprite_prop(37,33);
			set_sprite_prop(38,33);
			set_sprite_prop(39,33);

			move_sprite(2,pX,pY);
			move_sprite(1,pX+8,pY);
			move_sprite(0,pX+16,pY);
			move_sprite(5,pX,pY+8);
			move_sprite(4,pX+8,pY+8);
			move_sprite(3,pX+16,pY+8);
			move_sprite(8,pX,pY+16);
			move_sprite(7,pX+8,pY+16);
			move_sprite(6,pX+16,pY+16);
			move_sprite(11,pX,pY+24);
			move_sprite(10,pX+8,pY+24);
			move_sprite(9,pX+16,pY+24);
			move_sprite(14,pX,pY+32);
			move_sprite(13,pX+8,pY+32);
			move_sprite(12,pX+16,pY+32);
			move_sprite(17,pX,pY+40);
			move_sprite(16,pX+8,pY+40);
			move_sprite(15,pX+16,pY+40);
			break;
			}
		
		} else {
		
			switch (flipX){
			case 0:
		
				for (i=0; i!=18; i++){

					if (i <6){
					set_sprite_prop(i, 0);
					} else {
					set_sprite_prop(i, 1);
					}

				}	
		
			move_sprite(0,pX,pY+24);
			move_sprite(1,pX+8,pY+24);
			move_sprite(2,pX+16,pY+24);
			move_sprite(3,pX+24,pY+24);
			move_sprite(4,pX+32,pY+24);
			move_sprite(5,pX+40,pY+24);
			
			move_sprite(6,pX,pY+32);
			move_sprite(7,pX+8,pY+32);
			move_sprite(8,pX+16,pY+32);
			move_sprite(9,pX+24,pY+32);
			move_sprite(10,pX+32,pY+32);
			move_sprite(11,pX+40,pY+32);

			move_sprite(12,pX,pY+40);
			move_sprite(13,pX+8,pY+40);
			move_sprite(14,pX+16,pY+40);
			move_sprite(15,pX+24,pY+40);
			move_sprite(16,pX+32,pY+40);
			move_sprite(17,pX+40,pY+40);
			break;	
			
			case 1:
			
			for (i=0; i!=18; i++){
					if (i <6){
					set_sprite_prop(i, 32);
					} else {
					set_sprite_prop(i, 33);
					}
				}			
			
			break;
			
			move_sprite(5,pX,pY+24);
			move_sprite(4,pX+8,pY+24);
			move_sprite(3,pX+16,pY+24);
			move_sprite(2,pX+24,pY+24);
			move_sprite(1,pX+32,pY+24);
			move_sprite(0,pX+40,pY+24);
			
			move_sprite(11,pX,pY+32);
			move_sprite(10,pX+8,pY+32);
			move_sprite(9,pX+16,pY+32);
			move_sprite(8,pX+24,pY+32);
			move_sprite(7,pX+32,pY+32);
			move_sprite(6,pX+40,pY+32);

			move_sprite(17,pX,pY+40);
			move_sprite(16,pX+8,pY+40);
			move_sprite(15,pX+16,pY+40);
			move_sprite(14,pX+24,pY+40);
			move_sprite(13,pX+32,pY+40);
			move_sprite(12,pX+40,pY+40);			
			
			
			}
		}


	}

////////////////////////////////////////////////////////////////////////////////
//
// COLLISION CHECKS
//
////////////////////////////////////////////////////////////////////////////////

	void checkCollisions(){
	
	//GET A POWERUP?
	if (collisionCheck(pX+2, pY+16, 12, 24, powerUpX,powerUpY, 8, 8) == 1){
	powerUpY=190;
	powerUpNoise=170;
	move_sprite(34, powerUpX, powerUpY);
		if (powerUpType==0){

		HP+=10;
		if (HP >32){ HP =32;}
		updateBar(HP_BAR, HP);
		} else {
		MP+=10;
		if (MP >32){ MP =32;}
		updateBar(MP_BAR, MP);		
		}
		
	}
	
	//IS PLAYER VULNERABLE?	
		if (iFrames == 0){
			for (m=0; m!=3; m++){
			//FOR EACH ENEMY THAT IS ALIVE
				if (eHP[m] <128){
				
					if (collisionCheck(pX+2, pY+16, 12, 24, eX[m]+2, eY[m]+2, 12, 12) == 1){
					HP-= eDamage[m];
					updateBar(HP_BAR, HP);
					//MOVE THE CAHRACTER AWAY SLIGHTLY
					
					playerFrame = 8;
					updatePlayerFrame();
						if ((HP ==0 ) || (HP > 32)){
						HP =0;
						flipX =0;
						updateBar(HP_BAR, HP);						
						playerFrame = 9;
						updatePlayerFrame();
						stopAllSounds();
						//FALL PLAYER BACK TO THE GROUND
							for (n=0; n != 45; n++){
							
								if ((n %3)==2){
								
									switch (flipX){
									case 1:
									pX++;
									break;
									case 0:
									pX--;
									}
								
									if (n< 20){
									pY++;
									}
								}
								
								if (n <5){pY--;}
								if ((n >10) && (n <15)){pY++;}
								if ((n >14) && (n<30)){pY+=2;}								
								if ((n >30) && (n < 35)){pY--;}
								if ((n<35) && (n > 29)){pY++;}
								
								if ((n>34) && (n < 37)){pY--;}
								if ((n>37) && (n < 40)){pY++;}						
								
								if (pY>120){pY=120;};
								
								switch(n){
								case 30:
								case 34:
								case 40:
								case 41:
								case 42:
								NR11_REG = 0x7f;
								NR12_REG = 0x7f;
								NR13_REG= 0x04;
								NR14_REG= 0x80;							
								break;
								default:
								stopAllSounds();
								break;
								}
								
							updatePlayer();	
							wait_vbl_done();
							wait_vbl_done();
							wait_vbl_done();
							}
							

						endGame();
						}
				
					iFrames=30;
					}
				
				}
			
			}
		}
	}


	UINT8 collisionCheck(UINT8 x1, UINT8 y1, UINT8 w1, UINT8 h1, UINT8 x2, UINT8 y2, UINT8 w2, UINT8 h2){

		if ((x1 < (x2+w2)) && ((x1+w1) > x2) && (y1 < (h2+y2)) && ((y1+h1) > y2)){
		return 1;
		} else {
		return 0;
		}

	}


	void fadeInBkg(UINT8 edelay){
	
	BGP_REG=0x00;
	myDelay=0;
	waitFrames(edelay);
	
		if (_cpu == CGB_TYPE){
		VBK_REG = 1;
		set_bkg_palette(0,8, halfPalette);
		VBK_REG = 0;
		}		
	
	SHOW_BKG;
	BGP_REG=0x54;
	SHOW_BKG;
	myDelay=0;
	waitFrames(edelay);
	
		if (_cpu == CGB_TYPE){
		VBK_REG = 1;
		set_bkg_palette(0,8, halfPalette);
		VBK_REG = 0;
		}	
	
	
	BGP_REG=0xA4;
	SHOW_BKG;
	myDelay=0;
	waitFrames(edelay);
	BGP_REG=0xE4;
	SHOW_BKG;
	

	
	}


	void fadeOutBkg(UINT8 edelay){
	BGP_REG=0xE4;
	myDelay=0;
	waitFrames(edelay);

		if (_cpu == CGB_TYPE){
		VBK_REG = 1;
		set_bkg_palette(0,8, halfPalette);
		VBK_REG = 0;
		}	
	
	SHOW_BKG;
	BGP_REG=0xA4;
	SHOW_BKG;
	myDelay=0;
	waitFrames(edelay);
	
		if (_cpu == CGB_TYPE){
		VBK_REG = 1;
		set_bkg_palette(0,8, blackPalette);
		VBK_REG = 0;
		}		
	
	
	BGP_REG=0x54;
	SHOW_BKG;
	myDelay=0;
	waitFrames(edelay);

	BGP_REG=0x00;
	SHOW_BKG;

	
	}



	void fadeInSprites(UINT8 edelay){
	OBP0_REG=0x00;
	myDelay=0;
	waitFrames(edelay);
	SHOW_SPRITES;
	OBP0_REG=0x54;
	SHOW_SPRITES;
	myDelay=0;
	waitFrames(edelay);
	OBP0_REG=0xA4;
	SHOW_SPRITES;
	myDelay=0;
	waitFrames(edelay);
	OBP0_REG=0xE0;
	SHOW_SPRITES;
	}


	void fadeOutSprites(UINT8 edelay){
	OBP0_REG=0xE0;
	myDelay=0;
	waitFrames(edelay);
	SHOW_SPRITES;
	OBP0_REG=0xA4;
	SHOW_SPRITES;
	myDelay=0;
	waitFrames(edelay);
	OBP0_REG=0x54;
	SHOW_SPRITES;
	myDelay=0;
	waitFrames(edelay);
	OBP0_REG=0x00;
	SHOW_SPRITES;
	}

////////////////////////////////////////////////////////////////////////////////
//
// FRAME PAUSE
//
////////////////////////////////////////////////////////////////////////////////

	void performStateChange(){
//NOT REQUIRED...
	}

	void updateScore(){

	}


	void showValue(UINT8 value, UINT8 inX, UINT8 inY, UINT8 numChars){

	debugValueArray[0] = 0x40 + (value/100);
	i = value/100;
	value -=(i*100);
	debugValueArray[1] = 0x40 + (value/10);
	debugValueArray[2] = 0x40 + (value%10);

		switch (numChars){
		case 3:
		set_win_tiles(inX,inY,3,1,debugValueArray);
		break;
		case 2:
		set_win_tiles(inX,inY,2,1,&debugValueArray[1]);
		break;
		default:
		set_win_tiles(inX,inY,1,1,&debugValueArray[2]);
		break;
		}

	}


	void endGame(){
	fadeOutBkg(10);	
	wn=60;	
	fadeOutSprites(10);
	move_bkg(0,0);
	scene = 99;
	initBank = 1;
	newBank = 4;
	switchRomBanks();
	}


	void waitFrames(UINT8 edelay){

		while (myDelay != edelay){
		myDelay++;
		wait_vbl_done();
		}

	}

	UINT8 switchRomBanks(){
	initBank = 1;
	stopAllSounds();
	SWITCH_ROM_MBC1(newBank);
	newBank = 0;
	wait_vbl_done();
	}

	void stopAllSounds(){
	NR11_REG = 0x00; //SQUARE WAVE DUTY
	NR12_REG = 0x00; //VOLUME
	NR13_REG = 0x00; //LOWER SOUND FREQ
	NR14_REG = 0x00; //LARGER SOUND FREQ

	NR21_REG = 0x00; //SQUARE WAVE DUTY
	NR22_REG = 0x00; //VOLUME
	NR23_REG = 0x00; //LOWER SOUND FREQ
	NR24_REG = 0x00; //LARGER SOUND FREQ

	NR41_REG = 0x00; //SQUARE WAVE DUTY
	NR42_REG = 0x00; //VOLUME
	NR43_REG = 0x00; //LOWER SOUND FREQ
	NR44_REG = 0x00; //LARGER SOUND FREQ
	}


	void destroyEnemy(){
	//DESTROY THEN INIT A NEW ENEMY	
	stopAllSounds();

		if ((DIV_REG %32) < 8){
		instantiatePowerUp();
		}
	
		switch ((frameCounter+eHitIndex) % 2){
		case 0:
		eX[eHitIndex] = 240+(eHitIndex<<2);
		break;
		default:
		eX[eHitIndex] = 160+(eHitIndex<<3);
		}
	
		switch (level){
		case 1:
		eType[eHitIndex] = 192;
		eRealType[eHitIndex] = 0;
		eY[eHitIndex] = 48 + (DIV_REG % 80);
		eHP[eHitIndex]=16;
		break;
		
		case 2:
		
			for (i=0; i!=3; i++){
			eType[i] = 208;
			eRealType[i] = 1;
			}
			
		eType[eHitIndex] = 208;
		eRealType[eHitIndex] = 1;
		eY[eHitIndex] = 48 + (DIV_REG % 80);
		eHP[eHitIndex]=24;		
		break;
		
		default:
			switch ((frameCounter+eHitIndex) % 4){
			case 0:
			case 4:
			//INSTANTIATE SLIME
			eType[eHitIndex] = 192;
			eY[eHitIndex] = 48 + (DIV_REG % 80);
			eHP[eHitIndex]=16;
			eRealType[eHitIndex] = 0;
			eDamage[eHitIndex] = 3;		
			break;
			
			case 1:
			//INSTNATIATE SNAKE
			eType[eHitIndex] = 208;
			eY[eHitIndex] = 48 + (DIV_REG % 80);
			eHP[eHitIndex]=32;				
			eRealType[eHitIndex] = 1;
			eState[eHitIndex] = (DIV_REG % 20);
			eDamage[eHitIndex] = 2;
			break;
			
			case 2:
			//INSTANTIATE EYEBALL MONSTER
			eType[eHitIndex] = 224;
			eY[eHitIndex] = 48 + (DIV_REG % 80);
			eHP[eHitIndex]=48;				
			eRealType[eHitIndex] = 2;
			eState[eHitIndex] = DIV_REG;
			eDamage[eHitIndex] = 6;	
			break;
			
			case 3:
			//INSTANTIATE ARROW (DIES AFTER X = 242)
			
				switch ((frameCounter+eHitIndex) % 2){
				case 0:
				eX[eHitIndex] = 240-(eHitIndex<<2);
				break;
				default:
				eX[eHitIndex] = 160+(eHitIndex<<3);
				}			
			eState[eHitIndex] = 0;
			eY[eHitIndex] = 48 + (DIV_REG % 80);
			eHP[eHitIndex]=32;				
			eRealType[eHitIndex] = 3;	
			eType[eHitIndex] = 0xB4;
			eDamage[eHitIndex] = 4;
			break;			
			}
		
		break;
		}
	
	
	enemiesRemaining--;
	showValue(enemiesRemaining, 17, 1, 2);
	
		if (enemiesRemaining == 0){
		level++;
		showValue (level,12,1,1);
		enemiesRemaining =  13+(level*10);
		showValue(enemiesRemaining, 17, 1, 2);
		}
		
	stopAllSounds();
	
	}

	void instantiatePowerUp(){
	
		if (powerUpY >160){
		powerUpNoise=230;
		powerUpX=eX[eHitIndex]+4;
		powerUpY = eY[eHitIndex]+8;
		powerUpType = DIV_REG%2;
		
			if (powerUpType == 0){
			set_sprite_tile(34,0xF5);		//HEART - DEFAULT
			set_sprite_prop(34,6);
			move_sprite(34,powerUpX,powerUpY);		
			} else {
			set_sprite_tile(34,0xF6);		//MANA
			set_sprite_prop(34,7);
			move_sprite(34,powerUpX,powerUpY);		
			}
		}
	
	}
	
	void LaunchFireBall(){

	fireBallDir = flipX;
	fireBallLife=64;
	
	playerFrame = 4;
	updatePlayerFrame();

	fireBallY= pY+16;
							
		switch (flipX){
		case 0:
		set_sprite_prop(33, 0);
		fireBallX = pX+24;
		break;
		case 1:
		set_sprite_prop(33, 32);
		fireBallX = pX-8;		
		break;		
		}
		
	move_sprite(33,fireBallX,fireBallY);
	wait_vbl_done();
	wait_vbl_done();
	playerFrame = 0;	
	}
	






	void initGame(){
	pX=64;
	pY=64;
	jumpTime = 0;
	superAttacks = 3;
	myDamage = 9;
	attackDelay = 0;

	HP = 32;	//MAX IS 32
	MP = 16;	//MAX IS 32
//	scene=25;

	

	fireBallLife = 0;
	flipX = 0;
	screenShake = 0;
	powerUpY=180;
	powerUpNoise=255;
	
	pState = STATE_LANDED;
	
	
	playerFrame = 0;
	updatePlayer();
	updatePlayerFrame();
	updateBar(HP_BAR, HP);

	updateBar(MP_BAR, MP);

	
		if (scene ==5) {
		level = 1;
		//level = 2;			//GET SNAKES WORKING BETTER
		enemiesRemaining = 23;
		}
		
		if (scene ==15){
		level = 3;
		enemiesRemaining = 43;
		}
		
		if (scene ==25){
		enemiesRemaining = 63;
		level = 5;
		}

	showValue (level,12,1,1);
	
//INITIAL ENEMIES ARE ALWAYS SLIMES TO START OUT WITH
		for (eHitIndex=0; eHitIndex!=3; eHitIndex++){
		eTime[eHitIndex] =0;
		eFrame[eHitIndex] = 0;
		eHP[eHitIndex] = 16;
		eType[eHitIndex] = 192;
		eRealType[eHitIndex] = 1;
		eDamage[eHitIndex] = 4;
		destroyEnemy();
		}

	showValue(enemiesRemaining, 17, 1, 2);

//	showValue (level,0,0,2);
//	showValue (scene,0,1,2);

	stopAllSounds();

	SHOW_WIN;
	SHOW_SPRITES;
	SHOW_BKG;

	}
