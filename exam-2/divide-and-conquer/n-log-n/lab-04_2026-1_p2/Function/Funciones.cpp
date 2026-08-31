//
// Created by Ivan Piero Baltazar on 8/07/2026.
//

#include "Funciones.h"

#include <algorithm>
#include <iomanip>

void mergesort(Resultado arr[],int inicio,int fin) {
    if (inicio>=fin) {
        return;
    }

    int mitad = inicio + (fin-inicio)/2;

    mergesort(arr,inicio,mitad);
    mergesort(arr,mitad+1,fin);

    merge(arr,inicio,mitad,fin);

}

void merge(Resultado arr[],int inicio,int mitad,int fin) {
    //PARTE 1 COPIAR IZQ, DER
    int inicioIzq = inicio;
    int finIzq = mitad;

    int inicioDer = mitad+1;
    int finDer = fin;

    int n1 = finIzq - inicioIzq + 1;
    int n2 = finDer - inicioDer + 1;

    Resultado izquierda[n1];
    Resultado derecha[n2];

    for (int i = 0; i < n1; i++) {
        izquierda[i] = arr[inicioIzq+i];
    }
    for (int j = 0; j < n2; j++) {
        derecha[j] = arr[inicioDer+j];
    }

    //PARTE 2 ORDENAR
    int i = 0; //index left
    int j = 0; //index right
    int k = inicio; //index arr

    while (i < n1 && j < n2) {
        if (izquierda[i].distancia <= derecha[j].distancia) {
            arr[k] = izquierda[i];
            i++;
        } else{
            arr[k] = derecha[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = izquierda[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = derecha[j];
        j++;
        k++;
    }
}

void imprimirCiudades(Resultado arr[],int inicio, int fin,int D1,int D2) {
    int index_inferior = -1;
    int index_superior = -1;
    if (inicio == fin) {
        if (arr[inicio].distancia >=D1 && arr[inicio].distancia<=D2) {
            index_inferior = inicio;
            index_superior = fin;
        }
    }else {
        if (!(arr[fin].distancia < D1 && arr[fin].distancia < D2)) {
            index_inferior = busquedaBinariaInferior(arr,inicio,fin,D1);
            if ( arr[fin].distancia <= D2 ) {
                index_superior = fin;
            }else {
                index_superior = busquedaBinariaSuperior(arr,inicio,fin,D2);
            }
        }
    }
    if (index_inferior == -1 || index_superior == -1) {
        cout<<"No hay cuidades en ese rango"<<endl;
    }else {
        int cant = index_superior - index_inferior + 1;
        for (int i = index_inferior; i <= index_superior; i++) {
            cout <<left<<setw(10)<< arr[i].ciudad << "   :"<<arr[i].distancia << " km."<<endl;
        }
        cout<<"Total: "<<cant<<" cuidades"<<endl;
    }
}
void imprimirCiudadesAll(Resultado arr[],int size) {
    for (int i = 0; i < size; i++) {
        cout<<left<<setw(10)<<arr[i].ciudad<<":"<<arr[i].distancia<<" km."<<endl;
    }
}

int busquedaBinariaInferior(Resultado arr[],int inicio,int fin,int D1) {
    if (inicio>fin) {
        return -1;
    }
    if (inicio == fin) {
        if (arr[inicio].distancia >= D1) return inicio;
        else return -1;
    }
    int mitad = inicio + (fin - inicio)/2;

    if (arr[mitad].distancia == D1) return mitad;

    if (arr[mitad].distancia >= D1) {
        return busquedaBinariaInferior(arr,inicio,mitad,D1);
    }else {
        return busquedaBinariaInferior(arr,mitad+1,fin,D1);
    }
}

int busquedaBinariaSuperior(Resultado arr[],int inicio,int fin,int D2) {
    if (inicio>fin) {
        return -1;
    }
    if (inicio == fin) {
        if (arr[inicio].distancia > D2) return inicio-1;
        else return -1;
    }
    int mitad = inicio + (fin - inicio)/2;

    if (arr[mitad].distancia > D2) {
        return busquedaBinariaSuperior(arr,inicio,mitad,D2);
    }else {
        return busquedaBinariaSuperior(arr,mitad+1,fin,D2);
    }
}