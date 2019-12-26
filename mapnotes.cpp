#include "mapnotes.h"
#include "ui_mapnotes.h"

MapNotes::MapNotes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapNotes)
{
    ui->setupUi(this);
    ui->radioButton0->setStyleSheet("QRadioButton::indicator {width:15px;height:15px;border-radius:7px}"
                                    "QRadioButton::indicator:checked {background-color:green;}"
                                    "QRadioButton::indicator:unchecked {background-color:red;}"
                                    );
    ui->radioButton27->setStyleSheet("QRadioButton::indicator {width:15px;height:15px;border-radius:7px}"
                                    "QRadioButton::indicator:checked {background-color:green;}"
                                    "QRadioButton::indicator:unchecked {background-color:red;}"
                                    );
    ui->radioButton->setStyleSheet("QRadioButton::indicator {width:15px;height:15px;border-radius:7px}"
                                    "QRadioButton::indicator:checked {background-color:green;}"
                                    "QRadioButton::indicator:unchecked {background-color:red;}"
                                    );
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
    ui->radioButton0->setChecked(false);
    ui->radioButton27->setChecked(false);
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

void MapNotes::on_Build0_clicked()
{
    location.push_back(0);
    updateText();
}

void MapNotes::on_Build1_clicked()
{
    location.push_back(1);
    updateText();
}

void MapNotes::on_Build2_clicked()
{
    location.push_back(2);
    updateText();
}
void MapNotes::on_Build3_clicked()
{
    location.push_back(3);
    updateText();
}

void MapNotes::on_Build4_clicked()
{
    location.push_back(4);
    updateText();
}

void MapNotes::on_Build5_clicked()
{
    location.push_back(5);
    updateText();
}
void MapNotes::on_Build6_clicked()
{
    location.push_back(6);
    updateText();
}

void MapNotes::on_Build7_clicked()
{
    location.push_back(7);
    updateText();
}

void MapNotes::on_Build8_clicked()
{
    location.push_back(8);
    updateText();
}
void MapNotes::on_Build9_clicked()
{
    location.push_back(9);
    updateText();
}

void MapNotes::on_Build10_clicked()
{
    location.push_back(10);
    updateText();
}

void MapNotes::on_Build11_clicked()
{
    location.push_back(11);
    updateText();
}
void MapNotes::on_Build12_clicked()
{
    location.push_back(12);
    updateText();
}

void MapNotes::on_Build13_clicked()
{
    location.push_back(13);
    updateText();
}

void MapNotes::on_Build14_clicked()
{
    location.push_back(14);
    updateText();
}
void MapNotes::on_Build15_clicked()
{
    location.push_back(15);
    updateText();
}

void MapNotes::on_Build16_clicked()
{
    location.push_back(16);
    updateText();
}

void MapNotes::on_Build17_clicked()
{
    location.push_back(17);
    updateText();
}
void MapNotes::on_Build18_clicked()
{
    location.push_back(18);
    updateText();
}

void MapNotes::on_Build19_clicked()
{
    location.push_back(19);
    updateText();
}

void MapNotes::on_Build20_clicked()
{
    location.push_back(20);
    updateText();
}
void MapNotes::on_Build21_clicked()
{
    location.push_back(21);
    updateText();
}

void MapNotes::on_Build22_clicked()
{
    location.push_back(22);
    updateText();
}

void MapNotes::on_Build23_clicked()
{
    location.push_back(23);
    updateText();
}
void MapNotes::on_Build24_clicked()
{
    location.push_back(24);
    updateText();
}

void MapNotes::on_Build25_clicked()
{
    location.push_back(25);
    updateText();
}

void MapNotes::on_Build26_clicked()
{
    location.push_back(26);
    updateText();
}
void MapNotes::on_Build27_clicked()
{
    location.push_back(27);
    updateText();
}


void MapNotes::on_radioButton0_clicked()
{
    location.push_back(0);
    updateText();
}

void MapNotes::on_radioButton27_clicked()
{
    location.push_back(27);
    updateText();
}

void MapNotes::on_radioButton_clicked()
{
    location.push_back(23);
    updateText();
}

