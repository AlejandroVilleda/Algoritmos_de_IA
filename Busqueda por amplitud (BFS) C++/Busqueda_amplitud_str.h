#ifndef BFS_BUSQUEDA_AMPLITUD_STR_H
#define BFS_BUSQUEDA_AMPLITUD_STR_H
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Nodo_str
{
    /** Almacena el conjunto de datos **/

/// @ATRIBUTOS
    private:
        string Datos;
        vector<Nodo_str *> Hijos;
        Nodo_str *Padre = nullptr;
        float Costo{};

/// @MÉTODOS
    public:
        // Constructor
        Nodo_str(string Datos, vector<Nodo_str *> Hijos)
        {
            this-> Datos = std::move(Datos);
            this-> Hijos = std::move(Hijos);
        }

        explicit Nodo_str(string Datos)
        {
            this-> Datos = std::move(Datos);
        }

        // MÉTODOS PRINCIPALES
        // Métodos getters: retornan valores
        string get_Datos();
        vector<Nodo_str *> get_Hijos();
        Nodo_str *get_Padre();
        [[nodiscard]] float  get_Costo() const;

        // Métodos setters: asignan valores
        void set_Datos(string Dato_nuevo);
        void set_Hijos(vector<Nodo_str *> Hijos_nuevos);
        void set_Padre(Nodo_str *Nuevo_padre);
        void set_Costo(float Nuevo_costo);

        // MÉTODOS SECUNDARIOS
        bool Igual(Nodo_str Nodo_str);
        bool En_lista(queue<Nodo_str *> Lista_nodos);
};



#endif //BFS_BUSQUEDA_AMPLITUD_STR_H
