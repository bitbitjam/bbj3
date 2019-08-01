#include <genesis.h>
#include "gfx.h"
#include "sprite.h"
#include "sound.h"

#define STATE_IDLE                0

#define STATE_READY               1
#define STATE_PERFORM_BLOCK       2

#define STATE_PERFORM_PUNCH       4
#define STATE_PERFORM_SUPER       5


#define STATE_PERFORM_HURT        8
#define STATE_DEAD                9

#define P_HEALTH_MAX  5
#define P_STAMINA_MAX  512

#define P_X_SPEED   .004
#define P_BOB_SPEED .002
#define P_BOB_FRAMES 40

#define P_TIME_TELEGRAPH          5
#define P_TIME_PUNCH              5
#define P_TIME_SUPER              5
#define P_TIME_COOLDOWN           5

#define E_HEALTH_MAX  10
#define E_STAMINA_MAX  512

#define E_X_SPEED   .004
#define E_BOB_SPEED .0015
#define E_BOB_FRAMES 30

#define E_TIME_TELEGRAPH          5
#define E_TIME_PUNCH              5
#define E_TIME_SUPER              5
#define E_TIME_COOLDOWN           5

#define SFX_DIE                   64
#define SFX_HIT                   65
#define SFX_BLOCK                 66
#define SFX_TELEGRAPH             67

int frameCount = 0;

//player
Sprite* p_princess;
int p_state = STATE_IDLE;
int p_anim = 0;
int p_cooldown = 0;
int p_bob = 0;

int p_flip = 0;

int p_health = P_HEALTH_MAX;
int p_stamina = 512;
int p_stamina_regen = 2;

fix32 p_x = 80;
fix32 p_y = 120;

//enemy
Sprite* e_princess;
int e_state = STATE_IDLE;
int e_anim = 0;
int e_cooldown = 0;
int e_bob = 0;

int e_flip = 0;
u16 e_rng;

int e_health = E_HEALTH_MAX;
int e_stamina = 512;
int e_stamina_regen = 2;

fix32 e_x = 160;
fix32 e_y = 90;

//camera
fix32 cam_x;
fix32 cam_y;


int c_x_dir = 0;
int c_y_dir = 0;
int c_a = 0;
int c_b = 0;
int c_c = 0;

void joyHandler (u16 joy, u16 changed, u16 state)
{
  if (joy == JOY_1)
  {
    if (state & BUTTON_LEFT)
      c_x_dir = -1;
    else if (changed & BUTTON_LEFT && c_x_dir == -1)
      c_x_dir = 0;

    if (state & BUTTON_RIGHT)
      c_x_dir = 1;
    else if (changed & BUTTON_RIGHT && c_x_dir == 1)
      c_x_dir = 0;

    if (state & BUTTON_UP)
      c_y_dir = -1;
    else if (changed & BUTTON_UP && c_y_dir == -1)
      c_y_dir = 0;

    if (state & BUTTON_DOWN)
      c_y_dir = 1;
    else if (changed & BUTTON_DOWN && c_y_dir == 1)
      c_y_dir = 0;

    if (state & BUTTON_A)
      c_a = 1;
    else if (changed & BUTTON_A)
      c_a = 0;

    if (state & BUTTON_B)
      c_b = 1;
    else if (changed & BUTTON_B)
      c_b = 0;

    if (state & BUTTON_C)
      c_c = 1;
    else if (changed & BUTTON_C)
      c_c = 0;

  }

}

void setUpRingBg ()
{
  u16 index = 0;
  index = TILE_USERINDEX;
  VDP_drawImageEx(PLAN_A, &ring_image, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, index), 0, 0, FALSE, TRUE);
  index += ring_image.tileset->numTile;
  VDP_setPalette(PAL0, ring_image.palette->data);
}

void setUpSprites ()
{
  SPR_init(16, 256, 256);

  p_princess = SPR_addSprite(&p_back_sprite, 80, 120, TILE_ATTR(PAL2, TRUE, FALSE, FALSE));
  SPR_setAnim(p_princess, 0);
  p_state = STATE_READY;

  e_princess = SPR_addSprite(&p_front_sprite, 160, 90, TILE_ATTR(PAL1, TRUE, FALSE, FALSE));
  SPR_setAnim(e_princess, 0);
  e_state = STATE_READY;

  VDP_setPalette(PAL1, p_front_sprite.palette->data);
  VDP_setPalette(PAL2, p_back_sprite.palette->data);
}

