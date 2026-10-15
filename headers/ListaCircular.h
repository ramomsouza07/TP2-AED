#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

#include "Elemento.h"
#include <iostream>
using namespace std;

class ListaCircular {
    struct No {
        Elemento* info;
        No *ant, *prox;
    };
    No* prim;

public:
    ListaCircular() { prim = NULL; }
    void insere(Elemento* e);
    bool remove(int id);
    Elemento* busca(int id);
    void imprime();
};

#endif