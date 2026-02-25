#include "Animal.h"
#include <map>

double Animal::getEspaceRequisParType(const std::string& type) {
    static const std::map<std::string, double> espaceParType = {
        {"Vache", 15.0},      // Les vaches occupent beaucoup de place
        {"Cochon", 8.0},      // Moins que les vaches
        {"Mouton", 5.0},      // Moins que les cochons
        {"Cheval", 20.0},     // Plus que les vaches
        {"Poule", 1.5},       // Très peu de place
        {"Canard", 2.0},      // Légèrement plus que les poules
        {"Chèvre", 4.0}       // Entre mouton et cochon
    };
    
    auto it = espaceParType.find(type);
    if (it != espaceParType.end()) {
        return it->second;
    }
    
    // Espace par défaut pour un type inconnu
    return 5.0;
}

Animal::Animal(const std::string& nom, const std::string& type, int age)
    : nom(nom), type(type), age(age), espaceRequis(getEspaceRequisParType(type)) {}

const std::string& Animal::getNom() const {
    return nom;
}

const std::string& Animal::getType() const {
    return type;
}

int Animal::getAge() const {
    return age;
}

double Animal::getEspaceRequis() const {
    return espaceRequis;
}

void Animal::afficher() const {
    std::cout << "  • " << nom << " (" << type << ") - " << age << " ans - " 
              << espaceRequis << " m²" << std::endl;
}

bool Animal::estDuMemeType(const Animal& autre) const {
    return type == autre.type;
}
