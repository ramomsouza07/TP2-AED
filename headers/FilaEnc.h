#ifndef FILAENC_H
#define FILAENC_H

#include "ListaSimples.h"

class FilaEnc {
private:
    ListaSimples lista;

public:
    FilaEnc();
    void enfileirar(Elemento* e);
    Elemento* desenfileirar();
    void imprimir();
};

#endif