#ifndef PILHA_H
#define PILHA_H

#include "Elemento.h"
#include "ListaNaoOrdenada.h"

class Pilha {
private:
    ListaNaoOrdenada lista;

public:
    Pilha(int capacidade = 50);
 
    bool empilhar(Elemento* e);
    bool desempilhar();
    Elemento* consultarTopo() const;
    bool pilhaCheia() const;
    bool pilhaVazia() const;
};

#endif