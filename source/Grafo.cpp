#include "../headers/Grafo.h"

// Construtor: inicializa simultaneamente a Lista de Adjacencia e a Matriz de Adjacencia
// Complexidade: O(capacidadeMatriz^2)
Grafo::Grafo(bool ehDirecionado, int capInicial) {
    primeiro = NULL;
    numVertices = 0;
    direcionado = ehDirecionado;
    capacidadeMatriz = (capInicial > 0) ? capInicial : 100;

    // Alocacao dinamica da matriz de adjacencia e vetor de mapeamento de IDs
    idsMatriz = new long[capacidadeMatriz];
    matrizAdj = new int*[capacidadeMatriz];
    for (int i = 0; i < capacidadeMatriz; i++) {
        matrizAdj[i] = new int[capacidadeMatriz];
        for (int j = 0; j < capacidadeMatriz; j++) {
            matrizAdj[i][j] = 0; // 0 indica ausencia de aresta
        }
        idsMatriz[i] = 0;
    }
}

// Destrutor: libera toda a memoria alocada para as duas representacoes
// Complexidade: O(V^2 + E)
Grafo::~Grafo() {
    destroiGrafo();
}

// Desaloca memoria da lista encadeada (vertices e arestas) e da matriz de adjacencia
// Complexidade: O(V^2 + E)
void Grafo::destroiGrafo() {
    // 1. Libera memoria da Lista de Adjacencia
    Vertice* v = primeiro;
    while (v != NULL) {
        Vertice* proxV = v->prox;
        liberaArestas(v->primeiraAresta);
        if (v->info != NULL) {
            delete v->info; // Libera o Elemento polimorfico
        }
        delete v;
        v = proxV;
    }
    primeiro = NULL;

    // 2. Libera memoria da Matriz de Adjacencia
    if (matrizAdj != NULL) {
        for (int i = 0; i < capacidadeMatriz; i++) {
            delete[] matrizAdj[i];
        }
        delete[] matrizAdj;
        matrizAdj = NULL;
    }

    if (idsMatriz != NULL) {
        delete[] idsMatriz;
        idsMatriz = NULL;
    }

    numVertices = 0;
    capacidadeMatriz = 0;
}

// Libera iterativamente a lista encadeada de arestas de um vertice
// Complexidade: O(grau(v)) <= O(V)
void Grafo::liberaArestas(Aresta* a) {
    while (a != NULL) {
        Aresta* temp = a->prox;
        delete a;
        a = temp;
    }
}

// Localiza um vertice na lista encadeada pelo seu identificador unico
// Complexidade: O(V)
Grafo::Vertice* Grafo::encontraVertice(long id) const {
    Vertice* atual = primeiro;
    while (atual != NULL) {
        if (atual->info != NULL && atual->info->getID() == id) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

// Retorna o indice de linha/coluna correspondente a um ID na matriz de adjacencia
// Complexidade: O(V)
int Grafo::indiceVertice(long id) const {
    for (int i = 0; i < numVertices; i++) {
        if (idsMatriz[i] == id) {
            return i;
        }
    }
    return -1;
}

// Redimensiona dinamicamente a matriz e o vetor de IDs duplicando a capacidade
// Complexidade: O(V^2)
void Grafo::redimensionaMatriz() {
    int novaCap = capacidadeMatriz * 2;
    int** novaMatriz = new int*[novaCap];
    for (int i = 0; i < novaCap; i++) {
        novaMatriz[i] = new int[novaCap];
        for (int j = 0; j < novaCap; j++) {
            novaMatriz[i][j] = 0;
        }
    }

    // Copia os dados da matriz anterior
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            novaMatriz[i][j] = matrizAdj[i][j];
        }
    }

    // Copia o vetor de mapeamento de IDs
    long* novosIds = new long[novaCap];
    for (int i = 0; i < numVertices; i++) {
        novosIds[i] = idsMatriz[i];
    }
    for (int i = numVertices; i < novaCap; i++) {
        novosIds[i] = 0;
    }

    // Libera a memoria antiga
    for (int i = 0; i < capacidadeMatriz; i++) {
        delete[] matrizAdj[i];
    }
    delete[] matrizAdj;
    delete[] idsMatriz;

    matrizAdj = novaMatriz;
    idsMatriz = novosIds;
    capacidadeMatriz = novaCap;
}

