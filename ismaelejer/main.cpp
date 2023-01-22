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
    delete[] pmochila;
    bool c=false;
    do {
        cout << "Quieres meter, eliminar un objeto o lista \n";
        cin >> r;

        if("meter" != r || "eliminar" != r || r != "lista") {
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
            cout << "Que objeto desea elminar, introduca un numero\n";
            cin>> v;
            cout<<"Se va a borrar  " << mochila[stoi(v)]<<endl;
            mochila.erase(mochila.begin()+ stoi(v));
            cout<<"El objeto ha sido eliminado"<<endl;
        }
        else if(r=="lista"){

            for (int i = 0; i < mochila.size(); i++) {
                cout <<mochila[i]<<"\n";

            }
        }
    }while (r == "meter" || r == "eliminar" || r=="lista" || c==true);
    delete[] pmochila;
};
