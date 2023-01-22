/**
 Ejercicio 4: Implementar en C++ un sistema sencillo de altas y bajas de 
usuarios.
En dicho sistema de altas y bajas debe poder crearse un objeto “usuario” con 
nombre, apellidos y número de usuario, correspondiente al número de usuarios 
dados de alta. 
Importante remarcar que los ID de usuarios no se sustituyen. Si se han creado 3 
usuarios y se da de baja el tercero, el nuevo usuario tendrá el id 3. 
Para dar de baja un usuario, debe eliminarse usando el destructor del objeto 
usuario, mostrando por pantalla que usuarios han sido destruido.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iterator>
using namespace std;

class Usuario{

    private:
        string nombre;
  
        string apellido;
    
        int numero_usuario;
 
    
    public:
        void imprimir_usuario();
        void imprimir_altas_usuario();
        string getnombre();
        string getapellido();
        int getnumero_usuario();
        void setnombre(string nombre_new);
        void setapellido(string apellidos_new);
        void setnumero_usuario(int numero_usuario_new);
        Usuario(string nombre, string apellido, int numero_usuario);
    };
            Usuario::Usuario(string nombre, string apellido, int numero_usuario){
                this->nombre= nombre;
                this->apellido=apellido;
                this->numero_usuario=numero_usuario;
            };
            string Usuario::getnombre(){
                return nombre;
            };
            string Usuario::getapellido(){
                return apellido;
            };
            int Usuario::getnumero_usuario(){
                return numero_usuario;
            };
            void Usuario:: setnumero_usuario(int numero_usuario_new){
                numero_usuario=numero_usuario_new;
            };
            void Usuario:: setnombre(string nombre_new){
                nombre=nombre_new;
            };
            void Usuario:: setapellido(string apellido_new){
               apellido=apellido_new;
            };
            void Usuario::imprimir_usuario(){
                cout<<"Nombre del usuario: "<<nombre<<" Apellido del usuario: "<<apellido<<endl;
            };
            void Usuario::imprimir_altas_usuario(){
                cout<<"Nombre del usuario: "<<nombre<<" Apellido del usuario: "<<apellido<<" Identificador del usario: "<<numero_usuario<<endl;
            };


class Registro{
    private:
        vector<Usuario> usuarios;
        vector<Usuario> *pusuarios=&usuarios;
        vector<Usuario> altas_usuarios;
        vector<Usuario> *paltas_usuarios=&usuarios;
        int choose_baja;
    public:
        int getchoose_baja();
        void setchoose_baja(int choose_baja_new);
        ~Registro(){
            delete(&altas_usuarios[choose_baja]);
        };
        void anadir_usuario();
        void dar_alta();
        void dar_baja();
        void menu();
        void reajuste_vector();
};

            int Registro::getchoose_baja(){
                return choose_baja;
            };

            void Registro::setchoose_baja(int choose_baja_new){
                choose_baja=choose_baja_new;
            };

            void Registro::anadir_usuario(){
                string nombre_recibido;
                string apellido_recibido;
                int numero_usuario_recibido=0;
                cout<<"Dime tu nombre"<<endl;
                cin>>nombre_recibido;
                cout<<"Dime tu apellido"<<endl;
                cin>>apellido_recibido;
                Usuario voidUsuario(nombre_recibido, apellido_recibido,numero_usuario_recibido);
                voidUsuario.imprimir_usuario();
                usuarios.push_back(voidUsuario);
                cout<<"--------------------------------------------"<<endl;
                cout<<"Usuario creado: "<<endl;
            };


            void Registro::dar_alta() {
                cout<<"Dime el numero de usuario quieres dar de alta"<<endl;
                int choose;
                //cout << "Size" << usuarios.size()<<endl;
                for(int i = 0; i < usuarios.size(); i++){
                    cout<<""<<i<<".-";
                    usuarios[i].imprimir_usuario();// como pollas se pone esto bien
                    cout<<""<<endl;
                };
                cin>>choose;
                altas_usuarios.push_back(usuarios[choose]);
                altas_usuarios[altas_usuarios.size()].setnumero_usuario(altas_usuarios.size());
                cout<<"Usuario dado de alta con exito"<<endl;
            };


            void Registro::dar_baja(){
                cout<<"Dime el identificador del usuario que quieres dar de baja"<<endl;
    
                   for(int k = 0; k < usuarios.size(); k++){
                     cout<<""<<k<<".-";
                    usuarios[k].imprimir_usuario();
                    cout<<""<<endl;
                };
                cin>>choose_baja;
                usuarios.erase(usuarios.begin()+choose_baja);
                reajuste_vector();
                cout<<"Usuario dado de baja con exito"<<endl;
            };
            
            void Registro::reajuste_vector(){
                for (int i = 0; i<altas_usuarios.size(); i++){
                    if(altas_usuarios[i].getnumero_usuario() != i){
                        altas_usuarios[i].setnumero_usuario(i);
                    }
                };
            }
    
            void Registro::menu(){

                int choose;
                do{
                    cout<<"Elige una opcion"<<endl;
                    cout<<"--------------------------------------------"<<endl;
                    cout<<"Opcion 1-Anadir usuario"<<endl;
                    cout<<"Opcion 2-Dar de alta un usuario"<< endl;
                    cout<<"Opcion 3-Dar de baja un usuario"<< endl;
                    cout<<"Opcion 4-Salir"<<endl;
                    cout<<"--------------------------------------------"<<endl;
                    cin>>choose;
                        switch (choose){
                            case 1:
                                anadir_usuario();
                                break;
                            case 2:
                                dar_alta();
                                break;
                            case 3:
                                dar_baja();
                                break;
                            default: "Opcion no valida";
                                exit(-1);
                        };
                }
                while(choose!=4);
                altas_usuarios.~vector<Usuario>();
                usuarios.~vector<Usuario>();
                exit(-1);
            };


            int main(){
                Registro Registrobd;
                Registrobd.menu();
                return 0;
            };