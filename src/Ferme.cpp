#include "Ferme.h"
#include <iostream>
#include <iomanip>

int Ferme::trouverEnclosCompatible(const Animal& animal) const {
    for (size_t i = 0; i < enclos.size(); ++i) {
        if (enclos[i].getTypeAnimal() == animal.getType()) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

bool Ferme::ajouterAnimal(const Animal& animal) {
    int indexEnclos = trouverEnclosCompatible(animal);
    
    if (indexEnclos != -1) {
        return enclos[indexEnclos].ajouterAnimal(animal);
    }
    
    Enclos nouvelEnclos;
    if (nouvelEnclos.ajouterAnimal(animal)) {
        enclos.push_back(nouvelEnclos);
        return true;
    }
    
    return false;
}

void Ferme::afficher() const {
    if (estVide()) {
        std::cout << "\nLa ferme est vide. Aucun animal pour le moment." << std::endl;
        return;
    }
    
    std::cout << "\n--- Contenu de la ferme ---" << std::endl;
    
    for (size_t i = 0; i < enclos.size(); ++i) {
        std::cout << "\nEnclos " << (i + 1) << " - Type: " << enclos[i].getTypeAnimal() << std::endl;
        enclos[i].afficher();
    }
    
    afficherStatistiques();
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

void Ferme::afficherStatistiques() const {
    std::cout << "\n--- Statistiques Globales de la Ferme ---" << std::endl;
    std::cout << "Nombre total d'enclos: " << getNombreEnclos() << std::endl;
    std::cout << "Nombre total d'animaux: " << getNombreTotalAnimaux() << std::endl;
    
    double espaceTotal = 0.0;
    double spaceUtilise = 0.0;
    for (const auto& e : enclos) {
        espaceTotal += e.getSuperficieTotale();
        spaceUtilise += e.getEspaceOccupe();
    }
    
    std::cout << "Espace utilisé: " << spaceUtilise << " m² / " << espaceTotal << " m²" << std::endl;
    
    double pourcentageUtilisation = (espaceTotal > 0) ? (spaceUtilise / espaceTotal) * 100 : 0;
    std::cout << "Taux d'utilisation: " << pourcentageUtilisation << "%" << std::endl;
}
