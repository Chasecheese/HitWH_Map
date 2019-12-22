#ifndef MAPNOTES_H
#define MAPNOTES_H

#include <QWidget>
#include <QFrame>
#include <QPaintEvent>
#include <QPainter>
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
    int location[10];
    ~MapNotes();

private slots:
    void on_BulidH_clicked();

    void on_BulidY_clicked();

    void on_BuildT_clicked();

private:
    Ui::MapNotes *ui;
};

#endif // MAPNOTES_H
