#include <iostream>
#include "Funciones.h"
using namespace std;

int main() {

    int arr[]={8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    int result = resolver(arr,0,size-1);

    if (result > 0) {
        cout<<"El mayor valor es: "<<result<<endl;
    }

    return 0;
}
