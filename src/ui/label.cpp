#include "../../include/ui/label.h"
#include "../../external/aLogger/include/aLogger.h"


UILabel::UILabel(const std::string& textContent,
    const sf::Font* font,
    const unsigned int fontSize,
    const sf::Color& fontColor,
    const sf::Color& backgroundColor,
    const sf::Color& outlineColor,
    const uint32_t outlineThickness) {

    this->textContent.setFont(*font);
    this->textContent.setString(textContent);
    this->textContent.setCharacterSize(fontSize);
    this->textContent.setFillColor(fontColor);
    this->fontColor = fontColor;

    this->backgroundColor = backgroundColor;
    this->outlineColor = outlineColor;
    this->outlineThickness = outlineThickness;

    isDirty = true;
}

void UILabel::setText(const std::string& text) {
    this->textContent.setString(text);
    isDirty = true;  // Mark dirty so update recalculates
    update();
}

std::string UILabel::getText() const {
    return this->textContent.getString();
}

void UILabel::update() {
    if (!isDirty) return;
Log("Updating label",Log::Levels::DEBUG);
    const sf::FloatRect textBounds = textContent.getLocalBounds();

    textContent.setOrigin(textBounds.left + textBounds.width / 2.f,
                          textBounds.top + textBounds.height / 2.f);
    textContent.setPosition(position);
    textContent.setCharacterSize(fontSize);

    constexpr float padding = 10.f;
    backgroundRectangle.setSize(sf::Vector2f(textBounds.width + padding * 2,
                                             textBounds.height + padding * 2));
    backgroundRectangle.setOrigin(backgroundRectangle.getSize().x / 2.f,
                                  backgroundRectangle.getSize().y / 2.f);
    backgroundRectangle.setPosition(position);

    backgroundRectangle.setFillColor(backgroundColor);
    backgroundRectangle.setOutlineColor(outlineColor);
    backgroundRectangle.setOutlineThickness(static_cast<float>(outlineThickness));

    isDirty = false;
}

void UILabel::render(sf::RenderWindow& window) {
    if (!isVisible) return;
        window.draw(backgroundRectangle);
        window.draw(textContent);

}
