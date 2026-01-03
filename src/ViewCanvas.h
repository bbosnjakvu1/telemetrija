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

    void drawCoordinates(const gui::Size& sz, int zeroPos)
    {
        const gui::CoordType c_dx = 0;
        gui::CoordType arrH = 6;
        gui::CoordType arrW = 10;
        //x coordinates
        gui::Point p1(c_dx, zeroPos);
        gui::Point p2(sz.width, zeroPos);
        gui::Shape::drawLine(p1, p2, td::ColorID::SysText, 0);
        //strelica x
        p1.x = p2.x - arrW;
        p1.y = p2.y - arrH;
        gui::Shape::drawLine(p1, p2, td::ColorID::SysText, 0);
        p1.y = p2.y + arrH;
        gui::Shape::drawLine(p1, p2, td::ColorID::SysText, 0);
        p1.x = p2.x - 2*arrW;
        xOsa.draw(p1, gui::Font::ID::SystemLargest, td::ColorID::SysText);

        //y coordinate
        p1.x = 5;
        p1.y = c_dx;
        p2.x = p1.x;
        p2.y = sz.height;
        gui::Shape::drawLine(p1, p2, td::ColorID::SysText, 0);

        //strelica y
        p2.x = p1.x + arrH;
        p2.y = p1.y + arrW;
        gui::Shape::drawLine(p1, p2, td::ColorID::SysText, 0);
        p2.x = p1.x - arrH;
        gui::Shape::drawLine(p1, p2, td::ColorID::SysText, 0);
        p2.x += 3*arrW;
        p2.y = p1.y + 3.5*arrW;
        yOsa.draw({p1.x+5,p1.y+5}, gui::Font::ID::SystemLargest, td::ColorID::SysText);
    }

    void scaleFactor(double &scaleX, double &scaleY){



    }

    /*bool onZoom(const gui::InputDevice& inputDevice) override
    {
        double scale = inputDevice.getScale();
        _scaleX *= scale;
        _scaleY *= scale;
        reDraw();
        return true;
    }*/

    void onResize(const gui::Size& newSize) override{
        gui::Size sz;
        getSize(sz);
        double scalex=sz.height/newSize.height;
        double scaley=sz.width/newSize.width;
        _scaleX *= scalex;
        _scaleY *= scaley;
        reDraw();
    }

    /*bool onScroll(const gui::InputDevice& inputDevice) override{
        const gui::Point& delta = inputDevice.getScrollDelta();
        translate += delta;
        reDraw();
        return true;
    }*/
    
    void onDraw(const gui::Rect& rect) override{

        gui::Size sz;
        //koordinatni sistem


        gui::Transformation tr;
        //tr.translate(translate.x, 1); //scroll samo ljevo desno
        //tr.scale(_scaleX, _scaleY);
        tr.appendToContext();
        getSize(sz);
        drawCoordinates(sz,400);
        grafik.Draw();
    }

public:
    ViewCanvas()
    : gui::Canvas(){ //{gui::InputDevice::Event::Zoom}
        //enableResizeEvent(true);
        setClipsToBounds();
        //registerForScrollEvents();
        xOsa=gui::DrawableString(grafik.getX());
        yOsa=gui::DrawableString(grafik.getY());
    }

};
