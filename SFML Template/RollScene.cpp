#include "stdafx.h"
#include "RollScene.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "Player.h"
#include "Casino.h"
#include "Dice.h"
#include "RollDice.h"

RollScene::RollScene()
	:Scene(SceneIds::Dev1)
{
	int frameWidth = 5;
	int frameHeight = 9;
	for (int i = 0; i < 6; i++)
	{
		frames.push_back(sf::IntRect(5 + i * 35, 9, 28, 28));
		frames.push_back(sf::IntRect(5 + i * 35, 55, 28, 22));
		frames.push_back(sf::IntRect(5 + i * 35, 90, 28, 30));
		frames.push_back(sf::IntRect(5 + i * 35, 132, 28, 28));
	}
	
}

void RollScene::Init()
{
	std::cout << "RollScene::Init()" << std::endl;

	SettingObject();

	Scene::Init();
}

void RollScene::Enter()
{
	std::cout << "RollScene::Enter()" << std::endl;

	LoadResource();

	Scene::Enter();
}

void RollScene::Exit()
{
	std::cout << "SceneDev1::Exit()" << std::endl;

	UnloadResource();

	Scene::Exit();
}

void RollScene::Update(float dt)
{
	Scene::Update(dt);
	frameTime += dt;
	rollingTime += dt;

	if (rollingTime >= 2.f)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(0, 5);
		for (int i = 0; i < 8; i++)
		{
			int ran = dis(gen);
			std::string nm = "RollDice";
			nm += std::to_string(i + 1);
			if (!FindGo(nm)->IsMove())
				continue;
			diceNums.push_back(ran + 1);
			FindGo(nm)->SetTextureRect(frames[(ran * 4)]);
			
			FindGo(nm)->SetMove(false);
		}
		return;
	}
	if (frameTime >= 0.1)
	{
		currentFrame = (currentFrame + 1) % frames.size();
		for (int i = 0; i < 8; i++)
		{
			std::string nm = "RollDice";
			nm += std::to_string(i + 1);
			FindGo(nm)->SetTextureRect(frames[currentFrame]);
			
		}
		frameTime = 0;
	}
	
}

void RollScene::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

void RollScene::SettingObject()
{
	GameObject* obj = AddGo(new SpriteGo("test/background.png"));
	obj->SetOrigin(Origins::MC);
	obj->SetPosition({ FRAMEWROK.Instance().GetWindowSize().x / 2.f, FRAMEWROK.Instance().GetWindowSize().y / 2.f });

	for (int i = 0; i < 8; i++)
	{
		std::string nm = "RollDice";
		nm += std::to_string(i + 1);
		GameObject* dices = AddGo(new RollDice("test/rollDice.png", nm));
		dices->SetOrigin(Origins::TL);
		dices->SetPosition(
			{ FRAMEWROK.Instance().GetWindowSize().x / 4.f + (i % 4) * FRAMEWROK.Instance().GetWindowSize().x / 8.f,
			FRAMEWROK.Instance().GetWindowSize().y / 4.f + (i / 4) * FRAMEWROK.Instance().GetWindowSize().y / 4.f });
		dices->SetScale({ 3, 3 });
	}
	

}

void RollScene::LoadResource()
{
	TEXTURE_MGR.Load("test/background.png");
	TEXTURE_MGR.Load("test/rollDice.png");
}

void RollScene::UnloadResource()
{
	TEXTURE_MGR.Unload("test/background.png");
	TEXTURE_MGR.Unload("test/rollDice.png");
}

void RollScene::StartAnime()
{
}
