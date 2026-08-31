#include "FuncionesAuxiliares/Funciones.h"

int main() {
    int arr[]={-2, -5, 6, -2, -3, 1, 5, -6};
    int size = sizeof(arr)/sizeof(arr[0]);

    Resultado resultado = mergesort(arr,0,size-1);

    cout<<"Salida: "<<resultado.suma;
    cout<<" (Los elementos que suman el maximo son ";
    bool esPrimero=true;
    for (int i = resultado.inicio; i <= resultado.fin; i++) {
        if (!esPrimero)
            cout<<", ";
        esPrimero=false;
        cout<<arr[i];
    }
    cout<<")"<<endl;

    return 0;
}
