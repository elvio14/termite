#ifndef TERMITE_HPP
#define TERMITE_HPP

#include <SFML/Graphics.hpp>

class Termite {
public:
	Termite(float x, float y, int d) : position(x, y), speed(1.0f), direction(d) {};
	void moveToLamp(const sf::Vector2f& current, const sf::Vector2f& target, float distance);
	void render(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	void setPosition(float x, float y);
	sf::Vector2f behave(float angleX, float angleY);
	sf::Vector2f getClosestLight(const sf::Vector2f& termitePosition);
	float getDistance(sf::Vector2f termitePosition, sf::Vector2f lightPosition);

private:
	sf::Vector2f position;
	float speed;
	int direction;
	sf::Texture texture;
	sf::Sprite sprite;

};

extern std::vector<Termite> termites;

#endif