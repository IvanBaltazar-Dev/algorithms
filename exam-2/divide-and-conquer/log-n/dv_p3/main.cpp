#include <iostream>
#include "Funciones.h"

using namespace std;
int main() {
    int arr[]={5, 6, 1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);

    int result = resolver(arr, 0, size-1);

    cout<<result<<endl;

    return 0;
}
