#include "stdafx.h"

void MouseMgr::Init()
{
	mouseSprite.setOrigin({ 0.f,0.f });
}

void MouseMgr::Reset(const sf::RenderWindow& window)
{
	int mPosX = sf::Mouse::getPosition(window).x;
	int mPosY = sf::Mouse::getPosition(window).y;
	mouseSprite.setPosition(mPosX, mPosY);
	mouseSprite.setTexture(TEXTURE_MGR.Get("Resources/images/cursorActivated.png"));
	if ((int)objectType == 0)
		mouseSprite.setTexture(TEXTURE_MGR.Get("Resources/images/customCursor.png"));
}

void MouseMgr::Draw(sf::RenderWindow& window)
{
	window.draw(mouseSprite);
}

sf::Vector2i MouseMgr::getMousePosition()
{
	return mousePosition;
}
