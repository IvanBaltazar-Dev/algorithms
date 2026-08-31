#include "Funciones/Funciones.h"

int main() {
    int arr[]={-2, -5, 6, -2, -3, 1, 5, -6};
    int size = sizeof(arr)/sizeof(arr[0]);

    Resultado res = mergeSort(arr, 0, size-1);

    cout<<"Salida: ";
    cout<<res.suma;
    cout<<" (Los elementos que suman el maximo son ";
    bool primerElemento = true;
    for (int i=res.inicio; i <= res.fin; i++) {
        if (!primerElemento) {
            cout<<", ";
        }
        primerElemento = false;
        cout<<arr[i];
    }
    cout<<")"<<endl;

    return 0;
}
