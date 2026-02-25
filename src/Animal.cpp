#include "Animal.h"

Animal::Animal(const std::string& nom, const std::string& type, int age)
    : nom(nom), type(type), age(age) {}

const std::string& Animal::getNom() const {
    return nom;
}

const std::string& Animal::getType() const {
    return type;
}

int Animal::getAge() const {
    return age;
}

void Animal::afficher() const {
    std::cout << "  • " << nom << " (" << type << ") - " << age << " ans" << std::endl;
}

bool Animal::estDuMemeType(const Animal& autre) const {
    return type == autre.type;
}
