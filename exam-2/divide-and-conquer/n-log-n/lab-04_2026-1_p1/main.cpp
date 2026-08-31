#include "Funciones.h"
#include "EstructurasAdicionales/Resultado.h"

int main() {
    char almacen[] = {'A','F','B','F','F','C','C','F'}
;
    int n = sizeof(almacen) / sizeof(almacen[0]);

    Resultado resultado = resolver(almacen,0,n-1);

    cout<<"Conteos encontrados: "<<endl;
    imprimirConteos(resultado);

    Conteo conteo = conteoMayor(resultado);

    cout<<endl;
    cout<<"Solucion:"<<endl;
    cout<<"Polos con mas unidades: "<<conteo.valor<<endl;
    cout<<"Cantidad de polo: "<<conteo.cantidad<<endl;

    return 0;
}
