""" Busqueda por profundidad recursiva - Depth First Search (BFS) """
from Arbol import Nodo


# Ejecución del algoritmo de profundidad recursiva
def Buscar_solucion_Profundidad_Recursiva(Nodo_inicial: Nodo, Solucion, Visitados: list):
    """ Halla la solución por el algoritmo de profundidad recursiva """

    Visitados.append(Nodo_inicial.Datos)
    if Nodo_inicial.Datos == Solucion:
        return Nodo_inicial

    else:
        # Expandir nodos sucesores (hijos)
        dato_nodo = Nodo_inicial.Datos
        hijoIzq = Nodo([dato_nodo[1], dato_nodo[0], dato_nodo[2], dato_nodo[3]])
        hijoCen = Nodo([dato_nodo[0], dato_nodo[2], dato_nodo[1], dato_nodo[3]])
        hijoDer = Nodo([dato_nodo[0], dato_nodo[1], dato_nodo[3], dato_nodo[2]])

        Nodo_inicial.set_hijos([hijoIzq, hijoCen, hijoDer])

        for Nodo_hijo in Nodo_inicial.get_hijos():
            if not Nodo_hijo.Datos in Visitados:

                # Llamada recursiva
                Sol = Buscar_solucion_Profundidad_Recursiva(Nodo_hijo, Solucion, Visitados)
                if Sol != None:
                    return Sol

        return None


# Ejecuta el algoritmo del programa
def Buscar_lista_ordenada():
    # Estado_inicial = [3, 1, 2, 4]
    Estado_inicial = [4, 2, 3, 1]
    Solucion = [1, 2, 3, 4]
    Visitados = []
    Resultado = []

    Nodo_inicial = Nodo(Estado_inicial)
    nodo: Nodo = Buscar_solucion_Profundidad_Recursiva(Nodo_inicial, Solucion, Visitados)

    # Mostrar resultado
    while nodo.Padre is not None:
        Resultado.append(nodo.Datos)
        nodo = nodo.Padre

    Resultado.append(Estado_inicial)
    Resultado.reverse()

    print(Resultado)


if __name__ == "__main__":
    """ Ejecución del código """
    Buscar_lista_ordenada()
