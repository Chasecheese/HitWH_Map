#include "road.h"

Road::Road(int i)
{
    if(i==1){
        this->length=50;
        this->Nummber=1;
        this->endPointA = 1;
        this->endPointB = 2;
        this->pointNumber = 3;
        this->pointList.push_back(QPoint(360,340));
        this->pointList.push_back(QPoint(490,160));
        this->pointList.push_back(QPoint(230,230));
    }
    else {
        this->length=100;
        this->Nummber=2;
        this->endPointA = 3;
        this->endPointB = 4;
        this->pointNumber = 3;
        this->pointList.push_back(QPoint(360,400));
        this->pointList.push_back(QPoint(490,220));
        this->pointList.push_back(QPoint(230,290));
    }

}
