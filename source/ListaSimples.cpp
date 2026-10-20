#include "../headers/ListaSimples.h"

// Destrutor: percorre a lista desalocando cada nó para evitar memory leak | Complexidade: O(n)
ListaSimples::~ListaSimples() {
    No* p = prim;
    while(p != NULL) {
        No* t = p->prox; // Guarda a referência para o próximo nó antes da desalocação
        delete p;        // Liberta a memória do nó atual
        p = t;           // Avança para o próximo nó
    }
}

// Insere no início atualizando o descritor 'prim' | Complexidade: O(1)
void ListaSimples::insereInicio(Elemento* e) {
    No* novo = new No();
    novo->info = e;
    novo->prox = prim; // O antigo primeiro nó passa a ser o segundo
    prim = novo;       // Atualiza a cabeça da lista
    
    // Caso de borda: se a lista estava vazia, o novo nó também é o último
    if(ult == NULL) ult = novo;
}

// Insere no fim utilizando o descritor 'ult' sem percorrer a lista | Complexidade: O(1)
void ListaSimples::insereFim(Elemento* e) {
    No* novo = new No();
    novo->info = e;
    novo->prox = NULL; // Novo último nó aponta sempre para NULL
    
    if(prim == NULL) {
        // Caso de borda: inserção em lista vazia
        prim = novo;
        ult = novo;
    } else {
        // Encadeia após o último nó atual e atualiza a cauda
        ult->prox = novo;
        ult = novo;
    }
}

// Remove o primeiro nó e retorna o dado armazenado | Complexidade: O(1)
Elemento* ListaSimples::removeInicio() {
    if(prim == NULL) return NULL; // Subfluxo: lista vazia (underflow)
    
    No* aux = prim;               // Guarda o nó a ser desalocado
    Elemento* e = aux->info;      // Preserva o ponteiro do elemento para retorno
    prim = prim->prox;            // Avança a cabeça da lista
    
    // Caso de borda: se a lista ficou vazia, aterra o ponteiro 'ult'
    if(prim == NULL) ult = NULL;
    
    delete aux;                   // Desaloca o nó da estrutura
    return e;
}

// Remove o último nó percorrendo até ao penúltimo elemento | Complexidade: O(n)
Elemento* ListaSimples::removeFim() {
    if(prim == NULL) return NULL; // Subfluxo: lista vazia (underflow)
    
    Elemento* e = ult->info;
    
    // Caso de borda: lista com apenas um elemento
    if(prim == ult) {
        delete prim;
        prim = NULL;
        ult = NULL;
        return e;
    }
    
    // Busca linear até localizar o penúltimo nó (predecessor de 'ult')
    No* ant = prim;
    while(ant->prox != ult) {
        ant = ant->prox;
    }
    
    delete ult;       // Liberta a memória do último nó
    ult = ant;        // O penúltimo passa a ser o novo último
    ult->prox = NULL; // Aterra o ponteiro final
    return e;
}

// Busca linear e remoção de nó por chave (ID) com reencadeamento | Complexidade: O(n)
bool ListaSimples::remove(int id) {
    No* ant = NULL; // Ponteiro auxiliar para manter o nó anterior
    No* p = prim;   // Ponteiro de busca
    
    // Percorre a lista até encontrar o ID ou atingir o fim
    while(p != NULL && p->info->getID() != id) {
        ant = p;
        p = p->prox;
    }
    
    if(p == NULL) return false; // Elemento não encontrado na estrutura

    // Reencadeamento: verifica se a remoção ocorre na cabeça ou no meio/fim
    if(ant == NULL) prim = p->prox;
    else ant->prox = p->prox;

    // Caso de borda: se o nó removido era o último, atualiza o descritor 'ult'
    if(p == ult) ult = ant;
    
    delete p; // Liberta o nó removido da memória
    return true;
}

// Busca sequencial por chave (ID) | Complexidade: O(n)
Elemento* ListaSimples::busca(int id) {
    for(No* p = prim; p != NULL; p = p->prox) {
        if(p->info->getID() == id) return p->info; // Retorna o elemento se a chave coincidir
    }
    return NULL; // Chave não encontrada
}

// Percurso linear para exibição dos elementos | Complexidade: O(n)
void ListaSimples::imprime() {
    No* p = prim;
    while(p != NULL) {
        p->info->imprimirInfo(); // Delega a impressão ao método do próprio objeto
        p = p->prox;
    }
}