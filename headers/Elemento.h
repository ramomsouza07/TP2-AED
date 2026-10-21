#ifndef ELEMENTO_H
#define ELEMENTO_H

// [POO - Abstracao]: classe base abstrata pros elementos do sistema
class Elemento {
protected:
    long ID; // [POO - Encapsulamento]: protegido para ser acessado pelas classes filhas

public:
    Elemento(long id);
    virtual ~Elemento() = default; // destrutor virtual para liberar as classes filhas corretamente

    long getID() const;
    virtual void imprimirInfo() const = 0; // metodo virtual puro (= 0) que obriga as filhas a implementarem
};

#endif