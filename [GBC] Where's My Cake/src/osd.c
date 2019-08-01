
#include "map/map_osd.h"

#define OSD_SC_X	14
void osdd_score(){
	if(score){
		foo=score;
		if(score>999){
			row[0]=1+foo/1000;
		}else{
			row[0]=0;
		}
		
		if(score>99){
			foo=foo%1000;
			row[1]=1+foo/100;
		}else{
			row[1]=0;
		}
			
		if(score>9){
			foo=foo%100;
			row[2]=1+foo/10;
		}else{
			row[2]=0;
		}
		//LSD
		row[3]=1+foo%10;
		row[4]=1;row[5]=1;
	}else{
		for(i=0;i!=5;i++)
			row[i]=0;
		row[i]=1;
	}
	set_win_tiles(OSD_SC_X,0,6,1,&row);
}

#define OSD_LV_X	2
void osdd_level(){
	foo=level+1;
	if(foo>9){
		row[0]=1+foo/10;
	}else{
		row[0]=0;
	}
	row[1]=1+foo%10;
	set_win_tiles(OSD_LV_X,0,2,1,&row);
}

#define OSD_TIME_X	8
void osdd_time(){
	if(timeleft>9){
		row[0]=1+timeleft/10;
	}else{
		row[0]=0;
	}
	row[1]=1+timeleft%10;
	set_win_tiles(OSD_TIME_X,0,2,1,&row);
}

void init_osd(){
	
	SWITCH_ROM_MBC1(TILESET_BANK);
	VBK_REG=1;
	set_win_tiles(0,0,20,1,map_osdPLN1);
	VBK_REG=0;
	set_win_tiles(0,0,20,1,map_osdPLN0);
	
	WX_REG=7;
	WY_REG=144-8;
	
	osdd_score();
	osdd_level();
	osdd_time();
	
	SHOW_WIN;
	
}
