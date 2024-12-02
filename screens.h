#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "defaults.h"
#include "games.h"

enum Screen {
	Title,
	GlobalSettings,
	Selection,
	TTTGame,
	TTTSettings,
	UltimateGame,
	UltimateSettings,
};

/*
This section uses sf::Font and sf::Text. Font size defines the character/glyph/letter height. Font width is usually half of the font size/height, but this is always true for monospaced fonts. Non-monospaced fonts adjust the spacing between two consecutive glyphs so they are visually closer or farther apart, which is called kerning.
*/

float text_width(sf::Font &font, sf::Text &text) {
	std::string original_text(text.getString());
	float font_size = text.getCharacterSize();
	float text_width = original_text.length() * font_size * 0.5;

	for (int i = 0; i < original_text.length() - 1; i++) {
		text_width += font.getKerning(original_text[i], original_text[i + 1], font_size, false);
	}
	return text_width;
}

void title(sf::RenderWindow &window) {
	sf::Font font;
	if (!font.loadFromFile("font.ttf")) {
		std::cout << "[WARN] `assets/font.ttf` could not be loaded, no game text can load." << std::endl;
	}
	font.setSmooth(true);

	sf::Text base_text, title_text, selection_button, settings_button;
	base_text.setFont(font);
	base_text.setStyle(sf::Text::Regular);
	base_text.setFillColor(sf::Color::White);

	title_text = base_text;
	title_text.setString(BASE_TITLE);
	title_text.setCharacterSize(BASE_FONT_SIZE);
	title_text.setPosition((BASE_WINDOW_WIDTH - text_width(font, title_text)) * 0.5, 0);

	selection_button = base_text;
	selection_button.setString("Play");
	selection_button.setCharacterSize(BASE_FONT_SIZE * 0.5);
	selection_button.setPosition((BASE_WINDOW_WIDTH - text_width(font, selection_button)) * 0.5, (BASE_WINDOW_HEIGHT - selection_button.getCharacterSize()) * 0.5);

	settings_button = base_text;
	settings_button.setString("Settings");
	settings_button.setCharacterSize(BASE_FONT_SIZE * 0.5);
	settings_button.setPosition((BASE_WINDOW_WIDTH - text_width(font, settings_button)) * 0.5, BASE_WINDOW_HEIGHT * 0.75 - settings_button.getCharacterSize() * 0.5);

	window.draw(title_text);
	window.draw(selection_button);
	window.draw(settings_button);
}
void selection();