#include "Gameplay.h"

GamePlay::GamePlay()
{
}

GamePlay::~GamePlay()
{
}

void GamePlay::update(sf::Time t_deltaTime, sf::RenderWindow& t_window)
{
	levelOne.update(t_deltaTime);
}

void GamePlay::render(sf::RenderWindow& t_window)
{
	levelOne.render(t_window);
}

void GamePlay::setup(sf::Font& t_font)
{
	levelOne.setup(t_font);
}

void GamePlay::initialise()
{
}

void GamePlay::input(sf::RenderWindow& t_window)
{
}
