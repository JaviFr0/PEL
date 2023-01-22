#include <iostream>
#include <queue>

using namespace std;

// Plantilla de la clase Cola (para poder utilizar cualquier tipo de dato)
template <typename T>
class Cola {
private:
    // La cola real se implementa con una queue de STL
    queue<T> q;

public:
    // Métodos del TAD Cola
    void encolar(T elem);
    void desencolar();
    T frente();
    bool vacia();
};

// Implementación de los métodos del TAD Cola
template <typename T>
void Cola<T>::encolar(T elem) {
    q.push(elem);
}

template <typename T>
void Cola<T>::desencolar() {
    q.pop();
}

template <typename T>
T Cola<T>::frente() {
    return q.front();
}

template <typename T>
bool Cola<T>::vacia() {
    return q.empty();
}

// Función que comprueba si dos colas son idénticas
template <typename T>
bool sonIdenticas(Cola<T> cola1, Cola<T> cola2) {
    // Mientras ambas colas no estén vacías
    while (!cola1.vacia() && !cola2.vacia()) {
        // Si el elemento del frente de ambas colas es distinto, las colas no son idénticas
        if (cola1.frente() != cola2.frente()) {
            return false;
        }

        // Desencolamos el elemento de ambas colas
        cola1.desencolar();
        cola2.desencolar();
    }

    // Si ambas colas están vacías, son idénticas
    return cola1.vacia() && cola2.vacia();
}

int main() {
    // Creamos dos colas y las llenamos con algunos elementos
    Cola<int> cola1;
    cola1.encolar(1);
    cola1.encolar(2);
    cola1.encolar(3);

    Cola<int> cola2;
    cola2.encolar(1);
    cola2.encolar(2);
    cola2.encolar(3);

    // Comprobamos si las colas son idénticas
    if (sonIdenticas(cola1, cola2)) {
        cout << "Las colas son idénticas" << endl;
    } else {
        cout << "Las colas NO son idénticas" << endl;
    }

    return 0;
}
