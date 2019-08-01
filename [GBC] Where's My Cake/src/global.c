
unsigned char canscroll,enemies_left,num_levels,game_over;
unsigned char tick;
unsigned int foo,bar;
unsigned char timeleft;
unsigned int score,highscore;

unsigned char i,j;
unsigned char h,k;
unsigned char x,y;
unsigned int joy,lastjoy;

#define TILESET_BANK	2
#define TILESET_TILE	0x30

unsigned char level;
unsigned char *map,*attrmap;
unsigned char mapw,maph;

unsigned char scrx,scry;
unsigned char scr_loop;
#define LOOP_HORZ	1
#define LOOP_VERT	2
#define LOOP_BOTH	3

#define PPAL	0
#define PSPR	6
#define PTILE	0

unsigned char px,py;
char pvy;
unsigned char pspd,pcanjump,phflip;
#define pjumpv	2
#define pvy_max	3
unsigned char ptile_u,ptile_d,ptile_f,ptile_f2;
unsigned char panim,pframe,panim_t;
unsigned char pstate;
#define PANIM_STAND	0

extern void pmovesprite();
extern void ptile_up();
extern void ptile_down();
extern void ptile_left();
extern void ptile_right();
extern void p_upd();
#define FLAME_DELAY	5
extern void pkill();

#define PS_ACTIVE	1
#define PS_KILL		254


unsigned char grav_t;
#define grav_delay	9


#define SHOT_TILE	0xf0
#define SHOT_SPR	0
#define SHOT_PAL	1
#define MAX_SHOT	3
unsigned char shx[MAX_SHOT],shy[MAX_SHOT],sht[MAX_SHOT];
char shvx[MAX_SHOT];
unsigned char num_shot,shot_length,shot_spd;




extern void upd_scroll();
#define SCR_X1	60
#define SCR_X2	100
#define SCR_Y	88
#define YFAST	16
#define YFASTER	32

unsigned char can_exit;
unsigned char level_cleared;



#define ESPR	8
#define MAX_EN	16
unsigned char e;//idx
unsigned char etile_d,etile_u,etile_f,etile_f2;
unsigned char egrav_t;
unsigned char ex[MAX_EN],ey[MAX_EN],etype[MAX_EN],estate[MAX_EN],ehflip[MAX_EN],ecanjump[MAX_EN];
unsigned char et[MAX_EN];
char evy[MAX_EN];
unsigned char eanim_t[MAX_EN];

#define ET_A	0	//single-platform pacing; fast (1ai/f)
#define ET_A2	1	//slow 1ai/2f
#define ET_A3	2	//slower 1ai/3f
#define ET_A4	3	//slower 1ai/4f
#define ET_B	4	//like A, speed up when player is on the same level
#define ET_B2	5	//also turns to chase enemy
#define ET_A2F	6	//A2,but FLOWER
#define ET_BUTT1	7	//FAST horizontal butterfly
#define ET_BUTT2	8	//MED
#define ET_BUTT3	9	//SLOW
#define ET_BUTTV1	0xA	//vert butterfly, fast
#define ET_BUTTV2	0xB	//med
#define ET_BUTTV3	0xC	//slow

#define ET_FALL		0xF	//fast bear, falls off platforms
#define ET_FALLF		0xE	//fast FLOWER, falls off platforms


#define ES_NULL	0
#define ES_ACTIVE	1
#define ES_DIE	254

#define BEAR	0x20
#define BUTT	0x30
#define FLWR	0x40
#define FLAME	0x50

#define BEARPAL	3
#define BUTTPAL	4
#define BUTTPAL2	6
#define FLWRPAL	5
#define FLWRPAL2	7
#define FLAMEPAL	2



const unsigned char etile[]={
//	0		1		2		3		4		5		6		7		8		9
	BEAR,	BEAR,	BEAR,	BEAR,	FLWR,	FLWR,	FLWR,	BUTT,	BUTT,	BUTT,
	BUTT,	BUTT,	BUTT,	BUTT,	BUTT,	BEAR,	
};
const unsigned char edelay[]={
//	0		1		2		3		4		5		6		7		8		9
	4,		2,		3,		4,		2,		2,		2,		1,		2,		3,
	2,		3,		4,		1,		1,		1
};
const unsigned char epal[]={
//	0			1			2			3			4			5			6			7			8			9
	BEARPAL,	BEARPAL,	BEARPAL,	BEARPAL,	FLWRPAL2,	FLWRPAL,	FLWRPAL2,	BUTTPAL,	BUTTPAL2,	BUTTPAL2,
	BUTTPAL2,	BUTTPAL,	BUTTPAL,	BUTTPAL,	FLWRPAL,	BEARPAL
};

#define ENEMY_SPAWN_TILE	0x60

extern void emovesprite();
extern void etile_down();
extern void eai();
extern void spawn_enemy(unsigned char typ,unsigned char x,unsigned char y);
extern void init_enemies();
extern void e_upd();



#define PLAYER_START_TILE	0x7F

#define TT_PASS	0
#define TT_OBS	1
#define TT_PLFM	2
#define TT_HURT	3
#define TT_DOOR	126
#define TT_KEY	127
const unsigned char tiletype[]={
	TT_PASS,TT_PLFM,TT_PLFM,TT_OBS, TT_PLFM,TT_PLFM,TT_HURT,TT_PASS,
	TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,
	TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,
	TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,
	TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,
	TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,
	TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,
	TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,
	TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,
	TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,TT_PASS,
};
