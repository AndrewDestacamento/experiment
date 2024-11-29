#pragma once
#include <SFML/Graphics.hpp>
#include "games.h"
enum Screen {
	Title,
	Settings,
	Selection,
	TTTScreen,
	UltimateScreen,
};

void title();
void selection();
void tictactoe(sf::RenderWindow &window, sf::Vector2f size) {
	TicTacToe example_grid;
	example_grid.ttt_grid.calculate_grid(size);
	for (sf::RectangleShape square : example_grid.ttt_grid.grid_squares) {
		window.draw(square);
	}

}