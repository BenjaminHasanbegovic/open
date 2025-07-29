#include <SFML/Graphics.hpp>
#include "include/openWindow.h"
#include "./external/aLogger/include/aLogger.h"

int main() {
    setLogLevelFilter(Log::Levels::DEBUG,Log::Levels::ERR);
    constexpr float VIRTUAL_WIDTH = 1920.f;
    constexpr float VIRTUAL_HEIGHT = 1080.f;
    sf::RenderWindow window(sf::VideoMode(VIRTUAL_WIDTH, VIRTUAL_HEIGHT), "Test");



    sf::View view(sf::FloatRect(0, 0, VIRTUAL_WIDTH, VIRTUAL_HEIGHT));
    window.setView(view);

   sf::Font font;
    if (!font.loadFromFile("../assets/fonts/Intel_One_Mono/static/IntelOneMono-Light.ttf")) {
        Log("Failed to load font", Log::Levels::ERR);
        return -1;
    }
     UILabel test("Testing",&font,24,sf::Color::White);
UIImg testImg("../assets/textures/static/placeholderImg.png",sf::Color::Blue);
    test.setPosition(400,16);
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed){
            testImg.setSize(100,100);

        }
        if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        test.render(window);
testImg.render(window);

        window.display();
    }

    return 0;
}