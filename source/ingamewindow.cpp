#include "ingamewindow.h"

InGameWindow::InGameWindow(IStateManager *context, IWindowContent **_menu)
        :IWindowContent(context, context->getRenderWindow()),
          menu(_menu)
{
        loadMap();

        back_texture.loadFromFile("/home/bertrand/Dropbox/Pictures/wg/1370726354715.jpg");

        back.setTexture(back_texture);

        link.loadFromFile("./test.link");

        link.setCurrentMovment(link.stand_front);
}


bool InGameWindow::handleWindow()
{
        GameWindow *current_window = dynamic_cast<GameWindow *>(renderWindow);

        InfoTile *popup = nullptr;

        // Start game loop
        sf::Event event;
        while (current_window->isOpen()) {
                // Process events
                while (current_window->pollEvent(event)) {
                        // Close window : exit
                        if (event.type == sf::Event::Closed)
                                return false;

                        // Escape key : exit
                        if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)){
                                stateManager->setCurrentState(*menu);
                                return true;
                        }

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

        return 0;
}

void InGameWindow::loadMap()
{
        BaseMapBuilder *builder = new BaseMapBuilder;
        baseMap = builder->createBaseMap_Planar("./test2.map");
        delete builder;
}
