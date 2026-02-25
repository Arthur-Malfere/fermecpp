#include "Enclos.h"
#include <iostream>
#include <iomanip>

Enclos::Enclos(double superficieTotale)
    : superficieTotale(superficieTotale) {}

bool Enclos::validerAjout(const Animal& animal) const {
    if (!estVide() && !animal.estDuMemeType(animaux.front())) {
        return false;
    }
    
    if (getEspaceDisponible() < animal.getEspaceRequis()) {
        return false;
    }
    
    return true;
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

double Enclos::getEspaceOccupe() const {
    double total = 0.0;
    for (const auto& animal : animaux) {
        total += animal.getEspaceRequis();
    }
    return total;
}

double Enclos::getEspaceDisponible() const {
    return superficieTotale - getEspaceOccupe();
}

double Enclos::getSuperficieTotale() const {
    return superficieTotale;
}

void Enclos::afficher() const {
    std::cout << "  Nombre d'animaux: " << getNombreAnimaux() << std::endl;
    std::cout << "  Espace occupé: " << std::fixed << std::setprecision(1) 
              << getEspaceOccupe() << " m² / " << superficieTotale << " m²" << std::endl;
    std::cout << "  Espace disponible: " << getEspaceDisponible() << " m²" << std::endl;
    
    for (const auto& animal : animaux) {
        animal.afficher();
    }
}
