#ifndef REPL_H
#define REPL_H

#include "Ferme.h"
#include <string>

namespace REPL {

    void demarrer();
    
    void dialogueAjouterAnimal(Ferme& ferme);
    
    void afficherAide();
    
    void effacerEcran();
    
    std::string lireLigne(const std::string& prompt);
    
    std::string toLower(std::string str);
}

#endif // REPL_H
