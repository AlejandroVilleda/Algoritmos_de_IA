#ifndef LIBRO_DE_IA_CLASE_BUSQUEDA_AMPLITUD_H
#define LIBRO_DE_IA_CLASE_BUSQUEDA_AMPLITUD_H
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Nodo
{
    /** Almacena el conjunto de datos **/

/// @ATRIBUTOS
    private:
        vector<int> Datos;
        vector<Nodo *> Hijos;
        Nodo *Padre = nullptr;
        float Costo{};

/// @MÉTODOS
    public:
        // Constructor
        Nodo(vector<int> Datos, vector<Nodo *> Hijos)
        {
            this-> Datos = std::move(Datos);
            this-> Hijos = std::move(Hijos);
        }

        explicit Nodo(vector<int> Datos)
        {
            this-> Datos = std::move(Datos);
        }

        // MÉTODOS PRINCIPALES
        // Métodos getters: retornan valores
        vector<int> get_Datos();
        vector<Nodo *> get_Hijos();
        Nodo *get_Padre();
        [[nodiscard]] float  get_Costo() const;

        // Métodos setters: asignan valores
        void  set_Datos(vector<int> Dato_nuevo);
        void set_Hijos(vector<Nodo *> Hijos_nuevos);
        void set_Padre(Nodo *Nuevo_padre);
        void set_Costo(float Nuevo_costo);

        // MÉTODOS SECUNDARIOS
        bool Igual(Nodo nodo);
        bool En_lista(queue<Nodo *> Lista_nodos);
    };

#endif