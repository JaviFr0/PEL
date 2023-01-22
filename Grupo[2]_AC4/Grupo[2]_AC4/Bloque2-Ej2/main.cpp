#include <iostream>
#include <stack>

template <typename T>
void copiarPila(std::stack<T> &fuente, std::stack<T> &destino) {
    // Crear una pila auxiliar
    std::stack<T> auxiliar;

    // Mientras la pila fuente no esté vacía
    while (!fuente.empty()) {
       
        T elemento = fuente.top();

        auxiliar.push(elemento);

        fuente.pop();
    }

    // Mientras la pila auxiliar no esté vacía
    while (!auxiliar.empty()) {

        T elemento = auxiliar.top();

        destino.push(elemento);

        fuente.push(elemento);

        auxiliar.pop();
    }
}
