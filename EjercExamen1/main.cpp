#include <iostream>
#include "cmake-build-debug/VectorPEL.h"
#include "cmake-build-debug/ColaPEL.h"

using namespace std;

/*
 * La empersa hp tiene un problema con sus servidores, todas sus base de datos son sql y quieren cambiarla a base de datos no sql para realizar la migracion de los datos
 * se ha decidio trasladar la informacion a traves de un contenedor y la informacion se agregara al contenedor mediante funciones push_back, posterioremente los datos
 * del vector de transmision se agragaran una base de datos no relaional con estructura enlazada funcionando como un fifo, una vez terminada la migracion de datos se mostraran
 * todos los datos en la nueva base de datos por consola la estructura fifo solo tiene los metodos de acceso por la parte superiora
 */
class Dato{
private:
    int id;
    int num;
public:
    Dato(){
        Dato::id = 0;
        Dato::num = 0;
    }
    Dato(int i, int n){
        Dato::id = i;
        Dato::num = n;
    }
    void imprimirInfo(){
        cout << "El id es: " << id << " y el numero es: " << num << endl;
    }
};


void imprimirCola(ColaPEL<Dato>* &l){
    ColaPEL<Dato>* l_aux = new ColaPEL<Dato>;
    while (!l->esVacia()){
        Dato aux = l->extraer();
        aux.imprimirInfo();
        l_aux->insertar(aux);
    }
    l = l_aux;
}


int main() {
    Dato* d1 = new Dato(1, 1);
    Dato* d2 = new Dato(2, 2);
    Dato* d3 = new Dato(3, 3);
    Dato* d4 = new Dato(4, 4);
    Dato* d5 = new Dato(5, 5);

    VectorPEL<Dato>* v = new VectorPEL<Dato>;
    v->push_back(*d1);
    v->push_back(*d2);
    v->push_back(*d3);
    v->push_back(*d4);
    v->push_back(*d5);

    ColaPEL<Dato>* l = new ColaPEL<Dato>;
    for (auto i = size_t{0}; i < v->size() ; ++i){
        Dato* aux = v->getPos(i);
        l->insertar(*aux);
    }
    delete v;
    imprimirCola(l);
    bool vacia = l->esVacia();
    if (vacia == true){
        cout << "No Funka"<<endl;
    }else{
        cout << "Ahora si Funka"<<endl;
    }
    //cout << l->esVacia() << endl;
    return 0;
}

