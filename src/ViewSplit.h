#pragma once
#include <gui/SplitterLayout.h>
#include <gui/View.h>

#include "ViewScroll.h"
#include "ViewGrid.h"



class ViewSplit : public gui::View
{
    gui::SplitterLayout _splitter;
    ViewScroll scroll;
    std::function<void(int, int)> fcnChangeSettings;
    ViewGrid grid;


public:
    ViewSplit():_splitter(gui::SplitterLayout::Orientation::Vertical, gui::SplitterLayout::AuxiliaryCell::Second)
    ,fcnChangeSettings(std::bind(&ViewCanvas::changeSettings, &scroll.getCanvas(), std::placeholders::_1, std::placeholders::_2))
    ,grid(fcnChangeSettings)
    {
        _splitter.setContent(scroll, grid);
        setLayout(&_splitter);
    }
};
