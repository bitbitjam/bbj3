#include <stdlib.h>
#include <snes.h>
#include "libSuperAlex.h"
#include "soundbank.h"
#include "recursos.h"

Alex_Timer __alex_timers[NUM_TIMERS];
Alex_SpriteData __alex_sprites[128];
Alex_SpriteMovimiento __alex_movimientos[128];

char _debugMessage[200];
char _tamanioSprite;

int _fadeMelodia;

void alex_init(void) {
	
	int i=0;
	_fadeMelodia=0;
	
	//inicializar procesadores
	spcBoot();
	consoleInit();
    
    // Inicializar fuente. snesfont es un extern.
	consoleInitText(2, 0, &snesfont);
	
	
	//cargar banco de sonidos y asignamos algunos bloques de 256 bytes.
	spcSetBank(&__SOUNDBANK__);
	spcAllocateSoundRegion(BLOQUES_256_BYTES_SONIDO); 
	
	alex_setBrightness(0x0);
	
	alex_spriteSetSize(SPRITE_SIZE_16);
	
	//inicializar timers
	for (i=0; i<NUM_TIMERS; i++) {
		__alex_timers[i].activo = 0;
	}
	
	//inicializar datos de sprites
	for (i=0; i<128; i++) {
		__alex_sprites[i].x=0;
		__alex_sprites[i].y=0;
	}
	
	//inicializar datos de animaciones
	for (i=0; i<128; i++) {
		__alex_movimientos[i].activo = 0;
		__alex_movimientos[i].callback = NULL;
	}
}

void alex_loop(void) {
	
	//actualizar cosas de la lib
	_alex_actualizarTimers();
	_alex_actualizarMovSprites();
	_alex_actualizarFadeMelodia();
	
	//actualizar cosas de SNES
	spcProcess();
	WaitForVBlank();
	scanPads();
}

void alex_setBrightness(u8 intensidad) {
	setBrightness(intensidad);
}

void alex_die(char* mensaje) {
	consoleDrawText(0,1,"**** KABOOM! =( ****");
	if (mensaje!=NULL) {
		consoleDrawText(0,3, mensaje);
	}
	consoleSetTextCol(RGB15(0,0,0),  RGB15(31,0,0));
	while(1) {
		WaitForVBlank();
	}
}

//================================================
//consola
void alex_cleanText(void) {
	/*int i = 0;
	int j = 0;
	
	for (i=0;i<28; i++) {
		for (j=0; j<32; j++) {
			consoleDrawText(j,i," ");
		}
	}*/
	int x;
	for (x=0;x<0x800;x++) pvsneslibfont_map[x] = 0x00;
}

//================================================
//timer
void alex_timerSet(int timerID, int tiempo, void (*callback)(void) ) {
	//tiempo 0xFFF
	__alex_timers[timerID].activo = 1;
	__alex_timers[timerID].restante = tiempo;
	__alex_timers[timerID].callback = callback;
}

bool alex_timerIsOver(int timerID) {
	if (__alex_timers[timerID].activo == 0) return true;
	return false;
}

void alex_timerStop(int timerID) {
	__alex_timers[timerID].activo = 0;
}

u16 alex_timerGetRemain(int timerID) {
	return __alex_timers[timerID].restante;
}

void _alex_actualizarTimers(void) {
	
	int i=0;
	
	for (i=0; i<NUM_TIMERS; i++) {
		if (__alex_timers[i].activo == 1) {
			__alex_timers[i].restante--;
			if (__alex_timers[i].restante == 0 ) {
				//se acabo el tiempo. 
				__alex_timers[i].activo = 0;
				//Llamar callback si corresponde
				if (__alex_timers[i].callback != NULL) {
					__alex_timers[i].callback();
				}
			}
		}
	}
}

//================================================
//musica

void alex_melodyLoad(u16 melodia, u8 volumen) {
	spcLoad(melodia);
	spcSetModuleVolume(volumen);
}

void alex_melodyPlay(void) {
	spcPlay(0);
}

void alex_melodyStop(void) {
	spcStop();
	//spcSetModuleVolume(255);
}

void alex_melodyFade() {
	//spcFadeModuleVolume(volumen, velocidad);
	_fadeMelodia=31;
}

void alex_melodyVol(u8 volumen) {
	spcSetModuleVolume(volumen);
}

