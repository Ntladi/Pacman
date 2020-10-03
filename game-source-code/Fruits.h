#ifndef FRUITS_H_
#define FRUITS_H_
#include <vector>
#include "Entity.h"
#include "Grid.h"
using namespace std;
using EntityVec = std::vector<Entity>;

class Fruits
{
public:
	Fruits(const Grid & grid);
	EntityVec getFruits() const;
private:
	Grid grid_;
	const float width_;
	const float height_;
	const float xOffset_;
	const float yOffset_;
	EntityVec fruitCoords_;
	void generateFruit(const int & row, const int & col);
};
#endif
