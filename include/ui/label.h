#pragma once
#include "UIElement.h"
#include <SFML/Graphics.hpp>

class UILabel : public UIElement {
public:
    UILabel(const std::string& textContent,
        const sf::Font* font,
        unsigned int fontSize = 20,
        const sf::Color& fontColor = sf::Color::White,
        const sf::Color& backgroundColor = sf::Color::Transparent,
        const sf::Color& outlineColor = sf::Color::Transparent,
        uint32_t outlineThickness = 5
        );
    void update() override ;
    void setText(const std::string& text);
    std::string getText() const;

    void render(sf::RenderWindow& window) override;

private:
    sf::Text textContent;
};
