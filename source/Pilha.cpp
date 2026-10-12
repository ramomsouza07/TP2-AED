#include "Pilha.h"

Pilha::Pilha(int capacidade) : lista(capacidade) {
}

bool Pilha::empilhar(Elemento* e) {
    return lista.InserirNoFinal(e);
}

bool Pilha::desempilhar() {
    return lista.RemoverUltimo();
}
 
Elemento* Pilha::consultarTopo() const {
    return lista.ConsultarUltimo();
}
 
bool Pilha::pilhaCheia() const {
    return lista.Cheia();
}
 
bool Pilha::pilhaVazia() const {
    return lista.Vazia();
}