#ifndef RQRScene_DEFINED

#include "RQRSceneDirection.h"
#include "RQRSceneNode.h"
#include "RQRConst.h"

struct RQRScene {
	char tilesMap[RQRSceneSize];
	
	struct RQRSceneNode *queenSceneNode;
	struct RQRSceneNode *enemySceneNode;
	struct RQRSceneNode *treasureChestSceneNode;
};

#define RQRScene_DEFINED 1

#endif