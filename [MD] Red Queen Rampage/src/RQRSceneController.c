#include "RQRGameState.h"
#include "RQRGameController.h"
#include "RQRSceneController.h"

void RQRSceneControllerStep(struct RQRGameData *gameData)
{
	struct RQRScene *scene = gameData->scene;
	struct RQRInputData *inputData = gameData->inputData;
	
	RQRSceneControllerMoveSceneNode(gameData, scene->queenSceneNode);
}

void RQRSceneControllerMoveSceneNode(struct RQRGameData *gameData, struct RQRSceneNode *sceneNode)
{
	int targetX = sceneNode->x + sceneNode->xSpeed;
	int targetY = sceneNode->y + sceneNode->ySpeed;
	
	if (RQRSceneControllerIsTargetCoordinateTreasureChest(gameData, targetX, targetY))
	{
		RQRSceneControllerPickupTreasureChestAtCoordinate(gameData, targetX, targetY, sceneNode);
	}	
	else if (RQRSceneControllerIsTargetCoordinateEnemy(gameData, targetX, targetY))
	{
		RQRSceneControllerFightEnemyAtCoordinate(gameData, targetX, targetY, sceneNode);
	}
	else if (RQRSceneControllerIsTargetCoordinateFree(gameData, targetX, targetY))
	{
		sceneNode->x = targetX;
		sceneNode->y = targetY;
	}
	else if (RQRSceneControllerIsTargetCoordinateExit(gameData, targetX, targetY))
	{
		RQRGameControllerSwitchGameStateTo(gameData, RQRGameStateNeedToSwitchScene);
	}
}

void RQRSceneControllerFightEnemyAtCoordinate(struct RQRGameData *gameData, int targetX, int targetY, struct RQRSceneNode *sceneNode)
{
	struct RQRSceneNode *enemySceneNode = gameData->scene->enemySceneNode;

	if (enemySceneNode->isVisible)
	{
		sceneNode->health = sceneNode->health - 1;
		sceneNode->attack = sceneNode->attack + 1;
	
		enemySceneNode->isVisible = NO;
	}
}

void RQRSceneControllerPickupTreasureChestAtCoordinate(struct RQRGameData *gameData, int targetX, int targetY, struct RQRSceneNode *sceneNode)
{
	struct RQRSceneNode *treasureChestSceneNode = gameData->scene->treasureChestSceneNode;

	if (treasureChestSceneNode->isVisible)
	{
		sceneNode->health = 99;
		sceneNode->attack = sceneNode->attack + 1;
	
		treasureChestSceneNode->isVisible = NO;
	}
}

int RQRSceneControllerIsTargetCoordinateEqualToSymbol(struct RQRGameData *gameData, int targetX, int targetY, char symbol)
{
	int tileX = targetX / RQRTileWidth;
	int tileY = targetY / RQRTileHeight;
	
	int tileIndex = tileY * RQRSceneWidth + tileX;
	
	char tile = gameData->scene->tilesMap[tileIndex];
	if (tile == symbol)
	{
		return YES;
	}
	
	return NO;
}

int RQRSceneControllerIsTargetCoordinateTreasureChest(struct RQRGameData *gameData, int targetX, int targetY)
{
	struct RQRSceneNode *treasureChestSceneNode = gameData->scene->treasureChestSceneNode;
	
	if (
		treasureChestSceneNode->x / RQRTileWidth == targetX / RQRTileWidth &&
		treasureChestSceneNode->y / RQRTileHeight == targetY / RQRTileHeight &&
		treasureChestSceneNode->isVisible
	)
	{
		return YES;
	}
	
	return NO;
}

int RQRSceneControllerIsTargetCoordinateEnemy(struct RQRGameData *gameData, int targetX, int targetY)
{
	struct RQRSceneNode *enemySceneNode = gameData->scene->enemySceneNode;
	
	if (
		enemySceneNode->x / RQRTileWidth == targetX / RQRTileWidth &&
		enemySceneNode->y / RQRTileHeight == targetY / RQRTileHeight &&
		enemySceneNode->isVisible
	)
	{
		return YES;
	}
	
	return NO;
}

int RQRSceneControllerIsTargetCoordinateExit(struct RQRGameData *gameData, int targetX, int targetY)
{
	int result = RQRSceneControllerIsTargetCoordinateEqualToSymbol(gameData, targetX, targetY, '-');
	
	return result;
}

int RQRSceneControllerIsTargetCoordinateFree(struct RQRGameData *gameData, int targetX, int targetY)
{
	int result = RQRSceneControllerIsTargetCoordinateEqualToSymbol(gameData, targetX, targetY, ' ');
	
	return result;
}