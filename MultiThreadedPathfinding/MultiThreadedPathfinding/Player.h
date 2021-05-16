#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"

class Player
{
public:
	Player();
	~Player();

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void setup(sf::Font& t_font);
	void initialise();

	//Sets

	//Gets
	int getNodeIndexX() { return m_nodeIndexX; };
	int getNodeIndexY() { return m_nodeIndexY; };



	int getCurrentNode() { return m_currentNode; };


private:
	//Node Index
	int m_nodeIndexX = 0;
	int m_nodeIndexY = 0;

	sf::RectangleShape m_playerShape;

	void currentNodeUpdate();
	int rows = 30;
	//int rows = 100;
	//int rows = 1000;

	int m_currentNode;

};