
#define BEAR_DELAY	16
#define FLWR_DELAY	15
#define BUTT_DELAY	13

void e_animate(){
	
	k=etile[h];
	if(k==BEAR){
		if(eanim_t[e]==0 || eanim_t[e]==BEAR_DELAY*2){
			set_sprite_tile(ESPR+e*2,etile[h]);
			set_sprite_tile(ESPR+e*2+1,etile[h]+2);
		}else if(eanim_t[e]==BEAR_DELAY){
			set_sprite_tile(ESPR+e*2,etile[h]+4);
			set_sprite_tile(ESPR+e*2+1,etile[h]+4+2);
		}else if(eanim_t[e]==BEAR_DELAY*3){
			set_sprite_tile(ESPR+e*2,etile[h]+8);
			set_sprite_tile(ESPR+e*2+1,etile[h]+8+2);
		}else if(eanim_t[e]==BEAR_DELAY*4){
			eanim_t[e]=255;
		}
	}else if(k==BUTT){ 
		if(eanim_t[e]==0){
			set_sprite_tile(ESPR+e*2,etile[h]);
			set_sprite_tile(ESPR+e*2+1,etile[h]+2);
		}else if(eanim_t[e]==BUTT_DELAY){
			set_sprite_tile(ESPR+e*2,etile[h]+4);
			set_sprite_tile(ESPR+e*2+1,etile[h]+4+2);
		}else if(eanim_t[e]==BUTT_DELAY*2){
			eanim_t[e]=255;
		}
	}else if(k==FLWR){
		if(eanim_t[e]==0){
			set_sprite_tile(ESPR+e*2,etile[h]);
			set_sprite_tile(ESPR+e*2+1,etile[h]+2);
		}else if(eanim_t[e]==FLWR_DELAY){
			set_sprite_tile(ESPR+e*2,etile[h]+4);
			set_sprite_tile(ESPR+e*2+1,etile[h]+4+2);
		}else if(eanim_t[e]==FLWR_DELAY*2){
			eanim_t[e]=255;
		}
	}
	
	eanim_t[e]++;
}

void eflip(){
	if(ehflip[e]){
		set_sprite_prop(ESPR+e*2,epal[etype[e]]|S_FLIPX);
		set_sprite_prop(ESPR+e*2+1,epal[etype[e]]|S_FLIPX);
	}else{
		set_sprite_prop(ESPR+e*2,epal[etype[e]]);
		set_sprite_prop(ESPR+e*2+1,epal[etype[e]]);
	}
}

void emovesprite(){
	if(ehflip[e]){
		move_sprite(ESPR+e*2+1,8+ex[e]-8-scrx,16+ey[e]-16-scry);
		move_sprite(ESPR+e*2,8+ex[e]-scrx,16+ey[e]-16-scry);
	}else{
		move_sprite(ESPR+e*2,8+ex[e]-8-scrx,16+ey[e]-16-scry);
		move_sprite(ESPR+e*2+1,8+ex[e]-scrx,16+ey[e]-16-scry);
	}
}

void etile_down(){
	get_bkg_tiles((ex[e])/8,(ey[e])/8,1,1,&i);
	etile_d=tiletype[i-TILESET_TILE];
}

void etile_up(){
	get_bkg_tiles((ex[e])/8,(ey[e]-16)/8,1,1,&i);
	etile_u=tiletype[i-TILESET_TILE];
}

void etile_front(){
	if(ehflip[e])
		get_bkg_tiles((ex[e]-8)/8,(ey[e]-16)/8,1,2,&i);
	else
		get_bkg_tiles((ex[e]+7)/8,(ey[e]-16)/8,1,2,&i);
	etile_f=tiletype[i-TILESET_TILE];
	etile_f2=tiletype[j-TILESET_TILE];
}

void eai(){
	if(h==ET_A || h==ET_A2 || h==ET_A3 || h==ET_A4 || h==ET_A2F){
		if(ehflip[e]){
			ex[e]--;
			etile_front();
			etile_down();
			if(etile_d==TT_PASS || etile_d==TT_HURT || etile_f==TT_OBS || etile_f2==TT_OBS){
				ehflip[e]=0;
				eflip();
			}
		}else{
			ex[e]++;
			etile_front();
			etile_down();
			if(etile_d==TT_PASS || etile_d==TT_HURT || etile_f==TT_OBS || etile_f2==TT_OBS){
				ehflip[e]=1;
				eflip();
			}
		}
	}
	else
	if(h==ET_B || h==ET_B2){
		if(ehflip[e]){
			if(pcanjump && py+scry==ey[e]){
				ex[e]-=2;
				if(h==ET_B2 && px+scrx>ex[e]){
					ehflip[e]=0;
					eflip();
				}
			}else{
				ex[e]--;
			}
			etile_front();
			etile_down();
			if(etile_d==TT_PASS || etile_d==TT_HURT || etile_f==TT_OBS || etile_f2==TT_OBS){
				ehflip[e]=0;
				eflip();
			}
		}else{
			if(pcanjump && py+scry==ey[e]){
				ex[e]+=2;
				if(h==ET_B2 && px+scrx<ex[e]){
					ehflip[e]=1;
					eflip();
				}
			}else
				ex[e]++;
			etile_front();
			etile_down();
			if(etile_d==TT_PASS || etile_d==TT_HURT || etile_f==TT_OBS || etile_f2==TT_OBS){
				ehflip[e]=1;
				eflip();
			}
		}
	}
	else
	if(h==ET_BUTT1 || h==ET_BUTT2 || h==ET_BUTT3){
		
		if(ehflip[e]){
			ex[e]--;
			
			etile_front();
			if(etile_f==TT_OBS || etile_f2==TT_OBS){
				ehflip[e]=0;
				eflip();
			}
		}else{
			ex[e]++;
			
			etile_front();
			if(etile_f==TT_OBS || etile_f2==TT_OBS){
				ehflip[e]=1;
				eflip();
			}
		}
	}
	else
	if(h==ET_BUTTV1 || h==ET_BUTTV2 || h==ET_BUTTV3){
		
		if(ehflip[e]){
			ey[e]--;
			
			etile_up();
			if(etile_u==TT_OBS){
				ehflip[e]=0;
				eflip();
			}
		}else{
			ey[e]++;
			
			etile_down();
			if(etile_d==TT_OBS){
				ehflip[e]=1;
				eflip();
			}
		}
	}
	else
	if(h==ET_FALL || h==ET_FALLF){
		if(ehflip[e]){
			ex[e]--;
			
			etile_front();
			if(etile_f==TT_OBS || etile_f2==TT_OBS){
				ehflip[e]=0;
				eflip();
			}
		}else{
			ex[e]++;
			
			etile_front();
			if(etile_f==TT_OBS || etile_f2==TT_OBS){
				ehflip[e]=1;
				eflip();
			}
		}
		
		if(ecanjump[e]){
			etile_down();
			if(etile_d==TT_PASS){
				ecanjump[e]=0;
			}else if(etile_d==TT_HURT){
				if(ehflip[e])ehflip[e]=0;
				else ehflip[e]=1;
				eflip();
			}
		}else{
			if(egrav_t==grav_delay){
				if(evy[e]!=pvy_max*edelay[h])
					evy[e]++;
			}
			ey[e]+=evy[e];
			
			etile_down();
			if(etile_d==TT_OBS || etile_d==TT_PLFM){
				ey[e]-=ey[e]%8;
				evy[e]=0;
				ecanjump[e]=1;
			}
		}
	}
}

