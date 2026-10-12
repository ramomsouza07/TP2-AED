#ifndef FILACIRCULAR_H
#define FILACIRCULAR_H

#include "Elemento.h"

class FilaCircular {
private:
    Elemento** elemento;
    int capacidade;
    int inicio;    
    int tamanho;   

public:
    FilaCircular(int cap = 50);
    ~FilaCircular();

    bool enfileirar(Elemento* e);
    bool desenfileirar();
    Elemento* consultarInicio() const;
    bool filaCheia() const;
    bool filaVazia() const;
};

#endif