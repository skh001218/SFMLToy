#pragma once
#include "GameObject.h"
class Casino : public GameObject
{
protected:
	sf::Sprite sprite;
	std::string textureId;
	int diceNum;
	int price;

	std::vector<sf::IntRect> casinoArea;

public:
	Casino() = default;
	virtual ~Casino() = default;
	
	Casino(const int& dice, const std::string& textId, const std::string& name = "");
	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;
	void SetScale(const sf::Vector2f& newScale) override;

	void Reset() override;
	void SetPosition(const sf::Vector2f& pos) override;
	void Draw(sf::RenderWindow& window) override;
};

