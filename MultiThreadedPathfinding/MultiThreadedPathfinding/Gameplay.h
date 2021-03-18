#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <array>

class GamePlay
{
public:
	GamePlay();
	~GamePlay();
	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window);
	void render(sf::RenderWindow& t_window);
	void setup(sf::Font& t_font);
	void initialise();
private:
	//Font
	sf::Font m_font;
	void input(sf::RenderWindow& t_window);

	//Timer
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.0f / 2.0f);

};