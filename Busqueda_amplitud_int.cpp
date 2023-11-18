#include "Busqueda_amplitud_int.h"

// MÉTODOS PRINCIPALES
// Métodos getters: retornan valores
vector<int> Nodo:: get_Datos()
{
    return this-> Datos;
}

vector<Nodo *> Nodo:: get_Hijos()
{
    return this-> Hijos;
}

Nodo * Nodo:: get_Padre()
{
    return this-> Padre;
}

float Nodo:: get_Costo() const
{
    return this->Costo;
}

// Métodos setters: asignan valores
void Nodo::  set_Datos(vector<int> Dato_nuevo)
{
    this-> Datos = Dato_nuevo;
}

void Nodo:: set_Hijos(vector<Nodo *> Hijos_nuevos)
{
    this-> Hijos = Hijos_nuevos;

// Asignamos el valor del padre
    if(!this-> Hijos.empty())
    {
        for(Nodo *Iterador: Hijos_nuevos)
            Iterador-> Padre = this;
    }
}

void Nodo:: set_Padre(Nodo *Nuevo_padre)
{
    this-> Padre = Nuevo_padre;
}

void Nodo:: set_Costo(float Nuevo_costo)
{
    this-> Costo = Nuevo_costo;
}

// MÉTODOS SECUNDARIOS
bool Nodo:: Igual(Nodo nodo)
{
    if(this-> get_Datos() == nodo.get_Datos()){return true;}
    else{return false;}
}

bool Nodo:: En_lista(vector<Nodo *> Lista_nodos)
{
    bool En_la_lista;

    // Compara cada lista de nodos
    for(auto const &Vector: Lista_nodos)
    {
        if(this-> Igual(*Lista_nodos.front())) En_la_lista = true;
        Lista_nodos.erase(Lista_nodos.begin());
    }

    return En_la_lista;
}