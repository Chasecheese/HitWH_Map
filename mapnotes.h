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
    void updateText();
    void clear();
    vector<int> getLocation() const;
    void setLocation(const vector<int> &value);

    vector<Road> getRe() const;
    void setRe(const vector<Road> &value);

private slots:
    void push();
    void doubleClicked();
    void set(vector<int>);
    void setTest();
    void chooseHiden();

signals:
    void setHide();
private:
    Ui::MapNotes *ui;
    Route route;
    vector<int> location;
    vector<Road> re;
    Mybtn* Build[33];
    QGridLayout* controlBoard;
    QTimer* timer;
    int temp;
};

#endif // MAPNOTES_H
