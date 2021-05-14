#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <array>
#include "LevelOne.h"
#include "Level2.h"
#include "Level3.h"
#include "Enemy.h"
#include <fstream>
#include "Graph.h"
#include "GraphArc.h"
#include "GraphNode.h"
#include "NodeData.h"
#include "Globals.h"
#include "Player.h"


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

	enum Level { ONE, TWO, THREE };
	Level level = Level::ONE;

	std::vector<Node*> path;

	Player m_player;

	LevelOne levelOne;
	//LevelTwo levelTwo;
	//LevelThree levelThree;
	std::vector<Enemy*> m_enemys;
	void generateEnemyLevel1();
};