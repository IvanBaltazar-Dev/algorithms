#include "FuncionesAuxiliares/Funciones.h"
int main() {

    Resultado cuidades[]={{"Lima",      34},
{"Cusco",     12},
{"Arequipa",  67},
{"Trujillo",  8},
{"Piura",     45},
{"Iquitos",   23},
{"Tacna",     89},
{"Puno",      5 }};

    int size = sizeof(cuidades)/sizeof(cuidades[0]);

    mergesort(cuidades,0,size-1);

    cout<<"Cuidades ordenadas por distancia"<<endl;
    imprimirCuidadesAll(cuidades,size);

    return 0;
}

//ERRORES PUNTUALES
/*
 * copiar se copia iniciando en 0 ambos
 * for(int i = 0; i<n1; i++)
 *      izquierda[i]=cuidades[inicioIzq+i];
 * for(int j = 0; j<n2; j++)
 *      derecha[j]=cuidades[inicioDer+j];
 * NO OLVIDAR EL +i y +j
*/
// {"Lima",      34},
// {"Cusco",     12},
// {"Arequipa",  67},
// {"Trujillo",  8},
// {"Piura",     45},
// {"Iquitos",   23},
// {"Tacna",     89},
// {"Puno",      5 }
