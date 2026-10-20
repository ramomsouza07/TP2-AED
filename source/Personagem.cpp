#include "../headers/Personagem.h"
#include <iostream>

Personagem::Personagem(long id, std::string n, int nv) : Elemento(id) {
    nome = n;
    nivel = nv;
}

//mostra os dados do personagem
void Personagem::imprimirInfo() const {
    std::cout << "[Personagem] ID: " << getID() << " | Nome: " << nome << " | Nivel: " << nivel << std::endl;
}

std::string Personagem::getNome() const {
    return nome;
}

int Personagem::getNivel() const {
    return nivel;
}
