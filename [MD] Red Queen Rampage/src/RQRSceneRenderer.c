#include "RQRScene.h"
#include "RQRSceneRenderer.h"

void RQRSceneRendererRenderSceneWithGameData(struct RQRGameData *gameData)
{
	struct RQRScene *scene = gameData->scene;

	int x = 0;
	int y = 0;

	for (y = 0; y < RQRSceneHeight; y++)
	{
		for (x = 0; x < RQRSceneWidth; x++)
		{
			int sceneTilePosition = y * RQRSceneWidth + x;			
			
			char sceneTile[1];
			sceneTile[0] = scene->tilesMap[sceneTilePosition];

			int drawX = x + RQRAsciiRendererOffsetX;
			int drawY = y + RQRAsciiRendererOffsetY;			
			VDP_drawText(sceneTile, drawX, drawY);
		}
	}
	
	//render queen
	struct RQRSceneNode *queenSceneNode = scene->queenSceneNode;
	RQRSceneRendererRenderSceneNode(scene->queenSceneNode, "Q");
	
	//render enemy
	struct RQRSceneNode *enemySceneNode = scene->enemySceneNode;
	RQRSceneRendererRenderSceneNode(scene->enemySceneNode, "E");
		
	//treasure chest
	struct RQRSceneNode *treasureChestSceneNode = scene->treasureChestSceneNode;
	RQRSceneRendererRenderSceneNode(scene->treasureChestSceneNode, "T");
}

void RQRSceneRendererRenderSceneNode(struct RQRSceneNode *sceneNode, char *drawString)
{
	if (sceneNode->isVisible)
	{
		int tileX = sceneNode->x / RQRTileWidth;
		int tileY = sceneNode->y / RQRTileHeight;
	
		int drawX = RQRAsciiRendererOffsetX + tileX;
		int drawY = RQRAsciiRendererOffsetY + tileY;
	
		VDP_drawText(drawString, drawX, drawY);	
	}
}

void RQRSceneRendererRenderGUI(struct RQRGameData *gameData)
{
	struct RQRSceneNode *queenSceneNode = gameData->scene->queenSceneNode;

	int health = queenSceneNode->health;
	int attack = queenSceneNode->attack;

	char healthString[16];
	sprintf(healthString,"HP: %d", health);
	
	char attackString[16];
	sprintf(attackString,"Attack: %d", attack);

	VDP_drawText("Red Queen", 1, 1);
	VDP_drawText(healthString, 1, 3);
	VDP_drawText(attackString, 1, 4);
}

void RQRSceneRendererDrawTiles(struct RQRGameData *gameData)
{
	struct RQRScene *scene = gameData->scene;

	int x = 0;
	int y = 0;

	const int offsetX = 16;
	const int offsetY = 10;

	for (y = 0; y < RQRSceneHeight; y++)
	{
		for (x = 0; x < RQRSceneWidth; x++)
		{
			int sceneTilePosition = y * RQRSceneWidth + x;			
			
			char sceneTile[1];
			sceneTile[0] = scene->tilesMap[sceneTilePosition];

			int drawX = offsetX + x;
			int drawY = offsetY + y;			
			
			int tileIndex = 0;
			
			if (sceneTile[0] == '0')
			{
				tileIndex = 1;
			}
			VDP_setTileMapXY(APLAN, tileIndex, drawX, drawY);
		}
	}
}

void RQRSceneRendererRenderCleanTileRectAround(struct RQRSceneNode *sceneNode)
{

	const int offsetX = 16;
	const int offsetY = 10;

	int drawX = sceneNode->x / RQRTileWidth;
	int drawY = sceneNode->y / RQRTileHeight;
	
	int counterX = 0;
	int counterY = 0;
	
	for (counterX = 0; counterX < 3; counterX++)
	{
		for (counterY = 0; counterY < 3; counterY++)
		{
			int cleanX = drawX + counterX - 1;
			int cleanY = drawY + counterY - 1;
		
			if (cleanX > 0 && cleanY > 0 && cleanX < RQRSceneWidth -1 && cleanY < RQRSceneHeight - 1)
			{	
				cleanX = offsetX + cleanX;
				cleanY = offsetY + cleanY;
				
				VDP_setTileMapXY(APLAN, 0, cleanX, cleanY);			
			}
		}
	}
	

}

void RQRSceneRendererRenderSceneNodeGraphics(struct RQRSceneNode *sceneNode, int tileIndex)
{
	if (sceneNode->isVisible)
	{
	const int offsetX = 16;
	const int offsetY = 10;

	int drawX = sceneNode->x / RQRTileWidth;
	int drawY = sceneNode->y / RQRTileHeight;
	
	drawX = drawX + offsetX;
	drawY = drawY + offsetY;
	
	VDP_setTileMapXY(APLAN, TILE_ATTR_FULL(PAL1, 0, 0, 0, tileIndex), drawX, drawY);
	}
}


void RQRSceneRendererRenderSceneObjects(struct RQRGameData *gameData)
{
	RQRSceneRendererRenderCleanTileRectAround(gameData->scene->queenSceneNode);
	RQRSceneRendererRenderSceneNodeGraphics(gameData->scene->queenSceneNode, 2);
	RQRSceneRendererRenderSceneNodeGraphics(gameData->scene->enemySceneNode, 3);
	RQRSceneRendererRenderSceneNodeGraphics(gameData->scene->treasureChestSceneNode, 4);
}