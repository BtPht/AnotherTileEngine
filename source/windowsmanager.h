#ifndef WINDOWSMANAGER_H_
#define WINDOWSMANAGER_H_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "gamewindow.h"
#include "infotile.h"
#include "basemapbuilder.h"

class WindowsManager
{
public:
        WindowsManager();
        unsigned int runGame();

private:
        GameWindow *current_window ;
        BaseMap baseMap ;

        void initialise() ;
        void loadMap() ;
};

#endif /* WINDOWSMANAGER_H_ */
