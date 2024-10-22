#include "stdafx.h"
#include "TextGo.h"

TextGo::TextGo(const std::string& textInfo, const std::string& font, int textSize)
	:GameObject(textInfo), textInfo(textInfo), font(font), textSize(textSize)
{
}

void TextGo::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(text, originPreset);
}

void TextGo::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	text.setOrigin(origin);
}

void TextGo::Reset()
{
	FONT_MGR.Load(font);
	text.setFont(FONT_MGR.Get(font));
	text.setString(textInfo);
	text.setFillColor(sf::Color::White);
	SetOrigin(originPreset);
}

void TextGo::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	text.setPosition(pos);
}

void TextGo::Draw(sf::RenderWindow& window)
{
	GameObject::Draw(window);
	window.draw(text);
}
