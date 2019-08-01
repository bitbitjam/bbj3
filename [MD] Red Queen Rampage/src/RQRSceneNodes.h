#ifndef RQRSceneNodes

#include "RQRSceneNode.h"

void RQRSceneNodeQueenAllocateInitialize(struct RQRSceneNode *queenSceneNode);
void RQRSceneNodeEnemyAllocateInitialize(struct RQRSceneNode *enemySceneNode);
void RQRSceneNodeTreasureChestAllocateInitialize(struct RQRSceneNode *treasureChestSceneNode);

int RQRSceneRandomInsideX();
int RQRSceneRandomInsideY();

#define RQRSceneNodes 1

#endif