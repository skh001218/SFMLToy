#pragma once
#include "stdafx.h"
class SpriteGo : public GameObject
{
protected:
	sf::Sprite sprite;
	std::string textureId;

public:
	SpriteGo() = default;
	~SpriteGo() = default;

	SpriteGo(const std::string& textId, const std::string& name = "");

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void SetTextureRect(sf::IntRect rect) override;
	void SetScale(const sf::Vector2f& newOrigin) override;

	void Reset() override;
	void SetPosition(const sf::Vector2f& pos) override;
	void Draw(sf::RenderWindow& window) override;
};

