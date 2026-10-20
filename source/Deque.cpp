#include "../headers/Deque.h"

// Construtor padrão: o atributo 'lista' é inicializado automaticamente pelo seu próprio construtor | Complexidade: O(1)
Deque::Deque() {}

// Delega a inserção na extremidade frontal para a ListaDupla subjacente | Complexidade: O(1)
void Deque::inserirInicio(Elemento* e) {
    lista.insereInicio(e);
}

// Delega a inserção na extremidade traseira para a ListaDupla subjacente | Complexidade: O(1)
void Deque::inserirFim(Elemento* e) {
    lista.insereFim(e);
}

// Delega a remoção na extremidade frontal e retorna o elemento | Complexidade: O(1)
Elemento* Deque::removerInicio() {
    return lista.removeInicio();
}

// Delega a remoção na extremidade traseira e retorna o elemento | Complexidade: O(1)
Elemento* Deque::removerFim() {
    return lista.removeFim();
}

// Consulta o primeiro elemento do deque sem removê-lo | Complexidade: O(1)
Elemento* Deque::consultarInicio() const {
    return lista.verInicio();
}

// Consulta o último elemento do deque sem removê-lo | Complexidade: O(1)
Elemento* Deque::consultarFim() const {
    return lista.verFim();
}

// Verifica se o deque está vazio | Complexidade: O(1)
bool Deque::dequeVazio() const {
    return lista.vazia();
}

// Delega o percurso linear e a impressão para a estrutura interna | Complexidade: O(n)
void Deque::imprimir() {
    lista.imprime();
}