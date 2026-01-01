//
//  Created by Izudin Dzafic on 28/07/2020.
//  Copyright © 2020 IDz. All rights reserved.
//
#pragma once
#include <vector>
#include <memory>
#include <gui/Canvas.h>
#include <gui/Shape.h>



class LineGraph{
    std::vector <std::shared_ptr<gui::Shape>>graf;
    std::vector<double> x = {
        345, 78, 512, 220, 489, 61, 590, 134, 402, 275,
        98, 560, 310, 44, 225, 480, 365, 150, 520, 295,
        410, 200, 555, 90, 330, 470, 260, 35, 585, 185,
        440, 120, 505, 390, 65, 540, 215, 460, 170, 600,
        285, 425, 105, 350, 245, 575, 160, 495, 30, 380
    };

    std::vector<double> y = {
        20, 30, 40, 50, 60, 70, 80, 90, 100, 110,
        120, 130, 140, 150, 160, 170, 180, 190, 200, 210,
        220, 230, 240, 250, 260, 270, 280, 290, 300, 310,
        320, 330, 340, 350, 360, 370, 380, 390, 400, 410,
        420, 430, 440, 450, 460, 470, 480, 490, 500, 600
    };

public:
    LineGraph(double thickness=2.0)
    {
        for(int i=1; i<y.size();i++){
            graf.push_back(std::make_shared<gui::Shape>());
            graf[i-1]->createBezier(thickness,td::LinePattern::Solid).moveTo({y[i-1],x[i-1]}).lineTo({y[i],x[i]});
        }
    }
    std::vector <std::shared_ptr<gui::Shape>> &Graph(){return graf;}

    void Draw(){
        for(int i=0; i<graf.size();i++){
            graf[i]->drawWire(td::ColorID::White);
        }
    }

};
