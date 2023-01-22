#include "iostream"
using namespace std;
#ifndef LISTAENLAZADA_LINKED_LIST_H
#define LISTAENLAZADA_LINKED_LIST_H

template <typename T> class ListaGen {
protected:
    class  Nodo{
    public:
        T elemento;
        Nodo * siguiente;
        Nodo(T e){
            elemento = e;
            siguiente = 0;
        }
    };
    Nodo * primero;
public:
    ListaGen(){
        primero = 0;
    }
    void insertar_cabeza(T e){
        Nodo * nuevo = new Nodo(e);
        nuevo->siguiente = primero;
        primero = nuevo;
    }
    void insertar_cola(T e){
        Nodo * nuevo = new Nodo(e);
        bool existe_enlace = true;
        if (primero == NULL){
            nuevo->siguiente = primero;
            primero = nuevo;

        }else{
            Nodo* aux = primero;
            while (existe_enlace == true){
                if (aux->siguiente != NULL){
                    aux = aux->siguiente;
                } else {
                    aux->siguiente = nuevo;
                    existe_enlace = false;
                }

            }
        }
    }

    void insertar_pos(T e, int pos){
        if (pos > size()){
            std::cout << "no se puede insertar en esa posicion" << std::endl;
        } else {
            Nodo* aux = primero;
            for (int i = 0; i < pos; ++i) {
                aux = aux->siguiente;
            }
            Nodo * nuevo = Nodo(e);
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }

    bool es_vacia(){
        return primero == 0;
    }

    int size(){
        if (ListaGen::es_vacia()){
            return 0;
        }else {
            int contador = 0;
            bool existe_enlace = true;
            Nodo *aux = primero;
            while (existe_enlace == true) {
                if (aux->siguiente != 0) {
                    aux = aux->siguiente;
                    ++contador;
                } else {
                    existe_enlace = false;
                }
            }
            if (contador != 0) {
                return contador + 1;
            }
            return contador+1;
        }
    }

    void eliminar_cabeza(){
        Nodo * aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

    void elminar_cola(){
        Nodo* aux = primero;
        for (int i = 0; i < size(); ++i) {
            aux = aux->siguiente;
        }
        delete aux->siguiente;
        aux->siguiente = 0;
    }
    void eliminar_pos(int pos){
        Nodo * aux = primero;
        if (pos > size()){
            std::cout << "No se puede eliminar en dicha posicion" << std::endl;
        }else{
            Nodo* aux = primero;
            for (int i = 0; i < pos-1; ++i) {
                aux = aux->siguiente;
            }
            Nodo* aux2 = aux->siguiente;
            aux->siguiente = aux2->siguiente;
            delete aux2;
        }
    }
    T at(int pos) {
        Nodo *aux = primero;
        if (pos > size()) {
            std::cout << "No se puede extraer en dicha posicion" << std::endl;
        } else {
            Nodo *aux = primero;
            for (int i = 0; i < pos; ++i) {
                aux = aux->siguiente;
            }
            return aux->elemento;
        }
    }

    void mostrar_pos(int pos){
        if(pos > size()){
            std::cout << "No se puede eleiminar dicha posicion";
        }else{
            Nodo* aux = primero;
            for(int i = 0; i<pos; i++){//llegamos hasta el nodo anterior al que queremos eliminar
                aux = aux->siguiente;//guardamos en aux el nodo anterior al que queremos eliminar que señala al nodo que queremos eliminar
            }
            cout << aux->elemento << endl;


        }
    }

    void recorrerLista(){
        for(int i = 0; i<size()+1; ++i){
            mostrar_pos(i);
        }
    };

};
#endif //LISTAENLAZADA_LINKED_LIST_H