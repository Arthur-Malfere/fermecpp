#include "REPL.h"
#include <iostream>
#include <algorithm>

namespace REPL {

std::string toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

std::string lireLigne(const std::string& prompt) {
    std::cout << prompt;
    std::string ligne;
    std::getline(std::cin, ligne);
    return ligne;
}

void dialogueAjouterAnimal(Ferme& ferme) {
    std::cout << "\n--- Ajouter un nouvel animal ---" << std::endl;
    
    std::string nom = lireLigne("Nom de l'animal: ");
    if (nom.empty()) {
        std::cout << "Erreur: Le nom ne peut pas être vide." << std::endl;
        return;
    }
    
    std::string type = lireLigne("Type d'animal (Vache, Cochon, Poule, Mouton, etc.): ");
    if (type.empty()) {
        std::cout << "Erreur: Le type ne peut pas être vide." << std::endl;
        return;
    }
    
    if (!type.empty()) {
        type[0] = std::toupper(type[0]);
        for (size_t i = 1; i < type.length(); i++) {
            type[i] = std::tolower(type[i]);
        }
    }
    
    std::string ageStr = lireLigne("Âge de l'animal (en années): ");
    int age;
    try {
        age = std::stoi(ageStr);
        if (age < 0) {
            std::cout << "Erreur: L'âge ne peut pas être négatif." << std::endl;
            return;
        }
    } catch (const std::exception&) {
        std::cout << "Erreur: Âge invalide. Veuillez entrer un nombre." << std::endl;
        return;
    }
    
    Animal nouvelAnimal = {nom, type, age};
    ferme.ajouterAnimal(nouvelAnimal);
    
    std::cout << "✓ " << nom << " a été ajouté à la ferme avec succès!" << std::endl;
}

void afficherAide() {
    std::cout << "\nAide :" << std::endl;
    std::cout << "  ajouter  - Ajouter un nouvel animal à la ferme" << std::endl;
    std::cout << "  afficher - Afficher le contenu de la ferme" << std::endl;
    std::cout << "  cls      - Effacer l'écran" << std::endl;
    std::cout << "  aide     - Afficher cette aide" << std::endl;
    std::cout << "  quitter  - Quitter le programme" << std::endl;
}

void effacerEcran() {
    // Utilise les séquences d'échappement ANSI pour effacer l'écran
    // \033[2J efface l'écran, \033[H replace le curseur en haut à gauche
    std::cout << "\033[2J\033[H" << std::flush;
}

void demarrer() {
    Ferme ferme;
    
    bool continuer = true;
    
    while (continuer) {
        std::string commande = lireLigne("ferme> ");
        
        commande.erase(0, commande.find_first_not_of(" \t"));
        commande.erase(commande.find_last_not_of(" \t") + 1);
        std::string commandeLower = toLower(commande);
        
        if (commandeLower.empty()) {
            continue;
        }
        
        if (commandeLower == "ajouter" || commandeLower == "add") {
            dialogueAjouterAnimal(ferme);
        }
        else if (commandeLower == "afficher" || commandeLower == "show" || commandeLower == "list") {
            ferme.afficher();
        }
        else if (commandeLower == "cls" || commandeLower == "clear") {
            effacerEcran();
        }
        else if (commandeLower == "aide" || commandeLower == "help" || commandeLower == "?") {
            afficherAide();
        }
        else if (commandeLower == "quitter" || commandeLower == "quit" || commandeLower == "exit") {
            std::cout << "Au revoir!" << std::endl;
            continuer = false;
        }
        else {
            std::cout << "Erreur: Commande inconnue: '" << commande << "'" << std::endl;
            std::cout << "Tapez 'aide' pour voir les commandes disponibles." << std::endl;
        }
    }
}

} // namespace REPL
