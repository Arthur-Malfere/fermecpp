#include "Command.h"
#include "InputHandler.h"
#include <iostream>

void CommandeAjouter::executer(Ferme& ferme) {
    std::cout << "\n--- Ajouter un nouvel animal ---" << std::endl;
    std::string nom = InputHandler::lireLigne("Nom de l'animal: ");
    nom = InputHandler::nettoyer(nom);
    if (nom.empty()) {
        std::cout << "Erreur: Le nom ne peut pas être vide." << std::endl;
        return;
    }
    std::string type = InputHandler::lireLigne("Type d'animal (Vache, Cochon, Poule, Mouton, etc.): ");
    type = InputHandler::nettoyer(type);
    if (type.empty()) {
        std::cout << "Erreur: Le type ne peut pas être vide." << std::endl;
        return;
    }
    type = InputHandler::formaterType(type);
    int age = InputHandler::lireEntier("Âge de l'animal (en années): ", 0, 200);
    Animal nouvelAnimal(nom, type, age);
    if (ferme.ajouterAnimal(nouvelAnimal)) {
        std::cout << "✓ " << nom << " a été ajouté à la ferme avec succès!" << std::endl;
    } else {
        std::cout << "Erreur lors de l'ajout de l'animal." << std::endl;
    }
}

std::string CommandeAjouter::getNom() const {
    return "ajouter";
}

void CommandeAfficher::executer(Ferme& ferme) {
    ferme.afficher();
}

std::string CommandeAfficher::getNom() const {
    return "afficher";
}

void CommandeClear::executer(Ferme& /* ferme */) {
    std::cout << "\033[2J\033[H" << std::flush;
}

std::string CommandeClear::getNom() const {
    return "cls";
}

void CommandeAide::executer(Ferme& /* ferme */) {
    std::cout << "\nAide : " << std::endl;
    std::cout << "  ajouter  - Ajouter un nouvel animal à la ferme" << std::endl;
    std::cout << "  afficher - Afficher le contenu de la ferme" << std::endl;
    std::cout << "  cls      - Effacer l'écran" << std::endl;
    std::cout << "  aide     - Afficher cette aide" << std::endl;
    std::cout << "  quitter  - Quitter le programme" << std::endl;
}

std::string CommandeAide::getNom() const {
    return "aide";
}
