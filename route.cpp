#include "route.h"

Route::Route()
{

}

vector<Road> Route::getRoute(vector<int> location){
    vector<Road> temp;
    temp = calculate.getRoadList(location);
    return temp;
}


