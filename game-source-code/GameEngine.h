#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_
#include "Presentation.h"
#include "Coordinates.h"
#include "Fruits.h"
#include "Maze.h"
#include "Pacman.h"
#include "SeparatingAxisTheorem.h"

class GameEngine
{
public:
	GameEngine(const Coordinates & gridSize, const Coordinates & screenDimentions, ifstream & mazeFile);
	void runGame();
private:
	Presentation presentation_;
	Grid grid_;
	Maze maze_;
	Fruits fruits_;
	Pacman pacman_;
	SeparatingAxisTheorem collissions_;
};

#endif
