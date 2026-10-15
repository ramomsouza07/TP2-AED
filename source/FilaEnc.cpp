#include "../headers/FilaEnc.h"

FilaEnc::FilaEnc() {}

void FilaEnc::enfileirar(Elemento* e) {
    lista.insereFim(e);
}

Elemento* FilaEnc::desenfileirar() {
    return lista.removeInicio();
}

void FilaEnc::imprimir() {
    lista.imprime();
}