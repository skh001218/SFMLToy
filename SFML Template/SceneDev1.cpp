#include "stdafx.h"
#include "SceneDev1.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "Player.h"
#include "Casino.h"
#include "Dice.h"
#include "ClickableGo.h"

SceneDev1::SceneDev1()
	:Scene(SceneIds::Dev1)
{
}

void SceneDev1::Init()
{
	std::cout << "SceneDev1::Init()" << std::endl;
	SettingObject();
	Scene::Init();
}

void SceneDev1::Enter()
{
	std::cout << "SceneDev1::Enter()" << std::endl;

	LoadResource();


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
	Scene::Update(dt);
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev2);
	}	
}

void SceneDev1::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	MouseMgr::Instance().Reset(window);
	MouseMgr::Instance().Draw(window);
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
		GameObject* objPlayer = AddGo(new Player(i));
		objPlayer->SetPosition({ 0.f + i * 400.f, 1080.f });

		std::string na = "Player";
		na += std::to_string(i + 1);
		GameObject* dice = AddGo(new Dice(na));
		dice->SetOrigin(Origins::MC);
		dice->SetPosition({ objPlayer->GetPosition().x + 100,  objPlayer->GetPosition().y - 150 });
		GameObject* diceCount = AddGo(new TextGo("X 8"));
		diceCount->SetOrigin(Origins::ML);
		diceCount->SetPosition({ dice->GetPosition().x + 30, dice->GetPosition().y });

		players.push_back(objPlayer);
	}

	GameObject* objText2 = AddGo(new TextGo("Current Turn:\n   \"Player " + std::to_string((int)TempPlayerNo::player1 + 1) + "\""));
	objText2->SetOrigin(Origins::p24);
	objText2->SetPosition({ (1920 / 4), 0 });

	GameObject* clickObj1 = AddGo(new ClickableGo("Resources/images/note9m.png", "note9"));
	clickObj1->SetOrigin(Origins::p22);
	clickObj1->SetPosition({ 1920 / 2, 1080 / 2 });

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
}

void SceneDev1::UnloadResource()
{
	TEXTURE_MGR.Unload("graphics/background.png");
	TEXTURE_MGR.Unload("test/casino.png");
}
