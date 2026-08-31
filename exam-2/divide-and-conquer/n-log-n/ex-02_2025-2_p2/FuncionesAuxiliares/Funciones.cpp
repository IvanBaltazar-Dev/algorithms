//
// Created by Ivan Piero Baltazar on 8/07/2026.
//

#include "Funciones.h"

#include <algorithm>
#include <scoped_allocator>

void mergesort(Resultado datos[],int inicio,int fin) {
    if(inicio>=fin) return;

    int mitad = inicio + (fin - inicio)/2;

    mergesort(datos,inicio,mitad);
    mergesort(datos,mitad+1,fin);
    merge(datos,inicio,mitad,fin);
}

void merge(Resultado datos[],int inicio,int mitad,int fin) {
    int inicioIzq = inicio;
    int finIzq = mitad;

    int n1 = finIzq - inicioIzq + 1;
    Resultado izquierda[n1];
    for(int i=0;i<n1;i++) {
        izquierda[i] = datos[inicioIzq+i];
    }

    int inicioDer = mitad+1;
    int finDer = fin;

    int n2 = finDer - inicioDer + 1;
    Resultado derecha[n2];
    for(int j=0;j<n2;j++) {
        derecha[j] = datos[inicioDer+j];
    }

    int i = 0;
    int j = 0;
    //K inicia en INICIO
    int k = inicio;

    while (i < n1 && j < n2) {
        if (izquierda[i].idActividad <= derecha[j].idActividad) {
            //CASO 1: IZQUIERDA ES MENOR
            datos[k] = izquierda[i];
            i++;
            k++;
        }else {
            //CASO 2: DERECHA ES MENOR
            datos[k] = derecha[j];
            j++;
            k++;
        }
    }
    while (i < n1) {
        datos[k] = izquierda[i];
        i++;
        k++;
    }
    while (j < n2) {
        datos[k] = derecha[j];
        j++;
        k++;
    }

}

int resolver(Resultado datos[],int inicio,int fin) {
    if (inicio == fin) {
        return inicio;
    }

    int mitad = inicio + (fin - inicio)/2;

    if (datos[mitad].idActividad <= datos[fin].idActividad) {
        //ENCONTRAMOS O IZQUIERDA
        return resolver(datos,inicio,mitad);
    }else {
        return resolver(datos,mitad+1,fin);
    }
}

Acumulacion maximoRiesgo(Resultado datos[],int inicio,int fin) {
    if (inicio >= fin) {
        Acumulacion result{};
        result.suma = datos[inicio].riesgo;
        result.inicio = inicio;
        result.fin = fin;
        return result;
    }

    int mitad = inicio + (fin - inicio)/2;

    Acumulacion izquierda = maximoRiesgo(datos,inicio,mitad);
    Acumulacion derecha = maximoRiesgo(datos,mitad+1,fin);
    Acumulacion cruzado = maximoRiesgoMerge(datos,inicio,mitad,fin);

    return mayor(izquierda,derecha,cruzado);
}

Acumulacion mayor(Acumulacion izquierda,Acumulacion derecha,Acumulacion cruzado) {
    Acumulacion result = izquierda;
    if (result.suma < cruzado.suma) {
        result = cruzado;
    }
    if (result.suma < derecha.suma) {
        result = derecha;
    }
    return result;
}

Acumulacion maximoRiesgoMerge(Resultado datos[],int inicio,int mitad,int fin) {
    int sumaActual = 0;

    int inicioIzq = mitad;
    int finIzq = inicio;

    int indiceIzq = -1;
    int sumaIzq = INT_MIN;
    for (int i = inicioIzq; i >= finIzq; i--) {
        sumaActual += datos[i].riesgo;
        if (sumaActual > sumaIzq) {
            sumaIzq = sumaActual;
            indiceIzq = i;
        }
    }

    sumaActual = 0;
    int inicioDer = mitad+1;
    int finDer = fin;
    int sumaDer = INT_MIN;
    int indiceDer = -1;
    for (int i = inicioDer; i <= finDer; i++) {
        sumaActual += datos[i].riesgo;
        if (sumaActual > sumaDer) {
            sumaDer = sumaActual;
            indiceDer = i;
        }
    }

    Acumulacion result{};
    result.suma = sumaIzq+sumaDer;
    result.inicio = indiceIzq;
    result.fin = indiceDer;

    return result;
}