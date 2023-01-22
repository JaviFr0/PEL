#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

//Escribir un programa que utilice una Pila para comprobar si una determinada
//frase/palabra es un palíndromo. Nota: Una palabra o frase es palíndromo cuando la
//lectura directa e inversa es la misma y tiene igual valor

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    // Pide al usuario que ingrese una frase
    cout << "Ingresa una frase: ";
    string frase;
    getline(cin, frase);

    // Crea una pila y agrega cada carácter de la frase a la pila
    stack<char> *pila= new stack<char>();
    for (int i = 0; i < frase.length(); i++) {
        pila->push(frase[i]);
    }

    // Verifica si la frase es un palíndromo comparando cada carácter de la frase con el inverso de la pila
    bool esPalindromo = true;
    for (int i = 0; i < frase.length(); i++) {
        if (frase[i] != pila->top()) {
            esPalindromo = false;
            break;
        }
        pila->pop();
    }

    // Imprime el resultado
    if (esPalindromo) {
        cout << "La frase es un palíndromo." << endl;
    } else {
        cout << "La frase no es un palíndromo." << endl;
    }

    return 0;
}