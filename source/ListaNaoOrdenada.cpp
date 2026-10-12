#include "../headers/ListaNaoOrdenada.h"
#include <iostream>

ListaNaoOrdenada::ListaNaoOrdenada(int cap) {
    capacidade = cap;
    nElementos = 0;
    elementos = new Elemento*[capacidade];
}

ListaNaoOrdenada::~ListaNaoOrdenada() {
    for (int i = 0; i < nElementos; i++) {
        delete elementos[i];
    }
    delete[] elementos;
}

bool ListaNaoOrdenada::InserirNoInicio(Elemento* e) {
    if (nElementos >= capacidade) return false;
    for (int i = nElementos; i > 0; i--) {
        elementos[i] = elementos[i - 1];
    }
    elementos[0] = e;
    nElementos++;
    return true;
}

bool ListaNaoOrdenada::InserirNoFinal(Elemento* e) {
    if (nElementos >= capacidade) return false;
    elementos[nElementos] = e;
    nElementos++;
    return true;
}

bool ListaNaoOrdenada::RemoverPrimeiro() {
    if (nElementos == 0) return false;
    delete elementos[0];
    for (int i = 0; i < nElementos - 1; i++) {
        elementos[i] = elementos[i + 1];
    }
    nElementos--;
    return true;
}

bool ListaNaoOrdenada::RemoverUltimo() {
    if (nElementos == 0) return false;
    delete elementos[nElementos - 1];
    nElementos--;
    return true;
}

bool ListaNaoOrdenada::RemoverPeloId(long id) {
    for (int i = 0; i < nElementos; i++) {
        if (elementos[i]->getID() == id) {
            delete elementos[i];
            elementos[i] = elementos[nElementos - 1];
            nElementos--;
            return true;
        }
    }
    return false;
}

Elemento* ListaNaoOrdenada::BuscarPeloId(long id) const {
    for (int i = 0; i < nElementos; i++) {
        if (elementos[i]->getID() == id) {
            return elementos[i];
        }
    }
    return nullptr;
}

bool ListaNaoOrdenada::AlterarPeloId(long id, Elemento* novoElemento) {
    for (int i = 0; i < nElementos; i++) {
        if (elementos[i]->getID() == id) {
            delete elementos[i];
            elementos[i] = novoElemento;
            return true;
        }
    }
    return false;
}

void ListaNaoOrdenada::imprimirTodos() const {
    for (int i = 0; i < nElementos; i++) {
        elementos[i]->imprimirInfo();
    }
}
bool ListaNaoOrdenada::Vazia() const {
    return nElementos == 0;
}

bool ListaNaoOrdenada::Cheia() const {
    return nElementos >= capacidade;
}

Elemento* ListaNaoOrdenada::ConsultarPrimeiro() const {
    if (nElementos == 0) return nullptr;
    return elementos[0];
}

Elemento* ListaNaoOrdenada::ConsultarUltimo() const {
    if (nElementos == 0) return nullptr;
    return elementos[nElementos - 1];
}