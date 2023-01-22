/*
Inventario de armaduras dejadas  con los siguientes datos:
    - ID de la armadura
    - Nombre de la armadura
    - Descripción de las habilidades de la armadura

Para ello, se te ha encargado la responsabilidad de desarrollar una aplicación que almacene dicha informacion en grupos de 5,
ordenado de menor a mayor el id de armadura dentro de esos grupos.

Debido a un problema con los servidores de IS, la información seolo puede almacenarse en esta aplicación, por lo que para poder aumentar
la cantidad de datos que se quieren almacenar, debe agregarse una función que migre los datos ya ordenadoes (en bloques de grupo)
a una única lista enlazada, donde estarán todas lar armaduras.

La apliaciónm además, requiere de un método de búsqueda, que permite obtener la armadura buscando por su índice de las listas.

- Las estructuras y plantillas que deben utilizarse son las vistas en la asignatura
- En caso de que no quieran o puedan usarse, pueden realizrse el ejercicio mediante la clase estándar (penaliza)
- Se valora de forma positiva el uso de la recursividad en lugar de la iteratividad, pero no es un requisito obligatorio
- También se valorá de forma positiva que las funciones estén accesibles a través de un menú

*/

#include <iostream>
using namespace std;

class Armadura{

private:
    int id;
    string nombre;
    string descripcion;
public:
    Armadura() {
        id = 0;
        nombre = "";
        descripcion = "";
    }

    Armadura(int i , string n , string d) {
        id = i;
        nombre = n;
        descripcion = d;
    }

    int getID() {
        return id;
    }
};

class Contenedor {
private:
    int num_elementos;
    Armadura almacen[5];
public:
    Contenedor() {
        int num_elementos = 0;
    }

    void Insertar(Armadura a) {
        if(num_elementos > 5) {
            cout << "Contenedor lleno" << endl;
        } else {
            almacen[num_elementos] = a;
            num_elementos++;
        }
    }

    Armadura extraer() {
        Armadura aux = almacen[num_elementos];
        num_elementos--;
        return aux;
    }

    void ordenameEsta(){
        for(int i = 0; i < num_elementos; i++) {
            for(int j = 0; j < num_elementos; j++) {
                if(almacen[i].getID() < almacen[j].getID()) {
                    Armadura aux = almacen[i];
                    almacen[i] = almacen[j];
                    almacen[j] = aux;
                }
            }
        }
    }

    int size() { // Esto el lo ha llamado getElementos
        return num_elementos;
    }

    void mostrar() {
        for (int i = 0; i < num_elementos; i++) {
            cout << almacen[i].getID() << " - ";
        }
    }

};

class ListaEnlazada {
protected:
    class NodoArmadura {
    public:
        Armadura dato;
        NodoArmadura* enlace;

        NodoArmadura(Armadura a) {
            dato = a;
            enlace = 0;
        }
    };

private:
    NodoArmadura* primero;
public:
    ListaEnlazada() {
        primero = 0;
    }

    void insertar(Armadura a) {
        NodoArmadura* n = new NodoArmadura(a);
        n->enlace = primero;
        primero = n;
    }

    void rellenarLista(Contenedor &c, ListaEnlazada &l) {
        for(int i = 0; i < c.size()-1; i++) {
            Armadura aux = c.extraer();
            l.insertar(aux);
        }
    }
};




int main() {

    Armadura* a1 = new Armadura(1,"Dildo 3XL", "Pasión");
    Armadura* a2 = new Armadura(2,"Armadura", "Proteger");
    Armadura* a3 = new Armadura(3,"Comba", "Saltar");
    Armadura* a4 = new Armadura(4,"Dildo", "Disfrutar");
    Armadura* a5 = new Armadura(5,"Bolas", "Gozar");

    Contenedor* c1 = new Contenedor();
    c1->Insertar(*a1);
    c1->Insertar(*a3);
    c1->Insertar(*a2);
    c1->Insertar(*a4);
    c1->Insertar(*a5);

    Armadura* a6 = new Armadura(1,"Dildo 3XL", "Pasión");
    Armadura* a7 = new Armadura(2,"Armadura", "Proteger");
    Armadura* a8 = new Armadura(3,"Comba", "Saltar");
    Armadura* a9 = new Armadura(4,"Dildo", "Disfrutar");
    Armadura* a10 = new Armadura(5,"Bolas", "Gozar");

    Contenedor* c2 = new Contenedor();
    c2->Insertar(*a6);
    c2->Insertar(*a7);
    c2->Insertar(*a8);
    c2->Insertar(*a9);
    c2->Insertar(*a10);

    Armadura* a11= new Armadura(1,"Dildo 3XL", "Pasión");
    Armadura* a12 = new Armadura(2,"Armadura", "Proteger");
    Armadura* a13 = new Armadura(3,"Comba", "Saltar");
    Armadura* a14  = new Armadura(4,"Dildo", "Disfrutar");
    Armadura* a15  = new Armadura(5,"Bolas", "Gozar");

    Contenedor* c3 = new Contenedor();
    c3->Insertar(*a11);
    c3->Insertar(*a12);
    c3->Insertar(*a13);
    c3->Insertar(*a14);
    c3->Insertar(*a15);

    ListaEnlazada* l = new ListaEnlazada();
    l->rellenarLista(*c1, *l);
    l->rellenarLista(*c2, *l);
    l->rellenarLista(*c3, *l);




    cout << "Contenedor 1" << endl; c1->mostrar();   cout << endl;
    cout << "Contenedor 2" << endl; c2->mostrar();   cout << endl;
    cout << "Contenedor 3" << endl; c3->mostrar();   cout << endl;


    cout << "Contenedor ordenador" << endl;
    c1->ordenameEsta();  c1->mostrar();



    return 0;
}