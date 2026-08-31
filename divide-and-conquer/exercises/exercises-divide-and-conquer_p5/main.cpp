#include "Funciones.h"

int main() {
    int arr[]={8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = resuelve(arr, 0,size-1);

    cout<<"Salida: "<<arr[result]<<endl;

    return 0;
}
