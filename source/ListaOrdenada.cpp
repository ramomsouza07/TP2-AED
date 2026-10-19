#include "../headers/ListaOrdenada.h"
#include <iostream>

ListaOrdenada::ListaOrdenada(int cap) {
    capacidade = cap;
    nElementos = 0;
    elementos = new Elemento*[capacidade];
}

ListaOrdenada::~ListaOrdenada() {
    for (int i = 0; i < nElementos; i++) {
        delete elementos[i];
    }
    delete[] elementos;
}

int ListaOrdenada::BuscaBinaria(long id) const {
    int ini = 0;
    int fim = nElementos - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (elementos[meio]->getID() == id) {
            return meio;
        } else if (elementos[meio]->getID() < id) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int ListaOrdenada::Inserir(Elemento* e) {
    if (nElementos >= capacidade) return 0;
    
    int pos = 0;
    while (pos < nElementos && elementos[pos]->getID() < e->getID()) {
        pos++;
    }
    
    if (pos < nElementos && elementos[pos]->getID() == e->getID()) {
        return 0; 
    }
    
    for (int i = nElementos; i > pos; i--) {
        elementos[i] = elementos[i - 1];
    }
    
    elementos[pos] = e;
    nElementos++;
    return 1;
}

int ListaOrdenada::InserirNoInicio(Elemento* e) {
    return Inserir(e);
}

int ListaOrdenada::InserirNoFinal(Elemento* e) {
    return Inserir(e);
}

int ListaOrdenada::RemoverPrimeiro() {
    if (nElementos == 0) return 0;
    delete elementos[0];
    for (int i = 0; i < nElementos - 1; i++) {
        elementos[i] = elementos[i + 1];
    }
    nElementos--;
    return 1;
}

int ListaOrdenada::RemoverUltimo() {
    if (nElementos == 0) return 0;
    delete elementos[nElementos - 1];
    nElementos--;
    return 1;
}

int ListaOrdenada::RemoverPeloId(long id) {
    int pos = BuscaBinaria(id);
    if (pos == -1) return 0;
    
    delete elementos[pos];
    for (int i = pos; i < nElementos - 1; i++) {
        elementos[i] = elementos[i + 1];
    }
    nElementos--;
    return 1;
}

Elemento* ListaOrdenada::BuscarPeloId(long id) const {
    int pos = BuscaBinaria(id);
    if (pos != -1) {
        return elementos[pos];
    }
    return nullptr;
}

int ListaOrdenada::AlterarPeloId(long id, Elemento* novoElemento) {
    if (RemoverPeloId(id) == 1) {
        return Inserir(novoElemento);
    }
    return 0;
}

void ListaOrdenada::imprimirTodos() const {
    for (int i = 0; i < nElementos; i++) {
        elementos[i]->imprimirInfo();
    }
}