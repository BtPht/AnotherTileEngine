#ifndef INGAMEWINDOW_H
#define INGAMEWINDOW_H

#include "iwindowcontent.h"

#include "basemap.h"
#include "gamewindow.h"
#include "basemapbuilder.h"

class IWindowContent;

class InGameWindow : public IWindowContent
{
public:
        InGameWindow(IStateManager *context, IWindowContent **_menu);
        bool handleWindow();
private:
        IWindowContent **menu;

        sf::Texture back_texture;
        sf::Sprite back ;
        Player link;
        BaseMap baseMap ;

        void loadMap() ;
};

#endif // INGAMEWINDOW_H
