#include "../headers/PilhaEnc.h"

// Construtor padrão: o atributo 'lista' é inicializado automaticamente pelo seu próprio construtor | Complexidade: O(1)
PilhaEnc::PilhaEnc() {}

// Empilha (push) inserindo o elemento no início da ListaSimples (topo da pilha) | Complexidade: O(1)
void PilhaEnc::empilhar(Elemento* e) {
    lista.insereInicio(e);
}

// Desempilha (pop) removendo e retornando o elemento do início da ListaSimples (topo da pilha) | Complexidade: O(1)
Elemento* PilhaEnc::desempilhar() {
    return lista.removeInicio();
}

// Retorna o elemento do topo sem desempilhar | Complexidade: O(1)
Elemento* PilhaEnc::consultarTopo() const {
    return lista.verInicio();
}

// Verifica se a estrutura não possui elementos | Complexidade: O(1)
bool PilhaEnc::pilhaVazia() const {
    return lista.vazia();
}

// Delega o percurso linear (do topo à base) e a impressão para a estrutura interna | Complexidade: O(n)
void PilhaEnc::imprimir() {
    lista.imprime();
}