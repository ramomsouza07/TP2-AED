#ifndef EQUIPAMENTO_H
#define EQUIPAMENTO_H

#include "Elemento.h"
#include <string>

class Equipamento : public Elemento {
private:
    std::string nomeItem;
    int danoBase;

public:
    Equipamento(long id, std::string n, int dano);
    
    void imprimirInfo() const override;
    
    std::string getNomeItem() const;
    int getDanoBase() const;
};

#endif