#include "calculate.h"

Calculate::Calculate()
{

}

vector<Road> Calculate::getRoadList(vector<int> location){

    //模拟计算
    vector<int> roadlist = getRoadNum(location);
    //得到路径的编号列表

    vector<Road> temp;

    for(unsigned long long i=0;i<roadlist.size();i++){
        temp.push_back(Road(roadlist.at(i)));
    }
    return temp;
}

vector<int> Calculate::getRoadNum(vector<int> location){
    vector<int> temp;
    temp.push_back(location.at(0));
    temp.push_back(location.at(1));
    temp.push_back(location.at(2));
    return temp;
}
