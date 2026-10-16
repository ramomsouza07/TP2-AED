#ifndef GRAFO_H
#define GRAFO_H

#include "Elemento.h"
#include <iostream>

using namespace std;

// Classe Grafo: representa um grafo ponderado utilizando lista de adjacência dinâmica.
// Os vértices armazenam ponteiros para 'Elemento' (Personagem ou Equipamento).
class Grafo {
private:
    // Estrutura para representar cada Aresta na lista encadeada de adjacência
    struct Aresta {
        long idDestino;      // ID do vértice de destino
        int peso;            // Peso da aresta (ex: afinidade, nível de relação, distância)
        Aresta* prox;        // Próxima aresta na lista encadeada
    };

    // Estrutura para representar cada Vértice do Grafo
    struct Vertice {
        Elemento* info;         // Ponteiro para o Elemento armazenado (Personagem ou Equipamento)
        Aresta* primeiraAresta; // Ponteiro para a lista de arestas que partem deste vértice
        Vertice* prox;          // Próximo vértice na lista de vértices do grafo
    };

    Vertice* primeiro;       // Ponteiro para o primeiro vértice da lista
    int numVertices;         // Quantidade total de vértices no grafo
    bool direcionado;        // Indica se o grafo é direcionado (dígrafo) ou não-direcionado

    // Métodos auxiliares privados
    Vertice* encontraVertice(long id) const;
    void insereArestaDirecionada(Vertice* vOrigem, long idDestino, int peso);
    bool removeArestaDirecionada(Vertice* vOrigem, long idDestino);
    void liberaArestas(Aresta* a);
    void destroiGrafo();

    // Métodos auxiliares para percursos
    bool jaVisitado(long id, const long* visitados, int totalVisitados) const;
    void dfsRec(Vertice* vAtual, long* visitados, int& totalVisitados) const;

public:
    // Construtor: por padrão cria grafo não-direcionado (conexões bidirecionais de aliança/vínculo)
    Grafo(bool ehDirecionado = false);

    // Destrutor: desaloca toda a memória de vértices, arestas e elementos
    ~Grafo();

    // Operações de Inserção
    bool insereVertice(Elemento* e);
    bool insereAresta(long idOrigem, long idDestino, int peso = 1);

    // Operações de Remoção
    bool removeAresta(long idOrigem, long idDestino);
    bool removeVertice(long id);

    // Operações de Consulta e Busca
    Elemento* buscaVertice(long id) const;
    bool existeAresta(long idOrigem, long idDestino) const;
    int getNumVertices() const;
    bool estaVazio() const;

    // Métodos de Exibição e Percursos Clássicos
    void imprimeGrafo() const;
    void imprimeVizinhos(long id) const;
    void buscaEmLargura(long idInicio) const;
    void buscaEmProfundidade(long idInicio) const;
};

#endif
