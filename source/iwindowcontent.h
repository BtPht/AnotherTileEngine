#ifndef IWINDOWCONTENT_H
#define IWINDOWCONTENT_H

#include <SFML/Graphics.hpp>

#include "istatemanager.h"

class IWindowContent
{
public:
        virtual bool handleWindow(){return false;}
protected:
        IStateManager *stateManager;
        sf::RenderWindow *renderWindow;

        IWindowContent(IStateManager *_stateManager, sf::RenderWindow *_renderWindow){stateManager=_stateManager; renderWindow=_renderWindow;}
};

#endif // IWINDOWCONTENT_H
