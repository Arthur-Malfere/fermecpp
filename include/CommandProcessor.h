#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H

#include "Command.h"
#include <map>
#include <memory>
#include <vector>

class CommandProcessor {
private:
    std::map<std::string, std::shared_ptr<Command>> commandes;
    std::map<std::string, std::string> aliases; // alias -> nom de commande

public:
    CommandProcessor();

    void enregistrerCommande(std::shared_ptr<Command> commande, 
                           const std::vector<std::string>& aliasesList);
    
  
    std::shared_ptr<Command> getCommande(const std::string& nomOuAlias) const;
    
    bool executerCommande(const std::string& nomOuAlias, Ferme& ferme);
    
    bool existeCommande(const std::string& nomOuAlias) const;
};

#endif // COMMAND_PROCESSOR_H
