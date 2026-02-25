#include "Ferme.h"
#include <iostream>

void Ferme::ajouterAnimal(const Animal& animal) {
    for (auto& e : enclos) {
        if (e.getTypeAnimal() == animal.type) {
            e.ajouterAnimal(animal);
            return;
        }
    }
    
    Enclos nouvelEnclos;
    nouvelEnclos.ajouterAnimal(animal);
    enclos.push_back(nouvelEnclos);
}

void Ferme::afficher() const {
    if (enclos.empty()) {
        std::cout << "La ferme est vide. Aucun animal pour le moment." << std::endl;
        return;
    }
    
    std::cout << "\nContenu : " << std::endl;
    
    int totalAnimaux = 0;
    for (size_t i = 0; i < enclos.size(); i++) {
        std::cout << "\nEnclos " << i+1 << " - Type: " << enclos[i].getTypeAnimal() << std::endl;
        std::cout << "  Nombre d'animaux: " << enclos[i].getNombreAnimaux() << std::endl;
        
        for (const auto& animal : enclos[i].getAnimaux()) {
            std::cout << "    • " << animal.nom << " - " << animal.age << " ans" << std::endl;
            totalAnimaux++;
        }
    }
    
    std::cout << "\nTotal: " << totalAnimaux << " animaux dans " << enclos.size() << " enclos" << std::endl;
}

size_t Ferme::getNombreEnclos() const {
    return enclos.size();
}

size_t Ferme::getNombreTotalAnimaux() const {
    size_t total = 0;
    for (const auto& e : enclos) {
        total += e.getNombreAnimaux();
    }
    return total;
}

bool Ferme::estVide() const {
    return enclos.empty();
}
