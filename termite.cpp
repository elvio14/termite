#include "termite.hpp"
#include "game.hpp"
#include "light.hpp"
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>

const int groupRadius = Game::groupRadius;

void Termite::moveToLamp(const sf::Vector2f& current, const sf::Vector2f& target, float speed)
{
	sf::Vector2f direction = target - current;
	float length = std::sqrt(direction.x * direction.x + direction.y + direction.y);
	
	direction.x /= length;
	direction.y /= length;

	while (length > 0) {
		sf::Vector2f newPosition = position + direction * speed;
		position.x = newPosition.x;
		position.y = newPosition.y;
	}
}

float Termite::getDistance(sf::Vector2f termitePosition, sf::Vector2f lightPosition) {
	sf::Vector2f direction = lightPosition - termitePosition;
	float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	return distance;
}

sf::Vector2f Termite::getClosestLight(const sf::Vector2f& termitePosition) {
	std::vector<sf::Vector2f> sortedLights;
	for (int i = 0; i < lights.size(); i++) {
		if (lights[i].getStatus() == true) {
			sf::Vector2f lightPosition = lights[i].getPosition();
			sortedLights.push_back(lightPosition);
		}
	}

	auto comp = [this, &termitePosition](sf::Vector2f a, sf::Vector2f b) {
		return getDistance(termitePosition, a) < getDistance(termitePosition, b);
		};

	std::sort(sortedLights.begin(), sortedLights.end(), comp);
	if (sortedLights.size() > 0) {
		return sortedLights[0];
	}
	return sf::Vector2f();
}

sf::Vector2f Termite::behave(float angleX, float angleY ) {
	
	float groupRadius = 35.f;

	float distanceX = 0.f;
	float distanceY = 0.f;

	std::vector<bool> lightStatuses;
	for (int i = 0; i < lights.size(); i++) {
		bool isActive = lights[i].getStatus();
		lightStatuses.push_back(isActive);
	}

	auto activeLight = std::find(lightStatuses.begin(), lightStatuses.end(), true);

	if (activeLight != lightStatuses.end()) {
		sf::Vector2f sortedLights = getClosestLight(position);

		float activeX = sortedLights.x;
		float activeY = sortedLights.y;

		distanceX = activeX - position.x;
		distanceY = activeY - position.y;
	}
		

	float ny = angleY;
	float nx = angleX; 
	
	

	if (distanceY > groupRadius) {
		position.y += 2;
	}
	
	if (distanceY < -groupRadius) {
		position.y -= 2;
	}
	
	if (distanceX > groupRadius) {
		position.x += 2;
	}
	if (distanceX < -groupRadius) {
		position.x -= 2;
	}
	
	if (direction >= 0){
		position.y += 1 * std::cos(ny) + (rand() % 2 - rand() % 2);
		position.x += 1 * std::cos(nx) + (rand() % 2 - rand() % 2);
	}
	else
	if (direction < 0) {
		position.y -= 1 * std::cos(ny) - (rand() % 2 - rand() % 2);
		position.x -= 1 * std::cos(nx) - (rand() % 2 - rand() % 2);
	}


	return position;
}

sf::Vector2f Termite::getPosition() {
	return position;
}

void Termite::setPosition(float x, float y) {
	position.x = x;
	position.y = y;
}

void Termite::render(sf::RenderWindow& window){
	sf::CircleShape shape(5);
	shape.setPosition(position);
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(1.f);
	window.draw(shape);
}
