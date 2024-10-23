#pragma once
#include "Scene.h"
#include "Player.h"

class SceneDev1 : public Scene
{
protected:
	std::vector<GameObject*> players;

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
};

