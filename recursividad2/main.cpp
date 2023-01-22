#include <iostream>

using namespace std;

int sumadigitos(int n) {
    if (n < 10) {
        return n;
    } else {
        return n % 10 + sumadigitos(n / 10);
    }
}
int sumadigitositerativo(int n) {
    int suma = 0;
    while (n > 0) {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}
int main() {
    int n;

    cout << "Ingrese un numero: ";
    cin >> n;

    cout << "La suma de sus digitos recursiva  es: " << sumadigitos(n) << std::endl;
    cout << "La suma de sus digitos iterativa es: " << sumadigitositerativo(n) << std::endl;

}