// Insere um novo vertice sincronizando a Lista e a Matriz de Adjacencia
// Complexidade: O(V) amortizado
bool Grafo::insereVertice(Elemento* e) {
    if (e == NULL) {
        return false;
    }

    // Impede a insercao de IDs duplicados
    if (encontraVertice(e->getID()) != NULL) {
        return false;
    }

    // Se a matriz estiver cheia, expande dinamicamente sua capacidade
    if (numVertices >= capacidadeMatriz) {
        redimensionaMatriz();
    }

    // 1. Insercao na Lista Encadeada de Vertices
    Vertice* novo = new Vertice(e, primeiro);
    primeiro = novo;

    // 2. Insercao e inicializacao na Matriz de Adjacencia
    int idx = numVertices;
    idsMatriz[idx] = e->getID();
    for (int i = 0; i <= idx; i++) {
        matrizAdj[idx][i] = 0;
        matrizAdj[i][idx] = 0;
    }

    numVertices++;
    return true;
}

// Insere uma aresta direcionada no inicio da lista de adjacencia
// Complexidade: O(1)
void Grafo::insereArestaDirecionadaLista(Vertice* vOrigem, long idDestino, int peso) {
    Aresta* nova = new Aresta(idDestino, peso, vOrigem->primeiraAresta);
    vOrigem->primeiraAresta = nova;
}

// Insere uma aresta sincronizando Lista de Adjacencia e Matriz de Adjacencia
// Complexidade: O(V)
bool Grafo::insereAresta(long idOrigem, long idDestino, int peso) {
    Vertice* vOrig = encontraVertice(idOrigem);
    Vertice* vDest = encontraVertice(idDestino);

    // Ambos os vertices devem existir
    if (vOrig == NULL || vDest == NULL) {
        return false;
    }

    // Verifica se a conexao ja existe
    if (existeAresta(idOrigem, idDestino)) {
        return false;
    }

    // 1. Sincroniza Lista de Adjacencia
    insereArestaDirecionadaLista(vOrig, idDestino, peso);
    if (!direcionado && idOrigem != idDestino) {
        insereArestaDirecionadaLista(vDest, idOrigem, peso);
    }

    // 2. Sincroniza Matriz de Adjacencia
    int idxOrig = indiceVertice(idOrigem);
    int idxDest = indiceVertice(idDestino);
    if (idxOrig != -1 && idxDest != -1) {
        matrizAdj[idxOrig][idxDest] = peso;
        if (!direcionado) {
            matrizAdj[idxDest][idxOrig] = peso;
        }
    }

    return true;
}

// Remove aresta direcionada internamente na lista encadeada
// Complexidade: O(grau(v)) <= O(V)
bool Grafo::removeArestaDirecionadaLista(Vertice* vOrigem, long idDestino) {
    Aresta* ant = NULL;
    Aresta* atual = vOrigem->primeiraAresta;

    while (atual != NULL && atual->idDestino != idDestino) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        return false;
    }

    if (ant == NULL) {
        vOrigem->primeiraAresta = atual->prox;
    } else {
        ant->prox = atual->prox;
    }

    delete atual;
    return true;
}

// Remove uma aresta sincronizando Lista de Adjacencia e Matriz de Adjacencia
// Complexidade: O(V)
bool Grafo::removeAresta(long idOrigem, long idDestino) {
    Vertice* vOrig = encontraVertice(idOrigem);
    Vertice* vDest = encontraVertice(idDestino);

    if (vOrig == NULL || vDest == NULL) {
        return false;
    }

    // 1. Sincroniza Lista de Adjacencia
    bool remOrig = removeArestaDirecionadaLista(vOrig, idDestino);
    bool remDest = true;
    if (!direcionado && idOrigem != idDestino) {
        remDest = removeArestaDirecionadaLista(vDest, idOrigem);
    }

    // 2. Sincroniza Matriz de Adjacencia
    int idxOrig = indiceVertice(idOrigem);
    int idxDest = indiceVertice(idDestino);
    if (idxOrig != -1 && idxDest != -1) {
        matrizAdj[idxOrig][idxDest] = 0;
        if (!direcionado) {
            matrizAdj[idxDest][idxOrig] = 0;
        }
    }

    return remOrig || remDest;
}

