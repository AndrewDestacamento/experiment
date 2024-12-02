#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "defaults.h"
#include "games.h"
#include "grid.h"
#include "pieces.h"
#include "screens.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(BASE_WINDOW_WIDTH, BASE_WINDOW_HEIGHT), BASE_TITLE, sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(FRAMERATE_LIMIT);

    Screen current_screen = Screen::Selection;

    TicTacToe ttt_game(window);

    // Game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            /* 
            * Disable resizing
            case sf::Event::Resized:
                // Prevent window from being too thin
                if (event.size.height < 232) {
                    window.setSize(sf::Vector2u(window.getSize().x, 232));
                }
                break;
            */
            case sf::Event::MouseButtonPressed:
                // Add stuff
                break;
            case sf::Event::MouseButtonReleased:
                // Add stuff
                break;
            case sf::Event::MouseMoved:
                // Add stuff
                break;
            case sf::Event::MouseEntered:
                // Add stuff
                break;
            case sf::Event::MouseLeft:
                // Add stuff
                break;
            default:
                // Nothing to do
                break;
            }
        }
        window.clear(sf::Color::Black);

        // Draw stuff
        switch (current_screen) {
        case Title:
            title(window);
            break;
        case GlobalSettings:
            // Nothing to do
            break;
        case Selection:
            ttt_game.game_start();
            current_screen = TTTGame;
            break;
        case TTTGame:
            ttt_game.draw_board();
            break;
        case TTTSettings:
            // Nothing to do
            break;
        case UltimateGame:
            // Nothing to do
            break;
        case UltimateSettings:
            // Nothing to do
            break;
        default:
            // Just reset to title
            current_screen = Screen::Title;
            break;
        }

        window.display();
    }

    return 0;
}