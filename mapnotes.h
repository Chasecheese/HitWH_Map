#ifndef MAPNOTES_H
#define MAPNOTES_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <route.h>
#include <vector>
#include <QMouseEvent>
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
    vector<int> getLocation() const;
    void setLocation(const vector<int> &value);

    vector<Road> getRe() const;
    void setRe(const vector<Road> &value);

private slots:

    void on_Bulid0_clicked();

    void on_Build1_clicked();

    void on_Bulid2_clicked();

private:
    Ui::MapNotes *ui;
    Route route;
    vector<int> location;
    vector<Road> re;
};

#endif // MAPNOTES_H
