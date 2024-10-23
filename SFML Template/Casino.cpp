#include "stdafx.h"
#include "Casino.h"

Casino::Casino(const int& dice, const std::string& textId, const std::string& name)
	:diceNum(dice), textureId(textId), price(0)
{
	casinoArea.push_back({ 12, 3, 137, 76 });
	casinoArea.push_back({ 12, 91, 140, 78 });
	casinoArea.push_back({ 157, 4, 141, 80 });
	casinoArea.push_back({ 155, 93, 142, 78 });
	casinoArea.push_back({ 298, 4, 141, 83 });
	casinoArea.push_back({ 302, 96, 141, 79 });
}

void Casino::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(sprite, originPreset);
}

void Casino::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	sprite.setOrigin(origin);
}

void Casino::SetScale(const sf::Vector2f& newScale)
{
	scale = newScale;
	sf::Vector2f originScale = sprite.getScale();
	sprite.setScale({ originScale.x * scale.x, originScale.y * scale.y });
	sprite.setTextureRect(casinoArea[diceNum-1]);
	sprite.setRotation(270.f);
}

void Casino::Reset()
{
	sprite.setTexture(TEXTURE_MGR.Get(textureId));
	SetOrigin(originPreset);
}

void Casino::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	sprite.setPosition(pos);
}

void Casino::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(sprite);
}
