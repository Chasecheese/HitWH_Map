#include "mapnotes.h"
#include "ui_mapnotes.h"

MapNotes::MapNotes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapNotes)
{
    ui->setupUi(this);
    location[0] = 0;
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

    QColor squreColor = colorTable[4];//绘制bubble
    pen.setColor(squreColor.dark());

    painter.setPen(pen);
    painter.setBrush(squreColor);

    painter.drawRect(100,  100, 100, 30);
}

MapNotes::~MapNotes()
{
    delete ui;
}

void MapNotes::on_BulidH_clicked()
{
    location[0]++;
    location[location[0]] = 1;
}

void MapNotes::on_BulidY_clicked()
{
    location[0]++;
    location[location[0]] = 2;
}

void MapNotes::on_BuildT_clicked()
{
    location[0]++;
    location[location[0]] = 3;
}
