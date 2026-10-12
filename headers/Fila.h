#ifndef FILA_H
#define FILA_H
 
#include "Elemento.h"
#include "ListaNaoOrdenada.h"
 
class Fila {
private:
    ListaNaoOrdenada lista;
 
public:
    Fila(int capacidade = 50);
 
    bool enfileirar(Elemento* e);
    bool desenfileirar();
    Elemento* consultarInicio() const;
    bool filaCheia() const;
    bool filaVazia() const;
};
 
#endif