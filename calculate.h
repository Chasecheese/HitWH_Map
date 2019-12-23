#ifndef CALCULATE_H
#define CALCULATE_H

#include <vector>
#include <road.h>
class Calculate
{
public:
    Calculate();
    vector<Road> getRoadList(vector<int> location);
    vector<int> getRoadNum(vector<int> location);
private:

};

#endif // CALCULATE_H
