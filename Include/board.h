#include "../Include/cell.h"
#include<random>
#include<cstdlib>
#include<ctime>

class Board{
private:
	int rowCount,colCount;
	vector<Cell> gameBoard;
public:
	Board(int rowCount,int colCount);
	~Board();
	void setCells(vector<Cell> board);
	vector<Cell> getCells();
	void generateFood();
	void displayBoard();
	Cell& getCellAt(int row,int col);
	int getRowSize();
	int getColSize();
};

int getRandomDistribution(int maxRange);