// Remove um vertice e reorganiza simultaneamente a Lista e a Matriz de Adjacencia
// Complexidade: O(V^2)
bool Grafo::removeVertice(long id) {
    Vertice* vAlvo = encontraVertice(id);
    if (vAlvo == NULL) {
        return false;
    }

    int idxAlvo = indiceVertice(id);

    // 1. Sincronizacao da Lista de Adjacencia
    // Remove qualquer aresta direcionada para o vertice alvo em outros vertices
    Vertice* atualV = primeiro;
    while (atualV != NULL) {
        if (atualV != vAlvo) {
            removeArestaDirecionadaLista(atualV, id);
        }
        atualV = atualV->prox;
    }

    // Libera todas as arestas que saem do vertice alvo
    liberaArestas(vAlvo->primeiraAresta);
    vAlvo->primeiraAresta = NULL;

    // Desconecta o vertice da lista principal
    Vertice* antV = NULL;
    atualV = primeiro;
    while (atualV != NULL && atualV != vAlvo) {
        antV = atualV;
        atualV = atualV->prox;
    }

    if (antV == NULL) {
        primeiro = atualV->prox;
    } else {
        antV->prox = atualV->prox;
    }

    if (vAlvo->info != NULL) {
        delete vAlvo->info;
    }
    delete vAlvo;

    // 2. Sincronizacao da Matriz de Adjacencia
    // Desloca linhas e colunas para reorganizar a matriz eliminando idxAlvo
    if (idxAlvo != -1) {
        // Desloca linhas para cima
        for (int r = idxAlvo; r < numVertices - 1; r++) {
            idsMatriz[r] = idsMatriz[r + 1];
            for (int c = 0; c < numVertices; c++) {
                matrizAdj[r][c] = matrizAdj[r + 1][c];
            }
        }
        // Desloca colunas para a esquerda
        for (int c = idxAlvo; c < numVertices - 1; c++) {
            for (int r = 0; r < numVertices - 1; r++) {
                matrizAdj[r][c] = matrizAdj[r][c + 1];
            }
        }
        // Zera a ultima linha e coluna que ficaram vagas
        for (int c = 0; c < numVertices; c++) {
            matrizAdj[numVertices - 1][c] = 0;
            matrizAdj[c][numVertices - 1] = 0;
        }
        idsMatriz[numVertices - 1] = 0;
    }

    numVertices--;
    return true;
}

// Retorna o ponteiro para o elemento armazenado no vertice
// Complexidade: O(V)
Elemento* Grafo::buscaVertice(long id) const {
    Vertice* v = encontraVertice(id);
    if (v != NULL) {
        return v->info;
    }
    return NULL;
}

// Verifica existencia de aresta consultando a Matriz de Adjacencia em O(1) apos indices
// Complexidade: O(V)
bool Grafo::existeAresta(long idOrigem, long idDestino) const {
    return saoVizinhos(idOrigem, idDestino);
}

// Verifica se dois vertices sao vizinhos consultando diretamente a matriz
// Complexidade: O(V)
bool Grafo::saoVizinhos(long id1, long id2) const {
    int idx1 = indiceVertice(id1);
    int idx2 = indiceVertice(id2);

    if (idx1 == -1 || idx2 == -1) {
        return false;
    }

    return matrizAdj[idx1][idx2] != 0;
}

// Retorna o grau de um vertice (-1 se nao existir)
// Complexidade: O(V)
int Grafo::obterGrau(long id) const {
    Vertice* v = encontraVertice(id);
    if (v == NULL) {
        return -1;
    }

    int grau = 0;
    Aresta* a = v->primeiraAresta;
    while (a != NULL) {
        grau++;
        a = a->prox;
    }
    return grau;
}

// Retorna a quantidade de vertices cadastrados
// Complexidade: O(1)
int Grafo::getNumVertices() const {
    return numVertices;
}

// Retorna verdadeiro caso o grafo nao possua nenhum vertice
// Complexidade: O(1)
bool Grafo::estaVazio() const {
    return primeiro == NULL;
}

