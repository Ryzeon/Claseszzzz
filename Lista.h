#pragma once

#include <functional>

using namespace std;

typedef unsigned int uint;

template <typename T, T NADA = 0>
class Lista
{
    struct Nodo; // Prototipo de la clase nodo, la cual se implementa después
    typedef function<int(T, T)> Comp;

    Nodo* ini;
    uint lon;      // número de elementos en la lista
    Comp comparar; // lambda de criterio de comparación
public:
    Lista() : ini(nullptr), lon(0), comparar([](T a, T b)
        { return a - b; }) {}
    Lista(Comp comparar) : ini(nullptr), lon(0), comparar(comparar) {}


    ~Lista()
    {
        Nodo* aux = ini;
        while (aux != nullptr)
        {
            aux = ini;
            ini = ini->sig;
            delete aux;
        }
    }

    uint longitud()
    {
        return lon;
    }

    bool esVacia()
    {
        return lon < 1;
    }

    void agregaPos(T elem, uint pos)
    {
        if (pos > lon)
            return;
        if (pos == 0)
        {
            agregaInicial(elem);
        }
        else
        {
            Nodo* aux = ini;
            for (int i = 1; i < pos; i++)
            {
                aux = aux->sig;
            }
            Nodo* nuevo = new Nodo(elem, aux->sig);
            if (nuevo != nullptr)
            {
                aux->sig = nuevo;
                lon++;
            }
        }
    }

    void agregaInicial(T elem)
    {
        Nodo* nuevo = new Nodo(elem, ini);
        if (nuevo != nullptr)
        {
            ini = nuevo;
            lon++;
        }
    }

    void agregaFinal(T elem)
    {
        agregaPos(elem, lon);
    }
    void modificarInicial(T elem)
    {
        if (lon > 0)
        {
            ini->elem = elem;
        }
    }
    void modificarPos(T elem, uint pos)
    {
        if (pos >= 0 && pos < lon)
        {
            Nodo* aux = ini;
            for (int i = 0; i < pos; i++)
            {
                aux = aux->sig;
            }
            aux->elem = elem;
        }
    }
    void modificarFinal(T elem)
    {
        modificar(elem, lon - 1);
    }
    void eliminaInicial()
    {
        if (lon > 0)
        {
            Nodo* aux = ini;
            ini = ini->sig;
            delete aux;
            lon--;
        }
    }
    void eliminaPos(uint pos) {
        Nodo* aux = ini;
        for (int i = 1; i < pos; i++) {
            aux = aux->sig;
        }
        Nodo* aux2 = aux->sig;
        aux->sig = aux2->sig;
        delete aux2;
        lon--;
    }
    void eliminaFinal() {
        eliminaPos(lon - 1);
    }
    T obtenerInicial()
    {
        return obtenerPos(0);
    }
    T obtenerPos(uint pos)
    {
        if (pos >= 0 && pos < lon)
        {
            Nodo* aux = ini;
            for (int i = 0; i < pos; i++)
            {
                aux = aux->sig;
            }
            return aux->elem;
        }
        else
        {
            return NADA;
        }
    }
    T obtenerFinal()
    {
        return obtenerPos(lon - 1);
    }
    T buscar(T elem)
    {
        Nodo* aux = ini;
        while (aux != nullptr)
        {
            if (comparar(aux->elem, elem) == 0)
            {
                return aux->elem;
            }
            aux = aux->sig;
        }
        return NADA;
    }


    void imprimir() {
        Nodo* aux = ini;
        while (aux != nullptr) {
            cout << aux->elem << " ";
            aux = aux->sig;
        }
        cout << endl;
    }
};
template <typename T, T NADA>
struct Lista<T, NADA>::Nodo {
    T       elem;
    Nodo* sig; // puntero apunta al siguiente nodo

    Nodo(T elem = NADA, Nodo* sig = nullptr) : elem(elem), sig(sig) {}
};
