#include "ingamemenu.h"

InGameMenu::InGameMenu(IStateManager *context, IWindowContent **_game, IWindowContent **_exit)
        :IWindowContent(context, context->getRenderWindow()),
          game(_game),
          exit(_exit)
{
}

bool InGameMenu::handleWindow()
{
        sf::CircleShape shape(100);
        sf::Event event;

        shape.setFillColor(sf::Color::Blue);

        renderWindow->setTitle("In-game menu window");
        renderWindow->clear();
        renderWindow->draw(shape);
        renderWindow->display();

        while (renderWindow->waitEvent(event))
        {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                        return false;

                if (event.type == sf::Event::MouseButtonReleased){
                        stateManager->setCurrentState(*game);
                        return true;
                }
                if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Q)){
                        stateManager->setCurrentState(*exit);
                        return true;
                }
        }
}
