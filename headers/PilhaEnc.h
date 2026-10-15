#ifndef PILHAENC_H
#define PILHAENC_H

#include "ListaSimples.h"

class PilhaEnc {
private:
    ListaSimples lista;

public:
    PilhaEnc();
    void empilhar(Elemento* e);
    Elemento* desempilhar();
    void imprimir();
};

#endif