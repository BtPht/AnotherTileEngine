#ifndef LOADINGWINDOW_H
#define LOADINGWINDOW_H

#include "iwindowcontent.h"

class IWindowContent;

class LoadingWindow : public IWindowContent
{
public:
        LoadingWindow(IStateManager *context, IWindowContent **menu) ;
        bool handleWindow();
private:
        IWindowContent **menu;
};

#endif // LOADINGWINDOW_H
