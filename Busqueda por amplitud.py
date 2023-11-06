""" Busqueda por amplitud o por anchura - Breadth First Search (BFS)"""
from Arbol import Nodo

# Ejecución del algoritmo de amplitud
def Buscar_solucion_Amplitud(Estado_inicial, Solucion):
    """ Halla la solución por el algoritmo de amplitud """

    Solucionado = False
    Nodos_visitados = []
    Nodos_frontera = []

    NodoInicial = Nodo(Estado_inicial)
    Nodos_frontera.append(NodoInicial)

    while (not Solucionado) and (len(Nodos_frontera) != 0):
        nodo = Nodos_frontera.pop(0)

        # Extraer datos y añadirlo a visitados
        Nodos_visitados.append(nodo)

        if nodo.Datos == Solucion:
            # Solución encontrada
            Solucionado = True
            return nodo

        else:
            # Expandir nodo hijo
            dato_nodo = nodo.Datos

            # Operador izquierdo
            Hijo = [dato_nodo[1], dato_nodo[0], dato_nodo[2], dato_nodo[3]]
            HijoIzquierdo = Nodo(Hijo)
            if not HijoIzquierdo.En_lista(Nodos_visitados) and not HijoIzquierdo.En_lista(Nodos_frontera):
                Nodos_frontera.append(HijoIzquierdo)

            # Operador central
            Hijo = [dato_nodo[0], dato_nodo[2], dato_nodo[1], dato_nodo[3]]
            HijoCentral = Nodo(Hijo)
            if not HijoCentral.En_lista(Nodos_visitados) and not HijoCentral.En_lista(Nodos_frontera):
                Nodos_frontera.append(HijoCentral)

            # Operador derecho
            Hijo = [dato_nodo[0], dato_nodo[1], dato_nodo[3], dato_nodo[2]]
            HijoDerecho = Nodo(Hijo)
            if not HijoDerecho.En_lista(Nodos_visitados) and not HijoDerecho.En_lista(Nodos_frontera):
                Nodos_frontera.append(HijoDerecho)

        nodo.set_hijos([HijoIzquierdo, HijoCentral, HijoDerecho])


# Ejecución del algoritmo de amplitud
def Buscar_solucion_Amplitud_2(Conexion, Estado_inicial, Solucion):
    """ Halla la solución por el algoritmo de amplitud """

    Solucionado = False
    Nodos_visitados = []
    Nodos_frontera = []
    NodoInicial = Nodo(Estado_inicial)
    Nodos_frontera.append(NodoInicial)

    while (not Solucionado) and (len(Nodos_frontera) != 0):
        nodo = Nodos_frontera[0]

        # Extraer datos y añadirlo a visitados
        Nodos_visitados.append(Nodos_frontera.pop(0))

        if nodo.Datos == Solucion:
            # Solución encontrada
            Solucionado = True
            return nodo

        else:
            # Expandir nodo hijo (ciudades con conexión)
            dato_nodo = nodo.Datos
            Lista_hijos = []

            for un_hijo in Conexion[dato_nodo]:
                hijo = Nodo(un_hijo)
                Lista_hijos.append(hijo)

                if not hijo.En_lista(Nodos_visitados) and not hijo.En_lista(Nodos_frontera):
                    Nodos_frontera.append(hijo)

            nodo.set_hijos(Lista_hijos)


# Ejecuta el algoritmo del programa
def Buscar_lista_ordenada():
    Estado_inicial = [4, 2, 3, 1]
    # Estado_inicial = [3, 1, 2, 4]
    Solucion = [1, 2, 3, 4]
    Resultado = []

    Nodo_solucion = Buscar_solucion_Amplitud(Estado_inicial, Solucion)

    #Mostrando solución
    nodo = Nodo_solucion

    while nodo.Padre != None:
        Resultado.append(nodo.Datos)
        nodo = nodo.Padre

    Resultado.append(Estado_inicial)
    Resultado.reverse()

    print(Resultado)


def Buscar_ciudad():
    Conexiones = {
        'Malaga': {'Salamanca', 'Madrid', 'Barcelona'},
        'Sevilla': {'Santiago', 'Madrid'},
        'Granada': {'Valencia'},
        'Valencia': {'Barcelona'},
        'Madrid': {'Salamanca', 'Sevilla', 'Malaga', 'Barcelona', 'Santander'},
        'Salamanca': {'Malaga', 'Madrid'},
        'Santiago': {'Sevilla', 'Santander', 'Barcelona'},
        'Santander': {'Santiago', 'Madrid'},
        'Zaragoza': {'Barcelona'},
        'Barcelona': {'Zaragoza', 'Santiago', 'Madrid', 'Malaga', 'Valencia'}
    }

    Estado_inicial = 'Malaga'
    Solucion = 'Santiago'
    Resultado = []

    Nodo_solucion = Buscar_solucion_Amplitud_2(Conexiones, Estado_inicial, Solucion)

    #Mostrando solución
    nodo = Nodo_solucion

    while nodo.Padre != None:
        Resultado.append(nodo.Datos)
        nodo = nodo.Padre

    Resultado.append(Estado_inicial)
    Resultado.reverse()

    print(Resultado)


if __name__ == "__main__":
    """ Ejecución del código """

    Buscar_lista_ordenada()
    # Buscar_ciudad()