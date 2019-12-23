#include "route.h"

Route::Route()
{

}
vector<Road> Route::getRoute(){

    vector<Road> temp;
    temp.push_back(Road(1));
    temp.push_back(Road(2));
    return temp;
}
