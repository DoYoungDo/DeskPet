#include "petfactory.h"

#include "matchstickmen.h"
#include "petmanager.h"


PetFactory::PetFactory(QObject *parent)
    : QObject{parent}
{

}

PetFactory* PetFactory::instance()
{
    static PetFactory* factory = new PetFactory;
    return factory;
}

Pet* PetFactory::createPet()
{
    PetManager* pm = PetManager::instance();

    MatchstickMen* mm = new MatchstickMen;
    pm->addPet(mm);
    return mm;
}
