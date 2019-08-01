#include "libSuperAlex.h"
#include "recursos.h"
#include "enemies.h"
#include "main.h"

Enemy enemiesArray[ENEMIES_NUMBER];

int L_UPPER_LEFT = 128;
int L_DOWN_RIGHT = 392;

bool getEnemyActive(int id){
	return enemiesArray[id].active;
}
int getEnemySX(int id){
	return enemiesArray[id].screen_x;
}
int getEnemySY(int id){
	return enemiesArray[id].screen_y;
}

void ene_initEnemiesMechanism(){
	int i;
	
	for (i=0; i<ENEMIES_NUMBER;i++) {
		enemiesArray[i].active = false;
	}
}

void ene_clearEnemiesMechanism() {
	int i;
	for (i=0; i<ENEMIES_NUMBER;i++) {
		if (enemiesArray[i].active == true) {
			ene_removeEnemy(i);
			enemiesArray[i].active = false;
		}
	}
}

void ene_updateMapBoundaries(Map map){
	L_DOWN_RIGHT = map.width_px-128;
}
void ene_updateAnimVals(int i){
	switch(enemiesArray[i].category){
		case CATEGORY_STATIC :
			enemiesArray[i].animStart = enemiesArray[i].spr_num;
			enemiesArray[i].animEnd = enemiesArray[i].spr_num+1;
			enemiesArray[i].animSpeed = 8;
			break;
		case CATEGORY_JUMPER :
			enemiesArray[i].animStart = enemiesArray[i].spr_num;
			if(enemiesArray[i].state==STATE_JUMP) enemiesArray[i].animStart++;
			enemiesArray[i].animEnd = enemiesArray[i].animStart+1;
			enemiesArray[i].animSpeed = 8;
			break;
		case CATEGORY_WAS :
			switch(enemiesArray[i].state){
				case STATE_WALK :
					enemiesArray[i].animStart = enemiesArray[i].spr_num+1;
					enemiesArray[i].animEnd = enemiesArray[i].animStart+2;
					break;
				case STATE_ATTACK :
					enemiesArray[i].animStart = enemiesArray[i].spr_num+3;
					enemiesArray[i].animEnd = enemiesArray[i].animStart+3;
					break;
				case STATE_THROW :
					enemiesArray[i].animStart = enemiesArray[i].spr_num+6;
					enemiesArray[i].animEnd = enemiesArray[i].animStart+2;
					break;
				default :
					enemiesArray[i].animStart = enemiesArray[i].spr_num;
					enemiesArray[i].animEnd = enemiesArray[i].animStart+1;
			}
			
			enemiesArray[i].animSpeed = 8;
			break;
		default :
			enemiesArray[i].animStart = enemiesArray[i].spr_num;
			enemiesArray[i].animEnd = enemiesArray[i].spr_num+1;
			enemiesArray[i].animSpeed = 8;
	}
	enemiesArray[i].animFrame = enemiesArray[i].animStart;
	enemiesArray[i].animCount = 0;
}
void ene_explodeEnemy(int id) {
	enemiesArray[id].animStart = 16;
	enemiesArray[id].animEnd = 19;
	enemiesArray[id].animSpeed = 8;
	enemiesArray[id].animFrame = enemiesArray[id].animStart;
	enemiesArray[id].animCount = 0;
	enemiesArray[id].touchAction= ACTION_NONE;
	enemiesArray[id].category = CATEGORY_STATIC;
	enemiesArray[id].behaivour = BEHAIVOUR_NONE;
	enemiesArray[id].gravity = false;
}
void ene_explodeAllEnemies(int id) {
	int i;
	for (i=0; i<ENEMIES_NUMBER;i++) {
		if (enemiesArray[i].active == true) {
			if(enemiesArray[i].category != CATEGORY_DUMMY) ene_explodeEnemy(i);
		}
	}
}
void setEnemyState(int i, int state, bool override){
	if((enemiesArray[i].state != state) || override){
		enemiesArray[i].state = state;
		ene_updateAnimVals(i);
	}
}
void ene_addEnemy(int category, u8 spr_num, int map_x, int map_y, int speed, int behaivour, int touchAction, void (*callback)(void), int power, bool gravity, bool kamikaze, int pallete){
	
	int i;
	
	//search the first free slot
	for (i=0; i<ENEMIES_NUMBER;i++) {
		if (enemiesArray[i].active == false) {
			//add it here
			enemiesArray[i].active = true;
			enemiesArray[i].map_x = map_x <<PRECISSION;
			enemiesArray[i].map_y = map_y <<PRECISSION;
			enemiesArray[i].category = category;
			enemiesArray[i].speed = speed;
			enemiesArray[i].behaivour = behaivour;
			enemiesArray[i].touchAction = touchAction;
			enemiesArray[i].callback = callback;
			enemiesArray[i].power = power;
			enemiesArray[i].gravity = gravity;
			enemiesArray[i].kamikaze = kamikaze;
			enemiesArray[i].pallete = pallete;
			
			enemiesArray[i].spr_num = spr_num; //sprite graphic offset start (gfx start + offset in the picture)
			setEnemyState(i, STATE_WALK, true);
			enemiesArray[i].visible = false;
			enemiesArray[i].screen_x = 0;
			enemiesArray[i].screen_y = 0;
			enemiesArray[i].invencibility = 0;
			enemiesArray[i].invencibility_toogle = true;
			enemiesArray[i].flipx = 0;
			if (category != CATEGORY_DUMMY) {
				alex_spriteShow(ENEMIES_LAYER + i, 0, enemiesArray[i].screen_x, enemiesArray[i].screen_y, 2, 0, 0, enemiesArray[i].pallete);
				oamSetVisible((ENEMIES_LAYER + i)*4,OBJ_HIDE);
			} else {
				oamSetVisible((ENEMIES_LAYER + i)*4,OBJ_HIDE);
			}

			
			return;
		}
	}
	
	//nope, no free slots
	return;
}

