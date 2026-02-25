#ifndef ENCLOS_H
#define ENCLOS_H

#include "Animal.h"
#include <vector>
#include <string>

class Enclos {
private:
    std::string typeAnimal;
    std::vector<Animal> animaux;
    bool validerAjout(const Animal& animal) const;

public:
 
    const std::string& getTypeAnimal() const;
    
    bool ajouterAnimal(const Animal& animal);
    
    const std::vector<Animal>& getAnimaux() const;
    
    size_t getNombreAnimaux() const;
    
    bool estVide() const;
    
    void afficher() const;
};

#endif // ENCLOS_H
