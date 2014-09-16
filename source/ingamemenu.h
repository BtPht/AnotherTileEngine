#ifndef INGAMEMENU_H
#define INGAMEMENU_H

#include "iwindowcontent.h"

class IWindowContent;

class InGameMenu : public IWindowContent
{
public:
        InGameMenu(IStateManager *context, IWindowContent **game, IWindowContent **exit);
        bool handleWindow();
private:
        IWindowContent **game;
        IWindowContent **exit;
};

#endif // INGAMEMENU_H
