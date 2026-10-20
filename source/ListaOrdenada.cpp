#include "../headers/ListaOrdenada.h"
#include <iostream>

ListaOrdenada::ListaOrdenada(int cap) {
    capacidade = cap;
    nElementos = 0;
    elementos = new Elemento*[capacidade];
}

//limpa a memoria
ListaOrdenada::~ListaOrdenada() {
    for (int i = 0; i < nElementos; i++) {
        delete elementos[i];
    }
    delete[] elementos;
}

// complexidade O(log n) - divide na metade ate achar
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

// complexidade O(n) - acha a posicao certa e desloca os maiores pra frente
int ListaOrdenada::Inserir(Elemento* e) {
    if (nElementos >= capacidade) return 0;
    
    int pos = 0;
    while (pos < nElementos && elementos[pos]->getID() < e->getID()) {
        pos++;
    }
    
    // nao deixa inserir id repetido
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

// complexidade O(n) - chama o inserir normal pq precisa manter ordenado
int ListaOrdenada::InserirNoInicio(Elemento* e) {
    return Inserir(e);
}

//complexidade O(n)
int ListaOrdenada::InserirNoFinal(Elemento* e) {
    return Inserir(e);
}

// complexidade O(n) - remove o primeiro e puxa o resto
int ListaOrdenada::RemoverPrimeiro() {
    if (nElementos == 0) return 0;
    delete elementos[0];
    for (int i = 0; i < nElementos - 1; i++) {
        elementos[i] = elementos[i + 1];
    }
    nElementos--;
    return 1;
}

// complexidade  O(1) - remove direto do final
int ListaOrdenada::RemoverUltimo() {
    if (nElementos == 0) return 0;
    delete elementos[nElementos - 1];
    nElementos--;
    return 1;
}

// complexidade O(n) - acha com busca binaria mas tem q deslocar o vetor
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

//complexidade O(log n) - usa a busca binaria
Elemento* ListaOrdenada::BuscarPeloId(long id) const {
    int pos = BuscaBinaria(id);
    if (pos != -1) {
        return elementos[pos];
    }
    return nullptr;
}

//complexidade O(n) - remove o antigo e insere o novo na posicao ordenada
int ListaOrdenada::AlterarPeloId(long id, Elemento* novoElemento) {
    if (RemoverPeloId(id) == 1) {
        return Inserir(novoElemento);
    }
    return 0;
}

// complexidade O(n)
void ListaOrdenada::imprimirTodos() const {
    for (int i = 0; i < nElementos; i++) {
        elementos[i]->imprimirInfo();
    }
}