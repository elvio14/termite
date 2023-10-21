#ifndef WALL_HPP
#define WALL_HPP

#include <SFML/Graphics.hpp>

class Wall {
public: 
	Wall(sf::Vector2f position, sf::Vector2f size, float angle ) : position(position), size(size), angle(angle) {};

private: 
	sf::Vector2f position;
	sf::Vector2f size;
	float angle;
};

#endif