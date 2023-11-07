""" Busqueda por profundidad - Depth First Search (BFS)"""
from Arbol import Nodo


# Ejecución del algoritmo de amplitud
def Buscar_solucion_Profundidad(Estado_inicial, Solucion):
    """ Halla la solución por el algoritmo de amplitud """

    Solucionado = False
    Nodos_visitados = []
    Nodos_frontera = []

    NodoInicial = Nodo(Estado_inicial)
    Nodos_frontera.append(NodoInicial)

    while (not Solucionado) and (len(Nodos_frontera) != 0):
        nodo = Nodos_frontera.pop()

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
            if (not HijoIzquierdo.En_lista(Nodos_visitados)) and (not HijoIzquierdo.En_lista(Nodos_frontera)):
                Nodos_frontera.append(HijoIzquierdo)

            # Operador central
            Hijo = [dato_nodo[0], dato_nodo[2], dato_nodo[1], dato_nodo[3]]
            HijoCentral = Nodo(Hijo)
            if (not HijoCentral.En_lista(Nodos_visitados)) and (not HijoCentral.En_lista(Nodos_frontera)):
                Nodos_frontera.append(HijoCentral)

            # Operador derecho
            Hijo = [dato_nodo[0], dato_nodo[1], dato_nodo[3], dato_nodo[2]]
            HijoDerecho = Nodo(Hijo)
            if (not HijoDerecho.En_lista(Nodos_visitados)) and (not HijoDerecho.En_lista(Nodos_frontera)):
                Nodos_frontera.append(HijoDerecho)

            nodo.set_hijos([HijoIzquierdo, HijoCentral, HijoDerecho])


# Ejecuta el algoritmo del programa
def Buscar_lista_ordenada():
    Estado_inicial = [4, 2, 3, 1]
    # Estado_inicial = [3, 1, 2, 4]
    Solucion = [1, 2, 3, 4]
    Resultado = []

    Nodo_solucion = Buscar_solucion_Profundidad(Estado_inicial, Solucion)

    # Mostrando solución
    nodo = Nodo_solucion

    while nodo.Padre is not None:
        Resultado.append(nodo.Datos)
        nodo = nodo.Padre

    Resultado.append(Estado_inicial)
    Resultado.reverse()

    print(Resultado)


if __name__ == "__main__":
    """ Ejecución del código """
    Buscar_lista_ordenada()
