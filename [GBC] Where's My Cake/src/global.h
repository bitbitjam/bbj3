
extern void osdd_score();

extern unsigned char canscroll,enemies_left,num_levels,game_over;
extern unsigned int score,highscore;

extern unsigned char i,j;
extern unsigned char h,k;
extern unsigned char x,y;
extern unsigned int joy,lastjoy;

#define TILESET_BANK	2
#define TILESET_TILE	0x30

extern unsigned char level;
extern unsigned char *map,*attrmap;
extern unsigned char mapw,maph;

extern unsigned char scrx,scry;
extern unsigned char scr_loop;
#define LOOP_HORZ	1
#define LOOP_VERT	2
#define LOOP_BOTH	3


#define PPAL	0
#define PSPR	6
#define PTILE	0

extern unsigned char px,py;
extern char pvy;
extern unsigned char pspd,pcanjump,phflip;
#define pjumpv	2
#define pvy_max	3
extern unsigned char ptile_u,ptile_d,ptile_f,ptile_f2;
extern unsigned char panim,pframe,panim_t;
extern unsigned char pstate;

#define PS_ACTIVE	1
#define PS_KILL		254
#define FLAME_DELAY	5
extern void pkill();


extern unsigned char grav_t;
#define grav_delay	9



#define SHOT_TILE	0xf0
#define SHOT_SPR	0
#define SHOT_PAL	1
#define MAX_SHOT	3
extern unsigned char shx[MAX_SHOT],shy[MAX_SHOT],sht[MAX_SHOT];
extern char shvx[MAX_SHOT];
extern unsigned char num_shot,shot_length,shot_spd;



extern void upd_scroll();
#define SCR_X1	60
#define SCR_X2	100
#define SCR_Y	88
#define YFAST	16
#define YFASTER	32


extern unsigned char can_exit;
extern unsigned char level_cleared;






#define ESPR	8
#define MAX_EN	16
extern unsigned char e;
extern unsigned char etile_d,etile_u,etile_f,etile_f2;
extern unsigned char ex[MAX_EN],ey[MAX_EN],etype[MAX_EN],estate[MAX_EN],ehflip[MAX_EN],ecanjump[MAX_EN];
extern unsigned char et[MAX_EN];
extern unsigned char egrav_t;
extern char evy[MAX_EN];
extern unsigned char eanim_t[MAX_EN];

#define ET_A		0
#define ET_A2		1
#define ET_A3		2
#define ET_A4		3
#define ET_B		4
#define ET_B2		5
#define ET_A2F		6
#define ET_BUTT1	7
#define ET_BUTT2	8
#define ET_BUTT3	9
#define ET_BUTTV1	0xA
#define ET_BUTTV2	0xB
#define ET_BUTTV3	0xC
#define ET_FALLF	0xE
#define ET_FALL		0xF

#define ES_NULL		0
#define ES_ACTIVE	1
#define ES_DIE		254

#define FLAMEPAL	2
#define BEARPAL		3
#define BUTTPAL		4
#define FLWRPAL		5

extern const unsigned char etile[];
extern const unsigned char edelay[];
extern const unsigned char epal[];

#define BEAR	0x20
#define BUTT	0x30
#define FLWR	0x40
#define FLAME	0x50

extern void emovesprite();
extern void etile_down();
extern void eai();
extern void spawn_enemy(unsigned char typ,unsigned char x,unsigned char y);
extern void init_enemies();
extern void e_upd();




#define PLAYER_START_TILE	0x7f

#define TT_PASS	0
#define TT_OBS	1
#define TT_PLFM	2
#define TT_HURT	3
#define TT_DOOR	126
#define TT_KEY	127
extern const unsigned char tiletype[];


extern void pmovesprite();
extern void ptile_down();
extern void ptile_left();
extern void ptile_right();
extern void p_upd();



extern void sfx_shoot();
extern void sfx_jump();
extern void sfx_land();
extern void sfx_pickup();
extern void sfx_kill();



