#include "matchstickmen.h"

#include "mousemoveassistant.h"

#include <QPainter>
#include <QPainterPath>
#include <QTimer>


MatchstickMen::MatchstickMen()
    :Pet()
{
    petState = ((int)Egg);
    this->resize(150,130);
    MouseMoveAssistant::instance()->installWidget(this);
}

void MatchstickMen::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setOpacity(this->windowOpacity());
    painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿

    QRect validRect = this->rect().marginsRemoved(QMargins(1,1,1,1));

    // painter.setBrush(Qt::gray);
    // painter.drawRect(validRect);

    switch (petState) {
    case Egg:
    {
        painter.save();

        // QPen myPen;
        painter.setBrush(QColor("#eee5c7"));
        painter.setPen(QPen(Qt::gray, 2));


        QPoint start(validRect.center().x(), validRect.top());
        QPoint end(validRect.center().x(), validRect.bottom());
        QPoint second(start.x() - (start.x() - validRect.x()) / 2, start.y());
        QPoint third(validRect.x(), end.y() - 5);
        QPoint second1(start.x() + (start.x() - validRect.x()) / 2, start.y());
        QPoint third1(validRect.right(), end.y() - 5);

        QPainterPath eggPath;
        eggPath.moveTo(start);
        eggPath.cubicTo(second, third, end);
        eggPath.moveTo(start);
        eggPath.cubicTo(second1, third1, end);

        painter.drawPath(eggPath);

        QRadialGradient gradient;
        gradient.setFocalPoint(start);
        gradient.setFocalRadius(eggPath.boundingRect().width());
        gradient.setCenter(end);
        gradient.setRadius(eggPath.boundingRect().width());
        QGradientStop stop;
        stop.first = 0;
        stop.second = Qt::white;
        QGradientStop stop1;
        stop1.first = 1;
        stop1.second = Qt::black;
        gradient.setStops(QGradientStops() << stop << stop1);

        painter.setBrush(gradient);
        painter.drawPath(eggPath);

        painter.restore();
    }
    default:
        break;
    }
}
