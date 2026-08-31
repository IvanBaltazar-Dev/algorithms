#include "Funciones.h"

using namespace std;

int main() {

    int arr[]={1,1,1,0,0,0,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    int posPrimerZero = -1;
    encuentraZero(arr,0,size-1,posPrimerZero);
    if (posPrimerZero != -1) {
        cout<<size-posPrimerZero<<endl;
    }else {
        cout<<0<<endl;
    }
    return 0;
}
