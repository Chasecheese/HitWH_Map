#include "mapnotes.h"
#include "ui_mapnotes.h"



MapNotes::MapNotes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapNotes)
{
    ui->setupUi(this);  
    ifstream in;
    in.open("D:\\points.txt");
    int x,y;
    for(int i=0;i<28;i++){
        Build[i] = new QRadioButton(this);
        in>>x;
        in>>y;
        Build[i]->move(x,y);
        Build[i]->setText(QString::number(i));
        Build[i]->setObjectName(QString::number(i));
        connect(Build[i],SIGNAL(clicked()),this,SLOT(push()));
//        connect(Build[i],SIGNAL(pressed()),this,SLOT(countTime()));
//        connect(Build[i],SIGNAL(released()),this,SLOT(timestop()));
    }
//    connect(this,SIGNAL(timeout(int)),this,SLOT(longTimePress(int)));
    connect(this,SIGNAL(twice(int)),this,SLOT(doubleClicked(int)));
    timer = new QTimer();
}
void MapNotes::mousePressEvent(QMouseEvent *event){
    QPoint p_re = event->pos();
    QString str;
    str = QString("%1 , %2").arg(p_re.x()).arg(p_re.y());
    ui->label->setText(str);
}
void MapNotes::updateMapNotes(){

    re = route.getRoute(location);
    updateText();
    update();
}

void MapNotes::clear(){
    location.clear();
    updateMapNotes();
}

void MapNotes::updateText(){
    string str;
    for(unsigned long long i=0;i<location.size();i++){
        int a = location.at(i);
        str += to_string(a);
        str += "->";
    }
    ui->yet->setText(QString::fromStdString(str));
}

void MapNotes::paintEvent(QPaintEvent *){
    QPainter painter(this);
    // 设置画笔颜色
    static const QRgb colorTable[8] = {
        0x000000,0xFFA500, 0xCC6666, 0x66CC66, 0x00BFFF,
               0xBDB76B, 0xCC66CC,0x000000
    };
    //调色板
    QPen pen;
    pen.setWidth(5);
    QColor squreColor = colorTable[1];//绘制bubble
    pen.setColor(squreColor.light());
    painter.setPen(pen);
    painter.setBrush(squreColor);

    //按照坐标绘制路线
    QPoint* C;
    for(unsigned long long i=0;i<re.size();i++){
        C = new QPoint[re.at(i).getPointNumber()];
        for(unsigned long long j=0;j<re.at(i).getPointNumber();j++){
            C[j] = re.at(i).getPointList().at(j);
        }
        painter.drawPolyline(C,static_cast<int>(re.at(i).getPointNumber()));
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

vector<int> MapNotes::getLocation() const
{
    return location;
}

void MapNotes::setLocation(const vector<int> &value)
{
    location = value;
}


MapNotes::~MapNotes()
{
    delete ui;
}

void MapNotes::push(){
    QRadioButton* btn = qobject_cast<QRadioButton*>(sender());
    int num = btn->objectName().toInt();

    if(timer->isActive()){
        if(temp==num){
            emit twice(num);
            timer->stop();
            timer = new QTimer();
        }
    }
    else {
        timer->start(1);
        if(!(timer->isActive())){
            location.push_back(num);
            updateText();
        }
        temp = num;
    }

}

void MapNotes::timestop(){
    timer->stop();
    timer = nullptr;
}

void MapNotes::longTimePress(int i){
    qDebug()<<i<<endl;
}

void MapNotes::countTime(){

    QRadioButton* btn = qobject_cast<QRadioButton*>(sender());
    int num = btn->objectName().toInt();
    timer = new QTimer();
    timer->start(100);

    if(!(timer->isActive())&&!timer)
        emit timeout(num);
}

void MapNotes::doubleClicked(int i){
    qDebug()<<i<<"twice"<<endl;
}
