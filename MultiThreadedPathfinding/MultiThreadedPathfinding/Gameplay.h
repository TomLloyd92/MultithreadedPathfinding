#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <array>
#include "LevelOne.h"
#include "LevelTwo.h"
#include "LevelThree.h"
#include "Enemy.h"
#include <fstream>
#include "Graph.h"
#include "GraphArc.h"
#include "GraphNode.h"
#include "NodeData.h"
#include "Globals.h"
#include "Player.h"
#include "ThreadPool.h"

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

	int x = 0;

	//Timer
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.0f / 2.0f);

	enum Level { ONE, TWO, THREE };
	
	//<---------- Level Settings ----------------->
	bool showPath = true;

	Level level = Level::ONE;
	LevelOne levelOne;
	void generateEnemyLevel1();

	LevelTwo levelTwo;
	void generateEnemyLevel2();

	//LevelThree levelThree;
	void generateEnemyLevel3();


	//<----------End Level Settings ----------------->

	ThreadPool tp;

	bool hasStarted = false;
	bool hasStarted1 = false;
	bool hasStarted2 = false;
	bool hasStarted3 = false;
	bool everyoneHasReached = false;

	//std::vector<Node*> path;

	Player m_player;

	void renderEnemeys(std::vector<Enemy*> t_enemys, sf::RenderWindow& t_window);

	std::vector<Enemy*> m_enemys;
	std::vector<Enemy*> m_enemys1;
	std::vector<Enemy*> m_enemys2;
	std::vector<Enemy*> m_enemys3;
	std::vector<Enemy*> m_enemys4;
	std::vector<Enemy*> m_enemys5;
	std::vector<Enemy*> m_enemys6;
	std::vector<Enemy*> m_enemys7;
	std::vector<Enemy*> m_enemys8;
	std::vector<Enemy*> m_enemys9;

	void updateEnemyLvl1(sf::Time t_deltaTime, std::vector<Enemy*> enemys);
	void updateEnemyLvl2(sf::Time t_deltaTime, std::vector<Enemy*> enemys);
	void updateEnemyLvl2Other(sf::Time t_deltaTime, std::vector<Enemy*> enemys);


	void test() {  std::cout << "Test" << std::endl; };
	void test1() { std::cout << "Test1" << std::endl; };
	void test2() { std::cout << "Test2" << std::endl; };
	void test3() { std::cout << "Test3" << std::endl; };
	void test4() { std::cout << "Test4" << std::endl; };
	void test5() { std::cout << "Test5" << std::endl; };
	void test6() { std::cout << "Test6" << std::endl; };
	void test7() { std::cout << "Test7" << std::endl; };
	void test8() { std::cout << "Test8" << std::endl; };
	void test9() { std::cout << "Test9" << std::endl; };
	void test10() { std::cout << "Test10" << std::endl; };
	void test11() { std::cout << "Test11" << std::endl; };
	void test12() { std::cout << "Test12" << std::endl; };
	void test13() { std::cout << "Test13" << std::endl; };
	void test14() { std::cout << "Test14" << std::endl; };
	void test15() { std::cout << "Test15" << std::endl; };

	void moveSquareOnPath(std::vector<Node*> t_path, Enemy& t_enemy);

	float timer = 0;
	float TIMELIMIT = 1;
 
};