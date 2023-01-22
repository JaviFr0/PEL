#include <iostream>
using namespace std;
class X {
    private:
        int id;
    public:
        X(){
            X:: id = 0;
        }

        X(int ident){
            X::id = ident;
        }

        void imprimir(){
            cout << to_string(X::id) << endl;
        }

        ~X(){
            cout << "Borrado";
        };

        X eliminar(){
            X:: ~X();
            cout << "Borrado";
        };
};

int main(int, char**) {
    X* p_array = new X[3] {X( 1), X(2), X(3)};

    for (int i = 0; i<3; i++){
        p_array ->imprimir();
        //p_array[i].imprimir();
        p_array ++;
    }

        for (int i = 0; i<3; i++){
        p_array ->eliminar();
        //p_array[i].eliminar();
        p_array ++;
    }


};