void spawn_enemy(unsigned char typ,unsigned char x,unsigned char y){
	for(e=0;e<MAX_EN;e++){
		if(estate[e]==ES_NULL)break;
	}
	if(e==MAX_EN)return;
	
	etype[e]=typ;
	ex[e]=x*8;
	ey[e]=y*8+8;
	estate[e]=ES_ACTIVE;
	ehflip[e]=0;
	evy[e]=0;
	ecanjump[e]=1;
	et[e]=0;
	eanim_t[e]=255;
	
	set_sprite_tile(ESPR+e*2,etile[etype[e]]);
	set_sprite_tile(ESPR+e*2+1,etile[etype[e]]+2);
	set_sprite_prop(ESPR+e*2,epal[etype[e]]);
	set_sprite_prop(ESPR+e*2+1,epal[etype[e]]);
	emovesprite();
}

void init_enemies(){
	for(e=0;e<MAX_EN;e++){
		estate[e]=ES_NULL;
		
		move_sprite(ESPR+e*2,0,0);
		move_sprite(ESPR+e*2+1,0,0);
	}
}

void e_upd(){
	egrav_t++;
	enemies_left=0;
	for(e=0;e!=MAX_EN;e++){
		if(estate[e]!=ES_NULL){
			h=etype[e];
			enemies_left++;
			if(estate[e]==ES_ACTIVE){
				et[e]++;
				if(et[e]==edelay[h]){
					et[e]=0;
					eai();
					
					for(i=0;i!=num_shot;i++){
						if(sht[i]!=255){
							if(shx[i]<ex[e]+7 && shx[i]>ex[e]-8){
								if(shy[i]>ey[e]-16 && shy[i]<ey[e]){
									estate[e]=ES_DIE;
									et[e]=0;
									sht[i]=254;
									score+=5;
									osdd_score();
									sfx_kill();
								}
							}
						}
					}
				}
				
				e_animate();
				emovesprite();
				
				px+=scrx;
				if(px<=ex[e]+8 && px>=ex[e]-8){
					py+=scry;
					if(py<=ey[e]+8 && py>ey[e]-16){
						pkill();
					}
					py-=scry;
				}
				px-=scrx;
			}else if(estate[e]==ES_DIE){
				emovesprite();
				k=et[e];
				if(k==0){
					ehflip[e]=0;
					set_sprite_prop(ESPR+e*2,FLAMEPAL);
					set_sprite_prop(ESPR+e*2+1,FLAMEPAL);
					
					set_sprite_tile(ESPR+e*2,FLAME);
					set_sprite_tile(ESPR+e*2+1,FLAME+2);
				}else if(k==FLAME_DELAY){
					set_sprite_tile(ESPR+e*2,FLAME+4);
					set_sprite_tile(ESPR+e*2+1,FLAME+4+2);
				}else if(k==FLAME_DELAY*2){
					set_sprite_tile(ESPR+e*2,FLAME+8);
					set_sprite_tile(ESPR+e*2+1,FLAME+8+2);
				}else if(k==FLAME_DELAY*3){
					set_sprite_tile(ESPR+e*2,FLAME+12);
					set_sprite_tile(ESPR+e*2+1,FLAME+12+2);
				}else if(k==FLAME_DELAY*4){
					set_sprite_tile(ESPR+e*2,FLAME+16);
					set_sprite_tile(ESPR+e*2+1,FLAME+16+2);
				}else if(k==FLAME_DELAY*5){
					set_sprite_tile(ESPR+e*2,FLAME+20);
					set_sprite_tile(ESPR+e*2+1,FLAME+20+2);
				}else if(k==FLAME_DELAY*6){
					move_sprite(ESPR+e*2,0,0);
					move_sprite(ESPR+e*2+1,0,0);
					estate[e]=ES_NULL;
				}
				et[e]++;
			}
		}
	}
	
	if(egrav_t==grav_delay)egrav_t=0;
	
	if(!enemies_left){
		level_cleared=1;
	}
}
