#include <iostream>;
//Escibir un programa que la entrada estandar sea el precio de un producto y muestre en la salida 
//estándar el precio del producto al aplicarle el IVA
using namespace std;
 int main(){
    float precio,iva,preciofinal;
cout<< "¿Cual es el precio del producto sin IVA?"<<endl;
cin>>precio;
iva= precio*0,21;
preciofinal=iva+precio;
cout<<"El precio final es: "<< preciofinal<<endl;
 }

