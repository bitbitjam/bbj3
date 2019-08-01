#include "RQRConst.h"
#include "RQRSceneGenerator.h"
#include "RQRGameController.h"

void RQRGameControllerSwitchGameStateTo(struct RQRGameData *gameData, RQRGameState gameState)
{
	gameData->gameState = gameState;
};

void RQRGameControllerHandleStateChangeIfNeeded(struct RQRGameData *gameData)
{
	RQRGameState gameState = gameData->gameState;
	
	switch (gameState)
	{
		case RQRGameStateNeedToSwitchScene:
		{
			RQRSceneGeneratorGenerateSceneWithGameData(gameData);	
			RQRGameControllerSwitchGameStateTo(gameData, RQRGameStateIngame);
#if RQR_GRAPHICS_MODE
			RQRSceneRendererDrawTiles(gameData);
#endif
		} break;
		
		default: break;
	}
};