#pragma once
#include "UIElement.h"
#include <SFML/Graphics.hpp>

class UIImg : public UIElement {
public:
 UIImg(const std::string& imageSource,
 const sf::Color& outlineColor = sf::Color::Transparent,
        uint32_t outlineThickness = 5
        );
    void update() override ;
    void setImage(const std::string& imageSource);
    std::string getImageSource() const;

 void render(sf::RenderWindow& window) override;

protected:
    std::string imageSource;
    sf::Texture texture;
    sf::Sprite sprite;
};
