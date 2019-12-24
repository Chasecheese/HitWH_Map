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
    void Floyd();

    int Dist[27][27];

    int Map[27][27];

    void init();
private:

};

#endif // CALCULATE_H
