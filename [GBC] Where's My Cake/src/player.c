
#define PANIM_STAND	0
#define PANIM_WALK	1
#define PANIM_JUMP	2
#define PANIM_FALL	3
#define PANIM_ATTACK	4
#define PANIM_HURT	5

#define PD_WALK	8
#define PD_ATTACK	20
void panimate(){
	if(panim==PANIM_STAND){
		if(panim_t==0){
			set_sprite_tile(PSPR,PTILE);
			set_sprite_tile(PSPR+1,PTILE+2);
			panim_t++;
		}
	}else if(panim==PANIM_WALK){
		if(panim_t==0 || panim_t==PD_WALK*2){
			set_sprite_tile(PSPR,PTILE);
			set_sprite_tile(PSPR+1,PTILE+2);
		}else if(panim_t==PD_WALK){
			set_sprite_tile(PSPR,PTILE+4);
			set_sprite_tile(PSPR+1,PTILE+4+2);
		}else if(panim_t==PD_WALK*3){
			set_sprite_tile(PSPR,PTILE+8);
			set_sprite_tile(PSPR+1,PTILE+8+2);
		}else if(panim_t==PD_WALK*4){
			panim_t=255;
		}
		panim_t++;
	}else if(panim==PANIM_JUMP){
		if(panim_t==0){
			set_sprite_tile(PSPR,PTILE+12);
			set_sprite_tile(PSPR+1,PTILE+12+2);
			
			panim_t++;
		}
	}else if(panim==PANIM_FALL){
		if(panim_t==0){
			set_sprite_tile(PSPR,PTILE+16);
			set_sprite_tile(PSPR+1,PTILE+16+2);
			
			panim_t++;
		}
	}else if(panim==PANIM_ATTACK){
		if(panim_t==0){
			set_sprite_tile(PSPR,PTILE+20);
			set_sprite_tile(PSPR+1,PTILE+20+2);
		}else if(panim_t==PD_ATTACK){
			panim=PANIM_STAND;
			panim_t=255;
		}
		
		panim_t++;
	}
	
}

extern unsigned char tick;
#define SHOTFADE	8
void shupd(){
	for(i=0;i!=num_shot;i++){
		if(sht[i]!=255){
			if(sht[i]<=shot_length){
				sht[i]+=shot_spd;
				shx[i]+=shvx[i];
				move_sprite(SHOT_SPR+i,8+shx[i]-scrx-4,16+shy[i]-scry-4);
			}else{
				if(sht[i]!=shot_length+SHOTFADE){
					sht[i]++;
					if(sht[i]%2){
						move_sprite(SHOT_SPR+i,0,0);
						shy[i]--;
						if(shvx[i]<0)shvx[i]++;
						else if(shvx[i]>0)shvx[i]--;
						shx[i]+=shvx[i];
					}else{
						move_sprite(SHOT_SPR+i,8+shx[i]-scrx-4,16+shy[i]-scry-4);
					}
				}else{
					sht[i]=255;
					move_sprite(SHOT_SPR+i,0,0);
				}
			}			
		}
	}
}

void shoot(){
	for(i=0;i!=num_shot;i++)
		if(sht[i]==255)break;
	if(i==num_shot)return;
		
	sht[i]=0;
	if(phflip){
		shvx[i]=-shot_spd;
		if(joy&J_LEFT)shvx[i]-=pspd;
		set_sprite_prop(SHOT_SPR+i,SHOT_PAL|S_FLIPX);
		shx[i]=px+scrx-8;
	}else{
		shvx[i]=shot_spd;
		if(joy&J_RIGHT)shvx[i]+=pspd;
		set_sprite_prop(SHOT_SPR+i,SHOT_PAL);
		shx[i]=px+scrx+8;
	}
	shy[i]=py+scry-4;
	
	panim=PANIM_ATTACK;
	panim_t=0;
	
	sfx_shoot();
}

void pflip(){
	if(phflip){
		phflip=0;
		set_sprite_prop(PSPR,PPAL);
		set_sprite_prop(PSPR+1,PPAL);
	}else{
		phflip=1;
		set_sprite_prop(PSPR,PPAL|S_FLIPX);
		set_sprite_prop(PSPR+1,PPAL|S_FLIPX);
	}
}

void pmovesprite(){
	if(phflip==0){
		move_sprite(PSPR,8+px-8,16+py-16);
		move_sprite(PSPR+1,8+px,16+py-16);
	}else{
		move_sprite(PSPR+1,8+px-8,16+py-16);
		move_sprite(PSPR,8+px,16+py-16);
	}
}

void ptile_up(){
	get_bkg_tiles((px+scrx)/8,(py-16+scry)/8,1,1,&i);
	ptile_u=tiletype[i-TILESET_TILE];
}
void ptile_down(){
	get_bkg_tiles((px+scrx)/8,(py+scry)/8,1,1,&i);
	ptile_d=tiletype[i-TILESET_TILE];
}
void ptile_left(){
	get_bkg_tiles((px-8+scrx)/8,(py-16+scry)/8,1,2,&i);
	ptile_f=tiletype[i-TILESET_TILE];
	ptile_f2=tiletype[j-TILESET_TILE];
}
void ptile_right(){
	get_bkg_tiles((px+7+scrx)/8,(py-16+scry)/8,1,2,&i);
	ptile_f=tiletype[i-TILESET_TILE];
	ptile_f2=tiletype[j-TILESET_TILE];
}

