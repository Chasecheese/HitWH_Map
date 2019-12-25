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

void Calculate::floyd(){
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

    ofstream pout;//打印路径表
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

    floyd();
    vector<Road> temp;//返回location-1条路径
    if(location.size()>=1){
        for(unsigned long long i=0;i<location.size()-1;i++){
            temp.push_back(serachRoadNum(location.at(i),location.at(i+1)));
        }
    }
    return temp;
}

Road Calculate::serachRoadNum(int i,int j){
    for(unsigned long long k=0;k<=58;k++){
        if((roadCollection.at(k).endPointA==i)&&(roadCollection.at(k).endPointB==j)){
            return roadCollection.at(k);
        }
        if((roadCollection.at(k).endPointA==j)&&(roadCollection.at(k).endPointB==i)){
            return roadCollection.at(k);
        }
    }
    return Road();
}
