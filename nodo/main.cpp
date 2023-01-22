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
//Funciones de insercion de datos
template <typename T> void insercion_cabeza(Nodo<T>*&dato_nuevo,Nodo<T>* &pseudolista){
    dato_nuevo->enlaceNodo(pseudolista);
    pseudolista = dato_nuevo;
}
template<typename T> void insercion_cola(Nodo<T>*&dato_nuevo,Nodo<T>* &pseudolista){
    bool nodo_terminal = false;
    Nodo<T>*aux = pseudolista;
    while(nodo_terminal== false){
        if(aux-> enlaceNodo()== NULL){
            aux -> enlaceNodo(dato_nuevo);
            nodo_terminal = true;
        }else{
            aux = aux->enlaceNodo();
        }
    }
}

template<typename T>void insertar_posicion(Nodo<T>*&dato_nuevo,int pos,Nodo<T>* &pseudolista){
    int posicion = 0;
    bool salida = false;
    Nodo<T>*aux = pseudolista;
    while(salida == false){
        if (pos == posicion){
            dato_nuevo ->enlaceNodo(aux ->enlaceNodo());
            aux->enlazaNodo(dato_nuevo);
            salida =true;
        }else{
            if(aux->enlaceNodo()==NULL){
                salida = true;
            }else{
                ++posicion;
                aux = aux -> enlaceNodo();
            }
        }
    }
}

int main(int, char**)
{

    Nodo <int>* n1 = new Nodo<int>(1);
    Nodo <int>* n2 = new Nodo<int>(2);
    Nodo <int>* n3 = new Nodo<int>(3);


    n1->ponerEnlace(n2);
    n2->ponerEnlace(n3);

    Nodo<int>*pseudolista =n1;

    Nodo<int>* n4 = new Nodo<int>(0);
    recorremeEsta(pseudolista);
    cout<< " insertamos el nuevo nodo "<<endl;
  //  insercion_cabeza(n4, pseudolista);

    recorremeEsta(pseudolista);

    recorremeEsta<int>(n1);

};