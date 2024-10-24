#include "stdafx.h"
#include "Player.h"

Player::Player(int num)
	:score(0), colorNum(num)
{
	rectShape = sf::RectangleShape({ 300.f, 80.f });
}

void Player::SetScore(int score)
{
	this->score = score;
}

int Player::GetScore() const
{
	return score;
}

void Player::SetOrigin(Origins preset)
{
	sf::FloatRect rect = rectShape.getLocalBounds();
	sf::Vector2f newOrigin(rect.width, rect.height);
	newOrigin.x *= ((int)preset % 3) * 0.5f;
	newOrigin.y *= ((int)preset / 3) * 0.5f;
	origin = newOrigin;
	rectShape.setOrigin(origin);
}

void Player::SetOrigin(const sf::Vector2f& newOrigin)
{
	rectShape.setOrigin(newOrigin);
	origin = rectShape.getOrigin();
}

void Player::Reset()
{
	score = 0;
	
	rectShape.setFillColor(pColors[colorNum]);
	SetOrigin({ 0.f, 80.f });
	
}

void Player::SetPosition(const sf::Vector2f& pos)
{
	rectShape.setPosition(pos);
	position = pos;
}

void Player::Init()
{
	
}

void Player::Release()
{
}

void Player::Update(float dt)
{
}

void Player::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(rectShape);
}