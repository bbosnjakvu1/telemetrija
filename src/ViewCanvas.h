#pragma once
#include <gui/Canvas.h>
#include <gui/Shape.h>
#include <math/math.h>
#include <gui/Transformation.h>


#include "LineGraph.h"


//constexpr gui::CoordType dCtrl = 60, cX = 380, cY = 220, rB = 24.;
//dCtrl - shift for bezier control points
//cX - center (x coordinate) of the shape
//cY - center (Y coordinate) of the shape
//rB - radius of the Bezier shape (when dCtrl = 0)

constexpr bool showBezierConstructingPoints = true;
constexpr bool doNotShowNonBezierPrimitives = true;

//#define HIDE_NON_BEZIER

class ViewCanvas : public gui::Canvas
{
protected:
    LineGraph grafik;

    gui::Point _translate;
    double _scaleX = 1.0;
    double _scaleY = 1.0;
    cnt::PushBackVector<td::Point<td::INT4>> _kernelPoints;
protected:
    
    /*bool onZoom(const gui::InputDevice& inputDevice) override
    {
        double scale = inputDevice.getScale();
        _scaleX *= scale;
        _scaleY *= scale;
        reDraw();
        return true;
    }*/
    
    bool onScroll(const gui::InputDevice& inputDevice) override
    {
        const gui::Point& delta = inputDevice.getScrollDelta();
        _translate += delta;
        reDraw();
        return true;
    }
    
    void onDraw(const gui::Rect& rect) override
    {
        gui::Transformation tr;
        tr.translate(_translate.x, _translate.y);
        tr.scale(_scaleX, _scaleY);
        tr.appendToContext();
        grafik.Draw();
    }

public:
    ViewCanvas()
    : gui::Canvas({gui::InputDevice::Event::Zoom}) //{gui::InputDevice::Event::Zoom}  scrolling and zooming without scrollbars
    {
        setClipsToBounds();
        registerForScrollEvents();
    }
};