void cameraUpdate ()
{
  if (p_x - cam_x > 200)
    cam_x += (p_x - cam_x) - 200;

  if (p_x - cam_x < 50)
    cam_x += (p_x - cam_x) - 50;

  if (p_x < 0)
    p_x = 0;

  if (p_x > 380)
    p_x = 380;

  if (e_x < 30)
    e_x = 30;

  if (e_x > 360)
    e_x = 360;

  if (cam_x < 0)
    cam_x = 0;

  if (cam_x > 160)
    cam_x = 160;

    VDP_setHorizontalScroll(PLAN_A, fix32ToInt(-cam_x  * 1000));
}

void playerPrincessSwitchState (int newState, int cooldown)
{
  if (p_cooldown > 0)
    return;

  p_cooldown = cooldown;
  p_state = newState;
}

void playerPrincessIdle ()
{


}
void playerPrincessReady ()
{
  fix32 bob_mod = 2;

  p_cooldown--;

  p_anim = 0;
  p_bob++;
  if (p_bob > 1024)
    p_bob = 0;

  if (c_x_dir == -1)
  {
    p_x -= FIX32 (P_X_SPEED);
    bob_mod = 1;
  }
  if (c_x_dir == +1)
  {
    p_x += FIX32 (P_X_SPEED);
    bob_mod = 1;
  }
  if (c_y_dir == +1)
    playerPrincessSwitchState (STATE_PERFORM_BLOCK, 30);

    //bob
    p_y += cosFix32 (frameCount * P_BOB_FRAMES / bob_mod) * P_BOB_SPEED;

    if (p_y < 130)
      p_y = 130;
    if (p_y > 150)
      p_y -= 3;

    if (c_a)
    {
      SPR_setHFlip (p_princess ,FALSE);
      //p_anim = 2;
      p_flip = 0;
      playerPrincessSwitchState (STATE_PERFORM_PUNCH, 30);
    }
    else if (c_b)
    {
      SPR_setHFlip (p_princess ,TRUE);
      //p_anim = 1;
      p_flip = 1;
      playerPrincessSwitchState (STATE_PERFORM_PUNCH, 30);
    }
    /*
    else if (c_c)
    {
      //playerPrincessSwitchState (STATE_PERFORM_HURT, 12);
    }
    */
    else
    {
      p_anim = 0;
    }
}
void playerPrincessDead ()
{
  VDP_setVerticalScroll (PLAN_A,  (e_cooldown % 5) - 2);

  p_cooldown--;
  p_anim = 3;
  p_x += cosFix32 (frameCount * P_BOB_FRAMES * 2) * P_BOB_SPEED;
  p_y += 1;
}

void playerPrincessPunch ()
{
  p_cooldown--;

  if (p_cooldown < 10 && p_cooldown > 8)
  {

    if (p_flip == 0 && e_x - p_x < 20 && e_x - p_x > -48 ||
        p_flip == 1 && e_x - p_x < 48 && e_x - p_x > -20)
    {
      if (e_state == STATE_PERFORM_PUNCH && e_cooldown > 30)
      {
          SND_startPlayPCM_XGM(SFX_BLOCK, 1, SOUND_PCM_CH2);
      }
      else if (e_state == STATE_PERFORM_BLOCK)
      {
        SND_startPlayPCM_XGM(SFX_BLOCK, 1, SOUND_PCM_CH2);
        VDP_setVerticalScroll (PLAN_A,  3);
        VDP_waitVSync();
        VDP_setVerticalScroll (PLAN_A,  0);
      }
      else if (e_state == STATE_DEAD)
      {
        SND_startPlayPCM_XGM(SFX_DIE, 1, SOUND_PCM_CH2);
      }
      else
      {
        e_cooldown = 15;
        e_state = STATE_PERFORM_HURT;

        e_health -= 1;

        if (e_health <= 0)
          SND_startPlayPCM_XGM(SFX_DIE, 1, SOUND_PCM_CH2);
        else
          SND_startPlayPCM_XGM(SFX_HIT, 1, SOUND_PCM_CH2);
      }

    }
  }

  if (p_cooldown > 20)
  {
    p_anim = 1;
    p_y += 3;
  }
  else if (p_cooldown > 10)
  {
    p_anim = 2;
    p_y -= 3;
  }
  else if (p_cooldown <= 0)
    playerPrincessSwitchState (STATE_READY, 0);
}
void playerPrincessBlock ()
{
  p_cooldown--;

  p_anim = 1;

  if (p_cooldown > 0)
    return;

  if (c_y_dir != +1)
    playerPrincessSwitchState (STATE_READY, 0);
}
void playerPrincessHit ()
{
  p_cooldown--;

  p_anim = 3;

  VDP_setVerticalScroll (PLAN_A,  (p_cooldown % 5) - 2);

  if (p_x > e_x)
    p_x += 0.8 * p_cooldown;
  else
    p_x -= 0.8 * p_cooldown;

  if (p_cooldown < 5)
      p_y += 1 * p_cooldown;
  else
    p_y -= 0.5 * p_cooldown;

  if (p_cooldown <= 0)
    playerPrincessSwitchState (STATE_READY, 5);
}


