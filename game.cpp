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
		// סענוכüבא
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

		if (event.type == sf::Event::MouseButtonPressed &&
			event.mouseButton.button == sf::Mouse::Right)
		{
			sf::Time elapsed = clock.getElapsedTime();
			if (elapsed.asMilliseconds() > 250) {
				laser_sprites.push_back(new Laser(player.getPosition().x +
					player.getWidth() / 2 - 5, player.getPosition().y));
				clock.restart();
			}
		}
		//

		//intro
		if (event.type == sf::Event::KeyPressed)
			if (event.key.code == sf::Keyboard::Space)
				if (game_state == SPLASH) game_state = PLAY;

		if (event.type == sf::Event::KeyPressed)
			if (event.key.code == sf::Keyboard::Enter)
				if (game_state == SPLASH) game_state = PLAY;

		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			if (game_state == SPLASH) game_state = PLAY;
			
		
		//
			}
	}

void Game::update() {
	switch (game_state) {
	case SPLASH:

		break;
	case PLAY:
		player.update();
		for (auto it = laser_sprites.begin(); it != laser_sprites.end(); it++) {
			(*it)->update();
		}

		break;
	case GAME_OVER:
		break;
	default:
		break;
	}
}
void Game::draw() {
	
	switch (game_state) {
	case SPLASH:
		window.clear(sf::Color::Black);
		window.draw(splash.getSprite());
		window.display();
		break;
	case PLAY:
		window.clear(sf::Color::Black);
		window.draw(map.getSprite());
		player.draw(window);
		

			for (auto it = laser_sprites.begin(); it != laser_sprites.end(); it++) {
				(*it)->draw(window);
		
		}
		break;
	case GAME_OVER:

		break;
	default:
		break;

	}
	window.display();
}
void Game::check_collisions() {



	

}