#include "calculate.h"

Calculate::Calculate()
{

}

void Calculate::init(){
    ifstream in0;
    in0.open("D:\\distData.txt");
    for(int i=0;i<=27;i++){
        for(int j=0;j<=27;j++){
            in0>>Map[i][j];
            Dist[i][j]=Map[i][j];
            //初始邻接矩阵
        }
    }
    in0.close();

    for(int i=0;i<=27;i++){
        for(int j=0;j<=27;j++){
            if(Dist[i][j]!=0&&Dist[i][j]!=-1){
                path[i][j].push_back(i);
                path[i][j].push_back(j);
            }
        }
    }

    ifstream in;
    roadCollection.clear();
    in.open("D:\\roadData.txt");
    for(int i=0;i<=58;i++){
        Road tempRoad;
        in>>tempRoad.Nummber;
        in>>tempRoad.length;
        in>>tempRoad.endPointA;
        in>>tempRoad.endPointB;
        in>>tempRoad.pointNumber;
        int x,y;
        for(int j=0;j<static_cast<int>(tempRoad.pointNumber);j++){
            in>>x;
            in>>y;
            tempRoad.pointList.push_back(QPoint(x,y));
        }
        roadCollection.push_back(tempRoad);
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
                        updateRoute(i,k,j);
                    }
                }else if(Dist[i][j]==-1&&Dist[i][k]!=-1&&Dist[k][j]!=-1){
                    Dist[i][j] = Dist[i][k]+Dist[k][j];
                    updateRoute(i,k,j);
                }
            }
        }
    }

    ofstream out;
    out.open("D:\\floyd.txt");
    for(unsigned long long i=0;i<=27;i++){
        for(unsigned long long k=0;k<=27;k++){
            out<<Dist[i][k]<<"\t";
        }
        out<<endl;
    }
    out.close();

    ofstream pout;
    pout.open("D:\\path.txt");
    for(unsigned long long i=0;i<=27;i++){
        for(unsigned long long j=0;j<=27;j++){
            for(unsigned long long k=0;k<path[i][j].size();k++){
                pout<<path[i][j].at(k)<<"->";
            }
            pout<<"#\t";
        }
        pout<<"\n";
    }

}


void Calculate::updateRoute(int i,int k,int j){
    path[i][j].clear();
    for(unsigned long long t=0;t<path[i][k].size();t++){
        path[i][j].push_back(path[i][k].at(t));
    }
    for(unsigned long long t=0;t<path[k][j].size();t++){
        path[i][j].push_back(path[k][j].at(t));
    }
}

vector<Road> Calculate::getRoadList(vector<int> location){

    //模拟计算
    vector<int> roadlist = getRoadNum(location);
    //得到路径的编号列表

    vector<Road> temp;

    for(unsigned long long i=0;i<roadlist.size();i++){

    }
    Floyd();
    return temp;
}

//通过结点编号获取路径编号
vector<int> Calculate::getRoadNum(vector<int> location){
    vector<int> temp;
    for(int i=0;i<58;i++)
    temp.push_back(i);
    return temp;
}
