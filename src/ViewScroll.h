#pragma once
#include <gui/ViewScroller.h>
#include "ViewCanvas.h"

class ViewScroll : public gui::ViewScroller
{
private:
protected:
    ViewCanvas canvas;
protected:

public:
    ViewScroll()
        : gui::ViewScroller(gui::ViewScroller::Type::ScrollerAlwaysVisible, gui::ViewScroller::Type::NoScroll)
    {
        setContentView(&canvas);
    }
    
    ViewCanvas& getView()
    {
        return canvas;
    }

    ViewCanvas& getCanvas(){return canvas;}

};
