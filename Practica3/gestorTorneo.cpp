#include <cstdlib>
#include <iostream>
#include <cmath>
#include <stdbool.h>
#include <vector>
//Espacio de nombres para utilizar el cout<< y cin>>
using namespace std;

vector<string> nombresEquipo = {"Angeles", "Lakers", "Real", "Madrid"};
vector<string> nombresEntrenador = {"Lebron", "James", "Pau", "Gasol"};

class partido
{
public:
    string nombreEquipo = "";
    string nombreEquipo2 = "";
    int puntuacion = 0;
    int puntuacion2 = 0;
};

class equipo
{
private:
public:
    string entrenador = "";
    string nombreEquipo = "";
};

int main(int argc, char *argv[])
{
    vector<partido> totalPartidos = {};
    vector<equipo> totalEquipos = {};
    bool menu = true;
    int totalTeams = 0;
    equipo nuevoEquipo;
    partido nuevoPartido;
    while (menu) // Si no usas un valor valido estaras metido aqui todo el rato.
    {
        try
        {
            cout << "\nIntroduce el numero total de equipos. Min(2)/Max(" + to_string(nombresEquipo.size()) + ")\n";
            cin >> totalTeams;
            if (totalTeams > 1 && totalTeams < 5)
            {
                menu = false;
                cout << "\n Equipos creados con exito.";
            }
            else
            {
                cout << "\nDebe haber mas de 1 equipo para que exista un torneo.";
            }
        }
        catch (int totalTeams)
        {
            cout << "\nError, introduce bien los datos";
        }
    }
    for (int i = 0; totalTeams - 1; i++) // Generamos los equipos usando los vectores de nombres random de arriba
    {
        nuevoEquipo.nombreEquipo = nombresEquipo[i];
        nuevoEquipo.entrenador = nombresEntrenador[i];
        totalEquipos.push_back(nuevoEquipo);
    };
    system("cls");
    for (int o = 0; totalTeams - 1; o++) // Printeamos todos los equipos.
    {
        cout << "\nNombre del Equipo:" + totalEquipos[o].nombreEquipo + "\n Nombre del Entrenador: " + totalEquipos[o].entrenador;
    }

    for (int conteoEquipos = 0; totalTeams; conteoEquipos++)
    {
        for (int conteoEquipos2 = 0; totalTeams; conteoEquipos2++) // Bucle anidado para conectar todos los equipos
        {
            if (totalEquipos[conteoEquipos].nombreEquipo != totalEquipos[conteoEquipos2].nombreEquipo) //Añadimos una excepion de que no puedas jugar contigo mismo
            {
                partido nuevoPartido; // Creamos un nuevo partido y seteamos todos los valores
                nuevoPartido.nombreEquipo = nombresEquipo[conteoEquipos];
                nuevoPartido.nombreEquipo2 = nombresEquipo[conteoEquipos2];
                nuevoPartido.puntuacion = rand() % 100; // Puntuaciones random, fuera amigismos.
                nuevoPartido.puntuacion2 = rand() % 100;
                totalPartidos.push_back(nuevoPartido); // Introducimos un nuevo partido al vector.
            }
        }
    };

    for (int partidoIndividual = 0; totalPartidos.size(); partidoIndividual++) // Printeamos todos los partidos con sus diferentes resultados.
    {
        cout << "\n\n";
        cout << totalPartidos[partidoIndividual].nombreEquipo + " vs " + totalPartidos[partidoIndividual].nombreEquipo2;
        cout << "\n|" + totalPartidos[partidoIndividual].puntuacion + " | " + totalPartidos[partidoIndividual].puntuacion2;
    }
}