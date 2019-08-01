#include "RQRSceneNodes.h"
#include "RQRRandom.h"
#include "RQRConst.h"
#include <genesis.h>
#include <maths.h>

void RQRSceneNodeQueenAllocateInitialize(struct RQRSceneNode *queenSceneNode)
{
	queenSceneNode->x = RQRSceneRandomInsideX();
	queenSceneNode->y = RQRSceneRandomInsideY();
	queenSceneNode->xSpeed = 0;
	queenSceneNode->ySpeed = 0;	
	queenSceneNode->attack = 1;
	queenSceneNode->health = 99;
	
	queenSceneNode->isVisible = YES;
}

void RQRSceneNodeEnemyAllocateInitialize(struct RQRSceneNode *enemySceneNode)
{
	enemySceneNode->x = RQRSceneRandomInsideX();
	enemySceneNode->y = RQRSceneRandomInsideY();
	enemySceneNode->xSpeed = 0;
	enemySceneNode->ySpeed = 0;
	enemySceneNode->attack = 1;
	enemySceneNode->health = 1;	
	enemySceneNode->isVisible = YES;
}

void RQRSceneNodeTreasureChestAllocateInitialize(struct RQRSceneNode *treasureChestSceneNode)
{
	treasureChestSceneNode->x = RQRSceneRandomInsideX();
	treasureChestSceneNode->y = RQRSceneRandomInsideY();
	treasureChestSceneNode->xSpeed = 0;
	treasureChestSceneNode->ySpeed = 0;	
	treasureChestSceneNode->attack = 0;	
	treasureChestSceneNode->health = 1;
	treasureChestSceneNode->isVisible = YES;
}

int RQRSceneRandomInsideX()
{
	return RQRTileWidth + (randomIntFromZeroTo((RQRSceneWidth - 3 )) * RQRTileWidth);
}

int RQRSceneRandomInsideY()
{
	return RQRTileHeight + (randomIntFromZeroTo((RQRSceneHeight - 3 )) * RQRTileHeight);
}