#ifndef MATCHSTICKMEN_H
#define MATCHSTICKMEN_H

#include "pet.h"

class MatchstickMen : public Pet
{
    Q_OBJECT
public:
    MatchstickMen();

protected:
    virtual void paintEvent(QPaintEvent* event) override;

private:
    enum State{
        Egg
    };
};

#endif // MATCHSTICKMEN_H
