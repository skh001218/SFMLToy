#pragma once
#include "Scene.h"
#include "Player.h"

class SceneDev1 : public Scene
{
protected:
	std::vector<Player*> players;
	std::vector<sf::IntRect> frames;
	sf::Sprite sprite;

	float frameTime = 0.0f;
	int currentFrame = 0;
	float rollingTime = 0;

	bool isRoll = false;
	bool isBet = false;
	int currentTurn = 1;

	std::vector<int> diceNums;


public:
	SceneDev1();
	~SceneDev1() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SettingObject();
	void LoadResource();
	void UnloadResource();

	void StartAnimate(float dt);
	void BetCasino();
	void BettingCasino(int casino);
};

