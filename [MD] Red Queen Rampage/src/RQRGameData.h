#ifndef RQRGameData_DEFINED

#include "RQRScene.h"
#include "RQRInputData.h"
#include "RQRGameState.h"

struct RQRGameData 
{
	struct RQRScene *scene;
	struct RQRInputData *inputData;
	
	RQRSceneDirection exitDirection;
	RQRGameState gameState;
};

#define RQRGameData_DEFINED 1

#endif