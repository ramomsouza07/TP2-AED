#ifndef ARVORE_H
#define ARVORE_H

#include "Elemento.h"
#include <iostream>
using namespace std;

// Arvore Binaria de Busca (ABB): menores a esquerda, maiores a direita
class Arvore {
private:
    // [POO - Encapsulamento]: classe interna No privada, escondendo a estrutura de ponteiros do usuario
    class No {
        public:
            Elemento* info; // [POO - Polimorfismo]: ponteiro da classe base abstrata (aceita Personagem ou Equipamento)
            No* esq;
            No* dir;
    };
    No* raiz; // ponteiro privado para a raiz da arvore

    // metodos auxiliares recursivos privados (so a propria classe acessa)
    No* insereRec(No* no, Elemento* e);
    No* removeRec(No* no, long id, bool &removido);
    No* encontraMenor(No* no);
    Elemento* buscaRec(No* no, long id) const;
    void destroiRec(No* no);
    void emOrdem(No* no) const;
    void preOrdem(No* no) const;
    void posOrdem(No* no) const;
public:
    // construtor: inicia a arvore vazia
    Arvore(){
        raiz = NULL;
    }
    // destrutor: libera todos os nos da memoria ao destruir o objeto
    ~Arvore();

    // [POO - Abstracao]: interface publica simples (o usuario nao precisa lidar com os nos internos)
    void insere(Elemento* e);
    bool remove(long id);
    Elemento* busca(long id) const;
    void imprimeEmOrdem() const;
    void imprimePreOrdem() const;
    void imprimePosOrdem() const;
};

#endif