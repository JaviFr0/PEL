#include <iostream>
#include "ColaPEL.h"
#include "VectorPEL.h"
/*
 * En el palacio de Buckingham se ha colado el malo de Skyfall y ha borrado los datos de la tesoreria de la reina. El hijo, dosgustado, ha pedido a su mejor
agente que recupere los datos. Para ello, 007 ha contactado con nsootros para que preparemos un software que recupere los datos. Este software debe almacenar
lso datos de la base del malo en estructuras enlazadas de tipo FIFO. James Bond recuperara esos datos y lso alamacenara en estructuras estáticas manteniendo
 el tamaño original de la estructura enlazada. Una vez recuperado este dato se devolvera a la estructura de al reina, Para introducirlos en el servidor de la
debera usarse el metodo pushback. Una vez recuperados los datos y devueltos al servidor, 007 tendra qu hacer una busqueda en dicha estructura de forma
que recupere la informacion de la direccion del sobrino de la reina. La estructra de estos datos son el nombre de la persona, direccion y un identificador
del dato. Como medida restrictiva y para vuestro proximo proyecto teneis prohibido el uso de bucles. (no es obligatorio lo de los bucles)
 */
using namespace std;
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
};
void insertar(){
    ColaPEL<Dato>();
    VectorPEL<Dato> vector;
    Dato d1(1, 1);
    Dato d2(2, 2);
    Dato d3(3, 3);
    Dato d4(4, 4);
    Dato d5(5, 5);
}
void extraer(){
    ColaPEL<Dato> cola;
    VectorPEL<Dato> vector;
    Dato d1(1, 1);
    Dato d2(2, 2);
    Dato d3(3, 3);
    Dato d4(4, 4);
    Dato d5(5, 5);
}

int main() {
    insertar();
    extraer();
    return 0;
}
