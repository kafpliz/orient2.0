#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

class Pause {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Pause() {
		texture.loadFromFile(IMG + PAUSE);
		sprite.setTexture(texture);
	}
	sf::Sprite getSprite() { return sprite; }
};
