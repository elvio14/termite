#include "game.hpp"
#include "termite.hpp"
#include "lamp.hpp"
#include "light.hpp"
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

std::vector<Light> lights;
std::vector<Termite> termites;

const int Game::groupRadius = 200;
Lamp mLamp(300.f, 300.f, false);
Lamp mLamp2(200.f, 200.f, false);
Lamp mLamp3(100.f, 400.f, false);
Lamp mLamp4(450.f, 100.f, false);



float pi = static_cast<float>(M_PI);
float angleY = 3*pi/4;
float angleX = pi/4;


Game::Game()
	: mWindow(sf::VideoMode(640, 480), "SFML Game")
{

	int copiedGroupRadius = Game::groupRadius;

	lights.push_back(Light(300.f, 300.f, false));
	lights.push_back(Light(200.f, 200.f, false));
	lights.push_back(Light(100.f, 400.f, false));
	lights.push_back(Light(450.f, 100.f, false));

	for (int i = 0; i < 20; i++)
	{
		termites.push_back(Termite
		( (rand() % copiedGroupRadius - rand() % copiedGroupRadius) + 400.f,
			 (rand() % copiedGroupRadius - rand() % copiedGroupRadius) + 200.f,
			(rand()%2 - rand()%2)
		)
		);
	}
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		case sf::Event::MouseButtonPressed:
			mLamp.turnOnOff(event, mWindow);
			mLamp2.turnOnOff(event, mWindow);
			mLamp3.turnOnOff(event, mWindow);
			mLamp4.turnOnOff(event, mWindow);
			break;
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	for (auto& termite : termites)
	{
		sf::Vector2f termitePosition = termite.getPosition();
		sf::Vector2f newPosition = termite.behave(angleX, angleY);
		termite.setPosition(newPosition.x, newPosition.y);
	}

	
	angleY += 0.05f;
	angleX += 0.05f;
	
}

void Game::render()
{
	mWindow.clear();

	mLamp.render(mWindow);
	mLamp2.render(mWindow);
	mLamp3.render(mWindow);
	mLamp4.render(mWindow);

	for (auto& termite : termites)
	{
		termite.render(mWindow);
	}



	mWindow.display();
}