#include "../Include/cell.h"
#include "../Include/snake.h"
#include "../Include/board.h"


enum directionToMove{
	RIGHT=0,
	LEFT,
	UP,
	DOWN,
};

class game{
private:
	snake *Snake;
	Board *boardMap;
	directionToMove Direction;
public:
	game(int row,int col);
	void run();
};