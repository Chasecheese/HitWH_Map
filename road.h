#ifndef ROAD_H
#define ROAD_H

#include <QPoint>
#include <vector>
using namespace std;
class Road //任意两点之间的道路，一般包括多个拐点
{
public:
    Road(int i);
    int Nummber;            //路径编号
    float length;           //路径长度
    vector<QPoint> pointList;     //拐点容器
    unsigned long long pointNumber;      //点数量
    int endPointA,endPointB;//端点A，端点B
    string roadName;
};

#endif // ROAD_H
