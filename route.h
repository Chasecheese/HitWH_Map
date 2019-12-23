#ifndef ROUTE_H
#define ROUTE_H

#include <QPoint>
#include <calculate.h>
#include <vector>
#include <road.h>
using namespace std;

class Route
{
public:
    Calculate calculate;
    Route();
    vector<Road> getRoute();
};

#endif // ROUTE_H
