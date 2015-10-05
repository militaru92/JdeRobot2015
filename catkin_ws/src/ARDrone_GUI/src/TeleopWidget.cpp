#include <ARDrone_GUI/TeleopWidget.h>


TeleopWidget::TeleopWidget(QWidget *parent)
{
    line = QPointF(0, 0);
    qimage.load("ball.png");


    this->setAutoFillBackground(true);
    QPalette p = this->palette();
    p.setColor(this->backgroundRole(), QColor(0,0,0));
    this->setPalette(p);
    this->resize(300,300);
    this->setMinimumSize(300,300);

    this->winParent = parent;



}

TeleopWidget::~TeleopWidget()
{

}

void TeleopWidget::mouseMoveEvent(QMouseEvent * event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        double x = event->x() - this->width()/2;
        double y = event->y() - this->height()/2;
        this->line =QPointF(x, y);
        this->repaint();
    }

}

void TeleopWidget::stop()
{
    this->line = QPointF(0, 0);
    this->repaint();
}


void TeleopWidget::paintEvent(QPaintEvent * event)
{
    int height = this->height();
    int width = this->width();

    QPainter painter(this);
    QPen pen(Qt::blue,2);

    painter.setPen(pen);

    painter.translate(QPoint(width/2, height/2));

    painter.drawLine(QPointF(-width, 0), QPointF(width, 0));

    painter.drawLine(QPointF(0, -height), QPointF(0, height));

    pen = QPen(Qt::red, 2);

    painter.setPen(pen);

    if (abs(this->line.x()*2) >= this->size().width())
    {
        if (this->line.x()>=0)
        {
            this->line.setX(this->size().width()/2);
        }

        else if (this->line.x()<0)
        {
            this->line.setX((-this->size().width()/2)+1);
        }
    }

    if (abs(this->line.y()*2) >= this->size().height())
    {
        if (this->line.y()>=0)
        {
            this->line.setY(this->size().height()/2);
        }

        else if (this->line.y()<0)
        {
            this->line.setY((-this->size().height()/2)+1);
        }

    }

    painter.drawLine(QPointF(this->line.x(), -height), QPointF(this->line.x(), height));

    painter.drawLine(QPointF(-width, this->line.y()), QPointF( width, this->line.y()));

    double v_normalized,w_normalized;

    v_normalized = (1.0/(this->size().height()/2)) * this->line.y();

    w_normalized = (1.0/(this->size().width()/2)) * this->line.x();

    //this->winParent->setXYValues(w_normalized,v_normalized);
    emit setXY(w_normalized,v_normalized);

    painter.drawImage(this->line.x()-this->qimage.width()/2, this->line.y()-this->qimage.height()/2, this->qimage);

}
