//
//  Created by Izudin Dzafic on 28/07/2020.
//  Copyright © 2020 IDz. All rights reserved.
//
#pragma once
#include <gui/SplitterLayout.h>
#include <gui/View.h>

#include "ViewCanvas.h"
#include "ViewGrid.h"

class ViewSplit : public gui::View
{
    gui::SplitterLayout _splitter;
    ViewCanvas can;
    ViewGrid grid;
    std::function<void()>* _pUpdateMenuAndTB;
    std::function<void(float, bool, td::ColorID, td::ColorID)> _fnSetVisualEffects;

public:
    ViewSplit():_splitter(gui::SplitterLayout::Orientation::Vertical, gui::SplitterLayout::AuxiliaryCell::Second)
    {
        setMargins(0, 0, 0, 0);
        _splitter.setContent(can, grid);
        setLayout(&_splitter);
    }
};
