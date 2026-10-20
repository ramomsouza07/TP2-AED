#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "Elemento.h"
#include <string>

// herda de elemento
class Personagem : public Elemento {
private:
    std::string nome;
    int nivel;

public:
    Personagem(long id, std::string n, int nv);
    
    void imprimirInfo() const override;
    
    std::string getNome() const;
    int getNivel() const;
};

#endif