void p_upd(){
	if(!pcanjump||panim!=PANIM_ATTACK){
		if(joy&J_LEFT){
			if(panim==PANIM_STAND){
				panim=PANIM_WALK;
				panim_t=0;
			}
			if(!phflip){
				pflip();
			}
			
			if(px>=pspd)
				px-=pspd;
			else
				px=0;
			
			if(px<SCR_X1){
				i=SCR_X1-px;
				if(!(scr_loop&LOOP_HORZ)){
					if(scrx>=i){
						scrx-=i;
						px=SCR_X1;
					}
				}else{
					scrx-=i;
					px=SCR_X1;
				}
			}		
			
			ptile_left();
			if(ptile_f==TT_OBS || ptile_f2==TT_OBS){
				px+=pspd;
			}else if(ptile_f==TT_HURT || ptile_f2==TT_HURT){
				pkill();
			}
		}else if(joy&J_RIGHT){
			if(panim==PANIM_STAND){
				panim=PANIM_WALK;
				panim_t=0;
			}
			if(phflip){
				pflip();
			}
			
			if(px<=mapw*8-pspd-1)
				px+=pspd;
			else
				px=mapw*8-1;
			
			if(px>SCR_X2){
				i=px-SCR_X2;
				if(!(scr_loop&LOOP_HORZ)){
					if(scrx+i<=mapw*8-160){
						scrx+=i;
						px=SCR_X2;
					}
				}else{
					scrx+=i;
					px=SCR_X2;
				}
			}
			
			ptile_right();
			if(ptile_f==TT_OBS || ptile_f2==TT_OBS){
				px-=pspd;
			}else if(ptile_f==TT_HURT || ptile_f2==TT_HURT){
				pkill();
			}
		}else{
			if(panim==PANIM_WALK){
				panim=PANIM_STAND;
				panim_t=0;
			}
		}
	}
	
	if(pcanjump && joy&J_A && !(lastjoy&J_A)){
		pvy=-pjumpv;
		pcanjump=0;
		grav_t=0;
		if(panim!=PANIM_JUMP){
			panim=PANIM_JUMP;
			panim_t=0;
		}
		
		sfx_jump();
		
	}
	if(++grav_t==grav_delay){
		grav_t=0;
		if(pcanjump==0){
			if(pvy!=pvy_max)
				pvy++;
			if(panim!=PANIM_FALL && panim!=PANIM_ATTACK)if(pvy>0){
				panim=PANIM_FALL;
				panim_t=0;
			}
		}
	}
	
	py+=pvy;

	if(canscroll){
		i=maph*8-144+8;
		if(py>SCR_Y+YFASTER){
			if(!(scr_loop&LOOP_VERT)){
				if(scry<i){
					py-=pvy_max;
					scry+=pvy_max;
				}
			}else{
				py-=pvy_max;
				scry+=pvy_max;
			}
		}else if(py>SCR_Y+YFAST){
			if(!(scr_loop&LOOP_VERT)){ 
				if(scry<i){
					py-=2;
					scry+=2;
				}
			}else{
				py-=2;
				scry+=2;
			}
		}else if(py>SCR_Y){
			if(!(scr_loop&LOOP_VERT)){ 
				if(scry<i){
					py--;
					scry++;
				}
			}else{
				py--;
				scry++;
			}
		}else if(py<SCR_Y){
			if(!(scr_loop&LOOP_VERT)){
				if(scry>=1){
					py++;
					scry--;
				}
			}else{
				py++;
				scry--;
			}
		}
	}
	
	ptile_down();
	if(pvy==0){
		if(ptile_d==TT_PASS){
			if(pcanjump){
				pcanjump=0;
				grav_t=0;
				pvy=1;
			}
		}
	}else if(pvy>0){
		if(ptile_d==TT_OBS || ptile_d==TT_PLFM){
			py-=(py+scry)%8;
			pvy=0;
			pcanjump=1;
			if(panim==PANIM_FALL){
				panim=PANIM_STAND;
				panim_t=0;
				
				sfx_land();
				
			}
		}
	}else if(pvy<0){
		ptile_up();
		if(ptile_u==TT_OBS){
			pvy=0;
		}
	}
	if(ptile_d==TT_HURT)
		pkill();

	
	if(joy&J_B && !(lastjoy&J_B)){
		shoot();
	}
	
	
	if(canscroll)upd_scroll();
	if(pstate==PS_KILL){
		phflip=0;
		set_sprite_prop(PSPR,FLAMEPAL);
		set_sprite_prop(PSPR+1,FLAMEPAL);
		pmovesprite();
		set_sprite_tile(PSPR,FLAME);
		set_sprite_tile(PSPR+1,FLAME+2);
	}else{
		pmovesprite();
		panimate();
	}
	
	shupd();
}

void pkill(){
	if(pstate!=PS_KILL){
		pstate=PS_KILL;
		panim_t=0;
		sfx_kill();
	}
}
