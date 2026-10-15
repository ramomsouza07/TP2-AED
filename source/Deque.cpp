#include "../headers/Deque.h"

Deque::Deque() {}

void Deque::inserirInicio(Elemento* e) {
    lista.insereInicio(e);
}

void Deque::inserirFim(Elemento* e) {
    lista.insereFim(e);
}

Elemento* Deque::removerInicio() {
    return lista.removeInicio();
}

Elemento* Deque::removerFim() {
    return lista.removeFim();
}

void Deque::imprimir() {
    lista.imprime();
}