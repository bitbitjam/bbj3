#include <genesis.h>
#include "RQRInputController.h"
#include "RQRGameData.h"
#include "RQRSceneNode.h"

extern struct RQRGameData *gameDataGlobal;

void RQRInputControllerInitialize()
{
	JOY_init();
	JOY_setEventHandler( &RQRInputControllerJoypadHandler );
}

void RQRInputControllerJoypadHandler( u16 joy, u16 released, u16 pressed)
{
	struct RQRSceneNode *queenSceneNode = gameDataGlobal->scene->queenSceneNode;
	
	if (joy == JOY_1)
	{
		//right
		if (pressed & BUTTON_RIGHT)
		{
			queenSceneNode->xSpeed = 1;
		}
		else if (released & BUTTON_RIGHT)
		{
			queenSceneNode->xSpeed = 0;
		}
		
		//left
		if (pressed & BUTTON_LEFT)
		{
			queenSceneNode->xSpeed = -1;
		}
		else if (released & BUTTON_LEFT)
		{
			queenSceneNode->xSpeed = 0;
		}
		
		//up
		if (pressed & BUTTON_UP)
		{
			queenSceneNode->ySpeed = -1;
		}
		else if (released & BUTTON_UP)
		{
			queenSceneNode->ySpeed = 0;
		}		
		
		//down
		if (pressed & BUTTON_DOWN)
		{
			queenSceneNode->ySpeed = 1;
		}
		else if (released & BUTTON_DOWN)
		{
			queenSceneNode->ySpeed = 0;
		}
	}   
}