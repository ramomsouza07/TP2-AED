#ifndef LISTASIMPLES_H
#define LISTASIMPLES_H

#include "Elemento.h"
#include <iostream>
using namespace std;

class ListaSimples {
private:
    struct No {
        Elemento* info;
        No* prox;
    };
    No* prim;
    No* ult;

public:
    ListaSimples() { prim = NULL; ult = NULL; }
    ~ListaSimples();
    
    void insereInicio(Elemento* e);
    void insereFim(Elemento* e);
    Elemento* removeInicio();
    bool remove(int id);
    Elemento* busca(int id);
    void imprime();
};

#endif