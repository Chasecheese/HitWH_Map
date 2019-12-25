#ifndef ROAD_H
#define ROAD_H

#include <QPoint>
#include <vector>
using namespace std;
class Road //任意两点之间的道路，一般包括多个拐点
{
public:
    Road();
    int getNumber() const;
    void setNumber(int value);

    float getLength() const;
    void setLength(float value);

    vector<QPoint> getPointList() const;
    void setPointList(const vector<QPoint> &value);

    unsigned long long getPointNumber() const;
    void setPointNumber(unsigned long long value);

    int getEndPointA() const;
    void setEndPointA(int value);

    int getEndPointB() const;
    void setEndPointB(int value);

private:
    int Number;            //路径编号
    float length;           //路径长度
    vector<QPoint> pointList;     //拐点坐标容器
    unsigned long long pointNumber;      //点数量
    int endPointA;
    int endPointB;//端点A，端点B

};

#endif // ROAD_H
