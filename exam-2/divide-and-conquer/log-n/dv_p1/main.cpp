#include "Funciones.h"

int main() {
    int arr[]={1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};

    int size = sizeof(arr)/sizeof(arr[0]);

    int result = resolverParidad(arr, 0, size-1);

    if (result >= 0) {
        cout<<"Salida: "<<arr[result]<<endl;
    }else {
        cout<<"Todos tienen par"<<endl;
    }

    return 0;
}
