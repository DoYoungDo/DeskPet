#ifndef PET_H
#define PET_H

#include <QWidget>

class Pet : public QWidget
{
    Q_OBJECT
public:
    explicit Pet();
    virtual ~Pet() = default;

    virtual void setMouseTransparent(bool tran);
protected:
    int petState = 0;
};

#endif // PET_H
