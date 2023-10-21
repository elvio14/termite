#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <SFML/Graphics.hpp>

class Light {
public:
	Light(float x, float y, bool isActive) : lightPosition(x, y), isActive(isActive) {};
	
	sf::Vector2f getPosition();
	bool getStatus();
	void toggleActive();

private:
	sf::Vector2f lightPosition;
	bool isActive;
};

extern std::vector<Light> lights;

#endif