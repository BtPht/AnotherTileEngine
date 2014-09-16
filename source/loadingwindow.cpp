#include "loadingwindow.h"

LoadingWindow::LoadingWindow(IStateManager *context, IWindowContent **_menu)
        :IWindowContent(context, context->getRenderWindow()),
          menu(_menu)
{
}


bool LoadingWindow::handleWindow()
{
        sf::CircleShape shape(50);
        sf::Event event;

        renderWindow->setTitle("Loading...");
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
