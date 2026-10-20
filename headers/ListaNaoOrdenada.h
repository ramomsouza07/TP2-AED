#ifndef LISTANAOORDENADA_H
#define LISTANAOORDENADA_H

#include "Elemento.h"

//Lista sequencial nao ordenada
class ListaNaoOrdenada {
private:
    Elemento** elementos; // vetor de ponteiros
    int capacidade;
    int nElementos;

public:
    ListaNaoOrdenada(int cap = 50);
    ~ListaNaoOrdenada();

    int InserirNoInicio(Elemento* e);
    int InserirNoFinal(Elemento* e);
    int RemoverPrimeiro();
    int RemoverUltimo();
    int RemoverPeloId(long id);
    Elemento* BuscarPeloId(long id) const;
    int AlterarPeloId(long id, Elemento* novoElemento);
    void imprimirTodos() const;
    int Vazia() const;
    int Cheia() const;
    Elemento* ConsultarPrimeiro() const;
    Elemento* ConsultarUltimo() const;
};

#endif