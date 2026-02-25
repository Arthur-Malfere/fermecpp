#include "Enclos.h"
#include <iostream>

bool Enclos::validerAjout(const Animal& animal) const {
    return estVide() || animal.estDuMemeType(animaux.front());
}

const std::string& Enclos::getTypeAnimal() const {
    return typeAnimal;
}

bool Enclos::ajouterAnimal(const Animal& animal) {
    if (!validerAjout(animal)) {
        return false;
    }
    
    if (estVide()) {
        typeAnimal = animal.getType();
    }
    
    animaux.push_back(animal);
    return true;
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

void Enclos::afficher() const {
    std::cout << "  Nombre d'animaux: " << getNombreAnimaux() << std::endl;
    for (const auto& animal : animaux) {
        animal.afficher();
    }
}
