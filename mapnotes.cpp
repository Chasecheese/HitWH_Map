#include "mapnotes.h"
#include "ui_mapnotes.h"



MapNotes::MapNotes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapNotes)
{
    ui->setupUi(this);  
    ui->HidenButton->setVisible(false);
    ifstream in;
    ifstream namein;
    in.open("D:\\points.txt");
    namein.open("D:\\name.txt");
    int x,y;


    for(int i=0;i<33;i++){
        Build[i] = new Mybtn(this);
        in>>x;
        in>>y;
        namein>>name[i];
        Build[i]->move(x,y);
        Build[i]->setStyleSheet("color: white");
        Build[i]->setObjectName(QString::number(i));
        connect(Build[i],SIGNAL(clickedOnce()),this,SLOT(push()));
        connect(Build[i],SIGNAL(clickedTwice()),this,SLOT(doubleClicked()));
        Build[i]->setStyleSheet("QRadioButton::indicator {width:15px;height:15px;border-radius:7px}"
                                            "QRadioButton::indicator:checked {background-color:yellow;}"
                                            "QRadioButton::indicator:unchecked {background-color:white;}"
                                            );
    }

    connect(this,SIGNAL(setHide()),this,SLOT(chooseHiden()));
    in.close();
    namein.close();
}
void MapNotes::mousePressEvent(QMouseEvent *event){
    QPoint p_re = event->pos();
    QString str;
    str = QString("%1 , %2").arg(p_re.x()).arg(p_re.y());
    ui->label->setText(str);
}
void MapNotes::updateMapNotes(){

    noteNum.setLength(0);
    re = route.getRoute(location);
    update();
}

void MapNotes::clear(){
   location.clear();
   trans.clear();
   emit updateName(trans);
   updateMapNotes();
}

void MapNotes::updateText(string name){
    if(trans.length()>0)
        trans+="->";
    trans+=name;
    emit updateName(trans);
}


void MapNotes::paintEvent(QPaintEvent *){
    QPainter painter(this);
    // 设置画笔颜色
    static const QRgb colorTable[6] = {
        0xFFA500, 0xCC6666, 0x66CC66, 0x00BFFF,
               0xBDB76B, 0xCC66CC
    };
    //调色板
    int j=0;
    QPen pen;
    pen.setWidth(5);
    QColor squreColor = colorTable[j++];//绘制bubble
    pen.setColor(squreColor.light());
    painter.setPen(pen);
    painter.setBrush(squreColor);
    //按照坐标绘制路线
    QPoint* C;
    for(unsigned long long i=0;i<re.size();i++){
        if(re.at(i).getPointNumber()==static_cast<unsigned long long>(-1)){
            squreColor = colorTable[j++%6];
            pen.setColor(squreColor.light());
            painter.setPen(pen);
            painter.setBrush(squreColor);
        }
        else{
            C = new QPoint[re.at(i).getPointNumber()];
            for(unsigned long long j=0;j<re.at(i).getPointNumber();j++){
                C[j] = re.at(i).getPointList().at(j);
            }
            painter.drawPolyline(C,static_cast<int>(re.at(i).getPointNumber()));
        }
    }

    squreColor = colorTable[1];
    pen.setColor(squreColor.light());
    painter.setPen(pen);
    painter.setBrush(squreColor);
    for(int i= 1;i<=noteNum.ListLength();i++){
        int temp;
        noteNum.GetElem(i,temp);
        painter.drawRect(Build[temp]->x(),Build[temp]->y(),20,20);
    }
}

vector<Road> MapNotes::getRe() const
{
    return re;
}

void MapNotes::setRe(const vector<Road> &value)
{
    re = value;
}


MapNotes::~MapNotes()
{
    delete ui;
}

void MapNotes::push(){
    Mybtn* btn = qobject_cast<Mybtn*>(sender());
    int num = btn->objectName().toInt();
    updateText(name[num]);
    switch (num) {
    case 28:
        location.push_back(15);
        break;
    case 29:
        location.push_back(20);
        break;
    case 30:
        location.push_back(21);
        break;
    case 31:
        location.push_back(26);
        break;
    case 32:
        location.push_back(25);
        break;
    default:
        if(num<=27)
        location.push_back(num);
        break;
    }
    emit setHide();
}


void MapNotes::doubleClicked(){
    Mybtn* btn = qobject_cast<Mybtn*>(sender());
    int num = btn->objectName().toInt();
    qDebug()<<num;
    Build[num]->setCheckable(false);
    emit setHide();
}

void MapNotes::chooseHiden(){
    this->ui->HidenButton->setChecked(true);
}

void MapNotes::updateNotes(List list){
    noteNum = list;
    update();
}

