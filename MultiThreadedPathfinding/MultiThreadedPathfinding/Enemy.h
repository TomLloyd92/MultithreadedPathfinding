#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"

class Enemy
{
public:
	Enemy();
	~Enemy();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void setup(sf::Font& t_font);
	void initialise();

	sf::Vector2f pos;

private:
	void currentNode();
	int m_currentNode;
};