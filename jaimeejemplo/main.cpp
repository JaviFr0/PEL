#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <cstdlib>
using namespace std;
//sistema de multas, a los coches , registro de multas, la multa tiene q ser una clase, dentro de la multa precio, agente y lugar
//saber el tipo de etiqueta por km del coche 
class coche
{
    private:
        int kilometros;
        string matricula;
        string DNI;
        string marca;
        string itv;
        vector <multa> multasGenerales;
    public:
        int getkilometros();
        string getMatricula();
        string getDNI();
        string getMarca();
        string getitv();
        coche(int kilometros, string matricula, string DNI, string itv);        
};

       int coche::getkilometros(){
        return kilometros;
       }
        string coche::getMatricula(){
        return matricula;
        }
        string coche::getDNI(){
        return DNI;
        }
        string coche::getMarca(){
        return marca;
        }
        string coche::getitv(){
        return itv;
        }
class trafico
{
    private:
        vector <coche> coches;
//queremos todos los coches con menos que el parametro
    public:
        vector <coche> getCochesKm(int kilometros);
       
};
vector <coche> trafico::getCochesKm(int kilometros){
  
    for(int i=0; i<coches.size();i++){
        if(coches[i].getkilometros()< kilometros){

        }

    }
};

class multa
{
    private:
        int precio;
        string lugar;
        string agente;
    public:
        int getprecio();
        string getlugar();
        string getagente();
        multa(int precio, string lugar, string agente);
        int setpreciomulta(int precioP);
};


        int multa::getpreciomulta(int precioP){
            precio = precioP;
        };
   
        string multa::getagente(){
            return agente;
        };
        string multa::getlugar(){
            return lugar;
        };
        int multa::getprecio(){
        return precio;
        };

int main(int argc, char const *argv[])
{
    return 0;
}


