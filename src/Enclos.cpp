#include "Enclos.h"

bool Enclos::peutAjouter(const Animal& animal) const {
    return animaux.empty() || animal.type == typeAnimal;
}

void Enclos::ajouterAnimal(const Animal& animal) {
    if (animaux.empty()) {
        typeAnimal = animal.type;
    }
    animaux.push_back(animal);
}

const std::string& Enclos::getTypeAnimal() const {
    return typeAnimal;
}

const std::vector<Animal>& Enclos::getAnimaux() const {
    return animaux;
}

size_t Enclos::getNombreAnimaux() const {
    return animaux.size();
}

bool Enclos::estVide() const {
    return animaux.empty();
}
