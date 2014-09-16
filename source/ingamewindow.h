#ifndef INGAMEWINDOW_H
#define INGAMEWINDOW_H

#include "iwindowcontent.h"

class IWindowContent;

class InGameWindow : public IWindowContent
{
public:
        InGameWindow(IStateManager *context, IWindowContent **_menu);
        bool handleWindow();
private:
        IWindowContent **menu;
};

#endif // INGAMEWINDOW_H
