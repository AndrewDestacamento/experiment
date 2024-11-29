#pragma once
#include "grid.h"

enum Turn {
	Player1,
	Player2
};

class TicTacToe {
private:
	unsigned char rows = 3, columns = 3;
	Turn current_turn = Player1;
	bool random_turn = 0;
public:
	Grid ttt_grid;
	TicTacToe() {
		ttt_grid.rows = rows;
		ttt_grid.columns = columns;
	}
};

class Ultimate {
private:
	unsigned char rows = 9, columns = 9;
	bool ultimate = true;

};