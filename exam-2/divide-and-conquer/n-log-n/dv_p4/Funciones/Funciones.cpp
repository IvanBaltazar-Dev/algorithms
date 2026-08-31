//
// Created by Ivan Piero Baltazar on 8/07/2026.
//

#include "Funciones.h"

#include <algorithm>

Resultado mergeSort(int arr[], int inicio,int fin) {
    if (inicio == fin) {
        Resultado res{};
        res.suma = arr[inicio];
        res.inicio = inicio;
        res.fin = fin;
        return res;
    }
    int mitad = inicio + (fin - inicio)/2;

    Resultado izq = mergeSort(arr,inicio,mitad);
    Resultado der = mergeSort(arr,mitad+1,fin);
    Resultado cruzado = merge(arr,inicio,mitad,fin);

    return maximo(cruzado,izq,der);
}
Resultado merge(int arr[],int inicio,int mitad,int fin) {
    int inicioIzq = mitad;
    int finIzq = inicio;
    int indiceIzq = mitad;

    int sumaActual = 0;

    int sumaIzq = INT_MIN;
    for (int i = inicioIzq; i >= finIzq; i--) {
        sumaActual += arr[i];
        if (sumaActual > sumaIzq) {
            sumaIzq = sumaActual;
            indiceIzq = i;
        }
    }

    sumaActual = 0;
    int inicioDer = mitad + 1;
    int finDer = fin;
    int indiceDer = mitad+1;

    int sumaDer = INT_MIN;
    for (int i = inicioDer; i <= finDer; i++) {
        sumaActual += arr[i];
        if (sumaActual > sumaDer) {
            sumaDer = sumaActual;
            indiceDer = i;
        }
    }

    Resultado res{};
    res.suma = sumaIzq+sumaDer;
    res.inicio = indiceIzq;
    res.fin = indiceDer;

    return res;
}

Resultado maximo(Resultado a, Resultado b, Resultado c) {
    Resultado mayor = a;
    if (b.suma > mayor.suma) {
        mayor = b;
    }
    if (c.suma > mayor.suma) {
        mayor = c;
    }
    return mayor;
}