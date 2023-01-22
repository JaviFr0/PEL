#include "iostream"
#ifndef ACTIVIDADGRUPAL_4_COLAGEN_H
#define ACTIVIDADGRUPAL_4_COLAGEN_H

template <typename T> class ColaGen {
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
    ColaGen(){
        primero = 0;
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

    bool es_vacia(){
        return primero == 0;
    }

    int size(){
        int contador = 0;
        bool existe_enlace = true;
        Nodo* aux = primero;
        while (existe_enlace == true){
            if (aux->siguiente != 0){
                aux = aux->siguiente;
                ++contador;
            } else {
                existe_enlace = false;
            }
        }
        if (contador !=0){
            return contador+1;
        }
        return contador;
    }

    void eliminar_cabeza(){
        Nodo * aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

    T pop() {
        Nodo *aux = primero;
        if (0 > size()) {
            std::cout << "No se puede extraer en dicha posicion" << std::endl;
        } else {
            Nodo *aux = primero;
            for (int i = 0; i < 0; ++i) {
                aux = aux->siguiente;
            }
            T salida = aux->elemento;
            eliminar_cabeza();
            return salida;
        }
    }

};
#endif //ACTIVIDADGRUPAL_4_COLAGEN_H