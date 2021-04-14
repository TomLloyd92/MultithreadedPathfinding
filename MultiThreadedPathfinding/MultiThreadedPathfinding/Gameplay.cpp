#include "Gameplay.h"

GamePlay::GamePlay()
{
}

GamePlay::~GamePlay()
{
}

void GamePlay::update(sf::Time t_deltaTime, sf::RenderWindow& t_window)
{


	switch (level)
	{
	case GamePlay::ONE:
		//Level One Grid Update
		levelOne.update(t_deltaTime);
		break;
	case GamePlay::TWO:
		//Level Two Grid Update
		levelTwo.update(t_deltaTime);
		break;
	case GamePlay::THREE:
		//Level Two Grid Update
		levelThree.update(t_deltaTime);
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
		levelThree.render(t_window);
		break;
	default:
		break;
	}

}

void GamePlay::setup(sf::Font& t_font)
{
	switch (level)
	{
	case GamePlay::ONE:
		//Grid Setup
		levelOne.setup(t_font);
		break;
	case GamePlay::TWO:
		levelTwo.setup(t_font);
		break;
	case GamePlay::THREE:
		levelThree.setup(t_font);
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
