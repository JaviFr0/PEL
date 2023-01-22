#include <iostream>
#include <conio.h>
#include "minmax.h"
using namespace std;
//Crea una plantilla minmaxi, que declara dos plantillas de funciones, una para una función maxi, 
//que devuelve el valor más alto de los 2 parámetros entregados, y otra, una función min, que devuelve el valor más bajo.
int main(){ 
    
    cout<<"Dime el valor del primer número"<<endl;
int num_a;
    cin>>num_a;
    cout<<"Dime el valor del segundo número"<<endl;
int num_b;
    cin>>num_b;
    minmax(num_a, num_b);

getch();
};


