#pragma once
#include <gui/Window.h>
#include <gui/ActionItem.h>
#include "MenuBar.h"
#include "MainView.h"
#include "ViewSplit.h"
#include "ToolBar.h"
#include "Data.h"
#include "ViewTableEdit.h"
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
    Data data;
public:
    MainWindow()
        : gui::Window(gui::Geometry(50, 50, 800, 800))
    {
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

                /*td::UINT4 settingsID = 728289; //bilo koji unikatan broj
                auto pDlg = getAttachedWindow(settingsID);
                if (pDlg)
                    pDlg->setFocus();
                else
                {
                    DialogSettings* pSettingsDlg = new DialogSettings(this, settingsID);
                    pSettingsDlg->keepOnTopOfParent();
                    pSettingsDlg->setMainTB(&toolBar);
                    pSettingsDlg->open();
                }*/
                showYesNoQuestionAsync("Create new graf view?", "Are you sure?", "Yes", "No",
                                       [this](gui::Alert::Answer retStatus){
                                           if (retStatus != gui::Alert::Answer::Yes)
                                               return;

                                           td::BYTE ctxMenuID = 100;
                                           //add View
                                           //BackView2* pView =  new BackView2;
                                           ViewSplit* pView = new ViewSplit;

                                           int iPos = mainView.addView(pView,"Graf",&_imgComplex);

                                           mainView.setHeaderContextMenu(iPos, ctxMenuID);
                                           mainView.forwardContextMenuEvents(iPos, this);
                                           ++viewPos;
                                       });
                return true;
            }
            case 20:{
                showYesNoQuestionAsync("Create new data view", "Are you sure?", "Yes", "No",
                                       [this](gui::Alert::Answer retStatus){
                                           if (retStatus != gui::Alert::Answer::Yes)
                                               return;

                                           td::BYTE ctxMenuID = 100;
                                           //add View
                                           //BackView2* pView =  new BackView2;
                                           ViewTableEdit* pView = new ViewTableEdit();

                                           int iPos = mainView.addView(pView,"Data",&_imgComplex);

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
