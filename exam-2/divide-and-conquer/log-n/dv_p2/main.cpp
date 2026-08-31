#include "Funciones.h"

int main() {

    int arr[]={1,1,1,0,0,0,0};
    int size = sizeof(arr)/sizeof(arr[0]);

    int posZero = -1;

    resolver(arr, 0,size-1,posZero);

    cout<<"Output: "<<(posZero>=0?size-posZero:0)<<endl;

    return 0;
}
