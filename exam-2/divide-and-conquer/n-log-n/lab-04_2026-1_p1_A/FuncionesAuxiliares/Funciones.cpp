//
// Created by Ivan Piero Baltazar on 8/07/2026.
//

#include "Funciones.h"

#include <algorithm>

Resultado mergesort(char almacen[],int inicio, int fin) {
    if (inicio == fin) {
        Resultado res{};
        res.n = 1;

        res.datos[0].polo = almacen[inicio];
        res.datos[0].cantidad = 1;
        return res;
    }

    int mitad = inicio + (fin - inicio)/2;

    Resultado izq = mergesort(almacen,inicio, mitad);
        Resultado der = mergesort(almacen,mitad+1, fin);

    return merge(izq,der);
}


Resultado merge(Resultado izquierda, Resultado derecha) {
    Resultado res{};
    res.n = 0;

    int i = 0;
    int j = 0;

    while (i < izquierda.n && j < derecha.n ) {
        //TRES CASOS
        //CASO 1: SE REPITE EL MISMO POLO
        if (izquierda.datos[i].polo == derecha.datos[j].polo) {
            res.datos[res.n].polo = izquierda.datos[i].polo;
            res.datos[res.n].cantidad = izquierda.datos[i].cantidad + derecha.datos[j].cantidad;
            i++;
            j++;
            res.n++;
        }else if (izquierda.datos[i].polo < derecha.datos[j].polo) {
            //CASO 2: POLO IZQUIERDA MENOR
            res.datos[res.n].polo = izquierda.datos[i].polo;
            res.datos[res.n].cantidad = izquierda.datos[i].cantidad;
            i++;
            res.n++;
        }else {
            //CASO 3: POLO DERECHO MENOR
            res.datos[res.n].polo = derecha.datos[j].polo;
            res.datos[res.n].cantidad = derecha.datos[j].cantidad;
            j++;
            res.n++;
        }
    }
    while (i < izquierda.n) {
        res.datos[res.n].polo = izquierda.datos[i].polo;
        res.datos[res.n].cantidad = izquierda.datos[i].cantidad;
        i++;
        res.n++;
    }
    while (j < derecha.n) {
        res.datos[res.n].polo = derecha.datos[j].polo;
        res.datos[res.n].cantidad = derecha.datos[j].cantidad;
        j++;
        res.n++;
    }

    return res;
}

Conteo mayor(Resultado conteos) {
    Conteo resultado = conteos.datos[0];

    for (int i = 1; i < conteos.n; i++) {
        if (conteos.datos[i].cantidad > resultado.cantidad) {
            resultado = conteos.datos[i];
        }
    }
    return resultado;
}