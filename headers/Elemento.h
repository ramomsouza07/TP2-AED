#ifndef ELEMENTO_H
#define ELEMENTO_H

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