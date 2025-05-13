#ifndef MOUSEMOVEASSISTANT_H
#define MOUSEMOVEASSISTANT_H

#include <QObject>

class MouseMoveAssistant : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(MouseMoveAssistant)
    explicit MouseMoveAssistant(QObject *parent = nullptr);
public:
    static MouseMoveAssistant* instance();

    void installWidget(QWidget* w);
    // QObject interface
public:
    virtual bool eventFilter(QObject* watched, QEvent* event) override;
};

#endif // MOUSEMOVEASSISTANT_H
