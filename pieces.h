#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>
#include "defaults.h"

const float OUTLINE_RATIO = 1.5 - std::sqrtf(1.25); // Golden ratio for outline

sf::CircleShape nought(sf::Vector2f position, float radius, sf::Color color = sf::Color(15,80,255,255)) {
	float outline_radius = radius * OUTLINE_RATIO;

	sf::CircleShape nought(radius - outline_radius, 60);
	nought.setFillColor(sf::Color::Transparent);
	nought.setOutlineColor(color);
	nought.setOutlineThickness(outline_radius);
	nought.setPosition(sf::Vector2f(position.x + outline_radius, position.y + outline_radius)); // From top-left
	return nought;
}

void cross(sf::Vector2f position, float radius, sf::Color color = sf::Color(220, 0, 0, 255)) {};