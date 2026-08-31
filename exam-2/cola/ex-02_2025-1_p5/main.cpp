#include <iostream>
#include <ostream>

#include "Funciones.h"

#include "BibliotecaPila/Pila.h"

int main() {

    int arr[]={3, 1, 5, 3, 1, 0, 4};

    int size = sizeof(arr)/sizeof(arr[0]);

    Pila pila{};
    construir(pila);

    int cant_semillas = contadorSemillas(arr,size);

    cout<<"Cantidad maxima semillas: "<<cant_semillas<<endl;

    return 0;
}
