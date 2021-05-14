#include "Gameplay.h"

GamePlay::GamePlay()
{
}

GamePlay::~GamePlay()
{
}

void GamePlay::update(sf::Time t_deltaTime, sf::RenderWindow& t_window)
{
	path.clear();
	m_player.update(t_deltaTime);

	switch (level)
	{
	case GamePlay::ONE:
		//Level One Grid Update
		levelOne.update(t_deltaTime);

		//Update Enemys
		for (Enemy *enemy : m_enemys)
		{

			enemy->update(t_deltaTime);
			levelOne.levelGraph.aStar(levelOne.levelGraph.nodeIndex(enemy->getCurrentNode()), levelOne.levelGraph.nodeIndex(m_player.getCurrentNode()), path);

			//Path
			for (int i = 0; i < path.size(); i++)
			{
				path.at(i)->m_data.rectangle.setFillColor(sf::Color::Magenta);
				if (i == path.size() - 2)
				{
					//enemy->getRectangle()->setFillColor(sf::Color::Black);
					enemy->getRectangle()->setPosition(sf::Vector2f(path.at(i)->m_data.xPos, path.at(i)->m_data.yPos));
				}
			}
		}

		break;
	case GamePlay::TWO:
		//Level Two Grid Update
		//levelTwo.update(t_deltaTime);
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
		//levelTwo.render(t_window);
		break;
	case GamePlay::THREE:
		//Level Two Grid Render
		//levelThree.render(t_window);
		break;
	default:
		break;
	}


	//Draw Enemys
	for (Enemy* enemy : m_enemys)
	{
		enemy->render(t_window);
	}


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
		//levelTwo.setup(t_font);
		break;
	case GamePlay::THREE:
		//levelThree.setup(t_font);
		break;
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
	for (int i = 0; i < 10; i++)
	{
		Enemy* enemy = new Enemy();
		m_enemys.push_back(enemy);
	}
}
