#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "games.h"
#include "grid.h"
#include "pieces.h"
#include <iostream>

const unsigned short int BASE_WINDOW_LENGTH = 800;
const std::string BASE_TITLE = "Tic-Tac-Toe";

int main()
{
    sf::RenderWindow window(sf::VideoMode(BASE_WINDOW_LENGTH, BASE_WINDOW_LENGTH), BASE_TITLE);
    window.setFramerateLimit(30);

    // Game loop
    while (window.isOpen())
    {
        unsigned short int current_width = BASE_WINDOW_LENGTH, current_height = BASE_WINDOW_LENGTH;
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                current_width = event.size.width;
                current_height = event.size.height;
                if (current_height < 232) {
                    window.setSize(sf::Vector2u(window.getSize().x, 232));
                }
                break;
            case sf::Event::MouseButtonPressed:
                // Add stuff
                break;
            case sf::Event::MouseButtonReleased:
                // Add stuff
                break;
            case sf::Event::MouseMoved:
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
        window.display();
    }

    return 0;
}