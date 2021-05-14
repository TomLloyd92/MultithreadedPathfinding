#include "Enemy.h"

Enemy::Enemy()
{
	m_enemyShape.setSize(sf::Vector2f(TILE_WIDTH, TILE_WIDTH));
	m_enemyShape.setFillColor(sf::Color::Yellow);
}

Enemy::~Enemy()
{
}

void Enemy::update(sf::Time t_deltaTime)
{
	currentNodeUpdate();
}

void Enemy::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_enemyShape);
}

void Enemy::setup(sf::Font& t_font)
{
}

void Enemy::initialise()
{
}

void Enemy::currentNodeUpdate()
{
	m_currentNode = floor((m_enemyShape.getPosition().x + (TILE_WIDTH / 2)) / TILE_WIDTH) + (floor((m_enemyShape.getPosition().y + (TILE_WIDTH / 2)) / TILE_WIDTH) * rows);
}
