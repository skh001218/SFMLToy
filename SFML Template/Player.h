#pragma once
#include "GameObject.h"
class Player : public GameObject
{
protected:
	int score;
	sf::RectangleShape rectShape;
	sf::Vector2f origin;

	int colorNum;
	std::vector<sf::Color> pColors = 
		{ sf::Color::Green, sf::Color::Red, sf::Color::Blue, sf::Color::Yellow, sf::Color::Cyan };

public:
	Player() = default;
	virtual ~Player() = default;

	Player(int);

	void SetScore(int score);
	int GetScore() const;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;
	void SetPosition(const sf::Vector2f& pos) override;

	void Init() override;
	void Release() override;

	void Reset() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

