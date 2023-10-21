#include "light.hpp"

sf::Vector2f Light::getPosition() {
	return lightPosition;
}

void Light::toggleActive() {
	isActive = !isActive;
}

bool Light::getStatus() {
	return isActive;
}