#pragma once
#include "GameObject.h"
class ClickableGo : public GameObject
{
protected:
	sf::Sprite sprite;
	sf::RectangleShape spriteEdge;
	std::string textureId;
	ClickableTypes objectType = ClickableTypes::enabled;

public:
	ClickableGo() = default;
	~ClickableGo() = default;

	ClickableGo(const std::string& textId, const std::string& name = "");
	ClickableGo(ClickableTypes oT, const std::string& textId, const std::string& name = "");

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void Update(float dt) override;
	void Reset() override;
	void SetPosition(const sf::Vector2f& pos) override;
	void Draw(sf::RenderWindow& window) override;

};

