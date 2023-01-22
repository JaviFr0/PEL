/* En el palacio de Buckingham se ha colado el malo de Skyfall y ha borrado los datos de
la tesoreria de la reina. El hijo, dosgustado, ha pedido a su mejor
agente que recupere los datos. Para ello, 007 ha contactado con nosotros para que preparemos
un software que recupere los datos. Este software debe almacenar
lso datos de la base del malo en estructuras enlazadas de tipo FIFO. James Bond recuperara esos
datos y lso alamacenara en estructuras estáticas manteniendo
el tamaño original de la estructura enlazada. Una vez recuperado este dato se devolvera a la
estructura de al reina, Para introducirlos en el servidor de la
debera usarse el metodo pushback. Una vez recuperados los datos y devueltos al servidor,
007 tendra qu hacer una busqueda en dicha estructura de forma
que recupere la informacion de la direccion del sobrino de la reina. La estructra de estos datos
 son el nombre de la persona, direccion y un identificador
del dato. Como medida restrictiva y para vuestro proximo proyecto teneis prohibido el uso de bucles.
 (no es obligatorio lo de los bucles)
*/
#include <queue>
#include <vector>
#include <string>
 using namespace std;
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

