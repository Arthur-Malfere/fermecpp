#ifndef ENCLOS_H
#define ENCLOS_H

#include "Animal.h"
#include <vector>
#include <string>

class Enclos {
private:
    std::string typeAnimal;
    std::vector<Animal> animaux;
    double superficieTotale;  // En m²
    bool validerAjout(const Animal& animal) const;

public:
 
    Enclos(double superficieTotale = 100.0);
    
    const std::string& getTypeAnimal() const;
    
    bool ajouterAnimal(const Animal& animal);
    
    const std::vector<Animal>& getAnimaux() const;
    
    size_t getNombreAnimaux() const;
    
    bool estVide() const;
    
    double getEspaceOccupe() const;
    
    double getEspaceDisponible() const;
    
    double getSuperficieTotale() const;
    
    void afficher() const;
};

#endif // ENCLOS_H
