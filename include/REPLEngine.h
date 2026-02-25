#ifndef REPL_ENGINE_H
#define REPL_ENGINE_H

#include "Ferme.h"
#include "CommandProcessor.h"

class REPLEngine {
private:
    Ferme ferme;
    CommandProcessor commandProcessor;
    bool actif;
    
    void afficherBienvenue() const;
    
    void afficherFermeture() const;

public:
    REPLEngine();
    
    void run();
    
    void stop();
    
    void traiterCommande(const std::string& entree);
};

#endif // REPL_ENGINE_H
