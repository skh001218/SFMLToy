#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(const std::string& name)
	:name(name)
{
}

void GameObject::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = { 0.f, 0.f };
}

void GameObject::SetScale(const sf::Vector2f& newScale)
{
	scale = newScale;
}

void GameObject::SetTextureRect(sf::IntRect rect)
{
}

void GameObject::Init()
{
}

void GameObject::Release()
{
}

void GameObject::Reset()
{
}

void GameObject::Update(float dt)
{
}

void GameObject::Draw(sf::RenderWindow& window)
{
}
