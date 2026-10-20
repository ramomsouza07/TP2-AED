#include "../headers/ListaCircular.h"

// Destrutor: percorre o anel desalocando todos os nós para evitar memory leak | Complexidade: O(n)
ListaCircular::~ListaCircular() {
    if(!prim) return;
    No* p = prim;
    do {
        No* aux = p;
        p = p->prox;
        delete aux;
    } while(p != prim);
    prim = NULL;
}

// Insere no final do anel (imediatamente antes de 'prim') | Complexidade: O(1)
void ListaCircular::insereFim(Elemento* e) {
    No* novo = new No;
    novo->info = e;
    
    if(!prim) {
        // Caso de borda: lista vazia, o nó aponta para si mesmo fechando o anel
        prim = novo;
        novo->prox = novo;
        novo->ant = novo;
    } else {
        // Acede ao último nó em O(1) via 'prim->ant' e insere entre 'ult' e 'prim'
        No* ult = prim->ant;
        novo->prox = prim;
        novo->ant = ult;
        ult->prox = novo;
        prim->ant = novo;
    }
}

// Insere no início do anel aproveitando a inserção O(1) e deslocando 'prim' | Complexidade: O(1)
void ListaCircular::insereInicio(Elemento* e) {
    insereFim(e);
    prim = prim->ant; // O novo nó recém-inserido passa a ser a cabeça da lista
}

// Método padrão de inserção que delega para insereFim | Complexidade: O(1)
void ListaCircular::insere(Elemento* e) {
    insereFim(e);
}

// Remove o primeiro nó ('prim') do anel e retorna o elemento | Complexidade: O(1)
Elemento* ListaCircular::removeInicio() {
    if(!prim) return NULL; // Subfluxo: lista vazia (underflow)
    
    No* p = prim;
    Elemento* ret = p->info;
    
    if(p->prox == p) {
        // Caso de borda: único elemento no anel
        prim = NULL;
    } else {
        No* ult = prim->ant;
        prim = prim->prox;
        prim->ant = ult;
        ult->prox = prim;
    }
    
    delete p;
    return ret;
}

// Remove o último nó ('prim->ant') do anel em O(1) e retorna o elemento | Complexidade: O(1)
Elemento* ListaCircular::removeFim() {
    if(!prim) return NULL; // Subfluxo: lista vazia (underflow)
    
    No* ult = prim->ant;
    if(ult == prim) {
        return removeInicio(); // Caso de borda: único elemento
    }
    
    Elemento* ret = ult->info;
    No* penultimo = ult->ant;
    penultimo->prox = prim;
    prim->ant = penultimo;
    
    delete ult;
    return ret;
}

// Busca linear no anel e remoção de nó por chave (ID) | Complexidade: O(n)
bool ListaCircular::remove(int id) {
    if(!prim) return false; // Subfluxo: lista vazia (underflow)
    
    No* p = prim;
    // Percorre o anel com do-while para avaliar 'prim' antes de testar a volta completa
    do {
        if(p->info->getID() == id) {
            if(p->prox == p) {
                // Caso de borda: remoção do único nó restante na estrutura
                prim = NULL;
            } else {
                // Costura os ponteiros do predecessor e do sucessor ignorando o nó 'p'
                p->ant->prox = p->prox;
                p->prox->ant = p->ant;
                
                // Caso de borda: se o nó removido era a entrada da lista, avança 'prim'
                if(p == prim) prim = p->prox;
            }
            delete p; // Liberta a memória do nó removido
            return true;
        }
        p = p->prox;
    } while(p != prim); // Condição de paragem: completou uma volta inteira no anel
    
    return false; // Chave não encontrada após percorrer toda a lista
}

// Busca sequencial por chave (ID) percorrendo o anel | Complexidade: O(n)
Elemento* ListaCircular::busca(int id) {
    if(!prim) return NULL; // Lista vazia
    
    No* p = prim;
    do {
        if(p->info->getID() == id) return p->info; // Retorna o elemento se a chave coincidir
        p = p->prox;
    } while(p != prim);
    
    return NULL; // Elemento não encontrado
}

// Percurso completo no anel para exibição dos elementos | Complexidade: O(n)
void ListaCircular::imprime() {
    if(!prim) return; // Lista vazia
    
    No* p = prim;
    do {
        p->info->imprimirInfo(); // Delega a impressão ao método do objeto
        p = p->prox;
    } while(p != prim);
}