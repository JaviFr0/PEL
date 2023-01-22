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

    for(int l=0;l<=5;l++){

        pilas[l] = Pila();

    }

    int i=0, j=0, k=0;

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

        do{

            cout<<"Introduce un numero 'k': ";

            cin>>k;

        }while(k!=0&&k!=-1);

        if(k==-1){

            for(int x=1;x<=5;x++){

                cout<<"Borrando pila "<<x<<endl;

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

        }

    }while(i!=0 && k!=0);

    if(pilas[1].siguiente==NULL){

        cout<<"Se han eliminado todos los elementos, las pilas est�n vacias"<<endl;

    }

    else{

        for(int x=1;x<=5;x++){

            cout<<"Imprimiendo pila "<<x<<endl;

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
    }

    return 0;
}