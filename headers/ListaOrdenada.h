#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include "Elemento.h"

// Lista sequencial ordenada pelo id
class ListaOrdenada {
private:
    Elemento** elementos;
    int capacidade;
    int nElementos;

    int BuscaBinaria(long id) const; // auxiliar pra achar rapido

public:
    ListaOrdenada(int cap = 50);
    ~ListaOrdenada();

    int InserirNoInicio(Elemento* e);
    int InserirNoFinal(Elemento* e);
    int Inserir(Elemento* e); 
    int RemoverPrimeiro();
    int RemoverUltimo();
    int RemoverPeloId(long id);
    Elemento* BuscarPeloId(long id) const;
    int AlterarPeloId(long id, Elemento* novoElemento);
    void imprimirTodos() const;
};

#endif