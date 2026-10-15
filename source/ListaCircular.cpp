#include "../headers/ListaCircular.h"

void ListaCircular::insere(Elemento* e) {
    No* novo = new No;
    novo->info = e;
    if(!prim) {
        prim = novo;
        novo->prox = novo;
        novo->ant = novo;
    } else {
        No* ult = prim->ant;
        novo->prox = prim;
        novo->ant = ult;
        ult->prox = novo;
        prim->ant = novo;
    }
}

bool ListaCircular::remove(int id) {
    if(!prim) return false;
    No* p = prim;
    do {
        if(p->info->getID() == id) {
            if(p->prox == p) {
                prim = NULL;
            } else {
                p->ant->prox = p->prox;
                p->prox->ant = p->ant;
                if(p == prim) prim = p->prox;
            }
            delete p;
            return true;
        }
        p = p->prox;
    } while(p != prim);
    
    return false;
}

Elemento* ListaCircular::busca(int id) {
    if(!prim) return NULL;
    No* p = prim;
    do {
        if(p->info->getID() == id) return p->info;
        p = p->prox;
    } while(p != prim);
    return NULL;
}

void ListaCircular::imprime() {
    if(!prim) return;
    No* p = prim;
    do {
        p->info->imprimirInfo();
        p = p->prox;
    } while(p != prim);
}