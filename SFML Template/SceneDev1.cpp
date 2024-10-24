#include "stdafx.h"
#include "SceneDev1.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "Player.h"
#include "Casino.h"
#include "Dice.h"
#include "ClickableGo.h"
#include "RollDice.h"

SceneDev1::SceneDev1()
	:Scene(SceneIds::Dev1)
{
}

void SceneDev1::Init()
{
	std::cout << "SceneDev1::Init()" << std::endl;
	int frameWidth = 5;
	int frameHeight = 9;
	for (int i = 0; i < 6; i++)
	{
		frames.push_back(sf::IntRect(5 + i * 35, 9, 28, 28));
		frames.push_back(sf::IntRect(5 + i * 35, 55, 28, 22));
		frames.push_back(sf::IntRect(5 + i * 35, 90, 28, 30));
		frames.push_back(sf::IntRect(5 + i * 35, 132, 28, 28));
	}
	SettingObject();
	for (auto& p : players)
		p->Init();
	Scene::Init();
}

void SceneDev1::Enter()
{
	std::cout << "SceneDev1::Enter()" << std::endl;

	LoadResource();
	for (auto& p : players)
		p->Reset();
	Scene::Enter();
}

void SceneDev1::Exit()
{
	std::cout << "SceneDev1::Exit()" << std::endl;

	UnloadResource();

	Scene::Exit();
}

void SceneDev1::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		isRoll = true;
		//SCENE_MGR.ChangeScene(SceneIds::Dev2);
		rollingTime = 0;
		for (int i = 0; i < 8; i++)
		{
			std::string nm = "RollDice";
			nm += std::to_string(i + 1);
			FindGo(nm)->SetMove(true);
		}
	}
	if (isRoll)
	{
		StartAnimate(dt);
		players[currentTurn]->SetDiceList(diceNums);
	}
		
	Scene::Update(dt);
	if (InputMgr::GetKeyDown(sf::Keyboard::Numpad3))
	{
		players[currentTurn - 1]->SetTurn(false);
		currentTurn = 2;
	}
	players[currentTurn - 1]->SetTurn(true);
		
}

void SceneDev1::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	MouseMgr::Instance().Reset(window);
	MouseMgr::Instance().Draw(window);
	for (auto& p : players)
		p->Draw(window);
}

void SceneDev1::SettingObject()
{
	GameObject* obj = AddGo(new SpriteGo("graphics/background.png"));
	obj->SetOrigin(Origins::MC);
	obj->SetPosition({ 1920 / 2, 1080 / 2 });

	for (int i = 0; i < 6; i++)
	{
		GameObject* objcasino = AddGo(new Casino(i + 1, "test/casino.png"));
		objcasino->SetOrigin(Origins::MC);
		objcasino->SetPosition({ 400.f + 200 * i, 1080 * 1 / 3 });
		objcasino->SetScale({ 2, 2 });
	}

	for (int i = 0; i < 5; i++)
	{
		Player* objPlayer = new Player(i);
		objPlayer->SetPosition({ 0.f + i * 400.f, 1080.f });

		std::string na = "Player";
		na += std::to_string(i + 1);
		GameObject* dice = AddGo(new Dice(na));
		dice->SetOrigin(Origins::MC);
		dice->SetPosition({ objPlayer->GetPosition().x + 100,  objPlayer->GetPosition().y - 150 });
		GameObject* diceCount = AddGo(new TextGo("X 8",na + ""));
		diceCount->SetOrigin(Origins::ML);
		diceCount->SetPosition({ dice->GetPosition().x + 30, dice->GetPosition().y });

		players.push_back(objPlayer);
	}

	GameObject* clickObj1 = AddGo(new ClickableGo("Resources/images/note9m.png", "note9"));
	clickObj1->SetOrigin(Origins::MC);
	clickObj1->SetPosition({ 1920 / 2, 1080 / 2 });

	for (int i = 0; i < 8; i++)
	{
		std::string nm = "RollDice";
		nm += std::to_string(i + 1);
		GameObject* dices = AddGo(new RollDice("test/rollDice.png", nm));
		dices->SetOrigin(Origins::TL);
		dices->SetPosition(
			{ FRAMEWORK.Instance().GetWindow().getSize().x / 2.5f + (i % 4) * FRAMEWORK.Instance().GetWindow().getSize().x / 20.f,
			FRAMEWORK.Instance().GetWindow().getSize().y / 2.f + (i / 4) * FRAMEWORK.Instance().GetWindow().getSize().y / 10.f });
		dices->SetScale({ 2, 2 });
		dices->SetMove(false);
		dices->SetTextureRect(frames[0]);
	}
	GameObject* objText2 = AddGo(new TextGo("Current Turn:\n   \"Player " + std::to_string((int)TempPlayerNo::player1 + 1) + "\""));
	objText2->SetOrigin(Origins::TC);
	objText2->SetPosition({ (1920 / 4), 0 });

	

	GameObject* objText = AddGo(new TextGo("SceneDev1"));
	objText->SetOrigin(Origins::TC);
	objText->SetPosition({ 1920 / 2, 0 });
}

void SceneDev1::LoadResource()
{
	TEXTURE_MGR.Load("graphics/background.png");
	TEXTURE_MGR.Load("test/casino.png");
	TEXTURE_MGR.Load("graphics/background.png");
	TEXTURE_MGR.Load("Resources/images/customCursor.png");
	TEXTURE_MGR.Load("Resources/images/cursorActivated.png");
	TEXTURE_MGR.Load("Resources/images/note1m.png");
	TEXTURE_MGR.Load("Resources/images/note2m.png");
	TEXTURE_MGR.Load("Resources/images/note3m.png");
	TEXTURE_MGR.Load("Resources/images/note4m.png");
	TEXTURE_MGR.Load("Resources/images/note5m.png");
	TEXTURE_MGR.Load("Resources/images/note6m.png");
	TEXTURE_MGR.Load("Resources/images/note7m.png");
	TEXTURE_MGR.Load("Resources/images/note8m.png");
	TEXTURE_MGR.Load("Resources/images/note9m.png");
	TEXTURE_MGR.Load("test/rollDice.png");
}

void SceneDev1::UnloadResource()
{
	TEXTURE_MGR.Unload("graphics/background.png");
	TEXTURE_MGR.Unload("test/casino.png");
	TEXTURE_MGR.Unload("graphics/background.png");
	TEXTURE_MGR.Unload("Resources/images/customCursor.png");
	TEXTURE_MGR.Unload("Resources/images/cursorActivated.png");
	TEXTURE_MGR.Unload("Resources/images/note1m.png");
	TEXTURE_MGR.Unload("Resources/images/note2m.png");
	TEXTURE_MGR.Unload("Resources/images/note3m.png");
	TEXTURE_MGR.Unload("Resources/images/note4m.png");
	TEXTURE_MGR.Unload("Resources/images/note5m.png");
	TEXTURE_MGR.Unload("Resources/images/note6m.png");
	TEXTURE_MGR.Unload("Resources/images/note7m.png");
	TEXTURE_MGR.Unload("Resources/images/note8m.png");
	TEXTURE_MGR.Unload("Resources/images/note9m.png");
	TEXTURE_MGR.Unload("test/rollDice.png");
}

void SceneDev1::StartAnimate(float dt)
{
	frameTime += dt;
	rollingTime += dt;

	if (rollingTime >= 1.f)
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
