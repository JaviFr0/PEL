#include <iostream>

using namespace std;

template<typename T>
class VectorPEL {
private :
    T *v_, //Puntero que apunta al inicio del vector.
    *space_,// Puntero que apunta al siguiente del último elemento almacenado.
    *last_; // Puntero que apunta al siguiente bloque del ultimo elemento del vector.

public:
    VectorPEL() : v_{new T[0]}, space_{v_}, last_{v_} {}//Constructor inicializado a 0
    VectorPEL(VectorPEL<T> const &v) : v_{new T[v.capacity()]}, space_{v_ + v.size()}, last_{v_ + v.capacity} {
        try {
            for (auto i = size_t{0}; i < v.size(); ++i) {
                v_[i] = v[i];

            }
        } catch (...) {
            delete[] v_;
            throw;
        }
    }// Constructor copia
    ~VectorPEL() { delete[] v_; }

    // Metodos a declarar:
    // Size(); Capacity(); Beging(); End(); Empty();

    // Metodos de capacidad:
    // size_t size(){return space_ - v_;} Esta es otra manera de hacer lo de abajo:
    auto size() const -> size_t { return space_ - v_; }

    auto capacity() const -> size_t { return last_ - v_; }

    auto empty() const -> bool { return v_ == space_; }


    // Metodos de acceso:
    auto begin() const -> T const * { return v_; }

    auto begin() -> T * { return v_; }

    auto end() const -> T const * { return space_; }

    auto end() -> T * { return space_; }

    //Metodo Push_back:

    void push_back(T const &valor) {
        if (space_ == last_) {
            size_t cap = capacity(), new_cap = (cap == 0) ? 2 : 2 * cap;
            T *new_block = new T[new_cap];
            try {
                for (auto i = size_t{0}; i < cap; ++i) {
                    new_block[i] = v_[i];
                }
                new_block[cap] = valor;
            } catch (...) {
                 delete [] new_block;
                throw ;
            }
            delete []v_;
            v_ = new_block;
            space_ = new_block + cap + 1;
            last_ = new_block + new_cap;
        }
        else{
            *space_ = valor;
            ++space_;
        }
    }


};
