#include "EstructurasAdicionales/Resultado.h"
#include "Function/Funciones.h"

int main() {
    Resultado arr[] = {
        // {"Lima    ", 10},
        // {"Cusco   ", 20},
        // {"Arequipa", 30},
        // {"Trujillo", 40},
        // {"Piura   ", 50}

        // {"Puno",     15}

        {"Lima   ", 34},
        {"Cusco  ", 12},
        {"Arequipa", 67},
        {"Trujillo", 8},
        {"Piura  ", 45},
        {"Iquitos", 23},
        {"Tacna  ", 89},
        {"Puno   ", 5}
    };

    int size = sizeof(arr)/sizeof(arr[0]);
    int D1 = 10;
    int D2 = 45;

    mergesort(arr,0,size-1);

    cout<<"Ciudades ordenadas por distancia"<<endl;
    imprimirCiudadesAll(arr,size);

    cout<<"Ingrese rango inferior(D1) y superior(D2)"<<endl;
    cout<<"Ingrese limite inferior: ";
    cin>>D1;
    cout<<"Ingrese limite superior: ";
    cin>>D2;

    cout<<"Ciudades entre "<< D1 <<" km y "<< D2 <<" km"<<endl;
    imprimirCiudades(arr,0,size-1,D1,D2);

    return 0;
}

// {"Puno",     15}
//
//
//

// {"Lima   ", 34},
// {"Cusco  ", 12},
// {"Arequipa", 67},
// {"Trujillo", 8 },
// {"Piura  ", 45},
// {"Iquitos", 23},
// {"Tacna  ", 89},
// {"Puno   ", 5 }

