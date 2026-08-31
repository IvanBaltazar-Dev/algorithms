#include "Funciones.h"

Resultado resolver(char *arr,int inicio, int fin) {
    Resultado result{};

    if (inicio == fin) {
        result.datos[0].valor = arr[inicio];
        result.datos[0].cantidad = 1;
        result.n = 1;
        return result;
    }

    int mitad = inicio + (fin - inicio)/2;

    Resultado izq = resolver(arr,inicio,mitad);
    Resultado der = resolver(arr,mitad+1,fin);

    return combinar(izq,der);
}

Resultado combinar(Resultado izq, Resultado der) {
    Resultado result{};
    result.n = 0;

    int i=0; //
    int j=0;

    while ( i<izq.n && j<der.n) {
        //TRES CASOS
        if (izq.datos[i].valor == der.datos[j].valor) {
            result.datos[result.n].valor = izq.datos[i].valor;
            result.datos[result.n].cantidad = izq.datos[i].cantidad + der.datos[j].cantidad;

            i++;
            j++;

            result.n++;
        }

        else if (izq.datos[i].valor < der.datos[j].valor) {
            result.datos[result.n] = izq.datos[i];

            i++;
            result.n++;
        }
        else {
            result.datos[result.n] = der.datos[j];

            j++;
            result.n++;
        }
    }

    while (i < izq.n) {
        result.datos[result.n] = izq.datos[i];

        i++;
        result.n++;
    }

    while (j < der.n) {
        result.datos[result.n] = der.datos[j];

        j++;
        result.n++;
    }
    return result;
}

void imprimirConteos(Resultado resultado) {
    for (int i = 0; i < resultado.n; i++) {
        cout<<resultado.datos[i].valor<<" "<<resultado.datos[i].cantidad<<endl;
    }
    cout<<endl;
}

Conteo conteoMayor(Resultado resultado) {
    Conteo mayor = resultado.datos[0];

    for (int i = 0; i < resultado.n; i++) {
        if (resultado.datos[i].cantidad > mayor.cantidad) {
            mayor = resultado.datos[i];
        }
    }

    return mayor;
}