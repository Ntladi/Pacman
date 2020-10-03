#include "Fruits.h"

Fruits::Fruits(const Grid &grid) : grid_(grid),
		width_(grid_.getBlockDimentions().getX()),
		height_(grid_.getBlockDimentions().getY()), xOffset_(0), yOffset_(0)
{
	for(auto row = 0; row < grid.getMatrix().size(); row++)
	{
		for(auto col = 0; col < grid.getMatrix().at(row).size(); col++)
		{
			if(grid.getMatrix().at(row).at(col) == 7)
			{
				auto coords = grid.convertToScreenPos(row, col);
				fruitCoords_.push_back(Entity(coords, Coordinates(width_,height_)));
			}
		}
	}
}

EntityVec Fruits::getFruits() const
{
	return fruitCoords_;
}
