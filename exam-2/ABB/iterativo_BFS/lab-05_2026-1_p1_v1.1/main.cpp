#include "Functions/Funciones.h"

using namespace std;

int main() {
    ArbolBinarioBusqueda ABB{};
    construir(ABB);

    int arr[]={9,4,1,6,14,11,16,19};
    int size = sizeof(arr)/sizeof(arr[0]);

    cargarElementos(ABB,arr,size);
    recorrerPreOrden(ABB); cout<<endl;

    zigZagOrder(ABB);
    cout<<endl;


    return 0;
}
