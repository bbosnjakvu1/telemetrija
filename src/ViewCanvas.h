#pragma once
#include <gui/Canvas.h>
#include <gui/Shape.h>
#include <gui/Transformation.h>
#include <gui/DrawableString.h>


#include "LineGraph.h"


class ViewCanvas : public gui::Canvas{
protected:
    LineGraph grafik;
    gui::DrawableString xOsa;
    gui::DrawableString yOsa;
    gui::Point translate;
    double _scaleX = 1.0;
    double _scaleY = 1.0;

protected:

    bool getModelSize(gui::Size& modelSize)const override{
        double a=grafik.getXmax();
        modelSize.width=a*1+50;
        modelSize.height=550;
        return true;
    }
    
    void onDraw(const gui::Rect& rect) override{

        gui::Size sz;
        getSize(sz);
        grafik.Draw(sz,400);
    }

public:
    ViewCanvas()
        : gui::Canvas({gui::InputDevice::Event::Zoom}){
        enableResizeEvent(true);
        setClipsToBounds();
        registerForScrollEvents();
    }

    void changeSettings(int xid, int yid)
    {
        grafik.setX(xid);
        grafik.setY(yid);
    }

};
