#include "RQRRandom.h"
#include "RQRSceneDirection.h"
#include "RQRSceneGenerator.h"

void RQRSceneGeneratorSetSceneExitOnTop(struct RQRGameData *gameData)
{
	struct RQRScene *scene = gameData->scene;
	
	scene->tilesMap[3] = '-';
	scene->tilesMap[4] = '-';
}

void RQRSceneGeneratorSetSceneExitOnBottom(struct RQRGameData *gameData)
{
	struct RQRScene *scene = gameData->scene;
	
	int firstTile = (RQRSceneWidth * RQRSceneHeight) - 4;
	int secondTile = (RQRSceneWidth * RQRSceneHeight) - 5;
	
	scene->tilesMap[firstTile] = '-';
	scene->tilesMap[secondTile] = '-';
}

void RQRSceneGeneratorSetSceneExitOnLeft(struct RQRGameData *gameData)
{
	struct RQRScene *scene = gameData->scene;
	
	int firstTile = RQRSceneWidth * 4;
	int secondTile = RQRSceneWidth * 5;
	
	scene->tilesMap[firstTile] = '-';
	scene->tilesMap[secondTile] = '-';
}

void RQRSceneGeneratorSetSceneExitOnRight(struct RQRGameData *gameData)
{
	struct RQRScene *scene = gameData->scene;
	
	int firstTile = (RQRSceneWidth * 5) - 1;
	int secondTile = (RQRSceneWidth * 6) - 1;
	
	scene->tilesMap[firstTile] = '-';
	scene->tilesMap[secondTile] = '-';
}

void RQRSceneGeneratorAddExitToScene(struct RQRGameData *gameData)
{
	RQRSceneDirection exitDirection = randomIntFromZeroTo(RQRSceneDirectionDirectionCount - 1);
	
	//set exit on top for now
	switch (exitDirection)
	{
		case RQRSceneDirectionUp:
		{
			RQRSceneGeneratorSetSceneExitOnTop(gameData);
		} break;
		
		case RQRSceneDirectionDown:
		{
			RQRSceneGeneratorSetSceneExitOnBottom(gameData);
		} break;
		
		case RQRSceneDirectionLeft:
		{
			RQRSceneGeneratorSetSceneExitOnLeft(gameData);
		} break;
		
		case RQRSceneDirectionRight:
		{
			RQRSceneGeneratorSetSceneExitOnRight(gameData);
		} break;
		
		default: break;
	}
	
	gameData->exitDirection = exitDirection;
}

void RQRSceneGeneratorGenerateSceneWithGameData(struct RQRGameData *gameData)
{
	struct RQRScene *scene = gameData->scene;

	int x = 0;
	int y = 0;

	for (y = 0; y < RQRSceneHeight; y++)
	{
		for (x = 0; x < RQRSceneWidth; x++)
		{
			int sceneTilePosition = y * RQRSceneWidth + x;
			
			char outputTile = '0';			
			
			if (y > 0 && y < RQRSceneHeight - 1 && x > 0 && x < RQRSceneWidth - 1)
			{
				outputTile = ' ';
			}
			
			scene->tilesMap[sceneTilePosition] = outputTile;
		}
	}
	
	struct RQRSceneNode *queenSceneNode = scene->queenSceneNode;
	struct RQRSceneNode *enemySceneNode = scene->enemySceneNode;
	struct RQRSceneNode *treasureChestSceneNode = scene->treasureChestSceneNode;
	
	//RQRSceneNodeQueenAllocateInitialize(queenSceneNode);
	
	RQRSceneNodeEnemyAllocateInitialize(enemySceneNode);
	RQRSceneNodeTreasureChestAllocateInitialize(treasureChestSceneNode);			
	
	RQRSceneGeneratorAddExitToScene(gameData);	
}