#pragma once
#include "Singleton.h"

class MouseMgr : public Singleton<MouseMgr>
{
	friend Singleton<MouseMgr>;
	
private:
	sf::Vector2i mousePosition;
	sf::Sprite mouseSprite;
	bool inWindow = true;
	ObjectType objectType = ObjectType::defaultOJ;
	
	MouseMgr() = default;
	virtual ~MouseMgr()= default;
	MouseMgr(const MouseMgr&) = delete;
	MouseMgr& operator=(const MouseMgr&) = delete;

public:
	void Init();
	void Reset(const sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);


};

