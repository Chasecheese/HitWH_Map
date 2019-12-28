#ifndef MAPNOTES_H
#define MAPNOTES_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <route.h>
#include <vector>
#include <QMouseEvent>
#include <QRadioButton>
#include <QPushButton>
#include <QTimer>
#include <QTime>
#include <QVBoxLayout>
#include <QDebug>
#include <string>
#include <mybtn.h>
#include <Windows.h>
#include <list.h>

using namespace std;

namespace Ui {
class MapNotes;
}

class MapNotes : public QWidget
{
    Q_OBJECT

public:
    explicit MapNotes(QWidget *parent = nullptr);
    void updateMapNotes();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    ~MapNotes();
    void updateText(string name);
    void clear();

    vector<Road> getRe() const;
    void setRe(const vector<Road> &value);
    void print();

private slots:
    void push();
    void doubleClicked();
    void chooseHiden();
    void updateNotes(List);

signals:
    void setHide();
    void updateName(string);
private:
    Ui::MapNotes *ui;
    Route route;
    vector<int> location;
    vector<Road> re;
    string name[33];
    Mybtn* Build[33];
    QGridLayout* controlBoard;
    string trans;
    List noteNum;
};

#endif // MAPNOTES_H
