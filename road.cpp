#include "road.h"

Road::Road(){
    Number = -1;
    pointNumber = -1;
    length = -1;
}

int Road::getEndPointB() const
{
    return endPointB;
}

void Road::setEndPointB(int value)
{
    endPointB = value;
}

int Road::getEndPointA() const
{
    return endPointA;
}

void Road::setEndPointA(int value)
{
    endPointA = value;
}

unsigned long long Road::getPointNumber() const
{
    return pointNumber;
}

void Road::setPointNumber(unsigned long long value)
{
    pointNumber = value;
}

vector<QPoint> Road::getPointList() const
{
    return pointList;
}

void Road::setPointList(const vector<QPoint> &value)
{
    pointList = value;
}

float Road::getLength() const
{
    return length;
}

void Road::setLength(float value)
{
    length = value;
}

int Road::getNumber() const
{
    return Number;
}

void Road::setNumber(int value)
{
    Number = value;
}