void _alex_actualizarFadeMelodia(void){
	if (_fadeMelodia!=0){
		_fadeMelodia--;
		spcSetModuleVolume(_fadeMelodia*8);
	}
}

//================================================
//sonido

//puedes tener problemas de punteros aqui, ojo
void alex_cargarSonido(
			u8 *sonido, 
			u16 fin_sonido, 
			u8 vol, 
			u8 balance,
			brrsamples *destinoMemoria) 
{
	
	//alex_cargarSonido(&jumpsnd, &jumpsndend,SFX_VOL_DEFAULT,SFX_PANORAMA_DEFAULT,&destino);
	spcSetSoundEntry(vol, balance, FREQ_SFX, (fin_sonido - sonido) , sonido, destinoMemoria);
}

void alex_soundPlay(void) {
	spcPlaySoundV(0,15);	
}

//================================================
//control

int alex_buttonIsPressed(int control, u16 boton) {
	unsigned short pad = padsCurrent(control);
	if (pad & boton) {
		return 1;
	}
	return 0;
}
bool alex_anyButtonPressed(int control) {
	unsigned short pad = padsCurrent(control);
	return (pad != 0);
}

//================================================
//graficos

void alex_screenFadeOut(void){
	setFadeEffect(FADE_OUT);
}

void alex_screenFadeIn(void){
	setFadeEffect(FADE_IN);
}

void alex_cargarSprites(u8 *dir, u8 *dirEnd, u8 *paleta, u8 *paletaEnd, u16 dir) {
	//em, funciona mal xD
	//oamInitGfxSet(&sprite_prueba32, (&sprite_prueba32_end-&sprite_prueba32), &paleta_prueba32, (&paleta_prueba32_end-&paleta_prueba32), 0, 0x4000, OBJ_SIZE16);
	oamInitGfxSet((u8*) dir, (dirEnd- dir), (u8*)paleta, (paletaEnd - paleta), 0, dir, OBJ_SIZE16);
}

void alex_spriteSetSize(u8 tamanio){
	_tamanioSprite = tamanio;
}

//x, y 0-255
//prioridad 0-3
//vflip, hflip 0-1

void alex_spriteShow(int id, int offset, short x, short y, int prioridad, int vflip, int hflip, int paleta) {
	
	__alex_sprites[id].offset=offset;
	__alex_sprites[id].x=x;
	__alex_sprites[id].y=y;
	__alex_sprites[id].prioridad=prioridad;
	__alex_sprites[id].vflip=vflip;
	__alex_sprites[id].hflip=hflip;
	__alex_sprites[id].paleta=paleta;
	
	_alex_aplicarSprite(id);
}

void alex_spriteRemove(int id) {
	int idx = id * 4;
	__alex_movimientos[id].activo=0;
	//id debe ser multiplo de 4
	oamSetVisible(idx,OBJ_HIDE);
}

short alex_spriteGetX(int id) {
	return __alex_sprites[id].x;
}

short alex_spriteGetY(int id) {
	return __alex_sprites[id].y;
}

void alex_spriteUpdateCoordinates(int id, int x, int y) {
	__alex_sprites[id].x=x;
	__alex_sprites[id].y=y;
	_alex_aplicarSprite(id);
}
void alex_spriteUpdateFrameXY(int id, int offset, short x, short y, int vflip) {
	
	__alex_sprites[id].offset=offset;
	__alex_sprites[id].x=x;
	__alex_sprites[id].y=y;
	__alex_sprites[id].vflip=vflip;
	
	_alex_aplicarSprite(id);
}

void alex_spriteUpdateTileNumber(int id, int offset) {
	__alex_sprites[id].offset=offset;
	_alex_aplicarSprite(id);
}

void alex_spriteMove(int id, int x, int y, int duracion, void (*callback)(void) ) {
	
	signed short distx, disty;
	float no_usado;
	
	__alex_movimientos[id].activo=1;
	__alex_movimientos[id].nx=x;
	__alex_movimientos[id].ny=y;
	__alex_movimientos[id].restante=duracion;
	
	//calcular velocidad
	distx = x - alex_spriteGetX(id);
	disty = y - alex_spriteGetY(id);
	
	__alex_movimientos[id].xspeed = (float) distx / (float) duracion;
	__alex_movimientos[id].yspeed = (float) disty / (float) duracion;
	
	__alex_movimientos[id].acumx = 0.0;
	__alex_movimientos[id].acumy = 0.0;
	
	__alex_movimientos[id].callback = callback;
}

