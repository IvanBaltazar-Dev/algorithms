#include "EstructurasAuxiliares/Resultado.h"
#include "FuncionesAuxiliares/Funciones.h"

int main() {
    Resultado datos[]={{40, 6},
        {50, -4},
        {60, -9},
        {70, 0},
        {80, 7},
        {90, -1},
        {100, 4},
        {10, -3},
        {20, 1},
        {30, 4}};
    int size = sizeof(datos)/sizeof(datos[0]);

    int result = resolverRotacion(datos, 0,size-1);

    cout<<"Posicion inicial original: "<<result<<endl;

    mergesort(datos,0,size-1);

    int resultado = conteo(datos,0,size-1);

    cout<<"Máxima acumulación de riesgo en un intervalo continuo: "<<resultado<<endl;

    return 0;
}










