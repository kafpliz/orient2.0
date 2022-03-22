#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

class Map {
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Map() {
		texture.loadFromFile("map.jpg");
		sprite.setTexture(texture);
	}
	sf::Sprite getSprite() { return sprite; }

	void update() {}


};

