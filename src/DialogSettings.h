#pragma once
#include <gui/Dialog.h>
#include "ViewSettings.h"
#include <gui/Application.h>

class DialogSettings : public gui::Dialog{
    enum viewType {LineSingle, Data};

protected:


    ViewSettings _viewSettings;
    
    bool onClick(Dialog::Button::ID btnID, gui::Button* pButton) override
    {
        if (btnID == Dialog::Button::ID::OK)
        {
        }
        return true;
    }
public:
    DialogSettings(gui::Frame* pFrame, td::UINT4 wndID = 0)
    : gui::Dialog(pFrame, { {gui::Dialog::Button::ID::OK, tr("Ok"), gui::Button::Type::Default},
                            {gui::Dialog::Button::ID::Cancel, tr("Cancel")}}, gui::Size(450, 100), wndID)
    {
        setTitle(tr("New Tab"));
        setCentralView(&_viewSettings);
//        composeContent();
    }
    
    void setMainTB(gui::ToolBar* pTB)
    {
        _viewSettings.setMainTB(pTB);
    }

};

