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
//        sf::RectangleShape shape(sf::Vector2f(80,20));
//        sf::Event event;

//        renderWindow->setTitle("In-game window");
//        renderWindow->clear();
//        renderWindow->draw(shape);
//        renderWindow->display();

//        while (renderWindow->waitEvent(event))
//        {
//                // "close requested" event: we close the window
//                if (event.type == sf::Event::Closed)
//                        return false;

//                if (event.type == sf::Event::MouseButtonReleased){
//                        stateManager->setCurrentState(*menu);
//                        return true;
//                }
//        }

        GameWindow *current_window_d = dynamic_cast<GameWindow *>(renderWindow);

        InfoTile *popup = nullptr;

        // Start game loop
        sf::Event event;
        while (current_window_d->isOpen()) {
                // Process events
                while (current_window_d->pollEvent(event)) {
                        // Close window : exit
                        if (event.type == sf::Event::Closed)
                                return false;

                        // Escape key : exit
                        if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)){
                                stateManager->setCurrentState(*menu);
                                return true;
                        }

                        if (event.type == sf::Event::Resized) {
                                current_window_d->resize(event.size.width, event.size.height);
                        }
                        if (event.type == sf::Event::MouseWheelMoved) {
                                current_window_d->zoom(event.mouseWheel.delta);
                        }
                        if (event.type == sf::Event::MouseButtonReleased) {
                                delete popup;
                                popup = baseMap.getInfo(
                                                current_window_d->mapPixelToCoords(sf::Mouse::getPosition(*current_window_d))
                                                );
                        }
                }

                sf::Vector2f depl = link.update();

                baseMap.deplacement(link.getCurrentAnimation(),depl);

                link.move(depl);

                current_window_d->clear();

                current_window_d->draw(back);

                current_window_d->scrolling();

                baseMap.update();

                current_window_d->draw(baseMap);

                current_window_d->draw(link);

                if(popup != nullptr) current_window_d->draw(*popup);

                current_window_d->display();

        }

        return 0;
}

void InGameWindow::loadMap()
{
        BaseMapBuilder *builder = new BaseMapBuilder;
        baseMap = builder->createBaseMap_Planar("./test2.map");
        delete builder;
}
