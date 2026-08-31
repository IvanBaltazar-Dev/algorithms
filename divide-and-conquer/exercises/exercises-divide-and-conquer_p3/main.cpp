#include <iostream>

#include "Funciones.h"

int main() {
    int arr[]={5,6,1,2,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    int valueMin = resolver(arr, 0, size-1);;

    cout << valueMin << endl;
    return 0;
}
