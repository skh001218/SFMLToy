#pragma once
#include "GameObject.h"
class Player : public GameObject
{
protected:
	int score;
	sf::RectangleShape rectShape;
	sf::Vector2f origin;
	bool turn = false;
	bool isRolled = false;

	sf::Text text;

	int colorNum;
	std::vector<sf::Color> pColors = 
		{ sf::Color::Green, sf::Color::Red, sf::Color::Blue, sf::Color::Yellow, sf::Color::Cyan };

	std::vector<int> diceList;
	int betCasino[6] = { 0 };

public:
	Player() = default;
	virtual ~Player() = default;

	Player(int);

	void SetScore(int score);
	int GetScore() const;

	void SetTurn(bool tf);
	int GetTurn() const;

	void SetDiceList(std::vector<int> diceList) { this->diceList = diceList; };
	void SetDiceBet(int index) { diceList[index] = -1; };
	std::vector<int> GetDataList() const { return diceList; }

	void SetIsRolled(bool tf) { isRolled = tf; };
	int GetIsRolled() const { return isRolled; }
	void SetBetting(int index);

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;
	void SetPosition(const sf::Vector2f& pos) override;

	void Init() override;
	void Release() override;

	void Reset() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

