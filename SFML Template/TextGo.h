#pragma once
#include "GameObject.h"
class TextGo : public GameObject
{
protected:
	sf::Text text;
	std::string font;
	std::string textInfo;
	int textSize;
	
public:
	TextGo() = default;
	virtual ~TextGo() = default;

	TextGo(const std::string& textInfo, const std::string& name = "", 
		const std::string & font = "fonts/KOMIKAP_.ttf", int textSize = 50);

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void Reset() override;
	void SetPosition(const sf::Vector2f& pos) override;
	void Draw(sf::RenderWindow& window) override;
};

