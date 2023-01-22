#include <iostream>
#include <conio.h>
using namespace std;
/*Generad una clase/objeto que tenga una alineación de 4 bytes. 
Para dicha estructura, configurad una serie de métodos para manejar sus datos (los que sean). 
Entre estos métodos deberéis configurar el constructor y el destructor del objeto. 
Adicionalmente, hay que generar un array en el freestore para almacenar la información de estos objetos (generar al menos 3 de estos objetos) 
y que se pueda acceder a la misma mediante un puntero. 
Al terminar la ejecución, un método (destructor) eliminará tanto el objeto alojado en memoria como el puntero que lo apunta.
**/
class Memoria{
    private:
    int objeto;//int objects has 4 bytes
   
    public:
    Memoria(int objeto1); //constructor
    ~Memoria();//destructor
};
//constructor
Memoria::Memoria(int objeto1){
objeto=objeto1;
};
//destructor
Memoria::~Memoria(){
};
int main(){
int * pnt_int_array = new int[3];//allocate array in the free store
unsigned int_remaining = 3;
int * p = pnt_int_array;
while ((int_remaining > 0) && (cin >> *p++))
{
  --int_remaining;
}
delete(p);
};