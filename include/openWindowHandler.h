#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>
#include <memory>
#include "./ui/UIElement.h"

using namespace sf;
class oWindowManager {
public:
explicit oWindowManager(RenderWindow& appWindow);

    uint32_t addEventListener(const Event::EventType eventType,std::function<void(RenderWindow&,const Event&)> callback);
    bool removeEventListener(uint32_t listenerId);

    void defineUpdateLoop(uint32_t deltaTime);

    void render();

    void addElement(std::shared_ptr<UIElement> element);
    void removeElement(std::shared_ptr<UIElement> element);

 bool loadScene(const std::string& sceneFilePath,const std::string& buildPath);
private:
    bool buildSceneBinary(const std::string& sceneFilePath,const std::string& buildPath);
    RenderWindow& window;
    uint32_t nextListenerId{0};
    std::vector<std::shared_ptr<UIElement>> elements;
};
