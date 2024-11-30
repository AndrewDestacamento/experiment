#pragma once
#include "defaults.h"
#include "grid.h"

enum Turn {
	Player1,
	Player2
};

class TicTacToe {
private:
	unsigned int total_rows = 3, total_columns = 3;
	Turn current_turn = Player1;
	bool random_turn = 0;
public:
	Grid ttt_grid;
	TicTacToe() {
		ttt_grid.total_rows = total_columns;
		ttt_grid.total_columns = total_columns;
	}
};

class Ultimate {
private:
	unsigned int total_rows = 9, total_columns = 9;
	bool ultimate = true;

};