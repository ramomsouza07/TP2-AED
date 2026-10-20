#include "../headers/ListaDupla.h"

// Destrutor: percorre a estrutura desalocando cada nó para evitar memory leak | Complexidade: O(n)
ListaDupla::~ListaDupla() {
    No* p = prim;
    while(p) {
        No* aux = p; // Guarda a referência do nó atual para desalocação
        p = p->prox; // Avança para o próximo nó antes do delete
        delete aux;  // Liberta a memória do nó
    }
}

// Insere no início atualizando o encadeamento duplo e o descritor 'prim' | Complexidade: O(1)
void ListaDupla::insereInicio(Elemento* e) {
    No* novo = new No;
    novo->info = e;
    novo->ant = NULL;  // Novo primeiro nó não possui predecessor
    novo->prox = prim; // O antigo primeiro passa a ser o sucessor
    
    // Ajusta o ponteiro anterior da antiga cabeça ou atualiza 'ult' se a lista estava vazia
    if(prim != NULL) prim->ant = novo;
    else ult = novo;
    
    prim = novo; // Atualiza o descritor de início
}

// Insere no fim utilizando o descritor 'ult' sem percorrer a lista | Complexidade: O(1)
void ListaDupla::insereFim(Elemento* e) {
    No* novo = new No;
    novo->info = e;
    novo->prox = NULL; // Novo último nó não possui sucessor
    novo->ant = ult;   // O antigo último passa a ser o predecessor
    
    // Encadeia após a antiga cauda ou atualiza 'prim' se a lista estava vazia
    if(ult != NULL) ult->prox = novo;
    else prim = novo;
    
    ult = novo; // Atualiza o descritor de fim
}

// Remove o primeiro nó e retorna o elemento armazenado | Complexidade: O(1)
Elemento* ListaDupla::removeInicio() {
    if(!prim) return NULL; // Subfluxo: lista vazia (underflow)
    
    No* p = prim;          // Nó a ser removido
    Elemento* ret = p->info;
    prim = prim->prox;     // Avança o descritor de início
    
    // Aterra o ponteiro 'ant' da nova cabeça ou 'ult' caso a lista tenha ficado vazia
    if(prim) prim->ant = NULL;
    else ult = NULL;
    
    delete p;              // Desaloca o nó removido
    return ret;
}

// Remove o último nó diretamente via ponteiro 'ant' e retorna o elemento | Complexidade: O(1)
Elemento* ListaDupla::removeFim() {
    if(!ult) return NULL;  // Subfluxo: lista vazia (underflow)
    
    No* p = ult;           // Nó a ser removido
    Elemento* ret = p->info;
    ult = ult->ant;        // Retrocede o descritor de fim em O(1)
    
    // Aterra o ponteiro 'prox' da nova cauda ou 'prim' caso a lista tenha ficado vazia
    if(ult) ult->prox = NULL;
    else prim = NULL;
    
    delete p;              // Desaloca o nó removido
    return ret;
}

// Busca linear por chave (ID) e remoção com reencadeamento duplo | Complexidade: O(n)
bool ListaDupla::remove(int id) {
    No* p = prim;
    
    // Percorre a lista até localizar o ID ou atingir o final
    while(p && p->info->getID() != id) p = p->prox;
    if(!p) return false; // Elemento não encontrado

    // Casos de borda: reaproveita os métodos O(1) se o alvo estiver nas extremidades
    if(p == prim) { removeInicio(); return true; }
    if(p == ult) { removeFim(); return true; }

    // Caso geral (nó intermediário): costura os ponteiros do predecessor e do sucessor entre si
    p->ant->prox = p->prox;
    p->prox->ant = p->ant;
    
    delete p; // Liberta o nó da memória
    return true;
}

// Busca sequencial por chave (ID) | Complexidade: O(n)
Elemento* ListaDupla::busca(int id) {
    No* p = prim;
    while(p) {
        if(p->info->getID() == id) return p->info; // Retorna o elemento se a chave coincidir
        p = p->prox;
    }
    return NULL; // Chave não encontrada
}

// Percurso linear para exibição dos elementos | Complexidade: O(n)
void ListaDupla::imprime() {
    for(No* p = prim; p != NULL; p = p->prox)
        p->info->imprimirInfo(); // Delega a impressão ao método do objeto
}