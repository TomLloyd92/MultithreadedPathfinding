#include "Gameplay.h"

GamePlay::GamePlay()
{
}

GamePlay::~GamePlay()
{
}

void GamePlay::update(sf::Time t_deltaTime, sf::RenderWindow& t_window)
{
	std::cout << "Updating " << std::endl;

	//path.clear();
	m_player.update(t_deltaTime);

	switch (level)
	{
	case GamePlay::ONE:
		//Level One Grid Update
		levelOne.update(t_deltaTime);

		//updateEnemyLvl1(t_deltaTime, m_enemys);
		//updateEnemyLvl1(t_deltaTime, m_enemys1);
		//updateEnemyLvl1(t_deltaTime, m_enemys2);
		//updateEnemyLvl1(t_deltaTime, m_enemys3);
		//updateEnemyLvl1(t_deltaTime, m_enemys4);
		//updateEnemyLvl1(t_deltaTime, m_enemys5);
		//updateEnemyLvl1(t_deltaTime, m_enemys6);
		//updateEnemyLvl1(t_deltaTime, m_enemys7);
		//updateEnemyLvl1(t_deltaTime, m_enemys8);
		//updateEnemyLvl1(t_deltaTime, m_enemys9);

		tp.threadQue([&] { updateEnemyLvl1(t_deltaTime, m_enemys); });

		tp.threadQue([&] { updateEnemyLvl1(t_deltaTime, m_enemys1); });

		tp.threadQue([&] { updateEnemyLvl1(t_deltaTime, m_enemys2); });

		tp.threadQue([&] { updateEnemyLvl1(t_deltaTime, m_enemys3); });

		tp.threadQue([&] { updateEnemyLvl1(t_deltaTime, m_enemys4); });

		tp.threadQue([&] { updateEnemyLvl1(t_deltaTime, m_enemys5); });

		tp.threadQue([&] { updateEnemyLvl1(t_deltaTime, m_enemys6); });

		tp.threadQue([&] { updateEnemyLvl1(t_deltaTime, m_enemys7); });

		tp.threadQue([&] { updateEnemyLvl1(t_deltaTime, m_enemys8); });

		tp.threadQue([&] { updateEnemyLvl1(t_deltaTime, m_enemys9); });

		break;
	case GamePlay::TWO:
		//Level Two Grid Update
		levelTwo.update(t_deltaTime);

		tp.threadQue([&] { updateEnemyLvl2(t_deltaTime, m_enemys); });
		tp.threadQue([&] { updateEnemyLvl2(t_deltaTime, m_enemys1); });
		//tp.threadQue([&] { updateEnemyLvl2(t_deltaTime, m_enemys2); });
		//tp.threadQue([&] { updateEnemyLvl2(t_deltaTime, m_enemys3); });

		break;

	case GamePlay::THREE:
		//Level Two Grid Update
		//levelThree.update(t_deltaTime);
		break;
	default:
		break;
	}


}

void GamePlay::render(sf::RenderWindow& t_window)
{
	switch (level)
	{
	case GamePlay::ONE:
		//Level One Grid Render
		levelOne.render(t_window);
		break;
	case GamePlay::TWO:
		//Level Two Grid Render
		levelTwo.render(t_window);
		break;
	case GamePlay::THREE:
		//Level Two Grid Render
		//levelThree.render(t_window);
		break;
	default:
		break;
	}


	//Draw Enemys
	renderEnemeys(m_enemys, t_window);
	renderEnemeys(m_enemys1, t_window);
	renderEnemeys(m_enemys2, t_window);
	renderEnemeys(m_enemys3, t_window);
	renderEnemeys(m_enemys4, t_window);
	renderEnemeys(m_enemys5, t_window);
	renderEnemeys(m_enemys6, t_window);
	renderEnemeys(m_enemys7, t_window);
	renderEnemeys(m_enemys8, t_window);
	renderEnemeys(m_enemys9, t_window);



	//Draw Player
	m_player.render(t_window);
}

