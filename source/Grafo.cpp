#include "../headers/Grafo.h"


Grafo::Grafo(bool ehDirecionado) {
    primeiro = NULL;
    numVertices = 0;
    direcionado = ehDirecionado;
}


Grafo::~Grafo() {
    destroiGrafo();
}


void Grafo::destroiGrafo() {
    Vertice* v = primeiro;
    while (v != NULL) {
        Vertice* proxV = v->prox;
        liberaArestas(v->primeiraAresta);
        if (v->info != NULL) {
            delete v->info; 
        }
        delete v;
        v = proxV;
    }
    primeiro = NULL;
    numVertices = 0;
}


void Grafo::liberaArestas(Aresta* a) {
    while (a != NULL) {
        Aresta* temp = a->prox;
        delete a;
        a = temp;
    }
}


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


bool Grafo::insereVertice(Elemento* e) {
    if (e == NULL) {
        return false;
    }


    if (encontraVertice(e->getID()) != NULL) {
        return false;
    }

    Vertice* novo = new Vertice();
    novo->info = e;
    novo->primeiraAresta = NULL;
    novo->prox = primeiro;
    primeiro = novo;
    numVertices++;

    return true;
}


void Grafo::insereArestaDirecionada(Vertice* vOrigem, long idDestino, int peso) {
    Aresta* nova = new Aresta();
    nova->idDestino = idDestino;
    nova->peso = peso;
    nova->prox = vOrigem->primeiraAresta;
    vOrigem->primeiraAresta = nova;
}


bool Grafo::insereAresta(long idOrigem, long idDestino, int peso) {
    Vertice* vOrig = encontraVertice(idOrigem);
    Vertice* vDest = encontraVertice(idDestino);


    if (vOrig == NULL || vDest == NULL) {
        return false;
    }


    if (existeAresta(idOrigem, idDestino)) {
        return false;
    }


    insereArestaDirecionada(vOrig, idDestino, peso);


    if (!direcionado && idOrigem != idDestino) {
        insereArestaDirecionada(vDest, idOrigem, peso);
    }

    return true;
}


bool Grafo::removeArestaDirecionada(Vertice* vOrigem, long idDestino) {
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


bool Grafo::removeAresta(long idOrigem, long idDestino) {
    Vertice* vOrig = encontraVertice(idOrigem);
    Vertice* vDest = encontraVertice(idDestino);

    if (vOrig == NULL || vDest == NULL) {
        return false;
    }

    bool remOrig = removeArestaDirecionada(vOrig, idDestino);
    bool remDest = true;

    if (!direcionado && idOrigem != idDestino) {
        remDest = removeArestaDirecionada(vDest, idOrigem);
    }

    return remOrig || remDest;
}


bool Grafo::removeVertice(long id) {
    Vertice* vAlvo = encontraVertice(id);
    if (vAlvo == NULL) {
        return false;
    }


    Vertice* atualV = primeiro;
    while (atualV != NULL) {
        if (atualV != vAlvo) {
            removeArestaDirecionada(atualV, id);
        }
        atualV = atualV->prox;
    }


    liberaArestas(vAlvo->primeiraAresta);
    vAlvo->primeiraAresta = NULL;


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

    numVertices--;
    return true;
}


Elemento* Grafo::buscaVertice(long id) const {
    Vertice* v = encontraVertice(id);
    if (v != NULL) {
        return v->info;
    }
    return NULL;
}


bool Grafo::existeAresta(long idOrigem, long idDestino) const {
    Vertice* vOrig = encontraVertice(idOrigem);
    if (vOrig == NULL) {
        return false;
    }

    Aresta* a = vOrig->primeiraAresta;
    while (a != NULL) {
        if (a->idDestino == idDestino) {
            return true;
        }
        a = a->prox;
    }
    return false;
}


int Grafo::getNumVertices() const {
    return numVertices;
}


bool Grafo::estaVazio() const {
    return primeiro == NULL;
}


void Grafo::imprimeGrafo() const {
    if (primeiro == NULL) {
        cout << "\nO grafo esta vazio (nenhum vertice cadastrado)." << endl;
        return;
    }

    cout << "\n================ CONTEUDO DO GRAFO ================" << endl;
    cout << "Total de Vertices: " << numVertices 
         << " | Modo: " << (direcionado ? "Direcionado (Digrafo)" : "Nao-Direcionado") << endl;
    cout << "---------------------------------------------------" << endl;

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
}


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


bool Grafo::jaVisitado(long id, const long* visitados, int totalVisitados) const {
    for (int i = 0; i < totalVisitados; i++) {
        if (visitados[i] == id) {
            return true;
        }
    }
    return false;
}


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

