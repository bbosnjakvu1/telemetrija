#pragma once
#include <gui/TabView.h>
#include "ViewSplit.h"

class MainView : public gui::TabView

{
    gui::Image _imgComplex;//stavit nesto drugo
    int viewPos = 0;
public:
    MainView(): gui::TabView(gui::TabHeader::Type::FitToText, 8, 64)
    {

        td::BYTE ctxMenuID = 100;
        //add View
        //BackView2* pView =  new BackView2;
        ViewSplit* pView = new ViewSplit;

        int iPos = addView(pView,"view 1",&_imgComplex);
        if (iPos == 0)
            setNonRemovable(0);

        setHeaderContextMenu(iPos, ctxMenuID);
        forwardContextMenuEvents(iPos, this);
        ++viewPos;
    }
};
