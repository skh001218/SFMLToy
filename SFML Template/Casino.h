#pragma once
#include "GameObject.h"
class Casino : public GameObject
{
protected:
	sf::Sprite sprite;
	std::string textureId;
	int diceNum;
	int price;

	int betCnt[5] = {0};

	sf::RectangleShape rectShape;

	sf::Text text[5];

	sf::RectangleShape betCount[5];
	std::vector<sf::Color> pColors =
	{ sf::Color::Green, sf::Color::Red, sf::Color::Blue, sf::Color::Yellow, sf::Color::Cyan };

	std::vector<sf::IntRect> casinoArea;

public:
	Casino() = default;
	virtual ~Casino() = default;
	
	Casino(const int& dice, const std::string& textId, const std::string& name = "");
	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;
	void SetScale(const sf::Vector2f& newScale) override;

	void Reset() override;
	void Update(float dt) override;
	void SetPosition(const sf::Vector2f& pos) override;
	void Draw(sf::RenderWindow& window) override;

	sf::Sprite GetSprite() { return sprite; }
	sf::RectangleShape GetRectShape() { return rectShape; }

	void PlayerBet(int idx, int count) { betCnt[idx] = count; };
};

