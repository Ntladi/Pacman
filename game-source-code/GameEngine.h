#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_
#include "Presentation.h"

class GameEngine
{
public:
	GameEngine(const int &width, const int &height);
	void runGame();
private:
	Presentation presentation_;
};

#endif
