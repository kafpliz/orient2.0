#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"



class Obstacle {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed = sf::Vector2f(0.0f, 3.0f);
public:
	Obstacle() {
		texture.loadFromFile(IMG + obstacle);
		sprite.setTexture(texture);
		sprite.setScale(0.3f, 0.3f);
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
