#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"


class Pause_icon {
private:
	sf::Sprite sprite;
	sf::Texture texture;
public:
	Pause_icon(float x, float y) {
		texture.loadFromFile(IMG + pause_icon);
		sprite.setTexture(texture);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}

	void update() {}

	sf::Vector2f getPosition();
};



