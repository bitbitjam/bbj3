#include <genesis.h>

#include <memory.h>
#include "RQRConst.h"
#include "RQRGameData.h"
#include "RQRSceneNodes.h"
#include "RQRSceneRenderer.h"
#include "RQRSceneGenerator.h"
#include "RQRGameController.h"
#include "RQRInputController.h"
#include "RQRSceneController.h"

// Red Queen Rampage - Sega Genesis Game for BitBitJam 2016
// by Demens Deum 2016 (demensdeum@gmail.com) 

struct RQRGameData *gameDataGlobal;

const uint8_t wallTile[]={
17,17,33,17,17,17,33,17,34,34,34,34,17,33,17,33,17,33,17,33,17,33,17,33,34,34,34,34,17,17,17,17
};


const uint8_t queenTile[]={
255,255,255,255,255,111,111,111,255,246,102,255,255,243,99,255,255,246,102,255,255,21,85,31,255,245,85,255,255,85,245,95
};

const uint8_t RQRGamePallete[]={
0,0,12,170,4,68,0,44,0,64,0,10,4,140,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};



const uint8_t enemyTile[]={
255,255,255,255,245,69,255,255,245,85,255,255,244,68,79,255,255,255,68,79,255,68,79,255,255,255,68,79,255,255,255,255
};


const uint8_t treasureChestTile[]={
255,255,255,255,243,51,51,63,243,17,17,63,243,51,51,63,243,85,85,63,243,85,85,63,243,85,85,63,243,51,51,63
};


int main()
{	
	//struct RQRGameData *gameData = RQRAllocateInitializeGameData();

	//works but better in oop style
	struct RQRGameData gameData;
	gameData.gameState = RQRGameStateNeedToSwitchScene;
	
	struct RQRSceneNode queenSceneNode;
	RQRSceneNodeQueenAllocateInitialize(&queenSceneNode);

	struct RQRSceneNode enemySceneNode;
	RQRSceneNodeEnemyAllocateInitialize(&enemySceneNode);
		
	struct RQRSceneNode treasureChestSceneNode;
	RQRSceneNodeTreasureChestAllocateInitialize(&treasureChestSceneNode);
		
	struct RQRScene scene;
	scene.queenSceneNode = &queenSceneNode;
	scene.enemySceneNode = &enemySceneNode;
	scene.treasureChestSceneNode = &treasureChestSceneNode;

	struct RQRInputData inputData;
	inputData.isLeftKeyPressed = NO;
	inputData.isRightKeyPressed = NO;
	inputData.isDownKeyPressed = NO;
	inputData.isUpKeyPressed = NO;
	gameData.inputData = &inputData;

	gameData.scene = &scene;
	gameData.exitDirection = RQRSceneDirectionUp;
	
	gameDataGlobal = &gameData;

	RQRInputControllerInitialize();

	//RQRSceneGeneratorGenerateSceneWithGameData(gameDataGlobal);

#if RQR_GRAPHICS_MODE
	//we load our unique tile data at position 1 on VRAM
	VDP_loadTileData( (const u32 *)wallTile, 1, 1, 0); 
	VDP_loadTileData( (const u32 *)queenTile, 2, 1, 0); 
	VDP_loadTileData( (const u32 *)enemyTile, 3, 1, 0); 
	VDP_loadTileData( (const u32 *)treasureChestTile, 4, 1, 0); 	
	VDP_setPalette(PAL1, RQRGamePallete);	
#endif

	while(1)
	{
		RQRGameControllerHandleStateChangeIfNeeded(gameDataGlobal);	
		RQRSceneControllerStep(gameDataGlobal);
#if RQR_ASCII_MODE
		BMP_waitWhileFlipRequestPending();
		BMP_showFPS(1);

		BMP_clear();

		
		RQRSceneRendererRenderSceneWithGameData(gameDataGlobal);
#endif

#if RQR_GRAPHICS_MODE
		RQRSceneRendererRenderSceneObjects(gameDataGlobal);
#endif
		RQRSceneRendererRenderGUI(gameDataGlobal);
	        VDP_waitVSync();
	}
    return (0);
}