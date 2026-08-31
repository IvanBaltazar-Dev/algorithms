//
// Created by Ivan Piero Baltazar on 8/07/2026.
//

#include "Funciones.h"

#include <iomanip>

void imprimirCuidadesAll(Resultado cuidades[],int size) {
    for(int i=0;i<size;i++) {
        cout<<left<<setw(10)<<cuidades[i].cuidad<<":"<<cuidades[i].distancia<<" km."<<endl;
    }
}

void mergesort(Resultado cuidades[],int inicio,int fin) {
    if (inicio >= fin) return;

    int mitad = inicio + (fin - inicio)/2;

    mergesort(cuidades,inicio,mitad);
    mergesort(cuidades,mitad+1,fin);
    merge(cuidades,inicio,mitad,fin);
}

void merge(Resultado cuidades[],int inicio,int mitad,int fin) {
    int inicioIzq = inicio;
    int finIzq = mitad;

    int n1 = finIzq - inicioIzq + 1;
    Resultado izquierda[n1];

    for(int i=0;i<n1;i++) {
        izquierda[i] = cuidades[inicioIzq+i];
    }

    int inicioDer = mitad+1;
    int finDer = fin;

    int n2 = finDer - inicioDer + 1;
    Resultado derecha[n2];

    for(int j=0;j<n2;j++) {
        derecha[j] = cuidades[inicioDer+j];
    }

    int i = 0;
    int j = 0;
    // K INICIA EN INICIO
    int k = inicio;

    while (i < n1 && j < n2) {
        //CASOS
        //CASO 1: IZQUIERDA MENOR
        if (izquierda[i].distancia <= derecha[j].distancia) {
            cuidades[k] = izquierda[i];
            i++;
            k++;
        }else { //CASO 2: DERECHA MENOR
            cuidades[k] = derecha[j];
            j++;
            k++;
        }
    }

    while (i < n1) {
        cuidades[k] = izquierda[i];
        i++;
        k++;
    }
    while (j < n2) {
        cuidades[k] = derecha[j];
        j++;
        k++;
    }
}
