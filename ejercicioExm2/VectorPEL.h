
#include <iostream>

using namespace std;

template<typename T> class VectorPEL{
private:
    T * v_, * space_, * last_;

public:
    VectorPEL(): v_{new T[0]}, space_{v_}, last_{v_} {}
    VectorPEL(VectorPEL<T> const& v): v_{new T[v.capacity()]}, space_{v_ + v.size()}, last_{v_ + v.capacity()} {
        try{
            for (auto i = size_t{0}; i< v.size(); ++i){
                v_[i] = v[i];
            }
        }
        catch (...){
            delete[] v_;
            throw;
        }
    }
    ~VectorPEL() {delete[] v_;}

    auto capacity() const -> size_t {return last_ - v_;}
    auto size() const -> size_t {return space_ - v_;}
    auto empty() const -> bool {return v_ == last_;}

    auto begin() -> T* {return v_;}
    auto begin() const -> T const* {return v_;}
    auto end() -> T* {return space_;}
    auto end() const -> T const* {return space_;}

    auto getPos(size_t pos) -> T* {return v_ + pos;}
    auto getPos(size_t pos) const -> T const* {return v_ + pos;}

    auto push_back(T const& valor){
        if (space_ == last_){
            size_t cp = capacity(), new_cp = (cp == 0)? 2:2*cp;
            T* new_block = new T[new_cp];
            try{
                for (auto i = size_t{}; i < cp ; ++i){
                    new_block[i] = v_[i];
                }
                new_block[cp] = valor;
            }
            catch (...){
                delete[] new_block;
                throw;
            }
            delete[] v_;
            v_ = new_block;
            space_ = new_block + cp + 1;
            last_ = new_block + new_cp;
        }
        else{
            *space_ = valor;
            ++space_;
        }
    }

};
