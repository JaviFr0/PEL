#include <iostream>
#include "ListaGen.h"
using namespace std;
int main(){

    ListaGen<int>* num = new ListaGen<int>;

    num->insertar_cabeza(3);
    num->insertar_cabeza(1);
    num->insertar_cabeza(4);
    num->insertar_cabeza(6);
    num->insertar_cabeza(7);
    num->recorrerLista();
    cout<<&num<<endl;



    return 0;
};




