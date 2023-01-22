#include <iostream>
#include <queue>
#include <vector>

// estructura para un nodo de la cola enlazada
struct Node {
    std::string name;
    std::string address;
    int id;
    Node* next;
};

// función para pasar los datos de la cola enlazada a la cola estática
void transferData(Node* front, std::vector<Node>& staticQueue) {
    Node* curr = front;
    while (curr != nullptr) {
        // agrega el elemento a la cola estática
        staticQueue.push_back(*curr);
        // avanza al siguiente elemento
        curr = curr->next;
    }
}

// función para buscar información en la estructura
std::string search(std::vector<Node>& staticQueue, std::string name) {
    for (auto& node : staticQueue) {
        if (node.name == name) {
            return node.address;
        }
    }
    return "No se encontró la información buscada";
}

int main() {
    // ejemplo de cola enlazada
    Node n1 = {"Alice", "123 Main St", 1};
    Node n2 = {"Bob", "456 Park Ave", 2};
    Node n3 = {"Charlie", "789 Elm St", 3};
    n1.next = &n2;
    n2.next = &n3;

    std::vector<Node> staticQueue;
    // llama a la función para pasar los datos de la cola enlazada a la cola estática
    transferData(&n1, staticQueue);

    // llama a la función para buscar información en la estructura
    std::cout << "Dirección de Bob: " << search(staticQueue, "Bob") << std::endl;

    return 0;
}