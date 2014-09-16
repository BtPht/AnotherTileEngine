#ifndef INTROMENU_H
#define INTROMENU_H

#include "iwindowcontent.h"

class IWindowContent;

class IntroMenu : public IWindowContent
{
public:
        IntroMenu(IStateManager *context, IWindowContent **_game, IWindowContent **_exit);
        bool handleWindow();
private:
        IWindowContent **game;
        IWindowContent **exit;
};

#endif // INTROMENU_H
