#include <iostream>
#include "Pila.h"
#include "PilaEstatica.h"
#include "Vector.h"
using namespace std;

class DatosReina{
    private:
        int id;
        string nombre;
        string direccion;
    public:
        DatosReina(){
            id = 0;
            nombre = "";
            direccion = "";
        }
        DatosReina(int id, string nombre, string direccion){
            DatosReina::id = id;
            DatosReina::nombre = nombre;
            DatosReina::direccion = direccion;
        }
        void imprimirInfo(){
            cout << "El id es: " << id << " de: " << nombre << " y su direccion es: " << direccion << endl;
        }
        ~DatosReina(){}
};




int main(int, char**) {
    DatosReina* r1 = new DatosReina(1, "Reina 1", "Calle 1");
    DatosReina* r2 = new DatosReina(2, "Sobrino 2", "Calle 2");
    DatosReina* r3 = new DatosReina(3, "Rey 3", "Calle 3");
    DatosReina* r4 = new DatosReina(4, "Principe 4", "Calle 4");
    DatosReina* r5 = new DatosReina(5, "Nieto 5", "Calle 5");

    Pila<DatosReina>* pilaDinamica = new Pila<DatosReina>();
    pilaDinamica->insertar(*r1);
    pilaDinamica->insertar(*r2);
    pilaDinamica->insertar(*r3);
    pilaDinamica->insertar(*r4);
    pilaDinamica->insertar(*r5);

    PilaEstatica<DatosReina>* pilaEstatica = new PilaEstatica<DatosReina>(pilaDinamica->size());
    while(!pilaDinamica->pilaVacia()){
        pilaEstatica->push(pilaDinamica->quitar());
    }

    delete pilaDinamica;

    Vector<DatosReina>* vector = new Vector<DatosReina>();
    while(!pilaEstatica->pilaVacia()){
        vector->push_back(pilaEstatica->pop());
    }
    delete pilaEstatica;

    cout << "Vector" << endl;
    for(int i = 0; i < vector->size(); i++){
        DatosReina *aux = vector->now(i);
        aux->imprimirInfo();
    }
    vector->~Vector();
    r1->~DatosReina();
    r2->~DatosReina();
    r3->~DatosReina();
    r4->~DatosReina();
    r5->~DatosReina();
    return 0;
}