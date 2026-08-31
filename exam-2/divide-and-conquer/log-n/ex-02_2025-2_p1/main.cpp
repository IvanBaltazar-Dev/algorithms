#include "Funciones.h"

using namespace std;

int main() {
    int arr[]={98, 95, 93, 90, 72, 60, 55, 50};
    int size = sizeof(arr)/sizeof(arr[0]);

    int T = 40;

    int index = -1;

    resolver(arr, 0, size-1, T,index);

    if (index >= 0) {
        cout<<"Primera zona con caries clinica detectada en la posicion "<<index<<" (Recuerde que la posicion inicia en 0)"<<endl;
        cout<<"Densidad Registrada: "<<arr[index]<<endl;
    }else {
        cout<<"No se detecta caries clinica"<<endl;
    }

    return 0;
}
