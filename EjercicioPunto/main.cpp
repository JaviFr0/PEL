
#include <iostream>
using namespace std;

class Punto {
public:
    Punto(int x, int y) : x_(x), y_(y) {}
    int x() const { return x_; }
    int y() const { return y_; }

private:
    int x_;
    int y_;
};

class Nodo {
public:
    Nodo(const Punto& valor) : valor_(valor) {}
    const Punto& valor() const { return valor_; }

private:
    Punto valor_;
};
