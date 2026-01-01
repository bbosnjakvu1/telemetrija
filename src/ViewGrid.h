//
//  Created by Izudin Dzafic on 28/07/2020.
//  Copyright © 2020 IDz. All rights reserved.
//
#pragma once
#include <gui/View.h>
#include <gui/Label.h>
#include <gui/LineEdit.h>
#include <gui/TextEdit.h>
#include <gui/NumericEdit.h>
#include <gui/CheckBox.h>
#include <gui/Slider.h>
#include <gui/ComboBox.h>
#include <gui/Button.h>
#include <gui/DateEdit.h>
#include <gui/TimeEdit.h>

#include <gui/HorizontalLayout.h>
#include <gui/VerticalLayout.h>

#include <gui/ProgressIndicator.h>

#include <gui/GridLayout.h>
#include <gui/GridComposer.h>

class ViewGrid : public gui::View
{
private:
protected:
    gui::Label _lbl;
    gui::LineEdit _lineEdit;
    gui::Label _lbl2;
    gui::LineEdit _lineEdit2;
    gui::Label _lblKol;
    gui::NumericEdit _kol;

    gui::HorizontalLayout layoutH;
    gui::VerticalLayout controlls;
    gui::HorizontalLayout red1;
    gui::HorizontalLayout red2;

    gui::TextEdit textEdit;
    gui::TextEdit textEdit1;
    //gui::GridLayout gl;
public:
    ViewGrid()
    : _lbl("First lbl:")
    , _lbl2("Second lbl:")
    , _lblKol("Kolicina:")
    , _kol(td::decimal3, gui::LineEdit::Messages::Send)
    , layoutH(3)
    , controlls(2)
    , red1(4),  red2(2)
    //, gl(2,6)
    {
        _lineEdit.setToolTip("Ovo je tooltip");
        _lineEdit2.setToolTip("Ovo je drugi tooltip....");
        textEdit.setToolTip("Ovo je text edit za log");
        textEdit.setAsReadOnly();


        red1.append(_lbl);
        red1.append(_lineEdit);
        red1.append(_lbl2);
        red1.append(_lineEdit2);
        red2.append(_lblKol);
        red2.append(_kol);

        controlls.append(red1);controlls.append(red2);

        layoutH.append(controlls);
        layoutH.appendSpacer();
        layoutH.append(textEdit);

        //::GridComposer gc(gl);
        //gc.appendRow(_lbl);gc.appendCol(_lineEdit);gc.appendCol(_lbl2);gc.appendEmptyCols(1);gc.appendCol(_lineEdit2);
        //gc.appendRow(_lblKol);gc.appendCol(_kol);


        /*gl.insert(0,0, _lbl);
        gl.insert(0,1, _lineEdit);
        gl.insert(0,2, _lbl2);
        gl.insert(0,3, _lineEdit2);
        gl.insertSpacer(0,4,2,1);
        gl.insert(0,5,textEdit,-1);
        gl.insert(1,0, _lblKol);
        gl.insert(1,1, _kol);
        gl.insert(1,5,textEdit1,-1);
        */
        setLayout(&layoutH);

    }
    
    bool onBeginEdit(gui::LineEdit* pCtrl) override
    {
        textEdit.appendString("Begin edit!");
        mu::dbgLog("Begin Edit");
        return true;
    }
    
    bool onFinishEdit(gui::LineEdit* pCtrl) override
    {/*
        _textEdit.appendString("End edit: ");
        mu::dbgLog("End Edit");
        if (pCtrl == &_kol)
        {
            td::Variant kol = _kol.getValue();
            
            td::Variant dblIznos = kol * cij;
            td::Decimal2 dec2(dblIznos.r8Val());
            
            td::Variant iznos(dec2);
            
            td::Decimal2 maxIznos(100.0);
            if (dec2 > maxIznos)
            {
                //_cbKupiti.setTitle("Ne kupovati");
            }
            else
                
            return true;
        }*/
        return false;
    }
    
    bool onClick(gui::CheckBox* pCB) override
    {
        /*if (pCB== &_cbKupiti)
        {
            bool isChecked = _cbKupiti.isChecked();
            if (isChecked)
            {
                _textEdit.appendString(" Odabrano KUPITI ");
            }
            else
            {
                _textEdit.appendString(" Odabrano NEKupiti ");
            }
            return true;
        }*/
        return false;
    }
    
    bool onChangedValue(gui::Slider* pSlider) override
    {
       /* if (pSlider == &_slider)
        {
            double val = _slider.getValue();
            _progIndicator.setValue(val);
            return true;
        }*/
        return false;
    }
    
    bool onChangedSelection(gui::ComboBox* pCB) override
    {
        /*if (pCB == &_comboBox)
        {
            td::String strSel = pCB->getSelectedText();
            _textEdit.appendString(strSel);
            return true;
        }*/
        return false;
    }
    
    bool onClick(gui::Button* pBtn) override
    {/*
        if (pBtn == &_btnGetText)
        {
           td::String str = _textEdit.getText();
            const char* pStr = str.c_str();
            int k=0;
            ++k;
            return true;
        }
        else if (pBtn == &_btnClearText)
        {
            _textEdit.clean();
            return true;
        }
        else if (pBtn == &_btnGetDT)
        {
            td::Date dateVal = _date.getValue();
            td::Time timeVal = _time.getValue();
            
            td::String strDate = dateVal.toString();
            _textEdit.appendString(" Date=");
            _textEdit.appendString(strDate);
            td::String strTime = timeVal.toString();
            _textEdit.appendString(" Time=");
            _textEdit.appendString(strTime);
            return true;
        }*/
        return false;
    }
    
};
