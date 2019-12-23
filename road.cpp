#include "road.h"

Road::Road(int i)
{
    if(i==1){
        this->length=50;
        this->Nummber=1;
        this->endPointA = 1;
        this->endPointB = 2;
        this->pointNumber = 2;
        this->pointList.push_back(QPoint(490,160));
        this->pointList.push_back(QPoint(360,340));
    }
    else if(i==2) {
        this->length=100;
        this->Nummber=2;
        this->endPointA = 2;
        this->endPointB = 3;
        this->pointNumber = 2;
        this->pointList.push_back(QPoint(360,340));
        this->pointList.push_back(QPoint(230,230));
    }
    else {
        this->length=100;
        this->Nummber=3;
        this->endPointA = 3;
        this->endPointB = 1;
        this->pointNumber = 2;
        this->pointList.push_back(QPoint(230,230));
        this->pointList.push_back(QPoint(490,160));
    }

}
