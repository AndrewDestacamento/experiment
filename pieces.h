#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>
#include "defaults.h"

const float OUTLINE_RATIO = 1.5 - std::sqrtf(1.25);
const float CROSS_RATIO = (std::sqrtf(5) - 2.0) / std::sqrtf(2.0);

enum Visibility {
	Unplaced = 0,
	Hovering = 85,
	Placed = 255,
};

class Nought {
private:
	sf::CircleShape shape;
	Visibility visibility = Unplaced;
public:
	Nought(sf::Vector2f position = sf::Vector2f(0,0), float width = 0) {
		float radius = width * 0.5;
		float outline_radius = radius * OUTLINE_RATIO;

		shape.setRadius(radius - outline_radius);
		shape.setPointCount(60);
		shape.setFillColor(sf::Color::Transparent);
		shape.setOutlineColor(sf::Color(15, 80, 255, visibility));
		shape.setOutlineThickness(outline_radius);
		shape.setPosition(sf::Vector2f(position.x + outline_radius, position.y + outline_radius)); // From top-left
	}
	Visibility get_visibility() {
		return visibility;
	}
	void set_visibility(Visibility input_visibility) {
		visibility = input_visibility;
		shape.setOutlineColor(sf::Color(15, 80, 255, visibility));
	}
	void draw(sf::RenderWindow& window) {
		window.draw(shape);
	}
};

class Cross {
private:
	std::vector<sf::RectangleShape> shape;
	Visibility visibility = Unplaced;
public:
	Cross(sf::Vector2f position = sf::Vector2f(0, 0), float width = 0) {
		sf::RectangleShape minor;
		minor.setFillColor(sf::Color(220, 0, 0, visibility));
		minor.setSize(sf::Vector2f(width * (1.0 - CROSS_RATIO) * std::sqrtf(2), width * CROSS_RATIO * std::sqrt(2)));
		minor.setPosition(sf::Vector2f(position.x + width * CROSS_RATIO, position.y));
		minor.setRotation(45);
		shape.push_back(minor);

		sf::RectangleShape major = minor;
		major.setPosition(sf::Vector2f(position.x + width, position.y + width * CROSS_RATIO));
		major.setRotation(135);
		shape.push_back(major);
	}
	Visibility get_visibility() {
		return visibility;
	}
	void set_visibility(Visibility input_visibility) {
		visibility = input_visibility;
		for (sf::RectangleShape &line : shape) {
			line.setFillColor(sf::Color(220, 0, 0, visibility));
		}
	}
	void draw(sf::RenderWindow& window) {
		for (sf::RectangleShape &line : shape) {
			window.draw(line);
		}
	}
};