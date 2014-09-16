#ifndef ISTATEMANAGER_H
#define ISTATEMANAGER_H

#include <SFML/Graphics/RenderWindow.hpp>

class IWindowContent;

class IStateManager
{
public:
        virtual void setCurrentState(IWindowContent *newState) = 0;
        virtual sf::RenderWindow *getRenderWindow() = 0;
};

#endif // ISTATEMANAGER_H
