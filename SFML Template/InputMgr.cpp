#include "stdafx.h"

std::list<sf::Keyboard::Key> InputMgr::downList;
std::list<sf::Keyboard::Key> InputMgr::heldList;
std::list<sf::Keyboard::Key> InputMgr::upList;
std::list<sf::Mouse::Button> InputMgr::mDownList;
std::list<sf::Mouse::Button> InputMgr::mHeldList;
std::list<sf::Mouse::Button> InputMgr::mUpList;

void InputMgr::Clear()
{
	downList.clear();
	upList.clear();
	mDownList.clear();
	mUpList.clear();
}

void InputMgr::UpdateEvent(const sf::Event& ev)
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		if (std::find(heldList.begin(), heldList.end(), ev.key.code) == heldList.end())
		{
			heldList.push_back(ev.key.code);
			downList.push_back(ev.key.code);
		}
		break;
	case sf::Event::KeyReleased:
		heldList.remove(ev.key.code);
		upList.push_back(ev.key.code);
		break;
	case sf::Event::MouseButtonPressed:
		if (std::find(mHeldList.begin(), mHeldList.end(), ev.mouseButton.button) == mHeldList.end())
		{
			mHeldList.push_back(ev.mouseButton.button);
			mDownList.push_back(ev.mouseButton.button);
		}
		break;
	case sf::Event::MouseButtonReleased:
		mHeldList.remove(ev.mouseButton.button);
		mUpList.remove(ev.mouseButton.button);
	}
}

bool InputMgr::GetKeyDown(sf::Keyboard::Key key)
{
	return std::find(downList.begin(), downList.end(), key) != downList.end();;
}

bool InputMgr::GetKey(sf::Keyboard::Key key)
{
	return std::find(heldList.begin(), heldList.end(), key) != heldList.end();
}

bool InputMgr::GetKeyUp(sf::Keyboard::Key key)
{
	return std::find(upList.begin(), upList.end(), key) != upList.end();
}

bool InputMgr::GetMouseDown(sf::Mouse::Button button)
{
	return std::find(mDownList.begin(), mDownList.end(), button) != mDownList.end();
}

bool InputMgr::GetMouse(sf::Mouse::Button button)
{
	return std::find(mHeldList.begin(), mHeldList.end(), button) != mHeldList.end();
}

bool InputMgr::GetMouseUp(sf::Mouse::Button button)
{
	return std::find(mUpList.begin(), mUpList.end(), button) != mUpList.end();
}
