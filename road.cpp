#include "road.h"

Road::Road(int i)
{
    if(i==0){
        this->length=50;
        this->Nummber=0;
        this->endPointA = 0;
        this->endPointB = 1;
        this->pointNumber = 2;
        this->pointList.push_back(QPoint(462,886));
        this->pointList.push_back(QPoint(514,861));
    }
    else if(i==1) {
        this->length=100;
        this->Nummber=1;
        this->endPointA = 0;
        this->endPointB = 6;
        this->pointNumber = 2;
        this->pointList.push_back(QPoint(462,886));
        this->pointList.push_back(QPoint(462,667));
    }
    else if(i==2){
        this->length=100;
        this->Nummber=2;
        this->endPointA = 12;
        this->endPointB = 14;
        this->pointNumber = 2;
        this->pointList.push_back(QPoint(514,861));
        this->pointList.push_back(QPoint(462,667));
    }else if(i==3){
        this->pointList.push_back(QPoint(41,733));
        this->pointList.push_back(QPoint(278,659));
    }else if(i==4){
        this->pointList.push_back(QPoint(41,733));
        this->pointList.push_back(QPoint(243,563));
    }else if(i==5){
        this->pointList.push_back(QPoint(310,679));
        this->pointList.push_back(QPoint(278,659));
    }else if(i==6){
        this->pointList.push_back(QPoint(278,659));
        this->pointList.push_back(QPoint(342,660));
    }else if(i==7){
        this->pointList.push_back(QPoint(278,659));
        this->pointList.push_back(QPoint(243,563));
    }else if(i==8){
        this->pointList.push_back(QPoint(342,660));
        this->pointList.push_back(QPoint(372,559));
    }else if(i==9){
        this->pointList.push_back(QPoint(342,660));
        this->pointList.push_back(QPoint(462,667));
    }else if(i==10){
        this->pointList.push_back(QPoint(462,667));
        this->pointList.push_back(QPoint(580,660));
    }else if(i==11){
        this->pointList.push_back(QPoint(462,667));
        this->pointList.push_back(QPoint(459,529));
    }else if(i==12){
        this->pointList.push_back(QPoint(462,667));
        this->pointList.push_back(QPoint(267,377));
    }else if(i==13){
        this->pointList.push_back(QPoint(462,667));
        this->pointList.push_back(QPoint(372,559));
    }else if(i==14){
        this->pointList.push_back(QPoint(462,667));
        this->pointList.push_back(QPoint(474,329));
    }else if(i==15){
        this->pointList.push_back(QPoint(580,660));
        this->pointList.push_back(QPoint(632,658));
    }else if(i==16){
        this->pointList.push_back(QPoint(580,660));
        this->pointList.push_back(QPoint(459,529));
    }else if(i==17){
        this->pointList.push_back(QPoint(580,660));
        this->pointList.push_back(QPoint(267,377));
    }else if(i==18){
        this->pointList.push_back(QPoint(580,660));
        this->pointList.push_back(QPoint(474,329));
    }else if(i==19){
        this->pointList.push_back(QPoint(243,563));
        this->pointList.push_back(QPoint(239,517));
    }else if(i==20){
        this->pointList.push_back(QPoint(243,563));
        this->pointList.push_back(QPoint(284,534));
    }else if(i==21){
        this->pointList.push_back(QPoint(372,559));
        this->pointList.push_back(QPoint(335,492));
    }else if(i==22){
        this->pointList.push_back(QPoint(459,529));
        this->pointList.push_back(QPoint(267,377));
    }else if(i==23){
        this->pointList.push_back(QPoint(459,529));
        this->pointList.push_back(QPoint(474,329));
    }else if(i==24){
        this->pointList.push_back(QPoint(239,517));
        this->pointList.push_back(QPoint(280,497));
    }else if(i==25){
        this->pointList.push_back(QPoint(239,517));
        this->pointList.push_back(QPoint(288,460));
    }else if(i==26){
        this->pointList.push_back(QPoint(239,517));
        this->pointList.push_back(QPoint(234,414));
    }else if(i==27){
        this->pointList.push_back(QPoint(283,534));
        this->pointList.push_back(QPoint(280,497));
    }else if(i==28){
        this->pointList.push_back(QPoint(280,497));
        this->pointList.push_back(QPoint(335,492));
    }else if(i==29){
        this->pointList.push_back(QPoint(280,497));
        this->pointList.push_back(QPoint(288,460));
    }else if(i==30){
        this->pointList.push_back(QPoint(335,492));
        this->pointList.push_back(QPoint(288,460));
    }else if(i==31){
        this->pointList.push_back(QPoint(288,460));
        this->pointList.push_back(QPoint(234,414));
    }else if(i==32){
        this->pointList.push_back(QPoint(234,414));
        this->pointList.push_back(QPoint(236,363));
    }else if(i==33){
        this->pointList.push_back(QPoint(267,377));
        this->pointList.push_back(QPoint(236,363));
    }else if(i==34){
        this->pointList.push_back(QPoint(267,377));
        this->pointList.push_back(QPoint(474,329));
    }else if(i==35){
        this->pointList.push_back(QPoint(65,335));
        this->pointList.push_back(QPoint(129,365));
    }else if(i==36){
        this->pointList.push_back(QPoint(65,335));
        this->pointList.push_back(QPoint(236,363));
    }else if(i==37){
        this->pointList.push_back(QPoint(65,335));
        this->pointList.push_back(QPoint(474,329));
    }else if(i==38){
        this->pointList.push_back(QPoint(65,335));
        this->pointList.push_back(QPoint(98,251));
    }else if(i==39){
        this->pointList.push_back(QPoint(65,335));
        this->pointList.push_back(QPoint(228,248));
    }else if(i==40){
        this->pointList.push_back(QPoint(65,335));
        this->pointList.push_back(QPoint(235,222));
    }else if(i==41){
        this->pointList.push_back(QPoint(129,365));
        this->pointList.push_back(QPoint(236,363));
    }else if(i==42){
        this->pointList.push_back(QPoint(129,365));
        this->pointList.push_back(QPoint(474,329));
    }else if(i==43){
        this->pointList.push_back(QPoint(129,365));
        this->pointList.push_back(QPoint(98,251));
    }else if(i==44){
        this->pointList.push_back(QPoint(129,365));
        this->pointList.push_back(QPoint(338,248));
    }else if(i==45){
        this->pointList.push_back(QPoint(129,365));
        this->pointList.push_back(QPoint(235,222));
    }else if(i==46){
        this->pointList.push_back(QPoint(236,363));
        this->pointList.push_back(QPoint(474,329));
    }else if(i==47){
        this->pointList.push_back(QPoint(236,363));
        this->pointList.push_back(QPoint(98,251));
    }else if(i==48){
        this->pointList.push_back(QPoint(236,363));
        this->pointList.push_back(QPoint(338,248));
    }else if(i==49){
        this->pointList.push_back(QPoint(236,363));
        this->pointList.push_back(QPoint(235,222));
    }else if(i==50){
        this->pointList.push_back(QPoint(474,329));
        this->pointList.push_back(QPoint(98,251));
    }else if(i==51){
        this->pointList.push_back(QPoint(474,329));
        this->pointList.push_back(QPoint(338,248));
    }else if(i==52){
        this->pointList.push_back(QPoint(474,329));
        this->pointList.push_back(QPoint(235,222));
    }else if(i==53){
        this->pointList.push_back(QPoint(474,329));
        this->pointList.push_back(QPoint(474,262));
    }else if(i==54){
        this->pointList.push_back(QPoint(98,251));
        this->pointList.push_back(QPoint(338,248));
    }else if(i==55){
        this->pointList.push_back(QPoint(98,251));
        this->pointList.push_back(QPoint(235,222));
    }else if(i==56){
        this->pointList.push_back(QPoint(338,248));
        this->pointList.push_back(QPoint(235,222));
    }else if(i==57){
        this->pointList.push_back(QPoint(338,248));
        this->pointList.push_back(QPoint(474,262));
    }else if(i==58){
        this->pointList.push_back(QPoint(235,222));
        this->pointList.push_back(QPoint(236,136));
    }


}
