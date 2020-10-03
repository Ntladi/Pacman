#include "Grid.h"

Grid::Grid(const Coordinates &gridSize, const Coordinates &screenDimentions, ifstream & mazeFile) :
		screen_(screenDimentions), blockWidth_(screenDimentions.getX()/gridSize.getX()),
		blockHeight_(screenDimentions.getY()/gridSize.getY())
{
	resizeMatrix(gridSize.getX(), gridSize.getY());
	readMaze(mazeFile);
}

void Grid::readMaze(ifstream & mazeFile)
{
	for (auto row = 0; row < matrix_.size(); row++)
		for (auto col = 0; col < matrix_.at(row).size(); col++)
			mazeFile >> matrix_.at(row).at(col);
}

void Grid::resizeMatrix(const int &width, const int &height)
{
	matrix_.resize(height);
	for (int row = 0; row < matrix_.size(); row++)
		matrix_.at(row).resize(width);
}

Coordinates Grid::convertToGridPos(const float & screenWidth, const float & screenHeight) const
{
	auto x = int(screenWidth/blockWidth_);
	auto y = int(screenHeight/blockHeight_);

	return Coordinates{x,y};
}

Coordinates Grid::convertToScreenPos(const int & gridRow, const int & gridCol) const
{
	return Coordinates{gridCol * blockWidth_, gridRow * blockHeight_};
}

Coordinates Grid::getBlockDimentions() const
{
	return Coordinates{blockWidth_, blockHeight_};
}

Coordinates Grid::getScreenDimentions() const
{
	return screen_;
}

Matrix Grid::getMatrix() const
{
	return matrix_;
}
