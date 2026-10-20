#include "../headers/Equipamento.h"
#include <iostream>

Equipamento::Equipamento(long id, std::string n, int dano) : Elemento(id) {
    nomeItem = n;
    danoBase = dano;
}

//imprime  infos do equipamento
void Equipamento::imprimirInfo() const {
    std::cout << "[Equipamento] ID: " << getID() << " | Item: " << nomeItem << " | Dano: " << danoBase << std::endl;
}

std::string Equipamento::getNomeItem() const {
    return nomeItem;
}

int Equipamento::getDanoBase() const {
    return danoBase;
}
