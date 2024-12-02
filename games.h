#pragma once
#include <random>
#include "defaults.h"
#include "grid.h"

const int TITLEBAR_HEIGHT = 60; // Find a way to calculate this

enum Turn {
	Noughts,
	Crosses
};

enum GameState {
	NotStarted,
	NowPlaying,
	NoughtsWon,
	CrossesWon
};

Turn turn_randomize() {
	std::random_device entropy_source;
	std::default_random_engine generator(entropy_source());
	std::uniform_int_distribution<> choose(0, 1);

	return (choose(generator) ? Noughts : Crosses);
}

class TicTacToe {
private:
	GameState state = NotStarted;
	Turn current_turn;
	bool random_turn = false;
	sf::RenderWindow* window;
public:
	Grid ttt_grid;
	TicTacToe(sf::RenderWindow& input_window) {
		ttt_grid.total_rows = 3;
		ttt_grid.total_columns = 3;
		window = &input_window;
		ttt_grid.generate_grid();
	}


	void game_start() {
		state = NowPlaying;

		current_turn = turn_randomize();
		switch (current_turn) {
		case Noughts:
			window->setTitle("O's turn!");
			break;
		case Crosses:
			window->setTitle("X's turn!");
			break;
		default:
			// Something went wrong.
			break;
		}
	}

	void draw_board() {
		for (std::tuple<sf::RectangleShape, Nought, Cross> grid_square : ttt_grid.grid_squares) {
			window->draw(std::get<0>(grid_square));

			sf::Vector2f mouse_position = window->mapPixelToCoords(sf::Mouse::getPosition());
			mouse_position.x -= window->getPosition().x;
			mouse_position.y -= window->getPosition().y;
			mouse_position.y -= TITLEBAR_HEIGHT;

			switch (current_turn) {
			case Noughts:
				if (std::get<0>(grid_square).getGlobalBounds().contains(mouse_position)) {
					if (std::get <1>(grid_square).get_visibility() == Unplaced) {
						std::get<1>(grid_square).set_visibility(Hovering);
					}
				}
				else {
					if (std::get<1>(grid_square).get_visibility() == Hovering) {
						std::get<1>(grid_square).set_visibility(Unplaced);
					}
				}
				std::get<1>(grid_square).draw(*window);
				break;
			case Crosses:
				if (std::get<0>(grid_square).getGlobalBounds().contains(mouse_position)) {
					if (std::get <2>(grid_square).get_visibility() == Unplaced) {
						std::get<2>(grid_square).set_visibility(Hovering);
					}
				}
				else {
					if (std::get<2>(grid_square).get_visibility() == Hovering) {
						std::get<2>(grid_square).set_visibility(Unplaced);
					}
				}
				std::get<2>(grid_square).draw(*window);
				break;
			}
		}
	}
};

class Ultimate : private TicTacToe {
private:
	int total_rows = 9, total_columns = 9;
	bool ultimate = true;

};