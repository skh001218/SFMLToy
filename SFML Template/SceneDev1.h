#pragma once
#include "Scene.h"
class SceneDev1 : public Scene
{
protected:
	int i = 0;
public:
	SceneDev1();
	~SceneDev1() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

