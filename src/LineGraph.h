#pragma once
#include <vector>
#include <memory>
#include <gui/Canvas.h>
#include <gui/Shape.h>
#include <gui/DrawableString.h>
#include <dp/IDatabase.h>
#include <dp/IDataSet.h>

#include"Data.h"


class LineGraph{

    dp::IDataSetPtr xData;
    dp::IDataSetPtr yData;
    int x_id;
    int y_id;
    std::vector <std::shared_ptr<gui::Shape>>graf;

    std::vector<double> y = {
        // block of 50 values
        -1345.2, 0, -500, 987.4,  -412.8,  1765.9,  -89.3,
        1540.6, -1987.1,  645.2,   312.7, -1650.4,
        428.9, -743.5,  1899.8,  -256.1,  1023.6,
        -1784.9,   95.4,  1678.3, -1198.6,   560.1,
        -342.7,  1432.8, -188.9, -1567.2,   734.5,
        198.6, -923.4,  1820.7, -134.2,  1299.1,
        -167.5,   876.2, -1945.8,  158.4,  1120.6,
        -684.9,  1405.7, -321.8,  1903.4, -1012.5,
        499.2, -1728.6,  908.1,   -45.7,  1612.9,

        // repeat block (2)
        -1345.2,  987.4,  -412.8,  1765.9,  -89.3,
        1540.6, -1987.1,  645.2,   312.7, -1650.4,
        428.9, -743.5,  1899.8,  -256.1,  1023.6,
        -1784.9,   95.4,  1678.3, -1198.6,   560.1,
        -342.7,  1432.8, -188.9, -1567.2,   734.5,
        198.6, -923.4,  1820.7, -134.2,  1299.1,
        -167.5,   876.2, -1945.8,  158.4,  1120.6,
        -684.9,  1405.7, -321.8,  1903.4, -1012.5,
        499.2, -1728.6,  908.1,   -45.7,  1612.9,

        // repeat block (3)
        -1345.2,  987.4,  -412.8,  1765.9,  -89.3,
        1540.6, -1987.1,  645.2,   312.7, -1650.4,
        428.9, -743.5,  1899.8,  -256.1,  1023.6,
        -1784.9,   95.4,  1678.3, -1198.6,   560.1,
        -342.7,  1432.8, -188.9, -1567.2,   734.5,
        198.6, -923.4,  1820.7, -134.2,  1299.1,
        -167.5,   876.2, -1945.8,  158.4,  1120.6,
        -684.9,  1405.7, -321.8,  1903.4, -1012.5,
        499.2, -1728.6,  908.1,   -45.7,  1612.9,

        // repeat block (4)
        -1345.2,  987.4,  -412.8,  1765.9,  -89.3,
        1540.6, -1987.1,  645.2,   312.7, -1650.4,
        428.9, -743.5,  1899.8,  -256.1,  1023.6,
        -1784.9,   95.4,  1678.3, -1198.6,   560.1,
        -342.7,  1432.8, -188.9, -1567.2,   734.5,
        198.6, -923.4,  1820.7, -134.2,  1299.1,
        -167.5,   876.2, -1945.8,  158.4,  1120.6,
        -684.9,  1405.7, -321.8,  1903.4, -1012.5,
        499.2, -1728.6,  908.1,   -45.7,  1612.9,

        // final element (201st)
        512.0
    };


    std::vector<double> x = {
        0, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110,
        120, 130, 140, 150, 160, 170, 180, 190, 200, 210,
        220, 230, 240, 250, 260, 270, 280, 290, 300, 310,
        320, 330, 340, 350, 360, 370, 380, 390, 400, 410,
        420, 430, 440, 450, 460, 470, 480, 490, 500, 510,
        520, 530, 540, 550, 560, 570, 580, 590, 600, 610,
        620, 630, 640, 650, 660, 670, 680, 690, 700, 710,
        720, 730, 740, 750, 760, 770, 780, 790, 800, 810,
        820, 830, 840, 850, 860, 870, 880, 890, 900, 910,
        920, 930, 940, 950, 960, 970, 980, 990, 1000, 1010,
        1020, 1030, 1040, 1050, 1060, 1070, 1080, 1090, 1100, 1110,
        1120, 1130, 1140, 1150, 1160, 1170, 1180, 1190, 1200, 1210,
        1220, 1230, 1240, 1250, 1260, 1270, 1280, 1290, 1300, 1310,
        1320, 1330, 1340, 1350, 1360, 1370, 1380, 1390, 1400, 1410,
        1420, 1430, 1440, 1450, 1460, 1470, 1480, 1490, 1500, 1510,
        1520, 1530, 1540, 1550, 1560, 1570, 1580, 1590, 1600, 1610,
        1620, 1630, 1640, 1650, 1660, 1670, 1680, 1690, 1700, 1710,
        1720, 1730, 1740, 1750, 1760, 1770, 1780, 1790, 1800, 1810,
        1820, 1830, 1840, 1850, 1860, 1870, 1880, 1890, 1900, 1910,
        1920, 1930, 1940, 1950, 1960, 1970, 1980, 1990, 2000, 3000
    };

