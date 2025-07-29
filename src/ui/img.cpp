#include "../../include/ui/img.h"
#include "../../external/aLogger/include/aLogger.h"

UIImg::UIImg(const std::string& imageSource,
             const sf::Color& outlineColor,
             const uint32_t outlineThickness) {
    if (!texture.loadFromFile(imageSource)) {
        Log("The image src : {`$`}, couldn't be loaded.", Log::Levels::ERR, {imageSource});
        isVisible = false;
    } else {
        sprite.setTexture(texture);
        isVisible = true;
    }

    this->outlineColor = outlineColor;
    this->outlineThickness = outlineThickness;

    isDirty = true;
    this->imageSource = imageSource;
}


void UIImg::setImage(const std::string& imagePath) {
    if (!texture.loadFromFile(imagePath)) {
        Log("The image src : {`$`}, couldn't be loaded.", Log::Levels::ERR, {imagePath});
        isVisible = false;  // Hide if loading failed
    } else {
        sprite.setTexture(texture);
        this->imageSource = imagePath;
        isVisible = true;
        isDirty = true;
        update();
    }
}

std::string UIImg::getImageSource() const {
    return imageSource;
}

void UIImg::update() {
    if (!isDirty) return;

    constexpr float padding = 10.f;
    Log("Updating image", Log::Levels::DEBUG);

    const sf::FloatRect imgBounds = sprite.getLocalBounds();

    // Scale sprite to desired size
    float scaleX = size.x / imgBounds.width;
    float scaleY = size.y / imgBounds.height;

    sprite.setScale(scaleX, scaleY);
    sprite.setRotation(rotation);

    // Center origin for positioning
    sprite.setOrigin(imgBounds.left + imgBounds.width / 2.f,
                     imgBounds.top + imgBounds.height / 2.f);
    sprite.setPosition(position);

    // Set background rectangle size to sprite size + padding
    backgroundRectangle.setSize(sf::Vector2f(size.x + padding * 2.f,
                                             size.y + padding * 2.f));
    backgroundRectangle.setOrigin(backgroundRectangle.getSize().x / 2.f,
                                 backgroundRectangle.getSize().y / 2.f);
    backgroundRectangle.setPosition(position);

    backgroundRectangle.setFillColor(sf::Color::Transparent);
    backgroundRectangle.setOutlineColor(outlineColor);
    backgroundRectangle.setOutlineThickness(static_cast<float>(outlineThickness));

    isDirty = false;
}


void UIImg::render(sf::RenderWindow& window) {
    if (!isVisible) return;
    window.draw(backgroundRectangle);
    window.draw(sprite);
}
