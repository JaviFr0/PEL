#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    // Pedir al usuario que introduzca una frase
    cout << "Introduce una frase: ";
    string phrase;
    getline(cin, phrase);

    // Eliminar espacios y poner todos los caracteres en minúsculas
    string cleanPhrase;
    for (int i = 0; i < phrase.size(); i++) {
        if (phrase[i] != ' ') {
            cleanPhrase += tolower(phrase[i]);
        }
    }

    // Crear una pila con los caracteres de la frase
    stack<char> s;
    for (int i = 0; i < cleanPhrase.size(); i++) {
        s.push(cleanPhrase[i]);
    }

    // Comprobar si la frase es un palíndromo
    bool isPalindrome = true;
    for (int i = 0; i < cleanPhrase.size(); i++) {
        if (s.top() != cleanPhrase[i]) {
            isPalindrome = false;
            break;
        }
        s.pop();
    }

    // Mostrar el resultado
    if (isPalindrome) {
        cout << "La frase es un palíndromo." << endl;
    } else {
        cout << "La frase NO es un palíndromo." << endl;
    }

    return 0;
}
