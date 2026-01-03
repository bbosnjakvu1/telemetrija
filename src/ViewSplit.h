#pragma once
#include <gui/SplitterLayout.h>
#include <gui/View.h>

#include "ViewScroll.h"
#include "ViewGrid.h"

class ViewSplit : public gui::View
{
    gui::SplitterLayout _splitter;
    ViewScroll canvas;
    ViewGrid grid;

public:
    ViewSplit():_splitter(gui::SplitterLayout::Orientation::Vertical, gui::SplitterLayout::AuxiliaryCell::Second)
    {
        _splitter.setContent(canvas, grid);
        setLayout(&_splitter);
        grid.setHeight(500);
        //can.setFixedWidth(1920);
        //grid.setWidth(1920);
    }
};
