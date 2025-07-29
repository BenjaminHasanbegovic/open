#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <vector>
#include <memory>

/**
 * @class UIElement
 * @brief Base class for UI components with position, size, color, and hierarchy support.
 */
class UIElement {
public:
    virtual ~UIElement() = default;

    /** @brief Render the UI element on a given SFML window (must be implemented by subclasses). */
    virtual void render(sf::RenderWindow& window) = 0;

    /** @brief Updates internal shape and styling based on properties. */
    virtual void update();

    /** Visibility controls */
    void setVisibility(bool visible);
    bool getVisibility() const;

    /** Position & Size */
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;

    void setSize(float width, float height);
    sf::Vector2f getSize() const;

    /** Font size controls (for text-based UI elements) */
    virtual void setFontSize(unsigned int size);
    virtual unsigned int getFontSize() const;

    /** Rotation (in degrees) */
    void setRotation(float angle);
    float getRotation() const;

    /** Z-Index (used for rendering order) */
    void setZIndex(int zIndexValue);
    int getZIndex() const;

    /** Origin point for transformations */
    void setOrigin(float x, float y);
    sf::Vector2f getOrigin() const;

    /** Color & Styling */
    virtual void setFontColor(const sf::Color& color);
    virtual void setOutlineColor(const sf::Color& color);
    virtual void setBackgroundColor(const sf::Color& color);

    virtual sf::Color getFontColor() const;
    virtual sf::Color getOutlineColor() const;
    virtual sf::Color getBackgroundColor() const;

    /** Outline customization */
    void setOutlineThickness(uint32_t thickness);
    uint32_t getOutlineThickness() const;

    /** Outline corner radius (not natively supported by SFML) */
    void setOutlineRadius(float radius);
    float getOutlineRadius() const;

    /** Hierarchy management */
    virtual void addChild(std::shared_ptr<UIElement> child);
    virtual void removeChild(uint32_t childId);
    virtual std::vector<std::shared_ptr<UIElement>> getChildren() const;
    virtual UIElement* getParent() const;
    virtual void setParent(UIElement* parentElement);

protected:
    // --- State ---
    bool isDirty { true };
    bool isVisible { true };

    // --- Identification ---
    uint32_t id { 0 };
    uint32_t parentId { 0 };
    std::string className;

    // --- Geometry & Transform ---
    sf::Vector2f position { 0.f, 0.f };
    sf::Vector2f size { 0.f, 0.f };
    unsigned int fontSize { 20 };
    float rotation { 0.f };
    int zIndex { 0 };
    sf::Vector2f originPosition { 0.f, 0.f };

    // --- Colors & Styling ---
    sf::Color fontColor { sf::Color::White };
    sf::Color outlineColor { sf::Color::Transparent };
    sf::Color backgroundColor { sf::Color::Transparent };

    uint32_t outlineThickness { 0 };
    float outlineRadius { 0.f }; // Placeholder for custom rounded shape implementation

    // --- Hierarchy ---
    UIElement* parent { nullptr };
    std::unordered_map<uint32_t, std::unique_ptr<UIElement>> children;

    // --- Rendering ---
    sf::RectangleShape backgroundRectangle;
};