    td::String xOsa="x";
    td::String yOsa="y";
    double thickness=2.0;
public:
    LineGraph(double thickness=2.0):thickness(thickness)
    {
        //setX(0);
        //setY(1);
    }
    std::vector <std::shared_ptr<gui::Shape>> &Graph(){return graf;}

    void drawCoordinates(const gui::Size& sz, int zeroPos, int xmult=1)
    {
        const gui::CoordType c_dx = 0;
        gui::CoordType arrH = 6;
        gui::CoordType arrW = 10;
        //x osa
        gui::Point p1(c_dx, zeroPos);
        gui::Point p2(getXmax()*xmult, zeroPos);
        gui::Shape::drawLine(p1, p2, td::ColorID::SysText, 0);
        //strelica x
        p1.x = p2.x - arrW;
        p1.y = p2.y - arrH;
        gui::Shape::drawLine(p1, p2, td::ColorID::SysText, 0);
        p1.y = p2.y + arrH;
        gui::Shape::drawLine(p1, p2, td::ColorID::SysText, 0);
        p1.x = p2.x - 2*arrW;
        gui::DrawableString(xOsa).draw(p1, gui::Font::ID::SystemLargest, td::ColorID::SysText);

        //y osa
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
        gui::DrawableString(yOsa).draw({p1.x+5,p1.y+5}, gui::Font::ID::SystemLargest, td::ColorID::SysText);
    }

    void Draw(const gui::Size& sz, int zeroPos, int xmult=1, td::ColorID color=td::ColorID::Yellow){
        graf.clear();
        double zeroPosition=mapValues(0, sz);
        drawCoordinates(sz, zeroPosition, xmult);
        for(int i=1; i<y.size();i++){
            graf.push_back(std::make_shared<gui::Shape>());
            graf[i-1]->createBezier(thickness,td::LinePattern::Solid).moveTo({x[i-1]*xmult+5,
            mapValues(y[i-1], sz)}).lineTo({x[i]*xmult+5,mapValues(y[i], sz)});
        }
        for(int i=0; i<graf.size();i++){
            graf[i]->drawWire(color);
        }
    }

    double mapValues(double y, const gui::Size& sz){
        double mapped=0;
        double bottom=(getYmin()<=0)?getYmin():-10;
        double top=(getYmax()>=0)?getYmax():10;
        mapped=sz.height+(y - bottom)*(0-sz.height)/(top-bottom);
        return mapped;
    }

    int getXnum()const{return x.size();}
    int getYnum()const{return y.size();}

    double getXmax()const{return 2000;}
    double getYmax()const{return 2000;}
    double getXmin()const{return 0;}
    double getYmin()const{return -2000;}

    td::String getXname()const{return xOsa;}
    td::String getYname()const{return yOsa;}

    void setX(int xid){
        //xData=nullptr;
        x_id=xid;
        auto types=Data::instance().getTypes();
        xOsa=types[xid];
        dp::IDataSetPtr xData = Data::instance().getDB()->createDataSet("SELECT m.value FROM measurement m, data_type dt WHERE dt.id=m.data_type_id AND dt.name=?;", dp::IDataSet::Execution::EX_MULT);
        dp::Params par(xData->allocParams());
        td::Variant strVar(td::string8, td::nch, 40);
        strVar.setValue(xOsa);
        par << strVar;

        dp::DSColumns colsX(xData->allocBindColumns(1));
        colsX << "value" << td::real8;

        if (!xData->execute())
        {
            //show log
            mu::dbgLog("a");
            xData = nullptr;
            return;
        }
    }
    void setY(int yid){
        //yData=nullptr;
        y_id=yid;
        auto types=Data::instance().getTypes();
        yOsa=types[yid];
        yData = Data::instance().getDB()->createDataSet("SELECT m.value FROM measurement m, data_type dt WHERE dt.id=m.data_type_id AND dt.name=?;", dp::IDataSet::Execution::EX_MULT);
        dp::Params par(yData->allocParams());
        td::Variant strVar(td::string8, td::nch, 40);
        strVar.setValue(yOsa);
        par << strVar;

        dp::DSColumns colsX(yData->allocBindColumns(1));
        colsX << "value" << td::real8;

        if (!yData->execute())
        {
            //show log
            mu::dbgLog("a");
            yData = nullptr;
            return;
        }

    }



};