void GamePlay::setup(sf::Font& t_font)
{
	switch (level)
	{
	case GamePlay::ONE:
		//Grid Setup
		levelOne.setup(t_font);
		generateEnemyLevel1();
		break;
	case GamePlay::TWO:
		levelTwo.setup(t_font);
		generateEnemyLevel2();
		break;
	case GamePlay::THREE:
	/*	levelThree.setup(t_font);
		generateEnemyLevel3();
		break;*/
	default:
		break;
	}
}

void GamePlay::initialise()
{
}

void GamePlay::input(sf::RenderWindow& t_window)
{
}

void GamePlay::generateEnemyLevel1()
{
	//for (int i = 0; i < 500; i++)
	//{
	//	Enemy* enemy = new Enemy();
	//	m_enemys.push_back(enemy);
	//}

	for (int i = 0; i < 50; i++)
	{
		Enemy* enemy = new Enemy();
		m_enemys.push_back(enemy);
	}
	for (int i = 0; i < 50; i++)
	{
		Enemy* enemy = new Enemy();
		m_enemys1.push_back(enemy);
	}
	for (int i = 0; i < 50; i++)
	{
		Enemy* enemy = new Enemy();
		m_enemys2.push_back(enemy);
	}
	for (int i = 0; i < 50; i++)
	{
		Enemy* enemy = new Enemy();
		m_enemys3.push_back(enemy);
	}
	for (int i = 0; i < 50; i++)
	{
		Enemy* enemy = new Enemy();
		m_enemys4.push_back(enemy);
	}
	for (int i = 0; i < 50; i++)
	{
		Enemy* enemy = new Enemy();
		m_enemys5.push_back(enemy);
	}
	for (int i = 0; i < 50; i++)
	{
		Enemy* enemy = new Enemy();
		m_enemys6.push_back(enemy);
	}
	for (int i = 0; i < 50; i++)
	{
		Enemy* enemy = new Enemy();
		m_enemys7.push_back(enemy);
	}
	for (int i = 0; i < 50; i++)
	{
		Enemy* enemy = new Enemy();
		m_enemys8.push_back(enemy);
	}
	for (int i = 0; i < 50; i++)
	{
		Enemy* enemy = new Enemy();
		m_enemys9.push_back(enemy);
	}
}
void GamePlay::generateEnemyLevel2()
{
	for (int i = 0; i < 15; i++)
	{
		Enemy* enemy = new Enemy();
		m_enemys.push_back(enemy);
	}
	for (int i = 0; i < 15; i++)
	{
		Enemy* enemy = new Enemy();
		m_enemys1.push_back(enemy);
	}
	for (int i = 0; i < 10; i++)
	{
		Enemy* enemy = new Enemy();
		m_enemys2.push_back(enemy);
	}
	for (int i = 0; i < 10; i++)
	{
		Enemy* enemy = new Enemy();
		m_enemys3.push_back(enemy);
	}
}

void GamePlay::generateEnemyLevel3()
{
	for (int i = 0; i < 500; i++)
	{
		Enemy* enemy = new Enemy();
		m_enemys.push_back(enemy);
	}
}

void GamePlay::renderEnemeys(std::vector<Enemy*> t_enemys, sf::RenderWindow &t_window)
{
	//Draw Enemys
	for (Enemy* enemy : t_enemys)
	{
		switch (level)
		{
		case GamePlay::ONE:
			if (levelOne.levelGraph.nodeIndex(enemy->getCurrentNode())->m_data.passable)
			{
				enemy->render(t_window);
			}
			break;
		case GamePlay::TWO:
			if (levelTwo.levelGraph2.nodeIndex(enemy->getCurrentNode())->m_data.passable)
			{
				enemy->render(t_window);
			}
			break;
		case GamePlay::THREE:
			//if (levelThree.levelGraph3.nodeIndex(enemy->getCurrentNode())->m_data.passable)
			//{
			//	enemy->render(t_window);
			//}
			break;
		default:
			break;
		}
	}
}

