#include "stdafx.h"
#include "ClickableGo.h"

ClickableGo::ClickableGo(const std::string& textId, const std::string& name)
	:GameObject(name), textureId(textId)
{

}

ClickableGo::ClickableGo(ClickableTypes oT, const std::string& textId, const std::string& name)
	:GameObject(name), textureId(textId), objectType(oT)
{
}

void ClickableGo::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(sprite, originPreset);
	Utils::SetOrigin(spriteEdge, originPreset);
}

void ClickableGo::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	sprite.setOrigin(origin);
}

void ClickableGo::Update(float dt)
{	
	auto mPos = sf::Mouse::getPosition(FRAMEWORK.Instance().GetWindow());
	auto spPos = sprite.getPosition();
	auto spSize = sprite.getTextureRect();
	if (!InputMgr::GetMouse(sf::Mouse::Button::Left) &&(float)mPos.x > spPos.x - spSize.width / 2 && (float)mPos.x < spPos.x + spSize.width / 2
		&& (float)mPos.y > spPos.y - spSize.height / 2 && (float)mPos.y < spPos.y + spSize.height / 2)
	{
		objectType = ClickableTypes::enabled;
	}
	else if (!InputMgr::GetMouse(sf::Mouse::Button::Left))
		objectType = ClickableTypes::disabled;

	if (objectType == ClickableTypes::enabled)
	{	
		spriteEdge.setOutlineColor(sf::Color::Green);		
	}
	else if (objectType == ClickableTypes::disabled)
	{
		spriteEdge.setOutlineColor(sf::Color::Transparent);
	}
}

void ClickableGo::Reset()
{
	sprite.setTexture(TEXTURE_MGR.Get(textureId));
	SetOrigin(originPreset);
	auto temp = sprite.getLocalBounds();
	auto tempLoc = sprite.getPosition();
	spriteEdge.setSize({ temp.width, temp.height });
	spriteEdge.setOrigin(temp.width / 2, temp.height / 2);
	spriteEdge.setPosition(tempLoc);
	spriteEdge.setFillColor(sf::Color::Transparent);
	spriteEdge.setOutlineColor(sf::Color::Transparent);
	spriteEdge.setOutlineThickness(5.f);
}

void ClickableGo::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	sprite.setPosition(pos);
}

void ClickableGo::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(sprite);
	window.draw(spriteEdge);
}