void alex_spriteStopMove(int id) {
	__alex_movimientos[id].activo=0;
}

void _alex_aplicarSprite(int id){
	//id debe ser multiplo de 4
	
	int fours, offset, modo;
	int idx = id*4;
	
	if (_tamanioSprite == SPRITE_SIZE_16) {
		//16x16
		//modo = OBJ_SMALL;
		//fours = (__alex_sprites[id].offset / 8);
		//offset = ((fours * 16) + __alex_sprites[id].offset % 8) *2;
		modo = OBJ_SMALL;
		fours = (__alex_sprites[id].offset / 4);
		offset = (__alex_sprites[id].offset + (fours*12))*4;
	} 
	else {
		
		//32x32
		modo = OBJ_LARGE;
		fours = (__alex_sprites[id].offset / 4);
		offset = (__alex_sprites[id].offset + (fours*12))*4;
		
	}
	//*2 en 16, *4 en 32
	//******************
	//int offset = __alex_sprites[id].offset *2;
	//int offset = 6 2 en 16 12 4 en 32
	//int offset = (__alex_sprites[id].offset  + (fours*8))*2;
	//******************
	oamSet(idx, __alex_sprites[id].x, __alex_sprites[id].y, __alex_sprites[id].prioridad, __alex_sprites[id].vflip, __alex_sprites[id].hflip, offset, __alex_sprites[id].paleta); 
	oamSetEx(idx, modo, OBJ_SHOW);
	oamSetVisible(idx,OBJ_SHOW);
}

/**
typedef struct {
	u8 activo;
	short nx;
	short ny;
	signed int xspeed;
	signed int yspeed;
	int acumx;
	int acumy;
	u16 restante;
	void (*callback)(void);
}Alex_SpriteMovimiento;

Alex_SpriteMovimiento __alex_movimientos[128];
*/

void _alex_actualizarMovSprites(void) {
	int i = 0;
	int acumx = 0;
	int acumy = 0;
	
	int contPixeles, nuevox, nuevoy;
	
	for (i=0; i<128;i++) {
		if (__alex_movimientos[i].activo == 1 ) {
			//hacer movimiento en este sprite
			
			//obtener coordenadas actuales
			nuevox = alex_spriteGetX(i);
			nuevoy = alex_spriteGetY(i);
			
			__alex_movimientos[i].acumx +=__alex_movimientos[i].xspeed;
			__alex_movimientos[i].acumy +=__alex_movimientos[i].yspeed;
			
			//hay que mover pixeles?
			
			// x>1
			contPixeles = 0;
			if (__alex_movimientos[i].acumx > 1) {
				while(__alex_movimientos[i].acumx > 1) {
					contPixeles++;
					__alex_movimientos[i].acumx-=1;
				}
				nuevox += contPixeles;
			} 
			
			// x<-1
			contPixeles = 0;
			if (__alex_movimientos[i].acumx < -1) {
				while(__alex_movimientos[i].acumx < -1) {
					contPixeles--;
					__alex_movimientos[i].acumx+=1;
				}
				nuevox += contPixeles;
			}
			
			// y>1
			contPixeles = 0;
			if (__alex_movimientos[i].acumy > 1) {
				while(__alex_movimientos[i].acumy > 1) {
					contPixeles++;
					__alex_movimientos[i].acumy-=1;
				}
				nuevoy += contPixeles;
			} 
			
			// y<-1
			contPixeles = 0;
			if (__alex_movimientos[i].acumy < -1) {
				while(__alex_movimientos[i].acumy < -1) {
					contPixeles--;
					__alex_movimientos[i].acumy+=1;
				}
				nuevoy += contPixeles;
			} 
			
			//aplicar movimiento si es distinto al original
			if (nuevox != alex_spriteGetX(i) || nuevoy != alex_spriteGetY(i)) {
				alex_spriteUpdateCoordinates(i, nuevox, nuevoy);
			}
			
			//correr el timer
			__alex_movimientos[i].restante--;
			if (__alex_movimientos[i].restante == 0) {
				__alex_movimientos[i].activo=0;
				alex_spriteUpdateCoordinates(i, __alex_movimientos[i].nx, __alex_movimientos[i].ny);
				//Llamar callback si corresponde
				if (__alex_movimientos[i].callback != NULL) {
					__alex_movimientos[i].callback();
				}
			}
			
		}
	}
}