void playerPrincessBehavior ()
{
  if (p_health <= 0)
    p_state = STATE_DEAD;

  if (p_state == STATE_IDLE)
    playerPrincessIdle ();
  if (p_state == STATE_READY)
    playerPrincessReady ();
  if (p_state == STATE_DEAD)
    playerPrincessDead ();

  if (p_state == STATE_PERFORM_BLOCK)
    playerPrincessBlock ();
  if (p_state == STATE_PERFORM_PUNCH)
    playerPrincessPunch ();
  if (p_state == STATE_PERFORM_HURT)
    playerPrincessHit ();
  if (p_state == STATE_PERFORM_SUPER)
    playerPrincessPunch ();

  //update spriteData
  SPR_setAnim(p_princess, p_anim);
  SPR_setPosition(p_princess, p_x - cam_x, p_y - cam_y);
}


//ENEMY
void enemyPrincessSwitchState (int newState, int cooldown)
{
  if (e_cooldown > 0)
    return;

  e_cooldown = cooldown;
  e_state = newState;
}

void enemyPrincessIdle ()
{


}
void enemyPrincessReady ()
{
  fix32 bob_mod = 2;

  e_cooldown--;

  e_anim = 0;
  e_bob++;
  if (e_bob > 1024)
    e_bob = 0;



//random 0 to4096]
//bob
e_y += cosFix32 (frameCount * E_BOB_FRAMES / bob_mod) * E_BOB_SPEED;

if (e_y < 90)
  e_y = 90;
if (e_y > 120)
  e_y -= 3;

  if (e_rng < 10024)
  {
    e_x -= FIX32 (E_X_SPEED);
    p_flip = 0;
    bob_mod = 1;
  }
  else if (e_rng < 20048)
  {
    e_x += FIX32 (E_X_SPEED);
    p_flip = 1;
    bob_mod = 1;
  }
  else if (e_rng < 30000)
  {
    enemyPrincessSwitchState (STATE_PERFORM_BLOCK, 5);
  }


  else if (e_rng < 35000)
    {
      SPR_setHFlip (e_princess ,FALSE);
      //p_anim = 2;
      SND_startPlayPCM_XGM(SFX_TELEGRAPH, 1, SOUND_PCM_CH2);
      enemyPrincessSwitchState (STATE_PERFORM_PUNCH, 90);
    }
    else if (e_rng < 40000)
    {
      SPR_setHFlip (e_princess ,TRUE);
      //p_anim = 1;
      SND_startPlayPCM_XGM(SFX_TELEGRAPH, 1, SOUND_PCM_CH2);
      enemyPrincessSwitchState (STATE_PERFORM_PUNCH, 90);
    }
    else
    {
      e_anim = 0;
    }
}
void enemyPrincessDead ()
{
  VDP_setVerticalScroll (PLAN_A,  (e_cooldown % 5) - 2);

  e_cooldown--;
  e_anim = 1;
  e_x += cosFix32 (frameCount * E_BOB_FRAMES * 2) * E_BOB_SPEED;
  e_y += 1;
}
void enemyPrincessPunch ()
{
  e_cooldown--;

  if (e_cooldown < 30 && e_cooldown > 28)
  {

    if (e_flip == 0 && e_x - p_x < 30 && e_x - p_x > -58 ||
        p_flip == 1 && e_x - p_x < 58 && e_x - p_x > -30)
    {
      if (p_state == STATE_PERFORM_BLOCK)
      {
        SND_startPlayPCM_XGM(SFX_BLOCK, 1, SOUND_PCM_CH2);
        VDP_setVerticalScroll (PLAN_A,  3);
        VDP_waitVSync();
        VDP_setVerticalScroll (PLAN_A,  0);
        p_cooldown = 6;
      }
      else if (p_state == STATE_DEAD)
      {
        SND_startPlayPCM_XGM(SFX_DIE, 1, SOUND_PCM_CH2);
      }
      else
      {
        p_cooldown = 15;
        p_state = STATE_PERFORM_HURT;

        p_health -= 1;

        if (p_health <= 0)
          SND_startPlayPCM_XGM(SFX_DIE, 1, SOUND_PCM_CH2);
        else
          SND_startPlayPCM_XGM(SFX_HIT, 1, SOUND_PCM_CH2);
      }

    }
  }

  if (e_cooldown < 45 && e_cooldown > 30)
  {
    e_y -= 3;
  }
  else if (e_cooldown < 60 && e_cooldown > 45)
  {

    e_y += 3;
  }

  if (e_cooldown > 30)
  {
    e_anim = 2;
  }
  else if (e_cooldown > 0)
  {
    e_anim = 3;
  }
  else if (e_cooldown <= 0)
    enemyPrincessSwitchState (STATE_READY, 0);
}
void enemyPrincessBlock ()
{
  e_cooldown--;


  e_anim = 6;
  if (c_y_dir != +1)
    enemyPrincessSwitchState (STATE_READY, 0);
}
void enemyPrincessHit ()
{
  e_cooldown--;

  VDP_setVerticalScroll (PLAN_A,  (e_cooldown % 5) - 2);

  e_anim = 1;
  if (e_x > p_x)
    e_x += 0.8 * e_cooldown;
  else
    e_x -= 0.8 * e_cooldown;

  if (e_cooldown < 5)
      e_y += 1 * e_cooldown;
  else
    e_y -= 0.5 * e_cooldown;

  if (e_cooldown <= 0)
    enemyPrincessSwitchState (STATE_READY, 5);
}

