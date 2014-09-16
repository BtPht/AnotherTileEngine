#include "ingamewindow.h"

InGameWindow::InGameWindow(IStateManager *context, IWindowContent **_menu)
        :IWindowContent(context, context->getRenderWindow()),
          menu(_menu)
{
}


bool InGameWindow::handleWindow()
{
        sf::RectangleShape shape(sf::Vector2f(80,20));
        sf::Event event;

        renderWindow->setTitle("In-game window");
        renderWindow->clear();
        renderWindow->draw(shape);
        renderWindow->display();

        while (renderWindow->waitEvent(event))
        {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                        return false;

                if (event.type == sf::Event::MouseButtonReleased){
                        stateManager->setCurrentState(*menu);
                        return true;
                }
        }
}
