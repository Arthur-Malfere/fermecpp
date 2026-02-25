#ifndef COMMAND_H
#define COMMAND_H

#include "Ferme.h"
#include <string>

class Command {
public:
    virtual ~Command() = default;
    
    virtual void executer(Ferme& ferme) = 0;
    
    virtual std::string getNom() const = 0;
};

class CommandeAjouter : public Command {
public:
    void executer(Ferme& ferme) override;
    std::string getNom() const override;
};


class CommandeAfficher : public Command {
public:
    void executer(Ferme& ferme) override;
    std::string getNom() const override;
};


class CommandeClear : public Command {
public:
    void executer(Ferme& ferme) override;
    std::string getNom() const override;
};

class CommandeAide : public Command {
public:
    void executer(Ferme& ferme) override;
    std::string getNom() const override;
};

#endif // COMMAND_H
