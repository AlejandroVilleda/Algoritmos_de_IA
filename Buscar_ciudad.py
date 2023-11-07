""" Búsqueda por profundidad iterativa - Depth First Search (BFS) """
from Arbol import Nodo


# Ejecución del algoritmo de búsqueda por profundidad iterariva
def Buscar_solucion_Profundidad_Iterativa(Nodo, Solucion, Conexiones):
    for Limite in range(0, 100):
        Visitados = []

        Sol = Buscar_solucion_Profundidad_Recursiva(Nodo, Solucion, Visitados, Limite, Conexiones)
        if Sol != None:
            return Sol


# Ejecución del algoritmo de búsqueda por profundidad recursiva
def Buscar_solucion_Profundidad_Recursiva(nodo, Solucion, Visitados, Limite, Conexiones):
    """ Halla la solución por el algoritmo de profundidad recursiva """

    if Limite > 0:
        Visitados.append(nodo)

        if nodo.Datos == Solucion:
            # Solución encontrada
            Solucionado = True
            return nodo

        else:
            # Expandir nodo hijo (ciudades con conexión)
            dato_nodo = nodo.Datos
            Lista_hijos = []

            for un_hijo in Conexiones[dato_nodo]:
                hijo = Nodo(un_hijo)
                Lista_hijos.append(hijo)

                if not hijo.En_lista(Visitados):
                    Lista_hijos.append(hijo)

            nodo.set_hijos(Lista_hijos)

            for Nodo_hijo in nodo.get_hijos():
                if not Nodo_hijo.Datos in Visitados:
                    # Llamada recursiva
                    Sol = Buscar_solucion_Profundidad_Recursiva(Nodo_hijo, Solucion, Visitados, Limite - 1, Conexiones)

                    if Sol != None:
                        return Sol

        return None


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
    Nodo_inicial = Nodo(Estado_inicial)
    nodo = Buscar_solucion_Profundidad_Iterativa(Nodo_inicial, Solucion, Conexiones)

    #Mostrando solución
    if nodo != None:

        while nodo.Padre is not None:
            Resultado.append(nodo.Datos)
            nodo = nodo.Padre

        Resultado.append(Estado_inicial)
        Resultado.reverse()
        print(Resultado)

    else: print("Solución no encontrada")


if __name__ == "__main__":
    """ Ejecución del código """

    Buscar_ciudad()