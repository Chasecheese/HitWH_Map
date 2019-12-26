#ifndef CALCULATE_H
#define CALCULATE_H

#include <vector>
#include <road.h>
#include <fstream>
#include <iostream>
#include <hashtable.h>
using namespace std;

class Calculate
{
public:
    Calculate();

    vector<Road> getRoadList(vector<int> location);
    void floyd();
    void updateRoute(int old,int newr1,int newr2);
    vector<Road> serachRoad(int i,int j);
    Road serachRoadNum(int i,int j);
    void init();

    int Dist[28][28];
    vector<int> path[28][28];
    int Map[28][28];
    vector<Road> roadCollection;
    HashTable hashTable = HashTable(100);

private:

};



#endif // CALCULATE_H
