#include <iostream>
#include "PilaGen.h"
using namespace std;

int main() {
    PilaGen<int> *pilaI = new PilaGen<int>;
    PilaGen<int> *pilaJ = new PilaGen<int>;
    bool condicion = true;
    int opcionMenu , i , j;
    cout << " Ingrese un par de número enteros (i,j), " << endl;
    while ( condicion ){
        cout << "Opciones Menu: \n1. Añadir  números  \n2. Terminar programa" << endl;
        cin >> opcionMenu;
        switch ( opcionMenu ) {
            case 1:
            {
                cout << "Introduzca i: " << endl;
                cin >> i;
                pilaI->insertar_cabeza( i );
                cout << "Introduzca j: " << endl;
                cin >> j;
                pilaJ->insertar_cabeza( j );
                if ( i > 0 ){ //i es positivo
                    pilaI->insertar_cabeza( j );
                }else if ( i == 0 ){ //i igual menos q  cero
                    cout << "------------- PILA i -------------------" << endl;
                    int pilaIsize = pilaI->size();
                    for(int k = 0 ; k < pilaIsize; k++ ){
                        cout << pilaI->pop() << endl;
                    }
                    cout << "------------- PILA j -------------------" << endl;
                    int pilaJsize = pilaJ->size();
                    for(int m = 0 ; m < pilaJsize; m++ ){
                        cout << pilaJ->pop() << endl;
                    }
                    break;
                }else if( i < 0 ){ //i es 0
                    pilaJ->eliminar_cabeza();
                }
                break;
            }
            case 2:
            {
                condicion = false;
                break;
            }
            default :
            {
                cout << "ERROR, introduzca una opcion valida " << endl;
            }
        }
    }
    return 0;
}
