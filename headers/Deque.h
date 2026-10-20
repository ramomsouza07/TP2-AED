#ifndef DEQUE_H
#define DEQUE_H

#include "ListaDupla.h"

// TAD Deque (Double-Ended Queue) implementado por composição sobre ListaDupla
class Deque {
private:
    ListaDupla lista; // Estrutura subjacente que gere o armazenamento dinâmico

public:
    // Construtor padrão: inicializa o deque vazio via construtor de ListaDupla | Complexidade: O(1)
    Deque();
    
    // Insere um elemento na extremidade frontal do deque | Complexidade: O(1)
    void inserirInicio(Elemento* e);
    
    // Insere um elemento na extremidade traseira do deque | Complexidade: O(1)
    void inserirFim(Elemento* e);
    
    // Remove e retorna o elemento da extremidade frontal | Complexidade: O(1)
    Elemento* removerInicio();
    
    // Remove e retorna o elemento da extremidade traseira | Complexidade: O(1)
    Elemento* removerFim();

    // Consulta o elemento da extremidade frontal sem removê-lo | Complexidade: O(1)
    Elemento* consultarInicio() const;

    // Consulta o elemento da extremidade traseira sem removê-lo | Complexidade: O(1)
    Elemento* consultarFim() const;

    // Verifica se o deque está vazio | Complexidade: O(1)
    bool dequeVazio() const;
    
    // Percorre o deque exibindo os elementos armazenados | Complexidade: O(n)
    void imprimir();
};

#endif