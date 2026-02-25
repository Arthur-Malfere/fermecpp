#include "REPLEngine.h"
#include "InputHandler.h"
#include <iostream>

REPLEngine::REPLEngine() : actif(false) {}

void REPLEngine::afficherBienvenue() const {
    std::cout << "\nTapez 'aide' pour voir les commandes disponibles.\n" << std::endl;
}

void REPLEngine::afficherFermeture() const {
    std::cout << "Au revoir!" << std::endl;
}

void REPLEngine::run() {
    afficherBienvenue();
    actif = true;
    
    while (actif) {
        std::string entree = InputHandler::lireLigne("ferme> ");
        traiterCommande(entree);
    }
    
    afficherFermeture();
}

void REPLEngine::stop() {
    actif = false;
}

void REPLEngine::traiterCommande(const std::string& entree) {
    std::string commandeStr = InputHandler::nettoyer(entree);
    
    if (commandeStr.empty()) {
        return;
    }
    
    std::string commandeLower = InputHandler::toLower(commandeStr);
    if (commandeLower == "quitter" || commandeLower == "quit" || commandeLower == "exit") {
        stop();
        return;
    }
    
    if (!commandProcessor.executerCommande(commandeStr, ferme)) {
        std::cout << "Commande inconnue: '" << commandeStr << "'" << std::endl;
        std::cout << "Tapez 'aide' pour voir les commandes disponibles." << std::endl;
    }
}
