#ifndef GRID_H_
#define GRID_H_
#include "Coordinates.h"
#include <fstream>
#include <vector>
using namespace std;
using Matrix = vector<vector<int> >;

class Grid
{
public:
	Grid(const Coordinates & gridSize, const Coordinates & screenDimentions, ifstream & mazeFile);
	Matrix getMatrix() const;
	Coordinates getBlockDimentions() const;
	Coordinates convertToGridPos(const float & screenWidth, const float & screenHeight) const;
	Coordinates convertToScreenPos(const int & gridRow, const int & gridCol) const;
	Coordinates getScreenDimentions() const;
private:
	Coordinates screen_;
	Matrix matrix_;
	const float blockWidth_;
	const float blockHeight_;
	void readMaze(ifstream & mazeFile);
	void resizeMatrix(const int &width, const int &height);
};

#endif
