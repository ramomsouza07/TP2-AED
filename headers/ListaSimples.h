#ifndef LISTASIMPLES_H
#define LISTASIMPLES_H

#include "Elemento.h"
#include <iostream>
using namespace std;

// TAD Lista Simplesmente Encadeada com ponteiros descritores de início e fim
class ListaSimples {
private:
    // Classe privada interna do nó, ocultando detalhes de implementação do utilizador final
    class No {
    public:
        Elemento* info; // Ponteiro para o dado armazenado
        No* prox;       // Ponteiro para o próximo nó da sequência
    };
    
    No* prim; // Ponteiro descritor para o primeiro nó (head)
    No* ult;  // Ponteiro descritor para o último nó (tail)

public:
    // Construtor padrão: inicializa a lista vazia | Complexidade: O(1)
    ListaSimples() { prim = NULL; ult = NULL; }
    
    // Destrutor: desaloca todos os nós da lista | Complexidade: O(n)
    ~ListaSimples();
    
    // Insere um elemento no início da lista | Complexidade: O(1)
    void insereInicio(Elemento* e);

    // Insere um elemento no final da lista via ponteiro 'ult' | Complexidade: O(1)
    void insereFim(Elemento* e);
    
    // Remove o primeiro nó e retorna o seu elemento | Complexidade: O(1)
    Elemento* removeInicio();

    // Remove o último nó percorrendo até ao penúltimo e retorna o elemento | Complexidade: O(n)
    Elemento* removeFim();
    
    // Busca e remove um nó específico pelo ID | Complexidade: O(n)
    bool remove(int id);
    
    // Realiza busca linear pelo ID e retorna o elemento | Complexidade: O(n)
    Elemento* busca(int id);

    // Consulta o primeiro elemento sem removê-lo | Complexidade: O(1)
    Elemento* verInicio() const { return (prim != NULL) ? prim->info : NULL; }

    // Verifica se a lista está vazia | Complexidade: O(1)
    bool vazia() const { return prim == NULL; }
    
    // Percorre a lista exibindo os elementos na consola | Complexidade: O(n)
    void imprime();
};

#endif