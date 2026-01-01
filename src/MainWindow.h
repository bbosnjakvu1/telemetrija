//
//  Created by Izudin Dzafic on 28/07/2020.
//  Copyright © 2020 IDz. All rights reserved.
//
#pragma once
#include <gui/Window.h>
#include <gui/ActionItem.h>
#include "MenuBar.h"
#include "MainView.h"
#include <gui/FileDialog.h>


class MainWindow : public gui::Window
{
private:
protected:
    MenuBar _mainMenuBar;
    //ViewHoriz _myView;
    //ViewGrid _mainView;
    MainView _mainView;
public:
    MainWindow()
    : gui::Window(gui::Geometry(50, 50, 800, 500)) //druga dva broj su velicina(skontat kako forsiraf fullscreen)
    {
        setTitle("Telemetrija");
        _mainMenuBar.setAsMain(this);
        setCentralView(&_mainView);
    }
    
    ~MainWindow()
    {
    }
    
    bool shouldClose() override
    {
        return true;
    }
    
    void onClose() override
    {
        gui::Window::onClose();
    }
    
    bool onActionItem(gui::ActionItemDescriptor& aiDesc) override
    {
        auto [menuID, firstSubMenuID, lastSubMenuID, actionID] = aiDesc.getIDs();
        auto pAI = aiDesc.getActionItem();
        
        if (menuID == 20 && firstSubMenuID== 0 && lastSubMenuID == 0)
        {
            switch (actionID)
            {
                case 10:
                {
                    //PRIMJER snimanja fajla
                    bool bEnabled = pAI->isEnabled();
                    pAI->disable();
                    bEnabled = pAI->isEnabled();
                    
                    //gui::SaveFileDialog dlg("Save something");
                    td::String strNameLbl(tr("Snimi"));
                    strNameLbl += ":";
                    td::String dlgTitle("Snimi nesto");
                    const char* filter = ".xml";
                    const char* defaultFileName ="ImeFajla";

                    return true;
                }
                case 20:
                {
                    //PRIMJER Otvaranja fajla
                    pAI->disable();
                    td::String dlgTitle("Otvori nesto");
                    
                    return true;
                }
                case 30:
                {

                    return true;
                }
                default:
                    return false;
            }
        }
        if (menuID == 20 && firstSubMenuID== 0 && lastSubMenuID == 0)
        {
            if (actionID == 20)
            {

                return true;
            }
            
            if (actionID == 40)
            {

                return true;
            }
            
            if (actionID == 50)
            {

                return true;
            }
        }
        
        td::String msgText("Handling onActionItem MainWindow");
        td::String informativeText;
        informativeText.format("Handled onActionItem(subMenuID=%d, firstSubSubMenuID=%d, lastSubSubMenuID=%d, actionID=%d)", menuID, firstSubMenuID, lastSubMenuID, actionID);
        
       showAlert(msgText, informativeText);
        return true;
    }
    
};
