#pragma once
#include <vector>
#include <iostream>
#include "defaults.h"
#include "games.h"

class Grid {
private:
	friend class TicTacToe;
	friend class Ultimate;
	unsigned int total_rows = 0, total_columns = 0;
	bool ultimate = false;

public:
	std::vector<sf::RectangleShape> grid_squares;
	void calculate_grid() {
		if (ultimate) {
			//
		}

		sf::RectangleShape base_square;
		base_square.setFillColor(sf::Color::Transparent);
		base_square.setOutlineColor(sf::Color::White);
		base_square.setOutlineThickness((float)(BASE_WINDOW_WIDTH + BASE_WINDOW_HEIGHT) / 420.f);
		base_square.setSize(sf::Vector2f((float)BASE_WINDOW_WIDTH / total_columns, (float)BASE_WINDOW_HEIGHT / total_rows));

		sf::Vector2f square_position;
		for (int current_row = 0; current_row < total_rows; current_row++) {
			square_position.y = base_square.getSize().y * current_row;

			for (int current_column = 0; current_column < total_columns; current_column++) {
				square_position.x = base_square.getSize().x * current_column;

				sf::RectangleShape modified_square = base_square;
				modified_square.setPosition(square_position);
				grid_squares.push_back(modified_square);
			}
		}
	}
};