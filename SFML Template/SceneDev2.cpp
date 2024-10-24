#include "stdafx.h"
#include "SceneDev2.h"
#include "SpriteGo.h"
#include "TextGo.h"

SceneDev2::SceneDev2()
	:Scene(SceneIds::Dev2)
{
}

void SceneDev2::Init()
{
	std::cout << "SceneDev2::Init()" << std::endl;

	AddGo(new SpriteGo("graphics/player.png"));

	GameObject* objText = AddGo(new TextGo("SceneDev2"));
	objText->SetOrigin(Origins::p24);
	objText->SetPosition({ 1920 / 2, 0 });

	Scene::Init();
}

void SceneDev2::Enter()
{
	std::cout << "SceneDev2::Enter()" << std::endl;
	
	TEXTURE_MGR.Load("graphics/player.png");

	Scene::Enter();
}

void SceneDev2::Exit()
{
	std::cout << "SceneDev2::Exit()" << std::endl;

	TEXTURE_MGR.Unload("graphics/player.png");

	Scene::Exit();
}

void SceneDev2::Update(float dt)
{
	Scene::Update(dt);
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Dev1);
	}
}

void SceneDev2::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
