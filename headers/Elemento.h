#ifndef ELEMENTO_H
#define ELEMENTO_H

// classe base pros elementos
class Elemento {
protected:
    long ID;

public:
    Elemento(long id);
    virtual ~Elemento() = default;

    long getID() const;
    virtual void imprimirInfo() const = 0;
};

#endif