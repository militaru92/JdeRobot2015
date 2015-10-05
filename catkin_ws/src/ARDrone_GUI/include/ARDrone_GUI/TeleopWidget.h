#ifndef TELEOPWIDGET_H
#define TELEOPWIDGET_H

#include <iostream>
#include <QWidget>
#include <QtUiTools/QUiLoader>
#include <QFile>
#include <QGridLayout>
#include <QPalette>
#include <QtCore>
#include <QPainter>
#include <QMouseEvent>

class TeleopWidget : public QWidget
{
    Q_OBJECT
public:

    TeleopWidget(QWidget *parent = 0);
    virtual ~TeleopWidget();


signals:
    void stopSignal();
    void setXY(double,double);


public slots:

    void stop();


private:

    void paintEvent(QPaintEvent * event);
    void mouseMoveEvent(QMouseEvent * event);



    QImage qimage;
    QPointF line;

    QWidget *winParent;

};

#endif // TELEOPWIDGET_H
