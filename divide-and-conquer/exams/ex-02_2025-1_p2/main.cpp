#include "Funciones.h"

int main() {
    int arr[]={300, 350, 400, 450, 500, 550, 600, 650, 100, 145, 190, 235, 280};
    int size=sizeof(arr)/sizeof(arr[0]);

    int codigo = -1;
    cout<<"Ingrese el codigo de alerta a buscar: "<<endl;
    cin>>codigo;
    int result = -1;

    resuelve(arr, 0, size-1,codigo,result);

    if (result != -1) {
        cout<<"Codigo de alerta "<< codigo <<" encontrado en la posicion: " << result+1 << endl;
    }else {
        cout<<"Codigo de alerta "<< codigo <<" no encontrado."<<endl;
    }
    return 0;
}
