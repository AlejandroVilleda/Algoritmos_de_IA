#include "Busqueda_amplitud_str.h"

// MÉTODOS PRINCIPALES
// Métodos getters: retornan valores
string Nodo_str:: get_Datos()
{
    return this-> Datos;
}

vector<Nodo_str *> Nodo_str:: get_Hijos()
{
    return this-> Hijos;
}

Nodo_str * Nodo_str:: get_Padre()
{
    return this-> Padre;
}

float Nodo_str:: get_Costo() const
{
    return this->Costo;
}

// Métodos setters: asignan valores
void Nodo_str::  set_Datos(string Dato_nuevo)
{
    this-> Datos = Dato_nuevo;
}

void Nodo_str:: set_Hijos(vector<Nodo_str *> Hijos_nuevos)
{
    this-> Hijos = Hijos_nuevos;

// Asignamos el valor del padre
    if(!this-> Hijos.empty())
    {
        for(Nodo_str *Iterador: Hijos_nuevos)
            Iterador-> Padre = this;
    }
}

void Nodo_str:: set_Padre(Nodo_str *Nuevo_padre)
{
    this-> Padre = Nuevo_padre;
}

void Nodo_str:: set_Costo(float Nuevo_costo)
{
    this-> Costo = Nuevo_costo;
}

// MÉTODOS SECUNDARIOS
bool Nodo_str:: Igual(Nodo_str Nodo_str)
{
    if(this-> get_Datos() == Nodo_str.get_Datos()){return true;}
    else{return false;}
}

bool Nodo_str:: En_lista(queue<Nodo_str *> Lista_nodos)
{
    bool En_la_lista;

    // Compara cada lista de nodos
    for(int i = 0; i < Lista_nodos.size(); i++)
    {
        if(this-> Igual(*Lista_nodos.front())) En_la_lista = true;
        Lista_nodos.pop();
    }

    return En_la_lista;
}
