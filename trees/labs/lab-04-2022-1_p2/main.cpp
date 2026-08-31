#include "Funciones.h"

int main() {

    ArbolBinarioBusqueda ABB{};
    construir(ABB);

    int matrix[][2]={
        {20220815, 40},
        {20220710, 50},
        {20220720, 50},
        {20220630, 50},
        {20220624, 40},
        {20220615, 40},
        {20220618, 40},
        {20220930, 30}
    };
    int size = sizeof(matrix)/sizeof(matrix[0]);
    cargarDatos(ABB,matrix);

    recorrerPreOrden(ABB); cout << endl;
    int cant = 0;
    cout << "Ingrese la cantidad de solicitudes de despacho: ";
    cin>>cant;
    for (int i = 0; i < cant; i++) {
        int cantidad = 0;
        cout << "Ingrese la cantidad de unidades para el despacho "<<i+1<<": ";
        cin>>cantidad;

        int result = despachar(ABB,cantidad);

        if (result > 0) {
            cout << "No se ha logrado despachar "<< result << " unidades."<<endl;
        }else {
            cout<< "La representación, en preorden, del árbol de lotes de productos luego del despacho "<<i+1<<" es: "<<endl;
            recorrerPreOrden(ABB); cout << endl;
        }
    }

    return 0;
}
