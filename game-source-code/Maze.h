#ifndef MAZE_H_
#define MAZE_H_
#include <vector>
#include <fstream>
#include <iostream>
#include "Coordinates.h"
#include "Entity.h"
using namespace std;
using Matrix = std::vector<std::vector<int> >;
using EntityVec = std::vector<Entity >;

class Maze
{
public:
	Maze(const Coordinates & gridSize, const Coordinates & screenDimentions);
	EntityVec getWalls() const;
	Matrix getMatrix() const;
private:
	Coordinates screen_;
	Matrix matrix_;
	const float blockWidth_;
	const float blockHeight_;
	const float widthV_;
	const float heightShortV_;
	const float heightH_;
	const float widthShortH_;
	const float xOffset_;
	const float yOffset_;
	EntityVec wallCoords_;
	void readMaze();
	void resizeMatrix(const int &width, const int &height);
	void generateMaze();
	void horizontalWall(const int & row, const int & col);
	void verticalWall(const int & row, const int & col);
	void topLeftWall(const int & row, const int & col);
	void topRightWall(const int & row, const int & col);
	void bottomRightWall(const int & row, const int & col);
	void bottomLeftWall(const int & row, const int & col);
};

#endif
