#include <iostream>
using namespace std;

struct nodo
{
    float valor;
    nodo *siguiente = NULL;
    nodo *anterior = NULL;
};

nodo *inicio;
nodo *final = NULL;

void Mostrar()
{
    nodo *aux = inicio;
    if (inicio == NULL)
    {
        cout << endl << "Su lista esta vacia." << endl;
    }
    else
    {
        cout << endl << "Su lista es: ";
        cout << aux -> valor;
        aux = aux -> siguiente;

        while (aux != inicio)
        {
            cout << " -> " << aux -> valor;
            aux = aux -> siguiente;
        }
        cout << endl;
    }
}
void InsertarInicio(int value)
{
    nodo *aux = new nodo;
    if(inicio == NULL)
    {
        aux -> valor = value;
        aux -> siguiente = aux;
        aux -> anterior = aux;
        inicio = aux;
        final = aux;
    }
    else
    {
        inicio -> anterior = aux;
        aux -> valor = value;
        aux -> siguiente = inicio;
        aux -> anterior = NULL;
        inicio = aux;
        final -> siguiente = inicio;
        inicio -> anterior = final;
    }
    cout << endl << "Elemento anadido correctamente." << endl;
}
void InsertarFinal(int value)
{
    if(final == NULL)
    {
        nodo *aux = new nodo;
        aux -> valor = value;
        final = aux;
        inicio = aux;
    }
    else
    {
        nodo *aux= new nodo;
        final -> siguiente = aux;
        aux -> valor = value;
        aux -> siguiente = NULL;
        aux -> anterior = final;
        final = aux;
        final -> siguiente = inicio;
        inicio -> anterior = final;
    }
    cout << endl << "Elemento anadido correctamente." << endl;
}
void InsertarElegida(int position, int value)
{
    nodo *aux = inicio;
    nodo *predecesor = new nodo;
    predecesor -> siguiente = aux;

    for (int i = 0; i < position - 1; i++)
    {
        predecesor = predecesor -> siguiente;
        aux = aux -> siguiente;
        if (aux == inicio)
        {
            i = position;
            cout << "La lista es demasiado corta y no alcanza la posicion solicitada." << endl;
            cout << "El nuevo elemento se ha anadido en la ultima posicion." << endl;
        }
    }
    aux = new nodo;
    aux -> siguiente = predecesor -> siguiente;
    aux -> anterior = predecesor;
    predecesor -> siguiente = aux;
    aux -> valor = value;
    aux = aux -> siguiente;
    aux -> anterior = predecesor -> siguiente;
    if (aux -> siguiente == inicio) { final = aux; }

    cout << endl << "Elemento anadido correctamente." << endl;
}
void HallarMayor()
{
    nodo *aux = inicio;
    float mayor = -99999;
    int i = 0;
    if (inicio == NULL) { cout << endl << "La lista esta vacia." << endl; }
    else
    {
        do
        {
            if (aux -> valor > mayor)
            {
                mayor = aux -> valor;
                i = 1;
            }
            else if (aux -> valor == mayor) { i++; }
            aux = aux -> siguiente;
        } while (aux != inicio);
        cout << endl << "El mayor elemento es " << mayor << " y se ha encontrado " << i << " ve";
        if (i == 1) { cout << "z." << endl; } else { cout << "ces." << endl; }
    }
}
void SumarTodo()
{
    nodo *aux = inicio;
    float sumatorio = 0;
    if (inicio == NULL) { cout << endl << "La lista esta vacia." << endl; }
    else
    {
        do
        {
            sumatorio += aux -> valor;
            aux = aux -> siguiente;
        } while (aux != inicio);
        cout << endl << "La suma de todos los elementos es " << sumatorio << endl;
    }
}
void ComprobarOrdenada()
{
    if (inicio == NULL) { cout << endl << "La lista esta vacia." << endl; }
    else
    {
        string ordenada = "SI";
        nodo *aux = inicio -> siguiente;
        do
        {
            if (aux -> valor < aux -> anterior -> valor)
            {
                ordenada = "NO";
                aux = final;
            }
            aux = aux -> siguiente;
        } while (aux != inicio);

        cout << endl << "La lista " << ordenada << " esta ordenada" << endl;
    }
}
void EliminarUno(nodo *aux)
{
    aux -> anterior -> siguiente = aux -> siguiente;
    aux -> siguiente -> anterior = aux -> anterior;
    if (aux == inicio) { inicio = aux -> siguiente; }
    else if (aux == final) { final = aux -> anterior; }
    aux -> valor = NULL;
}
void EliminarIterativo(int value)
{
    nodo *aux = inicio;
    int i;
    if (inicio == NULL) { cout << endl << "Su lista esta vacia." << endl; }
    else if (inicio == final)
    {
        delete aux;
        aux = NULL;
        inicio = NULL;
        final = NULL;
    }
    else
    {
        do
        {
            i = 0;
            do
            {
                if (aux -> valor == value)
                {
                    EliminarUno(aux);
                    i++;
                }
                else
                {
                    aux = aux -> siguiente;
                }
            } while (aux != inicio);
        } while (i != 0);
        cout << endl << "Se han eliminado todos los " << value << endl;
    }
}
void EliminarRecursivo(nodo *aux, nodo *actual, float value)
{
    if (aux -> siguiente != inicio)
    {
        cout << endl << "aux es " << aux -> valor << " y actual es " << actual -> valor << ". Voy a recursivizar";
        EliminarRecursivo(aux -> siguiente, actual, value);
    }
    if (actual -> valor = value)
    {
        cout << endl << "Voy a eliminar " << actual -> valor;
        EliminarUno(actual);
        actual = actual -> anterior;
    }
    actual = actual -> anterior;
    Mostrar();
}
void Invertir()
{
    nodo *aux = final;
    nodo *sig;
    do
    {
        sig = aux -> siguiente;
        aux -> siguiente = aux -> anterior;
        aux -> anterior = sig;
        aux = aux -> siguiente;
    } while (aux != final);
    inicio = inicio -> siguiente;
    final = final -> siguiente;

    cout << endl << "Lista invertida correctamente" << endl;
}
void Intercambiar(int pos1, int pos2)
{
    nodo *aux1 = inicio, *aux2 = inicio, *aux3 = inicio;
    for (int i = 1; i < pos1; i++)
    {
        aux1 = aux1 -> siguiente;
    }
    aux1 -> anterior -> siguiente = aux1 -> siguiente;
    aux1 -> siguiente -> anterior = aux1 -> anterior;
    cout << "aux1 = " << aux1 -> valor << endl;
    for (int i = 1; i < pos2 - 1; i++)
    {
        aux2 = aux2 -> siguiente;
    }
    aux2 -> anterior -> siguiente = aux2 -> siguiente;
    aux2 -> siguiente -> anterior = aux2 -> anterior;
    cout << "aux2 = " << aux2 -> valor << endl;
    for (int i = 1; i <= pos2; i++)
    {
        if (i == pos1 - 1)
        {
            aux2 -> siguiente = aux3 -> siguiente;
            aux2 -> anterior = aux3;
            aux3 -> siguiente -> anterior = aux2;
            aux3 -> siguiente = aux2;
        }
        else if (i == pos2 - 1)
        {
            aux1 -> siguiente = aux3 -> siguiente;
            aux1 -> anterior = aux3;
            aux3 -> siguiente -> anterior = aux1;
            aux3 -> siguiente = aux1;
        }
        aux3 = aux3 -> siguiente;
    }
}
int main()
{
    float value = 0;
    int eleccion;
    do
    {
        cout << endl << "o o o o o o o o o o MENU o o o o o o o o o o" << endl;
        cout << "[1]  Mostrar la lista" << endl;                         // Funciona bien
        cout << "[2]  Insertar nodo al principio" << endl;               // Funciona bien
        cout << "[3]  Insertar nodo al final" << endl;
        // Si lo unico que hago es añadir un nodo al final, y despues mostrar, la funcion Mostrar() se atasca
        cout << "[4]  Insertar nodo en la posicion elegida" << endl;     // Funciona bien
        cout << "[5]  Hallar el valor mayor" << endl;                    // Funciona bien
        cout << "[6]  Mostrar la suma todos los nodos" << endl;          // Funciona bien
        cout << "[7]  Comprobar si la lista esta ordenada" << endl;      // Funciona bien
        cout << "[8]  Eliminar valor elegido y sus iguales" << endl;     // Iterativa bien. Recursiva mal
        cout << "[9]  Invertir la lista" << endl;                        // Funciona bien
        cout << "[10] Intercambiar 2 elementos elegidos" << endl;
        // Bien, salvo cuando quiero cambiar el 1º o el ultimo nodo
        cout << "[0]  SALIR" << endl;                                    // Funciona bien
        cout << "o o o o o o o o o o o o o o o o o o o o o o" << endl;
        cout << "INGRESE SU ELECCION: ";
        cin >> eleccion;

        switch (eleccion)
        {
            case 0: break;
            case 1: Mostrar(); break;
            case 2:
                cout << "Indique el valor del nuevo elemento: ";
                cin >> value;
                InsertarInicio(value);
                break;
            case 3:
                cout << "Indique el valor del nuevo elemento: ";
                cin >> value;
                InsertarFinal(value);
                break;
            case 4:
                int posicion;
                cout << "Indique la posicion en la que desea almacenar el valor: ";
                cin >> posicion;
                cout << "Indique el valor del nuevo elemento: ";
                cin >> value;
                if (posicion == 1) { InsertarInicio(value); }
                else { InsertarElegida(posicion, value); }
                break;
            case 5: HallarMayor(); break;
            case 6: SumarTodo(); break;
            case 7: ComprobarOrdenada(); break;
            case 8:
                int forma;
                cout << "Indique el valor que desea eliminar: ";
                cin >> value;
                cout << "Quieres eliminar de forma iterativa (0) o recursiva (1)? ";
                cin >> forma;
                if (forma == 0) { EliminarIterativo(value); }
                else if (forma == 1)
                {
                    EliminarRecursivo(inicio, final, value);
                }
                else { cout << "El valor insertado no se acepta. Prueba otra vez." << endl; }
                break;
            case 9: Invertir(); break;
            case 10:
                int pos1, pos2;
                cout << "Indique la posicion del primer elemento a cambiar: ";
                cin >> pos1;
                cout << "Indique la posicion del segundo elemento a cambiar: ";
                cin >> pos2;
                Intercambiar(pos1, pos2);
                break;
            default:
                cout << "El dato introducido no es valido, intentelo de nuevo" << endl << endl;
                break;
        }
    } while(eleccion != 0);
    cout << endl << "Acaba de abandonar el programa. Saludos.";
}