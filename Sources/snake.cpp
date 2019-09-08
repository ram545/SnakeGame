#include "../Include/snake.h"

snake::snake(Cell& initPos):head(initPos)
{
	snakeList.push_front(head);
}	

snake::~snake(){
	snakeList.clear();
}

void snake::grow(Cell& nextCell){
	this->head = nextCell;
	snakeList.push_front(this->head);
}
	
void snake::move(Cell& nextCell){
	Cell tail = snakeList.back();
	this->head=nextCell;
	snakeList.push_front(this->head);
	snakeList.pop_back();
	tail.setCellType(EMPTY);
}

bool snake::checkCrash(Cell& nextCell){
	list<Cell>::iterator it;
	for(it=snakeList.begin();it!=snakeList.end();++it){
		if(it->getRow()==nextCell.getRow() && it->getCol()==nextCell.getCol())
			return true;
	}
	return false;
}

list<Cell> snake::getSnakeList(){
	return this->snakeList;
}
	
void snake::setSnakeList(list<Cell> snakeList){
	this->snakeList=snakeList;
}
	
Cell snake::getHead(){
	return this->head;
}
	
void snake::setHead(Cell head){
	this->head = head;
}
