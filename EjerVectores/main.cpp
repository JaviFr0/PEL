#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <ranges>
#include <algorithm>
#include <stdexcept>
#include <string>
#include<bits/stdc++.h>

using namespace std;

/*Una discográfica, recientemente ha decidido actualizar sus sistemas informáticos,
pasando a almacenar todos los álbumes con la información correspondiente al
titulo del álbum, grupo al que pertenece y género musical que los representa.
Dicho programa, debe tener un sistema de búsquedas, que muestre por consola
los resultados de buscar, ya sea el grupo, el título o el género. En caso de no
encontrarlo se mostrará un mensaje por pantalla que indique que no se ha podido
encontrar el álbum.
Para realizar dicho proyecto, los álbumes se almacenarán en un vector, y debe
manejarse las búsquedas mediante estos.*/

template<typename T> // T debe ser un tipo default_initializable
class Vector {
    T* v_,     // inicio del espacio de capacidad reservada para el vector
    * space_, // fin de la secuencia de elementos almacenados
    * last_;  // fin de la capacidad reservada para el vector

    void bounds_check(std::size_t i) const { if (size() < i) throw std::out_of_range("Error"); }
public:
    Vector() // construye un vector vacío
            : v_{new T[0]}, space_{v_}, last_{v_} { }

    Vector(Vector<T> const& v)
            : v_{new T[v.capacity()]}, space_{v_ + v.size()}, last_{v_ + v.capacity()}
    {
        try {
            for (auto i = size_t{0}; i < v.size(); ++i)
                v_[i] = v[i];
        }
        catch (...) {
            delete[] v_;
            throw;
        }
    }

    auto& operator=(Vector<T> const& rhs)
    {
        auto tmp = Vector<T>{rhs};
        std::swap(v_, tmp.v_);
        std::swap(space_, tmp.space_);
        std::swap(last_, tmp.last_);
        return *this;
    }

    ~Vector() { delete[] v_; } // destruye el array apuntado por v_

    // funciones de capacidad_________________________________________
    auto size()     const -> std::size_t { return space_ - v_; }
    auto capacity() const -> std::size_t { return last_ - v_; }
    auto empty()    const -> bool        { return v_ == space_; }

    // funciones de acceso____________________________________________

    // sin bounds checking:
    auto operator[](std::size_t i)       -> T&       { return v_[i]; }
    auto operator[](std::size_t i) const -> T const& { return v_[i]; }
    // con bounds checking:
    auto at(std::size_t i)       -> T&       { bounds_check(i); return v_[i]; }
    auto at(std::size_t i) const -> T const& { bounds_check(i); return v_[i]; }

    auto begin()       -> T*       { return v_; }
    auto begin() const -> T const* { return v_; }
    auto end()         -> T*       { return space_; }
    auto end()   const -> T const* { return space_; }


