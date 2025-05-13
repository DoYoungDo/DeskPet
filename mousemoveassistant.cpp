#include "mousemoveassistant.h"

#include <QEvent>
#include <QMouseEvent>
#include <QWidget>


MouseMoveAssistant::MouseMoveAssistant(QObject *parent)
    : QObject{parent}
{

}

MouseMoveAssistant* MouseMoveAssistant::instance()
{
    static MouseMoveAssistant* ins = new MouseMoveAssistant;
    return ins;
}

void MouseMoveAssistant::installWidget(QWidget* w)
{
    if(w)
    {
        w->installEventFilter(this);
        // w->setMouseTracking();
    }
}

bool MouseMoveAssistant::eventFilter(QObject* watched, QEvent* event)
{
    if(watched->inherits("QWidget"))
    {
        QWidget * w = qobject_cast<QWidget*>(watched);
        if(event->type() == QEvent::MouseButtonPress)
        {
            w->setProperty("isPressed",true);
            w->setProperty("startPos",static_cast<QMouseEvent*>(event)->pos());
        }
        else if(event->type() == QEvent::MouseButtonRelease)
        {
            w->setProperty("isPressed",false);
        }
        else if(event->type() == QEvent::MouseMove)
        {
            if(w->property("isPressed").toBool())
            {
                QPoint startPos = w->property("startPos").toPoint();
                QPoint cursorPos = static_cast<QMouseEvent*>(event)->pos();
                QRect rect = w->geometry();
                // qDebug() << cursorPos << w->rect() << w->geometry();
                w->move(rect.x() + (cursorPos.x() - startPos.x()), rect.y() + (cursorPos.y() - startPos.y()));
            }
        }
    }

    return QObject::eventFilter(watched, event);
}
