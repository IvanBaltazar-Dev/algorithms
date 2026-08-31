#include "FuncionesAuxiliares/Funciones.h"

int main() {
    char almacen[]={'A','F','B','F','F','C','C','F'};
    int size = sizeof(almacen)/sizeof(almacen[0]);

    Datos resultado = mergesort(almacen,0,size-1);

    Conteo poloMayor = encontrarMayor(resultado);

    cout<<"Solucion:"<<endl;
    cout<<"Polos con mas unidades: "<<poloMayor.caracter<<endl;
    cout<<"Cantiadd de polo: "<<poloMayor.cantidad<<endl;


    return 0;
}
