#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

#include "Elemento.h"
#include <iostream>
using namespace std;

// TAD Lista Duplamente Encadeada Circular com ponteiro descritor de acesso
class ListaCircular {
private:
    // Classe privada interna do nó com encadeamento duplo circular
    class No {
    public:
        Elemento* info; // Ponteiro para o dado armazenado
        No *ant, *prox; // Ponteiros para os nós predecessor e sucessor no anel
    };
    
    No* prim; // Ponteiro descritor de entrada da lista (prim->ant referencia o último nó)

public:
    // Construtor padrão: inicializa a estrutura vazia | Complexidade: O(1)
    ListaCircular() { prim = NULL; }

    // Destrutor: desfaz o anel e desaloca todos os nós da estrutura | Complexidade: O(n)
    ~ListaCircular();
    
    // Insere um elemento no final do anel (mantido por compatibilidade) | Complexidade: O(1)
    void insere(Elemento* e);

    // Insere um elemento no início do anel (atualizando 'prim') | Complexidade: O(1)
    void insereInicio(Elemento* e);

    // Insere um elemento no final do anel (via 'prim->ant') | Complexidade: O(1)
    void insereFim(Elemento* e);

    // Remove o primeiro nó do anel e retorna o seu elemento | Complexidade: O(1)
    Elemento* removeInicio();

    // Remove o último nó do anel e retorna o seu elemento | Complexidade: O(1)
    Elemento* removeFim();
    
    // Busca linearmente pela chave (ID) e remove o nó correspondente | Complexidade: O(n)
    bool remove(int id);
    
    // Realiza busca sequencial no anel pelo ID e retorna o elemento | Complexidade: O(n)
    Elemento* busca(int id);

    // Verifica se a lista circular está vazia | Complexidade: O(1)
    bool vazia() const { return prim == NULL; }
    
    // Percorre o anel até retornar ao nó inicial exibindo os elementos | Complexidade: O(n)
    void imprime();
};

#endif