#ifndef EXITWINDOW_H
#define EXITWINDOW_H

#include "iwindowcontent.h"

class ExitWindow : public IWindowContent
{
public:
        ExitWindow(IStateManager *context);
        bool handleWindow();
};

#endif // EXITWINDOW_H
