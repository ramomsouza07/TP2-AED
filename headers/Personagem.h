#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "Elemento.h"
#include <string>

// [POO - Heranca]: Personagem herda da classe abstrata Elemento
class Personagem : public Elemento {
private:
    // [POO - Encapsulamento]: atributos privados
    std::string nome;
    int nivel;

public:
    Personagem(long id, std::string n, int nv);
    
    // [POO - Polimorfismo]: sobrescreve o metodo virtual puro da classe mae
    void imprimirInfo() const override;
    
    std::string getNome() const;
    int getNivel() const;
};

#endif
