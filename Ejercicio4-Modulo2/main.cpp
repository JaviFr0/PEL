#include <iostream>
#include <stack>

using namespace std;

const int numPilas = 5; // Número de pilas

int main() {
    // Creamos un arreglo de pilas
    stack<int> pilas[numPilas];

    // Pedimos la entrada de datos
    int i, j;
    cout << "Ingresa pares de enteros (i, j), donde 1 <= abs(i) <= " << numPilas << " y j es el elemento a insertar o eliminar (0 para terminar):" << endl;
    cin >> i;
    while (i != 0) {
        cin >> j;

        // Si i es positivo, insertamos j en la pila i
        if (i > 0) {
            pilas[i - 1].push(j);
        }
            // Si i es negativo, eliminamos j elementos de la pila j
        else {
            for (int k = 0; k < abs(j); k++) {
                pilas[abs(i) - 1].pop();
            }
        }

        // Pedimos la siguiente entrada de datos
        cin >> i;
    }

    // Mostramos el contenido de las pilas
    cout << endl << "Contenido de las pilas:" << endl;
    for (int k = 0; k < numPilas; k++) {
        cout << "Pila " << k + 1 << ": ";
        while (!pilas[k].empty()) {
            cout << pilas[k].top() << " ";
            pilas[k].pop();
        }
        cout << endl;
    }

    return 0;
}


