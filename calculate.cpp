#include "calculate.h"

Calculate::Calculate()
{

}

void Calculate::init(){

}


vector<Road> Calculate::getRoadList(vector<int> location){

    //模拟计算
    vector<int> roadlist = getRoadNum(location);
    //得到路径的编号列表

    vector<Road> temp;

    for(unsigned long long i=0;i<roadlist.size();i++){
        temp.push_back(Road().getRoad(i));
    }
    return temp;
}



//通过结点编号获取路径编号
vector<int> Calculate::getRoadNum(vector<int> location){
    vector<int> temp;

    for(int i=0;i<58;i++)
    temp.push_back(i);
    return temp;
}
