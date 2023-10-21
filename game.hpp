#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	void run();
	static const int groupRadius;
	

private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();

private:
	static const sf::Time TimePerFrame;

	sf::RenderWindow mWindow;

};

#endif