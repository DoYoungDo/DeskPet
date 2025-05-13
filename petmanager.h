#ifndef PETMANAGER_H
#define PETMANAGER_H

#include <QObject>

#include "pet.h"

class PetManager : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(PetManager)
    explicit PetManager(QObject *parent = nullptr);
public:
    static PetManager* instance();

    void addPet(Pet* pet);
    template<class T>
    QList<T*> pets()
    {
        QList<T*> list;
        for(Pet* p : mPets)
        {
            if(p->inherits(typeid (T).name()))
            {
                list << qobject_cast<T*>(p);
            }
        }
        return list;
    }

    QList<Pet*> pets();
    int petCount() const;

private:
    QList<Pet*> mPets;
};

#endif // PETMANAGER_H
