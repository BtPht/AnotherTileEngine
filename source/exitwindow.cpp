#include "exitwindow.h"

ExitWindow::ExitWindow(IStateManager *context)
        :IWindowContent(context,context->getRenderWindow())
{
}


bool ExitWindow::handleWindow()
{
        sf::RectangleShape shape(sf::Vector2f(60,30));
        shape.setFillColor(sf::Color::Red);
        sf::Event event;

        renderWindow->setTitle("Exiting...");
        renderWindow->clear();
        renderWindow->draw(shape);
        renderWindow->display();

        while (renderWindow->waitEvent(event))
        {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                        return false;
                if (event.type == sf::Event::MouseButtonReleased){
                        return false;
                }
        }
}