    void push_back(T const& val)
    {
        if (space_ == last_) { // capacidad agotada o primera vez que invocamos push_back
            std::size_t cp = capacity(),              // capacidad actual del vector
            new_cp = (cp == 0)? 2 : 2*cp; // nueva capacidad
            T* new_block = new T[new_cp]; // nuevo bloque de memoria
            try {
                for (auto i = std::size_t{}; i < cp; ++i)
                    new_block[i] = v_[i];
                new_block[cp] = val;
            }
            catch (...) { // de lanzarse una excepción...
                delete[] new_block; //... destruimos el nuevo array...
                throw;              // ...y relanzamos la excepción
            }
            // destruimos el array original y reasignamos los punteros:
            delete[] v_;
            v_ = new_block;
            space_ = new_block + cp + 1;
            last_ = new_block + new_cp;
        }
        else {
            *space_ = val;
            ++space_;
        }
    };
    // resto de la interfaz pública...

};
void BuscarAlbum(vector <string>*cap1, vector<string>*album);
void BuscarGrupoMusical(vector <string>*cap1,vector<string>*album1);
void BuscarGeneroMusical(vector <string>*cap1, vector<string>*album2);
vector<string> unir(vector <string>*cap1, vector<string>*cap, vector<string>*album,vector <string>*album1,vector<string>*album2);
void mostrarCatalogo();
int main(){
    auto *cap = new vector <std::string>{10};
    auto *cap1 = new vector <std::string>{15};
    auto *album1 = new vector <std::string>{};
    album1->push_back("The Beatles");
    album1->push_back("The Rolling Stones");
    album1->push_back("Mecano");
    album1->push_back("AC/DC");
    album1->push_back("Queen");
    auto *album2 = new vector <std::string>{};
    album2->push_back("Pop Rock");
    album2->push_back("Rock and Roll");
    album2->push_back("Pop");
    album2->push_back("Hard Rock");
    album2->push_back("Rock");
    auto *album = new vector <std::string>{};
    album->push_back("Abbey Road");
    album->push_back("Sticky Fingers");
    album->push_back("Entre el cielo y el suelo");
    album->push_back("Back in Black");
    album->push_back("Made in Heaven");
    int choose;
    do{ cout<<"--------------------------------------------"<<endl;
        cout<<"Elige una opcion:"<<endl;
        cout<<"--------------------------------------------"<<endl;
        cout<<"Opcion 1-Buscar por album"<<endl;
        cout<<"Opcion 2-Buscar por grupo"<< endl;
        cout<<"Opcion 3-Buscar por genero"<< endl;
        cout<<"Opcion 4-Mostrar Catalogo"<< endl;
        cout<<"Opcion 5-Salir"<<endl;
        cout<<"--------------------------------------------"<<endl;
        cin>>choose;
        switch (choose){
            case 1:
                cout<<"Entrando en la opcion 1(Buscar por album):"<<endl;
                unir(cap1, cap, album, album1, album2);
                BuscarAlbum(cap1, album);
                break;
            case 2:
                cout<<"Entrando en la opcion 2(Buscar por grupo):"<<endl;
                unir(cap1, cap, album, album1, album2);
                BuscarGrupoMusical(cap1, album1);
                break;
            case 3:
                cout<<"Entrando en la opcion 3(Buscar por genero):"<<endl;
                unir(cap1, cap, album, album1, album2);
                BuscarGeneroMusical(cap1, album2);
                break;
            case 4:
                cout<<"Mostrando Catalogo"<<endl;
                mostrarCatalogo();
                break;
            default: cout<< "Saliendo..."<<endl;
                exit(-1);
        };
    }
    while(choose!=5);
};
vector <string> unir(vector <string>*cap1, vector<string>*cap, vector<string>*album,vector <string>*album1,vector<string>*album2){

    merge(album->begin(), album->end(), album1->begin(), album1->end(), cap->begin());
    merge(album2->begin(), album2->end(), cap->begin(), cap->end(), cap1->begin());
    return *cap1;
};
void BuscarGrupoMusical(vector <string>*cap1, vector<string>*album1){
      string usuario2;
      cout<<"Dime el grupo a buscar:";
      cin.ignore();
      getline(cin,usuario2);
      for (std::string const& grupoMusical : *cap1) {
          for(std::string const& grupoMusical1: *album1)
          if (grupoMusical == usuario2 && usuario2==grupoMusical1) {
              cout << "Encontrado" << endl;
              return;
          }
      }
             cout<<"No encontrado"<<endl;

};
void BuscarGeneroMusical(vector <string>*cap1, vector<string>*album2) {

    string usuario3;
    cout<<"Dime el genero a buscar:";
    cin.ignore();
    getline(cin,usuario3);
    for (std::string const& generoMusical: *cap1) {
        for(std::string const& generoMusical1: *album2)
        if (generoMusical == usuario3 && usuario3==generoMusical1) {
            cout << "Encontrado" << endl;
            return;
        }
    }

            cout << "No encontrado" << endl;


};
void BuscarAlbum(vector <string>*cap1, vector<string>*album){
    string usuario1;
    cout<<"Dime el album a buscar:";
    cin.ignore();
    getline(cin,usuario1);

    for (std::string const& Tipodealbum : *cap1 ) {
        for(std::string const& Tipodealbum1: *album)
        if (Tipodealbum == usuario1 && Tipodealbum1==usuario1) {
            cout << "Encontrado" << endl;
            return;
        }
    }

            cout<<"no encontrado"<<endl;


};

void mostrarCatalogo(){
    cout<<"Los albumes de la discografica son:  ";
    cout<<"Abbey road, Sticky Fingers, Entre el cielo y el suelo, Black in Black y Made in Heaven"<<endl;
    cout<<"Los grupos de muscica son: ";
    cout<<"The Beatles, The Rolling Stones, Mecano, AC/DC y Queen"<<endl;
    cout<<"Los generos musicales son: ";
    cout<<"Pop Rock, Rock and Roll, Pop, Hard Rock y Rock "<<endl;
};
