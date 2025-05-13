#include "pet.h"


Pet::Pet()
    : QWidget{nullptr}
{
    setMouseTransparent(true);
    this->setWindowOpacity(0.7);
}

void Pet::setMouseTransparent(bool tran)
{
    this->setAttribute(Qt::WA_TransparentForMouseEvents, tran);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
}
