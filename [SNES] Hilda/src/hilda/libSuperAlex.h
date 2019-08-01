#include <snes.h>
#include "soundbank.h"

#ifndef __LIBALEX_LIB__
#define __LIBALEX_LIB__

//numero de bloques de 256 bytes para el buffer de sonido.
#define BLOQUES_256_BYTES_SONIDO 39

//Frecuencia de los efectos de sonido.
//Cada numero son 2000 Hz. Maximo son 6.
//Por ejemplo, 6 es 6*2000 = 12000 Hz.
#define FREQ_SFX 6

#define SFX_PANORAMA_DEFAULT 8
#define SFX_VOL_DEFAULT 15

#define MUSIC_VOL_DEFAULT 255

//numero de timers que manejara el juego.
#define NUM_TIMERS 8

#define TIMER_QUARTER_SECOND 7
#define TIMER_HALF_SECOND 15
#define TIMER_SECOND 31

#define SPRITE_SIZE_16 0
#define SPRITE_SIZE_32 1

typedef struct {
	u8 activo;
	u16 restante;
	void (*callback)(void);
}Alex_Timer;

typedef struct {
	short offset;
	short x;
	short y;
	short prioridad;
	short vflip;
	short hflip;
	short paleta;
}Alex_SpriteData;

typedef struct {
	u8 activo;
	short nx;
	short ny;
	signed float xspeed;
	signed float yspeed;
	signed float acumx;
	signed float acumy;
	u16 restante;
	void (*callback)(void);
}Alex_SpriteMovimiento;

//=====================================================================

/**
Inicializa todo
*/
void alex_init(void);

/**
Procesa el resto de cosas internas de la SNES que no nos interesa mucho.
*/
void alex_loop(void);

/**
Setea brillo. Valores desde 0x0 a 0xF
*/
void alex_setBrightness(u8 intensidad);

/**
Hacer que el juego muera xD! Util para debugear cosas!
Mensaje (opcional) le pasas un string con algo (usa sprintf).
Sino, le pasas NULL.

Ejemplo:
//**********MATAR**************
sprintf(_mensajeDebug, "contPixeles=%d nuevox=%d", contPixeles, nuevox);
alex_die(_mensajeDebug);
*/
void alex_die(char* mensaje);

//=====================================================================

/**
Limpia la pantalla de texto
*/
void alex_cleanText(void);

/**
Setea un timer y lo hecha a correr. timerID es el ID del timer (configuralo arriba!)
u16 tiempo de 0 a 65535 frames. (puedes usar constantes TIMER_CUARTO_SEGUNDO TIMER_MEDIO_SEGUNDO y TIMER_SEGUNDO :D)
callback, un puntero a una funcion que se llame cuando termine el timer.
*/
void alex_timerSet(int timerID, int tiempo, void (*callback)(void) );

/**
Pregunta si el timer timerID ha terminado
*/
bool alex_timerIsOver(int timerID);

/**
Detiene el timer timerID.
*/
void alex_timerStop(int timerID);

/**
Obtienes cuanto tiempo restante le queda a timerID.
*/
u16 alex_timerGetRemain(int timerID);

//privados xD
void _alex_actualizarTimers(void);

//=====================================================================

/**
Carga una melodia.
El parametro es MOD_NOMBRE_MELODIA
Volumen va de 0-255
*/
void alex_melodyLoad(u16 melodia, u8 volumen);

/**
Reproduce una melodia ya cargada
*/
void alex_melodyPlay(void);

/**
Para la melodia
*/
void alex_melodyStop(void);

/**
Hace un fade de la melodia.
*/
void alex_melodyFade();

/**
Cambia el volumen (0-255)
*/
void alex_melodyVol(u8 volumen);

//privados ;)
void _alex_actualizarFadeMelodia(void);

//=====================================================================

/**
Carga un sonido
sonido direccion memoria sonido
fin_sonido direccion memoria fin sonido
vol 0-15
pan 0-15 (default 8)
*/
void alex_cargarSonido(
			u8 *sonido, 
			u16 fin_sonido, 
			u8 vol, 
			u8 balance,
			brrsamples *destinoMemoria
			);

/**
Pues... reproduce el sonido xD!
*/
void alex_soundPlay(void);

//=====================================================================
/**
Ve si un boton de cierto control esta presionado. Retorna 1 o 0.
control es ID control (0 default) y boton usa estas constantes
KEY_A      for pad A button.
KEY_B      for pad B button.
KEY_X      for pad X button.
KEY_Y      for pad Y button.
KEY_SELECT for pad SELECT button.
KEY_START  for pad START button.
KEY_RIGHT  for pad RIGHT button.
KEY_LEFT   for pad LEFT button.
KEY_DOWN   for pad DOWN button.
KEY_UP     for pad UP button.
KEY_R      for Right shoulder button.
KEY_L      for Left shoulder button.
*/
int alex_buttonIsPressed(int control, u16 boton);
//=====================================================================
/**
Ve si hay una tecla cualquiera presionada.
control es ID control (0 default)
*/
bool alex_anyButtonPressed(int control);

/**
Hace fadein
*/
void alex_screenFadeIn(void);

/**
Hace fadeout
*/
void alex_screenFadeOut(void);

void alex_cargarSprites(u8 *dir, u8 *dirEnd, u8 *paleta, u8 *paletaEnd, u16 dir);

/**
Configura los sprites como de 16 o de 32 pixeles.
TAMANIO_16
TAMANIO_32

ejemplo: alex_configurarTamanioSprite(TAMANIO_16);
*/
void alex_spriteSetSize(u8 tamanio);

/**
Muestra (o actualiza) un sprite en pantalla
ID: ID sprite 0-128
offset: numero de tile a usar
x, y: coordenadas (0-255)
prioridad: 0-3
vflip, hflip: efecto espejo vertical u horizontal
*/
void alex_spriteShow(int id, int offset, short x, short y, int prioridad, int vflip, int hflip, int paleta);

/**
Saca un sprite de pantalla
*/
void alex_spriteRemove(int id);

/**
Obtiene la coordenada X actual del sprite
*/
short alex_spriteGetX(int id);

/**
Obtiene la coordenada Y actual del sprite
*/
short alex_spriteGetY(int id);

/**
Actualiza las coordenadas del sprite
*/
void alex_spriteUpdateCoordinates(int id, int x, int y);

/**
Actualiza coordenadas, el tile y el flip horizontal
*/
void alex_spriteUpdateFrameXY(int id, int offset, short x, short y, int hflip);

/**
Actualiza el numero de tile a usar en el sprite
*/
void alex_spriteUpdateTileNumber(int id, int offset);

//mover
void alex_spriteMove(int id, int x, int y, int duracion, void (*callback)(void) );

//abortar animacion
void alex_spriteStopMove(int id);

//privado!
void _alex_aplicarSprite(int id);
void _alex_actualizarMovSprites(void);

#endif // __LIBALEX_LIB__