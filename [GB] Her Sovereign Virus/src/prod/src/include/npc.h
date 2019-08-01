/**
 * npc.h
 * Quin Kennedy, David Frankel, Vivek Vimal, Party Skeleton, 2016
 */
#ifndef NPC_H
#define NPC_H

//the player takes up to 2 sprite slots, 
// and most NPCs (except NPC viruses) take two sprite slots
// so we can support ((40 - 2) / 2) = 18 NPCs
#define MAX_NUM_NPC 18

#include "entity.h"

EntityData npc_data[MAX_NUM_NPC];
UBYTE npc_counts[4];

void npc_init();
void npc_update();
void npc_draw();

void placeSprite(UBYTE index, EntityData *entity);
void tileSprite(UBYTE index, const unsigned char tile, EntityType type);
void npc_playerChangedLayer();

#endif
