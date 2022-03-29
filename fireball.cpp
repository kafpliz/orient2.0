#include "fireball.h"
#include "settings.h"


std::string Fireball::fireball_file_names[] ={"fireball.png", "player.png"};


Fireball::Fireball(float x, float y) {
	size_t type = rand() % 10;
	texture.loadFromFile(IMAGES_FOLDER +
		Fireball::fireball_file_names[type]);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}
void Fireball::update() {
	sprite.move(0.f, -FIREBALL_SPEEDY);
}
size_t Fireball::getWidth() { return sprite.getLocalBounds().width; }
size_t Fireball::getHeight() { return sprite.getLocalBounds().height; }
sf::FloatRect Fireball::getHitBox() { return sprite.getGlobalBounds(); }
void Fireball::draw(sf::RenderWindow& window) { window.draw(sprite); }
sf::Vector2f Fireball::getPosition() { return sprite.getPosition(); }