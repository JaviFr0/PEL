#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
struct Node {
    int data;
    Node* next;
};

// Agrega un nodo al final de la lista
void append(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// Agrega un nodo al principio de la lista
void push(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Inserta un nodo entre dos nodos existentes
void insertAfter(Node* prevNode, int data) {
    if (prevNode == nullptr) {
        cout << "El nodo anterior no puede ser nulo" << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

int main() {
    Node* head = nullptr;

    // Agrega algunos nodos a la lista
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    // Agrega un nodo al principio de la lista
    push(head, 0);

    // Inserta un nodo entre dos nodos existentes
    Node* current = head;
    while (current->data != 3) {
        current = current->next;
    }
    insertAfter(current, 3.5);

    // Imprime la lista
    current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout <<"" << endl;

    return 0;
}


/*
using namespace std;

int main() {
    // Semilla para generar números aleatorios
    srand(time(NULL));

    list<int> numbers; // Lista de números

    // Pedir números aleatorios al usuario
    cout << "Introduce números aleatorios (-1 para terminar):" << endl;
    int number;
    cin >> number;
    while (number != -1) {
        // Insertar el número en el centro de la lista
        list<int>::iterator it = numbers.begin();
        for (int i = 0; i < numbers.size() / 2; i++) {
            it++;
        }
        numbers.insert(it, number);

        cin >> number;
    }

    // Mostrar números impares
    cout << "Números impares:" << endl;
    for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        if (*it % 2 != 0) {
            cout << *it << endl;
        }
    }

    return 0;
}
 */