#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include "ListaGen.h"
//Enunciado 4
//Realiza un programa para crear una lista de números aleatorios. Los nuevos
//números deben insertarse en el centro de la lista (o el punto medio de los
//elementos de la misma). Una vez creada se ha de recorrer mostrando
//únicamente los números impares.
//Detalles:
//• Deben meterse los números aleatorios por el teclado del usuario.
//• Para terminar de crear la lista, se introducirá el valor reservado -1
using namespace std;

int main() {
    srand(time(NULL));

    list<int> *numbers = new list<int>;


    cout << "Introduce números aleatorios (-1 para terminar):" << endl;
    int number;
    cin >> number;
    while (number != -1) {
        // Insertar el número en el centro de la lista
        list<int>::iterator it = numbers->begin();
        for (int i = 0; i < numbers->size() / 2; i++) {
            it++;
        }
        numbers->insert(it, number);

        cin >> number;
    }

    // Mostrar números impares
    cout << "Números impares:" << endl;
    for (list<int>::iterator it = numbers->begin(); it != numbers->end(); it++) {
        if (*it % 2 != 0) {
            cout << *it << endl;
        }
    }

    return 0;
}