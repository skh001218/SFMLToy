#include "stdafx.h"
#include "Dice.h"

Dice::Dice(const std::string& name)
	: GameObject(name), num(0), textureId("test/dice.png"), count(8)
{
}

void Dice::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(sprite, originPreset);
}

void Dice::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	sprite.setOrigin(origin);
}

void Dice::SetScale(const sf::Vector2f& newScale)
{
	scale = newScale;
	sf::Vector2f originScale = sprite.getScale();
	sprite.setScale({ originScale.x * scale.x, originScale.y * scale.y });
	sprite.setRotation(270.f);
}

void Dice::Init()
{
	
}

void Dice::Reset()
{
	TEXTURE_MGR.Load(textureId);
	sprite.setTexture(TEXTURE_MGR.Get(textureId));
	sprite.setTextureRect({ 1, 33, 22, 29 });
	sf::Vector2f originScale = sprite.getScale();
	sprite.setScale({ originScale.x * 2, originScale.y * 2 });
	SetOrigin(originPreset);
	
}

void Dice::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	sprite.setPosition(pos);
}

void Dice::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(sprite);
}
