#include <iostream>
#include <conio.h>
#include "Lista.h"

using namespace std;

int opcion()
{
    system("cls");
    cout << "0. Agregar" << endl;
    cout << "1. Agregar al inicio" << endl;
    cout << "2. Agregar al final" << endl;
    cout << "3. Agregar en posicion" << endl;
    cout << "4. Eliminar al inicio" << endl;
    cout << "5. Eliminar al final" << endl;
    cout << "6. Eliminar en posicion" << endl;
    cout << "7. Obtener al inicio" << endl;
    cout << "8. Obtener al final" << endl;
    cout << "9. Obtener en posicion" << endl;
    cout << "10. Longitud" << endl;
    cout << "11. Es vacia" << endl;
    cout << "12. Imprimir" << endl;
    cout << "13. Salir" << endl;
    cout << "Opcion: ";
    int op;
    do
    {
        cin >> op;
    } while (op < -1 || op > 13);
    return op;
}

int main() {
    Lista<int> lista;
    int op, elem, pos;
    while (true)
    {
        op = opcion();
        if (op == 13)
            break;
        switch (op)
        {
        case 0:
            cout << "Elemento: ";
            cin >> elem;
            lista.agregaPos(elem, lista.longitud());
            break;
        case 1:
            cout << "Elemento: ";
            cin >> elem;
            lista.agregaInicial(elem);
            break;
        case 2:
            cout << "Elemento: ";
            cin >> elem;
            lista.agregaFinal(elem);
            break;
        case 3:
            cout << "Elemento: ";
            cin >> elem;
            cout << "Posicion: ";
            cin >> pos;
            lista.agregaPos(elem, pos);
            break;
        case 4:
            lista.eliminaInicial();
            break;
        case 5:
            lista.eliminaFinal();
            break;
        case 6:
            cout << "Posicion: ";
            cin >> pos;
            lista.eliminaPos(pos);
            break;
        case 7:
            cout << "Elemento: " << lista.obtenerInicial() << endl;
            system("pause");
            break;
        case 8:
            cout << "Elemento: " << lista.obtenerFinal() << endl;
            system("pause");
            break;
        case 9:

            cout << "Posicion: ";
            cin >> pos;
            cout << "Elemento: " << lista.obtenerPos(pos) << endl;
            system("pause");
            break;
        case 10:
            cout << "Longitud: " << lista.longitud() << endl;
            system("pause");
            break;
        case 11:
            cout << "Es vacia: " << (lista.esVacia() ? "Si" : "No") << endl;
            system("pause");
            break;
        case 12:
            lista.imprimir();
            system("pause");
            break;
        }
    }
    _getch();
    return 0;
}