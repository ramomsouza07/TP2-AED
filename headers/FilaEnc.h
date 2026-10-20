#ifndef FILAENC_H
#define FILAENC_H

#include "ListaSimples.h"

// TAD Fila Encadeada (FIFO - First-In, First-Out) implementado por composição sobre ListaSimples
class FilaEnc {
private:
    ListaSimples lista; // Estrutura subjacente que gere o encadeamento dinâmico

public:
    // Construtor padrão: inicializa a fila vazia via construtor de ListaSimples | Complexidade: O(1)
    FilaEnc();
    
    // Insere um elemento no final da fila (enqueue) | Complexidade: O(1)
    void enfileirar(Elemento* e);
    
    // Remove e retorna o elemento do início da fila (dequeue) | Complexidade: O(1)
    Elemento* desenfileirar();

    // Consulta o elemento na frente da fila sem removê-lo | Complexidade: O(1)
    Elemento* consultarInicio() const;

    // Verifica se a fila está vazia | Complexidade: O(1)
    bool filaVazia() const;
    
    // Percorre a fila do início ao fim exibindo os elementos | Complexidade: O(n)
    void imprimir();
};

#endif