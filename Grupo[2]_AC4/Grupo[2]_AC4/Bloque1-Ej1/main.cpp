#include <iostream>
#include "ColaGen.h"
#include "ListaGen.h"
#include "PilaGen.h"


//Enunciado 1
//Declara una clase “punto” que represente un punto dentro de un plano
//(coordenadas x e y), y genera una clase Nodo cuyo campo de valor sea
//“punto”
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
