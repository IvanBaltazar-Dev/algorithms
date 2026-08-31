#include "Funciones.h"

int main() {
    int arr[]={0, -1, 0, -1, 0, 1, 1, 2, 2, 3, 2, 2, 1, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    int result = resuelveRadiacion(arr, 0, size-1);

    if (result == -1) {
        cout<<"No se encontro radiciacion"<<endl;
    }else {
        int potencia_maxima = buscarPotenciaMaxima(arr, 0, size-1);

        cout<<"El resultado sera: La radiacion empieza a "<<result<<" km.";
        cout<<"Potencia maxima "<<arr[potencia_maxima]<<" megatones";
    }

    return 0;
}
