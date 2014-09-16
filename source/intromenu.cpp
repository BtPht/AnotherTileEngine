#include "intromenu.h"

IntroMenu::IntroMenu(IStateManager *context, IWindowContent **_game, IWindowContent **_exit)
        :IWindowContent(context, context->getRenderWindow()),
          game(_game),
          exit(_exit)

{
}

bool IntroMenu::handleWindow()
{
        sf::RectangleShape shape(sf::Vector2f(40,40));
        sf::Event event;

        renderWindow->setTitle("Welcome menu");
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
        }
}
