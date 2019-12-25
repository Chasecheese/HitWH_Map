#ifndef CALCULATE_H
#define CALCULATE_H

#include <vector>
#include <road.h>
#include <fstream>
#include <iostream>

using namespace std;

class Calculate
{
public:
    Calculate();
    vector<Road> getRoadList(vector<int> location);
    vector<int> getRoadNum(vector<int> location);

    void Floyd();
    void updateRoute(int old,int newr1,int newr2);

    int Dist[28][28];
    vector<int> x[28][28];
    int Map[28][28];
    vector<Road> roadCollection;
    void init();
private:

};

#endif // CALCULATE_H
