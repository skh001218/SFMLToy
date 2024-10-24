#include "stdafx.h"
#include "Utils.h"

sf::Vector2f Utils::SetOrigin(sf::Sprite& obj, Origins preset)
{
    sf::FloatRect rect = obj.getLocalBounds();
    sf::Vector2f newOrigin(rect.width, rect.height);
    newOrigin.x *= ((int)preset % 3) * 0.5f;
    newOrigin.y *= ((int)preset / 3) * 0.5f;
    obj.setOrigin(newOrigin);
    return newOrigin;
}

sf::Vector2f Utils::SetOrigin(sf::Text& obj, Origins preset)
{
    sf::FloatRect rect = obj.getLocalBounds();
    sf::Vector2f newOrigin(rect.width, rect.height);
    newOrigin.x *= ((int)preset % 3) * 0.5f;
    newOrigin.y *= ((int)preset / 3) * 0.5f;
    obj.setOrigin(newOrigin);
    return newOrigin;
}

sf::Vector2f Utils::SetOrigin(sf::RectangleShape obj, Origins preset)
{
    sf::FloatRect rect = obj.getLocalBounds();
    sf::Vector2f newOrigin(rect.width, rect.height);
    newOrigin.x *= ((int)preset % 3) * 0.5f;
    newOrigin.y *= ((int)preset / 3) * 0.5f;
    obj.setOrigin(newOrigin);
    return newOrigin;
}

sf::Vector2f Utils::OriginBasedLoc(Origins preset)
{
    sf::Vector2f newLocation(1920.f, 1080.f);
    newLocation.x *= ((int)preset % 3) * 0.5f;
    newLocation.y *= ((int)preset / 3) * 0.5f;

    return newLocation;
}
