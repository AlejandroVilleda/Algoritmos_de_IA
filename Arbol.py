class Nodo:
    """ Almacena un conjunto de datos"""

# MÉTODO CONSTRUCTOR
    def __init__(self, Datos, Hijo=None):

    # ATRIBUTOS
        self._Datos = Datos
        self._Hijos = None
        self._Padre = None
        self._Coste = None
        #self.set_hijos(Hijo)

#  MÉTODO STR
    def __str__(self): return str(self._Datos)

# MÉTODOS PRINCIPALES
    # Métodos getters: retornan valores
    def get_hijos(self): return self._Hijos

    @property
    def Padre(self): return self._Padre

    @property
    def Datos(self): return self._Datos

    @property
    def Coste(self): return self._Padre

    # Metodos setters: Asignan valores
    def set_hijos(self, Hijos):
        self._Hijos = Hijos

        # Asignamos el valor del padre
        if self._Hijos != None:
            for hijo in self._Hijos:
                hijo._Padre = self

    @Padre.setter
    def Padre(self, Padre):  self._Padre = Padre

    @Datos.setter
    def Datos(self, Datos): self._Datos = Datos

    @Coste.setter
    def Coste(self, Coste):  self._Coste = Coste

# MÉTODOS SECUNDARIO
    # Devuelve True si el dato del nodo es igual al pasado como parametro
    def Igual(self, Nodo):
        if self._Datos == Nodo._Datos: return True
        else: return False

    # Devuelve True si el dato del nodo es igual a alguno en la lista de nodos
    def En_lista(self, Lista_nodos):
        En_la_lista = False

        # Compara cada lista de nodos
        for nodo in Lista_nodos:
            if self.Igual(nodo):
                En_la_lista = True
                return En_la_lista


# función principal
def main():
    """ Ejecuta el código implementado de forma unitaría """

    print("Funcion:", main.__name__)
    print("Documentación:", main.__doc__)

    Nuevo_nodo = Nodo([5])
    Nuevo_nodo2 = Nodo([2])
    Nuevo_nodo3 = Nodo([2])


    pass


# Prueba unitaria
if __name__ == "__main__":
    main()



