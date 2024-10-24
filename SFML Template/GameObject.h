#pragma once
class GameObject
{
protected:
	std::string name;

	bool active = true;
	bool move = true;
	sf::Vector2f position;
	Origins originPreset;
	sf::Vector2f origin;
	sf::Vector2f scale;

	ClickableTypes objectType = ClickableTypes::disabled;

public:
	GameObject(const std::string& name = "");
	virtual ~GameObject() = default;

	const std::string& GetName() const { return name; }
	void SetName(const std::string& n) { name = n; }

	bool IsActive() const { return active; }
	void SetActive(bool a) { active = a; }

	bool IsMove() const { return move; }
	void SetMove(bool a) { move = a; }

	sf::Vector2f GetPosition() { return position; }
	virtual void SetPosition(const sf::Vector2f& pos) { position = pos; }

	sf::Vector2f GetOrigin() { return origin; }
	virtual void SetOrigin(Origins preset);
	virtual void SetOrigin(const sf::Vector2f& newOrigin)
	{
		origin = newOrigin;
		originPreset = Origins::Custom;
	}
	virtual void SetScale(const sf::Vector2f& newOrigin);
	virtual void SetTextureRect(sf::IntRect rect);

	virtual void Init();
	virtual void Release();

	virtual void Reset();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);
	
};

