#include "FuncionesAuxiliares/Funciones.h"

int main() {
    Resultado datos[]{
        {40, 6, 0},
        {50, -4, 1},
        {60, -9, 2},
        {70, 0, 3},
        {80, 7, 4},
        {90, -1, 5},
        {100, 4, 6},
        {10, -3, 7},
        {20, 1, 8},
        {30, 4, 9}
    };
    int size = sizeof(datos)/sizeof(datos[0]);

    mergesort(datos,0,size-1);
        cout<<"Posicion inicial original: "<<datos[0].posRotada<<endl;

    // int index_rot = resolver(datos,0,size-1);
    // cout<<"Posicion inicial original: "<<index_rot<<endl;

    Acumulacion result = maximoRiesgo(datos,0,size-1);
    cout<<"Maxima acumulacion de riesgo en un intervalo continuo: "<<result.suma<<endl;
    cout<<"Durante los id's: ";
    bool esPrimero = true;
    for(int i=result.inicio;i<=result.fin;i++) {
        if(!esPrimero) {
            cout<<", ";
        }
        esPrimero = false;
        cout<<datos[i].idActividad;
    }
    cout<<endl;

    return 0;
}



// {50,  4  },
// {60,  -1 },
// {70,  3  },
// {80,  -2 }
// {10,  -4 },
// {20,  5  },
// {30,  1  },
// {40,  -2 },


// {{80, -4,0}, {90, -2,1}, {10, 1,2}, {20, -3,3}, {30, 6,4}, {40, -8,5}, {50, 5,6}, {60, 2,7}, {70, -1,8}};



