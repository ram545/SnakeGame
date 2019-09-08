#include "../Include/board.h"

Board::Board(int rowCount,int colCount){
	int i,j;
	this->rowCount=rowCount;
	this->colCount=colCount;
	for(i=0;i<rowCount+2;i++){
		for(j=0;j<colCount+2;j++){
			Cell *TempObj = new Cell(i,j);
			gameBoard.push_back(*TempObj);
			if( (i==0||j==0) || (i==rowCount+1||j==colCount+1)){
				cout << i << " " << j << endl;
				getCellAt(i,j).setCellType(WALL);
			}
		}
	}
	srand(time(NULL));
}

Board::~Board(){
	rowCount=0;
	colCount=0;
	gameBoard.clear();
}

	
void Board::setCells(vector<Cell> board){
	this->gameBoard=board;
}

vector<Cell> Board::getCells(){
	return this->gameBoard;
}
	
void Board::generateFood(){
	int row,col;
	do{
		row = getRandomDistribution(rowCount);
		col = getRandomDistribution(colCount);
		cout << row << " " << col << endl;
	}while(getCellAt(row,col).getCellType()!=EMPTY);
	cout << "Food is Generated at " << "Row: " << row << " " << "Col: " << col << endl;
	getCellAt(row,col).setCellType(FOOD);
	cout << getCellAt(row,col).getCellType() << endl;
}
	
void Board::displayBoard(){
	int i,j,cellType;
	for(i=0;i<rowCount+2;i++){
		for(j=0;j<colCount+2;j++){
			cellType=getCellAt(i,j).getCellType();
			switch(cellType){
				case EMPTY:
					cout << " ";
					break;
				case FOOD:
					cout << "F";
					break;
				case SNAKE:
					cout << "S";
					break;
				case WALL:
					cout << "W";
					break;
				default:
					cout << " "; 
					break;
			}
		}
		cout << endl;
	}
}

Cell& Board::getCellAt(int row,int col){
	return gameBoard[row*(this->rowCount+1)+col];
}

int Board::getRowSize(){
	return rowCount;
}

int Board::getColSize(){
	return colCount;
}

int getRandomDistribution(int maxRange){
	int res,possion_constant=rand();
	std::default_random_engine generator;
	std::poisson_distribution<int> distribution(possion_constant);
	res=distribution(generator)%maxRange;
	if (res==0)
		return 1;
	else
		return res;
}
