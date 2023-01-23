#include <cstdio>
template<typename T> class Vector{
private:
    T * v_, // puntero que apunta al principio
    * space_, // puntero que apunta al ultimo elmento lleno mas uno
    * last_; // puntero que apunta al siguiente bloque del ultimo espacio del vector
public:
    Vector(): v_{new T[0]}, space_{v_}, last_{v_} {} // constructor inicializado a 0
    Vector(Vector<T> const& v): v_{new T[v.capacity()]}, space_{v_ + v.size()}, last_{v_ + v.capacity()} {
        try{
            for (auto i = size_t{0}; i < v.size(); i++){
                v_[i] = v[i];
            }
        }
        catch(...){
            delete[] v_;
            throw;
        }
    }//contructor copia

    ~Vector(){delete[] v_;}

    auto size() const -> size_t {return space_ - v_;} // Se hace constante del sistema. La flecha le declara el tipo porque es un "metodo puntero"
    auto capacity() const -> size_t {return last_ - v_;};
    auto empty() const -> bool {return v_ == space_;}
    auto now(int i) -> T* {return v_ + i;}

    //Metodos de acceso
    auto begin() const -> T const* {return v_;}
    auto end() const -> T const* {return space_;}

    //Metodo Push_back
    void push_back(T const& valor){
        if (space_ == last_){
            size_t cap = capacity(), new_cap = (cap == 0)? 2 : 2*cap;
            T* new_block = new T[new_cap];
            try{
                for (auto i = size_t{0}; i < cap; i++){
                    new_block[i] = v_[i];
                }
                new_block[cap] = valor;
            }
            catch(...){
                delete[] new_block;
                throw;
            }
            delete[] v_;
            v_ = new_block;
            space_ = new_block + cap + 1;
            last_ = new_block + new_cap;
        }else{
            *space_ = valor;
            ++space_;
        }
    }
};