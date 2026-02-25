#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

struct Animal {
    std::string nom;
    std::string type;
    int age;
};

struct Enclos {
    std::string typeAnimal;
    std::vector<Animal> animaux;
    
    bool peutAjouter(const Animal& animal) {
        return animaux.empty() || animal.type == typeAnimal;
    }
    
    void ajouterAnimal(const Animal& animal) {
        if (animaux.empty()) {
            typeAnimal = animal.type;
        }
        animaux.push_back(animal);
    }
};

struct Ferme {
    std::vector<Enclos> enclos;
    
    void ajouterAnimal(const Animal& animal) {
        for (auto& e : enclos) {
            if (e.typeAnimal == animal.type) {
                e.ajouterAnimal(animal);
                return;
            }
        }
        
        Enclos nouvelEnclos;
        nouvelEnclos.ajouterAnimal(animal);
        enclos.push_back(nouvelEnclos);
    }
    
    void afficher() {
        if (enclos.empty()) {
            std::cout << "La ferme est vide. Aucun animal pour le moment." << std::endl;
            return;
        }
        
        int totalAnimaux = 0;
        for (size_t i = 0; i < enclos.size(); i++) {
            std::cout << "\nEnclos " << i+1 << " - Type: " << enclos[i].typeAnimal << std::endl;
            std::cout << "  Nombre d'animaux: " << enclos[i].animaux.size() << std::endl;
            for (const auto& animal : enclos[i].animaux) {
                std::cout << "    • " << animal.nom << " - " << animal.age << " ans" << std::endl;
                totalAnimaux++;
            }
        }
        std::cout << "\nTotal: " << totalAnimaux << " animaux dans " << enclos.size() << " enclos" << std::endl;
    }
};

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
    std::cout << "\nCommandes disponibles :" << std::endl;
    std::cout << "  ajouter  - Ajouter un nouvel animal à la ferme" << std::endl;
    std::cout << "  afficher - Afficher le contenu de la ferme" << std::endl;
    std::cout << "  aide     - Afficher cette aide" << std::endl;
    std::cout << "  quitter  - Quitter le programme" << std::endl;
}

void repl() {
    Ferme ferme;
    
    bool continuer = true;
    
    while (continuer) {
        std::string commande = lireLigne(">>> ");
        
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
        else if (commandeLower == "aide" || commandeLower == "help" || commandeLower == "?") {
            afficherAide();
        }
        else if (commandeLower == "quitter" || commandeLower == "quit" || commandeLower == "exit") {
            std::cout << "Au revoir!" << std::endl;
            continuer = false;
        }
        else {
            std::cout << "Commande inconnue: '" << commande << "'" << std::endl;
            std::cout << "Tapez 'aide' pour voir les commandes disponibles." << std::endl;
        }
    }
}

int main() {
    repl();
    return 0;
}
