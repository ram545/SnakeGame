#include "../Include/cell.h"

Cell::Cell(int row,int col){
	this->row = row;
	this->col = col;
	this->type = EMPTY;
}

void Cell::setCellType(cellType type){
	this->type = type;
}

int Cell::getRow(){
	return this->row;
}

int Cell::getCol(){
	return this->col;
}

cellType Cell::getCellType(){
	return this->type;
}