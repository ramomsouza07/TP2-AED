#include "../headers/ListaSimples.h"

ListaSimples::~ListaSimples() {
    No* p = prim;
    while(p != NULL) {
        No* t = p->prox;
        delete p;
        p = t;
    }
}

void ListaSimples::insereInicio(Elemento* e) {
    No* novo = new No();
    novo->info = e;
    novo->prox = prim;
    prim = novo;
    if(ult == NULL) ult = novo;
}

void ListaSimples::insereFim(Elemento* e) {
    No* novo = new No();
    novo->info = e;
    novo->prox = NULL;
    if(prim == NULL) {
        prim = novo;
        ult = novo;
    } else {
        ult->prox = novo;
        ult = novo;
    }
}

Elemento* ListaSimples::removeInicio() {
    if(prim == NULL) return NULL;
    No* aux = prim;
    Elemento* e = aux->info;
    prim = prim->prox;
    if(prim == NULL) ult = NULL;
    delete aux;
    return e;
}

bool ListaSimples::remove(int id) {
    No* ant = NULL;
    No* p = prim;
    while(p != NULL && p->info->getID() != id) {
        ant = p;
        p = p->prox;
    }
    if(p == NULL) return false;

    if(ant == NULL) prim = p->prox;
    else ant->prox = p->prox;

    if(p == ult) ult = ant;
    delete p;
    return true;
}

Elemento* ListaSimples::busca(int id) {
    for(No* p = prim; p != NULL; p = p->prox) {
        if(p->info->getID() == id) return p->info;
    }
    return NULL;
}

void ListaSimples::imprime() {
    No* p = prim;
    while(p != NULL) {
        p->info->imprimirInfo();
        p = p->prox;
    }
}