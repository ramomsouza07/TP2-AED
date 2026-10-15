#include "../headers/Arvore.h"

Arvore::~Arvore() {
    destroiRec(raiz);
}

void Arvore::destroiRec(No* no) {
    if(no != NULL) {
        destroiRec(no->esq);
        destroiRec(no->dir);
        delete no;
    }
}

void Arvore::insere(Elemento* e) {
    raiz = insereRec(raiz, e);
}

Arvore::No* Arvore::insereRec(No* no, Elemento* e) {
    if(no == NULL) {
        No* novo = new No();
        novo->info = e;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    if(e->getID() < no->info->getID()) {
        no->esq = insereRec(no->esq, e);
    } else if(e->getID() > no->info->getID()) {
        no->dir = insereRec(no->dir, e);
    }
    return no;
}

Elemento* Arvore::busca(long id) const {
    return buscaRec(raiz, id);
}

Elemento* Arvore::buscaRec(No* no, long id) const {
    if(no == NULL) return NULL;
    if(id == no->info->getID()) return no->info;
    if(id < no->info->getID()) return buscaRec(no->esq, id);
    return buscaRec(no->dir, id);
}

Arvore::No* Arvore::encontraMenor(No* no) {
    No* atual = no;
    while(atual != NULL && atual->esq != NULL) {
        atual = atual->esq;
    }
    return atual;
}

bool Arvore::remove(long id) {
    bool removido = false;
    raiz = removeRec(raiz, id, removido);
    return removido;
}

Arvore::No* Arvore::removeRec(No* no, long id, bool &removido) {
    if(no == NULL) return NULL;

    if(id < no->info->getID()) {
        no->esq = removeRec(no->esq, id, removido);
    } else if(id > no->info->getID()) {
        no->dir = removeRec(no->dir, id, removido);
    } else {
        removido = true;
        // Caso 1 e 2: Sem filhos ou apenas 1 filho
        if(no->esq == NULL) {
            No* temp = no->dir;
            delete no;
            return temp;
        } else if(no->dir == NULL) {
            No* temp = no->esq;
            delete no;
            return temp;
        }
        // Caso 3: Dois filhos (substitui pelo sucessor em-ordem: menor da subárvore direita)
        No* temp = encontraMenor(no->dir);
        no->info = temp->info;
        bool dummy = false;
        no->dir = removeRec(no->dir, temp->info->getID(), dummy);
    }
    return no;
}

void Arvore::imprimeEmOrdem() const {
    emOrdem(raiz);
}

void Arvore::emOrdem(No* no) const {
    if(no != NULL) {
        emOrdem(no->esq);
        no->info->imprimirInfo();
        emOrdem(no->dir);
    }
}

void Arvore::imprimePreOrdem() const {
    preOrdem(raiz);
}

void Arvore::preOrdem(No* no) const {
    if(no != NULL) {
        no->info->imprimirInfo();
        preOrdem(no->esq);
        preOrdem(no->dir);
    }
}

void Arvore::imprimePosOrdem() const {
    posOrdem(raiz);
}

void Arvore::posOrdem(No* no) const {
    if(no != NULL) {
        posOrdem(no->esq);
        posOrdem(no->dir);
        no->info->imprimirInfo();
    }
}

