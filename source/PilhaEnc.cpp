#include "../headers/PilhaEnc.h"

PilhaEnc::PilhaEnc() {}

void PilhaEnc::empilhar(Elemento* e) {
    lista.insereInicio(e);
}

Elemento* PilhaEnc::desempilhar() {
    return lista.removeInicio();
}

void PilhaEnc::imprimir() {
    lista.imprime();
}