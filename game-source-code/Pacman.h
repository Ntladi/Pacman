#ifndef PACMAN_H_
#define PACMAN_H_
#include "Grid.h"
#include "Entity.h"

class Pacman: Entity
{
public:
	Pacman(Grid & grid);

private:
	Grid grid_;
};

#endif
