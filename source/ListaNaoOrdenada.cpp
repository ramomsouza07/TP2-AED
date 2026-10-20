#include "../headers/ListaNaoOrdenada.h"
#include <iostream>

//aloca o vetor com a capacidade inicial
ListaNaoOrdenada::ListaNaoOrdenada(int cap) {
    capacidade = cap;
    nElementos = 0;
    elementos = new Elemento*[capacidade];
}

//libera a memoria dos elementos e do vetor
ListaNaoOrdenada::~ListaNaoOrdenada() {
    for (int i = 0; i < nElementos; i++) {
        delete elementos[i];
    }
    delete[] elementos;
}

// complexidade O(n) - precisa empurrar todo mundo pra frente
int ListaNaoOrdenada::InserirNoInicio(Elemento* e) {
    if (nElementos >= capacidade) return 0;
    for (int i = nElementos; i > 0; i--) {
        elementos[i] = elementos[i - 1];
    }
    elementos[0] = e;
    nElementos++;
    return 1;
}

//complexidade O(1) - insere direto no fim
int ListaNaoOrdenada::InserirNoFinal(Elemento* e) {
    if (nElementos >= capacidade) return 0;
    elementos[nElementos] = e;
    nElementos++;
    return 1;
}

// complexidade O(n) - puxa os elementos pra tras depois de apagar o primeiro
int ListaNaoOrdenada::RemoverPrimeiro() {
    if (nElementos == 0) return 0;
    delete elementos[0];
    for (int i = 0; i < nElementos - 1; i++) {
        elementos[i] = elementos[i + 1];
    }
    nElementos--;
    return 1;
}

//complexidade O(1) - so apaga o ultimo
int ListaNaoOrdenada::RemoverUltimo() {
    if (nElementos == 0) return 0;
    delete elementos[nElementos - 1];
    nElementos--;
    return 1;
}

// complexidade  O(n) - procura o id no vetor e coloca o ultimo no lugar dele
int ListaNaoOrdenada::RemoverPeloId(long id) {
    for (int i = 0; i < nElementos; i++) {
        if (elementos[i]->getID() == id) {
            delete elementos[i];
            elementos[i] = elementos[nElementos - 1];
            nElementos--;
            return 1;
        }
    }
    return 0;
}

// complexidade O(n) - busca sequencial normal
Elemento* ListaNaoOrdenada::BuscarPeloId(long id) const {
    for (int i = 0; i < nElementos; i++) {
        if (elementos[i]->getID() == id) {
            return elementos[i];
        }
    }
    return nullptr;
}

//complexidade O(n) - acha o elemento pelo id e troca pelo novo
int ListaNaoOrdenada::AlterarPeloId(long id, Elemento* novoElemento) {
    for (int i = 0; i < nElementos; i++) {
        if (elementos[i]->getID() == id) {
            delete elementos[i];
            elementos[i] = novoElemento;
            return 1;
        }
    }
    return 0;
}

// complexidade O(n) - percorre a lista imprimindo
void ListaNaoOrdenada::imprimirTodos() const {
    for (int i = 0; i < nElementos; i++) {
        elementos[i]->imprimirInfo();
    }
}

//complexidade O(1)
int ListaNaoOrdenada::Vazia() const {
    if (nElementos == 0) return 1;
    return 0;
}

// complexidade O(1)
int ListaNaoOrdenada::Cheia() const {
    if (nElementos >= capacidade) return 1;
    return 0;
}

//complexidade O(1)
Elemento* ListaNaoOrdenada::ConsultarPrimeiro() const {
    if (nElementos == 0) return nullptr;
    return elementos[0];
}

// complexidade O(1)
Elemento* ListaNaoOrdenada::ConsultarUltimo() const {
    if (nElementos == 0) return nullptr;
    return elementos[nElementos - 1];
}