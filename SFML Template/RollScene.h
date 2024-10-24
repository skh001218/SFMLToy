#pragma once
#include "Scene.h"
class RollScene : public Scene
{
protected:
	std::vector<sf::IntRect> frames;
	sf::Sprite sprite;

	float frameTime = 0.0f;
	int currentFrame = 0;
	float rollingTime = 0;

	std::vector<int> diceNums;

public:
	RollScene();
	~RollScene() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SettingObject();
	void LoadResource();
	void UnloadResource();

	void StartAnime();

	std::vector<int> GetDiceNums() { return diceNums; }
};

