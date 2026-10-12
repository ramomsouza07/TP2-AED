#ifndef LISTANAOORDENADA_H
#define LISTANAOORDENADA_H

#include "Elemento.h"

class ListaNaoOrdenada {
private:
    Elemento** elementos;
    int capacidade;
    int nElementos;

public:
    ListaNaoOrdenada(int cap = 50);
    ~ListaNaoOrdenada();

    bool InserirNoInicio(Elemento* e);
    bool InserirNoFinal(Elemento* e);
    bool RemoverPrimeiro();
    bool RemoverUltimo();
    bool RemoverPeloId(long id);
    Elemento* BuscarPeloId(long id) const;
    bool AlterarPeloId(long id, Elemento* novoElemento);
    void imprimirTodos() const;
    bool Vazia() const;
    bool Cheia() const;
    Elemento* ConsultarPrimeiro() const;
    Elemento* ConsultarUltimo() const;
};

#endif