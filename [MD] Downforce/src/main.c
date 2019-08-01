#include "main.h"

////////////////////////////////////////////////////////////////////////////////
//
// int main()
//
////////////////////////////////////////////////////////////////////////////////
int main(){

    u8 exit = 0, mode = 1, circuit;

    // Pone las copias "shadow" de los registros a sus
    // valores por defecto, establecidos en hw_md.s
    VDP_init();

    // cambio el registro 11 del vdp para configurar el scroll
    // 4 half vscroll, full hscroll, el 6 es cell hscroll, el 7 es line hscroll
    VDP_setReg(11, 0x04);
    VDP_setHorizontalScroll(BPLAN, 0, 0);
    VDP_setHorizontalScroll(APLAN, 0, 0);

    // modo de 40 columnas
    VDP_setReg(12, 0x81);

    // definimos el tamaño del scroll a 64x32 tiles
    VDP_setReg(16, 0x01);
	
	 // carga el driver XGM en el z80
    SND_loadDriver_XGM();

    // inicia la SRAM
    initSRAM();
	
	// seleccionamos modo de la TV, horizontal o vertical
	mode = selectMode();
	
	disclaimerScreen( mode );

    ////////////////////////////////////////
    //  bucle infinito
    ////////////////////////////////////////
	while(1){

	    // attract mode
	    while( !exit ){

            draw1985Logo(mode);     // pantalla del logo

            introScreen(mode);    // intro

            // pantalla de titulo
			circuit = 0;
            exit = titleScreen(mode, &circuit);
	    }

        // doy valor inicial a las vars del juego,
        // carga los tiles e inicia sus sprites
        initGame(mode, circuit);

        gameLoop(mode, circuit);
        recordsScreen(1);

        exit = 0;
	}

    return 0;
}
