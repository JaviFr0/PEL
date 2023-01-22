#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() { top = nullptr; }

    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            std::cout << "La pila esta vacia" << std::endl;
            return -1;
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    void display() {
        Node* temp = top;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};
int main() {
    Stack* stack = new Stack();

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
                push(data);
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
