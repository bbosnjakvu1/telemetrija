//
//  Created by Izudin Dzafic on 28/07/2020.
//  Copyright © 2020 IDz. All rights reserved.
//
#pragma once
#include <gui/StandardTabView.h>
#include "ViewSplit.h"
#include <vector>
#include <memory>

class MainView : public gui::StandardTabView
{
private:
protected:
    ViewSplit _view;
    std::vector<std::shared_ptr<ViewSplit>>tabovi;

public:
    MainView()
    {
        tabovi.push_back(std::make_shared<ViewSplit>());
        tabovi.push_back(std::make_shared<ViewSplit>());
        //addView(&_canvas, "Canvas tab");
        addView(&*tabovi[0], "Prvi tab");
        addView(&*tabovi[1], "Prvi tab");

        //setTabLocation(StandardTabView::TabLocation::Bottom);
        setCurrentViewPos(1);
    }
    
    bool onChangedSelection(gui::StandardTabView* pTV, int newPos) override
    {
        gui::BaseView* pBV = pTV->getView(newPos);
        assert(pBV);
        if (newPos >= 0)
        {
            if (newPos == 0)
            {
                assert(pBV = &_view);
            }
            else
            {
            }
        }
            
        mu::dbgLog("Current viewPos=%d", newPos);
        return false;
    }
    
};
