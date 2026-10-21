#ifndef GRAFO_H
#define GRAFO_H

#include "Elemento.h"
#include <iostream>

using namespace std;

// Classe Grafo: implementa DUPLA REPRESENTACAO SIMULTANEA (Lista de Adjacencia + Matriz de Adjacencia)
// em conformidade com as diretrizes da disciplina de AED.
class Grafo {
private:
    // Classe Aresta interna privada para a lista encadeada de adjacencia
    class Aresta {
    public:
        long idDestino;      // Identificador do vertice de destino
        int peso;            // Peso associado a conexao (ponderacao)
        Aresta* prox;        // Ponteiro para a proxima aresta da lista

        // Construtor da Aresta | Complexidade: O(1)
        Aresta(long id, int p, Aresta* px = NULL) {
            idDestino = id;
            peso = p;
            prox = px;
        }
    };

    // Classe Vertice interna privada para a lista de vertices
    class Vertice {
    public:
        Elemento* info;         // Ponteiro polimorfico para Elemento (Personagem ou Equipamento)
        Aresta* primeiraAresta; // Ponteiro para o inicio da lista de arestas adjacentes
        Vertice* prox;          // Ponteiro para o proximo vertice da lista encadeada

        // Construtor do Vertice | Complexidade: O(1)
        Vertice(Elemento* inf, Vertice* px = NULL) {
            info = inf;
            primeiraAresta = NULL;
            prox = px;
        }
    };

    // --- Representacao 1: Lista de Adjacencia Encadeada Dinamica ---
    Vertice* primeiro;          // Ponteiro para o primeiro vertice da lista
    int numVertices;            // Quantidade de vertices no grafo
    bool direcionado;           // Indicador de direcionamento das arestas (digrafo ou nao)

    // --- Representacao 2: Matriz de Adjacencia Dinamica ---
    int** matrizAdj;            // Matriz bidimensional dinamica de pesos
    long* idsMatriz;            // Vetor de mapeamento: indice [0..numVertices-1] -> ID do vertice
    int capacidadeMatriz;       // Capacidade maxima alocada para linhas/colunas da matriz

    // --- Metodos Auxiliares Privados ---
    // Busca vertice por ID na lista encadeada | Complexidade: O(V)
    Vertice* encontraVertice(long id) const;

    // Retorna o indice de um ID na matriz de adjacencia (-1 se inexistente) | Complexidade: O(V)
    int indiceVertice(long id) const;

    // Insere aresta direcionada internamente na lista | Complexidade: O(1)
    void insereArestaDirecionadaLista(Vertice* vOrigem, long idDestino, int peso);

    // Remove aresta direcionada internamente na lista | Complexidade: O(grau(v)) <= O(V)
    bool removeArestaDirecionadaLista(Vertice* vOrigem, long idDestino);

    // Libera a memoria de uma lista encadeada de arestas | Complexidade: O(grau(v)) <= O(V)
    void liberaArestas(Aresta* a);

    // Redimensiona dinamicamente a matriz e o vetor de IDs quando capacidade esgota | Complexidade: O(V^2)
    void redimensionaMatriz();

    // Desaloca toda a memoria da lista, arestas, elementos e matriz | Complexidade: O(V^2 + E)
    void destroiGrafo();

    // Auxiliar de busca: verifica se ID ja foi visitado | Complexidade: O(V)
    bool jaVisitado(long id, const long* visitados, int totalVisitados) const;

    // Metodo recursivo auxiliar para percurso em profundidade | Complexidade: O(V + E)
    void dfsRec(Vertice* vAtual, long* visitados, int& totalVisitados) const;

public:
    // Construtor com inicializacao simultanea da matriz e lista | Complexidade: O(capacidadeMatriz^2)
    Grafo(bool ehDirecionado = false, int capInicial = 100);

    // Destrutor que libera toda a memoria alocada | Complexidade: O(V^2 + E)
    ~Grafo();

    // Insercao de Vertice (sincroniza lista e matriz) | Complexidade: O(V) amortizado
    bool insereVertice(Elemento* e);

    // Insercao de Aresta (sincroniza lista e matriz) | Complexidade: O(V)
    bool insereAresta(long idOrigem, long idDestino, int peso = 1);

    // Remocao de Aresta (sincroniza lista e matriz) | Complexidade: O(V)
    bool removeAresta(long idOrigem, long idDestino);

    // Remocao de Vertice (sincroniza lista e reorganiza matriz) | Complexidade: O(V^2)
    bool removeVertice(long id);

    // Consulta de Vertice | Complexidade: O(V)
    Elemento* buscaVertice(long id) const;

    // Verificacao de existencia de aresta (consulta direta via matriz) | Complexidade: O(V)
    bool existeAresta(long idOrigem, long idDestino) const;

    // Verificacao de vizinhanca entre dois vertices | Complexidade: O(V)
    bool saoVizinhos(long id1, long id2) const;

    // Retorna o grau do vertice pelo ID (-1 se nao existir) | Complexidade: O(V)
    int obterGrau(long id) const;

    // Retorna quantidade total de vertices cadastrados | Complexidade: O(1)
    int getNumVertices() const;

    // Verifica se o grafo esta sem vertices | Complexidade: O(1)
    bool estaVazio() const;

    // Exibe ambas as representacoes: Lista e Matriz de Adjacencia | Complexidade: O(V^2)
    void imprimeGrafo() const;

    // Exibe os vizinhos imediatos de um vertice | Complexidade: O(V + grau(v))
    void imprimeVizinhos(long id) const;

    // Percurso em Largura (BFS) a partir de um vertice | Complexidade: O(V + E)
    void buscaEmLargura(long idInicio) const;

    // Percurso em Profundidade (DFS) a partir de um vertice | Complexidade: O(V + E)
    void buscaEmProfundidade(long idInicio) const;
};

#endif
