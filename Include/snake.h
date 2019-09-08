#include "../Include/cell.h"
#include<list>
#include<iterator>

class snake{
private:
	Cell head;
	list<Cell> snakeList;
public:
	snake(Cell& initPos);
	~snake();
	void grow(Cell& nextCell);
	void move(Cell& nextCell);
	bool checkCrash(Cell& nextCell);
	list<Cell> getSnakeList();
	void setSnakeList(list<Cell> snakeList);
	Cell getHead();
	void setHead(Cell head);
};