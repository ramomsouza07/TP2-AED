#ifndef DEQUE_H
#define DEQUE_H

#include "ListaDupla.h"

class Deque {
private:
    ListaDupla lista;

public:
    Deque();
    void inserirInicio(Elemento* e);
    void inserirFim(Elemento* e);
    Elemento* removerInicio();
    Elemento* removerFim();
    void imprimir();
};

#endif