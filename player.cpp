#include "settings.h"
#include "player.h"
#include "game.h"

Player::Player(float x, float y, std::string texture_file_name) {
	texture.loadFromFile(texture_file_name);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}
void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}
void Player::update() {
	float speedx = PLAYER_SPEEDX;
	//float speedy = PLAYER_SPEEDY;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sprite.getPosition().x  > 0) {
		sprite.move(-speedx, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sprite.getPosition().x  < WINDOW_WIDTH - getWidth() ) {
		sprite.move(speedx, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJump) {
		jump();
	}
	if (isJump) {
		if (speedy < 24.f) { speedy += 1.f; }
		else { isJump = false; }
	}
	else speedy = 0.f;
	sprite.move(0, speedy);
			
	
}
size_t Player::getWidth() { return sprite.getLocalBounds().width;}
size_t Player::getHeight() { return sprite.getLocalBounds().height;}
sf::FloatRect Player::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Player::getPosition() { return sprite.getPosition(); }
void Player::reduceHp(float dmg) { hp -= dmg; }
bool Player::isDead() { return hp < 0; }
float Player::getHp() { return hp; }
void Player::jump() {
	isJump = true;
	speedy = -26.f;
}
