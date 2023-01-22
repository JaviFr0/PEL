#include <iostream>
#include "ListaGen.h"
//Enunciado 3
//Utilizando la lista de números enteros desarrollada en el apartado anterior, inserta
//tres nuevos elementos. Uno en la cabeza, otro en la cola y otro entre dos nodos


using namespace std;
int main(){

    ListaGen<int>* num = new ListaGen<int>;

    num->insertar_cabeza(3);
    num->insertar_cabeza(1);
    num->insertar_cabeza(4);
    num->insertar_cabeza(6);
    num->insertar_cabeza(7);
    num->insertar_cola(8);
    num->recorrerLista();
    cout<<&num<<endl;



    return 0;
};