// Exibe simultaneamente a Lista de Adjacencia e a Matriz de Adjacencia formatada
// Complexidade: O(V^2)
void Grafo::imprimeGrafo() const {
    if (primeiro == NULL || numVertices == 0) {
        cout << "\nO grafo esta vazio (nenhum vertice cadastrado)." << endl;
        return;
    }

    cout << "\n================ CONTEUDO DO GRAFO ================" << endl;
    cout << "Total de Vertices: " << numVertices 
         << " | Modo: " << (direcionado ? "Direcionado (Digrafo)" : "Nao-Direcionado") << endl;
    cout << "---------------------------------------------------" << endl;

    // 1. Exibicao da Lista de Adjacencia Encadeada
    cout << "\n>>> 1. REPRESENTACAO POR LISTA DE ADJACENCIA <<<" << endl;
    Vertice* v = primeiro;
    while (v != NULL) {
        cout << "Vertice: ";
        v->info->imprimirInfo();

        cout << "  Conexoes (Arestas):" << endl;
        Aresta* a = v->primeiraAresta;
        if (a == NULL) {
            cout << "    (Nenhuma conexao - vertice isolado)" << endl;
        } else {
            while (a != NULL) {
                cout << "    -> Conectado ao ID: " << a->idDestino << " [Peso/Afinidade: " << a->peso << "]";
                Vertice* dest = encontraVertice(a->idDestino);
                if (dest != NULL && dest->info != NULL) {
                    cout << " - ";
                    dest->info->imprimirInfo();
                } else {
                    cout << endl;
                }
                a = a->prox;
            }
        }
        cout << "---------------------------------------------------" << endl;
        v = v->prox;
    }

    // 2. Exibicao da Matriz de Adjacencia Formatada
    cout << "\n>>> 2. REPRESENTACAO POR MATRIZ DE ADJACENCIA <<<" << endl;
    cout << "ID Vertice\t";
    for (int j = 0; j < numVertices; j++) {
        cout << "[" << idsMatriz[j] << "]\t";
    }
    cout << endl;

    for (int i = 0; i < numVertices; i++) {
        cout << "[" << idsMatriz[i] << "]\t\t";
        for (int j = 0; j < numVertices; j++) {
            cout << matrizAdj[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "===================================================" << endl;
}

// Imprime os vizinhos imediatos de um vertice
// Complexidade: O(V + grau(v))
void Grafo::imprimeVizinhos(long id) const {
    Vertice* v = encontraVertice(id);
    if (v == NULL) {
        cout << "Vertice com ID " << id << " nao encontrado no grafo." << endl;
        return;
    }

    cout << "\n--- Vertice Selecionado ---" << endl;
    v->info->imprimirInfo();
    cout << "--- Conexoes Diretas (Vizinhos) ---" << endl;

    Aresta* a = v->primeiraAresta;
    if (a == NULL) {
        cout << "Nenhum vizinho conectado." << endl;
    } else {
        while (a != NULL) {
            cout << "-> Conexao com ID " << a->idDestino << " [Peso: " << a->peso << "]: ";
            Vertice* dest = encontraVertice(a->idDestino);
            if (dest != NULL && dest->info != NULL) {
                dest->info->imprimirInfo();
            } else {
                cout << "[Info indisponivel]" << endl;
            }
            a = a->prox;
        }
    }
    cout << "-----------------------------------" << endl;
}

// Verifica se um vertice ja consta no vetor de visitados
// Complexidade: O(V)
bool Grafo::jaVisitado(long id, const long* visitados, int totalVisitados) const {
    for (int i = 0; i < totalVisitados; i++) {
        if (visitados[i] == id) {
            return true;
        }
    }
    return false;
}

// Algoritmo de Busca em Largura (BFS - Breadth-First Search) utilizando fila dinamica
// Complexidade: O(V + E)
void Grafo::buscaEmLargura(long idInicio) const {
    Vertice* vInicio = encontraVertice(idInicio);
    if (vInicio == NULL) {
        cout << "Vertice inicial com ID " << idInicio << " nao encontrado." << endl;
        return;
    }

    if (numVertices == 0) return;

    long* visitados = new long[numVertices];
    int totalVisitados = 0;

    Vertice** fila = new Vertice*[numVertices];
    int iniFila = 0;
    int fimFila = 0;

    fila[fimFila++] = vInicio;
    visitados[totalVisitados++] = idInicio;

    cout << "\n--- Percurso em Largura (BFS) a partir do ID " << idInicio << " ---" << endl;
    int ordem = 1;

    while (iniFila < fimFila) {
        Vertice* atual = fila[iniFila++];
        cout << ordem++ << "o visitado: ";
        atual->info->imprimirInfo();

        Aresta* a = atual->primeiraAresta;
        while (a != NULL) {
            if (!jaVisitado(a->idDestino, visitados, totalVisitados)) {
                Vertice* vDest = encontraVertice(a->idDestino);
                if (vDest != NULL) {
                    visitados[totalVisitados++] = a->idDestino;
                    fila[fimFila++] = vDest;
                }
            }
            a = a->prox;
        }
    }

    delete[] visitados;
    delete[] fila;
}

// Algoritmo de Busca em Profundidade (DFS - Depth-First Search)
// Complexidade: O(V + E)
void Grafo::buscaEmProfundidade(long idInicio) const {
    Vertice* vInicio = encontraVertice(idInicio);
    if (vInicio == NULL) {
        cout << "Vertice inicial com ID " << idInicio << " nao encontrado." << endl;
        return;
    }

    if (numVertices == 0) return;

    long* visitados = new long[numVertices];
    int totalVisitados = 0;

    cout << "\n--- Percurso em Profundidade (DFS) a partir do ID " << idInicio << " ---" << endl;
    dfsRec(vInicio, visitados, totalVisitados);

    delete[] visitados;
}

// Metodo recursivo auxiliar para a busca em profundidade (DFS)
// Complexidade: O(V + E)
void Grafo::dfsRec(Vertice* vAtual, long* visitados, int& totalVisitados) const {
    visitados[totalVisitados++] = vAtual->info->getID();
    cout << totalVisitados << "o visitado: ";
    vAtual->info->imprimirInfo();

    Aresta* a = vAtual->primeiraAresta;
    while (a != NULL) {
        if (!jaVisitado(a->idDestino, visitados, totalVisitados)) {
            Vertice* vDest = encontraVertice(a->idDestino);
            if (vDest != NULL) {
                dfsRec(vDest, visitados, totalVisitados);
            }
        }
        a = a->prox;
    }
}
