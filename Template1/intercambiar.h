#include <iostream>
#include <conio.h>
using namespace std;
template<typename T> 
void intercambiar( T &n1, T &n2){
T aux;
aux=n1;
n1=n2;
n2=aux;
cout<<"El primer numero es "<<n1<<endl;
cout<<"El segundo numero es "<<n2<<endl;
};