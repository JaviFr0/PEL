/*Implementar en C++ un programa, simulando la pila de usuario 
(y declarando sus valores en la misma) tenga las siguientes funciones: 
• Permita ver que valores se almacenan en la pila del usuario en las diferentes 
posiciones.  
• Debe poder eliminarse el valor de cualquier posición de la pila de usuario.  
El  código  generado  debe  ser  a  prueba  de  errores.  Para  ello  implementa  los 
métodos necesarios para poder mantener el proceso de ejecución.**/
#include <iostream>
#include <stack>
#include <conio.h>
#include <stdlib.h>
using namespace std;


class STACK {
    struct node{
        string data;
        node* link;
    }*TOP;
    public:
        STACK(){
        TOP=NULL;
    }

        void PUSH(){
            struct node* p= new node;
            cout<<"Iserte un elemento: ";
            cin>>p->data;
            p->link=NULL;
            if(TOP==NULL){
                TOP=p;
            }
            else{
                p->link=TOP;
                TOP=p; 
            }
        };

        void POP(){
            if(TOP==NULL){
                cout<<"stack vacio"<<endl;
            }
            else{
                struct node*t=new node;
                t=TOP;
                cout<<"El elemento extraido es:  "<<t->data<<endl;
                TOP=TOP->link;
                delete t;
            }
        };

        void display(){
            struct node*t =new node;
            t=TOP;
            cout<<"Valores dentro de la pila: "<<endl;
            while(t!=NULL){
                cout<<t->data<<endl;
                t=t->link;
            }
        }
};

        int main(){
            int choice;
            STACK obj1;
            do{
                cout<<"---------------------------"<<endl;
                cout<<"Dime una opcion"<<endl;
                cout<<"Menu"<<endl;
                cout<<"\t1.Insertar"<<endl;
                cout<<"\t2.Extraer"<<endl;
                cout<<"\t3.Imprimir"<<endl;
                cout<<"\t4.EXIT"<<endl;
                cout<<"---------------------------"<<endl;
                cin>>choice;
                switch (choice){
                    case 1: obj1.PUSH();break;
                    case 2: obj1.POP();break;
                    case 3: obj1.display();break;
                    default: "Opcion no valida";
                    return(0);
                }
            }while(choice!=4);
            exit(-1);
        };