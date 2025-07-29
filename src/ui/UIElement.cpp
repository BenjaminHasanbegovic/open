#include "../../include/ui/UIElement.h"
#include <cmath>

void UIElement::update() {
    if (backgroundColor != sf::Color::Transparent) {
        backgroundRectangle.setOrigin(originPosition);
        backgroundRectangle.setPosition(position);
        backgroundRectangle.setSize(size);
        backgroundRectangle.setRotation(rotation);

        backgroundRectangle.setOutlineColor(outlineColor);
        backgroundRectangle.setOutlineThickness(static_cast<float>(outlineThickness));

        backgroundRectangle.setFillColor(backgroundColor);
    }
    isDirty = false;
}

// Visibility
void UIElement::setVisibility(const bool visible) {
    isVisible = visible;
    isDirty = true;
    update();
}
bool UIElement::getVisibility() const { return isVisible; }

// Position & Size
void UIElement::setPosition(float x, float y) {
    position = {x, y};
    isDirty = true;
    update();
}
sf::Vector2f UIElement::getPosition() const { return position; }

void UIElement::setSize(float width, float height) {
    size = {width, height};
    isDirty = true;
    update();
}
sf::Vector2f UIElement::getSize() const { return size; }

// Font size
void UIElement::setFontSize(const unsigned int size) {
    fontSize = size;
    isDirty = true;
    update();
}
unsigned int UIElement::getFontSize() const { return fontSize; }

// Rotation
void UIElement::setRotation(const float angle) {
    rotation = std::fmod(angle, 360.0f);
    if (rotation < 0) rotation += 360.0f;
    isDirty = true;
    update();
}
float UIElement::getRotation() const { return rotation; }

// Z-Index
void UIElement::setZIndex(int zIndexValue) {
    zIndex = zIndexValue;
    isDirty = true;
    update();
}
int UIElement::getZIndex() const { return zIndex; }

// Origin
void UIElement::setOrigin(float x, float y) {
    originPosition = sf::Vector2f(x, y);
    isDirty = true;
    update();
}
sf::Vector2f UIElement::getOrigin() const { return originPosition; }

// Colors & Styling
void UIElement::setFontColor(const sf::Color& color) {
    fontColor = color;
    isDirty = true;
    update();
}
void UIElement::setOutlineColor(const sf::Color& color) {
    outlineColor = color;
    isDirty = true;
    update();
}
void UIElement::setBackgroundColor(const sf::Color& color) {
    backgroundColor = color;
    isDirty = true;
    update();
}

sf::Color UIElement::getFontColor() const { return fontColor; }
sf::Color UIElement::getOutlineColor() const { return outlineColor; }
sf::Color UIElement::getBackgroundColor() const { return backgroundColor; }

// Outline thickness
void UIElement::setOutlineThickness(uint32_t thickness) {
    outlineThickness = thickness;
    isDirty = true;
    update();
}
uint32_t UIElement::getOutlineThickness() const { return outlineThickness; }

// Outline radius (placeholder, no effect in SFML default RectangleShape)
void UIElement::setOutlineRadius(const float radius) {
    outlineRadius = radius;
    isDirty = true;
    update();
}
float UIElement::getOutlineRadius() const { return outlineRadius; }

// Hierarchy Handling (placeholders)
void UIElement::addChild(std::shared_ptr<UIElement> child) {
    // TODO: Implement later
}
void UIElement::removeChild(uint32_t childId) {
    // TODO: Implement later
}
std::vector<std::shared_ptr<UIElement>> UIElement::getChildren() const {
    return {}; // placeholder
}
UIElement* UIElement::getParent() const {
    return nullptr; // placeholder
}
void UIElement::setParent(UIElement* parentElement) {
    // TODO: Implement later
}
