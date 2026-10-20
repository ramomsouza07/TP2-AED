#ifndef LISTADUPLA_H
#define LISTADUPLA_H

#include "Elemento.h"
#include <iostream>
using namespace std;

// TAD Lista Duplamente Encadeada com ponteiros descritores de início e fim
class ListaDupla {
private:
    // Classe privada interna do nó com encadeamento duplo
    class No {
    public:
        Elemento* info; // Ponteiro para o dado armazenado
        No* ant;        // Ponteiro para o nó predecessor
        No* prox;       // Ponteiro para o nó sucessor
    };
    
    No* prim; // Ponteiro descritor para o primeiro nó (head)
    No* ult;  // Ponteiro descritor para o último nó (tail)

public:
    // Construtor padrão: inicializa a lista vazia | Complexidade: O(1)
    ListaDupla() { prim = NULL; ult = NULL; }
    
    // Destrutor: desaloca todos os nós da estrutura | Complexidade: O(n)
    ~ListaDupla();

    // Insere um elemento no início da lista | Complexidade: O(1)
    void insereInicio(Elemento* e);
    
    // Insere um elemento no final da lista | Complexidade: O(1)
    void insereFim(Elemento* e);
    
    // Remove o primeiro nó e retorna o seu elemento | Complexidade: O(1)
    Elemento* removeInicio();
    
    // Remove o último nó retrocedendo via ponteiro 'ant' e retorna o elemento | Complexidade: O(1)
    Elemento* removeFim();
    
    // Busca linearmente e remove um nó específico pelo ID | Complexidade: O(n)
    bool remove(int id);
    
    // Realiza busca sequencial pelo ID e retorna o elemento | Complexidade: O(n)
    Elemento* busca(int id);

    // Consulta o primeiro elemento sem removê-lo | Complexidade: O(1)
    Elemento* verInicio() const { return (prim != NULL) ? prim->info : NULL; }

    // Consulta o último elemento sem removê-lo | Complexidade: O(1)
    Elemento* verFim() const { return (ult != NULL) ? ult->info : NULL; }

    // Verifica se a lista está vazia | Complexidade: O(1)
    bool vazia() const { return prim == NULL; }
    
    // Percorre a lista exibindo os elementos na consola | Complexidade: O(n)
    void imprime();
};

#endif