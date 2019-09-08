#include "../Include/Game.h"

game::game(int rowCount,int colCount){
	boardMap = new Board(rowCount,colCount);
}

void game::run(){
	int row,col;
	row = getRandomDistribution(boardMap->getRowSize());
	col = getRandomDistribution(boardMap->getColSize());
	Snake = new snake(boardMap->getCellAt(row,col));
	boardMap->getCellAt(row,col).setCellType(SNAKE);
	boardMap->generateFood();
	boardMap->displayBoard();
}

int main(){
	game snakeGame(5,5);
	snakeGame.run();
}