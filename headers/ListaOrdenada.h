#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include "Elemento.h"

class ListaOrdenada {
private:
    Elemento** elementos;
    int capacidade;
    int nElementos;

    int BuscaBinaria(long id) const;

public:
    ListaOrdenada(int cap = 50);
    ~ListaOrdenada();

    bool InserirNoInicio(Elemento* e);
    bool InserirNoFinal(Elemento* e);
    bool Inserir(Elemento* e); 
    bool RemoverPrimeiro();
    bool RemoverUltimo();
    bool RemoverPeloId(long id);
    Elemento* BuscarPeloId(long id) const;
    bool AlterarPeloId(long id, Elemento* novoElemento);
    void imprimirTodos() const;
};

#endif