#include <iostream>
#include "Lista.h"

using namespace std;

int main() {
    Lista<int> lista;
    lista.agregaPos(1, 0);
    lista.agregaPos(2, 1);
    lista.agregaPos(3, 2);
    lista.agregaPos(4, 3);

    lista.agregaInicial(10);

    lista.agregaFinal(20);

    cout << "Longitud: " << lista.longitud() << endl;
    cout << "Es vacia: " << lista.esVacia() << endl;
    cout << "Primer elemento: " << lista.obtenerInicial() << endl;
    cout << "Ultimo elemento: " << lista.obtenerFinal() << endl;
    lista.imprimir();
    return 0;
}