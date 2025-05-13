#include "petmanager.h"




PetManager::PetManager(QObject *parent)
    : QObject{parent}
{

}

PetManager* PetManager::instance()
{
    static PetManager* manager = new PetManager;
    return manager;
}

void PetManager::addPet(Pet* pet)
{
    if(!mPets.contains(pet))
    {
        mPets << pet;
    }
}

QList<Pet*> PetManager::pets()
{
    return mPets;
}

int PetManager::petCount() const
{
    return mPets.size();
}

