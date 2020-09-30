#include "Maze.h"

Maze::Maze(const Coordinates &gridSize, const Coordinates &screenDimentions) :
		screen_(screenDimentions), blockWidth_(screenDimentions.getX()/gridSize.getX()),
		blockHeight_(screenDimentions.getY()/gridSize.getY()), widthV_(1.f/4 * blockWidth_),
		heightShortV_(2.f/3 * blockHeight_), heightH_(1.f/3 * blockHeight_), widthShortH_(5.f/8 * blockWidth_),
		xOffset_(3.f/8 * blockWidth_), yOffset_(1.f/3 * blockHeight_)
{
	resizeMatrix(gridSize.getX(), gridSize.getY());
	readMaze();
	generateMaze();
}

void Maze::readMaze()
{
	auto mazeFile = ifstream { "maze.txt" };

	for (auto row = 0; row < matrix_.size(); row++)
		for (auto col = 0; col < matrix_.at(row).size(); col++)
			mazeFile >> matrix_.at(row).at(col);

	mazeFile.close();
}

void Maze::resizeMatrix(const int &width, const int &height)
{
	matrix_.resize(height);
	for (int row = 0; row < matrix_.size(); row++)
		matrix_.at(row).resize(width);
}

EntityVec Maze::getWalls() const
{
	return wallCoords_;
}

void Maze::generateMaze()
{
	for(auto row = 0; row < matrix_.size(); row++)
	{
		for(auto col = 0; col < matrix_.at(row).size(); col++)
		{
			switch(matrix_.at(row).at(col))
			{
			case 1:
				verticalWall(row, col);
				break;
			case 2:
				horizontalWall(row, col);
				break;
			case 3:
				topLeftWall(row, col);
				break;
			case 4:
				topRightWall(row, col);
				break;
			case 5:
				bottomLeftWall(row, col);
				break;
			case 6:
				bottomRightWall(row, col);
				break;
			default:
				break;
			}
		}
	}
}

void Maze::verticalWall(const int & row, const int & col)
{
	auto positionX = col * blockWidth_ + xOffset_;
	auto positionY = row * blockHeight_;

	wallCoords_.push_back(Entity{Coordinates{positionX,positionY}, Coordinates{widthV_,blockHeight_}});

}

void Maze::horizontalWall(const int & row, const int & col)
{
	auto positionX = col * blockWidth_;
	auto positionY = row * blockHeight_ + yOffset_;

	wallCoords_.push_back(Entity{Coordinates{positionX,positionY}, Coordinates{blockWidth_,heightH_}});
}

void Maze::topLeftWall(const int & row, const int & col)
{
	auto positionX = col * blockWidth_ + xOffset_;
	auto positionY = row * blockHeight_ + yOffset_;

	wallCoords_.push_back(Entity{Coordinates{positionX,positionY}, Coordinates{widthShortH_,heightH_}});
	wallCoords_.push_back(Entity{Coordinates{positionX,positionY}, Coordinates{widthV_,heightShortV_}});
}

void Maze::topRightWall(const int & row, const int & col)
{
	auto positionXH = col * blockWidth_;
	auto positionXV = col * blockWidth_ + xOffset_;
	auto positionY = row * blockHeight_ + yOffset_;

	wallCoords_.push_back(Entity{Coordinates{positionXH,positionY}, Coordinates{widthShortH_,heightH_}});
	wallCoords_.push_back(Entity{Coordinates{positionXV,positionY}, Coordinates{widthV_,heightShortV_}});
}

void Maze::bottomLeftWall(const int & row, const int & col)
{
	auto positionX = col * blockWidth_ + xOffset_;
	auto positionYH = row * blockHeight_ + yOffset_;
	auto positionYV = row * blockHeight_;

	wallCoords_.push_back(Entity{Coordinates{positionX,positionYH}, Coordinates{widthShortH_,heightH_}});
	wallCoords_.push_back(Entity{Coordinates{positionX,positionYV}, Coordinates{widthV_,heightShortV_}});
}

void Maze::bottomRightWall(const int & row, const int & col)
{
	auto positionXH = col * blockWidth_;
	auto positionYH = row * blockHeight_ + yOffset_;
	auto positionXV = col * blockWidth_ + xOffset_;
	auto positionYV = row * blockHeight_;

	wallCoords_.push_back(Entity{Coordinates{positionXH,positionYH}, Coordinates{widthShortH_,heightH_}});
	wallCoords_.push_back(Entity{Coordinates{positionXV,positionYV}, Coordinates{widthV_,heightShortV_}});
}
