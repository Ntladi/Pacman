#include "GameEngine.h"
using namespace std;

int main()
{
	auto engine = GameEngine{Coordinates(23,25),Coordinates(920,750)};
	engine.runGame();
}
