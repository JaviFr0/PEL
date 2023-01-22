#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <ranges>
#include <algorithm>
#include <stdexcept>
#include <string>
using namespace std;

/*Un videoclub solicita a vuestra empresa realizar un proyecto por el cual, se puedan
cargar nuevos discos en el sistema de alquileres. Para ello, es necesario almacenar
la información correspondiente al titulo de la película, el precio del alquiler y si es
un DVD, o un blu-ray. El sistema además tendrá que indicar si el disco está o no
alquilado.
 Este sistema debe permitir buscar los discos mediante su título. Si un título está
alquilado, no estará disponible su información, pero si no lo está se mostrará al
usuario en pantalla.
También debe haber una opción de alquilar, que cambie el estado de un no
alquilado a alquilado, y un sistema de devolución, que cambie el estado de
alquilado a no alquilado. */

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
class Disco{
private:
    int precio;
    string nombre_peli;
    bool alquilado;
    string tipo;

public:
    int getPrecio(){
        return precio;
    }
    string getNomre_peli(){
        return nombre_peli;
    }
    bool getAlquilado(){
        return alquilado;
    }
    string getTipo(){
        return tipo;
    }


    void setPrecio(int p){
        precio=p;
    }
    void setNombre_pel(string n){
        nombre_peli=n;
    }
    void setAlquilado(bool a){
        alquilado=a;
    }
    void setTipo(string t){
        tipo=t;
    }


    Disco(int precio, string nombre_peli,bool alquilado,string tipo){
        this->precio=precio;
        this->nombre_peli=nombre_peli;
        this->alquilado=alquilado;
        this->tipo=tipo;
    }


};

void buscar(vector<Disco> listaDiscos);
bool alquilado(vector<Disco>& listaDiscos);
bool devolver(vector<Disco>& listaDiscos);

int main(){


    Disco disco1(10,"Titanic",false,"dvd");
    Disco disco2(20,"Fast and Furious",true,"dvd");
    Disco disco3 (15,"Alien",false,"dvd");
    Disco disco4 (24,"Paco", true,"bluray");

    vector<Disco> listaDiscos;
    listaDiscos.push_back(disco1);
    listaDiscos.push_back(disco2);
    listaDiscos.push_back(disco3);
    listaDiscos.push_back(disco4);

    int choose;
    do{ cout<<"--------------------------------------------"<<endl;
        cout<<"Elige una opcion:"<<endl;
        cout<<"--------------------------------------------"<<endl;
        cout<<"Opcion 1-Buscar pelicula" <<endl;
        cout<<"Opcion 2-Alquilar"<< endl;
        cout<<"Opcion 3-Devolver"<< endl;
        cout<<"Opcion 4-Salir"<<endl;
        cout<<"--------------------------------------------"<<endl;
        cin>>choose;
        switch (choose){
            case 1:
                buscar(listaDiscos);
                break;
            case 2:
                cout<<"Entrando en la opcion 2(Alquilar):"<<endl;
                alquilado(listaDiscos);
                break;
            case 3:
                cout<<"Entrando en la opcion 3(Devolver):"<<endl;
                devolver(listaDiscos);
                break;
            default: "Opcion no valida";
                exit(-1);
        };
    }
    while(choose!=4);
};



void buscar(vector<Disco> listaDiscos){
    string nombre_peli;
    cout<<"Introduce el nombre de la pelicula que quieres buscar: "<<endl;
    cin>>nombre_peli;
    for (int i = 0; i < listaDiscos.size(); ++i) {
        if (listaDiscos[i].getNomre_peli()==nombre_peli){
            if(listaDiscos[i].getAlquilado()==true){
                cout<<"La pelicula esta alquilada"<<endl;
            }else{
                cout<<"La pelicula "<<nombre_peli<<endl;
                cout<<"El precio es: "<<listaDiscos[i].getPrecio()<<endl;
                cout<<"El tipo es: "<<listaDiscos[i].getTipo()<<endl;
                cout<<"La pelicula no esta alquilada"<<endl;
            }
        }
    }
}
bool alquilado(vector<Disco>& listaDiscos) {
    int n;
    for (int i = 0; i < listaDiscos.size(); i++) {
        if (listaDiscos[i].getAlquilado() == false) {
            cout << i<<": "<<listaDiscos[i].getNomre_peli() <<endl;
        }
    }

    cout<<"Indica el numero de peli para alquilar"<<endl;
    cin>>n;
    listaDiscos[n].setAlquilado(true);
};

bool devolver(vector<Disco>& listaDiscos) {
    int n;
    for (int i = 0; i < listaDiscos.size(); i++) {
        if (listaDiscos[i].getAlquilado() == true) {
            cout << i << ": " << listaDiscos[i].getNomre_peli() << endl;
        }
    }
    cout << "Indica el numero de peli para devolver" << endl;
    cin >> n;
    listaDiscos[n].setAlquilado(false);
};
