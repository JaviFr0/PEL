#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <ranges>
#include <algorithm>
#include <stdexcept>
#include <string>
using namespace std;
/*Identifica una problemática de libre elección y desarrolla una solución a la misma.
Una vez identificado el problema, justifica el porqué de esta y da una solución
codificable al respecto. Esta solución debe poder resolverse usando los
conocimientos desarrollados a lo largo de la asignatura.
No es necesario hacer un código excesivamente extenso, pero si poder
embarcarse en un proyecto de forma autónoma, y resolviendo la problemática
planteada.*/

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
void BuscarAlbum();
void BuscarGrupoMusical();
void BuscarGeneroMusical();
int main(){

    int choose;
    do{ cout<<"--------------------------------------------"<<endl;
        cout<<"Elige una opcion:"<<endl;
        cout<<"--------------------------------------------"<<endl;
        cout<<"Opcion 1-Buscar por album"<<endl;
        cout<<"Opcion 2-Buscar por grupo"<< endl;
        cout<<"Opcion 3-Buscar por genero"<< endl;
        cout<<"Opcion 4-Salir"<<endl;
        cout<<"--------------------------------------------"<<endl;
        cin>>choose;
        switch (choose){
            case 1:
                cout<<"Entrando en la opcion 1(Buscar por album):"<<endl;
                BuscarAlbum();
                break;
            case 2:
                cout<<"Entrando en la opcion 2(Buscar por grupo):"<<endl;
                BuscarGrupoMusical();
                break;
            case 3:
                cout<<"Entrando en la opcion 3(Buscar por genero):"<<endl;
                BuscarGeneroMusical();
                break;
            default: "Opcion no valida";
                exit(-1);
        };
    }
    while(choose!=4);
};

void BuscarGrupoMusical(){
    auto album1=Vector<std::string>{};
    album1.push_back("The Beatles");
    album1.push_back("The Rolling Stones");
    album1.push_back("Mecano");
    album1.push_back("AC/DC");
    album1.push_back("Queen");
    string usuario2;
    cout<<"Dime el grupo a buscar:";
    cin.ignore();
    getline(cin,usuario2);;
    for (std::string const& grupoMusical : album1) {
        if (grupoMusical == usuario2) {
            cout << "Encontrado" << endl;
            return;
        }
    }

    cout<<"No encontrado"<<endl;

};
void BuscarGeneroMusical() {
    auto album2 = Vector < std::string > {};
    album2.push_back("Pop Rock");
    album2.push_back("Rock and Roll");
    album2.push_back("Pop");
    album2.push_back("Hard Rock");
    album2.push_back("Rock");
    string usuario3;
    cout<<"Dime el genero a buscar:";
    cin.ignore();
    getline(cin,usuario3);
    for (std::string const& generoMusical: album2) {
        if (generoMusical == usuario3) {
            cout << "Encontrado" << endl;
            return;
        }
    }
    cout << "No encontrado" << endl;
};
void BuscarAlbum(){
    auto album=Vector<std::string>{};
    album.push_back("Abbey Road");
    album.push_back("Sticky Fingers");
    album.push_back("Entre el cielo y el suelo");
    album.push_back("Back in Black");
    album.push_back("Made in Heaven");
    cout<<"Dime el album a buscar:";
    string usuario1;
    cin.ignore();
    getline(cin,usuario1);

    for (std::string const& Tipodealbum : album ) {
        if(Tipodealbum==usuario1) {
            cout << "Encontrado" << endl;
            return;
        }

    }
    cout << "No encontrado" << endl;

};


