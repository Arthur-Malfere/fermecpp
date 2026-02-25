#include "InputHandler.h"
#include <algorithm>
#include <limits>
#include <iostream>
#include <cctype>

std::string InputHandler::lireLigne(const std::string& prompt) {
    std::cout << prompt;
    std::string ligne;
    std::getline(std::cin, ligne);
    return ligne;
}

int InputHandler::lireEntier(const std::string& prompt, int min, int max) {
    int valeur;
    while (true) {
        std::string entree = lireLigne(prompt);
        try {
            valeur = std::stoi(entree);
            if (valeur >= min && valeur <= max) {
                return valeur;
            }
            std::cout << "Erreur: La valeur doit être entre " << min << " et " << max << std::endl;
        } catch (const std::exception&) {
            std::cout << "Erreur: Veuillez entrer un nombre valide." << std::endl;
        }
    }
}

std::string InputHandler::toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

std::string InputHandler::nettoyer(std::string str) {
    str.erase(0, str.find_first_not_of(" \t\n\r"));
    str.erase(str.find_last_not_of(" \t\n\r") + 1);
    return str;
}

std::string InputHandler::formaterType(std::string type) {
    if (type.empty()) return type;
    type = toLower(type);
    type[0] = std::toupper(type[0]);
    return type;
}
