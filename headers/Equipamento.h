#ifndef EQUIPAMENTO_H
#define EQUIPAMENTO_H

#include "Elemento.h"
#include <string>

// [POO - Heranca]: Equipamento herda da classe abstrata Elemento
class Equipamento : public Elemento {
private:
    // [POO - Encapsulamento]: atributos privados
    std::string nomeItem;
    int danoBase; // atributo especifico de equipamento

public:
    Equipamento(long id, std::string n, int dano);
    
    // [POO - Polimorfismo]: sobrescreve o metodo virtual puro da classe mae
    void imprimirInfo() const override;
    
    std::string getNomeItem() const;
    int getDanoBase() const;
};

#endif
