#include "../headers/ListaDupla.h"

ListaDupla::~ListaDupla() {
    No* p = prim;
    while(p) {
        No* aux = p;
        p = p->prox;
        delete aux;
    }
}

void ListaDupla::insereInicio(Elemento* e) {
    No* novo = new No;
    novo->info = e;
    novo->ant = NULL;
    novo->prox = prim;
    if(prim != NULL) prim->ant = novo;
    else ult = novo;
    prim = novo;
}

void ListaDupla::insereFim(Elemento* e) {
    No* novo = new No;
    novo->info = e;
    novo->prox = NULL;
    novo->ant = ult;
    if(ult != NULL) ult->prox = novo;
    else prim = novo;
    ult = novo;
}

Elemento* ListaDupla::removeInicio() {
    if(!prim) return NULL;
    No* p = prim;
    Elemento* ret = p->info;
    prim = prim->prox;
    if(prim) prim->ant = NULL;
    else ult = NULL;
    delete p;
    return ret;
}

Elemento* ListaDupla::removeFim() {
    if(!ult) return NULL;
    No* p = ult;
    Elemento* ret = p->info;
    ult = ult->ant;
    if(ult) ult->prox = NULL;
    else prim = NULL;
    delete p;
    return ret;
}

bool ListaDupla::remove(int id) {
    No* p = prim;
    while(p && p->info->getID() != id) p = p->prox;
    if(!p) return false;

    if(p == prim) { removeInicio(); return true; }
    if(p == ult) { removeFim(); return true; }

    p->ant->prox = p->prox;
    p->prox->ant = p->ant;
    delete p;
    return true;
}

Elemento* ListaDupla::busca(int id) {
    No* p = prim;
    while(p) {
        if(p->info->getID() == id) return p->info;
        p = p->prox;
    }
    return NULL;
}

void ListaDupla::imprime() {
    for(No* p = prim; p != NULL; p = p->prox)
        p->info->imprimirInfo();
}