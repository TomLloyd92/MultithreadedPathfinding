#include "Player.h"



Player::Player()
{
	m_playerShape.setSize(sf::Vector2f(TILE_WIDTH, TILE_WIDTH));
	m_playerShape.setFillColor(sf::Color::Red);
	m_playerShape.setPosition(sf::Vector2f(21 * TILE_WIDTH, 21 * TILE_WIDTH));
}

Player::~Player()
{
}

void Player::update(sf::Time t_deltaTime)
{
	currentNodeUpdate();

}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_playerShape);
}

void Player::setup(sf::Font& t_font)
{

}

void Player::initialise()
{
}

void Player::currentNodeUpdate()
{
	m_currentNode = floor((m_playerShape.getPosition().x + (TILE_WIDTH / 2)) / TILE_WIDTH) + (floor((m_playerShape.getPosition().y + (TILE_WIDTH / 2)) / TILE_WIDTH) *  30);
}
