#include <cstdlib>
#include <iostream>
#include <cmath>
#include <stdbool.h>
//Espacio de nombres para utilizar el cout<< y cin>>
using namespace std;
//Clase hora
class hora
{
private:
    int horas = 0;
    int minutos = 0;
    int segundos = 0; //Datos Privados de la clase
public:
    //Constructores
    //Métodos de la clase
    void visualizar();
    void setHoras(int horas);
    void setMinutos(int minutos);
    void setSegundos(int segundos);
    int getHoras();
    int getMinutos();
    int getSegundos();
    void sumar(hora h1, hora h2);
};

void hora::setHoras(int horasP)
{
    horas = horasP;
}

void hora::setMinutos(int minutosP)
{
    minutos = minutosP;
}

void hora::setSegundos(int segundosP)
{
    segundos = segundosP;
}

int hora::getHoras()
{
    return horas;
}

int hora::getMinutos()
{
    return minutos;
}

int hora::getSegundos()
{
    return segundos;
}

void hora::visualizar()
{
    int secs = 0;
    int mins = 0;
    int hours = 0;
    int rest = 0;
    int total = horas * 3600 + minutos * 60 + segundos;

    hours = floor((total / 3600) / 24);
    rest = total % 3600;
    mins = floor(rest / 60);
    rest = rest % 60;
    secs = rest;

    string secs2 = to_string(secs);
    string mins2 = to_string(mins);
    string hours2 = to_string(hours);

    if (hours < 10)
    {
        hours2 = "0" + to_string(hours);
    }
    if (mins < 10)
    {
        mins2 = "0" + to_string(mins);
    }
    if (secs < 10)
    {
        secs2 = "0" + to_string(secs);
    }
    cout << "\nHORA FINAL:";
    cout << hours2 + ":" + mins2 + ":" + secs2;
    cout << "\nHoras: " + to_string(horas);
    cout << "\nMinutos " + to_string(minutos);
    cout << "\nSegundos " + to_string(segundos);
}

void hora::sumar(hora h1, hora h2)
{
    horas = h1.horas + h2.horas;
    minutos = h1.minutos + h2.minutos;
    segundos = h1.segundos + h2.segundos;
    cout << "\n Sumados ambas horas";
    /*     cout << "\nHoras: " + to_string(horas);
    cout << "\nMinutos " + to_string(minutos);
    cout << "\nSegundos " + to_string(segundos); */
}

int main(int argc, char *argv[])
{
    int optionMenu = 0;
    int helper = 0;
    bool menuActive = true;
    hora opcion1;
    hora opcion20;
    hora opcion21;
    hora opcion22;
    while (menuActive)
    {
        cout << "\n 1.- Ver la suma de una hora 0 y una hora random";
        cout << "\n 2.- Introducir 2 horas y sumarlas\n";
        cin >> optionMenu;
        switch (optionMenu)
        {
        case 1:
            opcion1.setHoras(rand() % 100);
            opcion1.setMinutos(rand() % 100);
            opcion1.setSegundos(rand() % 100);
            system("cls");
            opcion1.visualizar();
            break;
        case 2:
            cout << "\nIntroduce las horas de la primera hora para la Suma:\n";
            cin >> helper;
            opcion21.setHoras(helper);
            cout << "\nIntroduce los minutos de la primera hora para la Suma:\n";
            cin >> helper;
            opcion21.setMinutos(helper);
            cout << "\nIntroduce los segundos de la primera hora para la Suma:\n";
            cin >> helper;
            opcion21.setSegundos(helper);
            system("cls");
            cout << "Primera Hora Introducida\n";

            cout << "\nIntroduce las horas de la segunda hora para la Suma:\n";
            cin >> helper;
            opcion22.setHoras(helper);
            cout << "\nIntroduce los minutos de la segunda hora para la Suma:\n";
            cin >> helper;
            opcion22.setMinutos(helper);
            cout << "\nIntroduce los segundos de la segunda hora para la Suma:\n";
            cin >> helper;
            opcion22.setSegundos(helper);
            system("cls");
            cout << "Segunda Hora Introducida\n";
            opcion20.sumar(opcion21, opcion22);
            opcion20.visualizar();
            break;
        case 0:
            menuActive = false;
            break;
        default:
            cout << "Opcion Invalida";
        }
    }
}