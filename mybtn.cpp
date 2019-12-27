#include "mybtn.h"

#include <QEvent>
#include <QTimer>

Mybtn::Mybtn(QWidget *parent)
    :QRadioButton (parent),
      doubleClicked(false),
      oncetimer(new QTimer(this))
{
    oncetimer->setSingleShot(true);
    connect(oncetimer,SIGNAL(timeout()),this,SIGNAL(clickedOnce()));
}

Mybtn::Mybtn(const QString &text, QWidget *parent)
    :Mybtn(parent)
{
    setText(text);
}

Mybtn::Mybtn(const QIcon &icon, const QString &Text, QWidget *parent)
    :Mybtn(Text,parent)
{
    setIcon(icon);
}

Mybtn::~Mybtn()
{

}

bool Mybtn::event(QEvent *event){
    switch (event->type()) {
        case QEvent::MouseButtonRelease:
            if(doubleClicked==true){
                doubleClicked = false;
            }else {
                oncetimer->start(125);
            }
            break;

        case QEvent::MouseButtonDblClick:
            this->setChecked(false);
            oncetimer->stop();
            doubleClicked = true;
            emit clickedTwice();
            break;

        default:
            break;
    }
    return QRadioButton::event(event);
}
