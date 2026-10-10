#include "../headers/Elemento.h"

Elemento::Elemento(long id) {
    ID = id;
}

long Elemento::getID() const {
    return ID;
}