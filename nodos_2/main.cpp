#include <iostream>
using namespace std;

template <typename T> class Nodo
{
private:
    T dato;
    Nodo<T>* enlace;

public:
    Nodo(T d)
    {
        Nodo::dato = d;
        Nodo::enlace = 0;
    }
public:
    Nodo(T p, Nodo<T>* n)
    {
        Nodo::dato = p;
        Nodo::enlace = n;
    }
    T datoNodo() const
    {
        return dato;
    }

    Nodo* enlaceNodo() const
    {
        return enlace;
    }

    void ponerEnlace(Nodo<T>* sgte)
    {
        enlace = sgte;
    }
};

template <typename T> void recorremeEsta(Nodo<T>* pseudoLista)
{
    bool existe_enlace = true;
    while(existe_enlace == true){
        cout << pseudoLista->datoNodo() << endl;

        if(pseudoLista->enlaceNodo() == NULL){
            existe_enlace = false;
        }else{
            pseudoLista = pseudoLista->enlaceNodo();
        }
    }
}

int main(int, char**)
{

    Nodo <int>* n1 = new  Nodo<int>(1);
    Nodo <int>* n2 = new  Nodo<int>(2);
    Nodo <int>* n3 = new Nodo <int> (3);


    n1->ponerEnlace(n2);
    n2->ponerEnlace(n3);

    recorremeEsta<int>(n1);

};