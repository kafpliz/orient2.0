#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"
#include "player.h"
#include <vector>
#include "map.h"
#include <list>
#include"laser.h"
#include "splash.h"
#include "fireball.h"
#include "txt.h"
#include "pause.h"
#include "pause_icon.h"
#include "obstacle.h"


class Game {
public:
	enum  GameState { SPLASH, PLAY, PAUSE, GAME_OVER };
	Game();
	void play();
private:
	void check_events();
	void update();
	void draw();
	void check_collisions();

	sf::RenderWindow window;
	GameState game_state = SPLASH;
	Player player;
	Pause_icon iconpause;
	Map map;
	TextObj hp_text;
	std::list<Laser*> laser_sprites;
	std::list<Fireball*> fireball_sprites;
	Splash splash;
	Pause pause;
	Obstacle obs[OBSTACLE_QTY];
	sf::Clock clock;
};