void _ene_updateSprites(Player player) {
	
	int i;
	int prec_x=player.x>>PRECISSION, prec_y=player.y>>PRECISSION;
	int limitX=120;
	int limitY=120;
	
	//search the first active slot
	for (i=0; i<ENEMIES_NUMBER;i++) {
		if (enemiesArray[i].active == true) {
			
			//update screen coordinates
			//alex_cleanText();
			//consoleDrawText(1,5,"enemy pos=%d # %d", enemiesArray[i].map_x>>PRECISSION , enemiesArray[i].map_y>>PRECISSION);
			enemiesArray[i].distance_x = (enemiesArray[i].map_x>>PRECISSION) - prec_x;
			enemiesArray[i].distance_y = (enemiesArray[i].map_y>>PRECISSION) - prec_y;
			
			//map boundaries limit
			//if (prec_x > L_DOWN_RIGHT) enemiesArray[i].distance_x += 128;
			//if (prec_x < L_UPPER_LEFT) enemiesArray[i].distance_x -= 128;
			//if (prec_y > L_DOWN_RIGHT) enemiesArray[i].distance_y -= (prec_y - L_DOWN_RIGHT );
			//if (prec_y > L_UPPER_LEFT) enemiesArray[i].distance_y -= (L_UPPER_LEFT - prec_y );
			if (enemiesArray[i].category != CATEGORY_DUMMY) {
				enemiesArray[i].screen_x = player.s_x + enemiesArray[i].distance_x;
				enemiesArray[i].screen_y = player.s_y + enemiesArray[i].distance_y;
				//sprintf(_debugMessage, "screen_x=%d screen_y=%d", enemiesArray[i].screen_x , enemiesArray[i].screen_y);
				//alex_die(_debugMessage);
				//consoleDrawText(1,7,"ENEMYscreen_x=%d # %d", enemiesArray[i].screen_x , enemiesArray[i].screen_y);
				//it must be visible on screen?
				//if (prec_x < L_UPPER_LEFT) limitX-=(prec_x - L_UPPER_LEFT );
				if (prec_y < L_UPPER_LEFT) limitY-=(prec_y - L_UPPER_LEFT );
				if (prec_x > L_DOWN_RIGHT) limitX+=(prec_x - L_DOWN_RIGHT );
				if (prec_y > L_DOWN_RIGHT) limitY+=(prec_y - L_DOWN_RIGHT );
				//consoleDrawText(1,i,"distance_x=%d # %d", enemiesArray[i].distance_x , enemiesArray[i].distance_y);
				enemiesArray[i].visible = true;
				if(enemiesArray[i].category != CATEGORY_BOSS) {
					if (enemiesArray[i].distance_x > limitX ) enemiesArray[i].visible = false;
					if (enemiesArray[i].distance_x < -limitX ) enemiesArray[i].visible = false;
					if (enemiesArray[i].distance_y > limitY ) enemiesArray[i].visible = false;
					if (enemiesArray[i].distance_y < -limitY ) enemiesArray[i].visible = false;
				}
				/*if (enemiesArray[i].screen_x > 256 || enemiesArray[i].distance_x > 256) enemiesArray[i].visible = false;
				if (enemiesArray[i].screen_x < 0 || enemiesArray[i].distance_x < -256) enemiesArray[i].visible = false;
				if (enemiesArray[i].screen_y > 225 || enemiesArray[i].distance_y > 256) enemiesArray[i].visible = false;
				if (enemiesArray[i].screen_y < 0 || enemiesArray[i].distance_y < -256) enemiesArray[i].visible = false;*/
			}
			//consoleDrawText(1,6,"distance_x=%d # %d", enemiesArray[i].distance_x , enemiesArray[i].distance_y);

			
			//update sprite in the OAM
			if (enemiesArray[i].visible == true) {
				//sprintf(_debugMessage, "screen_x=%d screen_y=%d", enemiesArray[i].screen_x , enemiesArray[i].screen_y);
				//alex_die(_debugMessage);
				//Update animation
				enemiesArray[i].animCount += 1;
				if(enemiesArray[i].animCount >= enemiesArray[i].animSpeed) {
					enemiesArray[i].animFrame += 1;
					if(enemiesArray[i].animFrame >= enemiesArray[i].animEnd) enemiesArray[i].animFrame=enemiesArray[i].animStart;
					enemiesArray[i].animCount = 0;
				}
				//update the coordinates and show it
				//alex_spriteUpdateCoordinates(ENEMIES_LAYER + i, enemiesArray[i].screen_x , enemiesArray[i].screen_y);
				alex_spriteUpdateFrameXY(ENEMIES_LAYER + i, enemiesArray[i].animFrame, enemiesArray[i].screen_x , enemiesArray[i].screen_y, enemiesArray[i].flipx);
				//oamSet((ENEMIES_LAYER + i)*4, enemiesArray[i].screen_x, enemiesArray[i].screen_y, 2, 0, 0, enemiesArray[i].animFrame, 0);
				//anim_update(enemiesArray[i].spr_offStart,i+1,enemiesArray[i].animFrame);
				
				//oamSet(4, enemiesArray[i].screen_x, enemiesArray[i].screen_y, 2, 0, 0, 1-1, 0); 
				//oamSetEx(4, OBJ_SMALL, OBJ_SHOW);
				//oamSetVisible(4,OBJ_SHOW);
				
				//is player attacking the enemy?
				if (enemiesArray[i].active == true && player.state == STATE_ATTACK && enemiesArray[i].power !=-1 && enemiesArray[i].invencibility == 0) {
					if (enemiesArray[i].distance_y < ENEMIES_TOUCH_CLOSE && enemiesArray[i].distance_y > -ENEMIES_TOUCH_CLOSE)
					{
						if (enemiesArray[i].distance_x < ENEMIES_ATTACK_CLOSE && enemiesArray[i].distance_x > -ENEMIES_ATTACK_CLOSE) {
							//remove 1 hp
							enemiesArray[i].power--;
							if (enemiesArray[i].power == 0){
								//destroy it
								//ene_removeEnemy(i);
								ene_explodeEnemy(i);
							} else {
								enemiesArray[i].invencibility = 15;
							}
						}
					}
				}
				
				//is the player being hurted?
				if (enemiesArray[i].active == true && enemiesArray[i].invencibility != 0) {
					enemiesArray[i].invencibility--;
					if (enemiesArray[i].invencibility_toogle == true){
						enemiesArray[i].invencibility_toogle = false;
						oamSetVisible((ENEMIES_LAYER + i)*4,OBJ_HIDE);
					} else {
						enemiesArray[i].invencibility_toogle = true;
						oamSetVisible((ENEMIES_LAYER + i)*4,OBJ_SHOW);
					}
					if (enemiesArray[i].invencibility== 0){
						enemiesArray[i].invencibility_toogle = true;
						oamSetVisible((ENEMIES_LAYER + i)*4,OBJ_SHOW);
					}
				}
				
					//any behaivour?
					if (enemiesArray[i].invencibility ==0 ) {
						//Behaviour: WALKER --------------------------------------------------------------------------------------------------
						if (enemiesArray[i].behaivour == BEHAIVOUR_WALK_LEFT) {
							if (spriteCollision(enemiesArray[i].map_x -16 * enemiesArray[i].speed , enemiesArray[i].map_y) != true) {
								enemiesArray[i].map_x-=16 * enemiesArray[i].speed;
								enemiesArray[i].flipx = 0;
							} else {
								enemiesArray[i].behaivour = BEHAIVOUR_WALK_RIGHT;
							}
						} else if (enemiesArray[i].behaivour == BEHAIVOUR_WALK_RIGHT) {
							if (spriteCollision(enemiesArray[i].map_x +16 * enemiesArray[i].speed , enemiesArray[i].map_y) != true) {
								enemiesArray[i].map_x+=16* enemiesArray[i].speed;
								enemiesArray[i].flipx = 1;
							} else {
								enemiesArray[i].behaivour = BEHAIVOUR_WALK_LEFT;
							}
						//Behaviour: Shoot! (left) ------------------------------------------------------------------------------------------
						} else if (enemiesArray[i].behaivour == BEHAIVOUR_DEATH_LEFT) {
							if (spriteCollision(enemiesArray[i].map_x -16 * enemiesArray[i].speed , enemiesArray[i].map_y) != true) {
								enemiesArray[i].map_x-=16 * enemiesArray[i].speed;
							} else {
								ene_explodeEnemy(i);//ene_removeEnemy(i);
							}
						//Behaviour: Shoot! (right) -----------------------------------------------------------------------------------------
						} else if (enemiesArray[i].behaivour == BEHAIVOUR_DEATH_RIGHT) {
							if (spriteCollision(enemiesArray[i].map_x +16 * enemiesArray[i].speed , enemiesArray[i].map_y) != true) {
								enemiesArray[i].map_x+=16 * enemiesArray[i].speed;
							} else {
								ene_explodeEnemy(i);//ene_removeEnemy(i);
							}
						//Behaviour: JUMPER -------------------------------------------------------------------------------------------------
						} else if (enemiesArray[i].behaivour == BEHAIVOUR_JUMPER) {
						
							if (spriteCollision(enemiesArray[i].map_x, enemiesArray[i].map_y+PRECVAL) == true) {
								if(enemiesArray[i].active == true && enemiesArray[i].distance_x < ENEMIES_TOUCH_CLOSE && enemiesArray[i].distance_x > -ENEMIES_TOUCH_CLOSE){
									enemiesArray[i].speed = -JUMPVALUE*3;
									setEnemyState(i, STATE_JUMP, false);
								}
							}
							enemiesArray[i].speed += GRAVITY;
							if(enemiesArray[i].speed > MAX_FALL) enemiesArray[i].speed = MAX_FALL;
							if (spriteCollision(enemiesArray[i].map_x, enemiesArray[i].map_y+enemiesArray[i].speed) == true){
								enemiesArray[i].speed = 0;
								setEnemyState(i, STATE_STAND, false);
							}
							enemiesArray[i].map_y += enemiesArray[i].speed;
						//Behaviour: FAST SINE
						} else if (enemiesArray[i].behaivour == BEHAIVOUR_FAST_SINE) {
							if(enemiesArray[i].state==STATE_ATTACK){
								if(enemiesArray[i].animSpeed<16){
									enemiesArray[i].map_y += 64;
									if(enemiesArray[i].map_y > 204<<PRECISSION) enemiesArray[i].animSpeed = 24;
								}else{
									enemiesArray[i].map_y -= 64;
									if(enemiesArray[i].map_y < 68<<PRECISSION) {
										enemiesArray[i].animSpeed = 8;
										enemiesArray[i].state=STATE_STAND;
									}
								}
							} else {
								if(enemiesArray[i].distance_x < 0) enemiesArray[i].speed += 6;
								if(enemiesArray[i].distance_x > 0) enemiesArray[i].speed -= 6;
								
								if(enemiesArray[i].speed > 0) {	//moving right
									enemiesArray[i].speed -= 4;
									if(enemiesArray[i].speed < 0) enemiesArray[i].speed = 0;
									if(enemiesArray[i].speed > WALK_MAXSPEED) enemiesArray[i].speed = WALK_MAXSPEED;
								}
								if(enemiesArray[i].speed < 0) { //moving left
									enemiesArray[i].speed += 4;
									if(enemiesArray[i].speed > 0) enemiesArray[i].speed = 0;
									if(enemiesArray[i].speed < -WALK_MAXSPEED) enemiesArray[i].speed = -WALK_MAXSPEED;
								}
								
								enemiesArray[i].map_x += enemiesArray[i].speed;
								enemiesArray[i].animSpeed+=1;
								if(enemiesArray[i].animSpeed > 48) {
									enemiesArray[i].state=STATE_ATTACK;
									enemiesArray[i].animSpeed = 8;
								}
							}
							
						}  else if (enemiesArray[i].behaivour == BEHAIVOUR_MIMIC1) {
							enemiesArray[i].map_x = enemiesArray[ enemiesArray[i].speed ].map_x+256;
							enemiesArray[i].map_y = enemiesArray[ enemiesArray[i].speed ].map_y;
						}  else if (enemiesArray[i].behaivour == BEHAIVOUR_MIMIC2) {
							enemiesArray[i].map_x = enemiesArray[ enemiesArray[i].speed ].map_x;
							enemiesArray[i].map_y = enemiesArray[ enemiesArray[i].speed ].map_y+256;
						}  else if (enemiesArray[i].behaivour == BEHAIVOUR_MIMIC3) {
							enemiesArray[i].map_x = enemiesArray[ enemiesArray[i].speed ].map_x+256;
							enemiesArray[i].map_y = enemiesArray[ enemiesArray[i].speed ].map_y+256;
						}
					}
					
					//if there's gravity, apply it
					if (enemiesArray[i].gravity == true){
						if (spriteCollision(enemiesArray[i].map_x, enemiesArray[i].map_y+32) != true) {
							enemiesArray[i].map_y+=32;
						} 
					}
				
			} else {
				//just hide it
				enemiesArray[i].invencibility = 0;
				enemiesArray[i].invencibility_toogle = true;
				alex_spriteRemove((ENEMIES_LAYER + i));
				//oamSetVisible((ENEMIES_LAYER + i)*4,OBJ_HIDE);
				//If is kamikaze, delete it
				if (enemiesArray[i].kamikaze == true) {
					ene_explodeEnemy(i);
				}
			}
			
			//is player touching enemy?
			if (enemiesArray[i].visible == true || enemiesArray[i].category == CATEGORY_DUMMY)
				if (enemiesArray[i].active == true && enemiesArray[i].distance_x < ENEMIES_TOUCH_CLOSE && enemiesArray[i].distance_x > -ENEMIES_TOUCH_CLOSE) {
					if (enemiesArray[i].distance_y < ENEMIES_TOUCH_CLOSE && enemiesArray[i].distance_y > -ENEMIES_TOUCH_CLOSE) {
						//is touching! What's the touch action?
						if (enemiesArray[i].touchAction == ACTION_HURT_1) {
							atHurt(1);
						}
						else if (enemiesArray[i].touchAction == ACTION_HURT_2) {
							atHurt(2);
						}
						else if (enemiesArray[i].touchAction == ACTION_HURT_3) {
							atHurt(3);
						} 
						else if (enemiesArray[i].touchAction == ACTION_RECOVER_1) {
							atRecover(1);
						}
						else if (enemiesArray[i].touchAction == ACTION_RECOVER_2) {
							atRecover(2);
						}
						else if (enemiesArray[i].touchAction == ACTION_RECOVER_3) {
							atRecover(3);
						}
						else if (enemiesArray[i].touchAction == ACTION_CALL_FUNCTION) {
							if (enemiesArray[i].callback != NULL) {
								enemiesArray[i].callback();
							}
						}
						
						//If is kamikaze, delete it
						if (enemiesArray[i].kamikaze == true) {
							ene_removeEnemy(i);
						}
					}
				}
				
		}
		if(enemiesArray[i].animFrame==18 && enemiesArray[i].animCount>6){
			ene_removeEnemy(i);
		}
	}
}

void ene_removeEnemy(int id) {
	alex_spriteRemove((ENEMIES_LAYER + id));
	enemiesArray[id].active = false;
	if(enemiesArray[id].category==CATEGORY_BOSS){
		ene_clearEnemiesMechanism();
	}
}