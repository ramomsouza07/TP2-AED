#ifndef ARVORE_H
#define ARVORE_H

#include "Elemento.h"
#include <iostream>
using namespace std;

class Arvore {
private:
    struct No {
        Elemento* info;
        No* esq;
        No* dir;
    };
    No* raiz;

    No* insereRec(No* no, Elemento* e);
    No* removeRec(No* no, long id, bool &removido);
    No* encontraMenor(No* no);
    Elemento* buscaRec(No* no, long id) const;
    void destroiRec(No* no);
    void emOrdem(No* no) const;
    void preOrdem(No* no) const;
    void posOrdem(No* no) const;
public:
    Arvore(){
        raiz = NULL;
    }
    ~Arvore();

    void insere(Elemento* e);
    bool remove(long id);
    Elemento* busca(long id) const;
    void imprimeEmOrdem() const;
    void imprimePreOrdem() const;
    void imprimePosOrdem() const;
};

#endif