void enemyPrincessBehavior ()
{
  e_y += cosFix32 (frameCount * E_BOB_FRAMES) * E_BOB_SPEED;

  if (e_y < 90)
    e_y = 90;

  if (e_health <= 0)
    e_state = STATE_DEAD;

  if (e_state == STATE_IDLE)
    enemyPrincessIdle ();
  if (e_state == STATE_READY)
    enemyPrincessReady ();
  if (e_state == STATE_DEAD)
    enemyPrincessDead ();

  if (e_state == STATE_PERFORM_BLOCK)
    enemyPrincessBlock ();
  if (e_state == STATE_PERFORM_PUNCH)
    enemyPrincessPunch ();
  if (e_state == STATE_PERFORM_HURT)
    enemyPrincessHit ();
  if (e_state == STATE_PERFORM_SUPER)
    enemyPrincessPunch ();


  SPR_setAnim(e_princess, e_anim);
  SPR_setPosition(e_princess, e_x- cam_x, e_y- cam_y);
}

void drawWinScreen ()
{
  int i = 0;
  u16 index = 0;

  VDP_setHorizontalScroll(PLAN_A, 0);

  SPR_setPosition(p_princess,-100, 500);
  SPR_setPosition(e_princess, -100, 500);

  SPR_update ();
  VDP_waitVSync();

  SND_startPlay_XGM (gameover_music);

  VDP_clearPlan (PLAN_A, FALSE);

  DMA_waitCompletion();
  index = TILE_USERINDEX;
  VDP_drawImageEx(PLAN_A, &you_win_image, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, index), 0, 4, FALSE, TRUE);
  index += you_win_image.tileset->numTile;
  DMA_waitCompletion();
  for (i = 0; i < 400; i++)
  {

    VDP_waitVSync();
  }
}

