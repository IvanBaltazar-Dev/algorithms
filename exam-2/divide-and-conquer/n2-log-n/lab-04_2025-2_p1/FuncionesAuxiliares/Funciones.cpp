//
// Created by Ivan Piero Baltazar on 9/07/2026.
//

#include "Funciones.h"

Resultado mergesort(string mutaciones[],int inicio,int fin) {
    if(inicio>=fin) {
        Resultado result{};
        result.datos[0].nombre = mutaciones[inicio];
        result.datos[0].cantidad = 1;
        result.n = 1;
        return result;
    }
    int mitad = inicio + (fin-inicio)/2;

    Resultado izquierda = mergesort(mutaciones,inicio,mitad);
    Resultado derecha = mergesort(mutaciones,mitad+1,fin);

    return merge(izquierda,derecha);
}

Resultado merge(Resultado izquierda,Resultado derecha){
    Resultado result{};
    result.n = 0;

    int i = 0; //Izquierda
    int j = 0; //Derecha

    while (i < izquierda.n && j < derecha.n) {
        if (izquierda.datos[i].nombre == derecha.datos[j].nombre) {
            result.datos[result.n].nombre = izquierda.datos[i].nombre;
            result.datos[result.n].cantidad = izquierda.datos[i].cantidad + derecha.datos[j].cantidad;
            result.n++;

            i++;
            j++;
        }else if (izquierda.datos[i].nombre < derecha.datos[j].nombre) {
            result.datos[result.n].nombre = izquierda.datos[i].nombre;
            result.datos[result.n].cantidad = izquierda.datos[i].cantidad;
            result.n++;

            i++;
        }else {
            result.datos[result.n].nombre = derecha.datos[j].nombre;
            result.datos[result.n].cantidad = derecha.datos[j].cantidad;
            result.n++;

            j++;
        }
    }
    while (i < izquierda.n) {
        result.datos[result.n].nombre = izquierda.datos[i].nombre;
        result.datos[result.n].cantidad = izquierda.datos[i].cantidad;
        result.n++;
        i++;
    }
    while (j < derecha.n) {
        result.datos[result.n].nombre = derecha.datos[j].nombre;
        result.datos[result.n].cantidad = derecha.datos[j].cantidad;
        result.n++;
        j++;
    }

    return result;
}

string encontrarFaltante(string fila[],int size) {
    string datos[N]{};
    int cantDatos = 0;
    for (int i = 0; i < N; i++) {
        if (!fila[i].empty()){
            datos[cantDatos] = fila[i];
            cantDatos++;
        }
    }


    Resultado result = mergesort(datos,0,cantDatos-1);


    for (int i = 0; i < result.n; i++) {
        if (result.datos[i].cantidad % 2 != 0) {
            return result.datos[i].nombre;
        }
    }

    return "Sin faltante";
}