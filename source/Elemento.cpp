#include "../headers/Elemento.h"

// construtor guarda o id
Elemento::Elemento(long id) {
    ID = id;
}

long Elemento::getID() const {
    return ID;
}