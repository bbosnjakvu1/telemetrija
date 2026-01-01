//
//  Created by Izudin Dzafic on 28/07/2020.
//  Copyright © 2020 IDz. All rights reserved.
//
#pragma once
#include <gui/TabView.h>

class MainView : public gui::TabView
{
public:
    MainView(): gui::TabView(gui::TabHeader::Type::FitToText, 8, 64)
    {

    }
};