void GamePlay::updateEnemyLvl1(sf::Time t_deltaTime, std::vector<Enemy*> enemys)
{
	everyoneHasReached = false;
	std::vector<Node*> path;
	//while (!everyoneHasReached)
	//{
		static int x = 0;

		//Update Enemys
		for (Enemy* enemy : enemys)
		{
			path.clear();

			enemy->update(t_deltaTime);

			if (enemy->getCurrentNode() == m_player.getCurrentNode())
			{
				
				continue;
			}

			levelOne.levelGraph.aStar(levelOne.levelGraph.nodeIndex(enemy->getCurrentNode()), levelOne.levelGraph.nodeIndex(m_player.getCurrentNode()), path);

			//Path
			for (int i = 0; i < path.size(); i++)
			{
				if (showPath)
				{
					path.at(i)->m_data.rectangle.setFillColor(sf::Color::Magenta);
				}

				if (i == path.size() - 2)
				{
					//enemy->getRectangle()->setFillColor(sf::Color::Black);
					enemy->getRectangle()->setPosition(sf::Vector2f(path.at(i)->m_data.xPos, path.at(i)->m_data.yPos));
				}
			}
		//}
		//everyoneHasReached = true;
	}
	std::cout << "Function Finished" << std::endl;
}

void GamePlay::updateEnemyLvl2(sf::Time t_deltaTime, std::vector<Enemy*> enemys)
{
	std::cout << "ENTERING THE UPDAT ENEMY FUNCTION" << std::endl;

	//while (true)
	//{
		std::cout << "INSIDE THE WHILE LOOP" << std::endl;
		for (Enemy* enemy : enemys)
		{
			std::vector<Node*> path;
			enemy->update(t_deltaTime);

			if (enemy->getCurrentNode() == m_player.getCurrentNode())
			{
				continue;
			}

			levelTwo.levelGraph2.aStar(levelTwo.levelGraph2.nodeIndex(enemy->getCurrentNode()), levelTwo.levelGraph2.nodeIndex(m_player.getCurrentNode()), path);



			for (int i = 0; i < path.size(); i++)
			{
				if (showPath)
				{
					path.at(i)->m_data.rectangle.setFillColor(sf::Color::Magenta);
				}

				if (i == path.size() - 2)
				{
					//t_enemy.getRectangle()->setFillColor(sf::Color::Black);
					enemy->getRectangle()->setPosition(sf::Vector2f(path.at(i)->m_data.xPos, path.at(i)->m_data.yPos));
				}
			}
		}
	//}
}

void GamePlay::updateEnemyLvl2Other(sf::Time t_deltaTime, std::vector<Enemy*> enemys)
{
	std::cout << "ENTERING THE UPDAT ENEMY FUNCTION" << std::endl;

	while (true)
	{
	std::cout << "INSIDE THE WHILE LOOP" << std::endl;

	for (Enemy* enemy : enemys)
	{
		std::vector<Node*> path;
		enemy->update(t_deltaTime);

		if (enemy->getCurrentNode() == m_player.getCurrentNode())
		{
			continue;
		}

		levelTwo.levelGraph2.aStar(levelTwo.levelGraph2.nodeIndex(enemy->getCurrentNode()), levelTwo.levelGraph2.nodeIndex(m_player.getCurrentNode()), path);



		//Path

		tp.threadQue([=] { moveSquareOnPath(path, *enemy); });

		//for (int i = 0; i < path.size(); i++)
		//{
		//	if (showPath)
		//	{
		//		path.at(i)->m_data.rectangle.setFillColor(sf::Color::Magenta);
		//	}

		//	if (i == path.size() - 2)
		//	{
		//		//enemy->getRectangle()->setFillColor(sf::Color::Black);
		//		enemy->getRectangle()->setPosition(sf::Vector2f(path.at(i)->m_data.xPos, path.at(i)->m_data.yPos));
		//	}
		//}
	}
	}
}

void GamePlay::moveSquareOnPath(std::vector<Node*> t_path, Enemy &t_enemy)
{
	for (int i = 0; i < t_path.size(); i++)
	{
		if (showPath)
		{
			t_path.at(i)->m_data.rectangle.setFillColor(sf::Color::Magenta);
		}

		if (i == t_path.size() - 2)
		{
			//t_enemy.getRectangle()->setFillColor(sf::Color::Black);
			t_enemy.getRectangle()->setPosition(sf::Vector2f(t_path.at(i)->m_data.xPos, t_path.at(i)->m_data.yPos));
		}
	}
}
