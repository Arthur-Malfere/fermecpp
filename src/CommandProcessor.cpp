#include "CommandProcessor.h"
#include "InputHandler.h"

CommandProcessor::CommandProcessor() {
    auto commandeAjouter = std::make_shared<CommandeAjouter>();
    auto commandeAfficher = std::make_shared<CommandeAfficher>();
    auto commandeClear = std::make_shared<CommandeClear>();
    auto commandeAide = std::make_shared<CommandeAide>();
    
    enregistrerCommande(commandeAjouter, {"ajouter", "add"});
    enregistrerCommande(commandeAfficher, {"afficher", "show", "list"});
    enregistrerCommande(commandeClear, {"cls", "clear"});
    enregistrerCommande(commandeAide, {"aide", "help", "?"});
}

void CommandProcessor::enregistrerCommande(std::shared_ptr<Command> commande, 
                                          const std::vector<std::string>& aliasesList) {
    std::string nomPrincipal = commande->getNom();
    commandes[nomPrincipal] = commande;
    
    for (const auto& alias : aliasesList) {
        std::string aliasLower = InputHandler::toLower(alias);
        aliases[aliasLower] = nomPrincipal;
    }
}

std::shared_ptr<Command> CommandProcessor::getCommande(const std::string& nomOuAlias) const {
    std::string cle = InputHandler::toLower(nomOuAlias);
    
    auto it = commandes.find(cle);
    if (it != commandes.end()) {
        return it->second;
    }
    
    auto itAlias = aliases.find(cle);
    if (itAlias != aliases.end()) {
        auto itCmd = commandes.find(itAlias->second);
        if (itCmd != commandes.end()) {
            return itCmd->second;
        }
    }
    
    return nullptr;
}

bool CommandProcessor::executerCommande(const std::string& nomOuAlias, Ferme& ferme) {
    auto commande = getCommande(nomOuAlias);
    if (!commande) {
        return false;
    }
    
    commande->executer(ferme);
    return true;
}

bool CommandProcessor::existeCommande(const std::string& nomOuAlias) const {
    return getCommande(nomOuAlias) != nullptr;
}
