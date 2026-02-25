#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class Animal {
private:
    std::string nom;
    std::string type;
    int age;

public:

    Animal(const std::string& nom, const std::string& type, int age);
    
    const std::string& getNom() const;

    const std::string& getType() const;
    
    int getAge() const;
    
    void afficher() const;
    
    bool estDuMemeType(const Animal& autre) const;
};

#endif // ANIMAL_H
