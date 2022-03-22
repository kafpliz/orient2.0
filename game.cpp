#include "game.h"

Game::Game() :
	window(sf::VideoMode(
		static_cast<size_t> (WINDOW_WIDTH),
		static_cast<size_t> (WINDOW_HEIGHT)
	),
		WINDOW_TITLE,
		sf::Style::Titlebar | sf::Style::Close
	),
	player(WINDOW_WIDTH / 2 - 238 / 2.f,
		WINDOW_HEIGHT - 205.f, "player.png")
	
{
	window.setFramerateLimit(60);

}
void Game::play() {
	while (window.isOpen()) {
		check_events();
		update();
		check_collisions();
		draw();
	}
}
void Game::check_events() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();

		if (event.type == sf::Event::MouseButtonPressed &&
			event.mouseButton.button == sf::Mouse::Left)
		{
			sf::Time elapsed = clock.getElapsedTime();
			if (elapsed.asMilliseconds() > 250) {
				laser_sprites.push_back(new Laser(player.getPosition().x +
					player.getWidth() / 2 - 5, player.getPosition().y));
				clock.restart();
			}
		}


			}

	}

void Game::update() {
	switch (game_state) {
	case PLAY:

		player.update();
		//for (int i = 0; i < PLATFORM_QTY; i++) {
		//	platform[i].update();
	//	}
		for (auto it = laser_sprites.begin(); it != laser_sprites.end(); it++) {
			(*it)->update();
		}

		break;
	case GAME_OVER:
		break;
	}
}
void Game::draw() {
	window.clear();
	switch (game_state) {

	case PLAY:
	
		window.draw(map.getSprite());
		player.draw(window);
		//for (int i = 0; i < PLATFORM_QTY; i++) {
			//window.draw(platform[i].getSprite());

			for (auto it = laser_sprites.begin(); it != laser_sprites.end(); it++) {
				(*it)->draw(window);
		//	}
		}
		break;
	//case GAME_OVER:

	}
	window.display();
}
void Game::check_collisions() {



	

}