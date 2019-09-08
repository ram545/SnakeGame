#ifndef CELL_H
#define CELL_H

#include<iostream>

using namespace std;

enum cellType{
	EMPTY=0,
	FOOD,
	SNAKE,
	WALL,
};

class Cell{
private:
	int row,col;
	cellType type;
public:
	Cell(int row,int col);
	int getRow();
	int getCol();
	void setCellType(cellType type);
	cellType getCellType();
};

#endif