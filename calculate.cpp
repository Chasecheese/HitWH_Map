#include "calculate.h"

Calculate::Calculate()
{

}

void Calculate::init(){
    ifstream in;
    in.open("D:\\data.txt");
    for(int i=0;i<28;i++){
        for(int j=0;j<28;j++){
            in>>Map[i][j];
            Dist[i][j]=Map[i][j];
            if(Dist[i][j]!=-1&&Dist[i][j]!=0){
                x[i][j].push_back()
            }
        }
    }
    in.close();
}

void Calculate::Floyd(){
    init();
    //第一层循环选中介
    for(int k=0;k<28;k++){
        //第二层循环选择使用该中介要改造的行
        for(int i=0;i<28;i++){
            //第三层循环，改造改行的每一个元素
            for(int j=0;j<28;j++){
                if(Dist[i][j]!=-1&&Dist[i][k]!=-1&&Dist[k][j]!=-1){
                    if(Dist[i][j]>Dist[i][k]+Dist[k][j]){
                        Dist[i][j] = Dist[i][k]+Dist[k][j];
                        updateRoute(Dist[i][j],Dist[i][k],Dist[k][j]);
                    }
                }else if(Dist[i][j]==-1&&Dist[i][k]!=-1&&Dist[k][j]!=-1){
                    Dist[i][j] = Dist[i][k]+Dist[k][j];
                    updateRoute(Dist[i][j],Dist[i][k],Dist[k][j]);
                }
            }
        }
    }
}


void Calculate::updateRoute(int old, int newr1, int newr2){

}

vector<Road> Calculate::getRoadList(vector<int> location){

    //模拟计算
    vector<int> roadlist = getRoadNum(location);
    //得到路径的编号列表

    vector<Road> temp;

    for(unsigned long long i=0;i<roadlist.size();i++){
        temp.push_back(Road().getRoad(i));
    }
    init();
    return temp;
}



//通过结点编号获取路径编号
vector<int> Calculate::getRoadNum(vector<int> location){
    vector<int> temp;
    for(int i=0;i<58;i++)
    temp.push_back(i);
    return temp;
}
