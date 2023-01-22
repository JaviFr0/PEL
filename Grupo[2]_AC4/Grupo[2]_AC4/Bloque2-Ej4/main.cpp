

#include <iostream>

using namespace std;

class Pila{

public:

    int elemento;

    Pila *siguiente;

    Pila(){

        this->elemento=0;

        this->siguiente = NULL;

    }

    void crearNodo(int n){

        Pila *pila = new Pila();

        pila->elemento = n;

        pila->siguiente = this->siguiente;

        this->siguiente = pila;

    }

    void extraerNodo(){

        Pila *exter = this->siguiente;

        this->elemento = exter->elemento;

        this->siguiente = exter->siguiente;

        delete exter;

    }


};

int main(){


    Pila pilas [5];

    for(int k=0;k<=5;k++){

        pilas[k] = Pila();

    }

    int i=0, j=0;

    do{

        cout<<"Introduce un numero 'i': ";

        cin>>i;

        if(i>0){

            cout<<"Introduce un numero 'j': ";

            cin>>j;

            pilas[i].crearNodo(j);

            cout<<"Se ha agregado el elemento "<<j<<" a la pila "<<i<<endl;

        }

        else if(i<0){

            cout<<"Introduce un numero 'j': ";

            cin>>j;

            pilas[j].extraerNodo();

            cout<<"Se ha extraido el elemento "<<j<<" a la pila "<<j<<endl;

        }


    }while(i!=0);

    for(int x=1;x<=5;x++){

        while(pilas[x].siguiente!=NULL){

            pilas[x].extraerNodo();

            if(pilas[x].siguiente!=NULL){

                cout<<pilas[x].elemento<<",";

            }

            else{

                cout<<pilas[x].elemento<<"."<<endl;

            }

        }

    }

    return 0;
}
