#include <iostream>
using namespace std;
//Planear una funcion recursiva de la funcion matemactica de la suma de los n primeros numeros naturales, donde n es un numero entero positivo.
int suma(int n) {
    if (n <= 0) {
        return 0;
    }
    return n + suma(n - 1);
}

int main() {
    int n = 5;
    cout << suma(5);
}
