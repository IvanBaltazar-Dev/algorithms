#include "FuncionesAuxiliares/Funciones.h"


int main() {
    Resultado resultado[]={{10},{12},{14},{13},{11},{15}};
    int size=sizeof(resultado)/sizeof(resultado[0]);

    int result = mergesort(resultado,0,size-1);

    cout<<"Existen "<<result<<" pares anomalos."<<endl;
    return 0;
}
