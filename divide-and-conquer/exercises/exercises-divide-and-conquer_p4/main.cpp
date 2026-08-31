#include "Funciones.h"

int main() {

    int arr[N]={-2, -5, 6, -2, -3, 1, 5, -6};

    int iniMax = -1;
    int finMax = -1;
    int result = sumaMaxima(arr,0,N-1, iniMax, finMax);

    cout<<"Salida: "<<result;
    cout<<" (Los elementos que suman el maximo son ";
    for (int i=iniMax;i<=finMax;i++) {
        if (i != iniMax) {
            cout<<", ";
        }
        cout<<arr[i];
    }
    cout<<")"<<endl;
    return 0;
}
