#include "lamp.hpp"
#include "game.hpp"
#include "light.hpp"
#include <iostream>
#include <algorithm>

void Lamp::setPosition(float x, float y) {
	position.x = x;
	position.y = y;
}

sf::Vector2f Lamp::getPosition() {
	return position;
}

int Lamp::getPairedLightIndex(sf::Vector2f lampPosition) {
	for (int i = 0; i < lights.size(); i++) {
		sf::Vector2f lightPosition = lights[i].getPosition();
		if (lightPosition == lampPosition) {
			int index = i;
			return index;
		}
	}
	return int();
}

void Lamp::turnOnOff(const sf::Event& event, const sf::RenderWindow& window) {
	int pairedLight = getPairedLightIndex(position);
	if (event.mouseButton.button == sf::Mouse::Left) {
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

		sf::CircleShape boundCircle(lampSize);
		boundCircle.setPosition(position);
		if (boundCircle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
			isOn = !isOn;
			lights[pairedLight].toggleActive();
		}
	}
}

void Lamp::setActivePosition(sf::Vector2f activePosition) {
	if (isOn) {
		activePosition = position;
	}
}

bool Lamp::getLampStatus() {
	return isOn;
}

void Lamp::render(sf::RenderWindow& window) {
	sf::CircleShape shape(lampSize);
	shape.setPosition(position.x - lampSize/2, position.y - lampSize/2);
	if (isOn == true) 
	{
		shape.setFillColor(sf::Color::Yellow);
	}
	else{
		shape.setFillColor(sf::Color::White);
	}
	window.draw(shape);
}