#include <cstdlib>
#include <iostream>
#include <cmath>
#include <stdbool.h>
#include <vector>
#include <ranges>
#include <algorithm>
#include <stdexcept>
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

      void bounds_check(std::size_t i) const { if (size() < i) throw std::out_of_range("chupame los huevos es que me cago en la puta bro es que la culpa sea del tipo que se le olvide poner los parentesis"); }
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




int main(){
auto words = Vector<std::string>{
}; // vector de palabras inicialmente vacío

   auto mssg = []{
   cout <<"Insert a word (EOF to finish): "<<endl;
    return true;
    };

   for (auto wrd = std::string{}; mssg() and std::getline(std::cin, wrd); /* no-op */)
      words.push_back(wrd);

   std::ranges::sort(words);
   for (std::string const& wrd : words)
     cout<<"{}, "+ wrd<<endl;

};
