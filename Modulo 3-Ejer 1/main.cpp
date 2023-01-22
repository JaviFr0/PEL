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

// Función que crea un clon de una cola
template <typename T>
Cola<T> clonarCola(Cola<T> cola) {
    // Creamos una nueva cola
    Cola<T> colaClon;

    // Mientras la cola original no esté vacía
    while (!cola.vacia()) {
        // Copiamos el elemento del frente de la cola original al clon
        T elem = cola.frente();
        colaClon.encolar(elem);

        // Desencolamos el elemento de la cola original
        cola.desencolar();
    }

    // Devolvemos el clon
    return colaClon;
}

int main() {
    // Creamos una cola y la llenamos con algunos elementos
    Cola<int> cola;
    cola.encolar(1);
    cola.encolar(2);
    cola.encolar(3);

    // Creamos un clon de la cola
    Cola<int> colaClon = clonarCola(cola);

    // Mostramos el contenido de la cola original y del clon
    cout << "Cola original: ";
    while (!cola.vacia()) {
        cout << cola.frente() << " ";
        cola.desencolar();
    }
    cout << endl;

    cout << "Cola clon: ";
    while (!colaClon.vacia()) {
        cout << colaClon.frente() << " ";
        colaClon.desencolar();
    }
    cout << endl;

    return 0;
}
