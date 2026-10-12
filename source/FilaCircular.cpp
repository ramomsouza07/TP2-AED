#include "FilaCircular.h"
 
FilaCircular::FilaCircular(int cap) {
    capacidade = cap;
    inicio = 0;
    tamanho = 0;
    elemento = new Elemento*[capacidade];
}
 
FilaCircular::~FilaCircular() {
    for (int i = 0; i < tamanho; i++) {
        int posicao = (inicio + i) % capacidade;
        delete elemento[posicao];
    }
    delete[] elemento;
}
 
bool FilaCircular::enfileirar(Elemento* e) {
    if (e == nullptr || filaCheia()) return false;
    int posicao = (inicio + tamanho) % capacidade;
    elemento[posicao] = e;
    tamanho++;
    return true;
}

bool FilaCircular::desenfileirar() {
    if (filaVazia()) return false;
    delete elemento[inicio];
    inicio = (inicio + 1) % capacidade;
    tamanho--;
    return true;
}
 
Elemento* FilaCircular::consultarInicio() const {
    if (filaVazia()) return nullptr;
    return elemento[inicio];
}
 
bool FilaCircular::filaCheia() const {
    return tamanho == capacidade;
}
 
bool FilaCircular::filaVazia() const {
    return tamanho == 0;
}
