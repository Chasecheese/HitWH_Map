#ifndef MYBTN_H
#define MYBTN_H

#include <QRadioButton>
#include <QPushButton>
#include <QTimer>
#include <QEvent>
class QTimer;

class Mybtn : public QRadioButton
{

    Q_OBJECT

public:
    Mybtn(QWidget *parent=Q_NULLPTR);
    Mybtn(const QString &text, QWidget *parent = Q_NULLPTR);
    Mybtn(const QIcon &icon, const QString &text, QWidget *parent = Q_NULLPTR);
    ~Mybtn();

protected:
    virtual bool event(QEvent* event);
signals:
    void clickedOnce();
    void clickedTwice();

private:
    bool doubleClicked;
    QTimer* oncetimer;
};

#endif // MYBTN_H
