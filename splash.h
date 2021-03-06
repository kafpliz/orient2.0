#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

class Splash {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Splash() {
		texture.loadFromFile(IMG + SPLASH);
		sprite.setTexture(texture);
	}
	sf::Sprite getSprite() { return sprite; }
};