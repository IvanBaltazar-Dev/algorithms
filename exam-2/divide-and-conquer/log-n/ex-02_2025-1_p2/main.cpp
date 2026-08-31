#include "Funciones.h"

int main() {
    int arr[]={300, 350, 400, 450, 500, 550, 600, 650, 100, 145, 190, 235, 280};
    int size=sizeof(arr)/sizeof(arr[0]);

    int index_rot = resolver_rot(arr,0,size-1);

    int codigo = -1;
    int index_busqueda = -1;
    cout << "Ingrese el codigo de alerta a buscar: ";
    cin >> codigo;

    if (index_rot == 0) {
        index_busqueda = busquedaBinaria(arr,0,size-1,codigo);
    }else if (codigo >= arr[index_rot] && codigo <= arr[size-1]) {
        //PUEDE ESTAR EN EL SUB ARREGLO ROTADO
        index_busqueda = busquedaBinaria(arr,index_rot,size-1,codigo);
    }else {
        index_busqueda = busquedaBinaria(arr,0,index_rot-1,codigo);
    }

    if (index_busqueda == -1) {
        cout<<"Codigo de alerta "<<codigo<<" no encontrado."<<endl;
    }else {
        cout<<"Codigo de alerta "<<codigo<<" encontrado en la posicion "<<index_busqueda+1<<endl;
    }


    return 0;
}
