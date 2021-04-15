#include "Player.h"



Player::Player()
{
}

Player::~Player()
{
}

void Player::update(sf::Time t_deltaTime)
{


}

void Player::render(sf::RenderWindow& t_window)
{
}

void Player::setup(sf::Font& t_font)
{

}

void Player::initialise()
{
}

void Player::currentNodeUpdate()
{
	m_currentNode = floor((pos.x + (TILE_WIDTH / 2)) / TILE_WIDTH) + (floor((pos.y + (TILE_WIDTH / 2)) / TILE_WIDTH) *  30);
}
