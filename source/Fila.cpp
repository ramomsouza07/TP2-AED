#include "Fila.h"
 
Fila::Fila(int capacidade) : lista(capacidade) {
}
 
bool Fila::enfileirar(Elemento* e) {
    return lista.InserirNoFinal(e);
}
 
bool Fila::desenfileirar() {
    return lista.RemoverPrimeiro();
}
 
Elemento* Fila::consultarInicio() const {
    return lista.ConsultarPrimeiro();
}
 
bool Fila::filaCheia() const {
    return lista.Cheia();
}
 
bool Fila::filaVazia() const {
    return lista.Vazia();
};