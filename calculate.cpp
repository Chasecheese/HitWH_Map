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
    hashTable.InitHashTable();
    in.open("D:\\roadData.txt");
    for(int i=0;i<=59;i++){
        Road tempRoad;
        int number;
        in>>number;
        tempRoad.setNumber(number);
        float length;
        in>>length;
        tempRoad.setLength(length);
        int endPointA;
        in>>endPointA;
        tempRoad.setEndPointA(endPointA);
        int endPointB;
        in>>endPointB;
        tempRoad.setEndPointB(endPointB);
        unsigned long long pointNumber;
        in>>pointNumber;
        tempRoad.setPointNumber(pointNumber);
        int x,y;
        vector<QPoint> pointList;
        for(int j=0;j<static_cast<int>(tempRoad.getPointNumber());j++){
            in>>x;
            in>>y;
            pointList.push_back(QPoint(x,y));
            tempRoad.setPointList(pointList);
        }
        roadCollection.push_back(tempRoad);
        hashTable.insertHash(tempRoad);
    }


    ofstream rout;
    rout.open("D:\\roadData_copy.txt");
    for(unsigned long long i=0;i<=59;i++){
        Road tempRoad = roadCollection.at(i);
        rout<<tempRoad.getNumber()<<"\t";
        rout<<tempRoad.getLength()<<"\t";
        rout<<tempRoad.getEndPointA()<<"\t";
        rout<<tempRoad.getEndPointB()<<"\t";
        rout<<tempRoad.getPointNumber()<<"\t";
        for(unsigned long long j=0;j<tempRoad.getPointNumber();j++){
            rout<<tempRoad.getPointList().at(j).x()<<"\t";
            rout<<tempRoad.getPointList().at(j).y()<<"\t";
        }
        rout<<"\n";
    }

    ofstream hout;
    hout.open("D:\\roadData_hash.txt");

    for(unsigned long long i=0;i<hashTable.getLength();i++){
        if(hashTable.road[i].getNumber()!=-1){
            hout<<hashTable.road[i].getNumber()<<"\t";
            hout<<hashTable.road[i].getLength()<<"\t";
            hout<<hashTable.road[i].getEndPointA()<<"\t";
            hout<<hashTable.road[i].getEndPointB()<<"\t";
            hout<<hashTable.road[i].getPointNumber()<<"\t";
            for(unsigned long long j=0;j<hashTable.road[i].getPointNumber();j++){
                hout<<hashTable.road[i].getPointList().at(j).x()<<"\t";
                hout<<hashTable.road[i].getPointList().at(j).y()<<"\t";
            }
            hout<<"\n";
        }
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
    vector<Road> temp_return;//返回location-1条路径

    if(location.size()>=1){
        for(unsigned long long i=0;i<location.size()-1;i++){
            vector<Road> temp;
            temp.clear();
            temp = serachRoad(location.at(i),location.at(i+1));
            for(unsigned long long c=0;c<temp.size();c++){
                temp_return.push_back(temp.at(c));
            }
        }
    }

    return temp_return;
}

vector<Road> Calculate::serachRoad(int i,int j){
    vector<Road> temp;
    for(unsigned long long k=0;k<path[i][j].size();k=k+2){
        temp.push_back((serachRoadNum(path[i][j].at(k),path[i][j].at(k+1))));
    //    unsigned long long addr = hashTable.searchHash(path[i][j].at(k),path[i][j].at(k+1));
//        temp.push_back(hashTable.road[addr]);

    }
    return temp;
}

Road Calculate::serachRoadNum(int i, int j){
    for(unsigned long long k=0;k<=58;k++){
            if((roadCollection.at(k).getEndPointA()==i)&&(roadCollection.at(k).getEndPointB()==j)){
                return roadCollection.at(k);
            }
            if((roadCollection.at(k).getEndPointA()==j)&&(roadCollection.at(k).getEndPointB()==i)){
                return roadCollection.at(k);
            }
    }
    return roadCollection.at(59);
}
