#include "stdafx.h"
#include "Framework.h"
#include "SpriteGo.h"

void Framework::Init(int width, int height, const const std::string& name)
{
	window.create(sf::VideoMode(width, height), name);
    SCENE_MGR.Init();
    window.setMouseCursorVisible(false);
}

void Framework::Do()
{

    while (window.isOpen())
    {

        sf::Time dt = clock.restart();
        realDeltaTime = deltaTime = dt.asSeconds();
        deltaTime *= timeScale;
        realTime += realDeltaTime;
        time += deltaTime;


        //�̺�Ʈ ����
        InputMgr::Clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                
                }


            InputMgr::UpdateEvent(event);
        }
        //������Ʈ
        SCENE_MGR.Update(deltaTime);
    
        
        window.clear();
        //��ο�
        SCENE_MGR.Draw(window);

        window.display();
    }
}

void Framework::Release()
{
}
