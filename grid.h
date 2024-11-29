#pragma once
#include <vector>
#include <iostream>
#include "games.h"

class Grid {
private:
	friend class TicTacToe;
	friend class Ultimate;
	unsigned char rows, columns;
	bool ultimate = false;

public:
	std::vector<sf::RectangleShape> grid_squares;
	void calculate_grid(sf::Vector2f size) {
		if (ultimate) {
			//
		}
		float x_pos, y_pos;
		sf::Vector2f square_size(size.x / columns, size.y / columns);
		float outline_size = (size.x + size.y) * 0.002381;

		sf::RectangleShape base_square;
		base_square.setFillColor(sf::Color::Transparent);
		base_square.setOutlineColor(sf::Color::White);
		base_square.setOutlineThickness(outline_size);
		base_square.setSize(square_size);

		for (int row = 0; row < rows; row++) {
			sf::Vector2f square_position;
			square_position.y = square_size.y * row;
			for (int column = 0; column < columns; column++) {
				square_position.x = square_size.x * column;

				sf::RectangleShape modified_square = base_square;
				modified_square.setPosition(square_position);
				grid_squares.push_back(modified_square);
			}
		}
	}
};