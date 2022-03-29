#pragma once
#include "SFML/Graphics.hpp"

class Fireball {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	static std::string fireball_file_names[];
public:
	Fireball(float, float);
	void draw(sf::RenderWindow& window);
	void update();
	size_t getWidth();
	size_t getHeight();
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
	void spawn();
};

