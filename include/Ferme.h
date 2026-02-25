#ifndef FERME_H
#define FERME_H

#include "Enclos.h"
#include <vector>

class Ferme {
private:
    std::vector<Enclos> enclos;

public:

    void ajouterAnimal(const Animal& animal);
    
    void afficher() const;
    
    size_t getNombreEnclos() const;
    
    size_t getNombreTotalAnimaux() const;
    
    bool estVide() const;
};

#endif // FERME_H
