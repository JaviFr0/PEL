#include <iostream>

// estructura para un nodo de la cola enlazada
struct Node {
    int data;
    Node* next;
};

// estructura para la cola enlazada
struct Queue {
    Node* front;
    Node* rear;
};

// función para crear una cola vacía
Queue* createQueue() {
    Queue* q = new Queue();
    q->front = q->rear = nullptr;
    return q;
}

// función para agregar un elemento a la cola
void enqueue(Queue* q, int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;
    if (q->rear == nullptr) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
void showQueue(Queue* q) {
    Node* temp = q->front;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
// función para eliminar un elemento de la cola
void dequeue(Queue* q) {
    if (q->front == nullptr) {
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == nullptr) {
        q->rear = nullptr;
    }
    delete temp;
}

int main() {
    Queue* q = createQueue();

    int choice;
    while (true) {
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Mostrar cola" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Ingrese su opcion: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                std::cout << "Ingrese el valor a agregar: ";
                std::cin >> data;
                enqueue(q, data);
                break;
            }
            case 2: {
                dequeue(q);
                break;
            }
            case 3: {
                // función para mostrar los datos de la cola
                showQueue(q);
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                std::cout << "Opcion invalida, intente de nuevo." << std::endl;
            }
        }
    }
    return 0;
}


