#ifndef PILHAENC_H
#define PILHAENC_H

#include "ListaSimples.h"

// TAD Pilha Encadeada (LIFO - Last-In, First-Out) implementado por composição sobre ListaSimples
class PilhaEnc {
private:
    ListaSimples lista; // Estrutura subjacente que gere o encadeamento dinâmico

public:
    // Construtor padrão: inicializa a pilha vazia via construtor de ListaSimples | Complexidade: O(1)
    PilhaEnc();
    
    // Insere um elemento no topo da pilha (push) | Complexidade: O(1)
    void empilhar(Elemento* e);
    
    // Remove e retorna o elemento do topo da pilha (pop) | Complexidade: O(1)
    Elemento* desempilhar();

    // Consulta o elemento no topo da pilha sem removê-lo (top/peek) | Complexidade: O(1)
    Elemento* consultarTopo() const;

    // Verifica se a pilha está vazia | Complexidade: O(1)
    bool pilhaVazia() const;
    
    // Percorre a pilha a partir do topo exibindo os elementos | Complexidade: O(n)
    void imprimir();
};

#endif