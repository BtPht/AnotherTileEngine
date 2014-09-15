/*
 * WindowsManager.cpp
 *
 *  Created on: 24 juin 2013
 *      Author: bertrand
 */

#include "windowsmanager.h"

WindowsManager::WindowsManager()
{
}

unsigned int WindowsManager::runGame()
{
        initialise();

        loadMap();

        sf::Texture back_texture;
        back_texture.loadFromFile("/home/bertrand/Dropbox/Pictures/wg/1370726354715.jpg");
        sf::Sprite back(back_texture);

        Player link;
        if(!link.loadFromFile("./test.link")) return 4;

        link.setCurrentMovment(link.stand_front);

        InfoTile *popup = nullptr;

        // Start game loop
        sf::Event event;
        while (current_window->isOpen()) {
                // Process events
                while (current_window->pollEvent(event)) {
                        // Close window : exit
                        if (event.type == sf::Event::Closed)
                                current_window->close();

                        // Escape key : exit
                        if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                                current_window->close();

                        if (event.type == sf::Event::Resized) {
                                current_window->resize(event.size.width, event.size.height);
                        }
                        if (event.type == sf::Event::MouseWheelMoved) {
                                current_window->zoom(event.mouseWheel.delta);
                        }
                        if (event.type == sf::Event::MouseButtonReleased) {
                                delete popup;
                                popup = baseMap.getInfo(
                                                current_window->mapPixelToCoords(sf::Mouse::getPosition(*current_window))
                                                );
                        }
                }

                sf::Vector2f depl = link.update();

                baseMap.deplacement(link.getCurrentAnimation(),depl);

                link.move(depl);

                current_window->clear();

                current_window->draw(back);

                current_window->scrolling();

                baseMap.update();

                current_window->draw(baseMap);

                current_window->draw(link);

                if(popup != nullptr) current_window->draw(*popup);

                current_window->display();

        }

        delete current_window;
        return 0;
}

void WindowsManager::initialise()
{
        current_window = new GameWindow;
}

void WindowsManager::loadMap()
{
        BaseMapBuilder *builder = new BaseMapBuilder;
        baseMap = builder->createBaseMap_Planar("./test2.map");
        delete builder;
}
