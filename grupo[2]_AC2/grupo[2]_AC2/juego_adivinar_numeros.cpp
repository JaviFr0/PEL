#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;
void limpiar_pantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
int main() {
    int numero;
    int n=100;
    int a;
    int intentos = 0;
    srand(time(NULL));
    numero = 1 + rand() % (100 - 1 + 1);
    cout << "Bienvenidos al juego de adivinar numero"<<" Escriba un numero del 1 al 100:  " << endl;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a>=1 && a<=100)
        {

            if (numero>a){
                intentos++;
                cout<<"El numero introducido es menor, intentalo de nuevo. "<<endl;
            }else if(numero<a){
                intentos++;
                cout<<"El numero introducido es mayor, intenalo de nuevo."<<endl;
            }else{
                intentos++;
                cout<<"Enhorabuena has adivinado el numero en : "<<intentos<<" intentos."<<endl;
                n = -1;
            }

        }
        else{
            cout<<"Has introducido un valor incorrecto, vuelve a empezar"<<endl;
            cout<<"Introduzca cualquier letra para poder finalizar el programa."<<endl;
            getche();
            limpiar_pantalla();
            exit(-1);
        }

    }
    getchar();
    return 0;
}