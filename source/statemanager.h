#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "iwindowcontent.h"
#include "loadingwindow.h"
#include "intromenu.h"
#include "ingamewindow.h"
#include "ingamemenu.h"

class IWindowContent;

class StateManager : public IStateManager
{
public:
        StateManager();
        void setCurrentState(IWindowContent *newState);
        bool drawCurrentState();

        sf::RenderWindow *getRenderWindow();

        ~StateManager();
private:
        sf::RenderWindow contextwindow;
        IWindowContent *currentState;
};

#endif // STATEMANAGER_H
