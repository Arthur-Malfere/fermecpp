#ifndef FERME_H
#define FERME_H

#include "Enclos.h"
#include <vector>

class Ferme {
private:
    std::vector<Enclos> enclos;
    int trouverEnclosCompatible(const Animal& animal) const;

public:

    bool ajouterAnimal(const Animal& animal);
    
    void afficher() const;
    
    size_t getNombreEnclos() const;
    
    size_t getNombreTotalAnimaux() const;
    
    bool estVide() const;
    
    void afficherStatistiques() const;
};

#endif // FERME_H
