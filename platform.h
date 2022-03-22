/*
#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include <list>

class Platform {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed = sf::Vector2f(0.0f, 3.0f);
public:
	Platform() {
		texture.loadFromFile("platform.png");
		sprite.setTexture(texture);
	}
	sf::Sprite getSprite() { return sprite; }
	void init(float startx, float starty) { sprite.setPosition(startx, starty); }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	void update() {
		sprite.move(speed);
		if (sprite.getPosition().y >= WINDOW_HEIGHT) {
			int  line = rand() % 4;
			sprite.setPosition(line * 150.f, 0 - getHitBox().height);
		}
	}
};
*/