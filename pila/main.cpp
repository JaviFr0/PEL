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
    Stack stack;
    int choice;

    while (true) {
        std::cout << "1. Insertar elemento" << std::endl;
        std::cout << "2. Eliminar elemento" << std::endl;
        std::cout << "3. Mostrar elementos" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Ingrese su opcion: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                int value;
                std::cout << "Ingrese el valor a insertar: ";
                std::cin >> value;
                stack.push(value);
                break;
            case 2:
                std::cout << "Valor eliminado: " << stack.pop() << std::endl;
                break;
            case 3:
                stack.display();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Opcion no valida" << std::endl;
                break;
        }
    }
    return 0;
}
