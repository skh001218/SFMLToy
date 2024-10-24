#include "stdafx.h"
#include "Casino.h"

Casino::Casino(const int& dice, const std::string& textId, const std::string& name)
	:GameObject(name),diceNum(dice), textureId(textId), price(0)
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
	//sprite.setRotation(270.f);
}

void Casino::Reset()
{

	rectShape = sf::RectangleShape({ sprite.getGlobalBounds().width, sprite.getGlobalBounds().height });
	rectShape.setPosition(sprite.getGlobalBounds().left, sprite.getGlobalBounds().top);
	rectShape.setFillColor(sf::Color::Transparent);
	rectShape.setOutlineThickness(10);

	sprite.setTexture(TEXTURE_MGR.Get(textureId));
	SetOrigin(originPreset);

	for (int i = 0; i < _countof(betCount); i++)
	{
		betCount[i] = sf::RectangleShape({70, 30});
		betCount[i].setPosition(sprite.getGlobalBounds().left + 100, 
			sprite.getGlobalBounds().top + 170.f + 40.f * i);
		betCount[i].setFillColor(pColors[i]);

		FONT_MGR.Load("fonts/KOMIKAP_.ttf");
		text[i].setFont(FONT_MGR.Get("fonts/KOMIKAP_.ttf"));
		text[i].setString("0");
		text[i].setFillColor(sf::Color::Black); 
		text[i].setPosition(betCount[i].getPosition().x + betCount[i].getSize().x / 2 - 100.f + 100,
			betCount[i].getPosition().y + 30.f - betCount[i].getSize().y / 2 - 1.f * i);
		text[i].setOrigin(text[i].getLocalBounds().left + text[i].getLocalBounds().width / 2,
			text[i].getLocalBounds().top + text[i].getLocalBounds().height / 2);
	}

	
}

void Casino::Update(float dt)
{
	for (int i = 0; i < _countof(betCount); i++)
	{
		text[i].setString(std::to_string(betCnt[i]));
	}
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
	for (int i = 0; i < _countof(betCount); i++)
	{
		window.draw(betCount[i]);
		window.draw(text[i]);
	}
	//window.draw(rectShape);
}