void drawLoseScreen ()
{
  int i = 0;
  u16 index = 0;

  VDP_setHorizontalScroll(PLAN_A, 0);

  SPR_setPosition(p_princess,-100, 500);
  SPR_setPosition(e_princess, -100, 500);

  SPR_update ();
VDP_waitVSync();
  SND_startPlay_XGM (gameover_music);

  VDP_clearPlan (PLAN_A, FALSE);


  index = TILE_USERINDEX;
  VDP_drawImageEx(PLAN_A, &game_over_image, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, index), 0, 4, FALSE, TRUE);
  index += game_over_image.tileset->numTile;
  DMA_waitCompletion();
  for (i = 0; i < 400; i++)
  {

    VDP_waitVSync();
  }
}

void setUpTitleScreen ()
{
  int game_state = 0;
  int i = 0;
  u16 index = 0;

  VDP_setPalette(PAL0, ring_image.palette->data);

  while (game_state == 0)
  {
    DMA_waitCompletion();
    index = TILE_USERINDEX;
    VDP_drawImageEx(PLAN_A, &title_image_02, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, index), 0, 4, FALSE, TRUE);
    index += title_image_02.tileset->numTile;
    DMA_waitCompletion();
    for (i = 0; i < 20; i++)
    {

      VDP_waitVSync();
      if (c_a || c_b || c_c)
        game_state = 1;
    }
    if (game_state == 0)
    {
    DMA_waitCompletion();
    index = TILE_USERINDEX;
    VDP_drawImageEx(PLAN_A, &title_image_03, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, index), 0, 4, FALSE, TRUE);
    index += title_image_03.tileset->numTile;
    DMA_waitCompletion();
    for (i = 0; i < 20; i++)
    {

      VDP_waitVSync();
      if (c_a || c_b || c_c)
        game_state = 1;
    }
  }
  if (game_state == 0)
  {
    index = TILE_USERINDEX;
    DMA_waitCompletion();
    VDP_drawImageEx(PLAN_A, &title_image_01, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, index), 0, 4, FALSE, TRUE);
    index += title_image_01.tileset->numTile;
    DMA_waitCompletion();
    for (i = 0; i < 20; i++)
    {

      VDP_waitVSync();
      if (c_a || c_b || c_c)
        game_state = 1;
    }
  }
}
}

int main ()
{
  int i = 0;

  VDP_setScreenWidth320();

  JOY_init ();
  JOY_setEventHandler (&joyHandler);

  SND_setPCM_XGM(SFX_HIT, hit_sfx, sizeof(hit_sfx));
  SND_setPCM_XGM(SFX_BLOCK, block_sfx, sizeof(block_sfx));
  SND_setPCM_XGM(SFX_DIE, die_sfx, sizeof(die_sfx));
  SND_setPCM_XGM(SFX_TELEGRAPH, telegraph_sfx, sizeof(telegraph_sfx));

  setUpSprites ();

  while (1)
  {
    p_x = 190;
    e_x = 190;
    cam_x = 80;

    p_health = P_HEALTH_MAX;
    e_health = E_HEALTH_MAX;

    p_stamina = P_STAMINA_MAX;
    e_stamina = E_STAMINA_MAX;

    p_state = STATE_READY;
    e_state = STATE_READY;

    SND_startPlay_XGM (title_music);

    setUpTitleScreen ();

    setUpRingBg ();

    e_rng = random();

    SND_startPlay_XGM (game_music);

    while (p_health > 0 && e_health > 0)
    {
      playerPrincessBehavior ();
      enemyPrincessBehavior ();
      cameraUpdate ();

      SPR_update ();
      VDP_waitVSync();

      frameCount++;
      if (frameCount >= 10240000)
      {
        frameCount = 0;
      }

      if ((frameCount % 20) == 1)
        e_rng = random();
    }

    for (i = 0; i < 180; i++)
    {
      playerPrincessBehavior ();
      enemyPrincessBehavior ();

      SPR_update ();
      VDP_waitVSync();

      frameCount++;
      if (frameCount >= 10240000)
      {
        frameCount = 0;
      }
    }
    if (p_health > 0)
      drawWinScreen ();
    else
      drawLoseScreen ();
  }
}
