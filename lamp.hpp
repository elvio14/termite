#ifndef LAMP_HPP
#define LAMP_HPP

#include <SFML/Graphics.hpp>

class Lamp {
public: 
	Lamp(float x, float y, bool isOn) : position(x, y), speed(1.0f), isOn(isOn) {};
	void setPosition(float x, float y);
	sf::Vector2f getPosition();
	void turnOnOff(const sf::Event& event, const sf::RenderWindow& window);
	void setActivePosition(sf::Vector2f activePosition);
	bool getLampStatus();
	int getPairedLightIndex(sf::Vector2f lampPosition);

	void render(sf::RenderWindow& window);

private:
	sf::Vector2f position;
	float speed;
	bool isOn;
	float lampSize = 25.f;
};

#endif