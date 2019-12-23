#include "mapnotes.h"
#include "ui_mapnotes.h"

MapNotes::MapNotes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapNotes)
{
    ui->setupUi(this);
}

void MapNotes::updateMapNotes(){

    re = route.getRoute();
    update();
}

void MapNotes::paintEvent(QPaintEvent *){
    QPainter painter(this);
    // 设置画笔颜色
    static const QRgb colorTable[8] = {
        0x000000,0xFFA500, 0xCC6666, 0x66CC66, 0x00BFFF,
               0xBDB76B, 0xCC66CC,0x000000
    };//调色板
    QPen pen;
    pen.setWidth(3);
    QColor squreColor = colorTable[3];//绘制bubble
    pen.setColor(squreColor.light());
    painter.setPen(pen);
    painter.setBrush(squreColor);
    QPoint* C;

    for(unsigned long long i=0;i<re.size();i++){
        C = new QPoint[re.at(i).pointNumber];
        for(unsigned long long j=0;j<re.at(i).pointNumber;j++){
            C[j] = re.at(i).pointList.at(j);
        }
        painter.drawPolyline(C,static_cast<int>(re.at(i).pointNumber));
    }

}

MapNotes::~MapNotes()
{
    delete ui;
}

void MapNotes::on_BulidH_clicked()
{
    location.push_back(1);
}

void MapNotes::on_BulidY_clicked()
{
    location.push_back(2);
}

void MapNotes::on_BuildT_clicked()
{
    location.push_back(3);
}
