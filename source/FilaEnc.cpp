#include "../headers/FilaEnc.h"

// Construtor padrão: o atributo 'lista' é inicializado automaticamente pelo seu próprio construtor | Complexidade: O(1)
FilaEnc::FilaEnc() {}

// Enfileira (enqueue) delegando a inserção para o fim da ListaSimples (via ponteiro 'ult') | Complexidade: O(1)
void FilaEnc::enfileirar(Elemento* e) {
    lista.insereFim(e);
}

// Desenfileira (dequeue) removendo e retornando o elemento do início da ListaSimples (via ponteiro 'prim') | Complexidade: O(1)
Elemento* FilaEnc::desenfileirar() {
    return lista.removeInicio();
}

// Consulta o primeiro elemento da fila sem removê-lo | Complexidade: O(1)
Elemento* FilaEnc::consultarInicio() const {
    return lista.verInicio();
}

// Verifica se a fila está vazia | Complexidade: O(1)
bool FilaEnc::filaVazia() const {
    return lista.vazia();
}

// Delega o percurso linear e a impressão dos elementos para a estrutura interna | Complexidade: O(n)
void FilaEnc::imprimir() {
    lista.imprime();
}