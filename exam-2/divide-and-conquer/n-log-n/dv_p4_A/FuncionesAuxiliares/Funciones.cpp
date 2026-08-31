//
// Created by Ivan Piero Baltazar on 8/07/2026.
//

#include "Funciones.h"

Resultado mergesort(int arr[],int inicio,int fin) {
    if(inicio == fin) {
        Resultado res{};
        res.suma = arr[inicio];
        res.inicio = inicio;
        res.fin = inicio;
        return res;
    }
    int mitad = inicio + (fin - inicio)/2;

    Resultado izquierda = mergesort(arr,inicio,mitad);
    Resultado derecha = mergesort(arr,mitad+1,fin);
    Resultado cruzado = merge(arr,inicio,mitad,fin);

    return mayor(izquierda,derecha,cruzado);
}

Resultado mayor(Resultado izquierda,Resultado derecha,Resultado cruzado) {
    Resultado res = izquierda;
    if (res.suma < derecha.suma) {
        res = derecha;
    }
    if (res.suma < cruzado.suma) {
        res = cruzado;
    }
    return res;
}

Resultado merge(int arr[],int inicio,int mitad,int fin) {
    int sumaActual = 0;

    int inicioIzq = mitad;
    int finIzq = inicio;
    int sumaIzquierda = INT_MIN;
    int indiceIzq = -1;
    for (int i = inicioIzq; i >= finIzq; i--) {
        sumaActual += arr[i];
        if (sumaActual > sumaIzquierda) {
            sumaIzquierda = sumaActual;
            indiceIzq = i;
        }
    }

    sumaActual = 0;
    int inicioDer = mitad+1;
    int finDer = fin;
    int sumaDerecha = INT_MIN;
    int indiceDer = -1;
    for (int i = inicioDer; i <= finDer; i++) {
        sumaActual += arr[i];
        if (sumaActual > sumaDerecha) {
            sumaDerecha = sumaActual;
            indiceDer = i;
        }
    }

    Resultado res{};
    res.suma = sumaDerecha + sumaIzquierda;
    res.inicio = indiceIzq;
    res.fin = indiceDer;
    return res;
}
