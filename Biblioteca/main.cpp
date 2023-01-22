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
class Libro{
    private:
        string nombreLibro;
        string categoria;
        string autor;
        bool disponibilidad;
        
    public:
        string getnombreLibro();
        string getcategoria();
        string getautor();
        bool getdisponibilidad(); 
        void imprimirLibro();
        string setnombreLibro(string nombreLibroNew);
};
string Libro::setnombreLibro(string nombreLibroNew){
nombreLibro=nombreLibroNew;
};
void Libro::imprimirLibro(){
cout<<"nombre del libro: "<<nombreLibro<<"categoria del libro: "<<categoria<<"autor del libro: "<<autor<<"disponibilidad del libro: "<< disponibilidad<<endl;
};
string Libro::getnombreLibro(){
return nombreLibro;
};
string Libro::getautor(){
return autor;
};
string Libro::getcategoria(){
return categoria;
};
bool Libro::getdisponibilidad(){
return disponibilidad;
};
class Usuario{
    private:
        string nombreUsuario;
        string apellido;
        string DNI;
        string libroActual;
        vector <Libro> historialdelibros; 
    public:
    string setlibroActual(string libroActualNew);
        string getnombreUsuario(){
            return nombreUsuario;
        };
        string getapellido(){
            return apellido;
        };
        string getDNI(){
            return DNI;
        };
        string getlibroActual(){
            return libroActual;
        };
        void addLibroHistorial(Libro pLibro){
            historialdelibros.push_back(pLibro);
        }
        vector <Usuario> gethistorialdelibros();
};
string Usuario::setlibroActual(string libroActualNew){
    libroActual=libroActualNew;
}
class Biblioteca{
    private:
    vector <Libro> libros;
    vector <Usuario> usuarios;
    public:
    bool getlibrodisponible(bool disponibilidad);
    vector <Usuario> getusuarios();
    vector <Libro> getlibros();
    string getsacarlibro();
    string getdevolverlibro();
    void imprimirLibros();
};
void Biblioteca::imprimirLibros(){
    for(int i=0; libros.size(); i++){
        libros[i].imprimirLibro();
    }
};
bool Biblioteca::getlibrodisponible(bool disponibilidad){//xq bool
for(int i=0; libros.size(); i++){
   if(libros[i].getdisponibilidad()==true){
    libros[i].imprimirLibro();
   };
   };
    
};
string Biblioteca::getdevolverlibro(){
    int c; 
    cout<<"Dime el usuario que eres"<<endl;
    for(int j=0; usuarios.size(); j++){
        //cout<<usuarios[j] <<" ";
    };
    if(usuarios[c].getlibroActual()!=""){
        usuarios[c].getlibroActual()=="";
    }
};
string Biblioteca::getsacarlibro(){
    int b; 
    cout<<"Dime el usuario que eres"<<endl;
    for(int j=0; usuarios.size(); j++){
        //cout <<usuarios[j] <<" ";
    };
    if(usuarios[b].getlibroActual()==""){
        int a;
        cout<<"Dime el libro que deseas"<<endl;
        for(int i=0; libros.size(); i++){
        //cout <<libros[i] <<" ";
        //printear los libros con un numero donde puedas elegir(supongo que necesitas un for para printear el vector)
        };
        cin>>a;
        if(libros[a].getdisponibilidad()==true){
            libros[a].getdisponibilidad()==false;
            usuarios[a].setlibroActual(libros[a].getnombreLibro());
            usuarios[a].addLibroHistorial(libros[a]);
        };
    };
};
Biblioteca::Biblioteca(){
    vector <Libro> libros;
    vector <Usuario> usuarios;
};
main(){
   Biblioteca(){
    libro libro1("ElSenorDeLosAnilos","fantasia", "J.R.R Tolkien", true);
   };
};