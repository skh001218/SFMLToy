#include "stdafx.h"
#include "SceneDev1.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "ClickableGo.h"

SceneDev1::SceneDev1()
	:Scene(SceneIds::Dev1)
{

}

void SceneDev1::Init()
{
	std::cout << "SceneDev1::Init()" << std::endl;

	GameObject* obj = AddGo(new SpriteGo("graphics/background.png"));
	obj->SetOrigin(Origins::p22);
	obj->SetPosition({ 1920 / 2, 1080 / 2 });

	GameObject* objText = AddGo(new TextGo("SceneDev1"));
	objText->SetOrigin(Origins::p24);
	objText->SetPosition({ 1920 / 2, 0 });

	GameObject* objText2 = AddGo(new TextGo("Current Turn:\n   \"Player "+std::to_string((int)TempPlayerNo::player1+1)+"\""));
	objText2->SetOrigin(Origins::p24);
	objText2->SetPosition({ (1920 / 4), 0 });

	GameObject* clickObj1 = AddGo(new ClickableGo("Resources/images/note9m.png", "note9"));
	clickObj1->SetOrigin(Origins::p22);
	clickObj1->SetPosition({ 1920 / 2, 1080 / 2 });

	MouseMgr::Instance().Init();

	Scene::Init();
}

void SceneDev1::Enter()
{
	std::cout << "SceneDev1::Enter()" << std::endl;

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

	Scene::Enter();
}

void SceneDev1::Exit()
{
	std::cout << "SceneDev1::Exit()" << std::endl;

	TEXTURE_MGR.Unload("graphics/background.png");

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
