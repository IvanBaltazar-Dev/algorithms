//
// Created by Ivan Piero Baltazar on 10/07/2026.
//

#include "Funciones.h"

#include <algorithm>

Datos mergesort(char almacen[],int inicio,int fin) {
    if (inicio == fin) {
        Datos datos{};
        datos.conteo[0].caracter=almacen[inicio];
        datos.conteo[0].cantidad=1;
        datos.n = 1;
        return datos;
    }

    int mitad = inicio + (fin - inicio)/2;

    Datos izquierda = mergesort(almacen,inicio,mitad);
    Datos derecha = mergesort(almacen,mitad+1,fin);

    return merge(izquierda,derecha);
}

Datos merge(Datos izquierda,Datos derecha) {
    Datos datos{};
    datos.n=0;
    int i = 0;
    int j = 0;
    while (i < izquierda.n && j < derecha.n) {
        if (izquierda.conteo[i].caracter == derecha.conteo[j].caracter) {
            datos.conteo[datos.n].caracter = izquierda.conteo[i].caracter;
            datos.conteo[datos.n].cantidad = izquierda.conteo[i].cantidad + derecha.conteo[j].cantidad;
            i++;
            j++;
            datos.n++;
        }else if (izquierda.conteo[i].caracter < derecha.conteo[j].caracter) {
            datos.conteo[datos.n].caracter = izquierda.conteo[i].caracter;
            datos.conteo[datos.n].cantidad = izquierda.conteo[i].cantidad;
            i++;
            datos.n++;
        }else {
            datos.conteo[datos.n].caracter = derecha.conteo[j].caracter;
            datos.conteo[datos.n].cantidad = derecha.conteo[j].cantidad;
            j++;
            datos.n++;
        }
    }
    while (i < izquierda.n) {
        datos.conteo[datos.n].caracter = izquierda.conteo[i].caracter;
        datos.conteo[datos.n].cantidad = izquierda.conteo[i].cantidad;
        i++;
        datos.n++;
    }
    while (j < derecha.n) {
        datos.conteo[datos.n].caracter = derecha.conteo[j].caracter;
        datos.conteo[datos.n].cantidad = derecha.conteo[j].cantidad;
        j++;
        datos.n++;
    }

    return datos;
}

Conteo encontrarMayor(Datos resultado) {
    Conteo result{};
    for (int i = 0; i < resultado.n; i++) {
        if (result.cantidad <= resultado.conteo[i].cantidad) {
            result = resultado.conteo[i];
        }
    }
    return result;
}