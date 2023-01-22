#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    vector<string> mochila;
    vector<string> *pmochila=&mochila;
    string r;
    string v;
    string k;
    bool c=false;
    do {
        cout << "Quieres meter, eliminar un objeto o mostrar o salir \n";
        cin >> r;

        if("meter" != r && "eliminar" != r && r != "mostrar" && r!="salir") {
            c = true;
            cout << "Solo se aceptan: meter, eliminar o mostrar\n";

        };
        if (r == "meter") {
            cout << "Inserta el objeto que quieras meter\n";
            cin >> k;
            mochila.push_back(k);
        }
        else if (r == "eliminar") {
            for (int i = 0; i < mochila.size(); i++) {
                cout <<i<<": "<< mochila[i]<<"\n";
            }
            cout << "Que objeto desea elminar, introduzca un numero\n";
            cin>> v;
            cout<<"Se va a borrar  " << mochila[stoi(v)]<<endl;
            mochila.erase(mochila.begin()+ stoi(v));
            cout<<"El objeto ha sido eliminado"<<endl;
        }
        else if(r=="mostrar"){

            for (int i = 0; i < mochila.size(); i++) {
                cout <<mochila[i]<<"\n";

            }
        }
        else if(r=="salir"){ 
        mochila.~vector<string>();
        exit(-1);
                }
    
    }while (r == "meter" || r == "eliminar" || r=="mostrar" || c==true);
    mochila.~vector<string>();
};
