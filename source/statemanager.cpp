#include "statemanager.h"

StateManager::StateManager()
        :contextwindow(sf::VideoMode(400, 300), "Fenetre créée par défaut")
{
        IWindowContent **loading, **introMenu, **inGame, **inGameMenu, **exit;

        loading = new IWindowContent*;
        introMenu = new IWindowContent*;
        inGame = new IWindowContent*;
        inGameMenu = new IWindowContent*;
        exit = new IWindowContent*;

        *loading = new LoadingWindow(this, introMenu);
        *introMenu = new IntroMenu(this, inGame, exit);
        *inGame = new InGameWindow(this, inGameMenu);
        *inGameMenu = new InGameMenu(this, inGame, exit);

        currentState = *loading ;
}

StateManager::~StateManager()
{

}

void StateManager::setCurrentState(IWindowContent *newState)
{
        if(newState != nullptr)
                currentState = newState;
        else
                exit(3);
}

bool StateManager::drawCurrentState()
{
        return(currentState->handleWindow());
}

sf::RenderWindow *StateManager::getRenderWindow()
{
        return &contextwindow;
}
