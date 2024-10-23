#pragma once
#include "GameObject.h"
class ClickableGo : public GameObject
{
protected:
	sf::Sprite sprite;
	sf::Sprite spriteEdge;
	std::string textureId;
	ObjectType objectType = ObjectType::ClickableOJ;

public:
	ClickableGo() = default;
	~ClickableGo() = default;

	ClickableGo(const std::string& textId, const std::string& name = "");

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void Reset() override;
	void SetPosition(const sf::Vector2f& pos) override;
	void Draw(sf::RenderWindow& window) override;







};

