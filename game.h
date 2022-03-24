#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"
#include "player.h"
#include <vector>
#include "map.h"
#include "platform.h"
#include <list>
#include"laser.h"
#include "splash.h"

class Game {
public:
	enum GameState { SPLASH, PLAY, PAUSE, GAME_OVER };
	Game();
	void play();
private:
	void check_events();
	void update();
	void draw();
	void check_collisions();

	sf::RenderWindow window;
	Player player;
	Map map;
	//Platform platform[PLATFORM_QTY];;
	std::list<Laser*> laser_sprites;
	GameState game_state = SPLASH;
	Splash splash;


	sf::Clock clock;

};