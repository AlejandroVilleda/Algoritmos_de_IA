#ifndef BUSCAR_LISTA_ORDENADA
#define BUSCAR_LISTA_ORDENADA
#include "Busqueda_amplitud.h"
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

// Ejecución del algoritmo de amplitud
Nodo *Buscar_solucion_Amplitud(vector<int> Estado_inicial, vector<int> const &Solucion)
{

/* Halla la solución por el algoritmo de amplitud */
    bool Solucionado = false;
    queue<Nodo *> Nodos_visitados;
    queue<Nodo *> Nodos_frontera;
    vector<int> Hijo;
    Nodo *nodo;

    auto *NodoInicial = new Nodo(Estado_inicial);
    Nodos_frontera.push(NodoInicial);

    while((!Solucionado) && (!Nodos_frontera.empty()))
    {
        nodo = Nodos_frontera.front();
        Nodos_frontera.pop();

        // Extraer datos y añadirlo a visitados
        Nodos_visitados.push(nodo);

        if(nodo-> get_Datos() == Solucion)
        {
            // Solución encontrada
            Solucionado = true;
        }

        else
        {
            // Expandir nodo hijo
            vector<int> dato_nodo = nodo-> get_Datos();

            // Operador izquierdo
            Hijo = {dato_nodo[1], dato_nodo[0], dato_nodo[2], dato_nodo[3]};
            auto HijoIzquierdo = new Nodo(Hijo);
            if((!HijoIzquierdo-> En_lista(Nodos_visitados)) && (!HijoIzquierdo-> En_lista(Nodos_frontera)))
            {
                Nodos_frontera.push(HijoIzquierdo);
            }

            // Operador central
            Hijo = {dato_nodo[0], dato_nodo[2], dato_nodo[1], dato_nodo[3]};
            auto HijoCentral = new Nodo(Hijo);
            if((!HijoCentral-> En_lista(Nodos_visitados)) && (!HijoCentral-> En_lista(Nodos_frontera)))
            {
                Nodos_frontera.push(HijoCentral);
            }

            // Operador derecho
            Hijo = {dato_nodo[0], dato_nodo[1], dato_nodo[3], dato_nodo[2]};
            auto HijoDerecho = new Nodo(Hijo);
            if((!HijoDerecho-> En_lista(Nodos_visitados)) && (!HijoDerecho-> En_lista(Nodos_frontera)))
            {
                Nodos_frontera.push(HijoDerecho);
            }

            // vector<Nodo<int>> Hijos_nuevos = {HijoIzquierdo, HijoCentral, HijoDerecho};
            nodo-> set_Hijos(vector<Nodo *> {HijoIzquierdo, HijoCentral, HijoDerecho});
        }
    }

    return nodo;
}


// Ejecución del algoritmo de amplitud
Nodo *Buscar_solucion_Amplitud_2(vector<int> Estado_inicial, vector<int> const &Solucion)
{

/* Halla la solución por el algoritmo de amplitud */
    bool Solucionado = false;
    queue<Nodo *> Nodos_visitados;
    queue<Nodo *> Nodos_frontera;
    vector<int> Hijo;
    Nodo *nodo;

    auto *NodoInicial = new Nodo(Estado_inicial);
    Nodos_frontera.push(NodoInicial);

    while((!Solucionado) && (!Nodos_frontera.empty()))
    {
        nodo = Nodos_frontera.front();
        Nodos_frontera.pop();

        // Extraer datos y añadirlo a visitados
        Nodos_visitados.push(nodo);

        if(nodo-> get_Datos() == Solucion)
        {
            // Solución encontrada
            Solucionado = true;
        }

        else
        {
            // Expandir nodo hijo
            vector<int> dato_nodo = nodo-> get_Datos();

            // Operador izquierdo
            Hijo = {dato_nodo[1], dato_nodo[0], dato_nodo[2], dato_nodo[3]};
            auto HijoIzquierdo = new Nodo(Hijo);
            if((!HijoIzquierdo-> En_lista(Nodos_visitados)) && (!HijoIzquierdo-> En_lista(Nodos_frontera)))
            {
                Nodos_frontera.push(HijoIzquierdo);
            }

            // Operador central
            Hijo = {dato_nodo[0], dato_nodo[2], dato_nodo[1], dato_nodo[3]};
            auto HijoCentral = new Nodo(Hijo);
            if((!HijoCentral-> En_lista(Nodos_visitados)) && (!HijoCentral-> En_lista(Nodos_frontera)))
            {
                Nodos_frontera.push(HijoCentral);
            }

            // Operador derecho
            Hijo = {dato_nodo[0], dato_nodo[1], dato_nodo[3], dato_nodo[2]};
            auto HijoDerecho = new Nodo(Hijo);
            if((!HijoDerecho-> En_lista(Nodos_visitados)) && (!HijoDerecho-> En_lista(Nodos_frontera)))
            {
                Nodos_frontera.push(HijoDerecho);
            }

            // vector<Nodo<int>> Hijos_nuevos = {HijoIzquierdo, HijoCentral, HijoDerecho};
            nodo-> set_Hijos(vector<Nodo *> {HijoIzquierdo, HijoCentral, HijoDerecho});
        }
    }

    return nodo;
}



// Ejecuta el algoritmo del programa
void Buscar_lista_ordenada()
{
    vector<int> Estado_inicial = {4, 2, 3, 1};
    // vector<int> Estado_inicial = {3, 1, 2, 4};
    vector<int> Solucion = {1, 2, 3, 4};
    vector<vector<int>> Resultado;
    Nodo *Nodo_solucion;
    Nodo *nodo;

    Nodo_solucion = Buscar_solucion_Amplitud(Estado_inicial, Solucion);

    // Mostrando solución
    nodo = Nodo_solucion;

    while( nodo-> get_Padre() != nullptr)
    {
        Resultado.push_back(nodo-> get_Datos());
        nodo = nodo-> get_Padre();
    }

    Resultado.push_back(Estado_inicial);
    reverse(Resultado.begin(), Resultado.end());

    cout<< "[";
    for(auto const& Vector: Resultado)
    {
        cout<< "[";
        for(auto const& Valor: Vector)
        {
            cout<< Valor<< ",";
        }

        cout<< "], ";
    }
    cout<< "]"<< endl;
}


// Ejecuta el algoritmo del programa
void Buscar_ciudad()
{
    vector<int> Estado_inicial = {4, 2, 3, 1};
    // vector<int> Estado_inicial = {3, 1, 2, 4};
    vector<int> Solucion = {1, 2, 3, 4};
    vector<vector<int>> Resultado;
    Nodo *Nodo_solucion;
    Nodo *nodo;

    Nodo_solucion = Buscar_solucion_Amplitud(Estado_inicial, Solucion);

    // Mostrando solución
    nodo = Nodo_solucion;

    while( nodo-> get_Padre() != nullptr)
    {
        Resultado.push_back(nodo-> get_Datos());
        nodo = nodo-> get_Padre();
    }

    Resultado.push_back(Estado_inicial);
    reverse(Resultado.begin(), Resultado.end());

    cout<< "[";
    for(auto const& Vector: Resultado)
    {
        cout<< "[";
        for(auto const& Valor: Vector)
        {
            cout<< Valor<< ",";
        }

        cout<< "], ";
    }
    cout<< "]"<< endl;
}

#endif







