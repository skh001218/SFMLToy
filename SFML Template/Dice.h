#pragma once

class Dice : public GameObject
{
protected:
	int num;
	sf::Sprite sprite;
	std::string textureId;
	sf::Color color;
	int count;

public:
	Dice() = default;
	virtual ~Dice() = default;

	Dice(const std::string& name = "");
	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;
	void SetScale(const sf::Vector2f& newScale) override;

	void Init() override;

	void Reset() override;
	void SetPosition(const sf::Vector2f& pos) override;
	void Draw(sf::RenderWindow& window) override;
};

