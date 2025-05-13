#ifndef PETFACTORY_H
#define PETFACTORY_H

#include <QObject>

class Pet;

class PetFactory : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(PetFactory)
    explicit PetFactory(QObject *parent = nullptr);
public:
    static PetFactory* instance();

    Pet* createPet();
};

#endif // PETFACTORY_H
