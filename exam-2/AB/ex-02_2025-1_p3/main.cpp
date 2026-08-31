#include "Funciones.h"
#include <fstream>
int main() {

    ArbolBinarioBusqueda arbol;
    construir(arbol);

    ifstream archivo("datos.txt",ios::in);
    
    crearArbolSQL(arbol, archivo);
    imprimirArbolSQL(arbol);
    verificaArbolSQL(arbol);


    return 0;
}
