#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node {
public:
    Node() {
        data = 0;
        next = NULL;

    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    int getData() {
        return data;
    }
    void setData(int data) {
        this->data = data;
    }
    Node* getNext() {
        return next;
    }
    void setNext(Node* next) {
        this->next = next;
    }
    int data;
    Node* next;


};

// Función para insertar un nuevo elemento en el centro de la lista
void insertAtCenter(Node** head, int data) {
    Node* newNode = new Node;
    newNode->data = data;

    // Caso especial: si la lista está vacía, el nuevo nodo será el primero y último
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    // Encontramos el nodo del centro de la lista
    Node* p = *head;
    int count = 1;
    while (p->next != *head) {
        p = p->next;
        count++;
    }
    // p apunta al último nodo de la lista
    // count es el número de elementos de la lista

    // Insertamos el nuevo nodo en el centro de la lista
    newNode->next = p->next;
    p->next = newNode;
    if (count % 2 == 0) {
        // Si la lista tiene un número par de elementos, el nuevo nodo será el primero de los que están en el centro
        *head = newNode;
    }
}

// Función para recorrer la lista y mostrar sólo los números impares
void showOddNumbers(Node* head) {
    if (head == NULL) return;

    Node* p = head;
    do {
        if (p->data % 2 != 0) {
            cout << p->data << " ";
        }
        p = p->next;
    } while (p != head);
}

int main() {
    Node* head = NULL;

    // Insertamos elementos aleatorios en la lista hasta que el usuario introduzca -1
    int n;
    srand(time(NULL)); // Inicializamos la semilla para los números aleatorios
    do {
        cout << "Introduce un número (introduce -1 para terminar): ";
        cin >> n;
        if (n != -1) {
            insertAtCenter(&head, n);
        }
    } while (n != -1);

    // Mostramos sólo los números impares de la lista
    showOddNumbers(head);

    return 0;
}
