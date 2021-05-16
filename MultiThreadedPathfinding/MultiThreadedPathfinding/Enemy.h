#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "NodeCompare.h"
#include "GraphNode.h"
#include "Graph.h"


#include <list>
#include <queue>
#include <vector>
#include <functional>
#include <math.h>
#include "NodeCompare.h"


class Enemy
{
public:






	Enemy();
	~Enemy();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void setup(sf::Font& t_font);
	void initialise();

	//Gets
	int getCurrentNode() { return m_currentNode; };

	

	sf::RectangleShape* getRectangle() { return &m_enemyShape; };

private:
	void currentNodeUpdate();
	
	int m_currentNode;




	//std::vector<Node*> m_path;
	sf::RectangleShape m_enemyShape;

	int rows = 30;
	//int rows = 100;
	//int rows = 1000;

};