#include "FuncionesAuxiliares/Funciones.h"

int main() {
    char almacen[]={'A','F','B','F','F','C','C','F'};

    int size = sizeof(almacen)/sizeof(almacen[0]);

    Resultado conteos = mergesort(almacen, 0, size-1);

    Conteo resultado = mayor(conteos);

    cout<<"Solucion:"<<endl;
    cout<<"Polos con mas unidades: "<<resultado.polo<<endl;
    cout<<"Cantidad de polo: "<<resultado.cantidad<<endl;

    return 0;
}
