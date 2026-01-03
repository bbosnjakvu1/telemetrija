#pragma once
#include <gui/Window.h>
#include <gui/ActionItem.h>
#include "MenuBar.h"
#include "MainView.h"
#include "ViewSplit.h"
#include "ToolBar.h"
#include <gui/FileDialog.h>


class MainWindow : public gui::Window
{
private:
protected:
    MenuBar menuBar;
    MainView mainView;
    gui::Image _imgComplex;//stavit nesto drugo
    ToolBar toolBar;
    int viewPos = 0;
public:
    MainWindow()
        : gui::Window(gui::Size {800, 800}) //druga dva broj su velicina(skontat kako forsiraf fullscreen)
    {
        //this->setSize()
        //setResizable(false);
        setTitle("Telemetrija");
        menuBar.setAsMain(this);
        setToolBar(toolBar);
        setCentralView(&mainView);
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
        
        if (menuID == 10 && firstSubMenuID== 0 && lastSubMenuID == 0){
            switch (actionID)
            {
            case 10:
            {
                showYesNoQuestionAsync("Create new view", "Are you sure?", "Yes", "No",
                                       [this](gui::Alert::Answer retStatus){
                                           if (retStatus != gui::Alert::Answer::Yes)
                                               return;

                                           td::BYTE ctxMenuID = 100;
                                           //add View
                                           //BackView2* pView =  new BackView2;
                                           ViewSplit* pView = new ViewSplit;

                                           int iPos = mainView.addView(pView,"view 1",&_imgComplex);
                                           if (iPos == 0)
                                               mainView.setNonRemovable(0);

                                           mainView.setHeaderContextMenu(iPos, ctxMenuID);
                                           mainView.forwardContextMenuEvents(iPos, this);
                                           ++viewPos;
                                       });
                return true;
            }
            case 0:
            {

                return true;
            }
            }
        }

        if (menuID == 20 && firstSubMenuID== 0 && lastSubMenuID == 0)
        {
            switch (actionID)
            {
            case 10:
            {
                showYesNoQuestionAsync("Create new view", "Are you sure?", "Yes", "No",
                   [this](gui::Alert::Answer retStatus){
                       if (retStatus != gui::Alert::Answer::Yes)
                           return;

               td::BYTE ctxMenuID = 100;
               //add View
                   //BackView2* pView =  new BackView2;
                   ViewSplit* pView = new ViewSplit;

                   int iPos = mainView.addView(pView,"view 1",&_imgComplex);
                   if (iPos == 0)
                       mainView.setNonRemovable(0);

                   mainView.setHeaderContextMenu(iPos, ctxMenuID);
                   mainView.forwardContextMenuEvents(iPos, this);
                   ++viewPos;
                   });
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
