#ifndef ENCLOS_H
#define ENCLOS_H

#include "Animal.h"
#include <vector>
#include <string>

class Enclos {
private:
    std::string typeAnimal;
    std::vector<Animal> animaux;

public:

    bool peutAjouter(const Animal& animal) const;
    
    void ajouterAnimal(const Animal& animal);
    
    const std::string& getTypeAnimal() const;
    
    const std::vector<Animal>& getAnimaux() const;

    size_t getNombreAnimaux() const;
    
    bool estVide() const;
};

#endif // ENCLOS_H
