#include "Funciones.h"

int main() {

    int arr[]={98, 95, 93, 90, 72, 60, 55, 50};
    int size=sizeof(arr)/sizeof(arr[0]);

    int T = 80;

    int result = -1;
    resuelve(arr, 0 , size, T,result);

    if(result!=-1) {
        cout<<"Primera zona con caries clinica detectada en la posicion " << result
            <<" (Recuerde que la posicion inicia en 0)" << endl;
        cout<<"Densidad Registrada: "<<arr[result]<<endl;
    }else {
        cout<<"No se detecta caries clinica."<<endl;
    }

    return 0;
}
