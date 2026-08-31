#include "Funciones.h"
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"

int main() {
    //VALORES DEL ELEMENTO
    int cantidades[7][4] = {
        {100, 100, 100, 98},
        {103, 102, 100, 96},
        {100, 102, 102, 93},
        {101, 92, 100, 99},
        {100, 99, 100, 100},
        {99, 100, 101, 102},
        {100, 98, 100, 95}
    };

    ArbolBinarioBusqueda ABBDiaTurno{};
    construir(ABBDiaTurno);

    ArbolBinarioBusqueda ABBCantidad{};
    construir(ABBCantidad);

    insertadiaturno(ABBDiaTurno,cantidades);
    insertaCantidad(ABBCantidad,cantidades);


    recorrerEnOrden(ABBDiaTurno); cout<<endl;
    cout << "El arbol dia turno es arbol equilibrado "<< esEquilibrado(ABBDiaTurno) << endl;

    recorrerEnOrden(ABBCantidad); cout<<endl;
    cout << "El arbol cantidad es arbol equilibrado "<< esEquilibrado(ABBCantidad) << endl;


    return 0;
}



























