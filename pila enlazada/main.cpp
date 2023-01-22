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
    menu:
    Stack stack;
    int option;
    int data;
    std::cout << "1. Push" << std::endl;
    std::cout << "2. Pop" << std::endl;
    std::cout << "3. Display" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Ingrese una opcion: ";
    std::cin >> option;
    switch (option) {
        case 1:
            std::cout << "Ingrese un numero: ";
            std::cin >> data;
            stack.push(data);
            goto menu;
        case 2:
            std::cout << "El numero eliminado es: " << stack.pop() << std::endl;
            goto menu;
        case 3:
            stack.display();
            goto menu;
        case 4:
            break;
        default:
            std::cout << "Opcion invalida" << std::endl;
            goto menu;
    }
    return 0;
}