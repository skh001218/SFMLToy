#include "stdafx.h"
#include "RollDice.h"

RollDice::RollDice(const std::string& textId, const std::string& name)
	:GameObject(name), textureId(textId)
{
}

void RollDice::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(sprite, originPreset);
}

void RollDice::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	sprite.setOrigin(origin);
}

void RollDice::SetTextureRect(sf::IntRect rect)
{
	sprite.setTextureRect(rect);
}

void RollDice::SetScale(const sf::Vector2f& newOrigin)
{
	sprite.setScale(newOrigin);
}

void RollDice::Reset()
{
	sprite.setTexture(TEXTURE_MGR.Get(textureId));
	SetOrigin(originPreset);
}

void RollDice::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	sprite.setPosition(pos);
}

void RollDice::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(sprite);
}
