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
#include <QVBoxLayout>
#include <QDebug>
#include <string>

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
    void countTime();
    void longTimePress(int);
    void timestop();
    void doubleClicked(int);

signals:
    void timeout(int);
    void twice(int);

private:
    Ui::MapNotes *ui;
    Route route;
    vector<int> location;
    vector<Road> re;
    QRadioButton* Build[28];
    QGridLayout* controlBoard;
    QTimer* timer;
    int temp;
};

#endif // MAPNOTES_H
