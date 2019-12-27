#include "mapnotes.h"
#include "ui_mapnotes.h"



MapNotes::MapNotes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapNotes)
{
    ui->setupUi(this);  
    QPalette   pal;
    pal.setColor(QPalette::ButtonText, QColor(255,0,0));
    ui->HidenButton->setVisible(false);
    ifstream in;
    in.open("D:\\points.txt");
    int x,y;

    for(int i=0;i<33;i++){
        Build[i] = new Mybtn(this);
        in>>x;
        in>>y;
        Build[i]->move(x,y);
        Build[i]->setText(QString::number(i));
        Build[i]->setObjectName(QString::number(i));
        connect(Build[i],SIGNAL(clickedOnce()),this,SLOT(push()));
        connect(Build[i],SIGNAL(clickedTwice()),this,SLOT(doubleClicked()));
        Build[i]->setStyleSheet("QRadioButton::indicator {width:15px;height:15px;border-radius:7px}"
                                            "QRadioButton::indicator:checked {background-color:red;}"
                                            "QRadioButton::indicator:unchecked {background-color:white;}"
                                            );
    }

    connect(this->ui->HidenButton,SIGNAL(clicked()),this,SLOT(setTest()));
    connect(this,SIGNAL(setHide()),this,SLOT(chooseHiden()));
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
    Mybtn* btn = qobject_cast<Mybtn*>(sender());
    int num = btn->objectName().toInt();
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
    updateText();
    emit setHide();
}

void MapNotes::doubleClicked(){
    Mybtn* btn = qobject_cast<Mybtn*>(sender());
    int num = btn->objectName().toInt();
    qDebug()<<num;
    Build[num]->setCheckable(false);
    emit setHide();
}

void MapNotes::set(vector<int> temp){

    for(unsigned long long i=0;i<temp.size();i++){
        Build[temp.at(i)]->setChecked(true);
    }
}

void MapNotes::setTest(){

}

void MapNotes::chooseHiden(){
    this->ui->HidenButton->setChecked(true);
}

