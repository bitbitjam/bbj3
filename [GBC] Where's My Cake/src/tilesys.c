
#include "chr/chr_tileset.h"

const unsigned int tileset_pal[]={
	chr_tilesetCGBPal0c0,chr_tilesetCGBPal0c1,chr_tilesetCGBPal0c2,chr_tilesetCGBPal0c3,
	chr_tilesetCGBPal1c0,chr_tilesetCGBPal1c1,chr_tilesetCGBPal1c2,chr_tilesetCGBPal1c3,
	chr_tilesetCGBPal2c0,chr_tilesetCGBPal2c1,chr_tilesetCGBPal2c2,chr_tilesetCGBPal2c3,
	chr_tilesetCGBPal3c0,chr_tilesetCGBPal3c1,chr_tilesetCGBPal3c2,chr_tilesetCGBPal3c3,
	chr_tilesetCGBPal4c0,chr_tilesetCGBPal4c1,chr_tilesetCGBPal4c2,chr_tilesetCGBPal4c3,
	chr_tilesetCGBPal5c0,chr_tilesetCGBPal5c1,chr_tilesetCGBPal5c2,chr_tilesetCGBPal5c3,
	chr_tilesetCGBPal6c0,chr_tilesetCGBPal6c1,chr_tilesetCGBPal6c2,chr_tilesetCGBPal6c3,
	chr_tilesetCGBPal7c0,chr_tilesetCGBPal7c1,chr_tilesetCGBPal7c2,chr_tilesetCGBPal7c3,
};

void load_tileset(){
	SWITCH_ROM_MBC1(TILESET_BANK);
	set_bkg_palette(0,8,&tileset_pal[0]);
	set_bkg_data(TILESET_TILE,chr_tilesetLen,chr_tileset);
}
