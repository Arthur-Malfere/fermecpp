#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <string>
#include <climits>

class InputHandler {
public:
   
    static std::string lireLigne(const std::string& prompt);
    
    static int lireEntier(const std::string& prompt, int min = INT_MIN, int max = INT_MAX);
    
    static std::string toLower(std::string str);
    
    static std::string nettoyer(std::string str);

    static std::string formaterType(std::string type);
};

#endif // INPUT_HANDLER_H
