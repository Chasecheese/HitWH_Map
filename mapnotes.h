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

    void on_Build0_clicked();

    void on_Build1_clicked();

    void on_Build2_clicked();

    void on_Build3_clicked();

    void on_Build4_clicked();

    void on_Build5_clicked();

    void on_Build6_clicked();

    void on_Build7_clicked();

    void on_Build8_clicked();
    void on_Build9_clicked();

    void on_Build10_clicked();

    void on_Build11_clicked();

    void on_Build12_clicked();

    void on_Build13_clicked();

    void on_Build14_clicked();
    void on_Build15_clicked();

    void on_Build16_clicked();

    void on_Build17_clicked();

    void on_Build18_clicked();

    void on_Build19_clicked();

    void on_Build20_clicked();
    void on_Build21_clicked();

    void on_Build22_clicked();

    void on_Build23_clicked();

    void on_Build24_clicked();

    void on_Build25_clicked();

    void on_Build26_clicked();

    void on_Build27_clicked();

private:
    Ui::MapNotes *ui;
    Route route;
    vector<int> location;
    vector<Road> re;
};

#endif // MAPNOTES_H
