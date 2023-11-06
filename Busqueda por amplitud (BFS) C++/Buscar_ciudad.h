#ifndef BFS_BUSCAR_CIUDAD_H
#define BFS_BUSCAR_CIUDAD_H
#include "Busqueda_amplitud_str.h"
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;


// Ejecución del algoritmo de amplitud
Nodo_str *Buscar_solucion_Amplitud_2(map<string, vector<string>> Conexiones, string Estado_inicial, string Solucion)
{

/* Halla la solución por el algoritmo de amplitud */
    bool Solucionado = false;
    queue<Nodo_str *> Nodos_visitados;
    queue<Nodo_str *> Nodos_frontera;
    vector<string> Hijo;
    Nodo_str *nodo;

    auto *NodoInicial = new Nodo_str(Estado_inicial);
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
            // Expandir nodo hijo (ciudades con conexión)
            string dato_nodo = nodo-> get_Datos();
            vector<Nodo_str *> Lista_hijos;

            for (auto un_hijo: Conexiones[dato_nodo])
            {
                Nodo_str *hijo = new Nodo_str(un_hijo);
                Lista_hijos.push_back(hijo);

                if (!hijo-> En_lista(Nodos_visitados) && !hijo-> En_lista(Nodos_frontera))
                {
                    Nodos_frontera.push(hijo);
                }
            }
            nodo-> set_Hijos(Lista_hijos);
        }
    }

    return nodo;
}

// Ejecuta el algoritmo del programa
void Buscar_ciudad()
{
    typedef pair<string, vector<string>> Par;
    map<string, vector<string>> Conexiones =
    {
        {"Malaga", {"Salamanca", "Madrid", "Barcelona"}},
        {"Sevilla", {"Santiago", "Madrid"}},
        {"Granada", {"Valencia"}},
        {"Valencia", {"Barcelona"}},
        {"Madrid", {"Salamanca", "Sevilla", "Malaga", "Barcelona", "Santander"}},
        {"Salamanca", {"Malaga", "Madrid"}},
        {"Santiago", {"Sevilla", "Santander", "Barcelona"}},
        {"Santander", {"Santiago", "Madrid"}},
        {"Zaragoza", {"Barcelona"}},
        {"Barcelona", {"Zaragoza", "Santiago", "Madrid", "Malaga", "Valencia"}}
    };

    string Estado_inicial = "Malaga";
    string Solucion = "Santiago";
    vector<string> Resultado;
    Nodo_str *Nodo_solucion;
    Nodo_str *nodo;

    Nodo_solucion = Buscar_solucion_Amplitud_2(Conexiones, Estado_inicial, Solucion);

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
            cout<< Valor;
        }

        cout<< "], ";
    }
    cout<< "]"<< endl;
}




#endif //BFS_BUSCAR_CIUDAD_H
