#include <cstdlib>
#include <iostream>
#include <cmath>
#include <stdbool.h>
//Espacio de nombres para utilizar el cout<< y cin>>
using namespace std;
//Clase hora

class dateTime
{
private:
public:
    int dia;
    int mes;
    int year;
    string returnFechaFormateada();
};
class tarea
{
private:
public:
    string nombre = "";
    dateTime fechaEntrega;  
    string encargado = ""; 
    //Constructores
    //Métodos de la clase
};

string dateTime::returnFechaFormateada()
{
    string diaS = to_string(dia);
    string mesS = to_string(mes);
    string yearS = to_string(year);
    return diaS + "/" + mesS + "/" + yearS;
}

int main(int argc, char *argv[])
{
    int maxTareas = 0;
    int createdTareas = 0;
    int subMenuEdit = 0;
    bool found = false;
    cout << "Introduce el tamano maximo de tareas\n";
    cin >> maxTareas;
    tarea tareaVacia;
    tarea totalTareas[maxTareas] = {};
    int optionMenu = 0;
    string helper = "";
    bool menuActive = true;
    system("cls");
    tarea nuevaTarea;
    while (menuActive)
    {
        cout << "1.- Crear Tarea\n";
        cout << "2.- Borrar Tarea\n";
        cout << "3.- Editar Tarea\n";
        cout << "4.- Ver todas las tareas\n";
        cout << "0.- Salir\n";
        cin >> optionMenu;
        switch (optionMenu)
        {
        case 1:
            cout << "Introduce el nombre de la Tarea\n";
            cin >> nuevaTarea.nombre;
            cout << "Introduce el encargado de la Tarea\n";
            cin >> nuevaTarea.encargado;
            cout << "Introduce el dia de la fecha de entrega\n";
            cin >> nuevaTarea.fechaEntrega.dia;
            cout << "Introduce el mes de la fecha de entrega\n";
            cin >> nuevaTarea.fechaEntrega.mes;
            cout << "Introduce el ano de la fecha de entrega\n";
            cin >> nuevaTarea.fechaEntrega.year;
            createdTareas++;
            system("cls");
            break;
        case 2: // Borrar tareas
            if (createdTareas > 0)
            {
                found = false;
                helper = "";
                cout << "\nIntroduce el nombre de la tarea a borrar\n";
                cin >> helper;
                for (int i = 0; createdTareas; i++)
                {
                    if (totalTareas[i].nombre == helper)
                    {
                        found = true;
                        totalTareas[i] = tareaVacia;
                        tarea *totalTareas = new tarea[i];
                        createdTareas--;
                        system("cls");
                        cout << "\nTarea encotrada y borrada.\n";
                        break;
                    }
                }
                if (!found)
                {
                    cout << "\nNo encontrada tarea con ese nombre\n";
                }
            }
            else
            {
                cout << "\nNo hay ninguna tarea creada\n";
            }
            break;
        case 3:
            if (createdTareas > 0)
            {
                helper = "";
                cout << "\nIntroduce el nombre de la tarea a editar\n";
                cin >> helper;
                for (int i = 0; createdTareas; i++)
                {
                    if (totalTareas[i].nombre == helper)
                    {
                        subMenuEdit = 0;
                        cin >> subMenuEdit;
                        cout << "\n 1.- Modificar Nombre";
                        cout << "\n 2.- Modificar Encargado";
                        cout << "\n 3.- Modificar Tarea";
                        switch (subMenuEdit)
                        {
                        case 1:
                            cout << "Introduce el nombre de la Tarea\n";
                            cin >> totalTareas[i].nombre;
                            break;
                        case 2:
                            cout << "Introduce el encargado de la Tarea\n";
                            cin >> totalTareas[i].encargado;
                            break;
                        case 3:
                            cout << "Introduce el dia de la fecha de entrega\n";
                            cin >> totalTareas[i].fechaEntrega.dia;
                            cout << "Introduce el mes de la fecha de entrega\n";
                            cin >> totalTareas[i].fechaEntrega.mes;
                            cout << "Introduce el ano de la fecha de entrega\n";
                            cin >> totalTareas[i].fechaEntrega.year;
                            break;
                        case 0:
                            break;
                        default:
                            cout << "\n Valor Incorrecto\n";
                            break;
                        }
                    }
                    break;
                }
            }
            else
            {
                cout << "\nNo hay ninguna tarea creada\n";
            }
            break;
        case 4: // Ordena por fecha.
        for (int i = 0; maxTareas; i++)
            {
                cout << "\nTAREA Nº" + to_string(i);
                cout << "\nNombre de la Tarea: " + totalTareas[i].nombre;
                cout << "\nEncargado: " + totalTareas[i].encargado;
                cout << "\nFecha de Entrega: " + totalTareas[i].fechaEntrega.returnFechaFormateada();
            }
            break;
        case 0:
            menuActive = false;
            break;
        default:
            cout << "Opcion Invalida";
        }
    }
}