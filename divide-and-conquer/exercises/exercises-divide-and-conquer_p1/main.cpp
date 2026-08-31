#include "Funciones.h"

int main() {

    int arr[]={1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};
    int size = sizeof(arr)/sizeof(arr[0]);

    int result = resuelve(arr,0,size-1);

    cout<<"Salida: "<<result<<endl;
    return 0;
}