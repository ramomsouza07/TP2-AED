#ifndef LISTADUPLA_H
#define LISTADUPLA_H

#include "Elemento.h"
#include <iostream>
using namespace std;

class ListaDupla {
    struct No {
        Elemento* info;
        No* ant;
        No* prox;
    };
    No* prim;
    No* ult;

public:
    ListaDupla() { prim = 0; ult = 0; }
    ~ListaDupla();

    void insereInicio(Elemento* e);
    void insereFim(Elemento* e);
    Elemento* removeInicio();
    Elemento* removeFim();
    bool remove(int id);
    Elemento* busca(int id);
    void imprime();
};

#endif